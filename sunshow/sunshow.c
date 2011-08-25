#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "solarium-types.h"
#include "solarium-draw.h"

// Find the number of clocks per millisecond
#define CLOCKS_PER_MSEC CLOCKS_PER_SEC/1000

// Animation interval. 42 ms would give 24 frames a second, movie speed
#define DEF_FRAME_MSEC 84

// Length of day in milliseconds
#define DEF_DAY_LENGTH 9*60*1000

// Define where we start the day, where
// - 0 is midnight
// - .25 is sunrise
// - .5 is full noon
// - .75 is sunset
#define START_FRACTION .25

void do_sun_frame(double day_fraction);

int main (int argc, char **argv) {
	uint32_t day_length;
	uint8_t frame_msec;

	// One argument; its day_length
	if (argc == 1) {
		day_length = (uint16_t) atoi(argv[1])*60*1000;
		frame_msec = DEF_FRAME_MSEC;
	}
	// Two arguments; day_length, frame_msec
	else if (argc == 2) {
		day_length = (uint16_t) atoi(argv[1])*60*1000;
		frame_msec = (uint8_t) atoi(argv[2]);
	}
	// No arguments, use all defaults
	else {
		day_length = DEF_DAY_LENGTH;
		frame_msec = DEF_FRAME_MSEC;
	}

	printf("Setting up structures\n");
	setup();

	// Counters for the passing day
	clock_t day_start;
	double day_fraction;

	// Counters for each frame of animation
	clock_t frame_start;
	double frame_elapsed = 0;
	
	// Get the time in secs for when the day started
	day_start = clock() - (START_FRACTION * (double) day_length);

	while (1) {
		// How much of the day has passed
		day_fraction = (clock() - day_start)/day_length;

		// Restart day if we've reached the end of the day
		if (day_fraction >= 1) {
			day_start = clock();
			day_fraction = 0;
		}

		// Restart the timer for this frame
		frame_start = clock();

		// Process the current frame
		do_sun_frame(day_fraction);
		draw();

		// Wait for the remainder of the frame if we have extra time
		frame_elapsed = ((double) (clock() - frame_start)) / CLOCKS_PER_MSEC;
		if (frame_elapsed < frame_msec) {
			usleep(frame_msec - frame_elapsed);
		}
	}

	return(0);
}

// Do what's necessary for the next frame of the sunshow
void do_sun_frame (double day_fraction) {
	color_t *color_map;

	coordinates_t center;
	center.azimuth  = 0;
	center.az_cos = cos(center.azimuth);
	center.az_sin = sin(center.azimuth);
	center.elevation = 2*PI*day_fraction;
	center.ele_cos = cos(center.elevation);
	center.ele_sin = sin(center.elevation);

        color_map = get_color_map((int) NUM_MAPS*day_fraction);

	printf ("Calling draw_circles %4.2f\n", center.elevation);
	draw_circles(&center, color_map);
}

