Granary-Drk
===========

A Linux kernel module instrumentation framework, Developed as an extension of DrK (Dynamorio Kernel).

Compiling Granary
=================
Granary-Drk depends on kernel version and for successful compilation of the granary modules there is a need to add kernel patches which is present in `debugging`/`linux-src`. The patch is created with Linux kernel v3.8.2.

You will also need recent version of the GCC (at least`gcc`/`g++` 4.6 or above)

Generating symbols and wrapper
------------------------------
Grnaray uses kernel type informations and exported symbols to generate wrapper for the module. This is a one step process and doesn't need to be repeated unless you have build your kernel source again or migrating to the new kernel. This is a bit tedious process and will be removed in future updates. 

To generate symbols make sure to run (with sudo) `cfi/symbols/make_module.sh`.

Type information and wrapper generation is based on cparser(a GNU C99 declaration parser) developed by peter `https://github.com/pgoodman/cparser.git`. there is minor changes in wrapper generation scripts to make it work for this version of granary.

To generate wrappers make sure to run `cfi/scripts/make_wrapper.sh` and copy all the generated headers in `cfi/linux_wrapper/`. The script will generate both kernel wrapper and dynamic wrapper but to use these wrapper you need to update `cfi/linux_wrapper/white_list.txt` with the kernel functions you want to wrap. 

Compiling
---------
For compiling granary source : `core/build.sh`

To run granary on native system use `core/load.py --run-locally`. It provides differnt options to loading granary in VM also. This inserts the granary modules and run core/kernel_linux/controller init with your options from core/dr_options. For granary the default client is set as cfi.

load.py does following things :

`sudo insmod kernel_linux/modules/dynamorio.ko`

`sudo insmod kernel_linux/modules/dr_kernel_utils.ko`

`sudo insmod kernel_linux/modules/dynamorio_controller.ko`

`sudo insmod kernel_linux/modules/cfi.ko (default client)`

`./kernel_linux/controller init "$(cat dr_options)"`


Instrumenting kernel modules
============================
