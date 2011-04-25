#include "stdio.h"
#include <unistd.h>
#include <time.h>
#include "i2c/device.h"

#define ADDR_RED 4
#define ADDR_GREEN 5
#define ADDR_BLUE 2

int main( int argc, char **argv ) {
	init_devices();

	int i, r, g, b;
	time_t start, end;
	double elapsed;

	while (1) {
		for (i=REG_PWM0; i<=REG_PWM15; i++) {
			for (r=0; r<=255; r+=10) {
//start = time((char *)0);
				for (g=0; g<=255; g+=10) {
					for (b=0; b<=255; b+=10) {
        					write_register(ADDR_BLUE, i, b);
					}
        				write_register(ADDR_GREEN, i, g);
				}
				write_register(ADDR_RED, i, r);
//end = time((char *)0);
//elapsed = (end - start);
//printf("Elapsed %f : %5.2f K/s\n", elapsed, (191.25/elapsed));

			}
			write_register(ADDR_RED, i, 0);
			write_register(ADDR_GREEN, i, 0);
			write_register(ADDR_BLUE, i, 0);
		}
	}

	cleanup();
}
