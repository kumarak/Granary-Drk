/*
 * wrappers.hpp
 *
 *  Created on: 2013-03-31
 *      Author: akshayk
 */

#ifndef WRAPPERS_HPP_
#define WRAPPERS_HPP_

#define WRAP_RECURSIVE_KERNEL(arg) \
    if(is_kernel_virtual_address_space((void*)arg)) { \
        if(IS_WATCHPOINT(arg)){ \
            REMOVE_WATCHPOINT(arg);  \
        }   \
        WRAP_RECURSIVE(arg);    \
      }


#include "kern_allocator.hpp"
#include "fs/kern_wrapper_fs.hpp"
#include "kern_wrapper_dm.hpp"

/*TYPE_WRAPPER(struct file_system_type, {
        pre {
            D( kern_printk("    file_system_type\n"); )
            WRAP_FUNC(arg.mount);
            WRAP_FUNC(arg.kill_sb);
        }
        no_post
})
*/

FUNC_WRAPPER(dm_register_target, ( struct target_type * tt ), {
	WRAP_FUNC(tt->ctr);
	WRAP_FUNC(tt->dtr);
	WRAP_FUNC(tt->map);
	WRAP_FUNC(tt->iterate_devices);
	return dm_register_target(tt);
})




extern "C" {
    void init_wrapper(void) {
        //WRAPPER_INIT();
    }
}


#endif /* WRAPPERS_HPP_ */
