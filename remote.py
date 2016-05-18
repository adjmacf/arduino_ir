#!/usr/bin/env python3
import usb.core
import usb.util
import sys

# find our device
dev = usb.core.find(idVendor=0x0403, idProduct=0x6001)

# if it is there
if dev is None:
    raise ValueError("Device not found!")
