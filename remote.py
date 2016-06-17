#!/usr/bin/env python3
import usb.core
import usb.util
import sys
import array
import os
import time

# find our device
dev = usb.core.find(idVendor=0x0403, idProduct=0x6001)

# if it is there
if dev is None:
    raise ValueError("Device not found!")

interface = 0
endpoint = dev[0][(0,0)][0]

if dev.is_kernel_driver_active(interface) is True:
    dev.detach_kernel_driver(interface)
    usb.util.claim_interface(dev, interface)

# continually read data - when we recieve the character "p" send space keystroke
while True:
    x = dev.read(endpoint.bEndpointAddress, endpoint.wMaxPacketSize)
    if x != array.array("B", [1, 96]):
        print(x)
    if x == array.array("B", [1, 96, 0, 0]):
        os.system("xdotool key space")
        print("button hit")
        
    time.sleep(0.1)
