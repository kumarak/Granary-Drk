/*
 * kernel_wrapper.hpp
 *
 *  Created on: 2013-02-27
 *      Author: akshayk
 */

#ifndef KERNEL_WRAPPER_HPP_
#define KERNEL_WRAPPER_HPP_

/*
FUNC_WRAPPER(dquot_alloc_space, (struct inode *inode, qsize_t number, int warn), {
        struct inode *temp_inode = inode;
        int ret;
        REMOVE_WATCHPOINT(temp_inode);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //inode = temp_inode;
        ret = dquot_alloc_space(inode, number, warn);
        return ret;
})
*/

// percpu pointer alloc

FUNC_WRAPPER(__percpu_counter_init, ( struct percpu_counter *fbc, s64 amount, struct lock_class_key *key ), {
        kern_printk("__percpu_counter_init wrapper\n");
        int ret_val =  __percpu_counter_init(fbc, amount, key);
        //ADD_WATCHPOINT(TO_UNWATCHED_ADDRESS(fbc)->counters, sizeof(s32));
        //fbc = temp_fbc;
        return ret_val;
})

//void percpu_counter_destroy(struct percpu_counter *fbc)
FUNC_WRAPPER_VOID(percpu_counter_destroy, (struct percpu_counter *fbc), {
        kern_printk("percpu_counter_destroy wrapper\n");
        //REMOVE_WATCHPOINT(TO_UNWATCHED_ADDRESS(fbc)->counters);
        percpu_counter_destroy(fbc);
})



#endif /* KERNEL_WRAPPER_HPP_ */
