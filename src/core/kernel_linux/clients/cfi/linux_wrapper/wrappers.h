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
#define NO_RETURN

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


#include "wrapper_filesystem.h"
#include "wrapper_allocators.h"
#include "kernel_wrappers.h"

extern "C" {
    void init_wrapper(void) {
        //WRAPPER_INIT();
    }
}



#endif /* WRAPPERS_H_ */
