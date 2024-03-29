# Solarium Project 2011

## About the Art

The Solarium is an art project for Burning Man 2011.  It is a domed structure about 8' in diameter and 8' tall with space inside for approximately 6 people.  The inside of the dome will be lined with color LEDs spaced every 5" which will simulate a sunrise and sunset once every 9 minutes throughout the night.  During the day solar panels will recharge a set of deep cycle batteries that power the project.

## About the Hardware

The code for this project is written in C and compiled for the Marvell™ PXA270 microprocessor.  This is the processor for the Gumstix Verdex Pro (http://www.gumstix.com/store/product_info.php?products_id=209) that will run the Solarium.

The code will communicate with the light controller devices via the I2C serial interface.  The devices are NXPs PCA9635 (http://www.nxp.com/documents/data_sheet/PCA9635.pdf).  There are 108 devices split into groups of three to control red, green or blue LEDs.  Each group of three is mounted on a PCB called a "Ray" (as in "ray of light").  Since each device can control 16 single LEDs, the Ray as a whole can control 16 RGB LEDs.  There will be 36 Rays.

## Getting Started

You'll need to setup the Gumstix buildroot to so that you can cross compile for the PXA270.  The instructions are simple, but there are a lot of dependencies required that you'll have to install:

  svn co -r 1161 http://svn.gumstix.com/gumstix-buildroot/trunk gumstix-buildroot
  cd gumstix-buildroot 
  make defconfig
  make

Getting version 1161 is important because that is the version of the image on the gumstix I currently have and other versions may not be binary compatible.  Additional resources can be found here:

  http://docwiki.gumstix.org/index.php/Buildroot

## NOTES

* applied extra/gumstix-buildroot.dff patch prior to make defconfig
* Must install texinfo
* make MAKEINFO=/usr/bin/makeinfo
* Add third parameter to open at toolchain_build_arm_nofpu/gcc-3.4.5/gcc/collect2.c:1537
* Download zlib by hand and stick it in the dl directory (sourceforge is silly).
* Add <linux/limits.h> to build_arm_nofpu/linux-2.6.18gum/scripts/mod/sumversion.c
* add -dirty suffix to KERNEL_VERSION in build_arm_nofpu/diethotplug-0.4/Makefile
* Download sysfsutils by hand and stick it in the dl directory.
