#include <stdio.h>
#include <unistd.h>
#include "solarium-types.h"
#include "solarium-draw.h"

#define ENABLE_BEAM_STEP_DELAY 1
#define BEAM_STEP_DELAY 1000000

void set_beam_colors (int i)
{
	beam_t *beam = get_beam(i);
#if 0	
	static uint32_t rgb = 0x0000003f;

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

	rgb += 0x40;
	if (rgb >= 0x01000000) {
		rgb = 0x0000003f;
	}
#else
	if (!(i % 4)) {
//		printf ("Writing white\n");
		*(beam->red) = 255;
		*(beam->green) = 255;
		*(beam->blue) = 255;
	}
	else if ((i % 4) == 1) {
//		printf ("Writing red\n");
		*(beam->red) = 255;
		*(beam->green) = 0;
		*(beam->blue) = 0;
	}
	else if ((i % 4) == 2) {
//		printf ("Writing green\n");
		*(beam->red) = 0;
		*(beam->green) = 255;
		*(beam->blue) = 0;
	}
	else if ((i % 4) == 3) {
//		printf ("Writing blue\n");
		*(beam->red) = 0;
		*(beam->green) = 0;
		*(beam->blue) = 255;
	}
#endif
			
	*(beam->dirty) = 1;
}

int main (void)
{
	int i;

	setup();

	while (1) {
		i = NUM_BEAMS;
		while (i--) {
			set_beam_colors(i);

			draw();

#if ENABLE_BEAM_STEP_DELAY
			usleep(BEAM_STEP_DELAY);
#endif
		}

		sleep(30);
		clear();

		for (i = 0; i < NUM_BEAMS; ++i) {
			set_beam_colors(i);

			draw();

#if ENABLE_BEAM_STEP_DELAY
			usleep(BEAM_STEP_DELAY);
#endif
		}

		sleep(30);
		clear();
	}


	return 0;
}


