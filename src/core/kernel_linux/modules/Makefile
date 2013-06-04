
EXTRA_CFLAGS=-O1 -g3 $(DR_INCLUDE_FLAGS) -Wuninitialized -Wframe-larger-than=4096
#EXTRA_CFLAGS=-O1 -g $(DR_INCLUDE_FLAGS) -Werror -Wframe-larger-than=4096


CXX_FLAGS = -nostdlib -fno-exceptions -fno-rtti -std=c++0x -O0 -g3 \
			-funit-at-a-time -fno-rtti -fno-exceptions -fno-omit-frame-pointer #-foptimize-sibling-calls

EXTRA_AFLAGS=$(DR_INCLUDE_FLAGS)\
 -Xassembler -mmnemonic=intel -Xassembler -msyntax=intel -Xassembler -mnaked-reg\
 -Xassembler --noexecstack -Xassembler --64

	obj-m += dynamorio_controller.o
	dynamorio_controller-objs :=\
../../kernel_linux/dynamorio_controller_module.o\
../../kernel_linux/simple_tests/wrap.o\
../../kernel_linux/simple_tests/recurse.o\
../../kernel_linux/simple_tests/retaddr.o\
../../kernel_linux/simple_tests/eflags.o\
../../kernel_linux/simple_tests/eflags_asm.o\
../../kernel_linux/simple_tests/fib.o\
../../kernel_linux/simple_tests/xsave.o\
../../kernel_linux/simple_tests/exception_asm.o\
../../kernel_linux/simple_tests/repstr.o\
../../kernel_linux/simple_tests.o

	obj-m += dynamorio.o
	dynamorio-objs :=\
../../exports.o\
../../buildmark.o\
../../config.o\
../../dispatch.o\
../../dynamo.o\
../../emit.o\
../../fcache.o\
../../fragment.o\
../../hashtable.o\
../../heap.o\
../../hotpatch.o\
../../instrlist.o\
../../io.o\
../../link.o\
../../loader_shared.o\
../../moduledb.o\
../../module_list.o\
../../monitor.o\
../../nudge.o\
../../options.o\
../../perfctr.o\
../../perscache.o\
../../rct.o\
../../stats.o\
../../synch.o\
../../unit-rct.o\
../../utils.o\
../../barrier.o\
../../vmareas.o\
../../x86/arch.o\
../../x86/decode.o\
../../x86/decode_fast.o\
../../x86/decode_table.o\
../../x86/disassemble.o\
../../x86/emit_utils.o\
../../x86/encode.o\
../../x86/instr.o\
../../x86/instrument.o\
../../x86/interp.o\
../../x86/loadtoconst.o\
../../x86/mangle.o\
../../x86/optimize.o\
../../x86/proc.o\
../../x86/retcheck.o\
../../x86/sideline.o\
../../x86/steal_reg.o\
../../x86/x86_code.o\
../../x86/asm_defines.o\
../../x86/x86.o\
../../x86/watchpoints.o\
../../kernel_linux/os.o\
../../kernel_linux/hypercall_guest.o\
../../kernel_linux/page_table.o\
../../kernel_linux/kernel_interface.o\
../../kernel_linux/dynamorio_module_interface.o\
../../kernel_linux/dynamorio_module.o \
../../kernel_linux/code_cache_kernel.o

obj-m += dr_kernel_utils.o
	dr_kernel_utils-objs :=\
../../kernel_linux/dr_kernel_utils.o\
../../kernel_linux/trace/granary_trace.o\
../../kernel_linux/trace/trace_file.o\
../../kernel_linux/trace/trace_buffer.o

obj-m += instrcount.o
	instrcount-objs :=\
../../kernel_linux/clients/instrcount_module.o

#obj-m += stress_dead_reg.o
#	stress_dead_reg-objs :=\
#../../kernel_linux/clients/stress_dead_reg_module.o
#
#obj-m += cleancall.o
#	cleancall-objs :=\
#../../kernel_linux/clients/cleancall_module.o
#
#obj-m += client_codecache.o
#	client_codecache-objs :=\
#../../kernel_linux/clients/client_codecache.o
#
#obj-m += client_cleancall_codecache.o
#	client_cleancall_codecache-objs :=\
#../../kernel_linux/clients/client_cleancall_codecache.o

#obj-m += umbra.o
#	umbra-objs :=\
#../../kernel_linux/clients/umbra/analyzer.o\
#../../kernel_linux/clients/umbra/cfg.o\
#../../kernel_linux/clients/umbra/dr_client.o\
#../../kernel_linux/clients/umbra/instrument.o\
#../../kernel_linux/clients/umbra/optimize.o\
#../../kernel_linux/clients/umbra/shadow.o\
#../../kernel_linux/clients/umbra/table.o\
#../../kernel_linux/clients/umbra/umbra.o\
#../../kernel_linux/clients/umbra/utils.o\
#../../kernel_linux/clients/umbra/memcheck.o\
#../../kernel_linux/clients/umbra/memcheck_test.o\
#../../kernel_linux/clients/umbra/pagepool.o

obj-m += cfi.o
	cfi-objs :=\
../../kernel_linux/clients/cfi/cfi_module.o	\
../../kernel_linux/clients/cfi/cfi_notifier.o \
../../kernel_linux/clients/cfi/cfi_instrument.o \
../../kernel_linux/clients/cfi/cfi_kernel_interface.o \
../../kernel_linux/clients/cfi/cfi_wrapper.cc \
../../kernel_linux/clients/cfi/cfi_wrapper.o \
../../kernel_linux/clients/cfi/cfi_atomic.o \
../../kernel_linux/clients/cfi/cfi_address_logger.o	\
../../kernel_linux/clients/cfi/cfi_debug_log.o	\
../../kernel_linux/clients/cfi/cfi_memory_leak.o \
../../kernel_linux/clients/cfi/cfi_utils.o	\
../../kernel_linux/clients/cfi/cfi_insert_call.o	\
../../kernel_linux/clients/cfi/cfi_atomic_list.o	\
../../kernel_linux/clients/cfi/cfi_thread.o	\
../../kernel_linux/clients/cfi/cfi_hashtable.o \
../../kernel_linux/clients/cfi/cfi_memleak_instr.o \
../../kernel_linux/clients/cfi/cfi_hotpatch.o	\
../../kernel_linux/clients/cfi/cfi_buffer_overflow.o
#\
../../kernel_linux/clients/cfi/linux_wrapper/linux_wrapper.o

# make the kernel wrappers; this is such an ugly hack
SYS_MAP := $(DR_CORE_DIR)/../debugging/linux-3.8.2/System.map
#SYS_MAP := /boot/System.map-$(shell uname -r)
$(DR_CORE_DIR)/kernel_linux/modules/../../kernel_linux/clients/cfi/cfi_wrapper.cc: $(DR_CORE_DIR)/kernel_linux/clients/cfi/cfi_wrapper.hpp $(DR_CORE_DIR)/kernel_linux/clients/cfi/wrappers/white_list.txt $(DR_CORE_DIR)/kernel_linux/clients/cfi/types/kernel_types.hpp
	sudo cp $(SYS_MAP) $(DR_CORE_DIR)/kernel_linux/clients/cfi/wrappers/map.txt
	bash  $(DR_CORE_DIR)/symbols.sh $(DR_CORE_DIR)/../debugging/linux-3.8.2/Module.symvers $(DR_CORE_DIR)/kernel_linux/clients/cfi/wrappers/exported_syms
	sudo python $(DR_CORE_DIR)/kernel_linux/clients/cfi/make_wrappers.py $(DR_CORE_DIR)/kernel_linux/clients/cfi/
	g++ -mcmodel=kernel $(CXX_FLAGS) -DX86_64 -DLINUX -DLINUX_KERNEL -I$(GUEST_KERNELDIR)/include -I$(GUEST_KERNELDIR)/arch/x86/include -I$(DR_CORE_DIR) -c $(DR_CORE_DIR)/kernel_linux/clients/cfi/cfi_wrapper.cc \
		-o $(DR_CORE_DIR)/kernel_linux/clients/cfi/cfi_wrapper.o
	g++ -mcmodel=kernel $(CXX_FLAGS) -DX86_64 -DLINUX -DLINUX_KERNEL -I$(GUEST_KERNELDIR)/include -I/usr/include/ -I$(GUEST_KERNELDIR)/arch/x86/include -I$(DR_CORE_DIR)  \
		$(c_flags) -c -o $(DR_CORE_DIR)/kernel_linux/clients/cfi/.tmp_cfi_wrapper.cc $(DR_CORE_DIR)/kernel_linux/clients/cfi/cfi_wrapper.cc
	cp $(DR_CORE_DIR)/kernel_linux/clients/cfi/cfi_wrapper.cc $(DR_CORE_DIR)/kernel_linux/clients/cfi/cfi_wrapper.gen.cc
	$(cmd_modversions_cpp)
	$(call echo-cmd,record_mcount_cpp)
	$(cmd_record_mcount_cpp)
	scripts/basic/fixdep $(depfile) $@ '$(call make-cmd,cpp_o_c)' > $(dot-target).tmp;
	rm -f $(depfile);
	mv -f $(dot-target).tmp $(dot-target:.cc=.o).cmd
	
#../../kernel_linux/clients/cfi/cfi_inat_tables.h: ../../kernel_linux/clients/cfi/x86-opcode-map.txt 
#	LC_ALL=C awk -f ../../kernel_linux/clients/cfi/gen-insn-attr-x86.awk $< > $@

#obj-m += bb_stats.o
#	bb_stats-objs :=\
#../../kernel_linux/clients/bb_stats.o

obj-m += null.o
	null-objs :=\
../../kernel_linux/clients/null.o
