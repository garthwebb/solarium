 /*
 
 A list of datatypes for the Solarium Beams/Rays
 
 */

#include <stdint.h>
#include <stdio.h>

// A single PCA9635 device
typedef struct {
	uint8_t value[16];      // Each device controls 16 LEDs
	uint8_t addr;           // The i2c address for this device
	uint8_t *dirty;         // Whether any value has changed on this device.
					        // A pointer to ray's dirty
} device_t;

// Represents a RGB beam
typedef struct {
	uint8_t *red;   // Color components of the beam.  Pointers to values in a device
	uint8_t *green;
	uint8_t *blue;

	uint8_t *dirty; // Whether this beam has changed.
					// A pointer to a ray's dirty
} beam_t;

// Represents a ray of 16 beams
typedef struct ray_struct {
	uint8_t 	id;	         // This ray's ID  (for reference on the hemisphere chart)
	device_t	*devices[3]; // Pointers to the three devices for this beam
	beam_t  	*beams[16];  // Array of beam pointers this ray controls
	uint8_t 	dirty;       // Incremented everytime a beam is updated.
} ray_t;

// Represents a string of beams on a ring
typedef struct {
	beam_t	**beams;   // Pointer to the beams on this ring
	uint8_t num_beams; // Number of beams
} ring_t;

// Unusable addresses
// All call: 1110 000
// SW Reset: 0000 011
// Fm+     : 0000 100, 0000 101, 0000 110, 0000 111

#define NUM_DEVICES	108
#define NUM_BEAMS	576
#define NUM_RAYS	36
#define NUM_RINGS	17

void setup (void);
void set_ring_size (ring_t *ring, uint8_t num_beams);
void assign_ray (ring_t *ring, uint8_t ray_num);
void assign_partial_ray (ring_t *ring, uint8_t ray_num, uint8_t first, uint8_t last);
