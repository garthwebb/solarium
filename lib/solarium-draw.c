#include <math.h>
#include "solarium-types.h"
#include "solarium-draw.h"
#include "i2c/device.h"

#define PI 3.14159265

inline void draw_device (device_t *dev);

void draw (void)
{
	int i;
	ray_t *r;

	for (i = FIRST_RAY_INDEX; i <= LAST_RAY_INDEX; ++i) {
		r = get_ray(i);

		if (r == NULL || !r->dirty) {
			continue;
		}

		if (i < 30) {
			// HACK don't draw to currently disabled rays
			draw_device (r->devices[0]);
			draw_device (r->devices[1]);
			draw_device (r->devices[2]);
		}

                r->dirty = 0;
	}
}

// Return distance where COLOR_MAP_SIZE > dist >= 0
uint16_t calc_degree_distance (coordinates_t *p1, coordinates_t *p2)
{
	uint16_t dist = 0;
	double value = 0.0;
	double p1Latitude = p1->elevation * PI / 180;
	double p2Latitude = p2->elevation * PI / 180;
	double deltaLongitude = (p1->azimuth - p2->azimuth) * PI / 180;
	value = acos(sin(p1Latitude) * sin(p2Latitude) + cos(p1Latitude) * cos(p2Latitude) * cos(deltaLongitude));
	dist = value * 180 / PI;
	return dist;
}

// color_map must point to an array of COLOR_MAP_SIZE color_t structs
void draw_circles (coordinates_t *center_pos, color_t color_map[])
{
	uint8_t r_index, rb_index;
	uint16_t dist;
	ring_t *r;
	beam_t *b;
	coordinates_t *pos;
	for (r_index = 0; r_index < NUM_RINGS; ++r_index) {
		r = get_ring (r_index);
		for (rb_index = 0; rb_index < r->num_beams; ++rb_index) {
			b = r->beams[rb_index];
			pos = &(b->position);

			fprintf (stderr, "Ring %d Beam %d, elevation %d, azimuth %d\n",
				r_index, rb_index, pos->elevation, pos->azimuth);

			dist = calc_degree_distance (pos, center_pos);

			*(b->red) = color_map[dist].red;
			*(b->green) = color_map[dist].green;
			*(b->blue) = color_map[dist].blue;

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
