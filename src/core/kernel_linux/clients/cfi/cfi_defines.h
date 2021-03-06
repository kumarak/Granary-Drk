/*
 * cfi_defines.h
 *
 *  Created on: 2013-02-01
 *      Author: akshayk
 */

#ifndef CFI_DEFINES_H_
#define CFI_DEFINES_H_

//#define CFI_NO_WATCHPOINT

//#define CLIENT_BUFFER_OVERFLOW
#define CONFIG_USING_WATCHPOINT
#define CLIENT_MEMORY_LEAK
#define CFI_DEBUG
#define USING_HASHMAP

enum {
	CFI_ALIAS_ADDRESS_NOT_ENABLED               = 0x8000000000000000ULL,
    CFI_ALIAS_ADDRESS_ENABLED                   = ~CFI_ALIAS_ADDRESS_NOT_ENABLED, // high-order bit not set

    CFI_ALIAS_ADDRESS_INDEX_MASK                = 0xffff000000000000ULL,
    CFI_ALIAS_ADDRESS_INDEX_OFFSET              = (12 * 4),
    CFI_ALIAS_ADDRESS_DISPLACEMENT_MASK         = 0x0000ffffffffffffULL
};

enum {
    CFI_ALLOC_WHITE_LIST,
    CFI_ALLOC_GREY_LIST,
    CFI_LOST_REFERENCE,
    CFI_COLLECT_LIST
};

enum WATCHPOINT_CONTEXT_STATE {
    WP_MEMORY_ALLOCATED = 0x1ULL,
    WP_MEMORY_FREED = 0x2ULL,
    WP_MEMORY_REACHABLE = 0x4ULL,
    WP_MEMORY_UNREACHABLE = 0x8ULL,
    WP_DESCRIPTOR_ACTIVE = 0x10ULL,
    WP_DESCRIPTOR_KERNEL_ALLOC = 0x20ULL,
};

enum section_state {
    DYNAMIC_WRAPPER_SET = 0x1ULL,
    KERNEL_WRAPPER_SET  = 0x10ULL
};

typedef struct {
    const char *name;
    void    *start;
    unsigned long  size;
    void    *replace_func;
    void    *wrapper_func;
    void    *pre_wrapper;
    void    *post_wrapper;
} function_t;

typedef unsigned gfp_t;

#define WRAP_FUNCTION(fn_name, ret_type, nargs, ...) \
        ret_type (*fn_name)(__VA_ARGS__);

typedef struct mem_allocator {
#include "slubx.h"
}mem_allocator_t;

#undef WRAP_FUNCTION

#define DISPLAY_STRING(msg) dr_printf("%s\n", msg);
#define NULL_TERMINATE(buf) buf[(sizeof(buf)/sizeof(buf[0])) - 1] = '\0'




#endif /* CFI_DEFINES_H_ */
