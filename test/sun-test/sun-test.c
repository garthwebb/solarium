#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "solarium-types.h"
#include "solarium-draw.h"
#include "color_map.h"

#define ELEVATION_OFFSET 0

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

	int color_map_index[24] = {
            0, // 6 am
            1, // 7
            2, // 8
            3, // 9
            4, // 10
            5, // 11
            6, // 12 noon
            7, // 1 pm
            8, // 2 pm
            9, // 3 pm
            10, // 4 pm
            11, // 5 pm
            12, // 6 pm
            13,
            14,
            15,
            16,
            17,
            18, // 12 midnight
            19, // 1am
            20, // 2am
            21, // 3am
            22, // 4am
            23 // 5am
/*
            12,
            13,
            14,
            15,
            16,
            17,
            18,
            19,
            20,
            21,
            22,
            23,
*/
        };

	while (1) {
		center.azimuth = 0.0;
		center.az_sin = sin(center.azimuth);
		center.az_cos = cos(center.azimuth);
		for (ele = 0; ele < 360; ++ele) {
			color_t *color_map = get_color_map(
				color_map_index[(ele + ELEVATION_OFFSET)/15]
                        );
			center.elevation = radians[ele];
			center.ele_sin = sin(radians[ele]);
			center.ele_cos = cos(radians[ele]);
			printf ("%d %d\n", (ele + ELEVATION_OFFSET)/15, ele);
//			printf ("Calling draw_circles %d with offset %d color_map %d\n",
//				ele, (ele + ELEVATION_OFFSET)/15, color_map_index[(ele + ELEVATION_OFFSET)/15]);
			draw_circles(&center, color_map);
//			usleep(500000);
		}
	}

	return 0;
}
