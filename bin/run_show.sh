#!/bin/sh

/home/root/bin/sunshow

RET_CODE=$?

if [ "$RET_CODE" != "0" ]; then
       /sbin/reboot
fi
