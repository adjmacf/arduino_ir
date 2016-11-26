#!/usr/bin/env python3

"""
This script is to be run on the host computer to listen to any Aruino Uno Serial messages
"""

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
   # if x != array.array("B", [1, 96]):
   #     print(x)

    if x == array.array("B", [1, 96, 112]):
        os.system("xdotool key space")
        #print("button hit")

    # if we detect u char for up
    elif x == array.array("B", [1, 96, 117]):
        os.system("xdotool key Up")

    # if we detect d char for down
    elif x == array.array("B", [1, 96, 100]):
        os.system("xdotool key Down")

    # if we detect left
    elif x == array.array("B", [1, 96, 108]):
        os.system("xdotool key Left")

    # if we detect right
    elif x == array.array("B", [1, 96, 114]):
        os.system("xdotool key Right")

    # if we detect select
    elif x == array.array("B", [1, 96, 115]):
        os.system("xdotool key Return")
        
    time.sleep(0.01)
