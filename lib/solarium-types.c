#include "solarium-types.h"

// Each PCA9635
device_t device[NUM_DEVICES];

// All the beams in the Solarium
beam_t beam[NUM_BEAMS];

// All the rays in the Solarium.
ray_t  ray[NUM_RAYS+1];

// Each ring
ring_t ring[NUM_RINGS];

void setup (void) {
	int x, y;
	
	// Zero out the rays and assign devices
	for (x = 0; x < NUM_RAYS; x++) {
		ray[x].id = x + 1;
		ray[x].dirty = 0;

		// Assign the three devices and set pointers
		for (y = 0; y < 3; y++) {
			// Save a pointer to the next available device
			ray[x].devices[y] = &device[(3*x)+y];
			
			// Save a pointer to this device's ray's dirty bit
			device[(3*x) + y].dirty = &(ray[x].dirty);
		}

		// Assign beams sequentially
		for (y = 0; y < 16; y++) {
			ray[x].beams[y] = &beam[(16*x) + y];
			beam[(16*x) + y].dirty = &(ray[x].dirty);
		}
	}
	
	// Zero out devices and attach beams
	for (x = 0; x < NUM_DEVICES; x++) {
		device[x].dirty = 0;

		// Initialize each of the 16 LEDs the device controls
		for (y = 0; y < 16; y++) {
			// Zero out the value
			device[x].value[y] = 0;
			
			// Every three devices control all red, green or blue
			if (x % 3 == 0) {
				// The inx(x/3) makes sure that the device after this one gets
				// this same beam but assigns to green, etc
				beam[x / 3].red   = &(device[x].value[y]);
			} else if (x % 3 == 1) {
				beam[x / 3].green = &(device[x].value[y]);
			} else if (x % 3 == 2) {
				beam[x / 3].blue  = &(device[x].value[y]);
			}
		}
	}
	
	/*************************************************************/
	/* Size the rings and link rays/beams to rings, ring by ring */
	
	/** Ring 16 - 60 beams **/
	set_ring_size(&ring[16], 60);
	assign_ray(&ring[16], 1);
	assign_ray(&ring[16], 2);
	assign_ray(&ring[16], 3);
	assign_ray(&ring[16], 4);

	/** Ring 15 - 58 beams **/
	set_ring_size(&ring[15], 58);
	assign_ray(&ring[15], 5);
	assign_ray(&ring[15], 6);
	assign_ray(&ring[15], 7);
	assign_partial_ray(&ring[15], 8, 1, 10);

	/** Ring 14 - 56 beams **/
	set_ring_size(&ring[14], 56);
	assign_ray(&ring[14], 9);
	assign_ray(&ring[14], 10);
	assign_ray(&ring[14], 11);
	assign_partial_ray(&ring[14], 15, 11, 16);
	assign_partial_ray(&ring[14], 8, 11, 12);

	/** Ring 13 - 53 beams **/
	set_ring_size(&ring[13], 53);
	assign_ray(&ring[13], 12);
	assign_ray(&ring[13], 13);
	assign_ray(&ring[13], 14);
	assign_partial_ray(&ring[13], 15, 1, 5);

	/** Ring 12 - 50 beams **/
	set_ring_size(&ring[12], 50);
	assign_ray(&ring[12], 16);
	assign_ray(&ring[12], 17);
	assign_partial_ray(&ring[12], 18, 1, 13);

	/** Ring 11 - 46 beams **/
	set_ring_size(&ring[11], 46);
	assign_ray(&ring[11], 19);
	assign_ray(&ring[11], 20);
	assign_partial_ray(&ring[11], 21, 1, 11);
	assign_partial_ray(&ring[11], 18, 14, 16);

	/** Ring 10 - 43 beams **/
	set_ring_size(&ring[10], 43);
	assign_ray(&ring[10], 22);
	assign_ray(&ring[10], 23);
	assign_partial_ray(&ring[10], 26, 11, 16);
	assign_partial_ray(&ring[10], 21, 12, 16);

	/** Ring 9 - 39 beams **/
	set_ring_size(&ring[9], 39);
	assign_ray(&ring[9], 24);
	assign_ray(&ring[9], 25);
	assign_partial_ray(&ring[9], 26, 1, 7);

	/** Ring 8 - 35 beams **/
	set_ring_size(&ring[8], 35);
	assign_ray(&ring[8], 27);
	assign_ray(&ring[8], 28);
	assign_partial_ray(&ring[8], 26, 8, 10);

	/** Ring 7 - 31 beams **/
	set_ring_size(&ring[7], 31);
	assign_ray(&ring[7], 29);
	assign_partial_ray(&ring[7], 30, 1, 15);

	/** Ring 6 - 27 beams **/
	set_ring_size(&ring[6], 27);
	assign_ray(&ring[6], 31);
	assign_partial_ray(&ring[6], 32, 1, 10);
	assign_partial_ray(&ring[6], 30, 16, 16);

	/** Ring 5 - 22 beams **/
	set_ring_size(&ring[5], 22);
	assign_ray(&ring[5], 33);
	assign_partial_ray(&ring[5], 32, 11, 16);

	/** Ring 4 - 18 beams **/
	set_ring_size(&ring[4], 18);
	assign_ray(&ring[4], 34);
	assign_partial_ray(&ring[4], 35, 15, 16);

	/** Ring 3 - 14 beams **/
	set_ring_size(&ring[3], 14);
	assign_partial_ray(&ring[3], 35, 1, 14);

	/** Ring 2 - 9 beams **/
	set_ring_size(&ring[2], 9);
	assign_partial_ray(&ring[2], 36, 6, 14);
	
	/** Ring 1 - 4 beams **/
	set_ring_size(&ring[1], 4);
	assign_partial_ray(&ring[1], 36, 2, 5);

	/** Ring 0 - 1 beam **/
	set_ring_size(&ring[0], 1);
	assign_partial_ray(&ring[0], 36, 1, 1);
}

void set_ring_size (ring_t *ring, uint8_t num_beams) {
	int x;

	ring->num_beams = num_beams;
	ring->beams     = (beam_t **) malloc(num_beams * sizeof(beam_t*));

	for (x = 0; x < num_beams; x++) {
		ring->beams[x] = NULL;
	}
}

// Note, ray_num should start at 1 to match the hemisphere map.  It will be -1 in the function
// to map to the array properly.  Similarly first and last should start at 1
void assign_partial_ray (ring_t *ring, uint8_t ray_num, uint8_t first, uint8_t last) {
	int x = 0;
	int start = -1;
	int end;

	// Find the next place to start adding beams
	while ((start == -1) && (x < ring->num_beams)) {
		if (ring->beams[x] == NULL) {
			start = x;
		} else {
			x++;
		}
	}

	// If we didn't find a start position, exit
	if (start == -1) {
		fprintf(stderr, "Assigned ray to ring with no more room\n");
		exit(1);
	}

	// Make sure we clip where needed
	end = start+last;
	if (end > ring->num_beams) {
		end = ring->num_beams;
	}

	// Start assigning beams
	for (x = start; x < end; x++) {
		ring->beams[x] = ray[ray_num-1].beams[x+first-1];
	}
}

void assign_ray (ring_t *ring, uint8_t ray_num) {
	assign_partial_ray(ring, ray_num, 1, 16);
}
