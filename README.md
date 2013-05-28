Granary-Drk
===========

A Linux kernel module instrumentation framework, Developed as an extension of DrK (Dynamorio Kernel).

Compiling Granary
=================
Granary-Drk depends on the kernel and for successful compilation of the granary modules there is a need to add kernel patches which is present in `debugging`/`linux-src`. The patch is created with Linux kernel v3.8.2.

You will also need recent version of the GCC (at least`gcc`/`g++` 4.6 or above)

To generate the list of kernel exported symbols make sure to run (with sudo) cfi/symbols/make_module.sh. This is a one time step and does not need to be repeated, unless you have build your kernel source again.

There is also need to auto-generate wrappers; use cfi/scripts/generate_wrappers.py for that.



Instrumenting kernel modules
============================
