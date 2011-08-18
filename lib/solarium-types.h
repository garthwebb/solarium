 /*
 
 A list of datatypes for the Solarium Beams/Rays
 
 */

#ifndef __SOLARIUM_TYPES_H__
#define __SOLARIUM_TYPES_H__

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
	uint8_t		size;	     // The number of beams in the ray
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

#define NUM_RAYS	36
#define NUM_DEVICES	(NUM_RAYS * 3)
#define NUM_BEAMS	566
#define NUM_RINGS	17

#define FIRST_DEVICE_ADDRESS 18
#define FIRST_RAY_INDEX      1
#define LAST_RAY_INDEX       NUM_RAYS

extern uint8_t BAD_ADDRESSES[];

// This maps each degree of each ring to a particular beam on that ring. Beams are numbered by their
// order on the ring, e.g. ring 16 has beams 1 though 60, ring 15 has beams 1 through 58, etc.
extern uint8_t degree_map[17][360];

#define LAST_DEVICE_ADDRESS  (FIRST_DEVICE_ADDRESS + NUM_DEVICES + sizeof(BAD_ADDRESSES) - 1)

void setup (void);
device_t *get_device (int index);
ray_t *get_ray (int index);
beam_t *get_beam(int index);

#endif
