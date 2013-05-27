/* Auto-generated wrappers. */
#define D(...) __VA_ARGS__


#ifndef WRAPPER_FOR_struct_callback_head
#define WRAPPER_FOR_struct_callback_head
TYPE_WRAPPER(struct callback_head, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.func);
       // WRAP_RECURSIVE(arg.next);
        WRAP_FUNCTION(arg.func);
    }
    NO_POST
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_kset_uevent_ops
#define WRAPPER_FOR_struct_kset_uevent_ops
TYPE_WRAPPER(struct kset_uevent_ops, {
    NO_PRE
    NO_POST
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_kset
#define WRAPPER_FOR_struct_kset
TYPE_WRAPPER(struct kset, {
    PRE_WRAP {
        ADD_TO_HASH( &arg, SCAN_HEAD_FUNC(struct kset));
        WRAP_RECURSIVE(arg.kobj);
    }
    NO_POST
    NO_RETURN
})
#endif


//#define WRAPPER_FOR_struct_sysfs_ops
#ifndef WRAPPER_FOR_struct_sysfs_ops
#define WRAPPER_FOR_struct_sysfs_ops
TYPE_WRAPPER(struct sysfs_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.show);
        ADD_TO_HASH( &arg, SCAN_HEAD_FUNC(struct sysfs_ops));
        WRAP_FUNCTION(arg.show);
        WRAP_FUNCTION(arg.store);
        WRAP_FUNCTION(arg.namespace_);
    }
    NO_POST
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_kobj_ns_type_operations
#define WRAPPER_FOR_struct_kobj_ns_type_operations
TYPE_WRAPPER(struct kobj_ns_type_operations, {
    PRE_WRAP {
        ADD_TO_HASH( &arg, SCAN_HEAD_FUNC(struct kobj_ns_type_operations));
        WRAP_FUNCTION(arg.grab_current_ns);
        WRAP_FUNCTION(arg.netlink_ns);
        WRAP_FUNCTION(arg.initial_ns);
        WRAP_FUNCTION(arg.drop_ns);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_kobj_type
#ifndef WRAPPER_FOR_struct_kobj_type
#define WRAPPER_FOR_struct_kobj_type
TYPE_WRAPPER(struct kobj_type, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.release);
        WRAP_FUNCTION(arg.release);
        WRAP_FUNCTION(arg.child_ns_type);
        WRAP_FUNCTION(arg.namespace_);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_kobject
#ifndef WRAPPER_FOR_struct_kobject
#define WRAPPER_FOR_struct_kobject
TYPE_WRAPPER(struct kobject, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.parent);
        WRAP_RECURSIVE(arg.ktype);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_module_kobject
#ifndef WRAPPER_FOR_struct_module_kobject
#define WRAPPER_FOR_struct_module_kobject
TYPE_WRAPPER(struct module_kobject, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.kobj);
        WRAP_RECURSIVE(arg.mod);
        WRAP_RECURSIVE(arg.drivers_dir);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_module_attribute
#ifndef WRAPPER_FOR_struct_module_attribute
#define WRAPPER_FOR_struct_module_attribute
TYPE_WRAPPER(struct module_attribute, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.show);
        WRAP_FUNCTION(arg.show);
        WRAP_FUNCTION(arg.store);
        WRAP_FUNCTION(arg.setup);
        WRAP_FUNCTION(arg.test);
        WRAP_FUNCTION(arg.free);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_kernel_param_ops
#ifndef WRAPPER_FOR_struct_kernel_param_ops
#define WRAPPER_FOR_struct_kernel_param_ops
TYPE_WRAPPER(struct kernel_param_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.set);
        WRAP_FUNCTION(arg.set);
        WRAP_FUNCTION(arg.get);
        WRAP_FUNCTION(arg.free);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_kparam_array
#ifndef WRAPPER_FOR_struct_kparam_array
#define WRAPPER_FOR_struct_kparam_array
TYPE_WRAPPER(struct kparam_array, {
    NO_PRE
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_kernel_param
#ifndef WRAPPER_FOR_struct_kernel_param
#define WRAPPER_FOR_struct_kernel_param
TYPE_WRAPPER(struct kernel_param, {
    NO_PRE
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_tracepoint
#ifndef WRAPPER_FOR_struct_tracepoint
#define WRAPPER_FOR_struct_tracepoint
TYPE_WRAPPER(struct tracepoint, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.regfunc);
        WRAP_FUNCTION(arg.regfunc);
        WRAP_FUNCTION(arg.unregfunc);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_sched_class
#ifndef WRAPPER_FOR_struct_sched_class
#define WRAPPER_FOR_struct_sched_class
TYPE_WRAPPER(struct sched_class, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.enqueue_task);
        WRAP_FUNCTION(arg.enqueue_task);
        WRAP_FUNCTION(arg.dequeue_task);
        WRAP_FUNCTION(arg.yield_task);
        WRAP_FUNCTION(arg.yield_to_task);
        WRAP_FUNCTION(arg.check_preempt_curr);
        WRAP_FUNCTION(arg.pick_next_task);
        WRAP_FUNCTION(arg.put_prev_task);
        WRAP_FUNCTION(arg.select_task_rq);
        WRAP_FUNCTION(arg.migrate_task_rq);
        WRAP_FUNCTION(arg.pre_schedule);
        WRAP_FUNCTION(arg.post_schedule);
        WRAP_FUNCTION(arg.task_waking);
        WRAP_FUNCTION(arg.task_woken);
        WRAP_FUNCTION(arg.set_cpus_allowed);
        WRAP_FUNCTION(arg.rq_online);
        WRAP_FUNCTION(arg.rq_offline);
        WRAP_FUNCTION(arg.set_curr_task);
        WRAP_FUNCTION(arg.task_tick);
        WRAP_FUNCTION(arg.task_fork);
        WRAP_FUNCTION(arg.switched_from);
        WRAP_FUNCTION(arg.switched_to);
        WRAP_FUNCTION(arg.prio_changed);
        WRAP_FUNCTION(arg.get_rr_interval);
        WRAP_FUNCTION(arg.task_move_group);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_mutex
#ifndef WRAPPER_FOR_struct_mutex
#define WRAPPER_FOR_struct_mutex
TYPE_WRAPPER(struct mutex, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.owner);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_vfsmount
#ifndef WRAPPER_FOR_struct_vfsmount
#define WRAPPER_FOR_struct_vfsmount
TYPE_WRAPPER(struct vfsmount, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.mnt_root);
        WRAP_RECURSIVE(arg.mnt_sb);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_path
#ifndef WRAPPER_FOR_struct_path
#define WRAPPER_FOR_struct_path
TYPE_WRAPPER(struct path, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.mnt);
        WRAP_RECURSIVE(arg.dentry);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_aio_ring_info
#ifndef WRAPPER_FOR_struct_aio_ring_info
#define WRAPPER_FOR_struct_aio_ring_info
TYPE_WRAPPER(struct aio_ring_info, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.ring_pages);
    }
    NO_RETURN
})
#endif


//#define WRAPPER_FOR_struct_work_struct
#ifndef WRAPPER_FOR_struct_work_struct
#define WRAPPER_FOR_struct_work_struct
TYPE_WRAPPER(struct work_struct, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.func);
    }
    NO_POST
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_timer_list
#define WRAPPER_FOR_struct_timer_list
TYPE_WRAPPER(struct timer_list, {
    PRE_WRAP {
        ADD_TO_HASH(&arg, SCAN_HEAD_FUNC(struct timer_list));
        WRAP_FUNCTION(arg.function);
    }
    NO_POST
    NO_RETURN
})
#endif


//#define WRAPPER_FOR_struct_delayed_work
#ifndef WRAPPER_FOR_struct_delayed_work
#define WRAPPER_FOR_struct_delayed_work
TYPE_WRAPPER(struct delayed_work, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.work);
        WRAP_RECURSIVE(arg.timer);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_kioctx
#ifndef WRAPPER_FOR_struct_kioctx
#define WRAPPER_FOR_struct_kioctx
TYPE_WRAPPER(struct kioctx, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.mm);
        WRAP_RECURSIVE(arg.ring_info);
        WRAP_RECURSIVE(arg.wq);
        WRAP_RECURSIVE(arg.callback_head);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_kiocb
#ifndef WRAPPER_FOR_struct_kiocb
#define WRAPPER_FOR_struct_kiocb
TYPE_WRAPPER(struct kiocb, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.ki_cancel);
        WRAP_RECURSIVE(arg.ki_filp);
        WRAP_RECURSIVE(arg.ki_ctx);
        WRAP_FUNCTION(arg.ki_cancel);
        WRAP_FUNCTION(arg.ki_retry);
        WRAP_FUNCTION(arg.ki_dtor);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_poll_table_struct
#ifndef WRAPPER_FOR_struct_poll_table_struct
#define WRAPPER_FOR_struct_poll_table_struct
TYPE_WRAPPER(struct poll_table_struct, {
    PRE_WRAP {
        WRAP_FUNCTION(arg._qproc);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pid
#ifndef WRAPPER_FOR_struct_pid
#define WRAPPER_FOR_struct_pid
TYPE_WRAPPER(struct pid, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.rcu);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_fasync_struct
#ifndef WRAPPER_FOR_struct_fasync_struct
#define WRAPPER_FOR_struct_fasync_struct
TYPE_WRAPPER(struct fasync_struct, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.fa_next);
        WRAP_RECURSIVE(arg.fa_file);
        WRAP_RECURSIVE(arg.fa_rcu);
    }
    NO_RETURN
})
#endif


//#define WRAPPER_FOR_struct_file_lock_operations
#ifndef WRAPPER_FOR_struct_file_lock_operations
#define WRAPPER_FOR_struct_file_lock_operations
TYPE_WRAPPER(struct file_lock_operations, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.fl_copy_lock);
        WRAP_FUNCTION(arg.fl_copy_lock);
        WRAP_FUNCTION(arg.fl_release_private);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_lock_manager_operations
#ifndef WRAPPER_FOR_struct_lock_manager_operations
#define WRAPPER_FOR_struct_lock_manager_operations
TYPE_WRAPPER(struct lock_manager_operations, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.lm_compare_owner);
        WRAP_FUNCTION(arg.lm_compare_owner);
        WRAP_FUNCTION(arg.lm_notify);
        WRAP_FUNCTION(arg.lm_grant);
        WRAP_FUNCTION(arg.lm_break);
        WRAP_FUNCTION(arg.lm_change);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_file_lock
#ifndef WRAPPER_FOR_struct_file_lock
#define WRAPPER_FOR_struct_file_lock
TYPE_WRAPPER(struct file_lock, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.fl_next);
        WRAP_RECURSIVE(arg.fl_nspid);
        WRAP_RECURSIVE(arg.fl_file);
        WRAP_RECURSIVE(arg.fl_fasync);
    }
    NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_seq_operations
#define WRAPPER_FOR_struct_seq_operations
TYPE_WRAPPER(struct seq_operations, {
    PRE_WRAP {
        ADD_TO_HASH(&arg, SCAN_HEAD_FUNC(struct seq_operations));
        WRAP_FUNCTION(arg.start);
        WRAP_FUNCTION(arg.stop);
        WRAP_FUNCTION(arg.next);
        WRAP_FUNCTION(arg.show);
    }
    NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_seq_file
#define WRAPPER_FOR_struct_seq_file
TYPE_WRAPPER(struct seq_file, {
    PRE_WRAP {
        ADD_TO_HASH( &arg, SCAN_HEAD_FUNC(struct seq_file));
        WRAP_RECURSIVE(arg.lock);
    }
    NO_POST
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_file_operations
#define WRAPPER_FOR_struct_file_operations
TYPE_WRAPPER(struct file_operations, {
    PRE_WRAP {
        ADD_TO_HASH( &arg, SCAN_HEAD_FUNC(struct file_operations));
        WRAP_RECURSIVE(arg.owner);
        WRAP_FUNCTION(arg.llseek);
        WRAP_FUNCTION(arg.read);
        WRAP_FUNCTION(arg.write);
        WRAP_FUNCTION(arg.aio_read);
        WRAP_FUNCTION(arg.aio_write);
        WRAP_FUNCTION(arg.readdir);
        WRAP_FUNCTION(arg.poll);
        WRAP_FUNCTION(arg.unlocked_ioctl);
        WRAP_FUNCTION(arg.compat_ioctl);
        WRAP_FUNCTION(arg.mmap);
        WRAP_FUNCTION(arg.open);
        WRAP_FUNCTION(arg.flush);
        WRAP_FUNCTION(arg.release);
        WRAP_FUNCTION(arg.fsync);
        WRAP_FUNCTION(arg.aio_fsync);
        WRAP_FUNCTION(arg.fasync);
        WRAP_FUNCTION(arg.lock);
        WRAP_FUNCTION(arg.sendpage);
        WRAP_FUNCTION(arg.get_unmapped_area);
        WRAP_FUNCTION(arg.check_flags);
        WRAP_FUNCTION(arg.flock);
        WRAP_FUNCTION(arg.splice_write);
        WRAP_FUNCTION(arg.splice_read);
        WRAP_FUNCTION(arg.setlease);
        WRAP_FUNCTION(arg.fallocate);
        WRAP_FUNCTION(arg.show_fdinfo);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_fown_struct
#ifndef WRAPPER_FOR_struct_fown_struct
#define WRAPPER_FOR_struct_fown_struct
TYPE_WRAPPER(struct fown_struct, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.pid);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_cred
#ifndef WRAPPER_FOR_struct_cred
#define WRAPPER_FOR_struct_cred
TYPE_WRAPPER(struct cred, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.rcu);
    }
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_file
#define WRAPPER_FOR_struct_file
TYPE_WRAPPER(struct file, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.f_path);
        WRAP_RECURSIVE(arg.f_owner);
        WRAP_RECURSIVE(arg.f_mapping);
    }
    NO_POST
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_attribute_group
#define WRAPPER_FOR_struct_attribute_group
TYPE_WRAPPER(struct attribute_group, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.is_visible);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dev_pm_ops
#ifndef WRAPPER_FOR_struct_dev_pm_ops
#define WRAPPER_FOR_struct_dev_pm_ops
TYPE_WRAPPER(struct dev_pm_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.prepare);
        WRAP_FUNCTION(arg.prepare);
        WRAP_FUNCTION(arg.complete);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.resume);
        WRAP_FUNCTION(arg.freeze);
        WRAP_FUNCTION(arg.thaw);
        WRAP_FUNCTION(arg.poweroff);
        WRAP_FUNCTION(arg.restore);
        WRAP_FUNCTION(arg.suspend_late);
        WRAP_FUNCTION(arg.resume_early);
        WRAP_FUNCTION(arg.freeze_late);
        WRAP_FUNCTION(arg.thaw_early);
        WRAP_FUNCTION(arg.poweroff_late);
        WRAP_FUNCTION(arg.restore_early);
        WRAP_FUNCTION(arg.suspend_noirq);
        WRAP_FUNCTION(arg.resume_noirq);
        WRAP_FUNCTION(arg.freeze_noirq);
        WRAP_FUNCTION(arg.thaw_noirq);
        WRAP_FUNCTION(arg.poweroff_noirq);
        WRAP_FUNCTION(arg.restore_noirq);
        WRAP_FUNCTION(arg.runtime_suspend);
        WRAP_FUNCTION(arg.runtime_resume);
        WRAP_FUNCTION(arg.runtime_idle);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_device_type
#ifndef WRAPPER_FOR_struct_device_type
#define WRAPPER_FOR_struct_device_type
TYPE_WRAPPER(struct device_type, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.uevent);
        WRAP_FUNCTION(arg.uevent);
        WRAP_FUNCTION(arg.devnode);
        WRAP_FUNCTION(arg.release);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_bus_attribute
#ifndef WRAPPER_FOR_struct_bus_attribute
#define WRAPPER_FOR_struct_bus_attribute
TYPE_WRAPPER(struct bus_attribute, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.show);
        WRAP_FUNCTION(arg.show);
        WRAP_FUNCTION(arg.store);
    }
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_device_attribute
#define WRAPPER_FOR_struct_device_attribute
TYPE_WRAPPER(struct device_attribute, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.show);
        WRAP_FUNCTION(arg.show);
        WRAP_FUNCTION(arg.store);
    }
    NO_POST
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_device_driver
#define WRAPPER_FOR_struct_device_driver
TYPE_WRAPPER(struct device_driver, {
    PRE_WRAP {
        ADD_TO_HASH( &arg, SCAN_HEAD_FUNC(struct device_driver));;
        WRAP_RECURSIVE(arg.bus);
        WRAP_RECURSIVE(arg.owner);
        WRAP_FUNCTION(arg.probe);
        WRAP_FUNCTION(arg.remove);
        WRAP_FUNCTION(arg.shutdown);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.resume);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_driver_attribute
#ifndef WRAPPER_FOR_struct_driver_attribute
#define WRAPPER_FOR_struct_driver_attribute
TYPE_WRAPPER(struct driver_attribute, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.show);
        WRAP_FUNCTION(arg.show);
        WRAP_FUNCTION(arg.store);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_bus_type
#ifndef WRAPPER_FOR_struct_bus_type
#define WRAPPER_FOR_struct_bus_type
TYPE_WRAPPER(struct bus_type, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.match);
        WRAP_RECURSIVE(arg.dev_root);
        WRAP_RECURSIVE(arg.bus_attrs);
        WRAP_RECURSIVE(arg.dev_attrs);
        WRAP_RECURSIVE(arg.drv_attrs);
        WRAP_FUNCTION(arg.match);
        WRAP_FUNCTION(arg.uevent);
        WRAP_FUNCTION(arg.probe);
        WRAP_FUNCTION(arg.remove);
        WRAP_FUNCTION(arg.shutdown);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.resume);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_wakeup_source
#ifndef WRAPPER_FOR_struct_wakeup_source
#define WRAPPER_FOR_struct_wakeup_source
TYPE_WRAPPER(struct wakeup_source, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.timer);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_notifier_block
#ifndef WRAPPER_FOR_struct_notifier_block
#define WRAPPER_FOR_struct_notifier_block
TYPE_WRAPPER(struct notifier_block, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.notifier_call);
        WRAP_FUNCTION(arg.notifier_call);
        WRAP_RECURSIVE(arg.next);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_blocking_notifier_head
#ifndef WRAPPER_FOR_struct_blocking_notifier_head
#define WRAPPER_FOR_struct_blocking_notifier_head
TYPE_WRAPPER(struct blocking_notifier_head, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.head);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pm_qos_constraints
#ifndef WRAPPER_FOR_struct_pm_qos_constraints
#define WRAPPER_FOR_struct_pm_qos_constraints
TYPE_WRAPPER(struct pm_qos_constraints, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.notifiers);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dev_pm_qos_request
#ifndef WRAPPER_FOR_struct_dev_pm_qos_request
#define WRAPPER_FOR_struct_dev_pm_qos_request
TYPE_WRAPPER(struct dev_pm_qos_request, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dev_pm_qos
#ifndef WRAPPER_FOR_struct_dev_pm_qos
#define WRAPPER_FOR_struct_dev_pm_qos
TYPE_WRAPPER(struct dev_pm_qos, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.latency);
        WRAP_RECURSIVE(arg.latency_req);
        WRAP_RECURSIVE(arg.flags_req);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dev_pm_info
#ifndef WRAPPER_FOR_struct_dev_pm_info
#define WRAPPER_FOR_struct_dev_pm_info
TYPE_WRAPPER(struct dev_pm_info, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.wakeup);
        WRAP_RECURSIVE(arg.suspend_timer);
        WRAP_RECURSIVE(arg.work);
        WRAP_RECURSIVE(arg.qos);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dev_pm_domain
#ifndef WRAPPER_FOR_struct_dev_pm_domain
#define WRAPPER_FOR_struct_dev_pm_domain
TYPE_WRAPPER(struct dev_pm_domain, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.ops);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dma_map_ops
#ifndef WRAPPER_FOR_struct_dma_map_ops
#define WRAPPER_FOR_struct_dma_map_ops
TYPE_WRAPPER(struct dma_map_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.alloc);
        WRAP_FUNCTION(arg.alloc);
        WRAP_FUNCTION(arg.free);
        WRAP_FUNCTION(arg.mmap);
        WRAP_FUNCTION(arg.get_sgtable);
        WRAP_FUNCTION(arg.map_page);
        WRAP_FUNCTION(arg.unmap_page);
        WRAP_FUNCTION(arg.map_sg);
        WRAP_FUNCTION(arg.unmap_sg);
        WRAP_FUNCTION(arg.sync_single_for_cpu);
        WRAP_FUNCTION(arg.sync_single_for_device);
        WRAP_FUNCTION(arg.sync_sg_for_cpu);
        WRAP_FUNCTION(arg.sync_sg_for_device);
        WRAP_FUNCTION(arg.mapping_error);
        WRAP_FUNCTION(arg.dma_supported);
        WRAP_FUNCTION(arg.set_dma_mask);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dev_archdata
#ifndef WRAPPER_FOR_struct_dev_archdata
#define WRAPPER_FOR_struct_dev_archdata
TYPE_WRAPPER(struct dev_archdata, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dma_ops);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_class_attribute
#ifndef WRAPPER_FOR_struct_class_attribute
#define WRAPPER_FOR_struct_class_attribute
TYPE_WRAPPER(struct class_attribute, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.show);
        WRAP_FUNCTION(arg.show);
        WRAP_FUNCTION(arg.store);
        WRAP_FUNCTION(arg.namespace_);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_bin_attribute
#ifndef WRAPPER_FOR_struct_bin_attribute
#define WRAPPER_FOR_struct_bin_attribute
TYPE_WRAPPER(struct bin_attribute, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.read);
        WRAP_FUNCTION(arg.read);
        WRAP_FUNCTION(arg.write);
        WRAP_FUNCTION(arg.mmap);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_class_
#ifndef WRAPPER_FOR_struct_class_
#define WRAPPER_FOR_struct_class_
TYPE_WRAPPER(struct class_, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.dev_uevent);
        WRAP_RECURSIVE(arg.owner);
        WRAP_RECURSIVE(arg.class_attrs);
        WRAP_RECURSIVE(arg.dev_attrs);
        WRAP_RECURSIVE(arg.dev_bin_attrs);
        WRAP_RECURSIVE(arg.dev_kobj);
        WRAP_FUNCTION(arg.dev_uevent);
        WRAP_FUNCTION(arg.devnode);
        WRAP_FUNCTION(arg.class_release);
        WRAP_FUNCTION(arg.dev_release);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.resume);
        WRAP_FUNCTION(arg.namespace_);
    }
    NO_POST
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_device
#define WRAPPER_FOR_struct_device
TYPE_WRAPPER(struct device, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.release);
        WRAP_RECURSIVE(arg.parent);
        WRAP_RECURSIVE(arg.kobj);
        WRAP_RECURSIVE(arg.mutex);
        WRAP_RECURSIVE(arg.bus);
        WRAP_RECURSIVE(arg.driver);
        WRAP_RECURSIVE(arg.power);
        WRAP_RECURSIVE(arg.pm_domain);
        WRAP_RECURSIVE(arg.archdata);
        WRAP_RECURSIVE(arg.class_);
        WRAP_FUNCTION(arg.release);
    }
    NO_POST
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_hd_struct
#define WRAPPER_FOR_struct_hd_struct
TYPE_WRAPPER(struct hd_struct, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.__dev);
        WRAP_RECURSIVE(arg.holder_dir);
        WRAP_RECURSIVE(arg.callback_head);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_disk_part_tbl
#ifndef WRAPPER_FOR_struct_disk_part_tbl
#define WRAPPER_FOR_struct_disk_part_tbl
TYPE_WRAPPER(struct disk_part_tbl, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.callback_head);
        WRAP_RECURSIVE(arg.last_lookup);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_block_device_operations
#ifndef WRAPPER_FOR_struct_block_device_operations
#define WRAPPER_FOR_struct_block_device_operations
TYPE_WRAPPER(struct block_device_operations, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.open);
        WRAP_FUNCTION(arg.open);
        WRAP_FUNCTION(arg.release);
        WRAP_FUNCTION(arg.ioctl);
        WRAP_FUNCTION(arg.compat_ioctl);
        WRAP_FUNCTION(arg.direct_access);
        WRAP_FUNCTION(arg.check_events);
        WRAP_FUNCTION(arg.media_changed);
        WRAP_FUNCTION(arg.unlock_native_capacity);
        WRAP_FUNCTION(arg.revalidate_disk);
        WRAP_FUNCTION(arg.getgeo);
        WRAP_FUNCTION(arg.swap_slot_free_notify);
        WRAP_RECURSIVE(arg.owner);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_call_single_data
#ifndef WRAPPER_FOR_struct_call_single_data
#define WRAPPER_FOR_struct_call_single_data
TYPE_WRAPPER(struct call_single_data, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.func);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_kmem_cache_cpu
#ifndef WRAPPER_FOR_struct_kmem_cache_cpu
#define WRAPPER_FOR_struct_kmem_cache_cpu
TYPE_WRAPPER(struct kmem_cache_cpu, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.page);
        WRAP_RECURSIVE(arg.partial);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_kmem_cache
#ifndef WRAPPER_FOR_struct_kmem_cache
#define WRAPPER_FOR_struct_kmem_cache
TYPE_WRAPPER(struct kmem_cache, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.ctor);
        WRAP_RECURSIVE(arg.cpu_slab);
        WRAP_FUNCTION(arg.ctor);
        WRAP_RECURSIVE(arg.kobj);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_io_cq
#ifndef WRAPPER_FOR_struct_io_cq
#define WRAPPER_FOR_struct_io_cq
TYPE_WRAPPER(struct io_cq, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.q);
        WRAP_RECURSIVE(arg.ioc);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_io_context
#ifndef WRAPPER_FOR_struct_io_context
#define WRAPPER_FOR_struct_io_context
TYPE_WRAPPER(struct io_context, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.icq_hint);
        WRAP_RECURSIVE(arg.release_work);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_cgroup
#ifndef WRAPPER_FOR_struct_cgroup
#define WRAPPER_FOR_struct_cgroup
TYPE_WRAPPER(struct cgroup, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.parent);
        WRAP_RECURSIVE(arg.dentry);
        WRAP_RECURSIVE(arg.top_cgroup);
        WRAP_RECURSIVE(arg.pidlist_mutex);
        WRAP_RECURSIVE(arg.callback_head);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_cgroup_subsys_state
#ifndef WRAPPER_FOR_struct_cgroup_subsys_state
#define WRAPPER_FOR_struct_cgroup_subsys_state
TYPE_WRAPPER(struct cgroup_subsys_state, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.cgroup);
        WRAP_RECURSIVE(arg.dput_work);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_bio_vec
#ifndef WRAPPER_FOR_struct_bio_vec
#define WRAPPER_FOR_struct_bio_vec
TYPE_WRAPPER(struct bio_vec, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.bv_page);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_bio_integrity_payload
#ifndef WRAPPER_FOR_struct_bio_integrity_payload
#define WRAPPER_FOR_struct_bio_integrity_payload
TYPE_WRAPPER(struct bio_integrity_payload, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.bip_end_io);
        WRAP_RECURSIVE(arg.bip_bio);
        WRAP_FUNCTION(arg.bip_end_io);
        WRAP_RECURSIVE(arg.bip_work);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_mempool_s
#ifndef WRAPPER_FOR_struct_mempool_s
#define WRAPPER_FOR_struct_mempool_s
TYPE_WRAPPER(struct mempool_s, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.alloc);
        WRAP_FUNCTION(arg.alloc);
        WRAP_FUNCTION(arg.free);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_bio_set
#ifndef WRAPPER_FOR_struct_bio_set
#define WRAPPER_FOR_struct_bio_set
TYPE_WRAPPER(struct bio_set, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.bio_slab);
        WRAP_RECURSIVE(arg.bio_pool);
        WRAP_RECURSIVE(arg.bio_integrity_pool);
        WRAP_RECURSIVE(arg.bvec_pool);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_bio
#ifndef WRAPPER_FOR_struct_bio
#define WRAPPER_FOR_struct_bio
TYPE_WRAPPER(struct bio, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.bi_end_io);
        WRAP_RECURSIVE(arg.bi_next);
        WRAP_RECURSIVE(arg.bi_bdev);
        WRAP_FUNCTION(arg.bi_end_io);
        WRAP_RECURSIVE(arg.bi_ioc);
        WRAP_RECURSIVE(arg.bi_css);
        WRAP_RECURSIVE(arg.bi_integrity);
        WRAP_RECURSIVE(arg.bi_io_vec);
        WRAP_RECURSIVE(arg.bi_pool);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_request_list
#ifndef WRAPPER_FOR_struct_request_list
#define WRAPPER_FOR_struct_request_list
TYPE_WRAPPER(struct request_list, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.q);
        WRAP_RECURSIVE(arg.rq_pool);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_request
#ifndef WRAPPER_FOR_struct_request
#define WRAPPER_FOR_struct_request
TYPE_WRAPPER(struct request, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.end_io);
        WRAP_RECURSIVE(arg.csd);
        WRAP_RECURSIVE(arg.q);
        WRAP_RECURSIVE(arg.bio);
        WRAP_RECURSIVE(arg.biotail);
        WRAP_RECURSIVE(arg.rq_disk);
        WRAP_RECURSIVE(arg.part);
        WRAP_RECURSIVE(arg.rl);
        WRAP_FUNCTION(arg.end_io);
        WRAP_RECURSIVE(arg.next_rq);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_elevator_ops
#ifndef WRAPPER_FOR_struct_elevator_ops
#define WRAPPER_FOR_struct_elevator_ops
TYPE_WRAPPER(struct elevator_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.elevator_merge_fn);
        WRAP_FUNCTION(arg.elevator_merge_fn);
        WRAP_FUNCTION(arg.elevator_merged_fn);
        WRAP_FUNCTION(arg.elevator_merge_req_fn);
        WRAP_FUNCTION(arg.elevator_allow_merge_fn);
        WRAP_FUNCTION(arg.elevator_bio_merged_fn);
        WRAP_FUNCTION(arg.elevator_dispatch_fn);
        WRAP_FUNCTION(arg.elevator_add_req_fn);
        WRAP_FUNCTION(arg.elevator_activate_req_fn);
        WRAP_FUNCTION(arg.elevator_deactivate_req_fn);
        WRAP_FUNCTION(arg.elevator_completed_req_fn);
        WRAP_FUNCTION(arg.elevator_former_req_fn);
        WRAP_FUNCTION(arg.elevator_latter_req_fn);
        WRAP_FUNCTION(arg.elevator_init_icq_fn);
        WRAP_FUNCTION(arg.elevator_exit_icq_fn);
        WRAP_FUNCTION(arg.elevator_set_req_fn);
        WRAP_FUNCTION(arg.elevator_put_req_fn);
        WRAP_FUNCTION(arg.elevator_may_queue_fn);
        WRAP_FUNCTION(arg.elevator_init_fn);
        WRAP_FUNCTION(arg.elevator_exit_fn);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_elv_fs_entry
#ifndef WRAPPER_FOR_struct_elv_fs_entry
#define WRAPPER_FOR_struct_elv_fs_entry
TYPE_WRAPPER(struct elv_fs_entry, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.show);
        WRAP_FUNCTION(arg.show);
        WRAP_FUNCTION(arg.store);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_elevator_type
#ifndef WRAPPER_FOR_struct_elevator_type
#define WRAPPER_FOR_struct_elevator_type
TYPE_WRAPPER(struct elevator_type, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.icq_cache);
        WRAP_RECURSIVE(arg.ops);
        WRAP_RECURSIVE(arg.elevator_attrs);
        WRAP_RECURSIVE(arg.elevator_owner);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_elevator_queue
#ifndef WRAPPER_FOR_struct_elevator_queue
#define WRAPPER_FOR_struct_elevator_queue
TYPE_WRAPPER(struct elevator_queue, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.type);
        WRAP_RECURSIVE(arg.kobj);
        WRAP_RECURSIVE(arg.sysfs_lock);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_bvec_merge_data
#ifndef WRAPPER_FOR_struct_bvec_merge_data
#define WRAPPER_FOR_struct_bvec_merge_data
TYPE_WRAPPER(struct bvec_merge_data, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.bi_bdev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_bdi_writeback
#ifndef WRAPPER_FOR_struct_bdi_writeback
#define WRAPPER_FOR_struct_bdi_writeback
TYPE_WRAPPER(struct bdi_writeback, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.bdi);
        WRAP_RECURSIVE(arg.task);
        WRAP_RECURSIVE(arg.wakeup_timer);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_backing_dev_info
#ifndef WRAPPER_FOR_struct_backing_dev_info
#define WRAPPER_FOR_struct_backing_dev_info
TYPE_WRAPPER(struct backing_dev_info, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.congested_fn);
        WRAP_FUNCTION(arg.congested_fn);
        WRAP_RECURSIVE(arg.wb);
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.laptop_mode_wb_timer);
        WRAP_RECURSIVE(arg.debug_dir);
        WRAP_RECURSIVE(arg.debug_stats);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_blk_queue_tag
#ifndef WRAPPER_FOR_struct_blk_queue_tag
#define WRAPPER_FOR_struct_blk_queue_tag
TYPE_WRAPPER(struct blk_queue_tag, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.tag_index);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_bsg_class_device
#ifndef WRAPPER_FOR_struct_bsg_class_device
#define WRAPPER_FOR_struct_bsg_class_device
TYPE_WRAPPER(struct bsg_class_device, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.release);
        WRAP_RECURSIVE(arg.class_dev);
        WRAP_RECURSIVE(arg.parent);
        WRAP_RECURSIVE(arg.queue);
        WRAP_FUNCTION(arg.release);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_request_queue
#ifndef WRAPPER_FOR_struct_request_queue
#define WRAPPER_FOR_struct_request_queue
TYPE_WRAPPER(struct request_queue, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.request_fn);
        WRAP_RECURSIVE(arg.last_merge);
        WRAP_RECURSIVE(arg.elevator);
        WRAP_RECURSIVE(arg.root_rl);
        WRAP_FUNCTION(arg.request_fn);
        WRAP_FUNCTION(arg.make_request_fn);
        WRAP_FUNCTION(arg.prep_rq_fn);
        WRAP_FUNCTION(arg.unprep_rq_fn);
        WRAP_FUNCTION(arg.merge_bvec_fn);
        WRAP_FUNCTION(arg.softirq_done_fn);
        WRAP_FUNCTION(arg.rq_timed_out_fn);
        WRAP_FUNCTION(arg.dma_drain_needed);
        WRAP_FUNCTION(arg.lld_busy_fn);
        WRAP_RECURSIVE(arg.boundary_rq);
        WRAP_RECURSIVE(arg.delay_work);
        WRAP_RECURSIVE(arg.backing_dev_info);
        WRAP_RECURSIVE(arg.kobj);
        WRAP_RECURSIVE(arg.queue_tags);
        WRAP_RECURSIVE(arg.timeout);
        WRAP_RECURSIVE(arg.flush_rq);
        WRAP_RECURSIVE(arg.sysfs_lock);
        WRAP_FUNCTION(arg.bsg_job_fn);
        WRAP_RECURSIVE(arg.bsg_dev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_blk_integrity
#ifndef WRAPPER_FOR_struct_blk_integrity
#define WRAPPER_FOR_struct_blk_integrity
TYPE_WRAPPER(struct blk_integrity, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.generate_fn);
        WRAP_FUNCTION(arg.generate_fn);
        WRAP_FUNCTION(arg.verify_fn);
        WRAP_FUNCTION(arg.set_tag_fn);
        WRAP_FUNCTION(arg.get_tag_fn);
        WRAP_RECURSIVE(arg.kobj);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_gendisk
#ifndef WRAPPER_FOR_struct_gendisk
#define WRAPPER_FOR_struct_gendisk
TYPE_WRAPPER(struct gendisk, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.devnode);
        WRAP_FUNCTION(arg.devnode);
        WRAP_RECURSIVE(arg.part_tbl);
        WRAP_RECURSIVE(arg.part0);
        WRAP_RECURSIVE(arg.queue);
        WRAP_RECURSIVE(arg.driverfs_dev);
        WRAP_RECURSIVE(arg.slave_dir);
        WRAP_RECURSIVE(arg.integrity);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_block_device
#ifndef WRAPPER_FOR_struct_block_device
#define WRAPPER_FOR_struct_block_device
TYPE_WRAPPER(struct block_device, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.bd_inode);
        WRAP_RECURSIVE(arg.bd_super);
        WRAP_RECURSIVE(arg.bd_mutex);
        WRAP_RECURSIVE(arg.bd_contains);
        WRAP_RECURSIVE(arg.bd_part);
        WRAP_RECURSIVE(arg.bd_disk);
        WRAP_RECURSIVE(arg.bd_queue);
        WRAP_RECURSIVE(arg.bd_fsfreeze_mutex);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_swap_info_struct
#ifndef WRAPPER_FOR_struct_swap_info_struct
#define WRAPPER_FOR_struct_swap_info_struct
TYPE_WRAPPER(struct swap_info_struct, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.bdev);
        WRAP_RECURSIVE(arg.swap_file);
    }
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_address_space_operations
#define WRAPPER_FOR_struct_address_space_operations
TYPE_WRAPPER(struct address_space_operations, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.writepage);
        WRAP_FUNCTION(arg.writepage);
        WRAP_FUNCTION(arg.readpage);
        WRAP_FUNCTION(arg.writepages);
        WRAP_FUNCTION(arg.set_page_dirty);
        WRAP_FUNCTION(arg.readpages);
        WRAP_FUNCTION(arg.write_begin);
        WRAP_FUNCTION(arg.write_end);
        WRAP_FUNCTION(arg.bmap);
        WRAP_FUNCTION(arg.invalidatepage);
        WRAP_FUNCTION(arg.releasepage);
        WRAP_FUNCTION(arg.freepage);
        WRAP_FUNCTION(arg.direct_IO);
        WRAP_FUNCTION(arg.get_xip_mem);
        WRAP_FUNCTION(arg.migratepage);
        WRAP_FUNCTION(arg.launder_page);
        WRAP_FUNCTION(arg.is_partially_uptodate);
        WRAP_FUNCTION(arg.error_remove_page);
        WRAP_FUNCTION(arg.swap_activate);
        WRAP_FUNCTION(arg.swap_deactivate);
    }
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_address_space
#define WRAPPER_FOR_struct_address_space
TYPE_WRAPPER(struct address_space, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.host);
        WRAP_RECURSIVE(arg.i_mmap_mutex);
        WRAP_RECURSIVE(arg.backing_dev_info);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_page
#ifndef WRAPPER_FOR_struct_page
#define WRAPPER_FOR_struct_page
TYPE_WRAPPER(struct page, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.mapping);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_vm_fault
#ifndef WRAPPER_FOR_struct_vm_fault
#define WRAPPER_FOR_struct_vm_fault
TYPE_WRAPPER(struct vm_fault, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.page);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_vm_operations_struct
#ifndef WRAPPER_FOR_struct_vm_operations_struct
#define WRAPPER_FOR_struct_vm_operations_struct
TYPE_WRAPPER(struct vm_operations_struct, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.open);
        WRAP_FUNCTION(arg.open);
        WRAP_FUNCTION(arg.close);
        WRAP_FUNCTION(arg.fault);
        WRAP_FUNCTION(arg.page_mkwrite);
        WRAP_FUNCTION(arg.access);
        WRAP_FUNCTION(arg.set_policy);
        WRAP_FUNCTION(arg.get_policy);
        WRAP_FUNCTION(arg.migrate);
        WRAP_FUNCTION(arg.remap_pages);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_vm_area_struct
#ifndef WRAPPER_FOR_struct_vm_area_struct
#define WRAPPER_FOR_struct_vm_area_struct
TYPE_WRAPPER(struct vm_area_struct, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.vm_next);
        WRAP_RECURSIVE(arg.vm_mm);
        WRAP_RECURSIVE(arg.vm_file);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_mm_context_t
#ifndef WRAPPER_FOR_mm_context_t
#define WRAPPER_FOR_mm_context_t
TYPE_WRAPPER(mm_context_t, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.lock);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_core_thread
#ifndef WRAPPER_FOR_struct_core_thread
#define WRAPPER_FOR_struct_core_thread
TYPE_WRAPPER(struct core_thread, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.task);
        WRAP_RECURSIVE(arg.next);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_core_state
#ifndef WRAPPER_FOR_struct_core_state
#define WRAPPER_FOR_struct_core_state
TYPE_WRAPPER(struct core_state, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dumper);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_mm_struct
#ifndef WRAPPER_FOR_struct_mm_struct
#define WRAPPER_FOR_struct_mm_struct
TYPE_WRAPPER(struct mm_struct, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.get_unmapped_area);
        WRAP_RECURSIVE(arg.mmap);
        WRAP_RECURSIVE(arg.mmap_cache);
        WRAP_FUNCTION(arg.get_unmapped_area);
        WRAP_FUNCTION(arg.unmap_area);
        WRAP_RECURSIVE(arg.context);
        WRAP_RECURSIVE(arg.core_state);
        WRAP_RECURSIVE(arg.exe_file);
        WRAP_RECURSIVE(arg.pmd_huge_pte);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pid_link
#ifndef WRAPPER_FOR_struct_pid_link
#define WRAPPER_FOR_struct_pid_link
TYPE_WRAPPER(struct pid_link, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.pid);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_nsproxy
#ifndef WRAPPER_FOR_struct_nsproxy
#define WRAPPER_FOR_struct_nsproxy
TYPE_WRAPPER(struct nsproxy, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.net_ns);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_hrtimer_clock_base
#ifndef WRAPPER_FOR_struct_hrtimer_clock_base
#define WRAPPER_FOR_struct_hrtimer_clock_base
TYPE_WRAPPER(struct hrtimer_clock_base, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.get_time);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_hrtimer
#ifndef WRAPPER_FOR_struct_hrtimer
#define WRAPPER_FOR_struct_hrtimer
TYPE_WRAPPER(struct hrtimer, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.function);
        WRAP_FUNCTION(arg.function);
        WRAP_RECURSIVE(arg.base);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_signal_struct
#ifndef WRAPPER_FOR_struct_signal_struct
#define WRAPPER_FOR_struct_signal_struct
TYPE_WRAPPER(struct signal_struct, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.curr_target);
        WRAP_RECURSIVE(arg.group_exit_task);
        WRAP_RECURSIVE(arg.real_timer);
        WRAP_RECURSIVE(arg.leader_pid);
        WRAP_RECURSIVE(arg.tty_old_pgrp);
        WRAP_RECURSIVE(arg.cred_guard_mutex);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_sigaction
#ifndef WRAPPER_FOR_struct_sigaction
#define WRAPPER_FOR_struct_sigaction
TYPE_WRAPPER(struct sigaction, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.sa_handler);
        WRAP_FUNCTION(arg.sa_restorer);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_k_sigaction
#ifndef WRAPPER_FOR_struct_k_sigaction
#define WRAPPER_FOR_struct_k_sigaction
TYPE_WRAPPER(struct k_sigaction, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.sa);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_bio_list
#ifndef WRAPPER_FOR_struct_bio_list
#define WRAPPER_FOR_struct_bio_list
TYPE_WRAPPER(struct bio_list, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.head);
        WRAP_RECURSIVE(arg.tail);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_css_set
#ifndef WRAPPER_FOR_struct_css_set
#define WRAPPER_FOR_struct_css_set
TYPE_WRAPPER(struct css_set, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.callback_head);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_page_frag
#ifndef WRAPPER_FOR_struct_page_frag
#define WRAPPER_FOR_struct_page_frag
TYPE_WRAPPER(struct page_frag, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.page);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_task_struct
#ifndef WRAPPER_FOR_struct_task_struct
#define WRAPPER_FOR_struct_task_struct
TYPE_WRAPPER(struct task_struct, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.notifier);
        WRAP_RECURSIVE(arg.mm);
        WRAP_RECURSIVE(arg.active_mm);
        WRAP_RECURSIVE(arg.real_parent);
        WRAP_RECURSIVE(arg.parent);
        WRAP_RECURSIVE(arg.group_leader);
        WRAP_RECURSIVE(arg.nsproxy);
        WRAP_RECURSIVE(arg.signal);
        WRAP_FUNCTION(arg.notifier);
        WRAP_RECURSIVE(arg.task_works);
        WRAP_RECURSIVE(arg.bio_list);
        WRAP_RECURSIVE(arg.backing_dev_info);
        WRAP_RECURSIVE(arg.io_context);
        WRAP_RECURSIVE(arg.cgroups);
        WRAP_RECURSIVE(arg.perf_event_mutex);
        WRAP_RECURSIVE(arg.rcu);
        WRAP_RECURSIVE(arg.task_frag);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_module
#ifndef WRAPPER_FOR_struct_module
#define WRAPPER_FOR_struct_module
TYPE_WRAPPER(struct module, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.init);
        WRAP_RECURSIVE(arg.mkobj);
        WRAP_RECURSIVE(arg.modinfo_attrs);
        WRAP_RECURSIVE(arg.holders_dir);
        WRAP_FUNCTION(arg.init);
        WRAP_RECURSIVE(arg.waiter);
        WRAP_FUNCTION(arg.exit);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_file_system_type
#ifndef WRAPPER_FOR_struct_file_system_type
#define WRAPPER_FOR_struct_file_system_type
TYPE_WRAPPER(struct file_system_type, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.mount);
        WRAP_FUNCTION(arg.mount);
        WRAP_FUNCTION(arg.kill_sb);
        WRAP_RECURSIVE(arg.owner);
        WRAP_RECURSIVE(arg.next);
    }
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_super_operations
#define WRAPPER_FOR_struct_super_operations
TYPE_WRAPPER(struct super_operations, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.alloc_inode);
        WRAP_FUNCTION(arg.alloc_inode);
        WRAP_FUNCTION(arg.destroy_inode);
        WRAP_FUNCTION(arg.dirty_inode);
        WRAP_FUNCTION(arg.write_inode);
        WRAP_FUNCTION(arg.drop_inode);
        WRAP_FUNCTION(arg.evict_inode);
        WRAP_FUNCTION(arg.put_super);
        WRAP_FUNCTION(arg.sync_fs);
        WRAP_FUNCTION(arg.freeze_fs);
        WRAP_FUNCTION(arg.unfreeze_fs);
        WRAP_FUNCTION(arg.statfs);
        WRAP_FUNCTION(arg.remount_fs);
        WRAP_FUNCTION(arg.umount_begin);
        WRAP_FUNCTION(arg.show_options);
        WRAP_FUNCTION(arg.show_devname);
        WRAP_FUNCTION(arg.show_path);
        WRAP_FUNCTION(arg.show_stats);
        WRAP_FUNCTION(arg.quota_read);
        WRAP_FUNCTION(arg.quota_write);
        WRAP_FUNCTION(arg.bdev_try_to_free_page);
        WRAP_FUNCTION(arg.nr_cached_objects);
        WRAP_FUNCTION(arg.free_cached_objects);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dquot
#ifndef WRAPPER_FOR_struct_dquot
#define WRAPPER_FOR_struct_dquot
TYPE_WRAPPER(struct dquot, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dq_lock);
        WRAP_RECURSIVE(arg.dq_sb);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dquot_operations
#ifndef WRAPPER_FOR_struct_dquot_operations
#define WRAPPER_FOR_struct_dquot_operations
TYPE_WRAPPER(struct dquot_operations, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.write_dquot);
        WRAP_FUNCTION(arg.write_dquot);
        WRAP_FUNCTION(arg.alloc_dquot);
        WRAP_FUNCTION(arg.destroy_dquot);
        WRAP_FUNCTION(arg.acquire_dquot);
        WRAP_FUNCTION(arg.release_dquot);
        WRAP_FUNCTION(arg.mark_dirty);
        WRAP_FUNCTION(arg.write_info);
        WRAP_FUNCTION(arg.get_reserved_space);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_quotactl_ops
#ifndef WRAPPER_FOR_struct_quotactl_ops
#define WRAPPER_FOR_struct_quotactl_ops
TYPE_WRAPPER(struct quotactl_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.quota_on);
        WRAP_FUNCTION(arg.quota_on);
        WRAP_FUNCTION(arg.quota_on_meta);
        WRAP_FUNCTION(arg.quota_off);
        WRAP_FUNCTION(arg.quota_sync);
        WRAP_FUNCTION(arg.get_info);
        WRAP_FUNCTION(arg.set_info);
        WRAP_FUNCTION(arg.get_dqblk);
        WRAP_FUNCTION(arg.set_dqblk);
        WRAP_FUNCTION(arg.get_xstate);
        WRAP_FUNCTION(arg.set_xstate);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_export_operations
#ifndef WRAPPER_FOR_struct_export_operations
#define WRAPPER_FOR_struct_export_operations
TYPE_WRAPPER(struct export_operations, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.encode_fh);
        WRAP_FUNCTION(arg.encode_fh);
        WRAP_FUNCTION(arg.fh_to_dentry);
        WRAP_FUNCTION(arg.fh_to_parent);
        WRAP_FUNCTION(arg.get_name);
        WRAP_FUNCTION(arg.get_parent);
        WRAP_FUNCTION(arg.commit_metadata);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_xattr_handler
#ifndef WRAPPER_FOR_struct_xattr_handler
#define WRAPPER_FOR_struct_xattr_handler
TYPE_WRAPPER(struct xattr_handler, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.list);
        WRAP_FUNCTION(arg.list);
        WRAP_FUNCTION(arg.get);
        WRAP_FUNCTION(arg.set);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_quota_format_ops
#ifndef WRAPPER_FOR_struct_quota_format_ops
#define WRAPPER_FOR_struct_quota_format_ops
TYPE_WRAPPER(struct quota_format_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.check_quota_file);
        WRAP_FUNCTION(arg.check_quota_file);
        WRAP_FUNCTION(arg.read_file_info);
        WRAP_FUNCTION(arg.write_file_info);
        WRAP_FUNCTION(arg.free_file_info);
        WRAP_FUNCTION(arg.read_dqblk);
        WRAP_FUNCTION(arg.commit_dqblk);
        WRAP_FUNCTION(arg.release_dqblk);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_quota_format_type
#ifndef WRAPPER_FOR_struct_quota_format_type
#define WRAPPER_FOR_struct_quota_format_type
TYPE_WRAPPER(struct quota_format_type, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.qf_owner);
        WRAP_RECURSIVE(arg.qf_next);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_mem_dqinfo
#ifndef WRAPPER_FOR_struct_mem_dqinfo
#define WRAPPER_FOR_struct_mem_dqinfo
TYPE_WRAPPER(struct mem_dqinfo, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dqi_format);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_quota_info
#ifndef WRAPPER_FOR_struct_quota_info
#define WRAPPER_FOR_struct_quota_info
TYPE_WRAPPER(struct quota_info, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dqio_mutex);
        WRAP_RECURSIVE(arg.dqonoff_mutex);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dentry_operations
#ifndef WRAPPER_FOR_struct_dentry_operations
#define WRAPPER_FOR_struct_dentry_operations
TYPE_WRAPPER(struct dentry_operations, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.d_revalidate);
        WRAP_FUNCTION(arg.d_revalidate);
        WRAP_FUNCTION(arg.d_hash);
        WRAP_FUNCTION(arg.d_compare);
        WRAP_FUNCTION(arg.d_delete);
        WRAP_FUNCTION(arg.d_release);
        WRAP_FUNCTION(arg.d_prune);
        WRAP_FUNCTION(arg.d_iput);
        WRAP_FUNCTION(arg.d_dname);
        WRAP_FUNCTION(arg.d_automount);
        WRAP_FUNCTION(arg.d_manage);
    }
    NO_POST //check this for wrapper
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_shrinker
#ifndef WRAPPER_FOR_struct_shrinker
#define WRAPPER_FOR_struct_shrinker
TYPE_WRAPPER(struct shrinker, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.shrink);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_super_block
#ifndef WRAPPER_FOR_struct_super_block
#define WRAPPER_FOR_struct_super_block
TYPE_WRAPPER(struct super_block, {
    PRE_WRAP {
        ADD_TO_HASH(&arg, SCAN_HEAD_FUNC(struct super_block));
        WRAP_RECURSIVE(arg.s_type);
        WRAP_RECURSIVE(arg.s_root);
        WRAP_RECURSIVE(arg.s_bdev);
        WRAP_RECURSIVE(arg.s_bdi);
        WRAP_RECURSIVE(arg.s_dquot);
        WRAP_RECURSIVE(arg.s_vfs_rename_mutex);
        WRAP_RECURSIVE(arg.s_shrink);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_inode
#ifndef WRAPPER_FOR_struct_inode
#define WRAPPER_FOR_struct_inode
TYPE_WRAPPER(struct inode, {
    PRE_WRAP {
        ADD_TO_HASH( &arg, SCAN_HEAD_FUNC(struct inode));
        WRAP_RECURSIVE(arg.i_sb);
        WRAP_RECURSIVE(arg.i_mapping);
        WRAP_RECURSIVE(arg.i_mutex);
        WRAP_RECURSIVE(arg.i_flock);
        WRAP_RECURSIVE(arg.i_data);
    }
    NO_POST
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_dentry
#define WRAPPER_FOR_struct_dentry
TYPE_WRAPPER(struct dentry, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.d_parent);
        WRAP_RECURSIVE(arg.d_inode);
        WRAP_RECURSIVE(arg.d_sb);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_nameidata
#ifndef WRAPPER_FOR_struct_nameidata
#define WRAPPER_FOR_struct_nameidata
TYPE_WRAPPER(struct nameidata, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.path);
        WRAP_RECURSIVE(arg.root);
        WRAP_RECURSIVE(arg.inode);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_iattr
#ifndef WRAPPER_FOR_struct_iattr
#define WRAPPER_FOR_struct_iattr
TYPE_WRAPPER(struct iattr, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.ia_file);
    }
    NO_RETURN
})
#endif


//#define WRAPPER_FOR_struct_inode_operations
#ifndef WRAPPER_FOR_struct_inode_operations
#define WRAPPER_FOR_struct_inode_operations
TYPE_WRAPPER(struct inode_operations, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.lookup);
        WRAP_FUNCTION(arg.lookup);
        WRAP_FUNCTION(arg.follow_link);
        WRAP_FUNCTION(arg.permission);
        WRAP_FUNCTION(arg.get_acl);
        WRAP_FUNCTION(arg.readlink);
        WRAP_FUNCTION(arg.put_link);
        WRAP_FUNCTION(arg.create);
        WRAP_FUNCTION(arg.link);
        WRAP_FUNCTION(arg.unlink);
        WRAP_FUNCTION(arg.symlink);
        WRAP_FUNCTION(arg.mkdir);
        WRAP_FUNCTION(arg.rmdir);
        WRAP_FUNCTION(arg.mknod);
        WRAP_FUNCTION(arg.rename);
        WRAP_FUNCTION(arg.setattr);
        WRAP_FUNCTION(arg.getattr);
        WRAP_FUNCTION(arg.setxattr);
        WRAP_FUNCTION(arg.getxattr);
        WRAP_FUNCTION(arg.listxattr);
        WRAP_FUNCTION(arg.removexattr);
        WRAP_FUNCTION(arg.fiemap);
        WRAP_FUNCTION(arg.update_time);
        WRAP_FUNCTION(arg.atomic_open);
    }
    NO_POST  //check this for automatice wrapper
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_proc_dir_entry
#ifndef WRAPPER_FOR_struct_proc_dir_entry
#define WRAPPER_FOR_struct_proc_dir_entry
TYPE_WRAPPER(struct proc_dir_entry, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.read_proc);
        WRAP_RECURSIVE(arg.next);
        WRAP_FUNCTION(arg.read_proc);
        WRAP_FUNCTION(arg.write_proc);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ctl_table
#ifndef WRAPPER_FOR_struct_ctl_table
#define WRAPPER_FOR_struct_ctl_table
TYPE_WRAPPER(struct ctl_table, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.proc_handler);
        WRAP_RECURSIVE(arg.child);
        WRAP_FUNCTION(arg.proc_handler);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ctl_table_root
#ifndef WRAPPER_FOR_struct_ctl_table_root
#define WRAPPER_FOR_struct_ctl_table_root
TYPE_WRAPPER(struct ctl_table_root, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.lookup);
        WRAP_RECURSIVE(arg.default_set);
        WRAP_FUNCTION(arg.lookup);
        WRAP_FUNCTION(arg.permissions);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ctl_node
#ifndef WRAPPER_FOR_struct_ctl_node
#define WRAPPER_FOR_struct_ctl_node
TYPE_WRAPPER(struct ctl_node, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.header);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ctl_table_header
#ifndef WRAPPER_FOR_struct_ctl_table_header
#define WRAPPER_FOR_struct_ctl_table_header
TYPE_WRAPPER(struct ctl_table_header, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.ctl_table_arg);
        WRAP_RECURSIVE(arg.root);
        WRAP_RECURSIVE(arg.set);
        WRAP_RECURSIVE(arg.parent);
        WRAP_RECURSIVE(arg.node);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ctl_dir
#ifndef WRAPPER_FOR_struct_ctl_dir
#define WRAPPER_FOR_struct_ctl_dir
TYPE_WRAPPER(struct ctl_dir, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.header);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ctl_table_set
#ifndef WRAPPER_FOR_struct_ctl_table_set
#define WRAPPER_FOR_struct_ctl_table_set
TYPE_WRAPPER(struct ctl_table_set, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.is_seen);
        WRAP_FUNCTION(arg.is_seen);
        WRAP_RECURSIVE(arg.dir);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netns_core
#ifndef WRAPPER_FOR_struct_netns_core
#define WRAPPER_FOR_struct_netns_core
TYPE_WRAPPER(struct netns_core, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.sysctl_hdr);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netns_mib
#ifndef WRAPPER_FOR_struct_netns_mib
#define WRAPPER_FOR_struct_netns_mib
TYPE_WRAPPER(struct netns_mib, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.proc_net_devsnmp6);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netns_packet
#ifndef WRAPPER_FOR_struct_netns_packet
#define WRAPPER_FOR_struct_netns_packet
TYPE_WRAPPER(struct netns_packet, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.sklist_lock);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netns_unix
#ifndef WRAPPER_FOR_struct_netns_unix
#define WRAPPER_FOR_struct_netns_unix
TYPE_WRAPPER(struct netns_unix, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.ctl);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netns_ipv4
#ifndef WRAPPER_FOR_struct_netns_ipv4
#define WRAPPER_FOR_struct_netns_ipv4
TYPE_WRAPPER(struct netns_ipv4, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.forw_hdr);
        WRAP_RECURSIVE(arg.frags_hdr);
        WRAP_RECURSIVE(arg.ipv4_hdr);
        WRAP_RECURSIVE(arg.route_hdr);
        WRAP_RECURSIVE(arg.fibnl);
        WRAP_RECURSIVE(arg.icmp_sk);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netns_sysctl_ipv6
#ifndef WRAPPER_FOR_struct_netns_sysctl_ipv6
#define WRAPPER_FOR_struct_netns_sysctl_ipv6
TYPE_WRAPPER(struct netns_sysctl_ipv6, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.hdr);
        WRAP_RECURSIVE(arg.route_hdr);
        WRAP_RECURSIVE(arg.icmp_hdr);
        WRAP_RECURSIVE(arg.frags_hdr);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dst_entry
#ifndef WRAPPER_FOR_struct_dst_entry
#define WRAPPER_FOR_struct_dst_entry
TYPE_WRAPPER(struct dst_entry, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.input);
        WRAP_RECURSIVE(arg.callback_head);
        WRAP_RECURSIVE(arg.child);
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.ops);
        WRAP_RECURSIVE(arg.path);
        WRAP_RECURSIVE(arg.from);
        WRAP_FUNCTION(arg.input);
        WRAP_FUNCTION(arg.output);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pneigh_entry
#ifndef WRAPPER_FOR_struct_pneigh_entry
#define WRAPPER_FOR_struct_pneigh_entry
TYPE_WRAPPER(struct pneigh_entry, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.next);
        WRAP_RECURSIVE(arg.net);
        WRAP_RECURSIVE(arg.dev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_neigh_hash_table
#ifndef WRAPPER_FOR_struct_neigh_hash_table
#define WRAPPER_FOR_struct_neigh_hash_table
TYPE_WRAPPER(struct neigh_hash_table, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.hash_buckets);
        WRAP_RECURSIVE(arg.rcu);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_neigh_table
#ifndef WRAPPER_FOR_struct_neigh_table
#define WRAPPER_FOR_struct_neigh_table
TYPE_WRAPPER(struct neigh_table, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.hash);
        WRAP_RECURSIVE(arg.next);
        WRAP_FUNCTION(arg.hash);
        WRAP_FUNCTION(arg.constructor);
        WRAP_FUNCTION(arg.pconstructor);
        WRAP_FUNCTION(arg.pdestructor);
        WRAP_FUNCTION(arg.proxy_redo);
        WRAP_RECURSIVE(arg.parms);
        WRAP_RECURSIVE(arg.gc_work);
        WRAP_RECURSIVE(arg.proxy_timer);
        WRAP_RECURSIVE(arg.proxy_queue);
        WRAP_RECURSIVE(arg.nht);
        WRAP_RECURSIVE(arg.phash_buckets);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_neigh_ops
#ifndef WRAPPER_FOR_struct_neigh_ops
#define WRAPPER_FOR_struct_neigh_ops
TYPE_WRAPPER(struct neigh_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.solicit);
        WRAP_FUNCTION(arg.solicit);
        WRAP_FUNCTION(arg.error_report);
        WRAP_FUNCTION(arg.output);
        WRAP_FUNCTION(arg.connected_output);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_neighbour
#ifndef WRAPPER_FOR_struct_neighbour
#define WRAPPER_FOR_struct_neighbour
TYPE_WRAPPER(struct neighbour, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.output);
        WRAP_RECURSIVE(arg.next);
        WRAP_RECURSIVE(arg.tbl);
        WRAP_RECURSIVE(arg.parms);
        WRAP_RECURSIVE(arg.arp_queue);
        WRAP_RECURSIVE(arg.timer);
        WRAP_FUNCTION(arg.output);
        WRAP_RECURSIVE(arg.rcu);
        WRAP_RECURSIVE(arg.dev);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dst_ops
#ifndef WRAPPER_FOR_struct_dst_ops
#define WRAPPER_FOR_struct_dst_ops
TYPE_WRAPPER(struct dst_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.gc);
        WRAP_FUNCTION(arg.gc);
        WRAP_FUNCTION(arg.check);
        WRAP_FUNCTION(arg.default_advmss);
        WRAP_FUNCTION(arg.mtu);
        WRAP_FUNCTION(arg.cow_metrics);
        WRAP_FUNCTION(arg.destroy);
        WRAP_FUNCTION(arg.ifdown);
        WRAP_FUNCTION(arg.negative_advice);
        WRAP_FUNCTION(arg.link_failure);
        WRAP_FUNCTION(arg.update_pmtu);
        WRAP_FUNCTION(arg.redirect);
        WRAP_FUNCTION(arg.local_out);
        WRAP_FUNCTION(arg.neigh_lookup);
        WRAP_RECURSIVE(arg.kmem_cachep);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netns_ipv6
#ifndef WRAPPER_FOR_struct_netns_ipv6
#define WRAPPER_FOR_struct_netns_ipv6
TYPE_WRAPPER(struct netns_ipv6, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.sysctl);
        WRAP_RECURSIVE(arg.ip6_fib_timer);
        WRAP_RECURSIVE(arg.ip6_dst_ops);
        WRAP_RECURSIVE(arg.icmp_sk);
        WRAP_RECURSIVE(arg.ndisc_sk);
        WRAP_RECURSIVE(arg.tcp_sk);
        WRAP_RECURSIVE(arg.igmp_sk);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netns_sctp
#ifndef WRAPPER_FOR_struct_netns_sctp
#define WRAPPER_FOR_struct_netns_sctp
TYPE_WRAPPER(struct netns_sctp, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.proc_net_sctp);
        WRAP_RECURSIVE(arg.sysctl_header);
        WRAP_RECURSIVE(arg.ctl_sock);
        WRAP_RECURSIVE(arg.addr_wq_timer);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netns_dccp
#ifndef WRAPPER_FOR_struct_netns_dccp
#define WRAPPER_FOR_struct_netns_dccp
TYPE_WRAPPER(struct netns_dccp, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.v4_ctl_sk);
        WRAP_RECURSIVE(arg.v6_ctl_sk);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_nf_proto_net
#ifndef WRAPPER_FOR_struct_nf_proto_net
#define WRAPPER_FOR_struct_nf_proto_net
TYPE_WRAPPER(struct nf_proto_net, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.ctl_table_header);
        WRAP_RECURSIVE(arg.ctl_table);
        WRAP_RECURSIVE(arg.ctl_compat_header);
        WRAP_RECURSIVE(arg.ctl_compat_table);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_nf_generic_net
#ifndef WRAPPER_FOR_struct_nf_generic_net
#define WRAPPER_FOR_struct_nf_generic_net
TYPE_WRAPPER(struct nf_generic_net, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.pn);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_nf_tcp_net
#ifndef WRAPPER_FOR_struct_nf_tcp_net
#define WRAPPER_FOR_struct_nf_tcp_net
TYPE_WRAPPER(struct nf_tcp_net, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.pn);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_nf_udp_net
#ifndef WRAPPER_FOR_struct_nf_udp_net
#define WRAPPER_FOR_struct_nf_udp_net
TYPE_WRAPPER(struct nf_udp_net, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.pn);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_nf_icmp_net
#ifndef WRAPPER_FOR_struct_nf_icmp_net
#define WRAPPER_FOR_struct_nf_icmp_net
TYPE_WRAPPER(struct nf_icmp_net, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.pn);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_nf_ip_net
#ifndef WRAPPER_FOR_struct_nf_ip_net
#define WRAPPER_FOR_struct_nf_ip_net
TYPE_WRAPPER(struct nf_ip_net, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.generic);
        WRAP_RECURSIVE(arg.tcp);
        WRAP_RECURSIVE(arg.udp);
        WRAP_RECURSIVE(arg.icmp);
        WRAP_RECURSIVE(arg.icmpv6);
        WRAP_RECURSIVE(arg.ctl_table_header);
        WRAP_RECURSIVE(arg.ctl_table);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netns_ct
#ifndef WRAPPER_FOR_struct_netns_ct
#define WRAPPER_FOR_struct_netns_ct
TYPE_WRAPPER(struct netns_ct, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.nf_conntrack_cachep);
        WRAP_RECURSIVE(arg.nf_ct_proto);
        WRAP_RECURSIVE(arg.sysctl_header);
        WRAP_RECURSIVE(arg.acct_sysctl_header);
        WRAP_RECURSIVE(arg.tstamp_sysctl_header);
        WRAP_RECURSIVE(arg.event_sysctl_header);
        WRAP_RECURSIVE(arg.helper_sysctl_header);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netns_nf_frag
#ifndef WRAPPER_FOR_struct_netns_nf_frag
#define WRAPPER_FOR_struct_netns_nf_frag
TYPE_WRAPPER(struct netns_nf_frag, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.sysctl);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netns_xfrm
#ifndef WRAPPER_FOR_struct_netns_xfrm
#define WRAPPER_FOR_struct_netns_xfrm
TYPE_WRAPPER(struct netns_xfrm, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.state_hash_work);
        WRAP_RECURSIVE(arg.state_gc_work);
        WRAP_RECURSIVE(arg.policy_hash_work);
        WRAP_RECURSIVE(arg.nlsk);
        WRAP_RECURSIVE(arg.nlsk_stash);
        WRAP_RECURSIVE(arg.sysctl_hdr);
        WRAP_RECURSIVE(arg.xfrm4_dst_ops);
        WRAP_RECURSIVE(arg.xfrm6_dst_ops);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_net
#ifndef WRAPPER_FOR_struct_net
#define WRAPPER_FOR_struct_net
TYPE_WRAPPER(struct net, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.proc_net);
        WRAP_RECURSIVE(arg.proc_net_stat);
        WRAP_RECURSIVE(arg.sysctls);
        WRAP_RECURSIVE(arg.rtnl);
        WRAP_RECURSIVE(arg.genl_sock);
        WRAP_RECURSIVE(arg.loopback_dev);
        WRAP_RECURSIVE(arg.core);
        WRAP_RECURSIVE(arg.mib);
        WRAP_RECURSIVE(arg.packet);
        WRAP_RECURSIVE(arg.unx);
        WRAP_RECURSIVE(arg.ipv4);
        WRAP_RECURSIVE(arg.ipv6);
        WRAP_RECURSIVE(arg.sctp);
        WRAP_RECURSIVE(arg.dccp);
        WRAP_RECURSIVE(arg.ct);
        WRAP_RECURSIVE(arg.nf_frag);
        WRAP_RECURSIVE(arg.nfnl);
        WRAP_RECURSIVE(arg.nfnl_stash);
        WRAP_RECURSIVE(arg.wext_nlevents);
        WRAP_RECURSIVE(arg.xfrm);
        WRAP_RECURSIVE(arg.diag_nlsk);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_neigh_parms
#ifndef WRAPPER_FOR_struct_neigh_parms
#define WRAPPER_FOR_struct_neigh_parms
TYPE_WRAPPER(struct neigh_parms, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.neigh_setup);
        WRAP_RECURSIVE(arg.net);
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.next);
        WRAP_FUNCTION(arg.neigh_setup);
        WRAP_FUNCTION(arg.neigh_cleanup);
        WRAP_RECURSIVE(arg.tbl);
        WRAP_RECURSIVE(arg.callback_head);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netlink_callback
#ifndef WRAPPER_FOR_struct_netlink_callback
#define WRAPPER_FOR_struct_netlink_callback
TYPE_WRAPPER(struct netlink_callback, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.dump);
        WRAP_RECURSIVE(arg.skb);
        WRAP_FUNCTION(arg.dump);
        WRAP_FUNCTION(arg.done);
        WRAP_RECURSIVE(arg.module);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_net_device_ops
#ifndef WRAPPER_FOR_struct_net_device_ops
#define WRAPPER_FOR_struct_net_device_ops
TYPE_WRAPPER(struct net_device_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.ndo_init);
        WRAP_FUNCTION(arg.ndo_init);
        WRAP_FUNCTION(arg.ndo_uninit);
        WRAP_FUNCTION(arg.ndo_open);
        WRAP_FUNCTION(arg.ndo_stop);
        WRAP_FUNCTION(arg.ndo_start_xmit);
        WRAP_FUNCTION(arg.ndo_select_queue);
        WRAP_FUNCTION(arg.ndo_change_rx_flags);
        WRAP_FUNCTION(arg.ndo_set_rx_mode);
        WRAP_FUNCTION(arg.ndo_set_mac_address);
        WRAP_FUNCTION(arg.ndo_validate_addr);
        WRAP_FUNCTION(arg.ndo_do_ioctl);
        WRAP_FUNCTION(arg.ndo_set_config);
        WRAP_FUNCTION(arg.ndo_change_mtu);
        WRAP_FUNCTION(arg.ndo_neigh_setup);
        WRAP_FUNCTION(arg.ndo_tx_timeout);
        WRAP_FUNCTION(arg.ndo_get_stats64);
        WRAP_FUNCTION(arg.ndo_get_stats);
        WRAP_FUNCTION(arg.ndo_vlan_rx_add_vid);
        WRAP_FUNCTION(arg.ndo_vlan_rx_kill_vid);
        WRAP_FUNCTION(arg.ndo_poll_controller);
        WRAP_FUNCTION(arg.ndo_netpoll_setup);
        WRAP_FUNCTION(arg.ndo_netpoll_cleanup);
        WRAP_FUNCTION(arg.ndo_set_vf_mac);
        WRAP_FUNCTION(arg.ndo_set_vf_vlan);
        WRAP_FUNCTION(arg.ndo_set_vf_tx_rate);
        WRAP_FUNCTION(arg.ndo_set_vf_spoofchk);
        WRAP_FUNCTION(arg.ndo_get_vf_config);
        WRAP_FUNCTION(arg.ndo_set_vf_port);
        WRAP_FUNCTION(arg.ndo_get_vf_port);
        WRAP_FUNCTION(arg.ndo_setup_tc);
        WRAP_FUNCTION(arg.ndo_fcoe_enable);
        WRAP_FUNCTION(arg.ndo_fcoe_disable);
        WRAP_FUNCTION(arg.ndo_fcoe_ddp_setup);
        WRAP_FUNCTION(arg.ndo_fcoe_ddp_done);
        WRAP_FUNCTION(arg.ndo_fcoe_ddp_target);
        WRAP_FUNCTION(arg.ndo_fcoe_get_hbainfo);
        WRAP_FUNCTION(arg.ndo_fcoe_get_wwn);
        WRAP_FUNCTION(arg.ndo_rx_flow_steer);
        WRAP_FUNCTION(arg.ndo_add_slave);
        WRAP_FUNCTION(arg.ndo_del_slave);
        WRAP_FUNCTION(arg.ndo_fix_features);
        WRAP_FUNCTION(arg.ndo_set_features);
        WRAP_FUNCTION(arg.ndo_neigh_construct);
        WRAP_FUNCTION(arg.ndo_neigh_destroy);
        WRAP_FUNCTION(arg.ndo_fdb_add);
        WRAP_FUNCTION(arg.ndo_fdb_del);
        WRAP_FUNCTION(arg.ndo_fdb_dump);
        WRAP_FUNCTION(arg.ndo_bridge_setlink);
        WRAP_FUNCTION(arg.ndo_bridge_getlink);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ethtool_ops
#ifndef WRAPPER_FOR_struct_ethtool_ops
#define WRAPPER_FOR_struct_ethtool_ops
TYPE_WRAPPER(struct ethtool_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.get_settings);
        WRAP_FUNCTION(arg.get_settings);
        WRAP_FUNCTION(arg.set_settings);
        WRAP_FUNCTION(arg.get_drvinfo);
        WRAP_FUNCTION(arg.get_regs_len);
        WRAP_FUNCTION(arg.get_regs);
        WRAP_FUNCTION(arg.get_wol);
        WRAP_FUNCTION(arg.set_wol);
        WRAP_FUNCTION(arg.get_msglevel);
        WRAP_FUNCTION(arg.set_msglevel);
        WRAP_FUNCTION(arg.nway_reset);
        WRAP_FUNCTION(arg.get_link);
        WRAP_FUNCTION(arg.get_eeprom_len);
        WRAP_FUNCTION(arg.get_eeprom);
        WRAP_FUNCTION(arg.set_eeprom);
        WRAP_FUNCTION(arg.get_coalesce);
        WRAP_FUNCTION(arg.set_coalesce);
        WRAP_FUNCTION(arg.get_ringparam);
        WRAP_FUNCTION(arg.set_ringparam);
        WRAP_FUNCTION(arg.get_pauseparam);
        WRAP_FUNCTION(arg.set_pauseparam);
        WRAP_FUNCTION(arg.self_test);
        WRAP_FUNCTION(arg.get_strings);
        WRAP_FUNCTION(arg.set_phys_id);
        WRAP_FUNCTION(arg.get_ethtool_stats);
        WRAP_FUNCTION(arg.begin);
        WRAP_FUNCTION(arg.complete);
        WRAP_FUNCTION(arg.get_priv_flags);
        WRAP_FUNCTION(arg.set_priv_flags);
        WRAP_FUNCTION(arg.get_sset_count);
        WRAP_FUNCTION(arg.get_rxnfc);
        WRAP_FUNCTION(arg.set_rxnfc);
        WRAP_FUNCTION(arg.flash_device);
        WRAP_FUNCTION(arg.reset);
        WRAP_FUNCTION(arg.get_rxfh_indir_size);
        WRAP_FUNCTION(arg.get_rxfh_indir);
        WRAP_FUNCTION(arg.set_rxfh_indir);
        WRAP_FUNCTION(arg.get_channels);
        WRAP_FUNCTION(arg.set_channels);
        WRAP_FUNCTION(arg.get_dump_flag);
        WRAP_FUNCTION(arg.get_dump_data);
        WRAP_FUNCTION(arg.set_dump);
        WRAP_FUNCTION(arg.get_ts_info);
        WRAP_FUNCTION(arg.get_module_info);
        WRAP_FUNCTION(arg.get_module_eeprom);
        WRAP_FUNCTION(arg.get_eee);
        WRAP_FUNCTION(arg.set_eee);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_header_ops
#ifndef WRAPPER_FOR_struct_header_ops
#define WRAPPER_FOR_struct_header_ops
TYPE_WRAPPER(struct header_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.create);
        WRAP_FUNCTION(arg.create);
        WRAP_FUNCTION(arg.parse);
        WRAP_FUNCTION(arg.rebuild);
        WRAP_FUNCTION(arg.cache);
        WRAP_FUNCTION(arg.cache_update);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dsa_chip_data
#ifndef WRAPPER_FOR_struct_dsa_chip_data
#define WRAPPER_FOR_struct_dsa_chip_data
TYPE_WRAPPER(struct dsa_chip_data, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.mii_bus);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dsa_platform_data
#ifndef WRAPPER_FOR_struct_dsa_platform_data
#define WRAPPER_FOR_struct_dsa_platform_data
TYPE_WRAPPER(struct dsa_platform_data, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.netdev);
        WRAP_RECURSIVE(arg.chip);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_phy_driver
#ifndef WRAPPER_FOR_struct_phy_driver
#define WRAPPER_FOR_struct_phy_driver
TYPE_WRAPPER(struct phy_driver, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.config_init);
        WRAP_FUNCTION(arg.config_init);
        WRAP_FUNCTION(arg.probe);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.resume);
        WRAP_FUNCTION(arg.config_aneg);
        WRAP_FUNCTION(arg.read_status);
        WRAP_FUNCTION(arg.ack_interrupt);
        WRAP_FUNCTION(arg.config_intr);
        WRAP_FUNCTION(arg.did_interrupt);
        WRAP_FUNCTION(arg.remove);
        WRAP_FUNCTION(arg.match_phy_device);
        WRAP_FUNCTION(arg.ts_info);
        WRAP_FUNCTION(arg.hwtstamp);
        WRAP_FUNCTION(arg.rxtstamp);
        WRAP_FUNCTION(arg.txtstamp);
        WRAP_RECURSIVE(arg.driver);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_phy_device
#ifndef WRAPPER_FOR_struct_phy_device
#define WRAPPER_FOR_struct_phy_device
TYPE_WRAPPER(struct phy_device, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.adjust_link);
        WRAP_RECURSIVE(arg.drv);
        WRAP_RECURSIVE(arg.bus);
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.phy_queue);
        WRAP_RECURSIVE(arg.state_queue);
        WRAP_RECURSIVE(arg.lock);
        WRAP_RECURSIVE(arg.attached_dev);
        WRAP_FUNCTION(arg.adjust_link);
        WRAP_FUNCTION(arg.adjust_state);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_mii_bus
#ifndef WRAPPER_FOR_struct_mii_bus
#define WRAPPER_FOR_struct_mii_bus
TYPE_WRAPPER(struct mii_bus, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.read);
        WRAP_FUNCTION(arg.read);
        WRAP_FUNCTION(arg.write);
        WRAP_FUNCTION(arg.reset);
        WRAP_RECURSIVE(arg.mdio_lock);
        WRAP_RECURSIVE(arg.parent);
        WRAP_RECURSIVE(arg.dev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dsa_switch_driver
#ifndef WRAPPER_FOR_struct_dsa_switch_driver
#define WRAPPER_FOR_struct_dsa_switch_driver
TYPE_WRAPPER(struct dsa_switch_driver, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.probe);
        WRAP_FUNCTION(arg.probe);
        WRAP_FUNCTION(arg.setup);
        WRAP_FUNCTION(arg.set_addr);
        WRAP_FUNCTION(arg.phy_read);
        WRAP_FUNCTION(arg.phy_write);
        WRAP_FUNCTION(arg.poll_link);
        WRAP_FUNCTION(arg.get_strings);
        WRAP_FUNCTION(arg.get_ethtool_stats);
        WRAP_FUNCTION(arg.get_sset_count);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dsa_switch
#ifndef WRAPPER_FOR_struct_dsa_switch
#define WRAPPER_FOR_struct_dsa_switch
TYPE_WRAPPER(struct dsa_switch, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dst);
        WRAP_RECURSIVE(arg.pd);
        WRAP_RECURSIVE(arg.drv);
        WRAP_RECURSIVE(arg.master_mii_bus);
        WRAP_RECURSIVE(arg.slave_mii_bus);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dsa_switch_tree
#ifndef WRAPPER_FOR_struct_dsa_switch_tree
#define WRAPPER_FOR_struct_dsa_switch_tree
TYPE_WRAPPER(struct dsa_switch_tree, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.pd);
        WRAP_RECURSIVE(arg.master_netdev);
        WRAP_RECURSIVE(arg.link_poll_work);
        WRAP_RECURSIVE(arg.link_poll_timer);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_rps_map
#ifndef WRAPPER_FOR_struct_rps_map
#define WRAPPER_FOR_struct_rps_map
TYPE_WRAPPER(struct rps_map, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.rcu);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_rps_dev_flow_table
#ifndef WRAPPER_FOR_struct_rps_dev_flow_table
#define WRAPPER_FOR_struct_rps_dev_flow_table
TYPE_WRAPPER(struct rps_dev_flow_table, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.rcu);
        WRAP_RECURSIVE(arg.free_work);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netdev_rx_queue
#ifndef WRAPPER_FOR_struct_netdev_rx_queue
#define WRAPPER_FOR_struct_netdev_rx_queue
TYPE_WRAPPER(struct netdev_rx_queue, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.rps_map);
        WRAP_RECURSIVE(arg.rps_flow_table);
        WRAP_RECURSIVE(arg.kobj);
        WRAP_RECURSIVE(arg.dev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_qdisc_walker
#ifndef WRAPPER_FOR_struct_qdisc_walker
#define WRAPPER_FOR_struct_qdisc_walker
TYPE_WRAPPER(struct qdisc_walker, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.fn);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_tcf_proto_ops
#ifndef WRAPPER_FOR_struct_tcf_proto_ops
#define WRAPPER_FOR_struct_tcf_proto_ops
TYPE_WRAPPER(struct tcf_proto_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.classify);
        WRAP_RECURSIVE(arg.next);
        WRAP_FUNCTION(arg.classify);
        WRAP_FUNCTION(arg.init);
        WRAP_FUNCTION(arg.destroy);
        WRAP_FUNCTION(arg.get);
        WRAP_FUNCTION(arg.put);
        WRAP_FUNCTION(arg.change);
        WRAP_FUNCTION(arg.delete_);
        WRAP_FUNCTION(arg.walk);
        WRAP_FUNCTION(arg.dump);
        WRAP_RECURSIVE(arg.owner);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_tcf_proto
#ifndef WRAPPER_FOR_struct_tcf_proto
#define WRAPPER_FOR_struct_tcf_proto
TYPE_WRAPPER(struct tcf_proto, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.classify);
        WRAP_RECURSIVE(arg.next);
        WRAP_FUNCTION(arg.classify);
        WRAP_RECURSIVE(arg.q);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_gnet_dump
#ifndef WRAPPER_FOR_struct_gnet_dump
#define WRAPPER_FOR_struct_gnet_dump
TYPE_WRAPPER(struct gnet_dump, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.skb);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_Qdisc_class_ops
#ifndef WRAPPER_FOR_struct_Qdisc_class_ops
#define WRAPPER_FOR_struct_Qdisc_class_ops
TYPE_WRAPPER(struct Qdisc_class_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.select_queue);
        WRAP_FUNCTION(arg.select_queue);
        WRAP_FUNCTION(arg.graft);
        WRAP_FUNCTION(arg.leaf);
        WRAP_FUNCTION(arg.qlen_notify);
        WRAP_FUNCTION(arg.get);
        WRAP_FUNCTION(arg.put);
        WRAP_FUNCTION(arg.change);
        WRAP_FUNCTION(arg.delete_);
        WRAP_FUNCTION(arg.walk);
        WRAP_FUNCTION(arg.tcf_chain);
        WRAP_FUNCTION(arg.bind_tcf);
        WRAP_FUNCTION(arg.unbind_tcf);
        WRAP_FUNCTION(arg.dump);
        WRAP_FUNCTION(arg.dump_stats);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_Qdisc_ops
#ifndef WRAPPER_FOR_struct_Qdisc_ops
#define WRAPPER_FOR_struct_Qdisc_ops
TYPE_WRAPPER(struct Qdisc_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.enqueue);
        WRAP_RECURSIVE(arg.next);
        WRAP_FUNCTION(arg.enqueue);
        WRAP_FUNCTION(arg.dequeue);
        WRAP_FUNCTION(arg.peek);
        WRAP_FUNCTION(arg.drop);
        WRAP_FUNCTION(arg.init);
        WRAP_FUNCTION(arg.reset);
        WRAP_FUNCTION(arg.destroy);
        WRAP_FUNCTION(arg.change);
        WRAP_FUNCTION(arg.attach);
        WRAP_FUNCTION(arg.dump);
        WRAP_FUNCTION(arg.dump_stats);
        WRAP_RECURSIVE(arg.owner);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_qdisc_size_table
#ifndef WRAPPER_FOR_struct_qdisc_size_table
#define WRAPPER_FOR_struct_qdisc_size_table
TYPE_WRAPPER(struct qdisc_size_table, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.rcu);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_Qdisc
#ifndef WRAPPER_FOR_struct_Qdisc
#define WRAPPER_FOR_struct_Qdisc
TYPE_WRAPPER(struct Qdisc, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.enqueue);
        WRAP_FUNCTION(arg.enqueue);
        WRAP_FUNCTION(arg.dequeue);
        WRAP_RECURSIVE(arg.stab);
        WRAP_FUNCTION(arg.reshape_fail);
        WRAP_RECURSIVE(arg.__parent);
        WRAP_RECURSIVE(arg.dev_queue);
        WRAP_RECURSIVE(arg.next_sched);
        WRAP_RECURSIVE(arg.gso_skb);
        WRAP_RECURSIVE(arg.q);
        WRAP_RECURSIVE(arg.callback_head);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netdev_queue
#ifndef WRAPPER_FOR_struct_netdev_queue
#define WRAPPER_FOR_struct_netdev_queue
TYPE_WRAPPER(struct netdev_queue, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.qdisc);
        WRAP_RECURSIVE(arg.qdisc_sleeping);
        WRAP_RECURSIVE(arg.kobj);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_xps_map
#ifndef WRAPPER_FOR_struct_xps_map
#define WRAPPER_FOR_struct_xps_map
TYPE_WRAPPER(struct xps_map, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.rcu);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_xps_dev_maps
#ifndef WRAPPER_FOR_struct_xps_dev_maps
#define WRAPPER_FOR_struct_xps_dev_maps
TYPE_WRAPPER(struct xps_dev_maps, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.rcu);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_rtnl_link_ops
#ifndef WRAPPER_FOR_struct_rtnl_link_ops
#define WRAPPER_FOR_struct_rtnl_link_ops
TYPE_WRAPPER(struct rtnl_link_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.setup);
        WRAP_FUNCTION(arg.setup);
        WRAP_FUNCTION(arg.validate);
        WRAP_FUNCTION(arg.newlink);
        WRAP_FUNCTION(arg.changelink);
        WRAP_FUNCTION(arg.dellink);
        WRAP_FUNCTION(arg.get_size);
        WRAP_FUNCTION(arg.fill_info);
        WRAP_FUNCTION(arg.get_xstats_size);
        WRAP_FUNCTION(arg.fill_xstats);
        WRAP_FUNCTION(arg.get_num_tx_queues);
        WRAP_FUNCTION(arg.get_num_rx_queues);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dcbnl_rtnl_ops
#ifndef WRAPPER_FOR_struct_dcbnl_rtnl_ops
#define WRAPPER_FOR_struct_dcbnl_rtnl_ops
TYPE_WRAPPER(struct dcbnl_rtnl_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.ieee_getets);
        WRAP_FUNCTION(arg.ieee_getets);
        WRAP_FUNCTION(arg.ieee_setets);
        WRAP_FUNCTION(arg.ieee_getmaxrate);
        WRAP_FUNCTION(arg.ieee_setmaxrate);
        WRAP_FUNCTION(arg.ieee_getpfc);
        WRAP_FUNCTION(arg.ieee_setpfc);
        WRAP_FUNCTION(arg.ieee_getapp);
        WRAP_FUNCTION(arg.ieee_setapp);
        WRAP_FUNCTION(arg.ieee_delapp);
        WRAP_FUNCTION(arg.ieee_peer_getets);
        WRAP_FUNCTION(arg.ieee_peer_getpfc);
        WRAP_FUNCTION(arg.getstate);
        WRAP_FUNCTION(arg.setstate);
        WRAP_FUNCTION(arg.getpermhwaddr);
        WRAP_FUNCTION(arg.setpgtccfgtx);
        WRAP_FUNCTION(arg.setpgbwgcfgtx);
        WRAP_FUNCTION(arg.setpgtccfgrx);
        WRAP_FUNCTION(arg.setpgbwgcfgrx);
        WRAP_FUNCTION(arg.getpgtccfgtx);
        WRAP_FUNCTION(arg.getpgbwgcfgtx);
        WRAP_FUNCTION(arg.getpgtccfgrx);
        WRAP_FUNCTION(arg.getpgbwgcfgrx);
        WRAP_FUNCTION(arg.setpfccfg);
        WRAP_FUNCTION(arg.getpfccfg);
        WRAP_FUNCTION(arg.setall);
        WRAP_FUNCTION(arg.getcap);
        WRAP_FUNCTION(arg.getnumtcs);
        WRAP_FUNCTION(arg.setnumtcs);
        WRAP_FUNCTION(arg.getpfcstate);
        WRAP_FUNCTION(arg.setpfcstate);
        WRAP_FUNCTION(arg.getbcncfg);
        WRAP_FUNCTION(arg.setbcncfg);
        WRAP_FUNCTION(arg.getbcnrp);
        WRAP_FUNCTION(arg.setbcnrp);
        WRAP_FUNCTION(arg.setapp);
        WRAP_FUNCTION(arg.getapp);
        WRAP_FUNCTION(arg.getfeatcfg);
        WRAP_FUNCTION(arg.setfeatcfg);
        WRAP_FUNCTION(arg.getdcbx);
        WRAP_FUNCTION(arg.setdcbx);
        WRAP_FUNCTION(arg.peer_getappinfo);
        WRAP_FUNCTION(arg.peer_getapptable);
        WRAP_FUNCTION(arg.cee_peer_getpg);
        WRAP_FUNCTION(arg.cee_peer_getpfc);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pm_qos_request
#ifndef WRAPPER_FOR_struct_pm_qos_request
#define WRAPPER_FOR_struct_pm_qos_request
TYPE_WRAPPER(struct pm_qos_request, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.work);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_net_device
#ifndef WRAPPER_FOR_struct_net_device
#define WRAPPER_FOR_struct_net_device
TYPE_WRAPPER(struct net_device, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.rx_handler);
        WRAP_RECURSIVE(arg.dsa_ptr);
        WRAP_RECURSIVE(arg.master);
        WRAP_RECURSIVE(arg.queues_kset);
        WRAP_RECURSIVE(arg._rx);
        WRAP_FUNCTION(arg.rx_handler);
        WRAP_RECURSIVE(arg.ingress_queue);
        WRAP_RECURSIVE(arg._tx);
        WRAP_RECURSIVE(arg.qdisc);
        WRAP_RECURSIVE(arg.xps_maps);
        WRAP_RECURSIVE(arg.watchdog_timer);
        WRAP_FUNCTION(arg.destructor);
        WRAP_RECURSIVE(arg.nd_net);
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.phydev);
        WRAP_RECURSIVE(arg.pm_qos_req);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_nf_bridge_info
#ifndef WRAPPER_FOR_struct_nf_bridge_info
#define WRAPPER_FOR_struct_nf_bridge_info
TYPE_WRAPPER(struct nf_bridge_info, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.physindev);
        WRAP_RECURSIVE(arg.physoutdev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_sk_buff
#ifndef WRAPPER_FOR_struct_sk_buff
#define WRAPPER_FOR_struct_sk_buff
TYPE_WRAPPER(struct sk_buff, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.destructor);
        WRAP_RECURSIVE(arg.next);
        WRAP_RECURSIVE(arg.prev);
        WRAP_RECURSIVE(arg.sk);
        WRAP_RECURSIVE(arg.dev);
        WRAP_FUNCTION(arg.destructor);
        WRAP_RECURSIVE(arg.nfct_reasm);
        WRAP_RECURSIVE(arg.nf_bridge);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_sk_buff_head
#ifndef WRAPPER_FOR_struct_sk_buff_head
#define WRAPPER_FOR_struct_sk_buff_head
TYPE_WRAPPER(struct sk_buff_head, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.next);
        WRAP_RECURSIVE(arg.prev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_sk_filter
#ifndef WRAPPER_FOR_struct_sk_filter
#define WRAPPER_FOR_struct_sk_filter
TYPE_WRAPPER(struct sk_filter, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.bpf_func);
        WRAP_FUNCTION(arg.bpf_func);
        WRAP_RECURSIVE(arg.rcu);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_socket_wq
#ifndef WRAPPER_FOR_struct_socket_wq
#define WRAPPER_FOR_struct_socket_wq
TYPE_WRAPPER(struct socket_wq, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.fasync_list);
        WRAP_RECURSIVE(arg.rcu);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_proto_ops
#ifndef WRAPPER_FOR_struct_proto_ops
#define WRAPPER_FOR_struct_proto_ops
TYPE_WRAPPER(struct proto_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.release);
        WRAP_RECURSIVE(arg.owner);
        WRAP_FUNCTION(arg.release);
        WRAP_FUNCTION(arg.bind);
        WRAP_FUNCTION(arg.connect);
        WRAP_FUNCTION(arg.socketpair);
        WRAP_FUNCTION(arg.accept);
        WRAP_FUNCTION(arg.getname);
        WRAP_FUNCTION(arg.poll);
        WRAP_FUNCTION(arg.ioctl);
        WRAP_FUNCTION(arg.compat_ioctl);
        WRAP_FUNCTION(arg.listen);
        WRAP_FUNCTION(arg.shutdown);
        WRAP_FUNCTION(arg.setsockopt);
        WRAP_FUNCTION(arg.getsockopt);
        WRAP_FUNCTION(arg.compat_setsockopt);
        WRAP_FUNCTION(arg.compat_getsockopt);
        WRAP_FUNCTION(arg.sendmsg);
        WRAP_FUNCTION(arg.recvmsg);
        WRAP_FUNCTION(arg.mmap);
        WRAP_FUNCTION(arg.sendpage);
        WRAP_FUNCTION(arg.splice_read);
        WRAP_FUNCTION(arg.set_peek_off);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_socket
#ifndef WRAPPER_FOR_struct_socket
#define WRAPPER_FOR_struct_socket
TYPE_WRAPPER(struct socket, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.wq);
        WRAP_RECURSIVE(arg.file);
        WRAP_RECURSIVE(arg.sk);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_cg_proto
#ifndef WRAPPER_FOR_struct_cg_proto
#define WRAPPER_FOR_struct_cg_proto
TYPE_WRAPPER(struct cg_proto, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.enter_memory_pressure);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_sock
#ifndef WRAPPER_FOR_struct_sock
#define WRAPPER_FOR_struct_sock
TYPE_WRAPPER(struct sock, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.sk_state_change);
        WRAP_RECURSIVE(arg.__sk_common);
        WRAP_RECURSIVE(arg.sk_receive_queue);
        WRAP_RECURSIVE(arg.sk_filter);
        WRAP_RECURSIVE(arg.sk_wq);
        WRAP_RECURSIVE(arg.sk_async_wait_queue);
        WRAP_RECURSIVE(arg.sk_rx_dst);
        WRAP_RECURSIVE(arg.sk_dst_cache);
        WRAP_RECURSIVE(arg.sk_write_queue);
        WRAP_RECURSIVE(arg.sk_error_queue);
        WRAP_RECURSIVE(arg.sk_prot_creator);
        WRAP_RECURSIVE(arg.sk_peer_pid);
        WRAP_RECURSIVE(arg.sk_timer);
        WRAP_RECURSIVE(arg.sk_socket);
        WRAP_RECURSIVE(arg.sk_frag);
        WRAP_RECURSIVE(arg.sk_send_head);
        WRAP_RECURSIVE(arg.sk_cgrp);
        WRAP_FUNCTION(arg.sk_state_change);
        WRAP_FUNCTION(arg.sk_data_ready);
        WRAP_FUNCTION(arg.sk_write_space);
        WRAP_FUNCTION(arg.sk_error_report);
        WRAP_FUNCTION(arg.sk_backlog_rcv);
        WRAP_FUNCTION(arg.sk_destruct);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_request_sock
#ifndef WRAPPER_FOR_struct_request_sock
#define WRAPPER_FOR_struct_request_sock
TYPE_WRAPPER(struct request_sock, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dl_next);
        WRAP_RECURSIVE(arg.sk);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_request_sock_ops
#ifndef WRAPPER_FOR_struct_request_sock_ops
#define WRAPPER_FOR_struct_request_sock_ops
TYPE_WRAPPER(struct request_sock_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.rtx_syn_ack);
        WRAP_RECURSIVE(arg.slab);
        WRAP_FUNCTION(arg.rtx_syn_ack);
        WRAP_FUNCTION(arg.send_ack);
        WRAP_FUNCTION(arg.send_reset);
        WRAP_FUNCTION(arg.destructor);
        WRAP_FUNCTION(arg.syn_ack_timeout);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_timewait_sock_ops
#ifndef WRAPPER_FOR_struct_timewait_sock_ops
#define WRAPPER_FOR_struct_timewait_sock_ops
TYPE_WRAPPER(struct timewait_sock_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.twsk_unique);
        WRAP_RECURSIVE(arg.twsk_slab);
        WRAP_FUNCTION(arg.twsk_unique);
        WRAP_FUNCTION(arg.twsk_destructor);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_proto
#ifndef WRAPPER_FOR_struct_proto
#define WRAPPER_FOR_struct_proto
TYPE_WRAPPER(struct proto, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.close);
        WRAP_FUNCTION(arg.close);
        WRAP_FUNCTION(arg.connect);
        WRAP_FUNCTION(arg.disconnect);
        WRAP_FUNCTION(arg.accept);
        WRAP_FUNCTION(arg.ioctl);
        WRAP_FUNCTION(arg.init);
        WRAP_FUNCTION(arg.destroy);
        WRAP_FUNCTION(arg.shutdown);
        WRAP_FUNCTION(arg.setsockopt);
        WRAP_FUNCTION(arg.getsockopt);
        WRAP_FUNCTION(arg.compat_setsockopt);
        WRAP_FUNCTION(arg.compat_getsockopt);
        WRAP_FUNCTION(arg.compat_ioctl);
        WRAP_FUNCTION(arg.sendmsg);
        WRAP_FUNCTION(arg.recvmsg);
        WRAP_FUNCTION(arg.sendpage);
        WRAP_FUNCTION(arg.bind);
        WRAP_FUNCTION(arg.backlog_rcv);
        WRAP_FUNCTION(arg.release_cb);
        WRAP_FUNCTION(arg.mtu_reduced);
        WRAP_FUNCTION(arg.hash);
        WRAP_FUNCTION(arg.unhash);
        WRAP_FUNCTION(arg.rehash);
        WRAP_FUNCTION(arg.get_port);
        WRAP_FUNCTION(arg.clear_sk);
        WRAP_FUNCTION(arg.enter_memory_pressure);
        WRAP_RECURSIVE(arg.slab);
        WRAP_RECURSIVE(arg.rsk_prot);
        WRAP_RECURSIVE(arg.twsk_prot);
        WRAP_RECURSIVE(arg.owner);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_sock_common
#ifndef WRAPPER_FOR_struct_sock_common
#define WRAPPER_FOR_struct_sock_common
TYPE_WRAPPER(struct sock_common, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.skc_prot);
        WRAP_RECURSIVE(arg.skc_net);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_inet_timewait_sock
#ifndef WRAPPER_FOR_struct_inet_timewait_sock
#define WRAPPER_FOR_struct_inet_timewait_sock
TYPE_WRAPPER(struct inet_timewait_sock, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.__tw_common);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_inet_timewait_death_row
#ifndef WRAPPER_FOR_struct_inet_timewait_death_row
#define WRAPPER_FOR_struct_inet_timewait_death_row
TYPE_WRAPPER(struct inet_timewait_death_row, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.twcal_timer);
        WRAP_RECURSIVE(arg.twkill_work);
        WRAP_RECURSIVE(arg.tw_timer);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pci_ops
#ifndef WRAPPER_FOR_struct_pci_ops
#define WRAPPER_FOR_struct_pci_ops
TYPE_WRAPPER(struct pci_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.read);
        WRAP_FUNCTION(arg.read);
        WRAP_FUNCTION(arg.write);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pci_bus
#ifndef WRAPPER_FOR_struct_pci_bus
#define WRAPPER_FOR_struct_pci_bus
TYPE_WRAPPER(struct pci_bus, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.parent);
        WRAP_RECURSIVE(arg.self);
        WRAP_RECURSIVE(arg.ops);
        WRAP_RECURSIVE(arg.procdir);
        WRAP_RECURSIVE(arg.bridge);
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.legacy_io);
        WRAP_RECURSIVE(arg.legacy_mem);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pci_slot
#ifndef WRAPPER_FOR_struct_pci_slot
#define WRAPPER_FOR_struct_pci_slot
TYPE_WRAPPER(struct pci_slot, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.bus);
        WRAP_RECURSIVE(arg.kobj);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pci_error_handlers
#ifndef WRAPPER_FOR_struct_pci_error_handlers
#define WRAPPER_FOR_struct_pci_error_handlers
TYPE_WRAPPER(struct pci_error_handlers, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.error_detected);
        WRAP_FUNCTION(arg.error_detected);
        WRAP_FUNCTION(arg.mmio_enabled);
        WRAP_FUNCTION(arg.link_reset);
        WRAP_FUNCTION(arg.slot_reset);
        WRAP_FUNCTION(arg.resume);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pci_driver
#ifndef WRAPPER_FOR_struct_pci_driver
#define WRAPPER_FOR_struct_pci_driver
TYPE_WRAPPER(struct pci_driver, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.probe);
        WRAP_FUNCTION(arg.probe);
        WRAP_FUNCTION(arg.remove);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.suspend_late);
        WRAP_FUNCTION(arg.resume_early);
        WRAP_FUNCTION(arg.resume);
        WRAP_FUNCTION(arg.shutdown);
        WRAP_FUNCTION(arg.sriov_configure);
        WRAP_RECURSIVE(arg.driver);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pci_dev
#ifndef WRAPPER_FOR_struct_pci_dev
#define WRAPPER_FOR_struct_pci_dev
TYPE_WRAPPER(struct pci_dev, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.bus);
        WRAP_RECURSIVE(arg.subordinate);
        WRAP_RECURSIVE(arg.procent);
        WRAP_RECURSIVE(arg.slot);
        WRAP_RECURSIVE(arg.driver);
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.rom_attr);
        WRAP_RECURSIVE(arg.msi_kset);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_scsi_host_template
#ifndef WRAPPER_FOR_struct_scsi_host_template
#define WRAPPER_FOR_struct_scsi_host_template
TYPE_WRAPPER(struct scsi_host_template, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.detect);
        WRAP_RECURSIVE(arg.module);
        WRAP_FUNCTION(arg.detect);
        WRAP_FUNCTION(arg.release);
        WRAP_FUNCTION(arg.info);
        WRAP_FUNCTION(arg.ioctl);
        WRAP_FUNCTION(arg.compat_ioctl);
        WRAP_FUNCTION(arg.queuecommand);
        WRAP_FUNCTION(arg.transfer_response);
        WRAP_FUNCTION(arg.eh_abort_handler);
        WRAP_FUNCTION(arg.eh_device_reset_handler);
        WRAP_FUNCTION(arg.eh_target_reset_handler);
        WRAP_FUNCTION(arg.eh_bus_reset_handler);
        WRAP_FUNCTION(arg.eh_host_reset_handler);
        WRAP_FUNCTION(arg.slave_alloc);
        WRAP_FUNCTION(arg.slave_configure);
        WRAP_FUNCTION(arg.slave_destroy);
        WRAP_FUNCTION(arg.target_alloc);
        WRAP_FUNCTION(arg.target_destroy);
        WRAP_FUNCTION(arg.scan_finished);
        WRAP_FUNCTION(arg.scan_start);
        WRAP_FUNCTION(arg.change_queue_depth);
        WRAP_FUNCTION(arg.change_queue_type);
        WRAP_FUNCTION(arg.bios_param);
        WRAP_FUNCTION(arg.unlock_native_capacity);
        WRAP_FUNCTION(arg.proc_info);
        WRAP_FUNCTION(arg.eh_timed_out);
        WRAP_FUNCTION(arg.host_reset);
        WRAP_RECURSIVE(arg.proc_dir);
        WRAP_RECURSIVE(arg.shost_attrs);
        WRAP_RECURSIVE(arg.sdev_attrs);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_Scsi_Host
#ifndef WRAPPER_FOR_struct_Scsi_Host
#define WRAPPER_FOR_struct_Scsi_Host
TYPE_WRAPPER(struct Scsi_Host, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.scan_mutex);
        WRAP_RECURSIVE(arg.ehandler);
        WRAP_RECURSIVE(arg.hostt);
        WRAP_RECURSIVE(arg.bqt);
        WRAP_RECURSIVE(arg.uspace_req_q);
        WRAP_RECURSIVE(arg.shost_gendev);
        WRAP_RECURSIVE(arg.shost_dev);
        WRAP_RECURSIVE(arg.dma_dev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ata_eh_info
#ifndef WRAPPER_FOR_struct_ata_eh_info
#define WRAPPER_FOR_struct_ata_eh_info
TYPE_WRAPPER(struct ata_eh_info, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ata_eh_context
#ifndef WRAPPER_FOR_struct_ata_eh_context
#define WRAPPER_FOR_struct_ata_eh_context
TYPE_WRAPPER(struct ata_eh_context, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.i);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ata_link
#ifndef WRAPPER_FOR_struct_ata_link
#define WRAPPER_FOR_struct_ata_link
TYPE_WRAPPER(struct ata_link, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.ap);
        WRAP_RECURSIVE(arg.tdev);
        WRAP_RECURSIVE(arg.eh_info);
        WRAP_RECURSIVE(arg.eh_context);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ata_device
#ifndef WRAPPER_FOR_struct_ata_device
#define WRAPPER_FOR_struct_ata_device
TYPE_WRAPPER(struct ata_device, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.link);
        WRAP_RECURSIVE(arg.tdev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ata_queued_cmd
#ifndef WRAPPER_FOR_struct_ata_queued_cmd
#define WRAPPER_FOR_struct_ata_queued_cmd
TYPE_WRAPPER(struct ata_queued_cmd, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.scsidone);
        WRAP_RECURSIVE(arg.ap);
        WRAP_RECURSIVE(arg.dev);
        WRAP_FUNCTION(arg.scsidone);
        WRAP_FUNCTION(arg.complete_fn);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ata_host
#ifndef WRAPPER_FOR_struct_ata_host
#define WRAPPER_FOR_struct_ata_host
TYPE_WRAPPER(struct ata_host, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.ops);
        WRAP_RECURSIVE(arg.eh_mutex);
        WRAP_RECURSIVE(arg.eh_owner);
        WRAP_RECURSIVE(arg.simplex_claimed);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ata_port_operations
#ifndef WRAPPER_FOR_struct_ata_port_operations
#define WRAPPER_FOR_struct_ata_port_operations
TYPE_WRAPPER(struct ata_port_operations, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.qc_defer);
        WRAP_FUNCTION(arg.qc_defer);
        WRAP_FUNCTION(arg.check_atapi_dma);
        WRAP_FUNCTION(arg.qc_prep);
        WRAP_FUNCTION(arg.qc_issue);
        WRAP_FUNCTION(arg.qc_fill_rtf);
        WRAP_FUNCTION(arg.cable_detect);
        WRAP_FUNCTION(arg.mode_filter);
        WRAP_FUNCTION(arg.set_piomode);
        WRAP_FUNCTION(arg.set_dmamode);
        WRAP_FUNCTION(arg.set_mode);
        WRAP_FUNCTION(arg.read_id);
        WRAP_FUNCTION(arg.dev_config);
        WRAP_FUNCTION(arg.freeze);
        WRAP_FUNCTION(arg.thaw);
        WRAP_FUNCTION(arg.prereset);
        WRAP_FUNCTION(arg.softreset);
        WRAP_FUNCTION(arg.hardreset);
        WRAP_FUNCTION(arg.postreset);
        WRAP_FUNCTION(arg.pmp_prereset);
        WRAP_FUNCTION(arg.pmp_softreset);
        WRAP_FUNCTION(arg.pmp_hardreset);
        WRAP_FUNCTION(arg.pmp_postreset);
        WRAP_FUNCTION(arg.error_handler);
        WRAP_FUNCTION(arg.lost_interrupt);
        WRAP_FUNCTION(arg.post_internal_cmd);
        WRAP_FUNCTION(arg.sched_eh);
        WRAP_FUNCTION(arg.end_eh);
        WRAP_FUNCTION(arg.scr_read);
        WRAP_FUNCTION(arg.scr_write);
        WRAP_FUNCTION(arg.pmp_attach);
        WRAP_FUNCTION(arg.pmp_detach);
        WRAP_FUNCTION(arg.set_lpm);
        WRAP_FUNCTION(arg.port_suspend);
        WRAP_FUNCTION(arg.port_resume);
        WRAP_FUNCTION(arg.port_start);
        WRAP_FUNCTION(arg.port_stop);
        WRAP_FUNCTION(arg.host_stop);
        WRAP_FUNCTION(arg.sff_dev_select);
        WRAP_FUNCTION(arg.sff_set_devctl);
        WRAP_FUNCTION(arg.sff_check_status);
        WRAP_FUNCTION(arg.sff_check_altstatus);
        WRAP_FUNCTION(arg.sff_tf_load);
        WRAP_FUNCTION(arg.sff_tf_read);
        WRAP_FUNCTION(arg.sff_exec_command);
        WRAP_FUNCTION(arg.sff_data_xfer);
        WRAP_FUNCTION(arg.sff_irq_on);
        WRAP_FUNCTION(arg.sff_irq_check);
        WRAP_FUNCTION(arg.sff_irq_clear);
        WRAP_FUNCTION(arg.sff_drain_fifo);
        WRAP_FUNCTION(arg.bmdma_setup);
        WRAP_FUNCTION(arg.bmdma_start);
        WRAP_FUNCTION(arg.bmdma_stop);
        WRAP_FUNCTION(arg.bmdma_status);
        WRAP_FUNCTION(arg.em_show);
        WRAP_FUNCTION(arg.em_store);
        WRAP_FUNCTION(arg.sw_activity_show);
        WRAP_FUNCTION(arg.sw_activity_store);
        WRAP_FUNCTION(arg.phy_reset);
        WRAP_FUNCTION(arg.eng_timeout);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ata_port
#ifndef WRAPPER_FOR_struct_ata_port
#define WRAPPER_FOR_struct_ata_port
TYPE_WRAPPER(struct ata_port, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.scsi_host);
        WRAP_RECURSIVE(arg.ops);
        WRAP_RECURSIVE(arg.sff_pio_task_link);
        WRAP_RECURSIVE(arg.sff_pio_task);
        WRAP_RECURSIVE(arg.link);
        WRAP_RECURSIVE(arg.slave_link);
        WRAP_RECURSIVE(arg.pmp_link);
        WRAP_RECURSIVE(arg.excl_link);
        WRAP_RECURSIVE(arg.host);
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.tdev);
        WRAP_RECURSIVE(arg.scsi_scan_mutex);
        WRAP_RECURSIVE(arg.hotplug_task);
        WRAP_RECURSIVE(arg.scsi_rescan_task);
        WRAP_RECURSIVE(arg.fastdrain_timer);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_cleancache_ops
#ifndef WRAPPER_FOR_struct_cleancache_ops
#define WRAPPER_FOR_struct_cleancache_ops
TYPE_WRAPPER(struct cleancache_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.init_fs);
        WRAP_FUNCTION(arg.init_fs);
        WRAP_FUNCTION(arg.init_shared_fs);
        WRAP_FUNCTION(arg.get_page);
        WRAP_FUNCTION(arg.put_page);
        WRAP_FUNCTION(arg.invalidate_page);
        WRAP_FUNCTION(arg.invalidate_inode);
        WRAP_FUNCTION(arg.invalidate_fs);
    }
    NO_RETURN
})
#endif


#if defined(CAN_WRAP___quota_error) && CAN_WRAP___quota_error && defined(DETACH_ADDR___quota_error)
#ifndef WRAPPER_FOR___quota_error
FUNCTION_WRAPPER_VOID(__quota_error,(struct super_block *sb, const char *func, const char *fmt, ...), {
    va_list args__;
    va_start(args__, fmt);
    WRAP_RECURSIVE(sb);
    // TODO: variadic arguments
    D( granary_fault(); )
    __quota_error(sb, func, fmt);
    va_end(args__);
})
#endif
#endif


#define WRAPPER_FOR_struct_crypto_ablkcipher
#ifndef WRAPPER_FOR_struct_crypto_ablkcipher
#define WRAPPER_FOR_struct_crypto_ablkcipher
TYPE_WRAPPER(struct crypto_ablkcipher, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.base);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_crypto_async_request
#ifndef WRAPPER_FOR_struct_crypto_async_request
#define WRAPPER_FOR_struct_crypto_async_request
TYPE_WRAPPER(struct crypto_async_request, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.complete);
        WRAP_RECURSIVE(arg.tfm);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ablkcipher_request
#ifndef WRAPPER_FOR_struct_ablkcipher_request
#define WRAPPER_FOR_struct_ablkcipher_request
TYPE_WRAPPER(struct ablkcipher_request, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.base);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ablkcipher_tfm
#ifndef WRAPPER_FOR_struct_ablkcipher_tfm
#define WRAPPER_FOR_struct_ablkcipher_tfm
TYPE_WRAPPER(struct ablkcipher_tfm, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.setkey);
        WRAP_FUNCTION(arg.setkey);
        WRAP_FUNCTION(arg.encrypt);
        WRAP_FUNCTION(arg.decrypt);
        WRAP_FUNCTION(arg.givencrypt);
        WRAP_FUNCTION(arg.givdecrypt);
        WRAP_RECURSIVE(arg.base);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_crypto_aead
#ifndef WRAPPER_FOR_struct_crypto_aead
#define WRAPPER_FOR_struct_crypto_aead
TYPE_WRAPPER(struct crypto_aead, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.base);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_aead_request
#ifndef WRAPPER_FOR_struct_aead_request
#define WRAPPER_FOR_struct_aead_request
TYPE_WRAPPER(struct aead_request, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.base);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_aead_tfm
#ifndef WRAPPER_FOR_struct_aead_tfm
#define WRAPPER_FOR_struct_aead_tfm
TYPE_WRAPPER(struct aead_tfm, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.setkey);
        WRAP_FUNCTION(arg.setkey);
        WRAP_FUNCTION(arg.encrypt);
        WRAP_FUNCTION(arg.decrypt);
        WRAP_FUNCTION(arg.givencrypt);
        WRAP_FUNCTION(arg.givdecrypt);
        WRAP_RECURSIVE(arg.base);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_crypto_blkcipher
#ifndef WRAPPER_FOR_struct_crypto_blkcipher
#define WRAPPER_FOR_struct_crypto_blkcipher
TYPE_WRAPPER(struct crypto_blkcipher, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.base);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_blkcipher_desc
#ifndef WRAPPER_FOR_struct_blkcipher_desc
#define WRAPPER_FOR_struct_blkcipher_desc
TYPE_WRAPPER(struct blkcipher_desc, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.tfm);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_blkcipher_tfm
#ifndef WRAPPER_FOR_struct_blkcipher_tfm
#define WRAPPER_FOR_struct_blkcipher_tfm
TYPE_WRAPPER(struct blkcipher_tfm, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.setkey);
        WRAP_FUNCTION(arg.setkey);
        WRAP_FUNCTION(arg.encrypt);
        WRAP_FUNCTION(arg.decrypt);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_cipher_tfm
#ifndef WRAPPER_FOR_struct_cipher_tfm
#define WRAPPER_FOR_struct_cipher_tfm
TYPE_WRAPPER(struct cipher_tfm, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.cit_setkey);
        WRAP_FUNCTION(arg.cit_setkey);
        WRAP_FUNCTION(arg.cit_encrypt_one);
        WRAP_FUNCTION(arg.cit_decrypt_one);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_crypto_hash
#ifndef WRAPPER_FOR_struct_crypto_hash
#define WRAPPER_FOR_struct_crypto_hash
TYPE_WRAPPER(struct crypto_hash, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.base);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_hash_desc
#ifndef WRAPPER_FOR_struct_hash_desc
#define WRAPPER_FOR_struct_hash_desc
TYPE_WRAPPER(struct hash_desc, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.tfm);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_hash_tfm
#ifndef WRAPPER_FOR_struct_hash_tfm
#define WRAPPER_FOR_struct_hash_tfm
TYPE_WRAPPER(struct hash_tfm, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.init);
        WRAP_FUNCTION(arg.init);
        WRAP_FUNCTION(arg.update);
        WRAP_FUNCTION(arg.final);
        WRAP_FUNCTION(arg.digest);
        WRAP_FUNCTION(arg.setkey);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_compress_tfm
#ifndef WRAPPER_FOR_struct_compress_tfm
#define WRAPPER_FOR_struct_compress_tfm
TYPE_WRAPPER(struct compress_tfm, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.cot_compress);
        WRAP_FUNCTION(arg.cot_compress);
        WRAP_FUNCTION(arg.cot_decompress);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_crypto_rng
#ifndef WRAPPER_FOR_struct_crypto_rng
#define WRAPPER_FOR_struct_crypto_rng
TYPE_WRAPPER(struct crypto_rng, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.base);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_rng_tfm
#ifndef WRAPPER_FOR_struct_rng_tfm
#define WRAPPER_FOR_struct_rng_tfm
TYPE_WRAPPER(struct rng_tfm, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.rng_gen_random);
        WRAP_FUNCTION(arg.rng_gen_random);
        WRAP_FUNCTION(arg.rng_reset);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ablkcipher_alg
#ifndef WRAPPER_FOR_struct_ablkcipher_alg
#define WRAPPER_FOR_struct_ablkcipher_alg
TYPE_WRAPPER(struct ablkcipher_alg, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.setkey);
        WRAP_FUNCTION(arg.setkey);
        WRAP_FUNCTION(arg.encrypt);
        WRAP_FUNCTION(arg.decrypt);
        WRAP_FUNCTION(arg.givencrypt);
        WRAP_FUNCTION(arg.givdecrypt);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_aead_alg
#ifndef WRAPPER_FOR_struct_aead_alg
#define WRAPPER_FOR_struct_aead_alg
TYPE_WRAPPER(struct aead_alg, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.setkey);
        WRAP_FUNCTION(arg.setkey);
        WRAP_FUNCTION(arg.setauthsize);
        WRAP_FUNCTION(arg.encrypt);
        WRAP_FUNCTION(arg.decrypt);
        WRAP_FUNCTION(arg.givencrypt);
        WRAP_FUNCTION(arg.givdecrypt);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_blkcipher_alg
#ifndef WRAPPER_FOR_struct_blkcipher_alg
#define WRAPPER_FOR_struct_blkcipher_alg
TYPE_WRAPPER(struct blkcipher_alg, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.setkey);
        WRAP_FUNCTION(arg.setkey);
        WRAP_FUNCTION(arg.encrypt);
        WRAP_FUNCTION(arg.decrypt);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_cipher_alg
#ifndef WRAPPER_FOR_struct_cipher_alg
#define WRAPPER_FOR_struct_cipher_alg
TYPE_WRAPPER(struct cipher_alg, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.cia_setkey);
        WRAP_FUNCTION(arg.cia_setkey);
        WRAP_FUNCTION(arg.cia_encrypt);
        WRAP_FUNCTION(arg.cia_decrypt);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_compress_alg
#ifndef WRAPPER_FOR_struct_compress_alg
#define WRAPPER_FOR_struct_compress_alg
TYPE_WRAPPER(struct compress_alg, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.coa_compress);
        WRAP_FUNCTION(arg.coa_compress);
        WRAP_FUNCTION(arg.coa_decompress);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_rng_alg
#ifndef WRAPPER_FOR_struct_rng_alg
#define WRAPPER_FOR_struct_rng_alg
TYPE_WRAPPER(struct rng_alg, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.rng_make_random);
        WRAP_FUNCTION(arg.rng_make_random);
        WRAP_FUNCTION(arg.rng_reset);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_crypto_alg
#ifndef WRAPPER_FOR_struct_crypto_alg
#define WRAPPER_FOR_struct_crypto_alg
TYPE_WRAPPER(struct crypto_alg, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.cra_init);
        WRAP_FUNCTION(arg.cra_init);
        WRAP_FUNCTION(arg.cra_exit);
        WRAP_FUNCTION(arg.cra_destroy);
        WRAP_RECURSIVE(arg.cra_module);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_crypto_tfm
#ifndef WRAPPER_FOR_struct_crypto_tfm
#define WRAPPER_FOR_struct_crypto_tfm
TYPE_WRAPPER(struct crypto_tfm, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.exit);
        WRAP_FUNCTION(arg.exit);
        WRAP_RECURSIVE(arg.__crt_alg);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_nf_hook_ops
#ifndef WRAPPER_FOR_struct_nf_hook_ops
#define WRAPPER_FOR_struct_nf_hook_ops
TYPE_WRAPPER(struct nf_hook_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.hook);
        WRAP_FUNCTION(arg.hook);
        WRAP_RECURSIVE(arg.owner);
    }
    NO_RETURN
})
#endif


//#define WRAPPER_FOR_struct_buffer_head
#ifndef WRAPPER_FOR_struct_buffer_head
#define WRAPPER_FOR_struct_buffer_head
TYPE_WRAPPER(struct buffer_head, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.b_end_io);
        WRAP_RECURSIVE(arg.b_this_page);
        WRAP_RECURSIVE(arg.b_page);
        WRAP_RECURSIVE(arg.b_bdev);
        WRAP_FUNCTION(arg.b_end_io);
        WRAP_RECURSIVE(arg.b_assoc_map);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_jbd2_buffer_trigger_type
#ifndef WRAPPER_FOR_struct_jbd2_buffer_trigger_type
#define WRAPPER_FOR_struct_jbd2_buffer_trigger_type
TYPE_WRAPPER(struct jbd2_buffer_trigger_type, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.t_frozen);
        WRAP_FUNCTION(arg.t_frozen);
        WRAP_FUNCTION(arg.t_abort);
    }
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_journal_head
#define WRAPPER_FOR_struct_journal_head
TYPE_WRAPPER(struct journal_head, {
    PRE_WRAP {
        kern_printk("journal_head!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        ADD_TO_HASH( &arg, SCAN_HEAD_FUNC(struct journal_head));
        WRAP_RECURSIVE(arg.b_bh);
        WRAP_RECURSIVE(arg.b_transaction);
        WRAP_RECURSIVE(arg.b_next_transaction);
        WRAP_RECURSIVE(arg.b_tnext);
        WRAP_RECURSIVE(arg.b_tprev);
        WRAP_RECURSIVE(arg.b_cp_transaction);
        WRAP_RECURSIVE(arg.b_cpnext);
        WRAP_RECURSIVE(arg.b_cpprev);
        WRAP_RECURSIVE(arg.b_triggers);
        WRAP_RECURSIVE(arg.b_frozen_triggers);
    }
    NO_POST
    NO_RETURN
})
#endif


//#define WRAPPER_FOR_struct_transaction_s
#ifndef WRAPPER_FOR_struct_transaction_s
#define WRAPPER_FOR_struct_transaction_s
TYPE_WRAPPER(struct transaction_s, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.t_journal);
        WRAP_RECURSIVE(arg.t_reserved_list);
        WRAP_RECURSIVE(arg.t_buffers);
        WRAP_RECURSIVE(arg.t_forget);
        WRAP_RECURSIVE(arg.t_checkpoint_list);
        WRAP_RECURSIVE(arg.t_checkpoint_io_list);
        WRAP_RECURSIVE(arg.t_iobuf_list);
        WRAP_RECURSIVE(arg.t_shadow_list);
        WRAP_RECURSIVE(arg.t_log_list);
        WRAP_RECURSIVE(arg.t_cpnext);
        WRAP_RECURSIVE(arg.t_cpprev);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_crypto_shash
#ifndef WRAPPER_FOR_struct_crypto_shash
#define WRAPPER_FOR_struct_crypto_shash
TYPE_WRAPPER(struct crypto_shash, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.base);
    }
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_journal_s
#define WRAPPER_FOR_struct_journal_s
TYPE_WRAPPER(struct journal_s, {
    PRE_WRAP {
        kern_printk("journal_s!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        ADD_TO_HASH( &arg, SCAN_HEAD_FUNC(struct journal_s));
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.j_commit_callback);
        WRAP_RECURSIVE(arg.j_sb_buffer);
        WRAP_RECURSIVE(arg.j_barrier);
        WRAP_RECURSIVE(arg.j_running_transaction);
        WRAP_RECURSIVE(arg.j_committing_transaction);
        WRAP_RECURSIVE(arg.j_checkpoint_transactions);
        WRAP_RECURSIVE(arg.j_checkpoint_mutex);
        WRAP_RECURSIVE(arg.j_dev);
        WRAP_RECURSIVE(arg.j_fs_dev);
        WRAP_RECURSIVE(arg.j_inode);
        WRAP_RECURSIVE(arg.j_task);
        WRAP_RECURSIVE(arg.j_commit_timer);
        WRAP_RECURSIVE(arg.j_wbuf);
        WRAP_FUNCTION(arg.j_commit_callback);
        WRAP_RECURSIVE(arg.j_proc_entry);
        WRAP_RECURSIVE(arg.j_chksum_driver);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pglist_data
#ifndef WRAPPER_FOR_struct_pglist_data
#define WRAPPER_FOR_struct_pglist_data
TYPE_WRAPPER(struct pglist_data, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.kswapd);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_zone
#ifndef WRAPPER_FOR_struct_zone
#define WRAPPER_FOR_struct_zone
TYPE_WRAPPER(struct zone, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.zone_pgdat);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_zoneref
#ifndef WRAPPER_FOR_struct_zoneref
#define WRAPPER_FOR_struct_zoneref
TYPE_WRAPPER(struct zoneref, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.zone);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_prop_descriptor
#ifndef WRAPPER_FOR_struct_prop_descriptor
#define WRAPPER_FOR_struct_prop_descriptor
TYPE_WRAPPER(struct prop_descriptor, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.mutex);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_clocksource
#ifndef WRAPPER_FOR_struct_clocksource
#define WRAPPER_FOR_struct_clocksource
TYPE_WRAPPER(struct clocksource, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.read);
        WRAP_FUNCTION(arg.read);
        WRAP_FUNCTION(arg.enable);
        WRAP_FUNCTION(arg.disable);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.resume);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_mb_cache
#ifndef WRAPPER_FOR_struct_mb_cache
#define WRAPPER_FOR_struct_mb_cache
TYPE_WRAPPER(struct mb_cache, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.c_entry_cache);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_mb_cache_entry
#ifndef WRAPPER_FOR_struct_mb_cache_entry
#define WRAPPER_FOR_struct_mb_cache_entry
TYPE_WRAPPER(struct mb_cache_entry, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.e_cache);
        WRAP_RECURSIVE(arg.e_bdev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_irq_chip
#ifndef WRAPPER_FOR_struct_irq_chip
#define WRAPPER_FOR_struct_irq_chip
TYPE_WRAPPER(struct irq_chip, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.irq_startup);
        WRAP_FUNCTION(arg.irq_startup);
        WRAP_FUNCTION(arg.irq_shutdown);
        WRAP_FUNCTION(arg.irq_enable);
        WRAP_FUNCTION(arg.irq_disable);
        WRAP_FUNCTION(arg.irq_ack);
        WRAP_FUNCTION(arg.irq_mask);
        WRAP_FUNCTION(arg.irq_mask_ack);
        WRAP_FUNCTION(arg.irq_unmask);
        WRAP_FUNCTION(arg.irq_eoi);
        WRAP_FUNCTION(arg.irq_set_affinity);
        WRAP_FUNCTION(arg.irq_retrigger);
        WRAP_FUNCTION(arg.irq_set_type);
        WRAP_FUNCTION(arg.irq_set_wake);
        WRAP_FUNCTION(arg.irq_bus_lock);
        WRAP_FUNCTION(arg.irq_bus_sync_unlock);
        WRAP_FUNCTION(arg.irq_cpu_online);
        WRAP_FUNCTION(arg.irq_cpu_offline);
        WRAP_FUNCTION(arg.irq_suspend);
        WRAP_FUNCTION(arg.irq_resume);
        WRAP_FUNCTION(arg.irq_pm_shutdown);
        WRAP_FUNCTION(arg.irq_print_chip);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_irq_data
#ifndef WRAPPER_FOR_struct_irq_data
#define WRAPPER_FOR_struct_irq_data
TYPE_WRAPPER(struct irq_data, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.chip);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_rt_mutex
#ifndef WRAPPER_FOR_struct_rt_mutex
#define WRAPPER_FOR_struct_rt_mutex
TYPE_WRAPPER(struct rt_mutex, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.owner);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_napi_struct
#ifndef WRAPPER_FOR_struct_napi_struct
#define WRAPPER_FOR_struct_napi_struct
TYPE_WRAPPER(struct napi_struct, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.poll);
        WRAP_FUNCTION(arg.poll);
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.gro_list);
        WRAP_RECURSIVE(arg.skb);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_rcu_batch
#ifndef WRAPPER_FOR_struct_rcu_batch
#define WRAPPER_FOR_struct_rcu_batch
TYPE_WRAPPER(struct rcu_batch, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.head);
        WRAP_RECURSIVE(arg.tail);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_srcu_struct
#ifndef WRAPPER_FOR_struct_srcu_struct
#define WRAPPER_FOR_struct_srcu_struct
TYPE_WRAPPER(struct srcu_struct, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.batch_queue);
        WRAP_RECURSIVE(arg.batch_check0);
        WRAP_RECURSIVE(arg.batch_check1);
        WRAP_RECURSIVE(arg.batch_done);
        WRAP_RECURSIVE(arg.work);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_netlink_kernel_cfg
#ifndef WRAPPER_FOR_struct_netlink_kernel_cfg
#define WRAPPER_FOR_struct_netlink_kernel_cfg
TYPE_WRAPPER(struct netlink_kernel_cfg, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.input);
        WRAP_FUNCTION(arg.input);
        WRAP_RECURSIVE(arg.cb_mutex);
        WRAP_FUNCTION(arg.bind);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ff_device
#ifndef WRAPPER_FOR_struct_ff_device
#define WRAPPER_FOR_struct_ff_device
TYPE_WRAPPER(struct ff_device, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.upload);
        WRAP_FUNCTION(arg.upload);
        WRAP_FUNCTION(arg.erase);
        WRAP_FUNCTION(arg.playback);
        WRAP_FUNCTION(arg.set_gain);
        WRAP_FUNCTION(arg.set_autocenter);
        WRAP_FUNCTION(arg.destroy);
        WRAP_RECURSIVE(arg.mutex);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_input_dev
#ifndef WRAPPER_FOR_struct_input_dev
#define WRAPPER_FOR_struct_input_dev
TYPE_WRAPPER(struct input_dev, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.setkeycode);
        WRAP_FUNCTION(arg.setkeycode);
        WRAP_FUNCTION(arg.getkeycode);
        WRAP_RECURSIVE(arg.ff);
        WRAP_RECURSIVE(arg.timer);
        WRAP_FUNCTION(arg.open);
        WRAP_FUNCTION(arg.close);
        WRAP_FUNCTION(arg.flush);
        WRAP_FUNCTION(arg.event);
        WRAP_RECURSIVE(arg.grab);
        WRAP_RECURSIVE(arg.mutex);
        WRAP_RECURSIVE(arg.dev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_input_handler
#ifndef WRAPPER_FOR_struct_input_handler
#define WRAPPER_FOR_struct_input_handler
TYPE_WRAPPER(struct input_handler, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.event);
        WRAP_FUNCTION(arg.event);
        WRAP_FUNCTION(arg.events);
        WRAP_FUNCTION(arg.filter);
        WRAP_FUNCTION(arg.match);
        WRAP_FUNCTION(arg.connect);
        WRAP_FUNCTION(arg.disconnect);
        WRAP_FUNCTION(arg.start);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_input_handle
#ifndef WRAPPER_FOR_struct_input_handle
#define WRAPPER_FOR_struct_input_handle
TYPE_WRAPPER(struct input_handle, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.handler);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dma_async_tx_descriptor
#ifndef WRAPPER_FOR_struct_dma_async_tx_descriptor
#define WRAPPER_FOR_struct_dma_async_tx_descriptor
TYPE_WRAPPER(struct dma_async_tx_descriptor, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.tx_submit);
        WRAP_RECURSIVE(arg.chan);
        WRAP_FUNCTION(arg.tx_submit);
        WRAP_FUNCTION(arg.callback);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dma_device
#ifndef WRAPPER_FOR_struct_dma_device
#define WRAPPER_FOR_struct_dma_device
TYPE_WRAPPER(struct dma_device, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.device_alloc_chan_resources);
        WRAP_RECURSIVE(arg.dev);
        WRAP_FUNCTION(arg.device_alloc_chan_resources);
        WRAP_FUNCTION(arg.device_free_chan_resources);
        WRAP_FUNCTION(arg.device_prep_dma_memcpy);
        WRAP_FUNCTION(arg.device_prep_dma_xor);
        WRAP_FUNCTION(arg.device_prep_dma_xor_val);
        WRAP_FUNCTION(arg.device_prep_dma_pq);
        WRAP_FUNCTION(arg.device_prep_dma_pq_val);
        WRAP_FUNCTION(arg.device_prep_dma_memset);
        WRAP_FUNCTION(arg.device_prep_dma_interrupt);
        WRAP_FUNCTION(arg.device_prep_dma_sg);
        WRAP_FUNCTION(arg.device_prep_slave_sg);
        WRAP_FUNCTION(arg.device_prep_dma_cyclic);
        WRAP_FUNCTION(arg.device_prep_interleaved_dma);
        WRAP_FUNCTION(arg.device_control);
        WRAP_FUNCTION(arg.device_tx_status);
        WRAP_FUNCTION(arg.device_issue_pending);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dma_chan_dev
#ifndef WRAPPER_FOR_struct_dma_chan_dev
#define WRAPPER_FOR_struct_dma_chan_dev
TYPE_WRAPPER(struct dma_chan_dev, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.chan);
        WRAP_RECURSIVE(arg.device);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dma_chan
#ifndef WRAPPER_FOR_struct_dma_chan
#define WRAPPER_FOR_struct_dma_chan
TYPE_WRAPPER(struct dma_chan, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.device);
        WRAP_RECURSIVE(arg.dev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_rq_map_data
#ifndef WRAPPER_FOR_struct_rq_map_data
#define WRAPPER_FOR_struct_rq_map_data
TYPE_WRAPPER(struct rq_map_data, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.pages);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_raw_notifier_head
#ifndef WRAPPER_FOR_struct_raw_notifier_head
#define WRAPPER_FOR_struct_raw_notifier_head
TYPE_WRAPPER(struct raw_notifier_head, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.head);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ts_config
#ifndef WRAPPER_FOR_struct_ts_config
#define WRAPPER_FOR_struct_ts_config
TYPE_WRAPPER(struct ts_config, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.get_next_block);
        WRAP_RECURSIVE(arg.ops);
        WRAP_FUNCTION(arg.get_next_block);
        WRAP_FUNCTION(arg.finish);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ts_ops
#ifndef WRAPPER_FOR_struct_ts_ops
#define WRAPPER_FOR_struct_ts_ops
TYPE_WRAPPER(struct ts_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.init);
        WRAP_FUNCTION(arg.init);
        WRAP_FUNCTION(arg.find);
        WRAP_FUNCTION(arg.destroy);
        WRAP_FUNCTION(arg.get_pattern);
        WRAP_FUNCTION(arg.get_pattern_len);
        WRAP_RECURSIVE(arg.owner);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_clock_event_device
#ifndef WRAPPER_FOR_struct_clock_event_device
#define WRAPPER_FOR_struct_clock_event_device
TYPE_WRAPPER(struct clock_event_device, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.event_handler);
        WRAP_FUNCTION(arg.event_handler);
        WRAP_FUNCTION(arg.set_next_event);
        WRAP_FUNCTION(arg.set_next_ktime);
        WRAP_FUNCTION(arg.broadcast);
        WRAP_FUNCTION(arg.set_mode);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.resume);
    }
    NO_RETURN
})
#endif



#ifndef WRAPPER_FOR_struct_jbd2_journal_handle
#define WRAPPER_FOR_struct_jbd2_journal_handle
TYPE_WRAPPER(struct jbd2_journal_handle, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.h_transaction);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_jbd2_inode
#ifndef WRAPPER_FOR_struct_jbd2_inode
#define WRAPPER_FOR_struct_jbd2_inode
TYPE_WRAPPER(struct jbd2_inode, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.i_transaction);
        WRAP_RECURSIVE(arg.i_next_transaction);
        WRAP_RECURSIVE(arg.i_vfs_inode);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_inet_frag_queue
#ifndef WRAPPER_FOR_struct_inet_frag_queue
#define WRAPPER_FOR_struct_inet_frag_queue
TYPE_WRAPPER(struct inet_frag_queue, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.timer);
        WRAP_RECURSIVE(arg.fragments);
        WRAP_RECURSIVE(arg.fragments_tail);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_inet_frags
#ifndef WRAPPER_FOR_struct_inet_frags
#define WRAPPER_FOR_struct_inet_frags
TYPE_WRAPPER(struct inet_frags, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.hashfn);
        WRAP_RECURSIVE(arg.secret_timer);
        WRAP_FUNCTION(arg.hashfn);
        WRAP_FUNCTION(arg.constructor);
        WRAP_FUNCTION(arg.destructor);
        WRAP_FUNCTION(arg.skb_free);
        WRAP_FUNCTION(arg.match);
        WRAP_FUNCTION(arg.frag_expire);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_irqaction
#ifndef WRAPPER_FOR_struct_irqaction
#define WRAPPER_FOR_struct_irqaction
TYPE_WRAPPER(struct irqaction, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.handler);
        WRAP_RECURSIVE(arg.next);
        WRAP_FUNCTION(arg.thread_fn);
        WRAP_RECURSIVE(arg.thread);
        WRAP_RECURSIVE(arg.dir);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_irq_affinity_notify
#ifndef WRAPPER_FOR_struct_irq_affinity_notify
#define WRAPPER_FOR_struct_irq_affinity_notify
TYPE_WRAPPER(struct irq_affinity_notify, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.notify);
        WRAP_RECURSIVE(arg.work);
        WRAP_FUNCTION(arg.notify);
        WRAP_FUNCTION(arg.release);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_irq_desc
#ifndef WRAPPER_FOR_struct_irq_desc
#define WRAPPER_FOR_struct_irq_desc
TYPE_WRAPPER(struct irq_desc, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.irq_data);
        WRAP_FUNCTION(arg.handle_irq);
        WRAP_RECURSIVE(arg.action);
        WRAP_RECURSIVE(arg.affinity_notify);
        WRAP_RECURSIVE(arg.dir);
        WRAP_RECURSIVE(arg.owner);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_idr_layer
#ifndef WRAPPER_FOR_struct_idr_layer
#define WRAPPER_FOR_struct_idr_layer
TYPE_WRAPPER(struct idr_layer, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.callback_head);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_idr
#ifndef WRAPPER_FOR_struct_idr
#define WRAPPER_FOR_struct_idr
TYPE_WRAPPER(struct idr, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.top);
        WRAP_RECURSIVE(arg.id_free);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_cgroup_map_cb
#ifndef WRAPPER_FOR_struct_cgroup_map_cb
#define WRAPPER_FOR_struct_cgroup_map_cb
TYPE_WRAPPER(struct cgroup_map_cb, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.fill);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_cftype
#ifndef WRAPPER_FOR_struct_cftype
#define WRAPPER_FOR_struct_cftype
TYPE_WRAPPER(struct cftype, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.open);
        WRAP_FUNCTION(arg.open);
        WRAP_FUNCTION(arg.read);
        WRAP_FUNCTION(arg.read_u64);
        WRAP_FUNCTION(arg.read_s64);
        WRAP_FUNCTION(arg.read_map);
        WRAP_FUNCTION(arg.read_seq_string);
        WRAP_FUNCTION(arg.write);
        WRAP_FUNCTION(arg.write_u64);
        WRAP_FUNCTION(arg.write_s64);
        WRAP_FUNCTION(arg.write_string);
        WRAP_FUNCTION(arg.trigger);
        WRAP_FUNCTION(arg.release);
        WRAP_FUNCTION(arg.register_event);
        WRAP_FUNCTION(arg.unregister_event);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_cftype_set
#ifndef WRAPPER_FOR_struct_cftype_set
#define WRAPPER_FOR_struct_cftype_set
TYPE_WRAPPER(struct cftype_set, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.cfts);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_cgroup_subsys
#ifndef WRAPPER_FOR_struct_cgroup_subsys
#define WRAPPER_FOR_struct_cgroup_subsys
TYPE_WRAPPER(struct cgroup_subsys, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.css_alloc);
        WRAP_FUNCTION(arg.css_alloc);
        WRAP_FUNCTION(arg.css_online);
        WRAP_FUNCTION(arg.css_offline);
        WRAP_FUNCTION(arg.css_free);
        WRAP_FUNCTION(arg.can_attach);
        WRAP_FUNCTION(arg.cancel_attach);
        WRAP_FUNCTION(arg.attach);
        WRAP_FUNCTION(arg.fork);
        WRAP_FUNCTION(arg.exit);
        WRAP_FUNCTION(arg.bind);
        WRAP_RECURSIVE(arg.idr);
        WRAP_RECURSIVE(arg.base_cftypes);
        WRAP_RECURSIVE(arg.base_cftset);
        WRAP_RECURSIVE(arg.module);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_vm_struct
#ifndef WRAPPER_FOR_struct_vm_struct
#define WRAPPER_FOR_struct_vm_struct
TYPE_WRAPPER(struct vm_struct, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.next);
        WRAP_RECURSIVE(arg.pages);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ida
#ifndef WRAPPER_FOR_struct_ida
#define WRAPPER_FOR_struct_ida
TYPE_WRAPPER(struct ida, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.idr);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_acpi_device_dir
#ifndef WRAPPER_FOR_struct_acpi_device_dir
#define WRAPPER_FOR_struct_acpi_device_dir
TYPE_WRAPPER(struct acpi_device_dir, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.entry);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_acpi_device_ops
#ifndef WRAPPER_FOR_struct_acpi_device_ops
#define WRAPPER_FOR_struct_acpi_device_ops
TYPE_WRAPPER(struct acpi_device_ops, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.add);
        WRAP_FUNCTION(arg.remove);
        WRAP_FUNCTION(arg.start);
        WRAP_FUNCTION(arg.bind);
        WRAP_FUNCTION(arg.unbind);
        WRAP_FUNCTION(arg.notify);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_acpi_driver
#ifndef WRAPPER_FOR_struct_acpi_driver
#define WRAPPER_FOR_struct_acpi_driver
TYPE_WRAPPER(struct acpi_driver, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.ops);
        WRAP_RECURSIVE(arg.drv);
        WRAP_RECURSIVE(arg.owner);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_acpi_device
#ifndef WRAPPER_FOR_struct_acpi_device
#define WRAPPER_FOR_struct_acpi_device
TYPE_WRAPPER(struct acpi_device, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.parent);
        WRAP_RECURSIVE(arg.dir);
        WRAP_RECURSIVE(arg.ops);
        WRAP_RECURSIVE(arg.driver);
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.physical_node_lock);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pnp_protocol
#ifndef WRAPPER_FOR_struct_pnp_protocol
#define WRAPPER_FOR_struct_pnp_protocol
TYPE_WRAPPER(struct pnp_protocol, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.get);
        WRAP_FUNCTION(arg.get);
        WRAP_FUNCTION(arg.set);
        WRAP_FUNCTION(arg.disable);
        WRAP_FUNCTION(arg.can_wakeup);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.resume);
        WRAP_RECURSIVE(arg.dev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pnp_card
#ifndef WRAPPER_FOR_struct_pnp_card
#define WRAPPER_FOR_struct_pnp_card
TYPE_WRAPPER(struct pnp_card, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.protocol);
        WRAP_RECURSIVE(arg.procdir);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pnp_driver
#ifndef WRAPPER_FOR_struct_pnp_driver
#define WRAPPER_FOR_struct_pnp_driver
TYPE_WRAPPER(struct pnp_driver, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.probe);
        WRAP_FUNCTION(arg.probe);
        WRAP_FUNCTION(arg.remove);
        WRAP_FUNCTION(arg.shutdown);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.resume);
        WRAP_RECURSIVE(arg.driver);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pnp_card_driver
#ifndef WRAPPER_FOR_struct_pnp_card_driver
#define WRAPPER_FOR_struct_pnp_card_driver
TYPE_WRAPPER(struct pnp_card_driver, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.probe);
        WRAP_FUNCTION(arg.probe);
        WRAP_FUNCTION(arg.remove);
        WRAP_FUNCTION(arg.suspend);
        WRAP_FUNCTION(arg.resume);
        WRAP_RECURSIVE(arg.link);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pnp_card_link
#ifndef WRAPPER_FOR_struct_pnp_card_link
#define WRAPPER_FOR_struct_pnp_card_link
TYPE_WRAPPER(struct pnp_card_link, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.card);
        WRAP_RECURSIVE(arg.driver);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pnp_dev
#ifndef WRAPPER_FOR_struct_pnp_dev
#define WRAPPER_FOR_struct_pnp_dev
TYPE_WRAPPER(struct pnp_dev, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.protocol);
        WRAP_RECURSIVE(arg.card);
        WRAP_RECURSIVE(arg.driver);
        WRAP_RECURSIVE(arg.card_link);
        WRAP_RECURSIVE(arg.procent);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_tasklet_struct
#ifndef WRAPPER_FOR_struct_tasklet_struct
#define WRAPPER_FOR_struct_tasklet_struct
TYPE_WRAPPER(struct tasklet_struct, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.func);
        WRAP_RECURSIVE(arg.next);
        WRAP_FUNCTION(arg.func);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_tasklet_hrtimer
#ifndef WRAPPER_FOR_struct_tasklet_hrtimer
#define WRAPPER_FOR_struct_tasklet_hrtimer
TYPE_WRAPPER(struct tasklet_hrtimer, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.function);
        WRAP_RECURSIVE(arg.timer);
        WRAP_RECURSIVE(arg.tasklet);
        WRAP_FUNCTION(arg.function);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_subprocess_info
#ifndef WRAPPER_FOR_struct_subprocess_info
#define WRAPPER_FOR_struct_subprocess_info
TYPE_WRAPPER(struct subprocess_info, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.init);
        WRAP_RECURSIVE(arg.work);
        WRAP_FUNCTION(arg.init);
        WRAP_FUNCTION(arg.cleanup);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pci_host_bridge
#ifndef WRAPPER_FOR_struct_pci_host_bridge
#define WRAPPER_FOR_struct_pci_host_bridge
TYPE_WRAPPER(struct pci_host_bridge, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.release_fn);
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.bus);
        WRAP_FUNCTION(arg.release_fn);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_firmware
#ifndef WRAPPER_FOR_struct_firmware
#define WRAPPER_FOR_struct_firmware
TYPE_WRAPPER(struct firmware, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.pages);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_cyclecounter
#ifndef WRAPPER_FOR_struct_cyclecounter
#define WRAPPER_FOR_struct_cyclecounter
TYPE_WRAPPER(struct cyclecounter, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.read);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_timecounter
#ifndef WRAPPER_FOR_struct_timecounter
#define WRAPPER_FOR_struct_timecounter
TYPE_WRAPPER(struct timecounter, {
    NO_PRE
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_cdrom_device_ops
#ifndef WRAPPER_FOR_struct_cdrom_device_ops
#define WRAPPER_FOR_struct_cdrom_device_ops
TYPE_WRAPPER(struct cdrom_device_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.open);
        WRAP_FUNCTION(arg.open);
        WRAP_FUNCTION(arg.release);
        WRAP_FUNCTION(arg.drive_status);
        WRAP_FUNCTION(arg.check_events);
        WRAP_FUNCTION(arg.media_changed);
        WRAP_FUNCTION(arg.tray_move);
        WRAP_FUNCTION(arg.lock_door);
        WRAP_FUNCTION(arg.select_speed);
        WRAP_FUNCTION(arg.select_disc);
        WRAP_FUNCTION(arg.get_last_session);
        WRAP_FUNCTION(arg.get_mcn);
        WRAP_FUNCTION(arg.reset);
        WRAP_FUNCTION(arg.audio_ioctl);
        WRAP_FUNCTION(arg.generic_packet);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_cdrom_device_info
#ifndef WRAPPER_FOR_struct_cdrom_device_info
#define WRAPPER_FOR_struct_cdrom_device_info
TYPE_WRAPPER(struct cdrom_device_info, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.exit);
        WRAP_RECURSIVE(arg.ops);
        WRAP_RECURSIVE(arg.disk);
        WRAP_FUNCTION(arg.exit);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_kthread_worker
#ifndef WRAPPER_FOR_struct_kthread_worker
#define WRAPPER_FOR_struct_kthread_worker
TYPE_WRAPPER(struct kthread_worker, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.task);
        WRAP_RECURSIVE(arg.current_work);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_kthread_work
#ifndef WRAPPER_FOR_struct_kthread_work
#define WRAPPER_FOR_struct_kthread_work
TYPE_WRAPPER(struct kthread_work, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.func);
        WRAP_RECURSIVE(arg.worker);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_klist
#ifndef WRAPPER_FOR_struct_klist
#define WRAPPER_FOR_struct_klist
TYPE_WRAPPER(struct klist, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.get);
        WRAP_FUNCTION(arg.get);
        WRAP_FUNCTION(arg.put);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_tp_module
#ifndef WRAPPER_FOR_struct_tp_module
#define WRAPPER_FOR_struct_tp_module
TYPE_WRAPPER(struct tp_module, {
    NO_PRE
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_tracepoint_iter
#ifndef WRAPPER_FOR_struct_tracepoint_iter
#define WRAPPER_FOR_struct_tracepoint_iter
TYPE_WRAPPER(struct tracepoint_iter, {
    NO_PRE
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct___wait_queue
#ifndef WRAPPER_FOR_struct___wait_queue
#define WRAPPER_FOR_struct___wait_queue
TYPE_WRAPPER(struct __wait_queue, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.func);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_poll_table_entry
#ifndef WRAPPER_FOR_struct_poll_table_entry
#define WRAPPER_FOR_struct_poll_table_entry
TYPE_WRAPPER(struct poll_table_entry, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.filp);
        WRAP_RECURSIVE(arg.wait);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_poll_wqueues
#ifndef WRAPPER_FOR_struct_poll_wqueues
#define WRAPPER_FOR_struct_poll_wqueues
TYPE_WRAPPER(struct poll_wqueues, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.pt);
        WRAP_RECURSIVE(arg.polling_task);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_hrtimer_sleeper
#ifndef WRAPPER_FOR_struct_hrtimer_sleeper
#define WRAPPER_FOR_struct_hrtimer_sleeper
TYPE_WRAPPER(struct hrtimer_sleeper, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.timer);
        WRAP_RECURSIVE(arg.task);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_mii_if_info
#ifndef WRAPPER_FOR_struct_mii_if_info
#define WRAPPER_FOR_struct_mii_if_info
TYPE_WRAPPER(struct mii_if_info, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.mdio_read);
        WRAP_RECURSIVE(arg.dev);
        WRAP_FUNCTION(arg.mdio_read);
        WRAP_FUNCTION(arg.mdio_write);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_blk_plug_cb
#ifndef WRAPPER_FOR_struct_blk_plug_cb
#define WRAPPER_FOR_struct_blk_plug_cb
TYPE_WRAPPER(struct blk_plug_cb, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.callback);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_rtnl_af_ops
#ifndef WRAPPER_FOR_struct_rtnl_af_ops
#define WRAPPER_FOR_struct_rtnl_af_ops
TYPE_WRAPPER(struct rtnl_af_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.fill_link_af);
        WRAP_FUNCTION(arg.fill_link_af);
        WRAP_FUNCTION(arg.get_link_af_size);
        WRAP_FUNCTION(arg.validate_link_af);
        WRAP_FUNCTION(arg.set_link_af);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_class_interface
#ifndef WRAPPER_FOR_struct_class_interface
#define WRAPPER_FOR_struct_class_interface
TYPE_WRAPPER(struct class_interface, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.add_dev);
        WRAP_RECURSIVE(arg.class_);
        WRAP_FUNCTION(arg.add_dev);
        WRAP_FUNCTION(arg.remove_dev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_scm_cookie
#ifndef WRAPPER_FOR_struct_scm_cookie
#define WRAPPER_FOR_struct_scm_cookie
TYPE_WRAPPER(struct scm_cookie, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.pid);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_irq_chip_type
#ifndef WRAPPER_FOR_struct_irq_chip_type
#define WRAPPER_FOR_struct_irq_chip_type
TYPE_WRAPPER(struct irq_chip_type, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.chip);
        WRAP_FUNCTION(arg.handler);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_bio_pair
#ifndef WRAPPER_FOR_struct_bio_pair
#define WRAPPER_FOR_struct_bio_pair
TYPE_WRAPPER(struct bio_pair, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.bio1);
        WRAP_RECURSIVE(arg.bio2);
        WRAP_RECURSIVE(arg.bv1);
        WRAP_RECURSIVE(arg.bv2);
        WRAP_RECURSIVE(arg.bip1);
        WRAP_RECURSIVE(arg.bip2);
        WRAP_RECURSIVE(arg.iv1);
        WRAP_RECURSIVE(arg.iv2);
    }
    NO_RETURN
})
#endif


//#define WRAPPER_FOR_struct_dm_dev
#ifndef WRAPPER_FOR_struct_dm_dev
#define WRAPPER_FOR_struct_dm_dev
TYPE_WRAPPER(struct dm_dev, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.bdev);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_target_type
#ifndef WRAPPER_FOR_struct_target_type
#define WRAPPER_FOR_struct_target_type
TYPE_WRAPPER(struct target_type, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.module);
        WRAP_FUNCTION(arg.ctr);
        WRAP_FUNCTION(arg.dtr);
        WRAP_FUNCTION(arg.map);
        WRAP_FUNCTION(arg.map_rq);
        WRAP_FUNCTION(arg.end_io);
        WRAP_FUNCTION(arg.rq_end_io);
        WRAP_FUNCTION(arg.presuspend);
        WRAP_FUNCTION(arg.postsuspend);
        WRAP_FUNCTION(arg.preresume);
        WRAP_FUNCTION(arg.resume);
        WRAP_FUNCTION(arg.status);
        WRAP_FUNCTION(arg.message);
        WRAP_FUNCTION(arg.ioctl);
        WRAP_FUNCTION(arg.merge);
        WRAP_FUNCTION(arg.busy);
        WRAP_FUNCTION(arg.iterate_devices);
        WRAP_FUNCTION(arg.io_hints);
    }
    NO_RETURN
})
#endif


//#define WRAPPER_FOR_struct_dm_target
#ifndef WRAPPER_FOR_struct_dm_target
#define WRAPPER_FOR_struct_dm_target
TYPE_WRAPPER(struct dm_target, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.type);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_sg_mapping_iter
#ifndef WRAPPER_FOR_struct_sg_mapping_iter
#define WRAPPER_FOR_struct_sg_mapping_iter
TYPE_WRAPPER(struct sg_mapping_iter, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.page);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_pernet_operations
#ifndef WRAPPER_FOR_struct_pernet_operations
#define WRAPPER_FOR_struct_pernet_operations
TYPE_WRAPPER(struct pernet_operations, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.init);
        WRAP_FUNCTION(arg.init);
        WRAP_FUNCTION(arg.exit);
        WRAP_FUNCTION(arg.exit_batch);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_acpi_bus_type
#ifndef WRAPPER_FOR_struct_acpi_bus_type
#define WRAPPER_FOR_struct_acpi_bus_type
TYPE_WRAPPER(struct acpi_bus_type, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.find_device);
        WRAP_RECURSIVE(arg.bus);
        WRAP_FUNCTION(arg.find_device);
        WRAP_FUNCTION(arg.find_bridge);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_shash_desc
#ifndef WRAPPER_FOR_struct_shash_desc
#define WRAPPER_FOR_struct_shash_desc
TYPE_WRAPPER(struct shash_desc, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.tfm);
    }
    NO_RETURN
})
#endif


//#define WRAPPER_FOR_struct_dm_target_callbacks
#ifndef WRAPPER_FOR_struct_dm_target_callbacks
#define WRAPPER_FOR_struct_dm_target_callbacks
TYPE_WRAPPER(struct dm_target_callbacks, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.congested_fn);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_skb_seq_state
#ifndef WRAPPER_FOR_struct_skb_seq_state
#define WRAPPER_FOR_struct_skb_seq_state
TYPE_WRAPPER(struct skb_seq_state, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.root_skb);
        WRAP_RECURSIVE(arg.cur_skb);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_qtree_fmt_operations
#ifndef WRAPPER_FOR_struct_qtree_fmt_operations
#define WRAPPER_FOR_struct_qtree_fmt_operations
TYPE_WRAPPER(struct qtree_fmt_operations, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.mem2disk_dqblk);
        WRAP_FUNCTION(arg.mem2disk_dqblk);
        WRAP_FUNCTION(arg.disk2mem_dqblk);
        WRAP_FUNCTION(arg.is_id);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_qtree_mem_dqinfo
#ifndef WRAPPER_FOR_struct_qtree_mem_dqinfo
#define WRAPPER_FOR_struct_qtree_mem_dqinfo
TYPE_WRAPPER(struct qtree_mem_dqinfo, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dqi_sb);
        WRAP_RECURSIVE(arg.dqi_ops);
    }
    NO_RETURN
})
#endif


#if defined(CAN_WRAP_kobject_set_name) && CAN_WRAP_kobject_set_name
#ifndef WRAPPER_FOR_kobject_set_name
FUNCTION_WRAPPER(kobject_set_name, (int), (struct kobject *kobj, const char *name, ...), {
    va_list args__;
    va_start(args__, name);
    WRAP_RECURSIVE(kobj);
    // TODO: variadic arguments
    D( granary_fault(); )
    int ret = kobject_set_name(kobj, name);
    va_end(args__);
    return ret;
})
#endif
#endif


#define WRAPPER_FOR_struct_srcu_notifier_head
#ifndef WRAPPER_FOR_struct_srcu_notifier_head
#define WRAPPER_FOR_struct_srcu_notifier_head
TYPE_WRAPPER(struct srcu_notifier_head, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.mutex);
        WRAP_RECURSIVE(arg.srcu);
        WRAP_RECURSIVE(arg.head);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ata_port_info
#ifndef WRAPPER_FOR_struct_ata_port_info
#define WRAPPER_FOR_struct_ata_port_info
TYPE_WRAPPER(struct ata_port_info, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.port_ops);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_exec_domain
#ifndef WRAPPER_FOR_struct_exec_domain
#define WRAPPER_FOR_struct_exec_domain
TYPE_WRAPPER(struct exec_domain, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.handler);
        WRAP_RECURSIVE(arg.module);
        WRAP_RECURSIVE(arg.next);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_fastopen_queue
#ifndef WRAPPER_FOR_struct_fastopen_queue
#define WRAPPER_FOR_struct_fastopen_queue
TYPE_WRAPPER(struct fastopen_queue, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.rskq_rst_head);
        WRAP_RECURSIVE(arg.rskq_rst_tail);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_request_sock_queue
#ifndef WRAPPER_FOR_struct_request_sock_queue
#define WRAPPER_FOR_struct_request_sock_queue
TYPE_WRAPPER(struct request_sock_queue, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.rskq_accept_head);
        WRAP_RECURSIVE(arg.rskq_accept_tail);
        WRAP_RECURSIVE(arg.fastopenq);
    }
    NO_RETURN
})
#endif


#if defined(CAN_WRAP_dynamic_dname) && CAN_WRAP_dynamic_dname
#ifndef WRAPPER_FOR_dynamic_dname
FUNCTION_WRAPPER(dynamic_dname, (char *), (struct dentry *_arg1, char *_arg2, int _arg3, const char *_arg4, ...), {
    va_list args__;
    va_start(args__, _arg4);
    WRAP_RECURSIVE(_arg1);
    // TODO: variadic arguments
    D( granary_fault(); )
    char *ret = dynamic_dname(_arg1, _arg2, _arg3, _arg4);
    va_end(args__);
    RETURN_IN_WRAP(ret);
    return ret;
})
#endif
#endif


#define WRAPPER_FOR_struct_nf_sockopt_ops
#ifndef WRAPPER_FOR_struct_nf_sockopt_ops
#define WRAPPER_FOR_struct_nf_sockopt_ops
TYPE_WRAPPER(struct nf_sockopt_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.set);
        WRAP_FUNCTION(arg.set);
        WRAP_FUNCTION(arg.compat_set);
        WRAP_FUNCTION(arg.get);
        WRAP_FUNCTION(arg.compat_get);
        WRAP_RECURSIVE(arg.owner);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_packet_type
#ifndef WRAPPER_FOR_struct_packet_type
#define WRAPPER_FOR_struct_packet_type
TYPE_WRAPPER(struct packet_type, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.func);
        WRAP_RECURSIVE(arg.dev);
        WRAP_FUNCTION(arg.func);
        WRAP_FUNCTION(arg.id_match);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_klist_iter
#ifndef WRAPPER_FOR_struct_klist_iter
#define WRAPPER_FOR_struct_klist_iter
TYPE_WRAPPER(struct klist_iter, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.i_klist);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_node
#ifndef WRAPPER_FOR_struct_node
#define WRAPPER_FOR_struct_node
TYPE_WRAPPER(struct node, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.dev);
        WRAP_RECURSIVE(arg.node_work);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_atomic_notifier_head
#ifndef WRAPPER_FOR_struct_atomic_notifier_head
#define WRAPPER_FOR_struct_atomic_notifier_head
TYPE_WRAPPER(struct atomic_notifier_head, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.head);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_nf_afinfo
#ifndef WRAPPER_FOR_struct_nf_afinfo
#define WRAPPER_FOR_struct_nf_afinfo
TYPE_WRAPPER(struct nf_afinfo, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.checksum);
        WRAP_FUNCTION(arg.checksum);
        WRAP_FUNCTION(arg.checksum_partial);
        WRAP_FUNCTION(arg.route);
        WRAP_FUNCTION(arg.saveroute);
        WRAP_FUNCTION(arg.reroute);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_qdisc_watchdog
#ifndef WRAPPER_FOR_struct_qdisc_watchdog
#define WRAPPER_FOR_struct_qdisc_watchdog
TYPE_WRAPPER(struct qdisc_watchdog, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.timer);
        WRAP_RECURSIVE(arg.qdisc);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_preempt_ops
#ifndef WRAPPER_FOR_struct_preempt_ops
#define WRAPPER_FOR_struct_preempt_ops
TYPE_WRAPPER(struct preempt_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.sched_in);
        WRAP_FUNCTION(arg.sched_in);
        WRAP_FUNCTION(arg.sched_out);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_preempt_notifier
#ifndef WRAPPER_FOR_struct_preempt_notifier
#define WRAPPER_FOR_struct_preempt_notifier
TYPE_WRAPPER(struct preempt_notifier, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.ops);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ptr_heap
#ifndef WRAPPER_FOR_struct_ptr_heap
#define WRAPPER_FOR_struct_ptr_heap
TYPE_WRAPPER(struct ptr_heap, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.gt);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dma_page_list
#ifndef WRAPPER_FOR_struct_dma_page_list
#define WRAPPER_FOR_struct_dma_page_list
TYPE_WRAPPER(struct dma_page_list, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.pages);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_wait_bit_queue
#ifndef WRAPPER_FOR_struct_wait_bit_queue
#define WRAPPER_FOR_struct_wait_bit_queue
TYPE_WRAPPER(struct wait_bit_queue, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.wait);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_tick_device
#ifndef WRAPPER_FOR_struct_tick_device
#define WRAPPER_FOR_struct_tick_device
TYPE_WRAPPER(struct tick_device, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.evtdev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_class_dev_iter
#ifndef WRAPPER_FOR_struct_class_dev_iter
#define WRAPPER_FOR_struct_class_dev_iter
TYPE_WRAPPER(struct class_dev_iter, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.ki);
    }
    NO_POST
    NO_RETURN
})
#endif


#if defined(CAN_WRAP_bdi_register) && CAN_WRAP_bdi_register
#ifndef WRAPPER_FOR_bdi_register
FUNCTION_WRAPPER(bdi_register, (int), (struct backing_dev_info *bdi, struct device *parent, const char *fmt, ...), {
    va_list args__;
    va_start(args__, fmt);
    WRAP_RECURSIVE(bdi);
    WRAP_RECURSIVE(parent);
    // TODO: variadic arguments
    D( granary_fault(); )
    int ret = bdi_register(bdi, parent, fmt);
    va_end(args__);
    return ret;
})
#endif
#endif


#if defined(CAN_WRAP_kobject_add) && CAN_WRAP_kobject_add
#ifndef WRAPPER_FOR_kobject_add
FUNCTION_WRAPPER(kobject_add, (int), (struct kobject *kobj, struct kobject *parent, const char *fmt, ...), {
    va_list args__;
    va_start(args__, fmt);
    WRAP_RECURSIVE(kobj);
    WRAP_RECURSIVE(parent);
    // TODO: variadic arguments
    D( granary_fault(); )
    int ret = kobject_add(kobj, parent, fmt);
    va_end(args__);
    return ret;
})
#endif
#endif


#define WRAPPER_FOR_struct_acpi_pci_root
#ifndef WRAPPER_FOR_struct_acpi_pci_root
#define WRAPPER_FOR_struct_acpi_pci_root
TYPE_WRAPPER(struct acpi_pci_root, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.device);
        WRAP_RECURSIVE(arg.bus);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_acpi_pci_driver
#ifndef WRAPPER_FOR_struct_acpi_pci_driver
#define WRAPPER_FOR_struct_acpi_pci_driver
TYPE_WRAPPER(struct acpi_pci_driver, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.add);
        WRAP_FUNCTION(arg.add);
        WRAP_FUNCTION(arg.remove);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_mm_walk
#ifndef WRAPPER_FOR_struct_mm_walk
#define WRAPPER_FOR_struct_mm_walk
TYPE_WRAPPER(struct mm_walk, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.pgd_entry);
        WRAP_FUNCTION(arg.pgd_entry);
        WRAP_FUNCTION(arg.pud_entry);
        WRAP_FUNCTION(arg.pmd_entry);
        WRAP_FUNCTION(arg.pte_entry);
        WRAP_FUNCTION(arg.pte_hole);
        WRAP_FUNCTION(arg.hugetlb_entry);
        WRAP_RECURSIVE(arg.mm);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_restart_block
#ifndef WRAPPER_FOR_struct_restart_block
#define WRAPPER_FOR_struct_restart_block
TYPE_WRAPPER(struct restart_block, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.fn);
    }
    NO_RETURN
})
#endif


#if defined(CAN_WRAP___ata_ehi_push_desc) && CAN_WRAP___ata_ehi_push_desc && defined(DETACH_ADDR___ata_ehi_push_desc)
#ifndef WRAPPER_FOR___ata_ehi_push_desc
FUNCTION_WRAPPER_VOID(__ata_ehi_push_desc,(struct ata_eh_info *ehi, const char *fmt, ...), {
    va_list args__;
    va_start(args__, fmt);
    WRAP_RECURSIVE(ehi);
    // TODO: variadic arguments
    D( granary_fault(); )
    __ata_ehi_push_desc(ehi, fmt);
    va_end(args__);
})
#endif
#endif


#define WRAPPER_FOR_struct_tick_sched
#ifndef WRAPPER_FOR_struct_tick_sched
#define WRAPPER_FOR_struct_tick_sched
TYPE_WRAPPER(struct tick_sched, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.sched_timer);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_ahash_request
#ifndef WRAPPER_FOR_struct_ahash_request
#define WRAPPER_FOR_struct_ahash_request
TYPE_WRAPPER(struct ahash_request, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.base);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_subsys_interface
#ifndef WRAPPER_FOR_struct_subsys_interface
#define WRAPPER_FOR_struct_subsys_interface
TYPE_WRAPPER(struct subsys_interface, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.add_dev);
        WRAP_RECURSIVE(arg.subsys);
        WRAP_FUNCTION(arg.add_dev);
        WRAP_FUNCTION(arg.remove_dev);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_dmi_system_id
#ifndef WRAPPER_FOR_struct_dmi_system_id
#define WRAPPER_FOR_struct_dmi_system_id
TYPE_WRAPPER(struct dmi_system_id, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.callback);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_disk_part_iter
#ifndef WRAPPER_FOR_struct_disk_part_iter
#define WRAPPER_FOR_struct_disk_part_iter
TYPE_WRAPPER(struct disk_part_iter, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.disk);
        WRAP_RECURSIVE(arg.part);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_Sector
#ifndef WRAPPER_FOR_Sector
#define WRAPPER_FOR_Sector
TYPE_WRAPPER(Sector, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.v);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_execute_work
#ifndef WRAPPER_FOR_struct_execute_work
#define WRAPPER_FOR_struct_execute_work
TYPE_WRAPPER(struct execute_work, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.work);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_crypto_ahash
#ifndef WRAPPER_FOR_struct_crypto_ahash
#define WRAPPER_FOR_struct_crypto_ahash
TYPE_WRAPPER(struct crypto_ahash, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.init);
        WRAP_FUNCTION(arg.init);
        WRAP_FUNCTION(arg.update);
        WRAP_FUNCTION(arg.final);
        WRAP_FUNCTION(arg.finup);
        WRAP_FUNCTION(arg.digest);
        WRAP_FUNCTION(arg.export_);
        WRAP_FUNCTION(arg.import);
        WRAP_FUNCTION(arg.setkey);
        WRAP_RECURSIVE(arg.base);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_subsys_dev_iter
#ifndef WRAPPER_FOR_struct_subsys_dev_iter
#define WRAPPER_FOR_struct_subsys_dev_iter
TYPE_WRAPPER(struct subsys_dev_iter, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.ki);
    }
    NO_POST
    NO_RETURN
})
#endif


#if defined(CAN_WRAP_ata_port_desc) && CAN_WRAP_ata_port_desc
#ifndef WRAPPER_FOR_ata_port_desc
FUNCTION_WRAPPER_VOID(ata_port_desc,(struct ata_port *ap, const char *fmt, ...), {
    va_list args__;
    va_start(args__, fmt);
    WRAP_RECURSIVE(ap);
    // TODO: variadic arguments
    D( granary_fault(); )
    ata_port_desc(ap, fmt);
    va_end(args__);
})
#endif
#endif


#define WRAPPER_FOR_struct_net_proto_family
#ifndef WRAPPER_FOR_struct_net_proto_family
#define WRAPPER_FOR_struct_net_proto_family
TYPE_WRAPPER(struct net_proto_family, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.create);
        WRAP_FUNCTION(arg.create);
        WRAP_RECURSIVE(arg.owner);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_acpi_dock_ops
#ifndef WRAPPER_FOR_struct_acpi_dock_ops
#define WRAPPER_FOR_struct_acpi_dock_ops
TYPE_WRAPPER(struct acpi_dock_ops, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.handler);
        WRAP_FUNCTION(arg.uevent);
    }
    NO_RETURN
})
#endif


#if defined(CAN_WRAP_kthread_create_on_node) && CAN_WRAP_kthread_create_on_node
#ifndef WRAPPER_FOR_kthread_create_on_node
FUNCTION_WRAPPER(kthread_create_on_node, (struct task_struct *), (int (*threadfn)(void *), void *data, int node, const char namefmt[], ...), {
    va_list args__;
    va_start(args__, namefmt);
    WRAP_FUNCTION(threadfn);
    // TODO: variadic arguments
    D( granary_fault(); )
    struct task_struct *ret = kthread_create_on_node(threadfn, data, node, namefmt);
    va_end(args__);
    RETURN_IN_WRAP(ret);
    return ret;
})
#endif
#endif


#define WRAPPER_FOR_struct_tree_descr
#ifndef WRAPPER_FOR_struct_tree_descr
#define WRAPPER_FOR_struct_tree_descr
TYPE_WRAPPER(struct tree_descr, {
    NO_PRE
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_security_operations
#ifndef WRAPPER_FOR_struct_security_operations
#define WRAPPER_FOR_struct_security_operations
TYPE_WRAPPER(struct security_operations, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.ptrace_access_check);
        WRAP_FUNCTION(arg.ptrace_access_check);
        WRAP_FUNCTION(arg.ptrace_traceme);
        WRAP_FUNCTION(arg.capget);
        WRAP_FUNCTION(arg.capset);
        WRAP_FUNCTION(arg.capable);
        WRAP_FUNCTION(arg.quotactl);
        WRAP_FUNCTION(arg.quota_on);
        WRAP_FUNCTION(arg.syslog);
        WRAP_FUNCTION(arg.settime);
        WRAP_FUNCTION(arg.vm_enough_memory);
        WRAP_FUNCTION(arg.bprm_set_creds);
        WRAP_FUNCTION(arg.bprm_check_security);
        WRAP_FUNCTION(arg.bprm_secureexec);
        WRAP_FUNCTION(arg.bprm_committing_creds);
        WRAP_FUNCTION(arg.bprm_committed_creds);
        WRAP_FUNCTION(arg.sb_alloc_security);
        WRAP_FUNCTION(arg.sb_free_security);
        WRAP_FUNCTION(arg.sb_copy_data);
        WRAP_FUNCTION(arg.sb_remount);
        WRAP_FUNCTION(arg.sb_kern_mount);
        WRAP_FUNCTION(arg.sb_show_options);
        WRAP_FUNCTION(arg.sb_statfs);
        WRAP_FUNCTION(arg.sb_mount);
        WRAP_FUNCTION(arg.sb_umount);
        WRAP_FUNCTION(arg.sb_pivotroot);
        WRAP_FUNCTION(arg.sb_set_mnt_opts);
        WRAP_FUNCTION(arg.sb_clone_mnt_opts);
        WRAP_FUNCTION(arg.sb_parse_opts_str);
        WRAP_FUNCTION(arg.path_unlink);
        WRAP_FUNCTION(arg.path_mkdir);
        WRAP_FUNCTION(arg.path_rmdir);
        WRAP_FUNCTION(arg.path_mknod);
        WRAP_FUNCTION(arg.path_truncate);
        WRAP_FUNCTION(arg.path_symlink);
        WRAP_FUNCTION(arg.path_link);
        WRAP_FUNCTION(arg.path_rename);
        WRAP_FUNCTION(arg.path_chmod);
        WRAP_FUNCTION(arg.path_chown);
        WRAP_FUNCTION(arg.path_chroot);
        WRAP_FUNCTION(arg.inode_alloc_security);
        WRAP_FUNCTION(arg.inode_free_security);
        WRAP_FUNCTION(arg.inode_init_security);
        WRAP_FUNCTION(arg.inode_create);
        WRAP_FUNCTION(arg.inode_link);
        WRAP_FUNCTION(arg.inode_unlink);
        WRAP_FUNCTION(arg.inode_symlink);
        WRAP_FUNCTION(arg.inode_mkdir);
        WRAP_FUNCTION(arg.inode_rmdir);
        WRAP_FUNCTION(arg.inode_mknod);
        WRAP_FUNCTION(arg.inode_rename);
        WRAP_FUNCTION(arg.inode_readlink);
        WRAP_FUNCTION(arg.inode_follow_link);
        WRAP_FUNCTION(arg.inode_permission);
        WRAP_FUNCTION(arg.inode_setattr);
        WRAP_FUNCTION(arg.inode_getattr);
        WRAP_FUNCTION(arg.inode_setxattr);
        WRAP_FUNCTION(arg.inode_post_setxattr);
        WRAP_FUNCTION(arg.inode_getxattr);
        WRAP_FUNCTION(arg.inode_listxattr);
        WRAP_FUNCTION(arg.inode_removexattr);
        WRAP_FUNCTION(arg.inode_need_killpriv);
        WRAP_FUNCTION(arg.inode_killpriv);
        WRAP_FUNCTION(arg.inode_getsecurity);
        WRAP_FUNCTION(arg.inode_setsecurity);
        WRAP_FUNCTION(arg.inode_listsecurity);
        WRAP_FUNCTION(arg.inode_getsecid);
        WRAP_FUNCTION(arg.file_permission);
        WRAP_FUNCTION(arg.file_alloc_security);
        WRAP_FUNCTION(arg.file_free_security);
        WRAP_FUNCTION(arg.file_ioctl);
        WRAP_FUNCTION(arg.mmap_addr);
        WRAP_FUNCTION(arg.mmap_file);
        WRAP_FUNCTION(arg.file_mprotect);
        WRAP_FUNCTION(arg.file_lock);
        WRAP_FUNCTION(arg.file_fcntl);
        WRAP_FUNCTION(arg.file_set_fowner);
        WRAP_FUNCTION(arg.file_send_sigiotask);
        WRAP_FUNCTION(arg.file_receive);
        WRAP_FUNCTION(arg.file_open);
        WRAP_FUNCTION(arg.task_create);
        WRAP_FUNCTION(arg.task_free);
        WRAP_FUNCTION(arg.cred_alloc_blank);
        WRAP_FUNCTION(arg.cred_free);
        WRAP_FUNCTION(arg.cred_prepare);
        WRAP_FUNCTION(arg.cred_transfer);
        WRAP_FUNCTION(arg.kernel_act_as);
        WRAP_FUNCTION(arg.kernel_create_files_as);
        WRAP_FUNCTION(arg.kernel_module_request);
        WRAP_FUNCTION(arg.kernel_module_from_file);
        WRAP_FUNCTION(arg.task_fix_setuid);
        WRAP_FUNCTION(arg.task_setpgid);
        WRAP_FUNCTION(arg.task_getpgid);
        WRAP_FUNCTION(arg.task_getsid);
        WRAP_FUNCTION(arg.task_getsecid);
        WRAP_FUNCTION(arg.task_setnice);
        WRAP_FUNCTION(arg.task_setioprio);
        WRAP_FUNCTION(arg.task_getioprio);
        WRAP_FUNCTION(arg.task_setrlimit);
        WRAP_FUNCTION(arg.task_setscheduler);
        WRAP_FUNCTION(arg.task_getscheduler);
        WRAP_FUNCTION(arg.task_movememory);
        WRAP_FUNCTION(arg.task_kill);
        WRAP_FUNCTION(arg.task_wait);
        WRAP_FUNCTION(arg.task_prctl);
        WRAP_FUNCTION(arg.task_to_inode);
        WRAP_FUNCTION(arg.ipc_permission);
        WRAP_FUNCTION(arg.ipc_getsecid);
        WRAP_FUNCTION(arg.msg_msg_alloc_security);
        WRAP_FUNCTION(arg.msg_msg_free_security);
        WRAP_FUNCTION(arg.msg_queue_alloc_security);
        WRAP_FUNCTION(arg.msg_queue_free_security);
        WRAP_FUNCTION(arg.msg_queue_associate);
        WRAP_FUNCTION(arg.msg_queue_msgctl);
        WRAP_FUNCTION(arg.msg_queue_msgsnd);
        WRAP_FUNCTION(arg.msg_queue_msgrcv);
        WRAP_FUNCTION(arg.shm_alloc_security);
        WRAP_FUNCTION(arg.shm_free_security);
        WRAP_FUNCTION(arg.shm_associate);
        WRAP_FUNCTION(arg.shm_shmctl);
        WRAP_FUNCTION(arg.shm_shmat);
        WRAP_FUNCTION(arg.sem_alloc_security);
        WRAP_FUNCTION(arg.sem_free_security);
        WRAP_FUNCTION(arg.sem_associate);
        WRAP_FUNCTION(arg.sem_semctl);
        WRAP_FUNCTION(arg.sem_semop);
        WRAP_FUNCTION(arg.netlink_send);
        WRAP_FUNCTION(arg.d_instantiate);
        WRAP_FUNCTION(arg.getprocattr);
        WRAP_FUNCTION(arg.setprocattr);
        WRAP_FUNCTION(arg.secid_to_secctx);
        WRAP_FUNCTION(arg.secctx_to_secid);
        WRAP_FUNCTION(arg.release_secctx);
        WRAP_FUNCTION(arg.inode_notifysecctx);
        WRAP_FUNCTION(arg.inode_setsecctx);
        WRAP_FUNCTION(arg.inode_getsecctx);
        WRAP_FUNCTION(arg.unix_stream_connect);
        WRAP_FUNCTION(arg.unix_may_send);
        WRAP_FUNCTION(arg.socket_create);
        WRAP_FUNCTION(arg.socket_post_create);
        WRAP_FUNCTION(arg.socket_bind);
        WRAP_FUNCTION(arg.socket_connect);
        WRAP_FUNCTION(arg.socket_listen);
        WRAP_FUNCTION(arg.socket_accept);
        WRAP_FUNCTION(arg.socket_sendmsg);
        WRAP_FUNCTION(arg.socket_recvmsg);
        WRAP_FUNCTION(arg.socket_getsockname);
        WRAP_FUNCTION(arg.socket_getpeername);
        WRAP_FUNCTION(arg.socket_getsockopt);
        WRAP_FUNCTION(arg.socket_setsockopt);
        WRAP_FUNCTION(arg.socket_shutdown);
        WRAP_FUNCTION(arg.socket_sock_rcv_skb);
        WRAP_FUNCTION(arg.socket_getpeersec_stream);
        WRAP_FUNCTION(arg.socket_getpeersec_dgram);
        WRAP_FUNCTION(arg.sk_alloc_security);
        WRAP_FUNCTION(arg.sk_free_security);
        WRAP_FUNCTION(arg.sk_clone_security);
        WRAP_FUNCTION(arg.sk_getsecid);
        WRAP_FUNCTION(arg.sock_graft);
        WRAP_FUNCTION(arg.inet_conn_request);
        WRAP_FUNCTION(arg.inet_csk_clone);
        WRAP_FUNCTION(arg.inet_conn_established);
        WRAP_FUNCTION(arg.secmark_relabel_packet);
        WRAP_FUNCTION(arg.secmark_refcount_inc);
        WRAP_FUNCTION(arg.secmark_refcount_dec);
        WRAP_FUNCTION(arg.req_classify_flow);
        WRAP_FUNCTION(arg.tun_dev_alloc_security);
        WRAP_FUNCTION(arg.tun_dev_free_security);
        WRAP_FUNCTION(arg.tun_dev_create);
        WRAP_FUNCTION(arg.tun_dev_attach_queue);
        WRAP_FUNCTION(arg.tun_dev_attach);
        WRAP_FUNCTION(arg.tun_dev_open);
        WRAP_FUNCTION(arg.key_alloc);
        WRAP_FUNCTION(arg.key_free);
        WRAP_FUNCTION(arg.key_permission);
        WRAP_FUNCTION(arg.key_getsecurity);
        WRAP_FUNCTION(arg.audit_rule_init);
        WRAP_FUNCTION(arg.audit_rule_known);
        WRAP_FUNCTION(arg.audit_rule_match);
        WRAP_FUNCTION(arg.audit_rule_free);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_cgroup_scanner
#ifndef WRAPPER_FOR_struct_cgroup_scanner
#define WRAPPER_FOR_struct_cgroup_scanner
TYPE_WRAPPER(struct cgroup_scanner, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.test_task);
        WRAP_RECURSIVE(arg.cg);
        WRAP_FUNCTION(arg.test_task);
        WRAP_FUNCTION(arg.process_task);
        WRAP_RECURSIVE(arg.heap);
    }
    NO_RETURN
})
#endif


#if defined(CAN_WRAP_device_create) && CAN_WRAP_device_create
#ifndef WRAPPER_FOR_device_create
FUNCTION_WRAPPER(device_create, (struct device *), (struct class_ *cls, struct device *parent, dev_t devt, void *drvdata, const char *fmt, ...), {
    va_list args__;
    va_start(args__, fmt);
    WRAP_RECURSIVE(cls);
    WRAP_RECURSIVE(parent);
    // TODO: variadic arguments
    D( granary_fault(); )
    struct device *ret = device_create(cls, parent, devt, drvdata, fmt);
    va_end(args__);
    RETURN_IN_WRAP(ret);
    return ret;
})
#endif
#endif


#define WRAPPER_FOR_struct_offload_callbacks
#ifndef WRAPPER_FOR_struct_offload_callbacks
#define WRAPPER_FOR_struct_offload_callbacks
TYPE_WRAPPER(struct offload_callbacks, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.gso_segment);
        WRAP_FUNCTION(arg.gso_segment);
        WRAP_FUNCTION(arg.gso_send_check);
        WRAP_FUNCTION(arg.gro_receive);
        WRAP_FUNCTION(arg.gro_complete);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_packet_offload
#ifndef WRAPPER_FOR_struct_packet_offload
#define WRAPPER_FOR_struct_packet_offload
TYPE_WRAPPER(struct packet_offload, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.callbacks);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_flow_cache_ops
#ifndef WRAPPER_FOR_struct_flow_cache_ops
#define WRAPPER_FOR_struct_flow_cache_ops
TYPE_WRAPPER(struct flow_cache_ops, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.get);
        WRAP_FUNCTION(arg.get);
        WRAP_FUNCTION(arg.check);
        WRAP_FUNCTION(arg.delete_);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_flow_cache_object
#ifndef WRAPPER_FOR_struct_flow_cache_object
#define WRAPPER_FOR_struct_flow_cache_object
TYPE_WRAPPER(struct flow_cache_object, {
    NO_PRE
    NO_POST
    NO_RETURN
})
#endif


#if defined(CAN_WRAP___module_put_and_exit) && CAN_WRAP___module_put_and_exit && defined(DETACH_ADDR___module_put_and_exit)
#ifndef WRAPPER_FOR___module_put_and_exit
FUNCTION_WRAPPER_VOID(__module_put_and_exit,(struct module *mod, long code), {
    WRAP_RECURSIVE(mod);
    D( granary_fault(); )
    __module_put_and_exit(mod, code);
})
#endif
#endif


#if defined(CAN_WRAP_kobject_init_and_add) && CAN_WRAP_kobject_init_and_add
#ifndef WRAPPER_FOR_kobject_init_and_add
FUNCTION_WRAPPER(kobject_init_and_add, (int), (struct kobject *kobj, struct kobj_type *ktype, struct kobject *parent, const char *fmt, ...), {
    va_list args__;
    va_start(args__, fmt);
    WRAP_RECURSIVE(kobj);
    WRAP_RECURSIVE(ktype);
    WRAP_RECURSIVE(parent);
    // TODO: variadic arguments
    D( granary_fault(); )
    int ret = kobject_init_and_add(kobj, ktype, parent, fmt);
    va_end(args__);
    return ret;
})
#endif
#endif


#define WRAPPER_FOR_struct_zap_details
#ifndef WRAPPER_FOR_struct_zap_details
#define WRAPPER_FOR_struct_zap_details
TYPE_WRAPPER(struct zap_details, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.nonlinear_vma);
        WRAP_RECURSIVE(arg.check_mapping);
    }
    NO_RETURN
})
#endif


#if defined(CAN_WRAP_ata_ehi_push_desc) && CAN_WRAP_ata_ehi_push_desc
#ifndef WRAPPER_FOR_ata_ehi_push_desc
FUNCTION_WRAPPER_VOID(ata_ehi_push_desc,(struct ata_eh_info *ehi, const char *fmt, ...), {
    va_list args__;
    va_start(args__, fmt);
    WRAP_RECURSIVE(ehi);
    // TODO: variadic arguments
    D( granary_fault(); )
    ata_ehi_push_desc(ehi, fmt);
    va_end(args__);
})
#endif
#endif


#define WRAPPER_FOR_struct_netlink_dump_control
#ifndef WRAPPER_FOR_struct_netlink_dump_control
#define WRAPPER_FOR_struct_netlink_dump_control
TYPE_WRAPPER(struct netlink_dump_control, {
    PRE_WRAP {
        ABORT_IF_FUNCTION_IS_WRAPPED(arg.dump);
        WRAP_FUNCTION(arg.dump);
        WRAP_FUNCTION(arg.done);
        WRAP_RECURSIVE(arg.module);
    }
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_miscdevice
#ifndef WRAPPER_FOR_struct_miscdevice
#define WRAPPER_FOR_struct_miscdevice
TYPE_WRAPPER(struct miscdevice, {
    PRE_WRAP {
        WRAP_RECURSIVE(arg.parent);
        WRAP_RECURSIVE(arg.this_device);
    }
    NO_POST
    NO_RETURN
})
#endif


#define WRAPPER_FOR_struct_softirq_action
#ifndef WRAPPER_FOR_struct_softirq_action
#define WRAPPER_FOR_struct_softirq_action
TYPE_WRAPPER(struct softirq_action, {
    PRE_WRAP {
        WRAP_FUNCTION(arg.action);
    }
    NO_RETURN
})
#endif


#if defined(CAN_WRAP_dev_set_name) && CAN_WRAP_dev_set_name
#ifndef WRAPPER_FOR_dev_set_name
FUNCTION_WRAPPER(dev_set_name, (int), (struct device *dev, const char *name, ...), {
    va_list args__;
    va_start(args__, name);
    WRAP_RECURSIVE(dev);
    // TODO: variadic arguments
    D( granary_fault(); )
    int ret = dev_set_name(dev, name);
    va_end(args__);
    return ret;
})
#endif
#endif


