#include <stdio.h>
#include <unistd.h>
#include "solarium-types.h"
#include "solarium-draw.h"

uint8_t color_offsets[][] = {
	{ 0, 8, 16 },
	{ 0, 16, 8 },
	{ 8, 0, 16 },
	{ 8, 16, 0 },
	{ 16, 0, 8 },
	{ 16, 8, 0 }
};

int main (void)
{
	int i;
	beam_t *beam;
	uint32_t rgb = 0x00000080;
	unsigned int blue_offset = 0;
	unsigned int red_offset = 8;
	unsigned int green_offset = 16;

	setup();

	while (1) {
		for (i = 0; i < NUM_BEAMS; ++i) {
			beam = get_beam(i);
	
			*(beam->blue) = (uint8_t)rgb;
			*(beam->green) = (uint8_t)(rgb >> 8);
			*(beam->red) = (uint8_t)(rgb >> 16);
			*(beam->dirty) = 1;

			draw();

			rgb += 8;
			if (rgb >= 0x01000000) {
				rgb = 0x00000080;
			}

			usleep(100);
		}

		clear();

		i = NUM_BEAMS;
		while (i--) {
			beam = get_beam(i);
	
			*(beam->blue) = (uint8_t)rgb;
			*(beam->green) = (uint8_t)(rgb >> 8);
			*(beam->red) = (uint8_t)(rgb >> 16);
			*(beam->dirty) = 1;

			draw();

			rgb += 8;
			if (rgb >= 0x01000000) {
				rgb = 0x00000080;
			}

			usleep(100);
		}
	}


	return 0;
}


