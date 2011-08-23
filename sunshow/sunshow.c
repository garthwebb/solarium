#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "solarium-types.h"
#include "solarium-draw.h"

// Find the number of clocks per millisecond
#define CLOCKS_PER_MSEC CLOCKS_PER_SEC/1000

// Animation interval. 42 ms would give 24 frames a second, movie speed
#define FRAME_MSEC 84

// Length of day in milliseconds
#define DAY_LENGTH 9*60*1000

// Define where we start the day, where
// - 0 is midnight
// - .25 is sunrise
// - .5 is full noon
// - .75 is sunset
#define START_FRACTION .25

void do_sun_frame(double day_fraction);

int main (void) {
	printf("Setting up structures\n");
	setup();

	// Counters for the passing day
	clock_t day_start;
	double day_fraction;

	// Counters for each frame of animation
	clock_t frame_start;
	double frame_elapsed = 0;
	
	// Get the time in secs for when the day started
	day_start = clock() - (START_FRACTION * (double) DAY_LENGTH);

	while (1) {
		// How much of the day has passed
		day_fraction = (clock() - day_start)/DAY_LENGTH;

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
		if (frame_elapsed < FRAME_MSEC) {
			usleep(FRAME_MSEC - frame_elapsed);
		}
	}

	return(0);
}

// Do what's necessary for the next frame of the sunshow
void do_sun_frame (double day_fraction) {
	double lat, lon;

	// Get figure out lon/lat coords
	lat = compass_to_lat(day_fraction * 360.0);
	if (day_fraction <= 0.5) {
		lon = 90;
	} else {
		lon = -90;
	}

	//position_sun(lat, lon, day_fraction);
}

