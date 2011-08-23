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

		printf ("Setting color_map %d to %d, %d, %d\n", i, r, g, b);
		if (r > 0) {
			r -= 3;
			g -= 3;
			b -= 3;
		}
	}

	while (1) {
		center.azimuth = 0;
		for (ele = 270; ele < 360; ++ele) {
			center.elevation = ele;

			printf ("Calling draw_circles %d 0\n", ele);
			draw_circles(&center, color_map);
		}

		for (ele = 0; ele < 90; ++ele) {
			center.elevation = ele;

			printf ("Calling draw_circles %d 0\n", ele);
			draw_circles(&center, color_map);
		}

		center.azimuth = 180;
		for (ele = 90; ele < 270; ++ele) {
			center.elevation = ele;

			printf ("Calling draw_circles %d 90\n", ele);
			draw_circles(&center, color_map);
		}
	}

	return 0;
}
