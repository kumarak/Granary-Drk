/*
 * cfi_kernel_interface.c
 *
 *  Created on: 2012-04-09
 *      Author: akshayk
 */


#include <stddef.h>

#include "cfi_module.h"
#include "cfi_wrapper.h"
#include "cfi_kernel_addresses.h"
#if 0 && CFI_SEQUENTIALIZE_MODULE
#include "cfi_sequence.h"
#endif

#include <linux/kernel.h>
#include <linux/thread_info.h>

#ifdef E
#   undef E
#endif

#include "kernel_linux/clients/dcontext_extend.h"


uint64_t get_thread_private_extension(void) {
	return (uint64_t) (&(current_thread_info()->client_data));
}

enum {
    CFI_OFFSET = DR_EXTENSION(cfi),

    RETURN_STACK_OFFSET = offsetof(struct cfi_client_extension, return_address_stack),
    RETURN_STACK_SIZE_OFFSET = offsetof(struct cfi_client_extension, return_stack_size),
    EXIT_ADDRESS_OFFSET = offsetof(struct cfi_client_extension, exit_address)
};


/*enum {
  WHERE_NATIVE = 0,
  WHEREAMI_OFFSET = offsetof(struct dcontext, whereami)
};*/

void cfi_return_to_module_from_kernel(void) {

    __asm__ volatile (
		"pop %rbp;"
		"push %rbp;"
		"push %rbp;"
		"mov %rsp, %rbp;"
		"pushf;"
		"cli;"
		PUSHA
    );

    // get the thread private extension information
    // p[extension] = (struct cfi_client_extension *) dr_get_client_extension(DR_EXTENSION(cfi));
    // dr_get_client_extension takes offset in %edi
    // dr_get_client_extension returns value in %rax
    __asm__ volatile (
        "call dr_get_client_return_address_from_thread;"
        "mov %rax, 0x8(%rbp)"
    );

    // --(p[extension]->return_stack_size)

    __asm__ volatile (
		POPA
		"popf;"
		"pop %rbp;"
		"jmp dr_app_start;"
    );

}

#if 0
/// when we called into a kernel function, we stored the next native module address at the
/// top of the return address stack, and faked the return to go to 'cfi_module_interface_ret'
/// so that we would be able to re-attach DRK.
///
/// now, we have returned to here from the kernel; but, the return to the first instruction here pushed
/// rbp (as functions do), so we need to undo that. Then, we need to start DRK and tail call to the
/// native module address (which DRK will instrument).

static const unsigned long kernel_ret_addr = (unsigned long) dr_app_start_on_return;

/// DRK will call this function in place of doing a call instruction.
void cfi_call_kernel_from_module(void) {

    volatile struct cfi_client_extension *p[4];

    enum {
        extension = 3,              // -0x08(%rbp)
        original_return_addr = 2,   // -0x10(%rbp)
        wrapped_kernel_addr = 1,    // -0x18(%rbp)
        kernel_target_addr = 0      // -0x20(%rbp)
    };

    __asm__ volatile (
        PUSHA
        "pushf;"
        "cli;"
    );

    // state of the stack:
    // caller-saved base pointer                   <-.
    // ... local data?                               |
    // ... args for callee?                          |
    // return address (into caller)                  |        0x08(%rbp)
    // cfi_kernel_interface_call-saved base pointer -'   <--  0x00(%rbp)  * p[wrapped_kernel_addr]
    // p[extension]                                          -0x08(%rbp)  * old bp
    // p[original_return_addr]                               -0x10(%rbp)
    // p[wrapped_kernel_addr]                                -0x18(%rbp)
    // p[kernel_target_addr]                                 -0x20(%rbp)
    // ... saved registers                               <-- %rsp

    // get the thread private extension information

    // p[extension] = (struct cfi_client_extension *) dr_get_client_extension(DR_EXTENSION(cfi));
    // dr_get_client_extension takes offset in %edi
    // dr_get_client_extension returns value in %rax
    __asm__ volatile (
        "mov %0, %%rdi;"
        "call get_thread_private_extension;"
        "mov %%rax, -0x08(%%rbp);"
        : : "N"(CFI_OFFSET)
    );


    // p[kernel_target_addr] = p[extension]->exit_address;
    // p[extension] is in %rax
    __asm__ volatile (
        "mov %c0(%%rax), %%rdi;"
        "mov %%rdi, -0x20(%%rbp);"
        : : "N"(EXIT_ADDRESS_OFFSET)
    );

    __asm__ volatile (
        // kernel address is in %rdi, which is first param to cfi_get_kernel_wrapper
        "call cfi_get_kernel_wrapper;"  // get the kernel wrapper address
        "mov %rax, -0x18(%rbp);"

        "mov 0x08(%rbp), %rsi;"         // get the original return address
        "mov %rsi, -0x10(%rbp);"        // p[original_return_addr]
    );

    // store the original return address on the private stack
    // p[extension]->return_address_stack[(p[extension]->return_stack_size)++] = (
    //     (void *) p[original_return_addr]
    // );

    __asm__ volatile (
        // %rsi contains p[original_return_addr]

        "mov -0x08(%%rbp), %%rax;"      // %rax = &(p[extension])
        "mov %%rax, %%rbx;"             // %rbx = &(p[extension])
        "add %0, %%rbx;"                // %rbx = &(p[extension]->return_address_stack[0])

        "mov %c1(%%rax), %%rcx;"        // %rcx = p[extension]->return_stack_size
        "mov %%rsi, (%%rbx,%%rcx,8);"

        "add $0x1, %%rcx;" // ++ return_stack_size
        "mov %%rcx, %c1(%%rax);"
        : : "N"(RETURN_STACK_OFFSET), "N"(RETURN_STACK_SIZE_OFFSET)
    );

    __asm__ volatile (
        "mov $0x0, %rax;"
        "mov %rax, -0x10(%rbp);"        // hide the original return address
        "mov %rax, -0x20(%rbp);"        // hide the original target address
        "mov %rax, -0x08(%rbp);"        // hide the extension address

        "mov kernel_ret_addr, %rax;"    // overwrite return address with
        "mov %rax, 0x08(%rbp);"         // re-attach function

        "mov 0x00(%rbp), %rax;"         // duplicate the old base pointer and
        "mov %rax, -0x08(%rbp);"        // put in place of the extension

        "mov -0x18(%rbp), %rax;"        // overwrite the old base pointer with where
        "mov %rax, 0x00(%rbp);"         // we want to go

        "popf;"
        POPA                            // restore registers

        "mov -0x08(%rbp), %rbp;"        // restore old base pointer

        "lea 0x20(%rsp), %rsp;"        // pop all but extension
        "ret;"                          // jump to wrapped kernel function
    );

    (void) p;
    (void) kernel_ret_addr;
}
#endif



/// called when the kernel calls a module shadow address, which is bounced to
/// here (from the shadow)
void cfi_enter_module_from_shadow(void) {

    // implied push %rbp

    // stack looks like:
    //      <return address: in kernel>
    //      <module address>
    //      saved rbp

    __asm__ volatile (
        "push %rax;"                // save

        "mov 0x8(%rbp), %rax;"      // put return addr into rax
        "sub $0x20000005, %rax;"    // convert shadow addr to module addr
        "mov %rax, 0x8(%rbp);"      // replace return addr with module addr
    );

#if 0 && CFI_SEQUENTIALIZE_MODULE
    __asm__ __volatile__ (
        PUSHA
        "mov %rax, %rdi;"           // first arg to wait, entry point addr
        "call cfi_seq_wait_on_module;"
        POPA
    );
#endif

    __asm__ volatile (
        "pop %rax;"                 // restore

        "mov %rbp, %rsp;"
        "pop %rbp;"
        "jmp dr_app_start;"
    );

    // dr_app_start will push rbp, then when it returns, it will return to
    // the module address, which pushes rbp, and looks like a normal function
    // call
}

extern void dr_app_start_on_return(void);
static const unsigned long return_to_module_addr = (unsigned long) dr_app_start_on_return;


void cfi_exit_direct_call(void)
{
	// implicit: push %rbp
	//           mov %rsp, %rbp;

	__asm__ __volatile__ (
		// get address of the thread-private CFI info into %rdi
		"push %%rsi;"
		"push %%rax;"
		"call get_thread_private_extension;"
		"mov %%rax, %%rdi;"
		"pop %%rax;"

		// get the return address stack size into %rdx, increment it, then store it
		// back to the thread private info
		"mov %c0(%%rdi), %%rdx;"
		"add $1, %%rdx;" // this is the new stack size
		"mov %%rdx, %c0(%%rdi);"

		// now we need to go update the stack, but using the old address stack size
		"sub $1, %%rdx;" // this is the old stack size
		"add $%c1, %%rdi;" // now this is the address of the base of the stack
		"mov 0x20(%%rbp), %%rsi;"
		"mov %%rsi, (%%rdi,%%rdx,8);"
		: : "N"(RETURN_STACK_SIZE_OFFSET)
		, "N"(RETURN_STACK_OFFSET)
	);

	__asm__ __volatile (
		"pop %rsi;"
		"mov 0x28(%rbp), %rdx;"
		"push %rdx;"
		"popf;"
		//"mov return_to_module_addr, %rdx;"
		"mov %rdx, 0x28(%rbp);"
		"mov 0x18(%rbp), %rdx;"
		"mov %rdx, 0x20(%rbp);"
		"mov %rbp, %rsp;"
		"pop %rbp;"
		"pop %rdx;"
		"pop %rdi;"
		"lea 0x8(%rsp), %rsp;"
		"ret;"
	);

	(void) return_to_module_addr;
}

/// for fast return
void
cfi_exit_return_to_kernel(void)
{
	__asm__ volatile (
		"mov 0x18(%rbp), %rbx;"
		"push %rbx;"
		"popf;"
		"mov 0x10(%rbp), %rbx;"
		"mov %rbx, 0x18(%rbp);"
		"mov %rbp, %rsp;"
		"pop %rbp;"
		"pop %rbx;"
		"lea 0x8(%rsp), %rsp;"
		"ret;"
	);
}

