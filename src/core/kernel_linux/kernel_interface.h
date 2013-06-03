#ifndef __KERNEL_INTERFACE_H_
#define __KERNEL_INTERFACE_H_

#include "basic_types.h"


/* A minimal interface to the kernel. Seperated from the rest of the code not
 * for modularity but because of #include and symbol definition conflicts.
 */

bool kernel_module_init(size_t heap_size);

void kernel_module_exit(void);

bool kernel_interface_init(void);

void kernel_interface_exit(void);

bool kernel_find_dynamorio_module_bounds(byte** start, byte** end);

void* kernel_allocate_heap(size_t size);

void kernel_free_heap(void* heap);


void* kernel_allocate(size_t size);
void kernel_free(void* heap);

void debug_interrupt(struct kmem_cache*);

void*
kernel_get_thread_private_slot(size_t slot);

void*
kernel_thread_private_slot_init(size_t slot);

void *
kernel_get_thread_private_slot_from_rsp(void* rsp_ptr, size_t slot);

void*
kernel_memcpy(void *dest, void *src, size_t size);

void*
kernel_get_current(void);

bool
is_shadow_address(void *pc);


int kernel_get_online_processor_count(void);
int kernel_get_present_processor_count(void);

/* Returns the size of our TLS allocation and its offset from the kernel's GS
 * segment.
 */
void kernel_init_cpu_private_data(size_t* size, size_t* gs_offset);

/* Returns the linear address of the CPU's TLS storage. */
void* kernel_get_cpu_private_data(int cpu_id);

int kernel_get_cpu_id(void);

void kernel_run_on_all_cpus(void (*func) (void *info), void *info);

void kernel_printk(const char* fmt, ...);

#define KERNEL_ENV_NAME_MAX  50
#define KERNEL_ENV_VALUE_MAX 512

void kernel_setenv(const char* name, const char* value);
const char* kernel_getenv(const char* name);

bool kernel_native_swapgs(void* pc);

bool is_kernel_code(void* pc);
bool
is_kernel_symbol(void *pc);

/* None of these routines are safe to use after initilization. */
void* kernel_load_shared_library(char* name);
void* kernel_lookup_library_routine(void* lib, char* name);

void* get_thread_private_client_extension();

unsigned int
get_thread_private_slot(size_t slot);

void
set_thread_private_slot(size_t slot, unsigned int flag);

void*
get_stack_init_address(void);

bool kernel_shared_library_bounds(void* lib, byte* addr, byte** start,
                                  byte** end);
byte* kernel_get_module_base(byte* pc);

#endif
