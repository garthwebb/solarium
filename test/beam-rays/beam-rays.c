#include <stdio.h>
#include <unistd.h>
#include "solarium-types.h"
#include "solarium-draw.h"

#define ENABLE_BEAM_STEP_DELAY 0
#define BEAM_STEP_DELAY 1000000

#define COLOR_STEP 5

void set_beam_colors (int i)
{
	int j;
	beam_t *beam = get_beam(i);

	*(beam->red) = 255;
	*(beam->green) = 255;
	*(beam->blue) = 255;

	*(beam->dirty) = 1;

	for (j = 0; j < NUM_BEAMS; ++j) {
		beam = get_beam(j);
		if (j == i) {
			continue;
		}
		if (*(beam->red) || *(beam->green) || *(beam->blue)) {
			if (*(beam->red) < COLOR_STEP) {
				*(beam->red) = 0;
			}
			else {
				*(beam->red) -= COLOR_STEP;
			}
			if (*(beam->green) < COLOR_STEP) {
				*(beam->green) = 0;
			}
			else {
				*(beam->green) -= COLOR_STEP;
			}
			if (*(beam->blue) < COLOR_STEP) {
				*(beam->blue) = 0;
			}
			else {
				*(beam->blue) -= COLOR_STEP;
			}

			*(beam->dirty) = 1;
		}
	}
}

int main (void)
{
	int i;

	setup();

	while (1) {
		for (i = 0; i < NUM_BEAMS; ++i) {
			set_beam_colors(i);

			draw();

			printf ("Drew beam %d\n", i);

#if ENABLE_BEAM_STEP_DELAY
			usleep(BEAM_STEP_DELAY);
#endif
		}
	}

	return 0;
}


