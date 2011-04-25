/*

  This header contains the constants and data structures used in interacting
  with mutliple PCA9635 LED dimmer devices over i2c.

 */

#include <stdint.h>

/* Registers */
#define REG_MODE1   0x00 /* Mode registers: Set behavior of PCA9635 */
#define REG_MODE2   0x01
#define REG_PWM0    0x02 /* PWM registers: Set PWM for each LED */
#define REG_PWM1    0x03
#define REG_PWM2    0x04
#define REG_PWM3    0x05
#define REG_PWM4    0x06
#define REG_PWM5    0x07
#define REG_PWM6    0x08
#define REG_PWM7    0x09
#define REG_PWM8    0x0A
#define REG_PWM9    0x0B
#define REG_PWM10   0x0C
#define REG_PWM11   0x0D
#define REG_PWM12   0x0E
#define REG_PWM13   0x0F
#define REG_PWM14   0x10
#define REG_PWM15   0x11
#define REG_GRPPWM  0x12 /* Group duty cycle control */
#define REG_GRPFREQ 0x13 /* Group frequency */
#define REG_LEDOUT0 0x14 /* Controls behavior of PWM in groups of 4 LEDs */
#define REG_LEDOUT1 0x15
#define REG_LEDOUT2 0x16
#define REG_LEDOUT3 0x17
#define REG_SUBADR1 0x18 /* User programmable I2C subaddress 1-3 */
#define REG_SUBADR2 0x19
#define REG_SUBADR3 0x1A
#define REG_ALLCALLADR 0x1B /* All call I2C address */

/* Register MODE1 bits.  OR these together */
#define MODE1_AI2     0x80 // 0b10000000
#define MODE1_AI1     0x40 // 0b01000000
#define MODE1_AI0     0x20 // 0b00100000
#define MODE1_SLEEP   0x10 // 0b00010000
#define MODE1_SUB1    0x08 // 0b00001000
#define MODE1_SUB2    0x04 // 0b00000100
#define MODE1_SUB3    0x02 // 0b00000010
#define MODE1_ALLCALL 0x01 // 0b00000001

/* Register MODE2 bits.  OR these together */
#define MODE2_DMBLNK 0x20 // 0b00100000
#define MODE2_INVRT  0x10 // 0b00010000
#define MODE2_OCH    0x08 // 0b00001000
#define MODE2_OUTDRV 0x04 // 0b00000100
#define MODE2_LEDNZ  0x02 // 0b00000010 /* These define how LED outputs repond to */
#define MODE2_LEDN1  0x01 // 0b00000001 /* the MODE2_OUTDRV setting.  For PWM use */
#define MODE2_LEDN0  0x00 // 0b00000000 /* this isn't important                   */

/* Register LEDOUTX bits */
#define LEDOUT_DIMPWM 0x03
#define LEDOUT_PWM    0x02
#define LEDOUT_ON     0x01
#define LEDOUT_OFF    0x00

/* The full LEDOUT value is 8 bits with 2 bits for each LED.  This macro sets
   the full 8 bit value given 4 LEDOUT_X values, e.g:

     ledout_val(LEDOUT_PWM, LEDOUT_PWM, LEDOUT_PWM, LEDOUT_PWM)

   This would return a value setting all 4 of the LEDs for a LEDOUT group to PWM
*/
#define ledout_val(ldr3, ldr2, ldr1, ldr0) (ldr3<<6 | ldr2<<4 | ldr1<<2 | ldr0)

/* Reserved Addresses */

/* Adresses all devices on the I2C bus */
#define ADR_ALLCALL 0x70

/* Software reset */
#define ADR_SWRESET 0x03

/* High speed mode

/*
   Sub addresses are programmable via the REG_SUBADRX register.  These are the
   default startup values for these and can be changed.  Disabled by default
*/
#define ADR_SUBADR1 0x71
#define ADR_SUBADR2 0x72
#define ADR_SUBADR3 0x74

/* Data Types */

/* A device stores values for the device, its address and whether it needs to
   be updated
*/

typedef struct device {
  uint8_t addr;
  uint8_t val[8];
  uint8_t updated;
} device_t;

typedef struct beam {
  uint8_t *red;
  uint8_t *green;
  uint8_t *blue;
} beam_t;

typedef struct ray {
  beam_t   beams[16];
  device_t *devices[3];
} ray_t;

/* A ring stores pointers to individual beams */
typedef beam_t *ring_t;

/* A ringset stores points to each ring in the Solarium */
typedef ring_t *ringset_t;

/* Function Prototypes */

void init_devices (void);
void cleanup (void);
void write_register (uint8_t addr, uint8_t reg, uint8_t val);
