/*
 * wrappers.h
 *
 *  Created on: 2013-04-16
 *      Author: akshayk
 */

#ifndef WRAPPERS_H_
#define WRAPPERS_H_

#define PRE_WRAP pre
#define POST_WRAP post
#define ABORT_IF_FUNCTION_IS_WRAPPED(x)
#define NO_PRE
#define NO_POST no_post
#define NO_RETURN no_return

#define WRAP_FUNCTION WRAP_FUNC
#define PRE_OUT_WRAP(x) WRAP_RECURSIVE(x)
#define POST_OUT_WRAP(x) WRAP_RECURSIVE(x)
/*
TYPE_WRAPPER(struct inode, {
        pre {
            D( kern_printk("    inode\n"); )

            WRAP_RECURSIVE_KERNEL(arg.i_sb);
            WRAP_RECURSIVE_KERNEL(arg.i_op);
            WRAP_RECURSIVE_KERNEL(arg.i_fop);
            WRAP_RECURSIVE_KERNEL(arg.i_mapping);
        }
        no_post
})
*/

#define WRAP_RECURSIVE_KERNEL(arg) \
    if(is_kernel_virtual_address_space((void*)arg)) { \
        if(IS_WATCHPOINT(arg)){ \
            REMOVE_WATCHPOINT(arg);  \
        }   \
        WRAP_RECURSIVE(arg);    \
      }

extern __u32 half_md4_transform(__u32 buf[4], __u32 const in[8]);
extern int trace_event_raw_init(struct ftrace_event_call *call);

extern struct posix_acl *posix_acl_from_xattr(struct user_namespace *user_ns,
                                        const void *value, size_t size);
extern int posix_acl_to_xattr(struct user_namespace *user_ns,
                       const struct posix_acl *acl, void *buffer, size_t size);

#define SCAN_OBJECT(x)    \
        unsigned long size = type_class<ArgT__>::get_size();    \
        unsigned long i = 0;    \
        uint64_t *ptr = (uint64_t*)(&x);  \
        if(NULL != ptr) {   \
            while(i < size){    \
                uint64_t value = (uint64_t)(*ptr);  \
                if(is_alias_address(value)) {   \
                    cfi_collect_watcpoint(ptr, (void*)value);   \
                }   \
                ptr++;  \
                i = i + sizeof(void*);  \
            }   \
        }


#include "kernel_scanners.h"
#include "wrapper_filesystem.h"
#include "wrapper_allocators.h"
#include "kernel_wrappers.h"
#include "dynamic_wrappers.h"


#endif /* WRAPPERS_H_ */
