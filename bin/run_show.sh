#!/bin/sh

/home/root/bin/sunshow > /dev/null 2>&1

RET_CODE=$?

if [ "$RET_CODE" != "0" ]; then
       /sbin/reboot
fi
