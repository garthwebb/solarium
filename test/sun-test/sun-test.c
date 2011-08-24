#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "solarium-types.h"
#include "solarium-draw.h"
#include "color_map.h"

int main (void)
{
	int ele;
	coordinates_t center;
	int i;
/*
	uint8_t r = 255;
	uint8_t g = 255;
	uint8_t b = 255;
	color_t color_map [COLOR_MAP_SIZE];

	for (i = 0; i < COLOR_MAP_SIZE; ++i) {
		color_map[i].red = r;
		color_map[i].green = g;
		color_map[i].blue = b;

		printf ("Setting color_map %d to %d, %d, %d\n", i, r, g, b);
		if (r > 0) {
			r -= 3;
			g -= 3;
			b -= 3;
		}
	}
*/
	color_t *color_map = get_color_map(0);

/*
	for (i = 0; i < COLOR_MAP_SIZE; i++) {
		color_map[i].red = 0;
		color_map[i].green = 10;
		color_map[i].blue = 0;
	}
*/

	double radians[360];

	for (i = 0; i < 360; ++i) {
		radians[i] = i * PI / 180;
	}

	setup();

	while (1) {
		center.azimuth = 0.0;
		center.az_sin = sin(center.azimuth);
		center.az_cos = cos(center.azimuth);
		for (ele = 0; ele < 360; ++ele) {
			center.elevation = radians[ele];
			center.ele_sin = sin(radians[ele]);
			center.ele_cos = cos(radians[ele]);

			printf ("Calling draw_circles %d 0\n", ele);
			draw_circles(&center, color_map);
		}
	}

	return 0;
}
