#include <stdio.h>
#include "solarium-types.h"

// See solarium-types.c
extern device_t device[NUM_DEVICES];
extern beam_t beam[NUM_BEAMS];
extern ray_t  ray[NUM_RAYS+1];
extern ring_t ring[NUM_RINGS];

int main (void) {
	printf("Setting up structures\n");
	setup();
	
	return(0);
}
