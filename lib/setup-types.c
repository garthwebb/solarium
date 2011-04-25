#include "solarium-types.h"

#define NUM_DEVICES 108;
#define NUM_RAYS 36;
#define NUM_RINGS 17;

// Each PCA9635
device_t device[NUM_DEVICES];

// All the rays in the Solarium
ray_t  ray[NUM_RAYS];

// Each ring
ring_t ring[NUM_RINGS];

void setup (void) {
	int x, y;

	// Zero out the devices
	for (x = 0; x < NUM_DEVICES; x++) {
		device[x].dirty = 0;

		for (y = 0; y < 16; y++) {
			device[x].value[y] = 0;
		}
	}
	
	// Zero out the rays
	for (x = 0; x < NUM_RAYS; x++) {
		ray[x].id = x + 1;
		ray[x].dirty = 0;
	}
	
	/*********************************************/
	/* Shit load of manual linking, ring by ring */
	
	/** Ring 16 - 60 beams**/
	ring[16].num_beams = 60
	ring[16].beams = (beam_t *) malloc(60 * sizeof(beam_t));

}
