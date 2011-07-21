#include "solarium-types.h"
#include "i2c/device.h"

void draw_device (device_t *dev);

void draw (void) {
	int i, j;
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
