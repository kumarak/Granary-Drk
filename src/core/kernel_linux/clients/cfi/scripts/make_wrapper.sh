#! /bin/sh

# generating kernel types
make types KERNEL_DIR=../../../../../debugging/linux-3.8.2

# generating kernel wrapper and dynamic wrappers
make wrappers KERNEL_DIR=../../../../../debugging/linux-3.8.2

# generating type scanning functions
make scanners KERNEL_DIR=../../../../../debugging/linux-3.8.2

