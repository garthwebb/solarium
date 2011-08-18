#include "solarium-types.h"
#include "i2c/device.h"

inline void draw_device (device_t *dev);

void draw (void) {
	int i;
	ray_t *r;

	for (i = FIRST_RAY_INDEX; i <= LAST_RAY_INDEX; ++i) {
		r = get_ray(i);

                if (r == NULL || !r->dirty) {
			continue;
		}

		draw_device (r->devices[0]);
		draw_device (r->devices[1]);
		draw_device (r->devices[2]);

                r->dirty = 0;
	}
}

inline void draw_device (device_t *dev) {
	fast_write_brightness (dev->addr, dev->value, 16);
}

void clear (void) {
	int i;

	beam_t *b;

	for (i = 0; i < NUM_BEAMS; ++i) {
		b = get_beam(i);
		*(b->blue) = 0;
		*(b->green) = 0;
		*(b->red) = 0;
		*(b->dirty) = 1;
	}

	draw();
}
