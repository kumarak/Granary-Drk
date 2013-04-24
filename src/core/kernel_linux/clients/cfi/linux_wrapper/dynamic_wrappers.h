/*
 * dynamic_wrapper.hpp
 *
 *  Created on: 2013-03-03
 *      Author: akshayk
 */

#ifndef DYNAMIC_WRAPPER_HPP_
#define DYNAMIC_WRAPPER_HPP_

#define MAX_DEPTH 3

#define ADD_TO_HASH(key, value)\
        void *value_pair; \
        /*if(hashmap_get(kernel_pointer_hash, key,  (void**)&value_pair) != 0)*/{    \
                hashmap_put(kernel_pointer_hash, (void*)key, (void*)value); \
        }

#if 1
TYPE_SCAN_WRAPPER(struct inode*, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        hashmap_init(128, &htable);
        kern_printk("struct inode scan head: %lx\n", arg);
        if(!is_watchpoint_address(arg))
        	SCAN_FUNCTION(struct inode*)(htable, arg);
        hashmap_destroy(htable);
    }
    SCAN {
        hashmap_put(htable, (void*)arg, (void*)type_class<ArgT__>::get_size());
        SCAN_RECURSIVE(arg->i_hash);
        SCAN_RECURSIVE(arg->i_sb_list);
        SCAN_RECURSIVE(arg->i_dentry);
        SCAN_RECURSIVE(arg->i_count);
        SCAN_RECURSIVE(arg->i_atime);
        SCAN_RECURSIVE(arg->i_mtime);
        SCAN_RECURSIVE(arg->i_ctime);
        SCAN_RECURSIVE(arg->i_lock);
        SCAN_RECURSIVE(arg->i_mutex);
        SCAN_RECURSIVE(arg->i_op);
        SCAN_RECURSIVE(arg->i_fop);
        SCAN_RECURSIVE(arg->i_sb);
        SCAN_RECURSIVE(arg->i_flock);
        SCAN_RECURSIVE(arg->i_mapping);
        SCAN_RECURSIVE(arg->i_data);
        SCAN_RECURSIVE(arg->i_devices);
        SCAN_RECURSIVE(arg->i_writecount);
        SCAN_RECURSIVE(arg->i_acl);
        SCAN_RECURSIVE(arg->i_default_acl);

    }
})
#endif
#if 0
TYPE_SCAN_WRAPPER(struct inode, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        hashmap_init(128, &htable);
        SCAN_FUNCTION(struct inode)(htable, arg);
        //hashmap_destroy(htable);
    }

    SCAN {
        HASHMAP_PUT(htable, (void*)&arg, (void*)type_class<ArgT__>::get_size());
        SCAN_RECURSIVE(arg.i_hash);
        SCAN_RECURSIVE(arg.i_list);
        SCAN_RECURSIVE(arg.i_sb_list);
        SCAN_RECURSIVE(arg.i_dentry);
        SCAN_RECURSIVE(arg.i_count);
        SCAN_RECURSIVE(arg.i_atime);
        SCAN_RECURSIVE(arg.i_mtime);
        SCAN_RECURSIVE(arg.i_ctime);
        SCAN_RECURSIVE(arg.i_lock);
        SCAN_RECURSIVE(arg.i_mutex);
        SCAN_RECURSIVE(arg.i_alloc_sem);
        SCAN_RECURSIVE(arg.i_op);
        SCAN_RECURSIVE(arg.i_fop);
        SCAN_RECURSIVE(arg.i_sb);
        SCAN_RECURSIVE(arg.i_flock);
        SCAN_RECURSIVE(arg.i_mapping);
        SCAN_RECURSIVE(arg.i_data);
        SCAN_RECURSIVE(arg.i_devices);
        SCAN_RECURSIVE(arg.i_fsnotify_mark_entries);
        SCAN_RECURSIVE(arg.inotify_watches);
        SCAN_RECURSIVE(arg.inotify_mutex);
        SCAN_RECURSIVE(arg.i_writecount);
        SCAN_RECURSIVE(arg.i_acl);
        SCAN_RECURSIVE(arg.i_default_acl);
    }
})
#endif
MODULE_TYPE_WRAPPER(struct inode *, {
    pre {
#ifndef CFI_NO_WATCHPOINT
    	if(!is_watchpoint_address(arg)){
            P(kern_printk("struct inode is getting wrapped %lx\n", arg);)
            ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct inode*))
    	}
#else
        void *value;

        if(!hashmap_get(module_watchpoint_map, arg, &value)){
            kern_printk("struct inode is getting wrapped\n");
            ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct inode))
        }
#endif
    }
    no_post
#if 0
    post {
#ifndef CFI_NO_WATCHPOINT
    	if(!is_watchpoint_address(arg)){
            kern_printk("post scan struct inode %lx\n", arg);
            SCAN_HEAD_FUNC(struct inode*)(arg);
    	}
#else
        void *value;
        if(!hashmap_get(module_watchpoint_map, arg, &value)){
            kern_printk("post scan struct inode\n");
            SCAN_HEAD_FUNC(struct inode)(*arg);
        }
#endif
    }
#endif
})


TYPE_SCAN_WRAPPER(struct block_device*, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        hashmap_init(128, &htable);
        if(!is_watchpoint_address(arg))
        	SCAN_FUNCTION(struct block_device*)(htable, arg);
        hashmap_destroy(htable);
    }
    SCAN {
        HASHMAP_PUT(htable, (void*)arg, (void*)type_class<ArgT__>::get_size());
        SCAN_RECURSIVE(arg->bd_inode);
        SCAN_RECURSIVE(arg->bd_super);
        SCAN_RECURSIVE(arg->bd_mutex);
        SCAN_RECURSIVE(arg->bd_inodes);
     //   SCAN_RECURSIVE(arg->bd_holder_list);
        SCAN_RECURSIVE(arg->bd_contains);
        SCAN_RECURSIVE(arg->bd_part);
        SCAN_RECURSIVE(arg->bd_disk);
        SCAN_RECURSIVE(arg->bd_list);
        SCAN_RECURSIVE(arg->bd_fsfreeze_mutex);
    }
})

TYPE_SCAN_WRAPPER(struct block_device, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        hashmap_init(128, &htable);
        if(!is_watchpoint_address(arg))
        	SCAN_FUNCTION(struct block_device)(htable, arg);
        hashmap_destroy(htable);
    }
    SCAN {
        HASHMAP_PUT(htable, (void*)&arg, (void*)type_class<ArgT__>::get_size());
        SCAN_RECURSIVE(arg.bd_inode);
        SCAN_RECURSIVE(arg.bd_super);
        SCAN_RECURSIVE(arg.bd_mutex);
        SCAN_RECURSIVE(arg.bd_inodes);
       // SCAN_RECURSIVE(arg.bd_holder_list);
        SCAN_RECURSIVE(arg.bd_contains);
        SCAN_RECURSIVE(arg.bd_part);
        SCAN_RECURSIVE(arg.bd_disk);
        SCAN_RECURSIVE(arg.bd_list);
        SCAN_RECURSIVE(arg.bd_fsfreeze_mutex);
    }
})

MODULE_TYPE_WRAPPER(struct block_device* , {
    pre {
#ifndef CFI_NO_WATCHPOINT
    	if(!is_watchpoint_address(arg)){
            kern_printk("struct block_device is getting wrapped\n");
            ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct block_device*))
    	}
#else
        void *value;
        if(!hashmap_get(module_watchpoint_map, arg, &value)){
                kern_printk("struct block_device");
                ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct block_device))
        }
#endif
    }
    no_post
#if 0
    post {
#ifndef CFI_NO_WATCHPOINT
        if(!is_watchpoint_address(arg)){
            kern_printk("post scan struct block_device\n");
            SCAN_HEAD_FUNC(struct block_device*)(arg);
        }
#else
        void *value;
        if(!hashmap_get(module_watchpoint_map, arg, &value)){
            kern_printk("post scan struct block_device\n");
            SCAN_HEAD_FUNC(struct block_device)(*arg);
        }
#endif
    }
#endif
})


TYPE_SCAN_WRAPPER(struct file_system_type, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        hashmap_init(128, &htable);
        if(!is_watchpoint_address(arg))
        	SCAN_FUNCTION(struct file_system_type)(htable, arg);
        //hashmap_destroy(htable);
    }
    SCAN {
        HASHMAP_PUT(htable, (void*)&arg, (void*)type_class<ArgT__>::get_size());
        //SCAN_FUNC(arg.get_sb);
        SCAN_FUNC(arg.kill_sb);
        SCAN_RECURSIVE(arg.owner);
        SCAN_RECURSIVE(arg.next);
        SCAN_RECURSIVE(arg.fs_supers);
        SCAN_RECURSIVE(arg.s_lock_key);
        SCAN_RECURSIVE(arg.s_umount_key);
        SCAN_RECURSIVE(arg.i_lock_key);
        SCAN_RECURSIVE(arg.i_mutex_key);
        SCAN_RECURSIVE(arg.i_mutex_dir_key);
       // SCAN_RECURSIVE(arg.i_alloc_sem_key);
    }
})

TYPE_SCAN_WRAPPER(struct file_system_type*, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        hashmap_init(128, &htable);
        if(!is_watchpoint_address(arg))
        	SCAN_FUNCTION(struct file_system_type*)(htable, arg);
        //hashmap_destroy(htable);
    }
    SCAN {
        HASHMAP_PUT(htable, (void*)arg, (void*)type_class<ArgT__>::get_size());
        //SCAN_FUNC(arg->get_sb);
        SCAN_FUNC(arg->kill_sb);
        SCAN_RECURSIVE(arg->owner);
        SCAN_RECURSIVE(arg->next);
        SCAN_RECURSIVE(arg->fs_supers);
        SCAN_RECURSIVE(arg->s_lock_key);
        SCAN_RECURSIVE(arg->s_umount_key);
        SCAN_RECURSIVE(arg->i_lock_key);
        SCAN_RECURSIVE(arg->i_mutex_key);
        SCAN_RECURSIVE(arg->i_mutex_dir_key);
       // SCAN_RECURSIVE(arg->i_alloc_sem_key);
    }
})

MODULE_TYPE_WRAPPER(struct file_system_type* , {
    pre {
        if(!is_watchpoint_address(arg)){
                P(kern_printk("struct file_system_type");)
                ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct file_system_type*))
        }

    }
    no_post
#if 0
    post {
        if(!is_watchpoint_address(arg)){
            kern_printk("post scan struct file_system_type\n");
            SCAN_HEAD_FUNC(struct file_system_type*)(arg);
        }
    }
#endif
})


TYPE_SCAN_WRAPPER(struct super_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        hashmap_init(128, &htable);
        if(!is_watchpoint_address(arg))
        	SCAN_FUNCTION(struct super_operations)(htable, arg);
        hashmap_destroy(htable);
    }
    SCAN {
        HASHMAP_PUT(htable, (void*)&arg, (void*)type_class<ArgT__>::get_size());
        SCAN_FUNC(arg.alloc_inode);
        SCAN_FUNC(arg.destroy_inode);
        SCAN_FUNC(arg.dirty_inode);
        SCAN_FUNC(arg.write_inode);
        SCAN_FUNC(arg.drop_inode);
   //     SCAN_FUNC(arg.delete_inode);
        SCAN_FUNC(arg.put_super);
   //     SCAN_FUNC(arg.write_super);
        SCAN_FUNC(arg.sync_fs);
        SCAN_FUNC(arg.freeze_fs);
        SCAN_FUNC(arg.unfreeze_fs);
        SCAN_FUNC(arg.statfs);
        SCAN_FUNC(arg.remount_fs);
       // SCAN_FUNC(arg.clear_inode);
        SCAN_FUNC(arg.umount_begin);
        SCAN_FUNC(arg.show_options);
        SCAN_FUNC(arg.show_stats);
        SCAN_FUNC(arg.quota_read);
        SCAN_FUNC(arg.quota_write);
        SCAN_FUNC(arg.bdev_try_to_free_page);
    }
})

MODULE_TYPE_WRAPPER(struct super_operations* , {
    pre {
        if(!is_watchpoint_address(arg)){
                D( kern_printk("struct super_operations");)
                ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct super_operations))
        }

    }
    no_post
#if 0
    post {
    	if(!is_watchpoint_address(arg)){
            kern_printk("post scan struct super_operation\n");
            SCAN_HEAD_FUNC(struct super_operations)(*arg);
        }
    }
#endif
})


TYPE_SCAN_WRAPPER(struct dentry, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        hashmap_init(128, &htable);
        if(!is_watchpoint_address(arg))
            SCAN_FUNCTION(struct dentry)(htable, arg);
        hashmap_destroy(htable);
    }
    SCAN {
        HASHMAP_PUT(htable, (void*)&arg, (void*)type_class<ArgT__>::get_size());
        SCAN_RECURSIVE(arg.d_count);
        SCAN_RECURSIVE(arg.d_lock);
        SCAN_RECURSIVE(arg.d_inode);
        SCAN_RECURSIVE(arg.d_hash);
        SCAN_RECURSIVE(arg.d_parent);
        SCAN_RECURSIVE(arg.d_name);
        SCAN_RECURSIVE(arg.d_lru);
        SCAN_RECURSIVE(arg.d_subdirs);
        SCAN_RECURSIVE(arg.d_alias);
        SCAN_RECURSIVE(arg.d_op);
        SCAN_RECURSIVE(arg.d_sb);
    }
})

TYPE_SCAN_WRAPPER(struct dentry*, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        hashmap_init(128, &htable);
        if(!is_watchpoint_address(arg))
            SCAN_FUNCTION(struct dentry*)(htable, arg);
        hashmap_destroy(htable);
    }
    SCAN {
        HASHMAP_PUT(htable, (void*)arg, (void*)type_class<ArgT__>::get_size());
        SCAN_RECURSIVE(arg->d_count);
        SCAN_RECURSIVE(arg->d_lock);
        SCAN_RECURSIVE(arg->d_inode);
        SCAN_RECURSIVE(arg->d_hash);
       // SCAN_RECURSIVE(arg->d_parent);
        SCAN_RECURSIVE(arg->d_name);
        SCAN_RECURSIVE(arg->d_lru);
        SCAN_RECURSIVE(arg->d_subdirs);
        SCAN_RECURSIVE(arg->d_alias);
        SCAN_RECURSIVE(arg->d_op);
        SCAN_RECURSIVE(arg->d_sb);
    }
})

MODULE_TYPE_WRAPPER(struct dentry* , {
    pre {
        void *value;
        if(!is_watchpoint_address(arg)){
                P(kern_printk("struct dentry");)
                ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct dentry*))
        }
    }
    no_post
#if 0
    post {
        void *value;
        if(!is_watchpoint_address(arg)){
            kern_printk("post scan struct dentry\n");
            SCAN_HEAD_FUNC(struct dentry*)(arg);
        }
    }
#endif
})


TYPE_SCAN_WRAPPER(struct posix_acl, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        hashmap_init(128, &htable);
        if(!is_watchpoint_address(arg))
            SCAN_FUNCTION(struct posix_acl)(htable, arg);
        hashmap_destroy(htable);
    }
    SCAN {
        HASHMAP_PUT(htable, (void*)&arg, (void*)type_class<ArgT__>::get_size());
        SCAN_RECURSIVE(arg.a_refcount);
    }
})

MODULE_TYPE_WRAPPER(struct posix_acl* , {
    pre {
        if(!is_watchpoint_address(arg)){
            P(kern_printk("struct posix_acl");)
            ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct posix_acl))
        }
    }
    no_post
#if 0
    post {
        if(!is_watchpoint_address(arg)){
            kern_printk("post scan struct posix_acl\n");
            SCAN_HEAD_FUNC(struct posix_acl)(*arg);
        }
    }
#endif
})


TYPE_SCAN_WRAPPER(struct super_block, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        hashmap_init(128, &htable);
        if(!is_watchpoint_address(arg))
            SCAN_FUNCTION(struct super_block)(htable, arg);
        hashmap_destroy(htable);
    }
    SCAN {
        HASHMAP_PUT(htable, (void*)&arg, (void*)type_class<ArgT__>::get_size());
        SCAN_RECURSIVE(arg.s_list);
        SCAN_RECURSIVE(arg.s_type);
        SCAN_RECURSIVE(arg.s_op);
        SCAN_RECURSIVE(arg.dq_op);
        SCAN_RECURSIVE(arg.s_qcop);
        SCAN_RECURSIVE(arg.s_export_op);
        SCAN_RECURSIVE(arg.s_root);
        SCAN_RECURSIVE(arg.s_umount);
       // SCAN_RECURSIVE(arg.s_lock);
        SCAN_RECURSIVE(arg.s_active);
        SCAN_RECURSIVE(arg.s_inodes);
        SCAN_RECURSIVE(arg.s_anon);
        SCAN_RECURSIVE(arg.s_files);
        SCAN_RECURSIVE(arg.s_dentry_lru);
        SCAN_RECURSIVE(arg.s_bdev);
        SCAN_RECURSIVE(arg.s_bdi);
        SCAN_RECURSIVE(arg.s_mtd);
        SCAN_RECURSIVE(arg.s_instances);
        SCAN_RECURSIVE(arg.s_dquot);
       // SCAN_RECURSIVE(arg.s_wait_unfrozen);
        SCAN_RECURSIVE(arg.s_vfs_rename_mutex);
    }
})

MODULE_TYPE_WRAPPER(struct super_block* , {
    pre {
        void *value;
        if(!is_watchpoint_address(arg)){
            P(kern_printk("struct super_block\n");)
            ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct super_block))
        }
    }
    no_post
#if 0
    post {
        void *value;
        if(!is_watchpoint_address(arg)){
            kern_printk("post scan struct super_block\n");
            SCAN_HEAD_FUNC(struct super_block)(*arg);
        }
    }
#endif
})

//struct rb_root { struct rb_node * rb_node ; } ;

TYPE_SCAN_WRAPPER(struct rb_root, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        hashmap_init(128, &htable);
        if(!is_watchpoint_address(arg))
            SCAN_FUNCTION(struct rb_root)(htable, arg);
        hashmap_destroy(htable);
    }
    SCAN {
        HASHMAP_PUT(htable, (void*)&arg, (void*)type_class<ArgT__>::get_size());
        SCAN_RECURSIVE(arg.rb_node);
    }
})

TYPE_SCAN_WRAPPER(struct rb_root*, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        hashmap_init(128, &htable);
        if(!is_watchpoint_address(arg))
            SCAN_FUNCTION(struct rb_root*)(htable, arg);
        hashmap_destroy(htable);
    }
    SCAN {
        HASHMAP_PUT(htable, (void*)arg, (void*)type_class<ArgT__>::get_size());
        SCAN_RECURSIVE(arg->rb_node);
    }
})

MODULE_TYPE_WRAPPER(struct rb_root* , {
    pre {
        if(!is_watchpoint_address(arg)){
            kern_printk("struct rb_root\n");
            ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct rb_root))
        }
    }
    no_post
#if 0
    post {
        if(!is_watchpoint_address(arg)){
            kern_printk("post scan struct rb_root\n");
            SCAN_HEAD_FUNC(struct rb_root*)(arg);
        }
    }
#endif
})

#if 0
MODULE_TYPE_WRAPPER(struct page* , {
    pre {
            kern_printk("struct page : %lx\n", arg);
            //ADD_TO_HASH(arg, SCAN_FUNCTION(struct super_block))

    }
    post {
            D( kern_printk("struct page\n");)

    }
})


MODULE_TYPE_WRAPPER(struct file* , {
    pre {
        void *value;
        if(!hashmap_get(module_watchpoint_map, arg, &value)){
            kern_printk("struct file : %lx\n", arg);
            //ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct file))
        }

    }
    post {
            D( kern_printk("struct file\n");)

    }
})

MODULE_TYPE_WRAPPER(struct qstr* , {
    pre {
            kern_printk("struct qstr\n");
            //ADD_TO_HASH(arg, SCAN_FUNCTION(struct super_block))

    }
    post {
            D( kern_printk("struct qstr\n");)

    }
})


MODULE_TYPE_WRAPPER(struct fiemap_extent_info* , {
    pre {
            kern_printk("struct fiemap_extent_info\n");
            //ADD_TO_HASH(arg, SCAN_FUNCTION(struct super_block))

    }
    post {
            D( kern_printk("struct fiemap_extent_info\n");)

    }
})

MODULE_TYPE_WRAPPER(struct writeback_control* , {
    pre {
            kern_printk("struct writeback_control\n");
            //ADD_TO_HASH(arg, SCAN_FUNCTION(struct super_block))

    }
    post {
            D( kern_printk("struct writeback_control\n");)

    }
})
#endif
TYPE_SCAN_WRAPPER( struct address_space, {
        SCAN_HEAD {
            DECLARE_HASH(htable);
            hashmap_init(128, &htable);
            if(!is_watchpoint_address(arg))
                SCAN_FUNCTION(struct address_space)(htable, arg);
            hashmap_destroy(htable);
        }
        SCAN {
            HASHMAP_PUT(htable, (void*)&arg, (void*)type_class<ArgT__>::get_size());
            kern_printk("address space scanner----------- : %lx\n", arg.page_tree);
           // SCAN_RECURSIVE(arg.host);
            SCAN_RECURSIVE(arg.page_tree);
            SCAN_FUNC(arg.i_mmap_writable);
            SCAN_RECURSIVE(arg.i_mmap);
            SCAN_RECURSIVE(arg.i_mmap_nonlinear);
            //SCAN_FUNC(arg.truncate_count);
            SCAN_FUNC(arg.nrpages);
            SCAN_FUNC(arg.writeback_index);
            SCAN_RECURSIVE(arg.a_ops);
            SCAN_FUNC(arg.flags);
            SCAN_RECURSIVE(arg.backing_dev_info);
            SCAN_RECURSIVE(arg.private_list);
           // SCAN_RECURSIVE(arg.assoc_mapping);
        }
})

TYPE_SCAN_WRAPPER( struct address_space*, {
        SCAN_HEAD {
            DECLARE_HASH(htable);
            hashmap_init(128, &htable);
            if(!is_watchpoint_address(arg))
                SCAN_FUNCTION(struct address_space*)(htable, arg);
            hashmap_destroy(htable);
        }
        SCAN {
            HASHMAP_PUT(htable, (void*)arg, (void*)type_class<ArgT__>::get_size());
           // SCAN_RECURSIVE(arg->host);
            SCAN_RECURSIVE(arg->page_tree);
            SCAN_FUNC(arg->i_mmap_writable);
            SCAN_RECURSIVE(arg->i_mmap);
            SCAN_RECURSIVE(arg->i_mmap_nonlinear);
            //SCAN_FUNC(arg->truncate_count);
            SCAN_FUNC(arg->nrpages);
            SCAN_FUNC(arg->writeback_index);
            SCAN_RECURSIVE(arg->a_ops);
            SCAN_FUNC(arg->flags);
            SCAN_RECURSIVE(arg->backing_dev_info);
           // SCAN_RECURSIVE(arg->private_list);
            //SCAN_RECURSIVE(arg->assoc_mapping);
        }
})


MODULE_TYPE_WRAPPER(struct address_space* , {
    pre {
        if(!is_watchpoint_address(arg)){
            kern_printk("struct address_space\n");
            ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct address_space*))
        }

    }
    no_post
#if 0
    post {
        if(!is_watchpoint_address(arg)){
            kern_printk("post scan struct address_space\n");
            SCAN_HEAD_FUNC(struct address_space*)(arg);
        }

    }
#endif
})
#if 0
#endif
#if 0
MODULE_TYPE_WRAPPER(struct iovec* , {
    pre {
            kern_printk("struct iovec\n");
            //ADD_TO_HASH(arg, SCAN_FUNCTION(struct super_block))

    }
    post {
            D( kern_printk("struct iovec\n");)

    }
})

MODULE_TYPE_WRAPPER(struct kiocb* , {
    pre {
            kern_printk("struct kiocb\n");
            //ADD_TO_HASH(arg, SCAN_FUNCTION(struct super_block))

    }
    post {
            D( kern_printk("struct kiocb\n");)

    }
})


MODULE_TYPE_WRAPPER(struct nameidata* , {
    pre {
            kern_printk("struct nameidata\n");
            //ADD_TO_HASH(arg, SCAN_FUNCTION(struct super_block))

    }
    post {
            D( kern_printk("struct nameidata\n");)

    }
})
#endif


TYPE_SCAN_WRAPPER( struct seq_operations, {
        SCAN_HEAD {
            DECLARE_HASH(htable);
            hashmap_init(128, &htable);
            if(!is_watchpoint_address(arg))
                SCAN_FUNCTION(struct seq_operations)(htable, arg);
            hashmap_destroy(htable);
        }
        SCAN {
            HASHMAP_PUT(htable, (void*)&arg, (void*)type_class<ArgT__>::get_size());
            SCAN_FUNC(arg.start);
            SCAN_FUNC(arg.stop);
            SCAN_FUNC(arg.next);
            SCAN_FUNC(arg.show);
        }
})


TYPE_SCAN_WRAPPER( struct seq_file, {
        SCAN_HEAD {
            DECLARE_HASH(htable);
            hashmap_init(128, &htable);
            if(!is_watchpoint_address(arg))
                SCAN_FUNCTION(struct seq_file)(htable, arg);
            hashmap_destroy(htable);
        }
        SCAN {
            HASHMAP_PUT(htable, (void*)&arg, (void*)type_class<ArgT__>::get_size());
            SCAN_FUNC(arg.buf);
            SCAN_FUNC(arg.size);
            SCAN_FUNC(arg.from);
            SCAN_FUNC(arg.count);
            SCAN_FUNC(arg.index);
            SCAN_FUNC(arg.read_pos);
            SCAN_FUNC(arg.version);
            SCAN_RECURSIVE(arg.lock);
            SCAN_RECURSIVE(arg.op);
           // SCAN_FUNC(arg.private_data);
        }
})


TYPE_SCAN_WRAPPER( struct seq_operations*, {
        SCAN_HEAD {
            DECLARE_HASH(htable);
            hashmap_init(128, &htable);
            if(!is_watchpoint_address(arg))
                SCAN_FUNCTION(struct seq_operations*)(htable, arg);
            hashmap_destroy(htable);
        }
        SCAN {
            HASHMAP_PUT(htable, (void*)arg, (void*)type_class<ArgT__>::get_size());
            SCAN_FUNC(arg->start);
            SCAN_FUNC(arg->stop);
            SCAN_FUNC(arg->next);
            SCAN_FUNC(arg->show);
        }
})


TYPE_SCAN_WRAPPER( struct seq_file*, {
        SCAN_HEAD {
            DECLARE_HASH(htable);
            hashmap_init(128, &htable);
            if(!is_watchpoint_address(arg))
                SCAN_FUNCTION(struct seq_file*)(htable, arg);
            hashmap_destroy(htable);
        }
        SCAN {
            HASHMAP_PUT(htable, (void*)arg, (void*)type_class<ArgT__>::get_size());
            SCAN_FUNC(arg->buf);
            SCAN_FUNC(arg->size);
            SCAN_FUNC(arg->from);
            SCAN_FUNC(arg->count);
            SCAN_FUNC(arg->index);
            SCAN_FUNC(arg->read_pos);
            SCAN_FUNC(arg->version);
            SCAN_RECURSIVE(arg->lock);
            SCAN_RECURSIVE(arg->op);
            //SCAN_FUNC(arg->private_data);
        }
})

MODULE_TYPE_WRAPPER(struct seq_file* , {
    pre {
        if(!is_watchpoint_address(arg)){
            P(kern_printk("struct seq_file : %lx\n", arg);)
            ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct seq_file*))
        }

    }
    no_post
#if 0
    post {
        if(!is_watchpoint_address(arg)){
            kern_printk("post scan struct seq_file : %lx\n", arg);
            SCAN_HEAD_FUNC(struct seq_file*)(arg);
        }

    }
#endif
})

TYPE_SCAN_WRAPPER( struct vfsmount, {
        SCAN_HEAD {
            DECLARE_HASH(htable);
            hashmap_init(128, &htable);
            if(!is_watchpoint_address(arg))
                SCAN_FUNCTION(struct vfsmount)(htable, arg);
            hashmap_destroy(htable);
        }

        SCAN {
            HASHMAP_PUT(htable, (void*)&arg, (void*)type_class<ArgT__>::get_size());
            //SCAN_RECURSIVE(arg.mnt_hash);
            //SCAN_RECURSIVE(arg.mnt_parent);
            /*SCAN_RECURSIVE(arg.mnt_mountpoint);
            SCAN_RECURSIVE(arg.mnt_root);
            SCAN_RECURSIVE(arg.mnt_sb);
            SCAN_RECURSIVE(arg.mnt_mounts);
            SCAN_RECURSIVE(arg.mnt_child);
            SCAN_FUNC(arg.mnt_flags);
            SCAN_FUNC(arg.mnt_devname);
            SCAN_RECURSIVE(arg.mnt_list);
            SCAN_RECURSIVE(arg.mnt_expire);
            SCAN_RECURSIVE(arg.mnt_share);
            SCAN_RECURSIVE(arg.mnt_slave_list);
            SCAN_RECURSIVE(arg.mnt_slave);
            SCAN_RECURSIVE(arg.mnt_master);
            SCAN_RECURSIVE(arg.mnt_ns);
            SCAN_FUNC(arg.mnt_id);
            SCAN_FUNC(arg.mnt_group_id);
            SCAN_FUNC(arg.mnt_expiry_mark);
            SCAN_FUNC(arg.mnt_pinned);
            SCAN_FUNC(arg.mnt_ghosts);
            SCAN_FUNC(arg.mnt_writers);*/
        }
})

TYPE_SCAN_WRAPPER( struct vfsmount *, {
        SCAN_HEAD {
            DECLARE_HASH(htable);
            hashmap_init(128, &htable);
            if(!is_watchpoint_address(arg))
                SCAN_FUNCTION(struct vfsmount*)(htable, arg);
            hashmap_destroy(htable);
        }

        SCAN {
            HASHMAP_PUT(htable, (void*)arg, (void*)type_class<ArgT__>::get_size());
            //kern_printk("arg->mnt_hash : %lx\n", arg->mnt_mountpoint);
           // SCAN_RECURSIVE(arg->mnt_hash);
            /* the parent address of vfsmount, no required to scan this.*/
            /*if(arg->mnt_parent){
                SCAN_RECURSIVE(arg->mnt_parent);
            }*/
            //SCAN_RECURSIVE(arg->mnt_mountpoint);
            //SCAN_RECURSIVE(arg->mnt_root);
            //SCAN_RECURSIVE(arg->mnt_sb);
            //SCAN_RECURSIVE(arg->mnt_mounts);
            //SCAN_RECURSIVE(arg->mnt_child);
            //SCAN_FUNC(arg->mnt_flags);
            //SCAN_FUNC(arg->mnt_devname);
            //SCAN_RECURSIVE(arg->mnt_list);
            //SCAN_RECURSIVE(arg->mnt_expire);
            //SCAN_RECURSIVE(arg->mnt_share);
            //SCAN_RECURSIVE(arg->mnt_slave_list);
            //SCAN_RECURSIVE(arg->mnt_slave);
            //SCAN_RECURSIVE(arg->mnt_master);
            //SCAN_RECURSIVE(arg->mnt_ns);
            //SCAN_FUNC(arg->mnt_id);
           // SCAN_FUNC(arg->mnt_group_id);
            //SCAN_FUNC(arg->mnt_expiry_mark);
            //SCAN_FUNC(arg->mnt_pinned);
           // SCAN_FUNC(arg->mnt_ghosts);
           // SCAN_FUNC(arg->mnt_writers);
        }
})

MODULE_TYPE_WRAPPER(struct vfsmount* , {
        pre {
            if(!is_watchpoint_address(arg)){
                kern_printk("struct vfsmount : %lx\n", arg);
                ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct vfsmount*))
            }
        }
        no_post
#if 0
        post {
            if(!is_watchpoint_address(arg)){
                kern_printk("post scan struct vfsmount : %lx\n", arg);
                SCAN_HEAD_FUNC(struct vfsmount*)(arg);
            }
        }
#endif
})

TYPE_SCAN_WRAPPER( struct fid, {
        SCAN_HEAD {
            DECLARE_HASH(htable);
            hashmap_init(128, &htable);
            if(!is_watchpoint_address(arg))
            	SCAN_FUNCTION(struct fid)(htable, arg);
            hashmap_destroy(htable);
        }
        SCAN {
            HASHMAP_PUT(htable, (void*)&arg, (void*)type_class<ArgT__>::get_size());
            SCAN_FUNC(arg.i32.ino);
            SCAN_FUNC(arg.i32.gen);
            SCAN_FUNC(arg.i32.parent_ino);
            SCAN_FUNC(arg.i32.parent_gen);
            //SCAN_UNION(arg);
        }
})

TYPE_SCAN_WRAPPER( struct fid*, {
        SCAN_HEAD {
            DECLARE_HASH(htable);
            hashmap_init(128, &htable);
            if(!is_watchpoint_address(arg))
            	SCAN_FUNCTION(struct fid*)(htable, arg);
            hashmap_destroy(htable);
        }
        SCAN {
            HASHMAP_PUT(htable, (void*)arg, (void*)type_class<ArgT__>::get_size());
            SCAN_FUNC(arg->i32.ino);
            SCAN_FUNC(arg->i32.gen);
            SCAN_FUNC(arg->i32.parent_ino);
            SCAN_FUNC(arg->i32.parent_gen);
            //SCAN_UNION(arg);
        }
})

MODULE_TYPE_WRAPPER(struct fid* , {
    pre {
    	if(!is_watchpoint_address(arg)){
            P(kern_printk("struct fid\n");)
            ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct fid*))
        }
    }
    no_post
#if 0
    post {
    	if(!is_watchpoint_address(arg)){
            kern_printk("post scan struct fid\n");
           // SCAN_HEAD_FUNC(struct fid*)(arg);
        }
    }
#endif
})

TYPE_SCAN_WRAPPER( __kernel_fsid_t, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        hashmap_init(128, &htable);
        if(!is_watchpoint_address(arg))
        	SCAN_FUNCTION(__kernel_fsid_t)(htable, arg);
        hashmap_destroy(htable);
    }
    SCAN {
        HASHMAP_PUT(htable, (void*)&arg, (void*)type_class<ArgT__>::get_size());
        SCAN_FUNC(arg.val[0]);
        SCAN_FUNC(arg.val[1]);
    }
})

TYPE_SCAN_WRAPPER( __kernel_fsid_t*, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        hashmap_init(128, &htable);
        if(!is_watchpoint_address(arg))
        	SCAN_FUNCTION(__kernel_fsid_t *)(htable, arg);
        hashmap_destroy(htable);
    }
    SCAN {
        HASHMAP_PUT(htable, (void*)arg, (void*)type_class<ArgT__>::get_size());
        SCAN_FUNC(arg->val[0]);
        SCAN_FUNC(arg->val[1]);
    }
})

TYPE_SCAN_WRAPPER(struct kstatfs , {
		SCAN_HEAD{
			DECLARE_HASH(htable);
			hashmap_init(128, &htable);
			if(!is_watchpoint_address(arg))
				SCAN_FUNCTION(struct kstatfs)(htable, arg);
			hashmap_destroy(htable);
		}

		SCAN {
			HASHMAP_PUT(htable, (void*)&arg, (void*)type_class<ArgT__>::get_size());
			SCAN_FUNC(arg.f_type);
			SCAN_FUNC(arg.f_bsize);
			SCAN_FUNC(arg.f_blocks);
			SCAN_FUNC(arg.f_bfree);
			SCAN_FUNC(arg.f_bavail);
			SCAN_FUNC(arg.f_files);
			SCAN_FUNC(arg.f_ffree);
			SCAN_FUNC(arg.f_namelen);
			SCAN_FUNC(arg.f_frsize);
			SCAN_FUNC(arg.f_spare[0]);
			SCAN_FUNC(arg.f_spare[1]);
			SCAN_FUNC(arg.f_spare[2]);
			SCAN_FUNC(arg.f_spare[3]);
			SCAN_FUNC(arg.f_spare[4]);
			SCAN_RECURSIVE(arg.f_fsid);
		}
})

TYPE_SCAN_WRAPPER(struct kstatfs* , {
        SCAN_HEAD{
            DECLARE_HASH(htable);
            hashmap_init(128, &htable);
            if(!is_watchpoint_address(arg))
            	SCAN_FUNCTION(struct kstatfs*)(htable, arg);
            hashmap_destroy(htable);
        }

        SCAN {
            HASHMAP_PUT(htable, (void*)arg, (void*)type_class<ArgT__>::get_size());
            SCAN_FUNC(arg->f_type);
            SCAN_FUNC(arg->f_bsize);
            SCAN_FUNC(arg->f_blocks);
            SCAN_FUNC(arg->f_bfree);
            SCAN_FUNC(arg->f_bavail);
            SCAN_FUNC(arg->f_files);
            SCAN_FUNC(arg->f_ffree);
            SCAN_FUNC(arg->f_namelen);
            SCAN_FUNC(arg->f_frsize);
            SCAN_FUNC(arg->f_spare[0]);
            SCAN_FUNC(arg->f_spare[1]);
            SCAN_FUNC(arg->f_spare[2]);
            SCAN_FUNC(arg->f_spare[3]);
            SCAN_FUNC(arg->f_spare[4]);
            SCAN_RECURSIVE(arg->f_fsid);
        }
})

MODULE_TYPE_WRAPPER(struct kstatfs* , {
    pre {
    	if(!is_watchpoint_address(arg)){
            P(kern_printk("struct kstatfs\n");)
            ADD_TO_HASH(arg, SCAN_HEAD_FUNC(struct kstatfs*))
        }
    }
    no_post
#if 0
    post {
    	if(!is_watchpoint_address(arg)){
            kern_printk("post scan struct kstatfs\n");
            //SCAN_HEAD_FUNC(struct kstatfs*)(arg);
        }
    }
#endif
})


#endif /* DYNAMIC_WRAPPER_HPP_ */
