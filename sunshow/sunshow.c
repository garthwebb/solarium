#include <stdio.h>
#include "solarium-types.h"
#include <time.h>
#include <unistd.h>

// Find the number of clocks per millisecond
#define CLOCKS_PER_MSEC CLOCKS_PER_SEC/1000

// Animation interval. 42 ms would give 24 frames a second, movie speed
#define STEP_MSEC 84

// Length of day in milliseconds
#define DAY_LENGTH 9*60*1000

void do_sun_frame(double day_fraction);
double compass_to_lat (double deg);
double compass_to_lon (double deg);

int main (void) {
	printf("Setting up structures\n");
	setup();

	// Counters for each frame of animation
	clock_t frame_start, frame_cur;
	double frame_elapsed = 0;
	
	// Counters for the passing day
	clock_t day_start, day_cur
	double day_fraction;

	// Start the day at sunrise so we know its working right away
	day_fraction = .25;
	day_start = clock() - (day_fraction * (double) DAY_LENGTH);

	while (1) {
		// Restart day if we've reached the end of the day
		if (day_fraction >= 1) {
			day_start = clock();
		}

		// Restart the timer for this frame
		frame_start = clock();

		while (frame_elapsed < STEP_MSEC) {
			// Do any off step stuff here

			frame_cur = clock()
			frame_elapsed = ((double) (frame_cur - frame_start)) / CLOCKS_PER_MSEC;
		}

		day_fraction = (clock() - day_start)/DAY_LENGTH;
		do_sun_frame(day_fraction);
		refresh()
	}

	return(0);
}

void do_sun_frame (double day_fraction) {
	double lat, lon;

	// Get figure out lon/lat coords
	lat = compass_to_lat(day_fraction * 360.0);
	if (day_fraction <= 0.5) {
		lon = 90;
	} else {
		lon = -90
	}

	position_sun(lat, lon, day_fraction);
}

// Adjust for how lat is actually measured.  Start at due south, -90
//   0   90   180  270    360
// -90 -> 0 -> 90 -> 0 -> -90
double compass_to_lat (double deg) {
	if ((deg > 360) || (deg < 0))
		deg = deg % 360;

	if (deg < 180) {
		return (deg - 90);
	} else {
		return (270 - deg);	
	}
}

// Adjust for how lon is actually measured
//   0      180    360
//   0  ->  180  ->  0
double compass_to_lon (double deg) {
	if ((deg > 360) || (deg < 0))
		deg = deg % 360;

	if (deg <= 180) {
		return deg;
	} else {
		return 360-deg;
	}
}





