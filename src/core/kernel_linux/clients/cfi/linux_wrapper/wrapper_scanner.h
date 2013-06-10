/*
 * wrapper_scanner.h
 *
 *  Created on: 2013-06-06
 *      Author: akshayk
 */

#ifndef WRAPPER_SCANNER_H_
#define WRAPPER_SCANNER_H_

#define S(...) __VA_ARGS__




/*
#ifndef SCANNER_FOR_struct_address_space
#define SCANNER_FOR_struct_address_space
TYPE_SCAN_WRAPPER(struct address_space, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct address_space);
    }
    SCAN {
        S(kern_printk( "struct address_space\n");)
        S(SCAN_OBJECT(arg);)
        IS_VALID_ADDRESS(arg)
        SCAN_RECURSIVE_PTR(arg.host);
        SCAN_RECURSIVE(arg.page_tree);
        SCAN_RECURSIVE(arg.tree_lock);
        SCAN_FUNCTION(arg.i_mmap_writable);
        SCAN_RECURSIVE(arg.i_mmap);
        SCAN_RECURSIVE(arg.i_mmap_nonlinear);
        SCAN_RECURSIVE(arg.i_mmap_mutex);
        SCAN_FUNCTION(arg.nrpages);
        SCAN_FUNCTION(arg.writeback_index);
        SCAN_RECURSIVE_PTR(arg.a_ops);
        SCAN_FUNCTION(arg.flags);
        SCAN_RECURSIVE_PTR(arg.backing_dev_info);
        SCAN_RECURSIVE(arg.private_lock);
        SCAN_RECURSIVE(arg.private_list);
        SCAN_FUNCTION(arg.private_data);
    }
})
#endif

*/

#endif /* WRAPPER_SCANNER_H_ */
