/*
 * cfi_module.h
 *
 *  Created on: 2012-04-02
 *      Author: akshayk
 */

#ifndef CFI_MODULE_H_
#define CFI_MODULE_H_

#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/pfn.h>
#include <linux/gfp.h>
#include <asm/cacheflush.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/file.h>
#include <linux/mman.h>
#include <linux/binfmts.h>
#include <linux/version.h>
#include <linux/utsname.h>
#include <linux/kallsyms.h>
#include <linux/dcache.h>
#include <linux/fs.h>
#include <linux/jiffies.h>
#include <linux/sysctl.h>
#include <linux/err.h>

#include <asm/uaccess.h>

#include "dr_api.h"

#define OP_JMP_SIZE 5
#define STACK_SIZE 10

#define ADDRESS_PRINT(x)	\
	printk("module address : %x%x\n", (unsigned int)(((unsigned long)x >> 32) & 0xffffffff),(unsigned int)((unsigned long)x & 0xffffffff));

/// page protection
#define PF_PROT 	(1<<0)
#define PF_WRITE    (1<<1)
#define PF_USER 	(1<<2)
#define PF_RSVD 	(1<<3)
#define PF_INSTR    (1<<4)

/// define the boundaries of various address areas
#define MODULE_START_ADDR 	0xffffffffa0000000
#define MODULE_END_ADDR 	0xffffffffc0000000
#define MODULE_SHADOW_END 	0xffffffffe0000000
#define MODULE_SHADOW_END_EXTENDED 	0xffffffffff000000
#define MODULE_SHADOW_START MODULE_END_ADDR
#define VM_ALLOC	0x00000002

/// unrolling macros for applying something to all general purpose registers
#define ALL_REGS(R, R_last) \
	R(rdi, R(rsi, R(rdx, R(rbx, R(rcx, R(rax, R(r8, R(r9, R(r10, R(r11, R(r12, R(r13, R(r14, R_last(r15))))))))))))))

#define PUSH_LAST_REG(reg) \
	"push %" #reg ";"

#define PUSH_REG(reg, rest) \
	PUSH_LAST_REG(reg) \
	rest

#define POP_LAST_REG(reg) \
	"pop %" #reg ";"

#define POP_REG(reg, rest) \
	rest \
	POP_LAST_REG(reg)


/// used for counting the space needed to store all registers
#define PLUS_8_8 16
#define PLUS_8_16 24
#define PLUS_8_24 32
#define PLUS_8_32 40
#define PLUS_8_40 48
#define PLUS_8_48 56
#define PLUS_8_56 64
#define PLUS_8_64 72
#define PLUS_8_72 80
#define PLUS_8_80 88
#define PLUS_8_88 96
#define PLUS_8_96 104
#define PLUS_8_104 112
#define PLUS_8_112 116
#define PLUS_8_116 124

#define ADD_(x, y) x ## y
#define ADD(x, y) ADD_(x, y)
#define PLUS_EIGHT(_,rest) ADD(PLUS_8_, rest)
#define EIGHT(_) 8
#define TO_STRING_(a) #a
#define TO_STRING(a) TO_STRING_(a)
#define TO_STRING2(a) TO_STRING(a)

/// used to save and restore registers
#define PUSHA ALL_REGS(PUSH_REG, PUSH_LAST_REG)
#define POPA ALL_REGS(POP_REG, POP_LAST_REG)
#define PUSHA_SIZE TO_STRING(ALL_REGS(PLUS_EIGHT, EIGHT))

/// used to initialize stubs in the shadow module space
extern const unsigned long SHADOW_CALL_SIZE;
extern char SHADOW_CALL[];

int module_load_notifier(struct notifier_block *nb, unsigned long mod_state, void *vmod);
void *shadow_page_alloc(unsigned long size, unsigned long va_start, unsigned long va_end);

void drinit(client_id_t id);
void drinit_dcontext(unsigned int thread_id);

void cfi_enter_module_from_shadow(void);
void cfi_return_to_module_from_kernel(void);
void cfi_return_to_module_from_interrupt(void);
void cfi_call_kernel_from_module(void);
void cfi_direct_call_to_kernel(void);
void cfi_exit_direct_call_temp(void);
void cfi_exit_return_to_kernel(void);
uint64_t get_thread_private_extension(void);
//void cfi_exit_direct_call(struct dcontext *dcontext,uint64_t next_module_address, uint64_t kernel_wrapper_addr );


/* Granary init function*/
bool granary_module_init(void);

bool granary_module_exit(void);
#endif /* CFI_MODULE_H_ */
