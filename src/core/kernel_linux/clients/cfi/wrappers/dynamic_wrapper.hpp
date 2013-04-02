/*
 * dynamic_wrapper.hpp
 *
 *  Created on: 2013-01-17
 *      Author: akshayk
 */

#ifndef DYNAMIC_WRAPPER_HPP_
#define DYNAMIC_WRAPPER_HPP_


MODULE_TYPE_WRAPPER(struct inode *, {
    pre {
       // kern_printk(" inside inode module type wrapper pre\n");
      //  kern_printk("struct inode : %lx\n", arg);
        //ADD_WATCHPOINT(arg);
    }
    post {
      //  kern_printk(" inside inode module type wrapper post\n");
        //arg = arg + KERNEL_ADDRESS_OFFSET;
        //REMOVE_WATCHPOINT(arg);
    }
})


/*MODULE_TYPE_WRAPPER(struct pci_dev *, {
    pre {
        kern_printk(" inside pci_dev module type wrapper pre\n");
        kern_printk("struct pci_dev : %lx\n", arg);
        //ADD_WATCHPOINT(arg);
    }
    post {
        kern_printk(" inside pci_dev module type wrapper post\n");
        //arg = arg + KERNEL_ADDRESS_OFFSET;
        //REMOVE_WATCHPOINT(arg);
    }
})


MODULE_TYPE_WRAPPER(struct file_system_type *, {
    pre {
        kern_printk(" inside file_system_type module type wrapper pre\n");
        kern_printk("struct file_system_type : %lx\n", arg);
        //ADD_WATCHPOINT(arg);
    }
    post {
        kern_printk(" inside file_system_type module type wrapper post\n");
        //arg = arg + KERNEL_ADDRESS_OFFSET;
        //REMOVE_WATCHPOINT(arg);
    }
})


MODULE_TYPE_WRAPPER(struct super_block *, {
    pre {
        kern_printk(" inside super_block module type wrapper pre\n");
        kern_printk("struct super_block : %lx\n", arg);
        //ADD_WATCHPOINT(arg);
    }
    post {
        kern_printk(" inside super_block module type wrapper post\n");
        //arg = arg + KERNEL_ADDRESS_OFFSET;
        //REMOVE_WATCHPOINT(arg);
    }
})


MODULE_TYPE_WRAPPER(struct buffer_head *, {
    pre {
        kern_printk(" inside buffer_head module type wrapper pre\n");
        kern_printk("struct buffer_head : %lx\n", arg);
        //ADD_WATCHPOINT(arg);
    }
    post {
        kern_printk(" inside buffer_head module type wrapper post\n");
        //arg = arg + KERNEL_ADDRESS_OFFSET;
        //REMOVE_WATCHPOINT(arg);
    }
})


MODULE_TYPE_WRAPPER(struct dentry *, {
    pre {
        kern_printk(" inside dentry module type wrapper pre\n");
        kern_printk("struct dentry : %lx\n", arg);
        //ADD_WATCHPOINT(arg);
    }
    post {
        kern_printk(" inside dentry module type wrapper post\n");
        //arg = arg + KERNEL_ADDRESS_OFFSET;
        //REMOVE_WATCHPOINT(arg);
    }
})

MODULE_TYPE_WRAPPER(struct super_operations *, {
    pre {
        kern_printk(" inside super_operations module type wrapper pre\n");
        kern_printk("struct super_operations : %lx\n", arg);
        //ADD_WATCHPOINT(arg);
    }
    post {
        kern_printk(" inside super_operations module type wrapper post\n");
        //arg = arg + KERNEL_ADDRESS_OFFSET;
        //REMOVE_WATCHPOINT(arg);
    }
})


MODULE_TYPE_WRAPPER(struct inode *, {
    pre {
      //  kern_printk(" inside inode module type wrapper pre\n");
      //  kern_printk("struct inode : %lx\n", arg);
        //ADD_WATCHPOINT(arg);
    }
    post {
      //  kern_printk(" inside inode module type wrapper post\n");
        //arg = arg + KERNEL_ADDRESS_OFFSET;
        //REMOVE_WATCHPOINT(arg);
    }
})

MODULE_TYPE_WRAPPER(struct inode_operations *, {
    pre {
      //  kern_printk(" inside inode_operations module type wrapper pre\n");
      //  kern_printk("struct inode_operations : %lx\n", arg);
        //ADD_WATCHPOINT(arg);
    }
    post {
      //  kern_printk(" inside inode_operations module type wrapper post\n");
        //arg = arg + KERNEL_ADDRESS_OFFSET;
        //REMOVE_WATCHPOINT(arg);
    }
})

MODULE_TYPE_WRAPPER(struct block_device *, {
    pre {
      //  kern_printk(" inside block_device module type wrapper pre\n");
      //  kern_printk("struct block_device : %lx\n", arg);
        //ADD_WATCHPOINT(arg);
    }
    post {
      //  kern_printk(" inside block_device module type wrapper post\n");
        //arg = arg + KERNEL_ADDRESS_OFFSET;
        //REMOVE_WATCHPOINT(arg);
    }
})

MODULE_TYPE_WRAPPER(struct address_space *, {
    pre {
      //  kern_printk(" inside address_space module type wrapper pre\n");
      //  kern_printk("struct address_space : %lx\n", arg);
        //ADD_WATCHPOINT(arg);
    }
    post {
      //  kern_printk(" inside address_space module type wrapper post\n");
        //arg = arg + KERNEL_ADDRESS_OFFSET;
        //REMOVE_WATCHPOINT(arg);
    }
})

MODULE_TYPE_WRAPPER(struct address_space_operations *, {
    pre {
      //  kern_printk(" inside address_space_operations module type wrapper pre\n");
      //  kern_printk("struct address_space_operations : %lx\n", arg);
        //ADD_WATCHPOINT(arg);
    }
    post {
      //  kern_printk(" inside address_space_operations module type wrapper post\n");
        //arg = arg + KERNEL_ADDRESS_OFFSET;
        //REMOVE_WATCHPOINT(arg);
    }
})

MODULE_TYPE_WRAPPER(struct file_operations *, {
    pre {
       // kern_printk(" inside file_operations module type wrapper pre\n");
       // kern_printk("struct file_operations : %lx\n", arg);
        //ADD_WATCHPOINT(arg);
    }
    post {
       // kern_printk(" inside file_operations module type wrapper post\n");
        //arg = arg + KERNEL_ADDRESS_OFFSET;
        //REMOVE_WATCHPOINT(arg);
    }
})

MODULE_TYPE_WRAPPER(struct export_operations *, {
    pre {
      //  kern_printk(" inside export_operations module type wrapper pre\n");
    //    kern_printk("struct export_operations : %lx\n", arg);
        //ADD_WATCHPOINT(arg);
    }
    post {
     //   kern_printk(" inside export_operations module type wrapper post\n");
        //arg = arg + KERNEL_ADDRESS_OFFSET;
        //REMOVE_WATCHPOINT(arg);
    }
})

*/
#endif /* DYNAMIC_WRAPPER_HPP_ */
