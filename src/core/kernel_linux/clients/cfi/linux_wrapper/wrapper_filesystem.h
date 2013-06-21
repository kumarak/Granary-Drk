/*
 * wrapper_filesystem.h
 *
 *  Created on: 2013-04-16
 *      Author: akshayk
 */

#ifndef WRAPPER_FILESYSTEM_H_
#define WRAPPER_FILESYSTEM_H_


extern "C" {
    void debug_mount_bdev( struct file_system_type * fs_type , int flags , const char * dev_name , void * data ,
        int ( * fill_super ) ( struct super_block * , void * , int ) ) {
        kern_printk("%s\n", __FUNCTION__);
    }
}

#define IS_ARG_VALID(x) \
    if((uint64_t)x < 4096)  \
    {   return; }


void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = b[i] & (1<<j);
            byte >>= j;
            kern_printk("%u", byte);
        }
    }
    kern_printk("\n");
}

#define TRACES_WATCHPOINT(arg) \
        if(is_alias_address((uint64_t)arg)){    \
            descriptor *meta_info = WATCHPOINT_META(arg);   \
            kern_printk("type id : %lx\n", type_class<decltype(arg)>::get_size());  \
            kern_printk("read shadow : ");  \
            printBits(meta_info->shadow_size, (void*)meta_info->read_shadow);   \
            kern_printk("write shadow : ");  \
            printBits(meta_info->shadow_size, (void*)meta_info->write_shadow);   \
        }

/******************************************
 * TYPE WRAPPERS
 */

#define PRE pre

//struct radix_tree_iter { unsigned long index ; unsigned long next_index ; unsigned long tags ; } ;

TYPE_WRAPPER(long unsigned int, {
        no_pre
        no_post
        no_return
})

TYPE_WRAPPER(struct radix_tree_iter*, {
        pre {
            D(kern_printk("    radix_tree_iter\n");)
        }
        no_post
        no_return
})

TYPE_WRAPPER(struct radix_tree_node*, {
        pre {
            D(kern_printk("    radix_tree_node\n");)
        }
        no_post
        no_return
})

TYPE_WRAPPER(struct radix_tree_root*, {
        pre {
            D(kern_printk("    radix_tree_root\n");)
        }
        no_post
        no_return
})



TYPE_WRAPPER(struct address_space_operations, {
        pre {
            D(kern_printk("    address_space_operations\n");)

            WRAP_FUNC(arg.writepage);
            WRAP_FUNC(arg.readpage);
            WRAP_FUNC(arg.writepages);
            WRAP_FUNC(arg.set_page_dirty);
            WRAP_FUNC(arg.readpages);
            WRAP_FUNC(arg.write_begin);
            WRAP_FUNC(arg.write_end);
            WRAP_FUNC(arg.bmap);
            WRAP_FUNC(arg.invalidatepage);
            WRAP_FUNC(arg.releasepage);
            WRAP_FUNC(arg.direct_IO);
            WRAP_FUNC(arg.get_xip_mem);
            WRAP_FUNC(arg.migratepage);
            WRAP_FUNC(arg.launder_page);
            WRAP_FUNC(arg.is_partially_uptodate);
            WRAP_FUNC(arg.error_remove_page);
        }
        no_post
        no_return
})

#ifndef WRAPPER_FOR_struct_inode
#define WRAPPER_FOR_struct_inode
TYPE_WRAPPER(struct inode*, {
    PRE{
        IS_ARG_VALID(arg);
        D(kern_printk( "added to hash table struct inode\n");)
        ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct inode));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_sb);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_op);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_fop);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_mapping);
    //    WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_mutex);
    //    WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_flock);
    //    WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_data);
    }
    NO_POST
    wrap_return {
        kern_printk("inode return wrapper !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }
    //NO_RETURN
})
#endif



#define LOOP_COUNT 5

#if 0
TYPE_WRAPPER(struct super_block, {
        pre {
            D(kern_printk("    super_block\n");)
          //  ADD_TO_HASH( &arg, SCAN_HEAD_FUNC(struct super_block));
            WRAP_RECURSIVE_KERNEL(arg.s_type);
            WRAP_RECURSIVE_KERNEL(arg.s_op);
            WRAP_RECURSIVE_KERNEL(arg.s_export_op);
            WRAP_RECURSIVE_KERNEL(arg.dq_op);
            WRAP_RECURSIVE_KERNEL(arg.s_qcop);
            WRAP_RECURSIVE(arg.s_bdev);

            if(0 != arg.s_xattr) {
                D( kern_printk("inside super_block 1 : %lx\n", arg.s_xattr); )
                    struct xattr_handler *handler = (struct xattr_handler*)*arg.s_xattr;
                for(int i=0; i < LOOP_COUNT ; i++) {
                    D(kern_printk("inside super block 2 : %lx\n", handler);)
                        WRAP_RECURSIVE_KERNEL(handler);
                    ++handler;
                }
            }
        }
                no_post
        no_return
})
#endif
#if 0
TYPE_WRAPPER(struct address_space, {
        pre {
            D( kern_printk("    address_space\n");)
                WRAP_RECURSIVE_KERNEL(arg.a_ops);
        }
                no_post
        no_return
})
#endif
#ifndef WRAPPER_FOR_struct_address_space_operations
#define WRAPPER_FOR_struct_address_space_operations
TYPE_WRAPPER(struct address_space_operations*, {
    PRE{
        IS_ARG_VALID(arg);
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct address_space_operations\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct address_space_operations));
        }
        //ABORT_IF_FUNCTION_IS_WRAPPED(arg.writepage);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->writepage);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->readpage);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->writepages);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_page_dirty);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->readpages);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_begin);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_end);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bmap);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->invalidatepage);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->releasepage);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->freepage);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->direct_IO);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_xip_mem);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->migratepage);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->launder_page);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->is_partially_uptodate);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->error_remove_page);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->swap_activate);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->swap_deactivate);
    }
    NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_address_space
#define WRAPPER_FOR_struct_address_space
TYPE_WRAPPER(struct address_space*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct address_space\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct address_space));
        }
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->host);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->a_ops);
//        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_mmap_mutex);
  //      WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->backing_dev_info);
    }
    NO_POST
    NO_RETURN
})
#endif

#ifndef WRAPPER_FOR_struct_block_device
#define WRAPPER_FOR_struct_block_device
TYPE_WRAPPER(struct block_device*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct block_device\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct block_device));
        }
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_inode);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_super);
//        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_mutex);
//        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_contains);
//        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_part);
//        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_disk);
//        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_queue);
//        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_fsfreeze_mutex);
    }
    NO_POST
    NO_RETURN
})
#endif
#if 0
TYPE_WRAPPER(struct file_system_type, {
        pre {
            D( kern_printk("    file_system_type\n"); )
            WRAP_FUNC(arg.mount);
            WRAP_FUNC(arg.kill_sb);
        }
                no_post
        no_return
})

#endif

#ifndef WRAPPER_FOR_struct_file_system_type
#define WRAPPER_FOR_struct_file_system_type
TYPE_WRAPPER(struct file_system_type*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct file_system_type\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct file_system_type));
        }
    //    ABORT_IF_FUNCTION_IS_WRAPPED(arg.mount);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mount);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->kill_sb);
      //  WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
      //  WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
    }
    NO_POST
    NO_RETURN
})
#endif




#ifndef WRAPPER_FOR_struct_super_operations
#define WRAPPER_FOR_struct_super_operations
TYPE_WRAPPER(struct super_operations*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct super_operations\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct super_operations));
        }
        //ABORT_IF_FUNCTION_IS_WRAPPED(arg.alloc_inode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->alloc_inode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->destroy_inode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dirty_inode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_inode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->drop_inode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->evict_inode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->put_super);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sync_fs);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->freeze_fs);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->unfreeze_fs);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->statfs);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->remount_fs);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->umount_begin);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->show_options);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->show_devname);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->show_path);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->show_stats);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->quota_read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->quota_write);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bdev_try_to_free_page);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->nr_cached_objects);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->free_cached_objects);
    }
    NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dquot
#define WRAPPER_FOR_struct_dquot
TYPE_WRAPPER(struct dquot*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct dquot\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dquot));
        }
       // WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dq_lock);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dq_sb);
    }
    NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dquot_operations
#define WRAPPER_FOR_struct_dquot_operations
TYPE_WRAPPER(struct dquot_operations*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct dquot_operations\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dquot_operations));
        }
        //ABORT_IF_FUNCTION_IS_WRAPPED(arg.write_dquot);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_dquot);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->alloc_dquot);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->destroy_dquot);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->acquire_dquot);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release_dquot);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mark_dirty);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_info);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_reserved_space);
    }
    NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_quotactl_ops
#define WRAPPER_FOR_struct_quotactl_ops
TYPE_WRAPPER(struct quotactl_ops*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct quotactl_ops\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct quotactl_ops));
        }
        //ABORT_IF_FUNCTION_IS_WRAPPED(arg.quota_on);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->quota_on);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->quota_on_meta);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->quota_off);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->quota_sync);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_info);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_info);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_dqblk);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_dqblk);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_xstate);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_xstate);
    }
    NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_export_operations
#define WRAPPER_FOR_struct_export_operations
TYPE_WRAPPER(struct export_operations*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct export_operations\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct export_operations));
        }
       // ABORT_IF_FUNCTION_IS_WRAPPED(arg.encode_fh);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->encode_fh);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fh_to_dentry);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fh_to_parent);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_name);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_parent);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->commit_metadata);
    }
    NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dentry
#define WRAPPER_FOR_struct_dentry
TYPE_WRAPPER(struct dentry*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct dentry\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dentry));
        }
       // WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->d_parent);
       // WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->d_inode);
       // WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->d_sb);
    }
    NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_vfsmount
#define WRAPPER_FOR_struct_vfsmount
TYPE_WRAPPER(struct vfsmount*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct vfsmount\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct vfsmount));
        }
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mnt_root);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mnt_sb);
    }
    NO_POST
    NO_RETURN
})
#endif

#ifndef WRAPPER_FOR_struct_rb_node
#define WRAPPER_FOR_struct_rb_node
TYPE_WRAPPER(struct rb_node*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct rb_node\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct rb_node));
        }
    }
    NO_POST
    NO_RETURN
})
#endif

#ifndef WRAPPER_FOR_struct_rb_root
#define WRAPPER_FOR_struct_rb_root
TYPE_WRAPPER(struct rb_root*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct rb_root\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct rb_root));
        }
    }
    NO_POST
    NO_RETURN
})
#endif

#ifndef WRAPPER_FOR_struct_posix_acl
#define WRAPPER_FOR_struct_posix_acl
TYPE_WRAPPER(struct posix_acl*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct posix_acl\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct posix_acl));
        }
    }
    NO_POST
    NO_RETURN
})
#endif

#ifndef WRAPPER_FOR_struct_percpu_counter
#define WRAPPER_FOR_struct_percpu_counter
TYPE_WRAPPER(struct percpu_counter*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct percpu_counter\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct percpu_counter));
        }
    }
    NO_POST
    NO_RETURN
})
#endif

#ifndef WRAPPER_FOR_struct_lock_class_key
#define WRAPPER_FOR_struct_lock_class_key
TYPE_WRAPPER(struct lock_class_key*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct lock_class_key\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct lock_class_key));
        }
    }
    NO_POST
    NO_RETURN
})
#endif

#ifndef WRAPPER_FOR_struct_kgid_t
#define WRAPPER_FOR_struct_kgid_t
TYPE_WRAPPER(kgid_t*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct kgid_t\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(kgid_t));
        }
    }
    NO_POST
    NO_RETURN
})
#endif

#ifndef WRAPPER_FOR_struct_umode_t
#define WRAPPER_FOR_struct_umode_t
TYPE_WRAPPER(umode_t*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct kgid_t\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(umode_t));
        }
    }
    NO_POST
    NO_RETURN
})
#endif

#if 1
#ifndef WRAPPER_FOR_struct_buffer_head
#define WRAPPER_FOR_struct_buffer_head
TYPE_WRAPPER(struct buffer_head*, {
    PRE{
        IS_ARG_VALID(arg);
        ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct buffer_head));

        if(!is_alias_address((uint64_t)arg)){
            WRAP_FUNCTION(arg->b_end_io);
        } else {
            WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->b_end_io);
        }

        //WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_this_page);
        //WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_page);
       // WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_bdev);

     //   WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_assoc_map);
    }
    NO_POST
    NO_RETURN
})
#endif
#endif
#ifndef WRAPPER_FOR_struct_timer_list
#define WRAPPER_FOR_struct_timer_list
TYPE_WRAPPER(struct timer_list*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct timer_list\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct timer_list));
        }
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->function);
    }
    NO_POST
    NO_RETURN
})
#endif

#ifndef WRAPPER_FOR_struct_page
#define WRAPPER_FOR_struct_page
TYPE_WRAPPER(struct page*, {
    PRE{
        if(!is_alias_address((uint64_t)arg)){
           D(kern_printk( "added to hash table struct page\n");)
           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct page));
        }
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mapping);
    }
    NO_POST
    NO_RETURN
})
#endif


/***********************************************
 * FUNCTION WRAPPER
 */
FUNC_WRAPPER(vm_map_ram, (struct page **pages, unsigned int count, int node, pgprot_t prot), {
        set_section_state(KERNEL_WRAPPER_SET);
        vm_map_ram(pages, count, node, prot);
        unset_section_state(KERNEL_WRAPPER_SET);
})


FUNC_WRAPPER_VOID(unlock_page, (struct page *page), {
        set_section_state(KERNEL_WRAPPER_SET);
        unlock_page(page);
        unset_section_state(KERNEL_WRAPPER_SET);
})

FUNC_WRAPPER(register_filesystem, (struct file_system_type * fs), {
        int retvar;
        if(!is_alias_address((uint64_t)fs)){
               D(kern_printk( "wrapper function register_filesystem\n");)
               ADD_TO_HASH(fs, SCAN_HEAD_FUNC(struct file_system_type));
        }
        //ADD_TO_HASH(fs, SCAN_HEAD_FUNC(struct file_system_type));
        WRAP_FUNC(fs->mount);
        WRAP_FUNC(fs->kill_sb);
        set_section_state(KERNEL_WRAPPER_SET);
        retvar = register_filesystem(fs);
        unset_section_state(KERNEL_WRAPPER_SET);
        return retvar;
})

FUNC_WRAPPER(iget_locked, (struct super_block *sb, unsigned long ino), {
        struct super_operations *arg_sop = (struct super_operations*)sb->s_op;
        ADD_TO_HASH(sb, SCAN_HEAD_FUNC(struct super_block));

        //WRAP_FUNC(TO_UNWATCHED_ADDRESS(arg_sop)->alloc_inode);
        //WRAP_FUNC(TO_UNWATCHED_ADDRESS(arg_sop)->destroy_inode);
        //WRAP_FUNC(TO_UNWATCHED_ADDRESS(arg_sop)->dirty_inode);
        //WRAP_FUNC(TO_UNWATCHED_ADDRESS(arg_sop)->write_inode);
        WRAP_RECURSIVE_KERNEL(arg_sop);
        //ADD_TO_HASH(TO_UNWATCHED_ADDRESS(sb), SCAN_HEAD_FUNC(struct super_block));
        return iget_locked(sb, ino);
})
#if 0
FUNC_WRAPPER(security_inode_init_security, ( struct inode * inode , struct inode * dir ,
        const struct qstr * qstr , initxattrs initxattrs , void * fs_data ), {
        int ret;
        if(!is_alias_address((uint64_t)inode)){
                D(kern_printk( "wrapper function register_filesystem\n");)
                ADD_TO_HASH(inode, SCAN_HEAD_FUNC(struct inode));
        }
        //REMOVE_WATCHPOINT(temp_inode);
        //WRAP_RECURSIVE_KERNEL(temp_inode->i_sb);
        //WRAP_RECURSIVE_KERNEL(temp_inode->i_op);
        //WRAP_RECURSIVE_KERNEL(temp_inode->i_fop);
        //inode = temp_inode;
        ret = security_inode_init_security(inode, dir, qstr, initxattrs, fs_data);
        return ret;
})
#endif
FUNC_WRAPPER(__bread, ( struct block_device * bdev , sector_t block , unsigned size ), {
        set_section_state(KERNEL_WRAPPER_SET);
        struct buffer_head *ret = __bread(bdev, block, size);
        unset_section_state(KERNEL_WRAPPER_SET);
        return ret;
})

FUNC_WRAPPER(jbd2_journal_blocks_per_page, (struct inode *inode), {
        int retvar;
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_fop);
        set_section_state(KERNEL_WRAPPER_SET);
        retvar = jbd2_journal_blocks_per_page(inode);
        unset_section_state(KERNEL_WRAPPER_SET);
        return retvar;
})

FUNC_WRAPPER(generic_block_fiemap, (struct inode *inode, struct fiemap_extent_info *fieinfo, u64 start, u64 len, get_block_t get_block), {
        int ret;
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_fop);
        WRAP_FUNC(get_block);
        set_section_state(KERNEL_WRAPPER_SET);
        ret = generic_block_fiemap(inode, fieinfo, start, len, get_block);
        unset_section_state(KERNEL_WRAPPER_SET);
        return ret;
})


FUNC_WRAPPER_VOID(dquot_initialize, (struct inode *inode), {
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_fop);
        set_section_state(KERNEL_WRAPPER_SET);
        dquot_initialize(inode);
        unset_section_state(KERNEL_WRAPPER_SET);
})

FUNC_WRAPPER(inode_permission, (struct inode *inode, int mask), {
        int ret;
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_fop);
        set_section_state(KERNEL_WRAPPER_SET);
        ret = inode_permission(inode, mask);
        unset_section_state(KERNEL_WRAPPER_SET);
        return ret;
})

#define APP_WRAPPER_FOR_vfs_link
FUNC_WRAPPER(vfs_link, (struct dentry *old_dentry, struct inode *dir, struct dentry *new_dentry), {
        int ret;
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(dir)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(dir)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(dir)->i_fop);
        set_section_state(KERNEL_WRAPPER_SET);
        ret = vfs_link(old_dentry, dir, new_dentry);
        unset_section_state(KERNEL_WRAPPER_SET);
        return ret;
})

FUNC_WRAPPER_VOID(make_bad_inode, (struct inode *inode), {
        int ret;
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_fop);
        set_section_state(KERNEL_WRAPPER_SET);
        make_bad_inode(inode);
        unset_section_state(KERNEL_WRAPPER_SET);
})

FUNC_WRAPPER_VOID(jbd2_journal_init_jbd_inode, (struct jbd2_inode *jinode, struct inode *inode), {
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_fop);
        set_section_state(KERNEL_WRAPPER_SET);
        jbd2_journal_init_jbd_inode(jinode, inode);
        unset_section_state(KERNEL_WRAPPER_SET);
})


FUNC_WRAPPER_VOID(iget_failed, (struct inode *inode), {
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_fop);
        set_section_state(KERNEL_WRAPPER_SET);
        iget_failed(inode);
        unset_section_state(KERNEL_WRAPPER_SET);
})

FUNC_WRAPPER(vfs_unlink, (struct inode *dir, struct dentry *dentry), {
        int ret;
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(dir)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(dir)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(dir)->i_fop);
        set_section_state(KERNEL_WRAPPER_SET);
        ret = vfs_unlink(dir, dentry);
        unset_section_state(KERNEL_WRAPPER_SET);
        return ret;
})

FUNC_WRAPPER_VOID(unlock_new_inode, (struct inode *inode), {
        TRACES_WATCHPOINT(inode);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_fop);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(TO_UNWATCHED_ADDRESS(inode)->i_mapping)->a_ops);
        set_section_state(KERNEL_WRAPPER_SET);
        unlock_new_inode(inode);
        unset_section_state(KERNEL_WRAPPER_SET);
})

FUNC_WRAPPER(d_splice_alias, (struct inode *inode, struct dentry *dentry), {
        TRACES_WATCHPOINT(inode);
        TRACES_WATCHPOINT(dentry);
        set_section_state(KERNEL_WRAPPER_SET);
        struct dentry *ret = d_splice_alias(inode, dentry);
        unset_section_state(KERNEL_WRAPPER_SET);
        return ret;
})

FUNC_WRAPPER(d_obtain_alias, (struct inode *inode), {
        TRACES_WATCHPOINT(inode);
        set_section_state(KERNEL_WRAPPER_SET);
        struct dentry *ret = d_obtain_alias(inode);
        unset_section_state(KERNEL_WRAPPER_SET);
        return ret;
})


FUNC_WRAPPER_VOID(__breadahead, ( struct block_device * bdev , sector_t block , unsigned size ), {
        TRACES_WATCHPOINT(bdev);
        set_section_state(KERNEL_WRAPPER_SET);
        __breadahead(bdev, block, size);
        unset_section_state(KERNEL_WRAPPER_SET);
})

FUNC_WRAPPER(mpage_writepages, (struct address_space *mapping, struct writeback_control *wbc, get_block_t get_block), {
   // PRE_WRAP(mapping);
   // PRE_WRAP(wbc);
    WRAP_FUNC(get_block);
    int ret = mpage_writepages(mapping, wbc, get_block);
  //  RETURN_WRAP(ret);
    return ret;
})
FUNC_WRAPPER_VOID(inode_needs_sync, (struct inode *inode), {
        int ret;
        TRACES_WATCHPOINT(inode);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_fop);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(TO_UNWATCHED_ADDRESS(inode)->i_mapping)->a_ops);
        set_section_state(KERNEL_WRAPPER_SET);
        ret = inode_needs_sync(inode);
        unset_section_state(KERNEL_WRAPPER_SET);
        return ret;
})

#if 0
//extern void __percpu_counter_add ( struct percpu_counter * fbc , s64 amount , s32 batch ) ;
FUNC_WRAPPER_VOID(__percpu_counter_add, ( struct percpu_counter * fbc , s64 amount , s32 batch ), {
        //REMOVE_WATCHPOINT(fbc);
       //set_section_state(KERNEL_WRAPPER_SET);
        __percpu_counter_add(fbc, amount, batch);
       //unset_section_state(KERNEL_WRAPPER_SET);
        //return ret;
})
#endif


FUNC_WRAPPER(mount_bdev,( struct file_system_type * fs_type , int flags , const char * dev_name , void * data ,
        int ( * fill_super ) ( struct super_block * , void * , int ) ), {
        WRAP_FUNC(fill_super);
        debug_mount_bdev(fs_type, flags, dev_name, data, fill_super);
        return mount_bdev(fs_type, flags, dev_name, data, fill_super);
})


FUNC_WRAPPER(sb_set_blocksize, ( struct super_block *sb , int i ),{
        TRACES_WATCHPOINT(sb);
        return sb_set_blocksize(sb, i);
})


extern int bio_add_page(struct bio *, struct page *, unsigned int,unsigned int);

FUNC_WRAPPER(bio_add_page, (struct bio *bio, struct page *page, unsigned int data1,unsigned int data2), {
        return bio_add_page(bio, page, data1, data2);
})

FUNC_WRAPPER_VOID(_raw_spin_lock, ( raw_spinlock_t * lock ), {
        _raw_spin_lock(lock);
})

//extern void __mark_inode_dirty ( struct inode * , int ) ;
FUNC_WRAPPER_VOID(__mark_inode_dirty, (struct inode *inode, int data), {
        int ret;
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_sb);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_op);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(inode)->i_fop);
        WRAP_RECURSIVE_KERNEL(TO_UNWATCHED_ADDRESS(TO_UNWATCHED_ADDRESS(inode)->i_mapping)->a_ops);
        set_section_state(KERNEL_WRAPPER_SET);
        __mark_inode_dirty(inode, data);
        unset_section_state(KERNEL_WRAPPER_SET);
})

FUNC_WRAPPER(block_write_begin,( struct file * file , struct address_space * mapping , loff_t pos , unsigned len , unsigned flags , struct page * * pagep , void * * fsdata , get_block_t  get_block ) , {
        WRAP_FUNC(get_block);
        return block_write_begin(file, mapping, pos, len, flags, pagep, fsdata, get_block);
})


FUNC_WRAPPER(mpage_readpage, ( struct page * page , get_block_t get_block ) , {
        WRAP_FUNC(get_block);
        return mpage_readpage(page,  get_block);
})

FUNC_WRAPPER(mpage_readpages, ( struct address_space * mapping , struct list_head * pages , unsigned nr_pages , get_block_t get_block ) , {
        WRAP_FUNC(get_block);
        return mpage_readpages(mapping, pages, nr_pages, get_block);
})

FUNC_WRAPPER(submit_bh, ( int rw , struct buffer_head * bh ), {
        int retvar;
        if(NULL != bh) {
            WRAP_FUNC(TO_UNWATCHED_ADDRESS(bh)->b_end_io);
        }
        //set_section_state(KERNEL_WRAPPER_SET);
        retvar = submit_bh(rw, bh);
       //unset_section_state(KERNEL_WRAPPER_SET);
        return retvar;
})

FUNC_WRAPPER(__block_write_begin, ( struct page * page , loff_t pos ,
                                unsigned len , get_block_t * get_block ), {
        WRAP_FUNC(get_block);
        return __block_write_begin(page, pos, len, get_block);
})

//void * radix_tree_tag_set ( struct radix_tree_root * root , unsigned long index , unsigned int tag ) ;
FUNC_WRAPPER(radix_tree_tag_set, ( struct radix_tree_root * root , unsigned long index , unsigned int tag ), {
    //REMOVE_WATCHPOINT(root);
    return radix_tree_tag_set(root, index, tag);
})

#if 0
//void * radix_tree_tag_clear ( struct radix_tree_root * root , unsigned long index , unsigned int tag ) ;
FUNC_WRAPPER(radix_tree_tag_clear, ( struct radix_tree_root * root , unsigned long index , unsigned int tag ), {
        //REMOVE_WATCHPOINT(root);
        return radix_tree_tag_clear(root, index, tag);
})
#endif

extern int __ticket_spin_is_locked(arch_spinlock_t *lock);

FUNC_WRAPPER(__ticket_spin_is_locked, (arch_spinlock_t *lock), {
        //REMOVE_WATCHPOINT(lock);
        return __ticket_spin_is_locked(lock);
})

//void delayed_work_timer_fn ( unsigned long __data ) ;
FUNC_WRAPPER_VOID(delayed_work_timer_fn, (unsigned long __data),{
    delayed_work_timer_fn(__data);
})



extern "C" {
    void debug_flush_work(struct work_struct *work){
        kern_printk("flush_work : %lx\n", work);
    }

    void debug_flush_delayed_work(struct delayed_work *dwork){
        kern_printk("flush_work : %lx\n", dwork);
    }

    void debug_queue_work(struct workqueue_struct * wq , struct work_struct * work){
        kern_printk("flush_work : %lx\n", work);
    }

    void debug_queue_delayed_work(struct workqueue_struct * wq , struct delayed_work * dwork){
        kern_printk("flush_work : %lx\n", dwork);
    }
    //destroy_workqueue
    void debug_destroy_workqueue(struct workqueue_struct * wq){
        kern_printk("flush_work : %lx\n", wq);
    }
}

FUNC_WRAPPER(flush_work,( struct work_struct * work ), {
    debug_flush_work(work);
    return flush_work(work);
})

FUNC_WRAPPER(cancel_work_sync,( struct work_struct * work ), {
    return cancel_work_sync(work);
})

FUNC_WRAPPER(flush_delayed_work,( struct delayed_work *dwork ), {
    debug_flush_delayed_work(dwork);
    return flush_delayed_work(dwork);
})


FUNC_WRAPPER(queue_work,( struct workqueue_struct * wq , struct work_struct * work ), {
    debug_queue_work(wq, work);
    return queue_work(wq , work);
})

FUNC_WRAPPER(queue_delayed_work,( struct workqueue_struct * wq , struct delayed_work * work , unsigned long delay ), {
     debug_queue_delayed_work(wq, work);
     //REMOVE_WATCHPOINT(work);
     return queue_delayed_work(wq , work, delay);
})

FUNC_WRAPPER_VOID(inode_init_once, ( struct inode *inode ) ,{
            set_section_state(KERNEL_WRAPPER_SET);
            inode_init_once(inode);
            unset_section_state(KERNEL_WRAPPER_SET);
})

//extern struct rb_node *rb_first(const struct rb_root *);
FUNC_WRAPPER(rb_first, (const struct rb_root *rb),{
        struct rb_node *retvar;
        set_section_state(KERNEL_WRAPPER_SET);
        retvar = rb_first(rb);
        unset_section_state(KERNEL_WRAPPER_SET);
        return retvar;
})

FUNC_WRAPPER(_copy_to_user, (void *to, void *from, unsigned len), {
        REMOVE_WATCHPOINT(from);
        return _copy_to_user(to, from, len);
})

FUNC_WRAPPER(_copy_from_user, (void *to, void *from, unsigned len), {
        REMOVE_WATCHPOINT(to);
        return _copy_from_user(to, from, len);
})

FUNC_WRAPPER_VOID(register_shrinker, (struct shrinker *shr), {
        WRAP_FUNC(TO_UNWATCHED_ADDRESS(shr)->shrink);
        set_section_state(KERNEL_WRAPPER_SET);
        register_shrinker(shr);
        unset_section_state(KERNEL_WRAPPER_SET);
})

FUNC_WRAPPER_VOID(unregister_shrinker, (struct shrinker *shr), {
        WRAP_FUNC(TO_UNWATCHED_ADDRESS(shr)->shrink);
        set_section_state(KERNEL_WRAPPER_SET);
        unregister_shrinker(shr);
        unset_section_state(KERNEL_WRAPPER_SET);
})

void __ticket_spin_unlock(arch_spinlock_t *lock);

FUNC_WRAPPER_VOID(__ticket_spin_unlock, (arch_spinlock_t *lock), {
        //set_section_state(KERNEL_WRAPPER_SET);
        __ticket_spin_unlock(lock);
       //unset_section_state(KERNEL_WRAPPER_SET);
})

//extern void call_rcu_sched ( struct callback_head * head , void ( * func ) ( struct callback_head * rcu ) ) ;
FUNC_WRAPPER_VOID(call_rcu_sched, ( struct callback_head * head , void (*func)( struct callback_head * rcu )), {
        WRAP_FUNC(func)
        call_rcu_sched(head, func);
})


//#if defined(CAN_WRAP_kthread_create_on_node) && CAN_WRAP_kthread_create_on_node
#   define WRAPPER_FOR_kthread_create_on_node 1
    FUNC_WRAPPER(kthread_create_on_node, (
        int (*threadfn)(void *),
        void *data,
        int node,
        const char namefmt[],
        ...
    ), {
        va_list args__;
        va_start(args__, namefmt);

        WRAP_FUNC(threadfn);
        char name_buff[sizeof(task_struct().comm)];
        vsnprintf(&(name_buff[0]), sizeof(name_buff), namefmt, args__);
        struct task_struct *ret = kthread_create_on_node(threadfn, data, node, name_buff);
        va_end(args__);
        return ret;
    })
//#endif

#if defined(CAN_WRAP_kthread_create) && CAN_WRAP_kthread_create
#   define WRAPPER_FOR_kthread_create 1
    FUNC_WRAPPER(kthread_create, (
        int (*threadfn)(void *),
        void *data,
        const char namefmt[],
        ...
    ), {
        va_list args__;
        va_start(args__, namefmt);

        WRAP_FUNC(threadfn);
        char name_buff[sizeof(task_struct().comm)];
        vsnprintf(&(name_buff[0]), sizeof(name_buff), namefmt, args__);
        struct task_struct *ret = kthread_create(threadfn, data, name_buff);
        va_end(args__);
        return ret;
    })
#endif

//unsigned int radix_tree_gang_lookup

    FUNC_WRAPPER(radix_tree_gang_lookup, (struct radix_tree_root *root, void **results,
                                    unsigned long first_index, unsigned int max_items), {
            return radix_tree_gang_lookup(root, results, first_index, max_items);
    })


#endif /* WRAPPER_FILESYSTEM_H_ */
