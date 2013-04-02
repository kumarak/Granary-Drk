/* Auto-generated wrappers. */
TYPE_SCAN_WRAPPER(struct list_head, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.next);
        SCAN_RECURSIVE(arg.prev);
    }
})

MODULE_TYPE_WRAPPER(struct list_head* , {
    MODULE_PRE {
		D( kern_printk("struct list_head");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct list_head))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct list_head");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct file_system_type, {
    PRE_SCAN {
        SCAN_PTR(arg.get_sb);
        SCAN_PTR(arg.kill_sb);
        SCAN_RECURSIVE(arg.owner);
        SCAN_RECURSIVE(arg.next);
        SCAN_RECURSIVE(arg.fs_supers);
        SCAN_RECURSIVE(arg.s_lock_key);
        SCAN_RECURSIVE(arg.s_umount_key);
        SCAN_RECURSIVE(arg.i_lock_key);
        SCAN_RECURSIVE(arg.i_mutex_key);
        SCAN_RECURSIVE(arg.i_mutex_dir_key);
        SCAN_RECURSIVE(arg.i_alloc_sem_key);
    }
})

MODULE_TYPE_WRAPPER(struct file_system_type* , {
    MODULE_PRE {
		D( kern_printk("struct file_system_type");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct file_system_type))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct file_system_type");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(spinlock_t, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.raw_lock);
    }
})

MODULE_TYPE_WRAPPER(spinlock_t* , {
    MODULE_PRE {
		D( kern_printk("spinlock_t");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(spinlock_t))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("spinlock_t");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct kmem_cache_node, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.list_lock);
        SCAN_RECURSIVE(arg.partial);
        SCAN_RECURSIVE(arg.nr_slabs);
        SCAN_RECURSIVE(arg.total_objects);
        SCAN_RECURSIVE(arg.full);
    }
})

MODULE_TYPE_WRAPPER(struct kmem_cache_node* , {
    MODULE_PRE {
		D( kern_printk("struct kmem_cache_node");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct kmem_cache_node))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct kmem_cache_node");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct kref, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.refcount);
    }
})

MODULE_TYPE_WRAPPER(struct kref* , {
    MODULE_PRE {
		D( kern_printk("struct kref");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct kref))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct kref");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct kobject, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.entry);
        SCAN_RECURSIVE(arg.parent);
        SCAN_RECURSIVE(arg.kset);
        SCAN_RECURSIVE(arg.ktype);
        SCAN_RECURSIVE(arg.sd);
        SCAN_RECURSIVE(arg.kref);
    }
})

MODULE_TYPE_WRAPPER(struct kobject* , {
    MODULE_PRE {
		D( kern_printk("struct kobject");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct kobject))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct kobject");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct kmem_cache, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.oo);
        SCAN_RECURSIVE(arg.local_node);
        SCAN_RECURSIVE(arg.max);
        SCAN_RECURSIVE(arg.min);
        SCAN_PTR(arg.ctor);
        SCAN_RECURSIVE(arg.list);
        SCAN_RECURSIVE(arg.kobj);
    }
})

MODULE_TYPE_WRAPPER(struct kmem_cache* , {
    MODULE_PRE {
		D( kern_printk("struct kmem_cache");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct kmem_cache))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct kmem_cache");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct page, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg._count);
        SCAN_RECURSIVE(arg.lru);
    }
})

MODULE_TYPE_WRAPPER(struct page* , {
    MODULE_PRE {
		D( kern_printk("struct page");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct page))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct page");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct super_operations, {
    PRE_SCAN {
        SCAN_PTR(arg.alloc_inode);
        SCAN_PTR(arg.destroy_inode);
        SCAN_PTR(arg.dirty_inode);
        SCAN_PTR(arg.write_inode);
        SCAN_PTR(arg.drop_inode);
        SCAN_PTR(arg.delete_inode);
        SCAN_PTR(arg.put_super);
        SCAN_PTR(arg.write_super);
        SCAN_PTR(arg.sync_fs);
        SCAN_PTR(arg.freeze_fs);
        SCAN_PTR(arg.unfreeze_fs);
        SCAN_PTR(arg.statfs);
        SCAN_PTR(arg.remount_fs);
        SCAN_PTR(arg.clear_inode);
        SCAN_PTR(arg.umount_begin);
        SCAN_PTR(arg.show_options);
        SCAN_PTR(arg.show_stats);
        SCAN_PTR(arg.quota_read);
        SCAN_PTR(arg.quota_write);
        SCAN_PTR(arg.bdev_try_to_free_page);
    }
})

MODULE_TYPE_WRAPPER(struct super_operations* , {
    MODULE_PRE {
		D( kern_printk("struct super_operations");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct super_operations))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct super_operations");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct dquot_operations, {
    PRE_SCAN {
        SCAN_PTR(arg.initialize);
        SCAN_PTR(arg.drop);
        SCAN_PTR(arg.alloc_space);
        SCAN_PTR(arg.alloc_inode);
        SCAN_PTR(arg.free_space);
        SCAN_PTR(arg.free_inode);
        SCAN_PTR(arg.transfer);
        SCAN_PTR(arg.write_dquot);
        SCAN_PTR(arg.alloc_dquot);
        SCAN_PTR(arg.destroy_dquot);
        SCAN_PTR(arg.acquire_dquot);
        SCAN_PTR(arg.release_dquot);
        SCAN_PTR(arg.mark_dirty);
        SCAN_PTR(arg.write_info);
        SCAN_PTR(arg.reserve_space);
        SCAN_PTR(arg.claim_space);
        SCAN_PTR(arg.release_rsv);
        SCAN_PTR(arg.get_reserved_space);
    }
})

MODULE_TYPE_WRAPPER(struct dquot_operations* , {
    MODULE_PRE {
		D( kern_printk("struct dquot_operations");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct dquot_operations))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct dquot_operations");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct quotactl_ops, {
    PRE_SCAN {
        SCAN_PTR(arg.quota_on);
        SCAN_PTR(arg.quota_off);
        SCAN_PTR(arg.quota_sync);
        SCAN_PTR(arg.get_info);
        SCAN_PTR(arg.set_info);
        SCAN_PTR(arg.get_dqblk);
        SCAN_PTR(arg.set_dqblk);
        SCAN_PTR(arg.get_xstate);
        SCAN_PTR(arg.set_xstate);
        SCAN_PTR(arg.get_xquota);
        SCAN_PTR(arg.set_xquota);
    }
})

MODULE_TYPE_WRAPPER(struct quotactl_ops* , {
    MODULE_PRE {
		D( kern_printk("struct quotactl_ops");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct quotactl_ops))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct quotactl_ops");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct export_operations, {
    PRE_SCAN {
        SCAN_PTR(arg.encode_fh);
        SCAN_PTR(arg.fh_to_dentry);
        SCAN_PTR(arg.fh_to_parent);
        SCAN_PTR(arg.get_name);
        SCAN_PTR(arg.get_parent);
    }
})

MODULE_TYPE_WRAPPER(struct export_operations* , {
    MODULE_PRE {
		D( kern_printk("struct export_operations");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct export_operations))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct export_operations");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct hlist_node, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.next);
    }
})

MODULE_TYPE_WRAPPER(struct hlist_node* , {
    MODULE_PRE {
		D( kern_printk("struct hlist_node");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct hlist_node))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct hlist_node");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct rcu_head, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.next);
        SCAN_PTR(arg.func);
    }
})

MODULE_TYPE_WRAPPER(struct rcu_head* , {
    MODULE_PRE {
		D( kern_printk("struct rcu_head");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct rcu_head))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct rcu_head");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct dentry, {
    PRE_SCAN {
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

MODULE_TYPE_WRAPPER(struct dentry* , {
    MODULE_PRE {
		D( kern_printk("struct dentry");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct dentry))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct dentry");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct rw_semaphore, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.wait_lock);
        SCAN_RECURSIVE(arg.wait_list);
    }
})

MODULE_TYPE_WRAPPER(struct rw_semaphore* , {
    MODULE_PRE {
		D( kern_printk("struct rw_semaphore");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct rw_semaphore))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct rw_semaphore");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct mutex, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.count);
        SCAN_RECURSIVE(arg.wait_lock);
        SCAN_RECURSIVE(arg.wait_list);
        SCAN_RECURSIVE(arg.owner);
    }
})

MODULE_TYPE_WRAPPER(struct mutex* , {
    MODULE_PRE {
		D( kern_printk("struct mutex");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct mutex))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct mutex");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct xattr_handler, {
    PRE_SCAN {
        SCAN_PTR(arg.list);
        SCAN_PTR(arg.get);
        SCAN_PTR(arg.set);
    }
})

MODULE_TYPE_WRAPPER(struct xattr_handler* , {
    MODULE_PRE {
		D( kern_printk("struct xattr_handler");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct xattr_handler))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct xattr_handler");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct hlist_head, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.first);
    }
})

MODULE_TYPE_WRAPPER(struct hlist_head* , {
    MODULE_PRE {
		D( kern_printk("struct hlist_head");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct hlist_head))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct hlist_head");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct mem_dqinfo, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.dqi_format);
        SCAN_RECURSIVE(arg.dqi_dirty_list);
    }
})

MODULE_TYPE_WRAPPER(struct mem_dqinfo* , {
    MODULE_PRE {
		D( kern_printk("struct mem_dqinfo");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct mem_dqinfo))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct mem_dqinfo");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct quota_info, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.dqio_mutex);
        SCAN_RECURSIVE(arg.dqonoff_mutex);
        SCAN_RECURSIVE(arg.dqptr_sem);
    }
})

MODULE_TYPE_WRAPPER(struct quota_info* , {
    MODULE_PRE {
		D( kern_printk("struct quota_info");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct quota_info))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct quota_info");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct __wait_queue_head, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE(arg.task_list);
    }
})

MODULE_TYPE_WRAPPER(struct __wait_queue_head* , {
    MODULE_PRE {
		D( kern_printk("struct __wait_queue_head");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct __wait_queue_head))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct __wait_queue_head");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct super_block, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.s_list);
        SCAN_RECURSIVE(arg.s_type);
        SCAN_RECURSIVE(arg.s_op);
        SCAN_RECURSIVE(arg.dq_op);
        SCAN_RECURSIVE(arg.s_qcop);
        SCAN_RECURSIVE(arg.s_export_op);
        SCAN_RECURSIVE(arg.s_root);
        SCAN_RECURSIVE(arg.s_umount);
        SCAN_RECURSIVE(arg.s_lock);
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
        SCAN_RECURSIVE(arg.s_wait_unfrozen);
        SCAN_RECURSIVE(arg.s_vfs_rename_mutex);
    }
})

MODULE_TYPE_WRAPPER(struct super_block* , {
    MODULE_PRE {
		D( kern_printk("struct super_block");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct super_block))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct super_block");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct inode_operations, {
    PRE_SCAN {
        SCAN_PTR(arg.create);
        SCAN_PTR(arg.lookup);
        SCAN_PTR(arg.link);
        SCAN_PTR(arg.unlink);
        SCAN_PTR(arg.symlink);
        SCAN_PTR(arg.mkdir);
        SCAN_PTR(arg.rmdir);
        SCAN_PTR(arg.mknod);
        SCAN_PTR(arg.rename);
        SCAN_PTR(arg.readlink);
        SCAN_PTR(arg.follow_link);
        SCAN_PTR(arg.put_link);
        SCAN_PTR(arg.truncate);
        SCAN_PTR(arg.permission);
        SCAN_PTR(arg.check_acl);
        SCAN_PTR(arg.setattr);
        SCAN_PTR(arg.getattr);
        SCAN_PTR(arg.setxattr);
        SCAN_PTR(arg.getxattr);
        SCAN_PTR(arg.listxattr);
        SCAN_PTR(arg.removexattr);
        SCAN_PTR(arg.truncate_range);
        SCAN_PTR(arg.fallocate);
        SCAN_PTR(arg.fiemap);
    }
})

MODULE_TYPE_WRAPPER(struct inode_operations* , {
    MODULE_PRE {
		D( kern_printk("struct inode_operations");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct inode_operations))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct inode_operations");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct file_operations, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.owner);
        SCAN_PTR(arg.llseek);
        SCAN_PTR(arg.read);
        SCAN_PTR(arg.write);
        SCAN_PTR(arg.aio_read);
        SCAN_PTR(arg.aio_write);
        SCAN_PTR(arg.readdir);
        SCAN_PTR(arg.poll);
        SCAN_PTR(arg.ioctl);
        SCAN_PTR(arg.unlocked_ioctl);
        SCAN_PTR(arg.compat_ioctl);
        SCAN_PTR(arg.mmap);
        SCAN_PTR(arg.open);
        SCAN_PTR(arg.flush);
        SCAN_PTR(arg.release);
        SCAN_PTR(arg.fsync);
        SCAN_PTR(arg.aio_fsync);
        SCAN_PTR(arg.fasync);
        SCAN_PTR(arg.lock);
        SCAN_PTR(arg.sendpage);
        SCAN_PTR(arg.get_unmapped_area);
        SCAN_PTR(arg.check_flags);
        SCAN_PTR(arg.flock);
        SCAN_PTR(arg.splice_write);
        SCAN_PTR(arg.splice_read);
        SCAN_PTR(arg.setlease);
    }
})

MODULE_TYPE_WRAPPER(struct file_operations* , {
    MODULE_PRE {
		D( kern_printk("struct file_operations");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct file_operations))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct file_operations");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct radix_tree_root, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.rnode);
    }
})

MODULE_TYPE_WRAPPER(struct radix_tree_root* , {
    MODULE_PRE {
		D( kern_printk("struct radix_tree_root");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct radix_tree_root))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct radix_tree_root");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct prio_tree_root, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.prio_tree_node);
    }
})

MODULE_TYPE_WRAPPER(struct prio_tree_root* , {
    MODULE_PRE {
		D( kern_printk("struct prio_tree_root");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct prio_tree_root))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct prio_tree_root");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct address_space_operations, {
    PRE_SCAN {
        SCAN_PTR(arg.writepage);
        SCAN_PTR(arg.readpage);
        SCAN_PTR(arg.sync_page);
        SCAN_PTR(arg.writepages);
        SCAN_PTR(arg.set_page_dirty);
        SCAN_PTR(arg.readpages);
        SCAN_PTR(arg.write_begin);
        SCAN_PTR(arg.write_end);
        SCAN_PTR(arg.bmap);
        SCAN_PTR(arg.invalidatepage);
        SCAN_PTR(arg.releasepage);
        SCAN_PTR(arg.direct_IO);
        SCAN_PTR(arg.get_xip_mem);
        SCAN_PTR(arg.migratepage);
        SCAN_PTR(arg.launder_page);
        SCAN_PTR(arg.is_partially_uptodate);
        SCAN_PTR(arg.error_remove_page);
    }
})

MODULE_TYPE_WRAPPER(struct address_space_operations* , {
    MODULE_PRE {
		D( kern_printk("struct address_space_operations");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct address_space_operations))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct address_space_operations");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct address_space, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.host);
        SCAN_RECURSIVE(arg.page_tree);
        SCAN_RECURSIVE(arg.tree_lock);
        SCAN_RECURSIVE(arg.i_mmap);
        SCAN_RECURSIVE(arg.i_mmap_nonlinear);
        SCAN_RECURSIVE(arg.i_mmap_lock);
        SCAN_RECURSIVE(arg.a_ops);
        SCAN_RECURSIVE(arg.backing_dev_info);
        SCAN_RECURSIVE(arg.private_lock);
        SCAN_RECURSIVE(arg.private_list);
        SCAN_RECURSIVE(arg.assoc_mapping);
    }
})

MODULE_TYPE_WRAPPER(struct address_space* , {
    MODULE_PRE {
		D( kern_printk("struct address_space");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct address_space))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct address_space");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct inode, {
    PRE_SCAN {
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

MODULE_TYPE_WRAPPER(struct inode* , {
    MODULE_PRE {
		D( kern_printk("struct inode");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct inode))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct inode");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct block_device, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.bd_inode);
        SCAN_RECURSIVE(arg.bd_super);
        SCAN_RECURSIVE(arg.bd_mutex);
        SCAN_RECURSIVE(arg.bd_inodes);
        SCAN_RECURSIVE(arg.bd_holder_list);
        SCAN_RECURSIVE(arg.bd_contains);
        SCAN_RECURSIVE(arg.bd_part);
        SCAN_RECURSIVE(arg.bd_disk);
        SCAN_RECURSIVE(arg.bd_list);
        SCAN_RECURSIVE(arg.bd_fsfreeze_mutex);
    }
})

MODULE_TYPE_WRAPPER(struct block_device* , {
    MODULE_PRE {
		D( kern_printk("struct block_device");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct block_device))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct block_device");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct posix_acl, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.a_refcount);
    }
})

MODULE_TYPE_WRAPPER(struct posix_acl* , {
    MODULE_PRE {
		D( kern_printk("struct posix_acl");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct posix_acl))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct posix_acl");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(rwlock_t, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.raw_lock);
    }
})

MODULE_TYPE_WRAPPER(rwlock_t* , {
    MODULE_PRE {
		D( kern_printk("rwlock_t");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(rwlock_t))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("rwlock_t");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct journal_superblock_s, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.s_header);
    }
})

MODULE_TYPE_WRAPPER(struct journal_superblock_s* , {
    MODULE_PRE {
		D( kern_printk("struct journal_superblock_s");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct journal_superblock_s))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct journal_superblock_s");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct timer_list, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.entry);
        SCAN_PTR(arg.function);
        SCAN_RECURSIVE(arg.base);
    }
})

MODULE_TYPE_WRAPPER(struct timer_list* , {
    MODULE_PRE {
		D( kern_printk("struct timer_list");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct timer_list))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct timer_list");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct journal_s, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.j_sb_buffer);
        SCAN_RECURSIVE(arg.j_superblock);
        SCAN_RECURSIVE(arg.j_state_lock);
        SCAN_RECURSIVE(arg.j_barrier);
        SCAN_RECURSIVE(arg.j_running_transaction);
        SCAN_RECURSIVE(arg.j_committing_transaction);
        SCAN_RECURSIVE(arg.j_checkpoint_transactions);
        SCAN_RECURSIVE(arg.j_wait_transaction_locked);
        SCAN_RECURSIVE(arg.j_wait_logspace);
        SCAN_RECURSIVE(arg.j_wait_done_commit);
        SCAN_RECURSIVE(arg.j_wait_checkpoint);
        SCAN_RECURSIVE(arg.j_wait_commit);
        SCAN_RECURSIVE(arg.j_wait_updates);
        SCAN_RECURSIVE(arg.j_checkpoint_mutex);
        SCAN_RECURSIVE(arg.j_dev);
        SCAN_RECURSIVE(arg.j_fs_dev);
        SCAN_RECURSIVE(arg.j_list_lock);
        SCAN_RECURSIVE(arg.j_inode);
        SCAN_RECURSIVE(arg.j_task);
        SCAN_RECURSIVE(arg.j_commit_timer);
        SCAN_RECURSIVE(arg.j_revoke_lock);
        SCAN_RECURSIVE(arg.j_revoke);
    }
})

MODULE_TYPE_WRAPPER(struct journal_s* , {
    MODULE_PRE {
		D( kern_printk("struct journal_s");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct journal_s))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct journal_s");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct sk_buff, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.next);
        SCAN_RECURSIVE(arg.prev);
        SCAN_RECURSIVE(arg.sk);
        SCAN_RECURSIVE(arg.dev);
        SCAN_PTR(arg.destructor);
        SCAN_RECURSIVE(arg.users);
    }
})

MODULE_TYPE_WRAPPER(struct sk_buff* , {
    MODULE_PRE {
		D( kern_printk("struct sk_buff");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct sk_buff))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct sk_buff");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct net_device_ops, {
    PRE_SCAN {
        SCAN_PTR(arg.ndo_init);
        SCAN_PTR(arg.ndo_uninit);
        SCAN_PTR(arg.ndo_open);
        SCAN_PTR(arg.ndo_stop);
        SCAN_PTR(arg.ndo_start_xmit);
        SCAN_PTR(arg.ndo_select_queue);
        SCAN_PTR(arg.ndo_change_rx_flags);
        SCAN_PTR(arg.ndo_set_rx_mode);
        SCAN_PTR(arg.ndo_set_multicast_list);
        SCAN_PTR(arg.ndo_set_mac_address);
        SCAN_PTR(arg.ndo_validate_addr);
        SCAN_PTR(arg.ndo_do_ioctl);
        SCAN_PTR(arg.ndo_set_config);
        SCAN_PTR(arg.ndo_change_mtu);
        SCAN_PTR(arg.ndo_neigh_setup);
        SCAN_PTR(arg.ndo_tx_timeout);
        SCAN_PTR(arg.ndo_get_stats);
        SCAN_PTR(arg.ndo_vlan_rx_register);
        SCAN_PTR(arg.ndo_vlan_rx_add_vid);
        SCAN_PTR(arg.ndo_vlan_rx_kill_vid);
        SCAN_PTR(arg.ndo_poll_controller);
        SCAN_PTR(arg.ndo_fcoe_enable);
        SCAN_PTR(arg.ndo_fcoe_disable);
        SCAN_PTR(arg.ndo_fcoe_ddp_setup);
        SCAN_PTR(arg.ndo_fcoe_ddp_done);
    }
})

MODULE_TYPE_WRAPPER(struct net_device_ops* , {
    MODULE_PRE {
		D( kern_printk("struct net_device_ops");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct net_device_ops))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct net_device_ops");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct ethtool_ops, {
    PRE_SCAN {
        SCAN_PTR(arg.get_settings);
        SCAN_PTR(arg.set_settings);
        SCAN_PTR(arg.get_drvinfo);
        SCAN_PTR(arg.get_regs_len);
        SCAN_PTR(arg.get_regs);
        SCAN_PTR(arg.get_wol);
        SCAN_PTR(arg.set_wol);
        SCAN_PTR(arg.get_msglevel);
        SCAN_PTR(arg.set_msglevel);
        SCAN_PTR(arg.nway_reset);
        SCAN_PTR(arg.get_link);
        SCAN_PTR(arg.get_eeprom_len);
        SCAN_PTR(arg.get_eeprom);
        SCAN_PTR(arg.set_eeprom);
        SCAN_PTR(arg.get_coalesce);
        SCAN_PTR(arg.set_coalesce);
        SCAN_PTR(arg.get_ringparam);
        SCAN_PTR(arg.set_ringparam);
        SCAN_PTR(arg.get_pauseparam);
        SCAN_PTR(arg.set_pauseparam);
        SCAN_PTR(arg.get_rx_csum);
        SCAN_PTR(arg.set_rx_csum);
        SCAN_PTR(arg.get_tx_csum);
        SCAN_PTR(arg.set_tx_csum);
        SCAN_PTR(arg.get_sg);
        SCAN_PTR(arg.set_sg);
        SCAN_PTR(arg.get_tso);
        SCAN_PTR(arg.set_tso);
        SCAN_PTR(arg.self_test);
        SCAN_PTR(arg.get_strings);
        SCAN_PTR(arg.phys_id);
        SCAN_PTR(arg.get_ethtool_stats);
        SCAN_PTR(arg.begin);
        SCAN_PTR(arg.complete);
        SCAN_PTR(arg.get_ufo);
        SCAN_PTR(arg.set_ufo);
        SCAN_PTR(arg.get_flags);
        SCAN_PTR(arg.set_flags);
        SCAN_PTR(arg.get_priv_flags);
        SCAN_PTR(arg.set_priv_flags);
        SCAN_PTR(arg.get_sset_count);
        SCAN_PTR(arg.self_test_count);
        SCAN_PTR(arg.get_stats_count);
        SCAN_PTR(arg.get_rxnfc);
        SCAN_PTR(arg.set_rxnfc);
        SCAN_PTR(arg.flash_device);
        SCAN_PTR(arg.reset);
    }
})

MODULE_TYPE_WRAPPER(struct ethtool_ops* , {
    MODULE_PRE {
		D( kern_printk("struct ethtool_ops");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct ethtool_ops))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct ethtool_ops");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct netdev_hw_addr_list, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.list);
    }
})

MODULE_TYPE_WRAPPER(struct netdev_hw_addr_list* , {
    MODULE_PRE {
		D( kern_printk("struct netdev_hw_addr_list");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct netdev_hw_addr_list))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct netdev_hw_addr_list");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct netdev_queue, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.dev);
        SCAN_RECURSIVE(arg.qdisc);
        SCAN_RECURSIVE(arg.qdisc_sleeping);
        SCAN_RECURSIVE(arg._xmit_lock);
    }
})

MODULE_TYPE_WRAPPER(struct netdev_queue* , {
    MODULE_PRE {
		D( kern_printk("struct netdev_queue");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct netdev_queue))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct netdev_queue");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct semaphore, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE(arg.wait_list);
    }
})

MODULE_TYPE_WRAPPER(struct semaphore* , {
    MODULE_PRE {
		D( kern_printk("struct semaphore");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct semaphore))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct semaphore");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct work_struct, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.data);
        SCAN_RECURSIVE(arg.entry);
        SCAN_PTR(arg.func);
    }
})

MODULE_TYPE_WRAPPER(struct work_struct* , {
    MODULE_PRE {
		D( kern_printk("struct work_struct");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct work_struct))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct work_struct");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct dev_pm_info, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.power_state);
        SCAN_RECURSIVE(arg.entry);
        SCAN_RECURSIVE(arg.suspend_timer);
        SCAN_RECURSIVE(arg.work);
        SCAN_RECURSIVE(arg.wait_queue);
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE(arg.usage_count);
        SCAN_RECURSIVE(arg.child_count);
    }
})

MODULE_TYPE_WRAPPER(struct dev_pm_info* , {
    MODULE_PRE {
		D( kern_printk("struct dev_pm_info");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct dev_pm_info))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct dev_pm_info");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct dev_archdata, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.dma_ops);
    }
})

MODULE_TYPE_WRAPPER(struct dev_archdata* , {
    MODULE_PRE {
		D( kern_printk("struct dev_archdata");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct dev_archdata))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct dev_archdata");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct klist_node, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.n_node);
        SCAN_RECURSIVE(arg.n_ref);
    }
})

MODULE_TYPE_WRAPPER(struct klist_node* , {
    MODULE_PRE {
		D( kern_printk("struct klist_node");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct klist_node))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct klist_node");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct device, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.parent);
        SCAN_RECURSIVE(arg.p);
        SCAN_RECURSIVE(arg.kobj);
        SCAN_RECURSIVE(arg.type);
        SCAN_RECURSIVE(arg.sem);
        SCAN_RECURSIVE(arg.bus);
        SCAN_RECURSIVE(arg.driver);
        SCAN_RECURSIVE(arg.power);
        SCAN_RECURSIVE(arg.dma_parms);
        SCAN_RECURSIVE(arg.dma_pools);
        SCAN_RECURSIVE(arg.dma_mem);
        SCAN_RECURSIVE(arg.archdata);
        SCAN_RECURSIVE(arg.devres_lock);
        SCAN_RECURSIVE(arg.devres_head);
        SCAN_RECURSIVE(arg.knode_class);
        SCAN_RECURSIVE(arg.class1);
        SCAN_PTR(arg.release);
    }
})

MODULE_TYPE_WRAPPER(struct device* , {
    MODULE_PRE {
		D( kern_printk("struct device");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct device))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct device");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct net_device, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.name_hlist);
        SCAN_RECURSIVE(arg.dev_list);
        SCAN_RECURSIVE(arg.napi_list);
        SCAN_RECURSIVE(arg.stats);
        SCAN_RECURSIVE(arg.wireless_handlers);
        SCAN_RECURSIVE(arg.wireless_data);
        SCAN_RECURSIVE(arg.netdev_ops);
        SCAN_RECURSIVE(arg.ethtool_ops);
        SCAN_RECURSIVE(arg.header_ops);
        SCAN_RECURSIVE(arg.master);
        SCAN_RECURSIVE(arg.uc);
        SCAN_RECURSIVE(arg.addr_list_lock);
        SCAN_RECURSIVE(arg.mc_list);
        SCAN_RECURSIVE(arg.ieee80211_ptr);
        SCAN_RECURSIVE(arg.dev_addrs);
        SCAN_RECURSIVE(arg.rx_queue);
        SCAN_RECURSIVE(arg._tx);
        SCAN_RECURSIVE(arg.qdisc);
        SCAN_RECURSIVE(arg.tx_global_lock);
        SCAN_RECURSIVE(arg.watchdog_timer);
        SCAN_RECURSIVE(arg.refcnt);
        SCAN_RECURSIVE(arg.todo_list);
        SCAN_RECURSIVE(arg.index_hlist);
        SCAN_RECURSIVE(arg.link_watch_next);
        SCAN_PTR(arg.destructor);
        SCAN_RECURSIVE(arg.npinfo);
        SCAN_RECURSIVE(arg.br_port);
        SCAN_RECURSIVE(arg.macvlan_port);
        SCAN_RECURSIVE(arg.garp_port);
        SCAN_RECURSIVE(arg.dev);
        SCAN_RECURSIVE(arg.rtnl_link_ops);
        SCAN_RECURSIVE(arg.dcbnl_ops);
    }
})

MODULE_TYPE_WRAPPER(struct net_device* , {
    MODULE_PRE {
		D( kern_printk("struct net_device");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct net_device))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct net_device");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct resource, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.parent);
        SCAN_RECURSIVE(arg.sibling);
        SCAN_RECURSIVE(arg.child);
    }
})

MODULE_TYPE_WRAPPER(struct resource* , {
    MODULE_PRE {
		D( kern_printk("struct resource");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct resource))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct resource");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct pci_bus, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.node);
        SCAN_RECURSIVE(arg.parent);
        SCAN_RECURSIVE(arg.children);
        SCAN_RECURSIVE(arg.devices);
        SCAN_RECURSIVE(arg.self);
        SCAN_RECURSIVE(arg.slots);
        SCAN_RECURSIVE(arg.ops);
        SCAN_RECURSIVE(arg.procdir);
        SCAN_RECURSIVE(arg.bridge);
        SCAN_RECURSIVE(arg.dev);
        SCAN_RECURSIVE(arg.legacy_io);
        SCAN_RECURSIVE(arg.legacy_mem);
    }
})

MODULE_TYPE_WRAPPER(struct pci_bus* , {
    MODULE_PRE {
		D( kern_printk("struct pci_bus");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct pci_bus))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct pci_bus");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct rb_node, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.rb_right);
        SCAN_RECURSIVE(arg.rb_left);
    }
})

MODULE_TYPE_WRAPPER(struct rb_node* , {
    MODULE_PRE {
		D( kern_printk("struct rb_node");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct rb_node))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct rb_node");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct sched_entity, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.load);
        SCAN_RECURSIVE(arg.run_node);
        SCAN_RECURSIVE(arg.group_node);
        SCAN_RECURSIVE(arg.parent);
        SCAN_RECURSIVE(arg.cfs_rq);
        SCAN_RECURSIVE(arg.my_q);
    }
})

MODULE_TYPE_WRAPPER(struct sched_entity* , {
    MODULE_PRE {
		D( kern_printk("struct sched_entity");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct sched_entity))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct sched_entity");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct sched_rt_entity, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.run_list);
        SCAN_RECURSIVE(arg.back);
        SCAN_RECURSIVE(arg.parent);
        SCAN_RECURSIVE(arg.rt_rq);
        SCAN_RECURSIVE(arg.my_q);
    }
})

MODULE_TYPE_WRAPPER(struct sched_rt_entity* , {
    MODULE_PRE {
		D( kern_printk("struct sched_rt_entity");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct sched_rt_entity))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct sched_rt_entity");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct plist_head, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.prio_list);
        SCAN_RECURSIVE(arg.node_list);
    }
})

MODULE_TYPE_WRAPPER(struct plist_head* , {
    MODULE_PRE {
		D( kern_printk("struct plist_head");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct plist_head))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct plist_head");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct plist_node, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.plist);
    }
})

MODULE_TYPE_WRAPPER(struct plist_node* , {
    MODULE_PRE {
		D( kern_printk("struct plist_node");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct plist_node))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct plist_node");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct pid_link, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.node);
        SCAN_RECURSIVE(arg.pid);
    }
})

MODULE_TYPE_WRAPPER(struct pid_link* , {
    MODULE_PRE {
		D( kern_printk("struct pid_link");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct pid_link))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct pid_link");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct completion, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.wait);
    }
})

MODULE_TYPE_WRAPPER(struct completion* , {
    MODULE_PRE {
		D( kern_printk("struct completion");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct completion))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct completion");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct sysv_sem, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.undo_list);
    }
})

MODULE_TYPE_WRAPPER(struct sysv_sem* , {
    MODULE_PRE {
		D( kern_printk("struct sysv_sem");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct sysv_sem))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct sysv_sem");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct thread_struct, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.ds_ctx);
    }
})

MODULE_TYPE_WRAPPER(struct thread_struct* , {
    MODULE_PRE {
		D( kern_printk("struct thread_struct");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct thread_struct))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct thread_struct");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct sigpending, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.list);
        SCAN_RECURSIVE(arg.signal);
    }
})

MODULE_TYPE_WRAPPER(struct sigpending* , {
    MODULE_PRE {
		D( kern_printk("struct sigpending");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct sigpending))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct sigpending");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct prop_local_single, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.lock);
    }
})

MODULE_TYPE_WRAPPER(struct prop_local_single* , {
    MODULE_PRE {
		D( kern_printk("struct prop_local_single");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct prop_local_single))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct prop_local_single");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct task_struct, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.usage);
        SCAN_RECURSIVE(arg.sched_class);
        SCAN_RECURSIVE(arg.se);
        SCAN_RECURSIVE(arg.rt);
        SCAN_RECURSIVE(arg.preempt_notifiers);
        SCAN_RECURSIVE(arg.cpus_allowed);
        SCAN_RECURSIVE(arg.sched_info);
        SCAN_RECURSIVE(arg.tasks);
        SCAN_RECURSIVE(arg.pushable_tasks);
        SCAN_RECURSIVE(arg.mm);
        SCAN_RECURSIVE(arg.active_mm);
        SCAN_RECURSIVE(arg.real_parent);
        SCAN_RECURSIVE(arg.parent);
        SCAN_RECURSIVE(arg.children);
        SCAN_RECURSIVE(arg.sibling);
        SCAN_RECURSIVE(arg.group_leader);
        SCAN_RECURSIVE(arg.ptraced);
        SCAN_RECURSIVE(arg.ptrace_entry);
        SCAN_RECURSIVE(arg.bts);
        SCAN_RECURSIVE(arg.thread_group);
        SCAN_RECURSIVE(arg.vfork_done);
        SCAN_RECURSIVE(arg.start_time);
        SCAN_RECURSIVE(arg.real_start_time);
        SCAN_RECURSIVE(arg.cputime_expires);
        SCAN_RECURSIVE(arg.real_cred);
        SCAN_RECURSIVE(arg.cred);
        SCAN_RECURSIVE(arg.cred_guard_mutex);
        SCAN_RECURSIVE(arg.replacement_session_keyring);
        SCAN_RECURSIVE(arg.sysvsem);
        SCAN_RECURSIVE(arg.thread);
        SCAN_RECURSIVE(arg.fs);
        SCAN_RECURSIVE(arg.files);
        SCAN_RECURSIVE(arg.nsproxy);
        SCAN_RECURSIVE(arg.signal);
        SCAN_RECURSIVE(arg.sighand);
        SCAN_RECURSIVE(arg.blocked);
        SCAN_RECURSIVE(arg.real_blocked);
        SCAN_RECURSIVE(arg.saved_sigmask);
        SCAN_RECURSIVE(arg.pending);
        SCAN_PTR(arg.notifier);
        SCAN_RECURSIVE(arg.notifier_mask);
        SCAN_RECURSIVE(arg.audit_context);
        SCAN_RECURSIVE(arg.seccomp);
        SCAN_RECURSIVE(arg.alloc_lock);
        SCAN_RECURSIVE(arg.irqaction);
        SCAN_RECURSIVE(arg.pi_lock);
        SCAN_RECURSIVE(arg.pi_waiters);
        SCAN_RECURSIVE(arg.pi_blocked_on);
        SCAN_RECURSIVE(arg.bio_list);
        SCAN_RECURSIVE(arg.reclaim_state);
        SCAN_RECURSIVE(arg.backing_dev_info);
        SCAN_RECURSIVE(arg.io_context);
        SCAN_RECURSIVE(arg.last_siginfo);
        SCAN_RECURSIVE(arg.ioac);
        SCAN_RECURSIVE(arg.mems_allowed);
        SCAN_RECURSIVE(arg.cgroups);
        SCAN_RECURSIVE(arg.cg_list);
        SCAN_RECURSIVE(arg.robust_list);
        SCAN_RECURSIVE(arg.compat_robust_list);
        SCAN_RECURSIVE(arg.pi_state_list);
        SCAN_RECURSIVE(arg.pi_state_cache);
        SCAN_RECURSIVE(arg.perf_event_ctxp);
        SCAN_RECURSIVE(arg.perf_event_mutex);
        SCAN_RECURSIVE(arg.perf_event_list);
        SCAN_RECURSIVE(arg.mempolicy);
        SCAN_RECURSIVE(arg.fs_excl);
        SCAN_RECURSIVE(arg.rcu);
        SCAN_RECURSIVE(arg.splice_pipe);
        SCAN_RECURSIVE(arg.dirties);
        SCAN_RECURSIVE(arg.scm_work_list);
        SCAN_RECURSIVE(arg.ret_stack);
        SCAN_RECURSIVE(arg.trace_overrun);
        SCAN_RECURSIVE(arg.tracing_graph_pause);
    }
})

MODULE_TYPE_WRAPPER(struct task_struct* , {
    MODULE_PRE {
		D( kern_printk("struct task_struct");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct task_struct))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct task_struct");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct buffer_head, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.b_this_page);
        SCAN_RECURSIVE(arg.b_page);
        SCAN_RECURSIVE(arg.b_bdev);
        SCAN_PTR(arg.b_end_io);
        SCAN_RECURSIVE(arg.b_assoc_buffers);
        SCAN_RECURSIVE(arg.b_assoc_map);
        SCAN_RECURSIVE(arg.b_count);
    }
})

MODULE_TYPE_WRAPPER(struct buffer_head* , {
    MODULE_PRE {
		D( kern_printk("struct buffer_head");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct buffer_head))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct buffer_head");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct pci_dev, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.bus_list);
        SCAN_RECURSIVE(arg.bus);
        SCAN_RECURSIVE(arg.subordinate);
        SCAN_RECURSIVE(arg.procent);
        SCAN_RECURSIVE(arg.slot);
        SCAN_RECURSIVE(arg.driver);
        SCAN_RECURSIVE(arg.dma_parms);
        SCAN_RECURSIVE(arg.dev);
        SCAN_RECURSIVE(arg.enable_cnt);
        SCAN_RECURSIVE(arg.saved_cap_space);
        SCAN_RECURSIVE(arg.rom_attr);
        SCAN_RECURSIVE(arg.msi_list);
        SCAN_RECURSIVE(arg.vpd);
        SCAN_RECURSIVE(arg.ats);
    }
})

MODULE_TYPE_WRAPPER(struct pci_dev* , {
    MODULE_PRE {
		D( kern_printk("struct pci_dev");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct pci_dev))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct pci_dev");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct mii_bus, {
    PRE_SCAN {
        SCAN_PTR(arg.read);
        SCAN_PTR(arg.write);
        SCAN_PTR(arg.reset);
        SCAN_RECURSIVE(arg.mdio_lock);
        SCAN_RECURSIVE(arg.parent);
        SCAN_RECURSIVE(arg.dev);
    }
})

MODULE_TYPE_WRAPPER(struct mii_bus* , {
    MODULE_PRE {
		D( kern_printk("struct mii_bus");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct mii_bus))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct mii_bus");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct xenbus_watch, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.list);
        SCAN_PTR(arg.callback);
    }
})

MODULE_TYPE_WRAPPER(struct xenbus_watch* , {
    MODULE_PRE {
		D( kern_printk("struct xenbus_watch");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct xenbus_watch))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct xenbus_watch");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct xenbus_device, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.otherend_watch);
        SCAN_RECURSIVE(arg.dev);
        SCAN_RECURSIVE(arg.down);
    }
})

MODULE_TYPE_WRAPPER(struct xenbus_device* , {
    MODULE_PRE {
		D( kern_printk("struct xenbus_device");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct xenbus_device))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct xenbus_device");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct dev_pm_ops, {
    PRE_SCAN {
        SCAN_PTR(arg.prepare);
        SCAN_PTR(arg.complete);
        SCAN_PTR(arg.suspend);
        SCAN_PTR(arg.resume);
        SCAN_PTR(arg.freeze);
        SCAN_PTR(arg.thaw);
        SCAN_PTR(arg.poweroff);
        SCAN_PTR(arg.restore);
        SCAN_PTR(arg.suspend_noirq);
        SCAN_PTR(arg.resume_noirq);
        SCAN_PTR(arg.freeze_noirq);
        SCAN_PTR(arg.thaw_noirq);
        SCAN_PTR(arg.poweroff_noirq);
        SCAN_PTR(arg.restore_noirq);
        SCAN_PTR(arg.runtime_suspend);
        SCAN_PTR(arg.runtime_resume);
        SCAN_PTR(arg.runtime_idle);
    }
})

MODULE_TYPE_WRAPPER(struct dev_pm_ops* , {
    MODULE_PRE {
		D( kern_printk("struct dev_pm_ops");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct dev_pm_ops))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct dev_pm_ops");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct device_driver, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.bus);
        SCAN_RECURSIVE(arg.owner);
        SCAN_PTR(arg.probe);
        SCAN_PTR(arg.remove);
        SCAN_PTR(arg.shutdown);
        SCAN_PTR(arg.suspend);
        SCAN_PTR(arg.resume);
        SCAN_RECURSIVE(arg.pm);
        SCAN_RECURSIVE(arg.p);
    }
})

MODULE_TYPE_WRAPPER(struct device_driver* , {
    MODULE_PRE {
		D( kern_printk("struct device_driver");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct device_driver))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct device_driver");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct xenbus_driver, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.owner);
        SCAN_RECURSIVE(arg.ids);
        SCAN_PTR(arg.probe);
        SCAN_PTR(arg.otherend_changed);
        SCAN_PTR(arg.remove);
        SCAN_PTR(arg.suspend);
        SCAN_PTR(arg.resume);
        SCAN_PTR(arg.uevent);
        SCAN_RECURSIVE(arg.driver);
        SCAN_PTR(arg.read_otherend_details);
        SCAN_PTR(arg.is_ready);
    }
})

MODULE_TYPE_WRAPPER(struct xenbus_driver* , {
    MODULE_PRE {
		D( kern_printk("struct xenbus_driver");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct xenbus_driver))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct xenbus_driver");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct phy_driver, {
    PRE_SCAN {
        SCAN_PTR(arg.config_init);
        SCAN_PTR(arg.probe);
        SCAN_PTR(arg.suspend);
        SCAN_PTR(arg.resume);
        SCAN_PTR(arg.config_aneg);
        SCAN_PTR(arg.read_status);
        SCAN_PTR(arg.ack_interrupt);
        SCAN_PTR(arg.config_intr);
        SCAN_PTR(arg.did_interrupt);
        SCAN_PTR(arg.remove);
        SCAN_RECURSIVE(arg.driver);
    }
})

MODULE_TYPE_WRAPPER(struct phy_driver* , {
    MODULE_PRE {
		D( kern_printk("struct phy_driver");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct phy_driver))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct phy_driver");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct delayed_work, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.work);
        SCAN_RECURSIVE(arg.timer);
    }
})

MODULE_TYPE_WRAPPER(struct delayed_work* , {
    MODULE_PRE {
		D( kern_printk("struct delayed_work");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct delayed_work))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct delayed_work");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct phy_device, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.drv);
        SCAN_RECURSIVE(arg.bus);
        SCAN_RECURSIVE(arg.dev);
        SCAN_RECURSIVE(arg.phy_queue);
        SCAN_RECURSIVE(arg.state_queue);
        SCAN_RECURSIVE(arg.irq_disable);
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE(arg.attached_dev);
        SCAN_PTR(arg.adjust_link);
        SCAN_PTR(arg.adjust_state);
    }
})

MODULE_TYPE_WRAPPER(struct phy_device* , {
    MODULE_PRE {
		D( kern_printk("struct phy_device");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct phy_device))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct phy_device");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct napi_struct, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.poll_list);
        SCAN_PTR(arg.poll);
        SCAN_RECURSIVE(arg.poll_lock);
        SCAN_RECURSIVE(arg.dev);
        SCAN_RECURSIVE(arg.dev_list);
        SCAN_RECURSIVE(arg.gro_list);
        SCAN_RECURSIVE(arg.skb);
    }
})

MODULE_TYPE_WRAPPER(struct napi_struct* , {
    MODULE_PRE {
		D( kern_printk("struct napi_struct");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct napi_struct))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct napi_struct");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct journal_head, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.b_bh);
        SCAN_RECURSIVE(arg.b_transaction);
        SCAN_RECURSIVE(arg.b_next_transaction);
        SCAN_RECURSIVE(arg.b_tnext);
        SCAN_RECURSIVE(arg.b_tprev);
        SCAN_RECURSIVE(arg.b_cp_transaction);
        SCAN_RECURSIVE(arg.b_cpnext);
        SCAN_RECURSIVE(arg.b_cpprev);
        SCAN_RECURSIVE(arg.b_triggers);
        SCAN_RECURSIVE(arg.b_frozen_triggers);
    }
})

MODULE_TYPE_WRAPPER(struct journal_head* , {
    MODULE_PRE {
		D( kern_printk("struct journal_head");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct journal_head))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct journal_head");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct ctl_table, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.child);
        SCAN_RECURSIVE(arg.parent);
    }
})

MODULE_TYPE_WRAPPER(struct ctl_table* , {
    MODULE_PRE {
		D( kern_printk("struct ctl_table");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct ctl_table))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct ctl_table");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct pci_dynids, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE(arg.list);
    }
})

MODULE_TYPE_WRAPPER(struct pci_dynids* , {
    MODULE_PRE {
		D( kern_printk("struct pci_dynids");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct pci_dynids))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct pci_dynids");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct pci_driver, {
    PRE_SCAN {
        SCAN_RECURSIVE(arg.node);
        SCAN_RECURSIVE(arg.id_table);
        SCAN_PTR(arg.probe);
        SCAN_PTR(arg.remove);
        SCAN_PTR(arg.suspend);
        SCAN_PTR(arg.suspend_late);
        SCAN_PTR(arg.resume_early);
        SCAN_PTR(arg.resume);
        SCAN_PTR(arg.shutdown);
        SCAN_RECURSIVE(arg.err_handler);
        SCAN_RECURSIVE(arg.driver);
        SCAN_RECURSIVE(arg.dynids);
    }
})

MODULE_TYPE_WRAPPER(struct pci_driver* , {
    MODULE_PRE {
		D( kern_printk("struct pci_driver");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct pci_driver))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct pci_driver");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct mb_cache_op, {
    PRE_SCAN {
        SCAN_PTR(arg.free);
    }
})

MODULE_TYPE_WRAPPER(struct mb_cache_op* , {
    MODULE_PRE {
		D( kern_printk("struct mb_cache_op");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct mb_cache_op))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct mb_cache_op");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

TYPE_SCAN_WRAPPER(struct poll_table_struct, {
    PRE_SCAN {
        SCAN_PTR(arg.qproc);
    }
})

MODULE_TYPE_WRAPPER(struct poll_table_struct* , {
    MODULE_PRE {
		D( kern_printk("struct poll_table_struct");)
		ADD_TO_HASH(arg, SCAN_FUNCTION(struct poll_table_struct))
		ADD_TYPELESS_WATCHPOINT(arg);
    }
    MODULE_POST {
		D( kern_printk("struct poll_table_struct");)
		REMOVE_TYPELESS_WATCHPOINT(arg);
    }
    NO_MODULE_RETURN
})

