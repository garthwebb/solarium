#############################################################################
#
#	Makefile for building the Hello World sample program
#
#############################################################################

ifeq ($(DEBUG),y)
	CFLAGS += -O -g	-Wall	# -O is need to expand inlines
else
	CFLAGS += -O2 -Wall
endif

TARGET	= sun-test

PWD     := $(shell pwd)
SOLARIUM_ROOT = $(PWD)/../..
SOLARIUM_LIB  = $(SOLARIUM_ROOT)/lib

GUMSTIX_BUILDROOT   = $(SOLARIUM_ROOT)/../gumstix/gumstix-buildroot
BUILD_ARM           = $(wildcard $(GUMSTIX_BUILDROOT)/build_arm*)
CROSS_COMPILE       = $(patsubst %gcc, %, $(wildcard $(BUILD_ARM)/staging_dir/bin/arm-linux-uclibc*-gcc))

ifeq ($(strip $(CROSS_COMPILE)),)
$(error Unable to detect Cross Compiler)
endif

TARGET_ARCH=-Os -march=armv5te -mtune=xscale -Wa,-mcpu=xscale
CC = $(CROSS_COMPILE)gcc

#
# If you need additional serch paths for include files, then use the -I flag
# and add them to the CPPFLAGS variable
#

CPPFLAGS += -I $(SOLARIUM_LIB)

#
# If you need addional search paths for library files, then use the -L flag
# and add them to LDFLAGS.
#

LDFLAGS += -static -s

#
# If you need additional libraries, then use -lxxx to search for libxxx.a
#

# LDLIBS += -lxxx

.PHONY: all

all:	depend $(TARGET)

#
# You can change the $(TARGET).c if that's not your main file and you can
# add additional .o files to the end of the line
#

SRCS	= $(TARGET).c $(SOLARIUM_LIB)/i2c/device.c $(SOLARIUM_LIB)/i2c/i2c-api.c $(SOLARIUM_LIB)/i2c/DumpMem.c $(SOLARIUM_LIB)/i2c/Log.c $(SOLARIUM_LIB)/solarium-types.c $(SOLARIUM_LIB)/solarium-draw.c
OBJS	= $(SRCS:.c=.o)
		     
$(TARGET) : $(OBJS)

clean:
	rm -rf $(OBJS) core .depend $(TARGET)

depend .depend dep:
	$(CC) $(CFLAGS) $(CPPFLAGS) -M $(SRCS) > .depend

ifeq (.depend,$(wildcard .depend))
include .depend
endif

upload:
	scp $(TARGET) 192.168.1.141:/home/garth/bin

