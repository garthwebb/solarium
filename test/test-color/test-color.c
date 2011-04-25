#include "stdio.h"
#include <unistd.h>
#include <time.h>
#include "i2c/device.h"
#include <stdlib.h>

#define ADDR_RED 4
#define ADDR_GREEN 5
#define ADDR_BLUE 2

uint8_t red[16], green[16], blue[16];

void spatter(uint8_t *a);
void spread(uint8_t *a);

int main( int argc, char **argv ) {
	init_devices();

	int i, r, g, b;

	for (i=0; i<=15; i++) {
		red[i] = 0;
		green[i] = 0;
		blue[i] = 0;
	}

	while (1) {
		spatter(red);
		spatter(green);
		spatter(blue);

		spread(red);
		spread(green);
		spread(blue);


		for (i=REG_PWM0; i<=REG_PWM15; i++) {
			write_register(ADDR_RED, i, red[i-REG_PWM0]);
			write_register(ADDR_GREEN, i, green[i-REG_PWM0]);
			write_register(ADDR_BLUE, i, blue[i-REG_PWM0]);
		}
	}

	cleanup();
}


void spatter (uint8_t *a) {
	int rpos, rval;

	rpos = random()%16;
	rval = random()%255;
	if (a[rpos] < rval) a[rpos] = rval;
}

void spread (uint8_t *a) {
	uint8_t cur[15];
	int i;

	int next, last;

	for (i=0; i<=15; i++) {
		cur[i] = a[i];
	}

	for (i=0; i<=15; i++) {
		next = i+1;
		if (next == 16) next = 0;
		last = i-1;
		if (last == -1) last = 15;

		if ((a[i] >= cur[next]) && (a[i] >= cur[last])) {
			a[i] = (int) cur[i]*.95;
		} else if (a[i] < cur[next]) {
			a[i] = (int) cur[next]*.75;
		} else if (a[i] < cur[last]) {
			a[i] = (int) cur[last]*.75;
		}
	}

//	for (i=0; i<=15; i++) {
//                if (a[i] > 255) a[i] = 0;
//        }
}

