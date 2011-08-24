#include <math.h>
#include "solarium-types.h"
#include "solarium-draw.h"
#include "i2c/device.h"
#include "color_map.h"

color_t global_color_map[NUM_MAPS][COLOR_MAP_SIZE] = COLOR_MAP_INIT;
color_t sun_color_map[NUM_MAPS][COLOR_MAP_SIZE] = COLOR_MAP_INIT;

uint8_t atten[256] = {0,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,17,17,18,18,19,19,20,20,21,21,22,22,23,23,24,24,25,25,26,26,27,28,28,29,29,30,30,31,31,32,32,33,33,34,35,35,36,36,37,37,38,38,39,40,40,41,41,42,42,43,44,44,45,45,46,46,47,48,48,49,49,50,50,51,52,52,53,53,54,55,55,56,56,57,58,58,59,59,60,61,61,62,63,63,64,64,65,66,66,67,68,68,69,69,70,71,71,72,73,73,74,75,75,76,77,77,78,79,79,80,81,81,82,83,83,84,85,86,86,87,88,88,89,90,91,91,92,93,93,94,95,96,96,97,98,99,100,100,101,102,103,103,104,105,106,107,107,108,109,110,111,112,112,113,114,115,116,117,118,119,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,140,141,142,143,144,145,147,148,149,150,152,153,154,156,157,159,160,162,163,165,167,168,170,172,174,176,178,180,182,185,187,190,193,196,200,204,208,213,219,227,237,255};

inline void draw_device (device_t *dev);

void draw (void)
{
	int i;
	ray_t *r;

	for (i = FIRST_RAY_INDEX; i <= LAST_RAY_INDEX; ++i) {
		r = get_ray(i);

		if (!r->dirty) {
			continue;
		}

		draw_device (r->devices[0]);
		draw_device (r->devices[1]);
		draw_device (r->devices[2]);

                r->dirty = 0;
	}
}

// Return distance where COLOR_MAP_SIZE > dist >= 0
uint16_t calc_degree_distance (coordinates_t *p1, coordinates_t *p2)
{
	static double one80_pi = 180 / PI;
	uint16_t dist = 0;
	double value = 0.0;
	double deltaLongitude = p1->azimuth - p2->azimuth;
	value = acos(p1->ele_sin * p2->ele_sin + p1->ele_cos * p2->ele_cos * cos(deltaLongitude));
	dist = value * one80_pi + 0.5;
	return dist;
}

// color_map must point to an array of COLOR_MAP_SIZE color_t structs
void draw_circles (coordinates_t *center_pos, color_t *my_color_map)
{
	uint8_t r_index, rb_index;
	uint16_t dist;
	ring_t *r;
	beam_t *b;
	coordinates_t *pos;
//	fprintf (stderr, "Inside draw_circles\n");
	for (r_index = 0; r_index < NUM_RINGS; ++r_index) {
		r = get_ring (r_index);
//		fprintf (stderr, "Num beams %d for ring %d\n", r->num_beams, r_index);
		for (rb_index = 0; rb_index < r->num_beams; ++rb_index) {
			b = r->beams[rb_index];
			pos = &(b->position);

			dist = calc_degree_distance (pos, center_pos);

                        if (r_index == 0) {
			fprintf (stderr, "Ring %d Beam %d, elevation %d, azimuth %d colors %d, %d, %d\n",
				r_index, rb_index, (int)(pos->elevation * 180 / PI), (int)(pos->azimuth * 180 / PI), my_color_map[dist].red, my_color_map[dist].green, my_color_map[dist].blue);
			}

			*(b->red) = atten[my_color_map[dist].red];
			*(b->green) = atten[my_color_map[dist].green];
			*(b->blue) = atten[my_color_map[dist].blue];

			// possibly optimize to only set dirty if changed?
			*(b->dirty) = 1;
		}
	}

	draw();
}

inline void draw_device (device_t *dev)
{
//	fprintf(stderr, "Writing to address %d\n", dev->addr);
	fast_write_brightness (dev->addr, dev->value, 16);
}

void clear (void)
{
	int i;

	beam_t *b;

	for (i = 0; i < NUM_BEAMS; ++i) {
		b = get_beam(i);
		*(b->blue) = 0;
		*(b->green) = 0;
		*(b->red) = 0;
		*(b->dirty) = 1;
	}

	draw();
}

color_t *get_color_map (int i)
{
    return global_color_map[i];
}

color_t *get_sun_color_map (int i)
{
    return &(sun_color_map[i][0]);
}

