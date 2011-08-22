#include <stdio.h>
#include <unistd.h>
#include "solarium-types.h"
#include "solarium-draw.h"

int main (void)
{
	int i, ele;
	coordinates_t center;
	uint8_t r = 255;
	uint8_t g = 255;
	uint8_t b = 255;
	color_t color_map [COLOR_MAP_SIZE];

	setup();

	for (i = 0; i < COLOR_MAP_SIZE; ++i) {
		color_map[i].red = r;
		color_map[i].green = g;
		color_map[i].blue = b;

		if (r > 0) {
			--r;
			--g;
			--b;
		}
	}

	while (1) {
		center.azimuth = 0;
		for (ele = 0; ele < 90; ele++) {
			center.elevation = ele;

			draw_circles(&center, color_map);
		}

		center.azimuth = 180;
		for (ele = 90; ele >= 0; ele--) {
			center.elevation = ele;

			draw_circles(&center, color_map);
		}
	}

	return 0;
}
