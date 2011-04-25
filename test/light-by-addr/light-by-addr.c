#include "stdio.h"
#include <unistd.h>
#include <time.h>
#include "i2c/device.h"
#include <stdlib.h>

uint8_t max_val = 255;

int main( int argc, char **argv ) {
	int red_addr, grn_addr, blu_addr;
	red_addr = atoi(argv[1]);
	grn_addr = atoi(argv[2]);
	blu_addr = atoi(argv[3]);

	printf("Lighting red: % 3d, green: % 3d, blue: % 3d\n", red_addr, grn_addr, blu_addr);
	
	init_devices();

	int i;

	for (i=REG_PWM0; i<=REG_PWM15; i++) {
		write_register(red_addr, i, 0);
		write_register(grn_addr, i, 0);
		write_register(blu_addr, i, 0);
	}

	printf("Running ...\n");
	while (1) {

		for (i=REG_PWM0; i<=REG_PWM15; i++) {
			printf(" - Red %d at 128\n", i);
			write_register(red_addr, i, 128);
			usleep(500000);
			
			printf(" - Green %d at 128\n", i);
			write_register(grn_addr, i, 128);
			usleep(500000);

			printf(" - Blue %d at 128\n", i);
			write_register(blu_addr, i, 128);
			usleep(500000);
			
			printf(" - Red %d at 255\n", i);
			write_register(red_addr, i, 255);
			usleep(500000);

			printf(" - Green %d at 255\n", i);
			write_register(grn_addr, i, 255);
			usleep(500000);

			printf(" - Blue %d at 255\n", i);
			write_register(blu_addr, i, 255);
			usleep(500000);
			
			write_register(red_addr, i, 0);
			write_register(grn_addr, i, 0);
			write_register(blu_addr, i, 0);
		}
	}

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
