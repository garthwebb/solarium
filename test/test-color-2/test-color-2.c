#include "stdio.h"
#include <unistd.h>
#include <time.h>
#include "i2c/device.h"
#include <stdlib.h>

#define ADDR_RED 18 
#define ADDR_GREEN 19
#define ADDR_BLUE 20

uint8_t red[16], green[16], blue[16];
uint8_t max_val = 255;

void ooze (uint8_t *r, uint8_t *g, uint8_t *b);

int main( int argc, char **argv ) {
	init_devices();

        int red_addr, grn_addr, blu_addr;
        red_addr = atoi(argv[1]);
        grn_addr = atoi(argv[2]);
        blu_addr = atoi(argv[3]);

	int i, r, g, b;

	for (i=0; i<=15; i++) {
		red[i] = 0;
		green[i] = 0;
		blue[i] = 0;
	}
	for (i=REG_PWM0; i<=REG_PWM15; i++) {
		write_register(red_addr, i, 0);
		write_register(grn_addr, i, 0);
		write_register(blu_addr, i, 0);
	}

	// Initial bu p values
	r = 5;
	g = 0;
	b = 0;

	while (1) {
		// For the first pixel, cycle the color

		// Red
		if (red[0] + r > max_val) {
			g = r;
			r *= -1;
			red[0] = max_val;
		} else if (red[0] + r < 0) {
			r = 0;
			red[0] = 0;
		} else {
			red[0] += r;
		}

		// Green
                if (green[0] + g > max_val) { 
                        b = g;
                        g *= -1;
                        green[0] = max_val;
                } else if (green[0] + g < 0) {
                        g = 0;
                        green[0] = 0;
                } else {
			green[0] += g;
		}

		// Blue
                if (blue[0] + b > max_val) { 
                        r = b;
                        b *= -1;
                        blue[0] = max_val;
                } else if (blue[0] + b < 0) {
                        b = 0;
                        blue[0] = 0;
                } else {
			blue[0] += b;
		}

		// For the rest ooze the color to the other pixels
		ooze(red, green, blue);

                fast_write_brightness (red_addr, red, 16);
                fast_write_brightness (grn_addr, green, 16);
                fast_write_brightness (blu_addr, blue, 16);
//		for (i=REG_PWM0; i<=REG_PWM15; i++) {
	//		if ((i < REG_PWM11) || (i == REG_PWM12) || (i == REG_PWM13) || (i == REG_PWM14) || (i == REG_PWM15)) {
//			write_register(red_addr, i, red[i-REG_PWM0]);
//			write_register(grn_addr, i, green[i-REG_PWM0]);
//			write_register(blu_addr, i, blue[i-REG_PWM0]);
	//		}
//		}
	}

	fprintf(stderr, "Exiting...\n");
	cleanup();
}


void ooze (uint8_t *r, uint8_t *g, uint8_t *b) {
	int i;

	for (i=15; i>0; i--) {
		r[i] = r[i-1];
		g[i] = g[i-1];
		b[i] = b[i-1];
	}
}

