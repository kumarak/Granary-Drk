#!/bin/bash

SMP=2
MEM=2048
NETWORK=virtio
GRAPHIC= #-nographic
GRAPHIC_FLAG=0

QEMU=$(which qemu-system-x86_64)
#qemu-system-x86_64 -smp 1 -m 2048 -s -hda /home/akshayk/GranaryCode/ubuntu.qcow2 -net nic,model=virtio -net "user,hostfwd=tcp::5556-:22" &
$QEMU -smp $SMP -s -m $MEM $GRAPHIC -hda /home/akshayk/GranaryCode/ubuntu.qcow2 -net nic,model=$NETWORK -net "user,hostfwd=tcp::5556-:22" &


