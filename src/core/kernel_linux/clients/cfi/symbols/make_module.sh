#!/bin/sh
me=`logname`

host_map=/boot/System.map-`uname -r`
#client_map=/boot/System.map-`uname -r`
client_map=../../../../../debugging/linux-3.2.33/System.map

# copy the System.map into a convenient location for Python to extract all names
sudo cp $host_map ./host_map.txt
sudo chown $me ./host_map.txt

sudo cp $client_map ./client_map.txt
sudo chown $me ./client_map.txt

sudo chown $me ./symbol_get_addr.h

# use Python to extract all names into all_symbols.inc
python get_symbols.py

# make the kernel module
make clean
make

# install module
sudo insmod get_symbols.ko

# use python to extract all symbols
sudo python get_exported_symbols.py

# remove module; symbols should be there :D
sudo rmmod get_symbols

