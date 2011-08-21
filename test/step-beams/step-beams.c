#include <stdio.h>
#include <unistd.h>
#include "solarium-types.h"
#include "solarium-draw.h"

#define ENABLE_BEAM_STEP_DELAY 0
#define BEAM_STEP_DELAY 1000000

uint8_t color_offsets[6][3] = {
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
	uint32_t rgb = 0x0000003f;

	setup();

	while (1) {
		for (i = 0; i < NUM_BEAMS; ++i) {
			beam = get_beam(i);
//			fprintf(stderr, "Testing beam %d\n", i);
	
			if (((uint8_t)rgb) == 0xbf) {
				*(beam->blue) = 0;
			}
			else {
				*(beam->blue) = (uint8_t)rgb;
			}
			*(beam->green) = (uint8_t)(rgb >> 8);
			if (*(beam->blue) == 0x3f) {
				*(beam->red) = ~(uint8_t)(rgb >> 16);
			}
			else {
				*(beam->red) = (uint8_t)(rgb >> 16);
			}
			*(beam->dirty) = 1;

			draw();

			rgb += 0x40;
			if (rgb >= 0x01000000) {
				rgb = 0x0000003f;
			}

#if ENABLE_BEAM_STEP_DELAY
			usleep(BEAM_STEP_DELAY);
#endif
		}

		sleep(30);
		clear();

		i = NUM_BEAMS;
		while (i--) {
			beam = get_beam(i);
	
			if (((uint8_t)rgb) == 0xbf) {
				*(beam->blue) = 0;
			}
			else {
				*(beam->blue) = (uint8_t)rgb;
			}
			*(beam->green) = (uint8_t)(rgb >> 8);
			if (*(beam->blue) == 0x3f) {
				*(beam->red) = ~(uint8_t)(rgb >> 16);
			}
			else {
				*(beam->red) = (uint8_t)(rgb >> 16);
			}
			*(beam->dirty) = 1;

			draw();

			rgb += 0x40;
			if (rgb >= 0x01000000) {
				rgb = 0x0000003f;
			}

#if ENABLE_BEAM_STEP_DELAY
			usleep(BEAM_STEP_DELAY);
#endif
		}

		sleep(30);
		clear();
	}


	return 0;
}


