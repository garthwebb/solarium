#############################################################################
#
#	Makefile for building the Hello World sample program
#
#############################################################################

ifeq ($(DEBUG),y)
	CFLAGS += -O -g		# -O is need to expand inlines
else
	CFLAGS += -O2
endif

TARGET	= hello

PWD     := $(shell pwd)

GUMSTIX_BUILDROOT   = /home/garth/gumstix/gumstix-buildroot
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

# CPPFLAGS += -I somedir

#
# If you need addional search paths for library files, then use the -L flag
# and add them to LDFLAGS.
#

# LDFLAGS += -L somedir

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

SRCS	= $(TARGET).c
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
	scp $(TARGET) 192.168.1.121:/home/garth/bin

