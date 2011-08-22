#include "device.h"
#include "i2c-dev.h"
#include "i2c-api.h"
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "Log.h"

#define NUM_DEVICES 3;

//device_t devices[3];

const char *i2cDevName = "/dev/i2c-0";
int i2cDev;

void init_devices (void) {

  if (( i2cDev = open( i2cDevName, O_RDWR )) < 0 ) {
    LogError( "Error  opening '%s': %s\n", i2cDevName, strerror( errno ));
    exit( 1 );
  }

  /* Disabled MODE1_SLEEP which is set by default, retains ALLCALL so devices
     continue to respond to this address
  */
  write_register(ADR_ALLCALL, REG_MODE1, MODE1_ALLCALL);

  /* Disables MODE2_OUTDRV which is set by default, making the LED outputs
     open-drain rather than totem-pole.  Retains LEDN1.
  */
  write_register(ADR_ALLCALL, REG_MODE2, MODE2_LEDN1);

  /* Make sure all LED outs are set for PWM */
  uint8_t all_pwm = ledout_val(LEDOUT_PWM, LEDOUT_PWM, LEDOUT_PWM, LEDOUT_PWM);

  write_register(ADR_ALLCALL, REG_LEDOUT0, all_pwm);
  write_register(ADR_ALLCALL, REG_LEDOUT1, all_pwm);
  write_register(ADR_ALLCALL, REG_LEDOUT2, all_pwm);
  write_register(ADR_ALLCALL, REG_LEDOUT3, all_pwm);
}

void cleanup (void) {
  close( i2cDev );
}

void write_register (uint8_t addr, uint8_t reg, uint8_t val) {
  int rc;

  I2cSetSlaveAddress(i2cDev, addr, I2C_NO_CRC);

  rc = I2cTransfer( i2cDev, reg, &val, 1, NULL, 0, NULL );
  //printf("\n");
}

// Expects an array of brightness values
void fast_write_brightness (uint8_t addr, uint8_t vals[], size_t num_vals) {
  int rc;

  I2cSetSlaveAddress(i2cDev, addr, I2C_NO_CRC);

  rc = I2cTransfer( i2cDev, ALL_PWM_VALS, vals, num_vals, NULL, 0, NULL );
}

