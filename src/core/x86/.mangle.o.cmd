cmd_/home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/mangle.o := gcc -Wp,-MD,/home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/.mangle.o.d  -nostdinc -isystem /usr/lib/gcc/x86_64-linux-gnu/4.7/include -I/home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include -Iarch/x86/include/generated -Iinclude  -include /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/include/linux/kconfig.h -D__KERNEL__ -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -O2 -m64 -mtune=generic -mno-red-zone -mcmodel=kernel -funit-at-a-time -maccumulate-outgoing-args -fstack-protector -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -DCONFIG_AS_FXSAVEQ=1 -pipe -Wno-sign-compare -fno-asynchronous-unwind-tables -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -Wframe-larger-than=1024 -Wno-unused-but-set-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -pg -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO -O3 -g -DDR_REG_ENUM_COMPATIBILITY -DX86_64 -DLINUX -DLINUX_KERNEL -I/home/akshayk/GranaryCode/Granary-Drk/src/core/lib/include -I/home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux -I/home/akshayk/GranaryCode/Granary-Drk/src/core/lib -I/home/akshayk/GranaryCode/Granary-Drk/src/core/x86 -I/home/akshayk/GranaryCode/Granary-Drk/src/core -Wframe-larger-than=4096  -DMODULE  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(mangle)"  -D"KBUILD_MODNAME=KBUILD_STR(dynamorio)" -c -o /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/.tmp_mangle.o /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/mangle.c

source_/home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/mangle.o := /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/mangle.c

deps_/home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/mangle.o := \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../globals.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../configure.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/lib/globals_shared.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/limits_wrapper.h \
  include/linux/kernel.h \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  /usr/lib/gcc/x86_64-linux-gnu/4.7/include/stdarg.h \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include/asm/linkage.h \
    $(wildcard include/config/x86/32.h) \
    $(wildcard include/config/x86/64.h) \
    $(wildcard include/config/x86/alignment/16.h) \
  include/linux/stringify.h \
  include/linux/stddef.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include/asm/types.h \
  include/asm-generic/types.h \
  include/asm-generic/int-ll64.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/linux/posix_types.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include/asm/posix_types.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include/asm/posix_types_64.h \
  include/linux/bitops.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include/asm/bitops.h \
    $(wildcard include/config/x86/cmov.h) \
  /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include/asm/alternative.h \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/paravirt.h) \
  /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include/asm/asm.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include/asm/cpufeature.h \
    $(wildcard include/config/x86/invlpg.h) \
  /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include/asm/required-features.h \
    $(wildcard include/config/x86/minimum/cpu/family.h) \
    $(wildcard include/config/math/emulation.h) \
    $(wildcard include/config/x86/pae.h) \
    $(wildcard include/config/x86/cmpxchg64.h) \
    $(wildcard include/config/x86/use/3dnow.h) \
    $(wildcard include/config/x86/p6/nop.h) \
  include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  include/asm-generic/bitops/sched.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include/asm/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/le.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/linux/swab.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include/asm/swab.h \
    $(wildcard include/config/x86/bswap.h) \
  include/linux/byteorder/generic.h \
  include/asm-generic/bitops/ext2-atomic-setbit.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/typecheck.h \
  include/linux/printk.h \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
  include/linux/dynamic_debug.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/types_wrapper.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/configure.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/signal_wrapper.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/debugging/linux-3.2.33/arch/x86/include/asm/sigcontext.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/lib/include/dr_app.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../heap.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../utils.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../config.h \
    $(wildcard include/config/h/.h) \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../stats.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../event_strings.h \
    $(wildcard include/config/file/invalid/string.h) \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../options.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../optionsx.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/os_exports.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/../os_shared.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/../globals.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/x86/arch_exports.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/configure.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/os_shared.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/x86/proc.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/x86/../link.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../vmareas.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../instrlist.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../dispatch.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/lib/dr_stats.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/lib/globals_shared.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/lib/statsx.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../kernel_linux/clients/dcontext_extend.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/arch.h \
  /usr/lib/gcc/x86_64-linux-gnu/4.7/include/stddef.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/instr.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../link.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../fragment.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../hashtable.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../hashtablex.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../instrlist.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/instr_create.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/decode.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/decode_fast.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/disassemble.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/instrument.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/../module_shared.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/module.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/kernel_interface.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/basic_types.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/static_assert.h \
  /home/akshayk/GranaryCode/Granary-Drk/src/core/types_wrapper.h \

/home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/mangle.o: $(deps_/home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/mangle.o)

$(deps_/home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/modules/../../x86/mangle.o):
