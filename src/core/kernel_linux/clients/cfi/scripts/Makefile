
#KERNEL_DIR ?= /lib/modules/$(shell uname -r)/build
KERNEL_DIR ?= /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.8.2
PWD = $(shell pwd)
UNAME = $(shell uname)

#compilation toolchain
GR_CPP = cpp
GR_CC = gcc
GR_LD = gcc
GR_LDD = ldd
GR_CXX = g++-4.7
GR_CXX_STD = -std=gnu++0x
GR_PYTHON = python

#later used command options
GR_MAKE =
GR_CLEAN =
GR_OUTPUT_FORMAT =

#Compilation option
GR_DEBUG_LEVEL = -g3 -O4
GR_LD_PREFIX_FLAG = 
GR_LD_SUFFIX_FLAG =
GR_ASM_FLAGS = -I$(PWD)
GR_CC_FLAGS = -I$(PWD) $(GR_DEBUG_LEVEL)
GR_CXX_FLAGS = -I$(PWD) $(GR_DEBUG_LEVEL) -fno-rtti
GR_CXX_FLAGS += -fno-exceptions -Wall -Werror -Wextra -Wstrict-aliasing=2
GR_CXX_FLAGS += -Wno-variadic-macros -Wno-long-long -Wno-unused-function
GR_CXX_FLAGS += -Wno-format-security -funit-at-a-time -Wshadow

GR_EXTRA_CC_FLAGS ?=
GR_EXTRA_CXX_FLAGS ?=
GR_EXTRA_LD_FLAGS ?=

# Options for generating type information.
GR_TYPE_CC = $(GR_CC)
GR_TYPE_CC_FLAGS =
GR_INPUT_TYPES =
GR_OUTPUT_TYPES =
GR_OUTPUT_WRAPPERS =

GR_TYPE_INCLUDE = 

# Conditional compilation for kernel code; useful for testing if Granary code
# compiles independent of the Linux kernel.
KERNEL ?= 1

# Enable address sanitizer on Granary? Default is 2, which means it is
# "unsupported", i.e. llvm was not compiled with compiler-rt.
GR_ASAN ?= 2

# Enable libc++? (llvm's c++ standard library)
GR_LIBCXX ?= 0


# Are we making a DLL for later dynamic linking?
GR_DLL ?= 0
GR_OUTPUT_PREFIX =
GR_OUTPUT_SUFFIX = .out

ifneq (,$(findstring gcc,$(GR_CC))) # gcc
	GR_CC_FLAGS += -fdiagnostics-show-option
	GR_TYPE_CC_FLAGS += -fdiagnostics-show-option
	GR_CXX_FLAGS += -fdiagnostics-show-option
endif

GR_CXX_FLAGS += $(GR_CXX_STD)

# pass the debug / optimisation settings to the kernel's makefile.
EXTRA_CFLAGS = $(GR_DEBUG_LEVEL)

GR_COMMON_KERNEL_FLAGS = 

ifneq (,$(findstring clang,$(GR_CC))) # clang
	GR_COMMON_KERNEL_FLAGS += -mkernel -mcmodel=kernel -fno-builtin
	GR_COMMON_KERNEL_FLAGS += -ffreestanding
else # gcc
	GR_COMMON_KERNEL_FLAGS += -mcmodel=kernel -maccumulate-outgoing-args
	GR_COMMON_KERNEL_FLAGS += -nostdlib -nostartfiles -nodefaultlibs
endif

# common flags to disable certain user space features for the kernel
GR_COMMON_KERNEL_FLAGS += -mno-red-zone -mno-3dnow -fno-stack-protector
GR_COMMON_KERNEL_FLAGS += -mno-sse -mno-sse2 -mno-mmx -m64 -march=native
GR_COMMON_KERNEL_FLAGS += -fno-asynchronous-unwind-tables -fno-common

GR_INPUT_TYPES = types.h
GR_OUTPUT_TYPES = kernel_types.h
GR_OUTPUT_WRAPPERS = kernel_wrappers.h
GR_OUTPUT_SCANNERS = kernel_scanners.h
GR_OUTPUT_FUNCTION_WRAPPER = function_wrapper.h
GR_OUTPUT_DYNAMIC_WRAPPERS = dynamic_wrappers.h

GR_MAKE = make -C $(KERNEL_DIR) M=$(PWD) modules
GR_CLEAN = make -C $(KERNEL_DIR) M=$(PWD) clean
GR_OUTPUT_FORMAT = S

GR_TYPE_CC_FLAGS += $(GR_COMMON_KERNEL_FLAGS)
GR_TYPE_CXX_FLAGS += $(GR_COMMON_KERNEL_FLAGS)
GR_ASM_FLAGS += -DGRANARY_IN_KERNEL=1
GR_CC_FLAGS += $(GR_COMMON_KERNEL_FLAGS) -S -DGRANARY_IN_KERNEL=1
GR_CXX_FLAGS += $(GR_COMMON_KERNEL_FLAGS) -S -DGRANARY_IN_KERNEL=1

GR_TYPE_INCLUDE = -I./ -isystem $(KERNEL_DIR)/include
GR_TYPE_INCLUDE += -isystem $(KERNEL_DIR)/arch/x86/include
GR_TYPE_INCLUDE += -isystem $(KERNEL_DIR)/arch/x86/include/generated

GR_CC_FLAGS += $(GR_EXTRA_CC_FLAGS)
GR_CXX_FLAGS += $(GR_EXTRA_CXX_FLAGS)

types:
	$(GR_TYPE_CC) $(GR_TYPE_CC_FLAGS) $(GR_TYPE_INCLUDE) -E $(GR_INPUT_TYPES) > /tmp/ppt.h
	$(GR_PYTHON) post_process_header.py /tmp/ppt.h > /tmp/ppt2.h
	$(GR_PYTHON) reorder_header.py /tmp/ppt2.h > $(GR_OUTPUT_TYPES)


# auto-generate wrappers
wrappers: types
	$(GR_PYTHON) generate_wrappers.py $(GR_OUTPUT_TYPES) > $(GR_OUTPUT_WRAPPERS)
	$(GR_PYTHON) generate_function_wrapper.py $(GR_OUTPUT_TYPES) > $(GR_OUTPUT_FUNCTION_WRAPPER)
	$(GR_PYTHON) generate_dynamic_wrappers.py $(GR_OUTPUT_TYPES) > $(GR_OUTPUT_DYNAMIC_WRAPPERS)

scanners: types
	$(GR_PYTHON) generate_scanner.py $(GR_OUTPUT_TYPES) > $(GR_OUTPUT_SCANNERS)

detach: types
	@$(GR_PYTHON) generate_detach_table.py $(GR_OUTPUT_TYPES) detach.inc 
	@$(call GR_GET_LD_LIBRARIES)
	@echo "  DETACH [GR] granary/gen/detach.inc"
