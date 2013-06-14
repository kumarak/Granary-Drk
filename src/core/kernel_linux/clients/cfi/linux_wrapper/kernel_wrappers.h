/* Auto-generated wrappers. */
#define D(...) //__VA_ARGS__

#ifndef WRAPPER_FOR_struct_callback_head
#define WRAPPER_FOR_struct_callback_head
TYPE_WRAPPER(struct callback_head*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct callback_head\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct callback_head));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->func);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_nameidata
#define WRAPPER_FOR_struct_nameidata
TYPE_WRAPPER(struct nameidata*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct nameidata\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct nameidata));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->path);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->root);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->inode);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_iattr
#define WRAPPER_FOR_struct_iattr
TYPE_WRAPPER(struct iattr*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct iattr\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct iattr));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ia_file);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_inode_operations
#define WRAPPER_FOR_struct_inode_operations
TYPE_WRAPPER(struct inode_operations*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct inode_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct inode_operations));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->lookup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->follow_link);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->permission);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_acl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->readlink);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->put_link);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->create);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->link);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->unlink);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->symlink);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mkdir);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rmdir);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mknod);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rename);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setattr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getattr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setxattr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getxattr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->listxattr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->removexattr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fiemap);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->update_time);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->atomic_open);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_kset_uevent_ops
#define WRAPPER_FOR_struct_kset_uevent_ops
TYPE_WRAPPER(struct kset_uevent_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct kset_uevent_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct kset_uevent_ops));
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_kset
#define WRAPPER_FOR_struct_kset
TYPE_WRAPPER(struct kset*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct kset\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct kset));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->kobj);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_sysfs_ops
#define WRAPPER_FOR_struct_sysfs_ops
TYPE_WRAPPER(struct sysfs_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct sysfs_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct sysfs_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->show);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->store);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->namespace_);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_kobj_ns_type_operations
#define WRAPPER_FOR_struct_kobj_ns_type_operations
TYPE_WRAPPER(struct kobj_ns_type_operations*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct kobj_ns_type_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct kobj_ns_type_operations));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->grab_current_ns);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->netlink_ns);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->initial_ns);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->drop_ns);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_kobj_type
#define WRAPPER_FOR_struct_kobj_type
TYPE_WRAPPER(struct kobj_type*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct kobj_type\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct kobj_type));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->child_ns_type);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->namespace_);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_kobject
#define WRAPPER_FOR_struct_kobject
TYPE_WRAPPER(struct kobject*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct kobject\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct kobject));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->parent);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ktype);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_module_kobject
#define WRAPPER_FOR_struct_module_kobject
TYPE_WRAPPER(struct module_kobject*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct module_kobject\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct module_kobject));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->kobj);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mod);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->drivers_dir);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_module_attribute
#define WRAPPER_FOR_struct_module_attribute
TYPE_WRAPPER(struct module_attribute*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct module_attribute\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct module_attribute));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->show);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->store);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->test);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->free);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_kernel_param_ops
#define WRAPPER_FOR_struct_kernel_param_ops
TYPE_WRAPPER(struct kernel_param_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct kernel_param_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct kernel_param_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->free);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_kparam_array
#define WRAPPER_FOR_struct_kparam_array
TYPE_WRAPPER(struct kparam_array*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct kparam_array\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct kparam_array));
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_kernel_param
#define WRAPPER_FOR_struct_kernel_param
TYPE_WRAPPER(struct kernel_param*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct kernel_param\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct kernel_param));
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_sched_class
#define WRAPPER_FOR_struct_sched_class
TYPE_WRAPPER(struct sched_class*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct sched_class\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct sched_class));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->enqueue_task);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dequeue_task);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->yield_task);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->yield_to_task);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->check_preempt_curr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pick_next_task);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->put_prev_task);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->select_task_rq);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->migrate_task_rq);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pre_schedule);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->post_schedule);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->task_waking);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->task_woken);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_cpus_allowed);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rq_online);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rq_offline);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_curr_task);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->task_tick);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->task_fork);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->switched_from);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->switched_to);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->prio_changed);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_rr_interval);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->task_move_group);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_mutex
#define WRAPPER_FOR_struct_mutex
TYPE_WRAPPER(struct mutex*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct mutex\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct mutex));
	     WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_attribute_group
#define WRAPPER_FOR_struct_attribute_group
TYPE_WRAPPER(struct attribute_group*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct attribute_group\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct attribute_group));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->is_visible);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dev_pm_ops
#define WRAPPER_FOR_struct_dev_pm_ops
TYPE_WRAPPER(struct dev_pm_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dev_pm_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dev_pm_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->prepare);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->complete);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->suspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->freeze);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->thaw);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->poweroff);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->restore);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->suspend_late);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume_early);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->freeze_late);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->thaw_early);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->poweroff_late);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->restore_early);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->suspend_noirq);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume_noirq);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->freeze_noirq);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->thaw_noirq);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->poweroff_noirq);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->restore_noirq);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->runtime_suspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->runtime_resume);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->runtime_idle);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_device_type
#define WRAPPER_FOR_struct_device_type
TYPE_WRAPPER(struct device_type*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct device_type\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct device_type));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->uevent);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->devnode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_bus_attribute
#define WRAPPER_FOR_struct_bus_attribute
TYPE_WRAPPER(struct bus_attribute*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct bus_attribute\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct bus_attribute));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->show);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->store);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_device_attribute
#define WRAPPER_FOR_struct_device_attribute
TYPE_WRAPPER(struct device_attribute*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct device_attribute\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct device_attribute));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->show);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->store);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_device_driver
#define WRAPPER_FOR_struct_device_driver
TYPE_WRAPPER(struct device_driver*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct device_driver\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct device_driver));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bus);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->probe);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->remove);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->shutdown);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->suspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_driver_attribute
#define WRAPPER_FOR_struct_driver_attribute
TYPE_WRAPPER(struct driver_attribute*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct driver_attribute\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct driver_attribute));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->show);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->store);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_bus_type
#define WRAPPER_FOR_struct_bus_type
TYPE_WRAPPER(struct bus_type*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct bus_type\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct bus_type));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev_root);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bus_attrs);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev_attrs);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->drv_attrs);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->match);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->uevent);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->probe);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->remove);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->shutdown);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->suspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_timer_list
#define WRAPPER_FOR_struct_timer_list
TYPE_WRAPPER(struct timer_list*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct timer_list\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct timer_list));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->function);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_wakeup_source
#define WRAPPER_FOR_struct_wakeup_source
TYPE_WRAPPER(struct wakeup_source*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct wakeup_source\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct wakeup_source));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->timer);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_work_struct
#define WRAPPER_FOR_struct_work_struct
TYPE_WRAPPER(struct work_struct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct work_struct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct work_struct));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->func);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_notifier_block
#define WRAPPER_FOR_struct_notifier_block
TYPE_WRAPPER(struct notifier_block*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct notifier_block\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct notifier_block));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->notifier_call);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_blocking_notifier_head
#define WRAPPER_FOR_struct_blocking_notifier_head
TYPE_WRAPPER(struct blocking_notifier_head*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct blocking_notifier_head\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct blocking_notifier_head));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->head);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pm_qos_constraints
#define WRAPPER_FOR_struct_pm_qos_constraints
TYPE_WRAPPER(struct pm_qos_constraints*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pm_qos_constraints\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pm_qos_constraints));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->notifiers);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dev_pm_qos_request
#define WRAPPER_FOR_struct_dev_pm_qos_request
TYPE_WRAPPER(struct dev_pm_qos_request*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dev_pm_qos_request\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dev_pm_qos_request));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dev_pm_qos
#define WRAPPER_FOR_struct_dev_pm_qos
TYPE_WRAPPER(struct dev_pm_qos*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dev_pm_qos\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dev_pm_qos));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->latency);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->latency_req);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->flags_req);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dev_pm_info
#define WRAPPER_FOR_struct_dev_pm_info
TYPE_WRAPPER(struct dev_pm_info*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dev_pm_info\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dev_pm_info));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->wakeup);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->suspend_timer);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->work);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->qos);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dev_pm_domain
#define WRAPPER_FOR_struct_dev_pm_domain
TYPE_WRAPPER(struct dev_pm_domain*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dev_pm_domain\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dev_pm_domain));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ops);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dma_map_ops
#define WRAPPER_FOR_struct_dma_map_ops
TYPE_WRAPPER(struct dma_map_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dma_map_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dma_map_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->alloc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->free);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mmap);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_sgtable);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->map_page);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->unmap_page);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->map_sg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->unmap_sg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sync_single_for_cpu);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sync_single_for_device);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sync_sg_for_cpu);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sync_sg_for_device);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mapping_error);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dma_supported);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_dma_mask);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dev_archdata
#define WRAPPER_FOR_struct_dev_archdata
TYPE_WRAPPER(struct dev_archdata*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dev_archdata\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dev_archdata));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dma_ops);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_class_attribute
#define WRAPPER_FOR_struct_class_attribute
TYPE_WRAPPER(struct class_attribute*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct class_attribute\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct class_attribute));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->show);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->store);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->namespace_);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_bin_attribute
#define WRAPPER_FOR_struct_bin_attribute
TYPE_WRAPPER(struct bin_attribute*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct bin_attribute\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct bin_attribute));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mmap);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_class_
#define WRAPPER_FOR_struct_class_
TYPE_WRAPPER(struct class_*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct class_\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct class_));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->class_attrs);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev_attrs);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev_bin_attrs);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev_kobj);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dev_uevent);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->devnode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->class_release);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dev_release);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->suspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->namespace_);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_device
#define WRAPPER_FOR_struct_device
TYPE_WRAPPER(struct device*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct device\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct device));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->parent);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->kobj);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mutex);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bus);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->driver);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->power);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pm_domain);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->archdata);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->class_);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_hd_struct
#define WRAPPER_FOR_struct_hd_struct
TYPE_WRAPPER(struct hd_struct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct hd_struct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct hd_struct));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->__dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->holder_dir);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->callback_head);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_disk_part_tbl
#define WRAPPER_FOR_struct_disk_part_tbl
TYPE_WRAPPER(struct disk_part_tbl*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct disk_part_tbl\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct disk_part_tbl));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->callback_head);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->last_lookup);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_block_device_operations
#define WRAPPER_FOR_struct_block_device_operations
TYPE_WRAPPER(struct block_device_operations*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct block_device_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct block_device_operations));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->open);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ioctl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->compat_ioctl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->direct_access);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->check_events);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->media_changed);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->unlock_native_capacity);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->revalidate_disk);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getgeo);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->swap_slot_free_notify);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_call_single_data
#define WRAPPER_FOR_struct_call_single_data
TYPE_WRAPPER(struct call_single_data*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct call_single_data\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct call_single_data));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->func);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_kmem_cache_cpu
#define WRAPPER_FOR_struct_kmem_cache_cpu
TYPE_WRAPPER(struct kmem_cache_cpu*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct kmem_cache_cpu\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct kmem_cache_cpu));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->page);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->partial);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_kmem_cache
#define WRAPPER_FOR_struct_kmem_cache
TYPE_WRAPPER(struct kmem_cache*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct kmem_cache\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct kmem_cache));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->cpu_slab);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ctor);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->kobj);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_io_cq
#define WRAPPER_FOR_struct_io_cq
TYPE_WRAPPER(struct io_cq*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct io_cq\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct io_cq));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->q);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ioc);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_io_context
#define WRAPPER_FOR_struct_io_context
TYPE_WRAPPER(struct io_context*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct io_context\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct io_context));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->icq_hint);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->release_work);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cgroup
#define WRAPPER_FOR_struct_cgroup
TYPE_WRAPPER(struct cgroup*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cgroup\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cgroup));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->parent);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dentry);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->top_cgroup);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pidlist_mutex);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->callback_head);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cgroup_subsys_state
#define WRAPPER_FOR_struct_cgroup_subsys_state
TYPE_WRAPPER(struct cgroup_subsys_state*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cgroup_subsys_state\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cgroup_subsys_state));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->cgroup);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dput_work);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_bio_vec
#define WRAPPER_FOR_struct_bio_vec
TYPE_WRAPPER(struct bio_vec*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct bio_vec\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct bio_vec));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bv_page);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_bio_integrity_payload
#define WRAPPER_FOR_struct_bio_integrity_payload
TYPE_WRAPPER(struct bio_integrity_payload*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct bio_integrity_payload\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct bio_integrity_payload));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bip_bio);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bip_end_io);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bip_work);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_mempool_s
#define WRAPPER_FOR_struct_mempool_s
TYPE_WRAPPER(struct mempool_s*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct mempool_s\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct mempool_s));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->alloc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->free);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_bio_set
#define WRAPPER_FOR_struct_bio_set
TYPE_WRAPPER(struct bio_set*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct bio_set\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct bio_set));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bio_slab);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bio_pool);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bio_integrity_pool);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bvec_pool);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_bio
#define WRAPPER_FOR_struct_bio
TYPE_WRAPPER(struct bio*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct bio\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct bio));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bi_next);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bi_bdev);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bi_end_io);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bi_ioc);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bi_css);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bi_integrity);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bi_io_vec);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bi_pool);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_request_list
#define WRAPPER_FOR_struct_request_list
TYPE_WRAPPER(struct request_list*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct request_list\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct request_list));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->q);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rq_pool);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_request
#define WRAPPER_FOR_struct_request
TYPE_WRAPPER(struct request*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct request\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct request));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->csd);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->q);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bio);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->biotail);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rq_disk);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->part);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->end_io);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next_rq);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_elevator_ops
#define WRAPPER_FOR_struct_elevator_ops
TYPE_WRAPPER(struct elevator_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct elevator_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct elevator_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_merge_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_merged_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_merge_req_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_allow_merge_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_bio_merged_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_dispatch_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_add_req_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_activate_req_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_deactivate_req_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_completed_req_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_former_req_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_latter_req_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_init_icq_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_exit_icq_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_set_req_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_put_req_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_may_queue_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_init_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->elevator_exit_fn);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_elv_fs_entry
#define WRAPPER_FOR_struct_elv_fs_entry
TYPE_WRAPPER(struct elv_fs_entry*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct elv_fs_entry\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct elv_fs_entry));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->show);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->store);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_elevator_type
#define WRAPPER_FOR_struct_elevator_type
TYPE_WRAPPER(struct elevator_type*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct elevator_type\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct elevator_type));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->icq_cache);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->elevator_attrs);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->elevator_owner);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_elevator_queue
#define WRAPPER_FOR_struct_elevator_queue
TYPE_WRAPPER(struct elevator_queue*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct elevator_queue\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct elevator_queue));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->type);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->kobj);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sysfs_lock);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_bvec_merge_data
#define WRAPPER_FOR_struct_bvec_merge_data
TYPE_WRAPPER(struct bvec_merge_data*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct bvec_merge_data\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct bvec_merge_data));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bi_bdev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_delayed_work
#define WRAPPER_FOR_struct_delayed_work
TYPE_WRAPPER(struct delayed_work*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct delayed_work\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct delayed_work));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->work);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->timer);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_bdi_writeback
#define WRAPPER_FOR_struct_bdi_writeback
TYPE_WRAPPER(struct bdi_writeback*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct bdi_writeback\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct bdi_writeback));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bdi);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->task);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->wakeup_timer);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_backing_dev_info
#define WRAPPER_FOR_struct_backing_dev_info
TYPE_WRAPPER(struct backing_dev_info*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct backing_dev_info\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct backing_dev_info));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->congested_fn);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->wb);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->laptop_mode_wb_timer);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->debug_dir);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->debug_stats);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_blk_queue_tag
#define WRAPPER_FOR_struct_blk_queue_tag
TYPE_WRAPPER(struct blk_queue_tag*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct blk_queue_tag\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct blk_queue_tag));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tag_index);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_bsg_class_device
#define WRAPPER_FOR_struct_bsg_class_device
TYPE_WRAPPER(struct bsg_class_device*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct bsg_class_device\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct bsg_class_device));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->class_dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->parent);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->queue);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_request_queue
#define WRAPPER_FOR_struct_request_queue
TYPE_WRAPPER(struct request_queue*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct request_queue\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct request_queue));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->last_merge);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->elevator);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->root_rl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->request_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->make_request_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->prep_rq_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->unprep_rq_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->merge_bvec_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->softirq_done_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rq_timed_out_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dma_drain_needed);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->lld_busy_fn);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->boundary_rq);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->delay_work);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->backing_dev_info);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->kobj);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->queue_tags);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->timeout);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->flush_rq);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sysfs_lock);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bsg_job_fn);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bsg_dev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_blk_integrity
#define WRAPPER_FOR_struct_blk_integrity
TYPE_WRAPPER(struct blk_integrity*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct blk_integrity\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct blk_integrity));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->generate_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->verify_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_tag_fn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_tag_fn);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->kobj);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_gendisk
#define WRAPPER_FOR_struct_gendisk
TYPE_WRAPPER(struct gendisk*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct gendisk\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct gendisk));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->devnode);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->part_tbl);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->part0);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->driverfs_dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->slave_dir);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->integrity);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_block_device
#define WRAPPER_FOR_struct_block_device
TYPE_WRAPPER(struct block_device*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct block_device\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct block_device));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_inode);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_super);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_mutex);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_contains);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_part);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_disk);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bd_fsfreeze_mutex);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_swap_info_struct
#define WRAPPER_FOR_struct_swap_info_struct
TYPE_WRAPPER(struct swap_info_struct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct swap_info_struct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct swap_info_struct));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bdev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->swap_file);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_address_space_operations
#define WRAPPER_FOR_struct_address_space_operations
TYPE_WRAPPER(struct address_space_operations*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct address_space_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct address_space_operations));
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
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct address_space\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct address_space));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->host);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_mmap_mutex);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->backing_dev_info);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_page
#define WRAPPER_FOR_struct_page
TYPE_WRAPPER(struct page*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct page\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct page));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mapping);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_vm_fault
#define WRAPPER_FOR_struct_vm_fault
TYPE_WRAPPER(struct vm_fault*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct vm_fault\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct vm_fault));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->page);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_vm_operations_struct
#define WRAPPER_FOR_struct_vm_operations_struct
TYPE_WRAPPER(struct vm_operations_struct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct vm_operations_struct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct vm_operations_struct));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->open);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->close);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fault);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->page_mkwrite);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->access);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_policy);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_policy);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->migrate);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->remap_pages);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_vm_area_struct
#define WRAPPER_FOR_struct_vm_area_struct
TYPE_WRAPPER(struct vm_area_struct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct vm_area_struct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct vm_area_struct));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->vm_next);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->vm_mm);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->vm_file);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_mm_context_t
#define WRAPPER_FOR_mm_context_t
TYPE_WRAPPER(mm_context_t*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrappermm_context_t\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(mm_context_t));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->lock);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_core_thread
#define WRAPPER_FOR_struct_core_thread
TYPE_WRAPPER(struct core_thread*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct core_thread\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct core_thread));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->task);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_core_state
#define WRAPPER_FOR_struct_core_state
TYPE_WRAPPER(struct core_state*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct core_state\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct core_state));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dumper);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_mm_struct
#define WRAPPER_FOR_struct_mm_struct
TYPE_WRAPPER(struct mm_struct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct mm_struct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct mm_struct));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mmap);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mmap_cache);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_unmapped_area);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->unmap_area);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->context);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->core_state);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->exe_file);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pmd_huge_pte);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pid
#define WRAPPER_FOR_struct_pid
TYPE_WRAPPER(struct pid*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pid\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pid));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rcu);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pid_link
#define WRAPPER_FOR_struct_pid_link
TYPE_WRAPPER(struct pid_link*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pid_link\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pid_link));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pid);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cred
#define WRAPPER_FOR_struct_cred
TYPE_WRAPPER(struct cred*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cred\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cred));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rcu);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_poll_table_struct
#define WRAPPER_FOR_struct_poll_table_struct
TYPE_WRAPPER(struct poll_table_struct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct poll_table_struct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct poll_table_struct));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->_qproc);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_fasync_struct
#define WRAPPER_FOR_struct_fasync_struct
TYPE_WRAPPER(struct fasync_struct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct fasync_struct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct fasync_struct));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->fa_next);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->fa_file);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->fa_rcu);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_file_lock_operations
#define WRAPPER_FOR_struct_file_lock_operations
TYPE_WRAPPER(struct file_lock_operations*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct file_lock_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct file_lock_operations));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fl_copy_lock);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fl_release_private);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_lock_manager_operations
#define WRAPPER_FOR_struct_lock_manager_operations
TYPE_WRAPPER(struct lock_manager_operations*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct lock_manager_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct lock_manager_operations));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->lm_compare_owner);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->lm_notify);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->lm_grant);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->lm_break);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->lm_change);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_file_lock
#define WRAPPER_FOR_struct_file_lock
TYPE_WRAPPER(struct file_lock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct file_lock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct file_lock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->fl_next);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->fl_nspid);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->fl_file);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->fl_fasync);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_seq_operations
#define WRAPPER_FOR_struct_seq_operations
TYPE_WRAPPER(struct seq_operations*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct seq_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct seq_operations));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->start);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->stop);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->next);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->show);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_seq_file
#define WRAPPER_FOR_struct_seq_file
TYPE_WRAPPER(struct seq_file*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct seq_file\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct seq_file));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->lock);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_file_operations
#define WRAPPER_FOR_struct_file_operations
TYPE_WRAPPER(struct file_operations*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct file_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct file_operations));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->llseek);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->aio_read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->aio_write);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->readdir);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->poll);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->unlocked_ioctl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->compat_ioctl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mmap);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->open);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->flush);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fsync);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->aio_fsync);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fasync);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->lock);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sendpage);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_unmapped_area);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->check_flags);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->flock);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->splice_write);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->splice_read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setlease);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fallocate);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->show_fdinfo);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_proc_dir_entry
#define WRAPPER_FOR_struct_proc_dir_entry
TYPE_WRAPPER(struct proc_dir_entry*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct proc_dir_entry\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct proc_dir_entry));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_proc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_proc);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ctl_table
#define WRAPPER_FOR_struct_ctl_table
TYPE_WRAPPER(struct ctl_table*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ctl_table\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ctl_table));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->child);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->proc_handler);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ctl_table_root
#define WRAPPER_FOR_struct_ctl_table_root
TYPE_WRAPPER(struct ctl_table_root*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ctl_table_root\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ctl_table_root));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->default_set);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->lookup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->permissions);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ctl_node
#define WRAPPER_FOR_struct_ctl_node
TYPE_WRAPPER(struct ctl_node*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ctl_node\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ctl_node));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->header);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ctl_table_header
#define WRAPPER_FOR_struct_ctl_table_header
TYPE_WRAPPER(struct ctl_table_header*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ctl_table_header\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ctl_table_header));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ctl_table_arg);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->root);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->set);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->parent);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->node);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ctl_dir
#define WRAPPER_FOR_struct_ctl_dir
TYPE_WRAPPER(struct ctl_dir*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ctl_dir\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ctl_dir));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->header);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ctl_table_set
#define WRAPPER_FOR_struct_ctl_table_set
TYPE_WRAPPER(struct ctl_table_set*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ctl_table_set\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ctl_table_set));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->is_seen);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dir);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netns_core
#define WRAPPER_FOR_struct_netns_core
TYPE_WRAPPER(struct netns_core*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netns_core\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netns_core));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sysctl_hdr);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netns_mib
#define WRAPPER_FOR_struct_netns_mib
TYPE_WRAPPER(struct netns_mib*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netns_mib\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netns_mib));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->proc_net_devsnmp6);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netns_packet
#define WRAPPER_FOR_struct_netns_packet
TYPE_WRAPPER(struct netns_packet*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netns_packet\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netns_packet));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sklist_lock);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netns_unix
#define WRAPPER_FOR_struct_netns_unix
TYPE_WRAPPER(struct netns_unix*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netns_unix\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netns_unix));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ctl);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netns_ipv4
#define WRAPPER_FOR_struct_netns_ipv4
TYPE_WRAPPER(struct netns_ipv4*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netns_ipv4\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netns_ipv4));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->forw_hdr);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->frags_hdr);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ipv4_hdr);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->route_hdr);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->fibnl);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->icmp_sk);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netns_sysctl_ipv6
#define WRAPPER_FOR_struct_netns_sysctl_ipv6
TYPE_WRAPPER(struct netns_sysctl_ipv6*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netns_sysctl_ipv6\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netns_sysctl_ipv6));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->hdr);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->route_hdr);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->icmp_hdr);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->frags_hdr);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dst_entry
#define WRAPPER_FOR_struct_dst_entry
TYPE_WRAPPER(struct dst_entry*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dst_entry\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dst_entry));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->callback_head);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->child);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->path);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->from);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->input);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->output);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pneigh_entry
#define WRAPPER_FOR_struct_pneigh_entry
TYPE_WRAPPER(struct pneigh_entry*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pneigh_entry\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pneigh_entry));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->net);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_neigh_parms
#define WRAPPER_FOR_struct_neigh_parms
TYPE_WRAPPER(struct neigh_parms*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct neigh_parms\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct neigh_parms));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->net);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->neigh_setup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->neigh_cleanup);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tbl);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->callback_head);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_sk_buff_head
#define WRAPPER_FOR_struct_sk_buff_head
TYPE_WRAPPER(struct sk_buff_head*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct sk_buff_head\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct sk_buff_head));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->prev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_neigh_hash_table
#define WRAPPER_FOR_struct_neigh_hash_table
TYPE_WRAPPER(struct neigh_hash_table*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct neigh_hash_table\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct neigh_hash_table));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->hash_buckets);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rcu);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_neigh_table
#define WRAPPER_FOR_struct_neigh_table
TYPE_WRAPPER(struct neigh_table*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct neigh_table\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct neigh_table));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->hash);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->constructor);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pconstructor);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pdestructor);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->proxy_redo);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->parms);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->gc_work);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->proxy_timer);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->proxy_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->nht);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->phash_buckets);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_neigh_ops
#define WRAPPER_FOR_struct_neigh_ops
TYPE_WRAPPER(struct neigh_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct neigh_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct neigh_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->solicit);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->error_report);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->output);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->connected_output);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_neighbour
#define WRAPPER_FOR_struct_neighbour
TYPE_WRAPPER(struct neighbour*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct neighbour\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct neighbour));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tbl);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->parms);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->arp_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->timer);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->output);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rcu);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dst_ops
#define WRAPPER_FOR_struct_dst_ops
TYPE_WRAPPER(struct dst_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dst_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dst_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->gc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->check);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->default_advmss);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mtu);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cow_metrics);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->destroy);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ifdown);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->negative_advice);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->link_failure);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->update_pmtu);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->redirect);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->local_out);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->neigh_lookup);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->kmem_cachep);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netns_ipv6
#define WRAPPER_FOR_struct_netns_ipv6
TYPE_WRAPPER(struct netns_ipv6*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netns_ipv6\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netns_ipv6));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sysctl);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ip6_fib_timer);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ip6_dst_ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->icmp_sk);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ndisc_sk);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tcp_sk);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->igmp_sk);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netns_sctp
#define WRAPPER_FOR_struct_netns_sctp
TYPE_WRAPPER(struct netns_sctp*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netns_sctp\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netns_sctp));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->proc_net_sctp);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sysctl_header);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ctl_sock);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->addr_wq_timer);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netns_dccp
#define WRAPPER_FOR_struct_netns_dccp
TYPE_WRAPPER(struct netns_dccp*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netns_dccp\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netns_dccp));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->v4_ctl_sk);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->v6_ctl_sk);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_nf_proto_net
#define WRAPPER_FOR_struct_nf_proto_net
TYPE_WRAPPER(struct nf_proto_net*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct nf_proto_net\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct nf_proto_net));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ctl_table_header);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ctl_table);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ctl_compat_header);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ctl_compat_table);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_nf_generic_net
#define WRAPPER_FOR_struct_nf_generic_net
TYPE_WRAPPER(struct nf_generic_net*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct nf_generic_net\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct nf_generic_net));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pn);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_nf_tcp_net
#define WRAPPER_FOR_struct_nf_tcp_net
TYPE_WRAPPER(struct nf_tcp_net*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct nf_tcp_net\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct nf_tcp_net));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pn);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_nf_udp_net
#define WRAPPER_FOR_struct_nf_udp_net
TYPE_WRAPPER(struct nf_udp_net*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct nf_udp_net\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct nf_udp_net));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pn);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_nf_icmp_net
#define WRAPPER_FOR_struct_nf_icmp_net
TYPE_WRAPPER(struct nf_icmp_net*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct nf_icmp_net\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct nf_icmp_net));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pn);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_nf_ip_net
#define WRAPPER_FOR_struct_nf_ip_net
TYPE_WRAPPER(struct nf_ip_net*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct nf_ip_net\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct nf_ip_net));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->generic);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tcp);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->udp);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->icmp);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->icmpv6);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ctl_table_header);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ctl_table);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netns_ct
#define WRAPPER_FOR_struct_netns_ct
TYPE_WRAPPER(struct netns_ct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netns_ct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netns_ct));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->nf_conntrack_cachep);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->nf_ct_proto);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sysctl_header);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->acct_sysctl_header);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tstamp_sysctl_header);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->event_sysctl_header);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->helper_sysctl_header);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netns_nf_frag
#define WRAPPER_FOR_struct_netns_nf_frag
TYPE_WRAPPER(struct netns_nf_frag*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netns_nf_frag\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netns_nf_frag));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sysctl);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netns_xfrm
#define WRAPPER_FOR_struct_netns_xfrm
TYPE_WRAPPER(struct netns_xfrm*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netns_xfrm\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netns_xfrm));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->state_hash_work);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->state_gc_work);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->policy_hash_work);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->nlsk);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->nlsk_stash);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sysctl_hdr);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->xfrm4_dst_ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->xfrm6_dst_ops);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_net
#define WRAPPER_FOR_struct_net
TYPE_WRAPPER(struct net*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct net\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct net));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->proc_net);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->proc_net_stat);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sysctls);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rtnl);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->genl_sock);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->loopback_dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->core);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mib);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->packet);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->unx);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ipv4);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ipv6);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sctp);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dccp);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ct);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->nf_frag);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->nfnl);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->nfnl_stash);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->wext_nlevents);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->xfrm);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->diag_nlsk);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_nsproxy
#define WRAPPER_FOR_struct_nsproxy
TYPE_WRAPPER(struct nsproxy*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct nsproxy\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct nsproxy));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->net_ns);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_hrtimer_clock_base
#define WRAPPER_FOR_struct_hrtimer_clock_base
TYPE_WRAPPER(struct hrtimer_clock_base*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct hrtimer_clock_base\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct hrtimer_clock_base));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_time);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_hrtimer
#define WRAPPER_FOR_struct_hrtimer
TYPE_WRAPPER(struct hrtimer*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct hrtimer\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct hrtimer));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->function);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_signal_struct
#define WRAPPER_FOR_struct_signal_struct
TYPE_WRAPPER(struct signal_struct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct signal_struct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct signal_struct));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->curr_target);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->group_exit_task);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->real_timer);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->leader_pid);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tty_old_pgrp);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->cred_guard_mutex);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_sigaction
#define WRAPPER_FOR_struct_sigaction
TYPE_WRAPPER(struct sigaction*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct sigaction\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct sigaction));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sa_handler);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sa_restorer);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_k_sigaction
#define WRAPPER_FOR_struct_k_sigaction
TYPE_WRAPPER(struct k_sigaction*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct k_sigaction\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct k_sigaction));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sa);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_bio_list
#define WRAPPER_FOR_struct_bio_list
TYPE_WRAPPER(struct bio_list*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct bio_list\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct bio_list));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->head);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tail);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_css_set
#define WRAPPER_FOR_struct_css_set
TYPE_WRAPPER(struct css_set*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct css_set\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct css_set));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->callback_head);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_page_frag
#define WRAPPER_FOR_struct_page_frag
TYPE_WRAPPER(struct page_frag*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct page_frag\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct page_frag));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->page);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_task_struct
#define WRAPPER_FOR_struct_task_struct
TYPE_WRAPPER(struct task_struct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct task_struct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct task_struct));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mm);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->active_mm);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->real_parent);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->parent);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->group_leader);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->nsproxy);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->signal);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->notifier);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->task_works);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bio_list);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->backing_dev_info);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->io_context);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->cgroups);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->perf_event_mutex);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rcu);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->task_frag);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_module
#define WRAPPER_FOR_struct_module
TYPE_WRAPPER(struct module*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct module\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct module));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mkobj);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->modinfo_attrs);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->holders_dir);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->waiter);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->exit);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_file_system_type
#define WRAPPER_FOR_struct_file_system_type
TYPE_WRAPPER(struct file_system_type*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct file_system_type\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct file_system_type));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mount);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->kill_sb);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_super_operations
#define WRAPPER_FOR_struct_super_operations
TYPE_WRAPPER(struct super_operations*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct super_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct super_operations));
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
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dquot\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dquot));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dq_lock);
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
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dquot_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dquot_operations));
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
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct quotactl_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct quotactl_ops));
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
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct export_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct export_operations));
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


#ifndef WRAPPER_FOR_struct_xattr_handler
#define WRAPPER_FOR_struct_xattr_handler
TYPE_WRAPPER(struct xattr_handler*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct xattr_handler\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct xattr_handler));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->list);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_quota_format_ops
#define WRAPPER_FOR_struct_quota_format_ops
TYPE_WRAPPER(struct quota_format_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct quota_format_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct quota_format_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->check_quota_file);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_file_info);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_file_info);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->free_file_info);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_dqblk);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->commit_dqblk);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release_dqblk);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_quota_format_type
#define WRAPPER_FOR_struct_quota_format_type
TYPE_WRAPPER(struct quota_format_type*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct quota_format_type\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct quota_format_type));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->qf_owner);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->qf_next);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_mem_dqinfo
#define WRAPPER_FOR_struct_mem_dqinfo
TYPE_WRAPPER(struct mem_dqinfo*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct mem_dqinfo\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct mem_dqinfo));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dqi_format);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_quota_info
#define WRAPPER_FOR_struct_quota_info
TYPE_WRAPPER(struct quota_info*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct quota_info\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct quota_info));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dqio_mutex);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dqonoff_mutex);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dentry_operations
#define WRAPPER_FOR_struct_dentry_operations
TYPE_WRAPPER(struct dentry_operations*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dentry_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dentry_operations));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->d_revalidate);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->d_hash);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->d_compare);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->d_delete);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->d_release);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->d_prune);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->d_iput);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->d_dname);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->d_automount);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->d_manage);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_shrinker
#define WRAPPER_FOR_struct_shrinker
TYPE_WRAPPER(struct shrinker*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct shrinker\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct shrinker));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->shrink);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_super_block
#define WRAPPER_FOR_struct_super_block
TYPE_WRAPPER(struct super_block*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct super_block\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct super_block));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->s_type);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->s_root);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->s_bdev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->s_bdi);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->s_dquot);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->s_vfs_rename_mutex);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->s_shrink);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_inode
#define WRAPPER_FOR_struct_inode
TYPE_WRAPPER(struct inode*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct inode\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct inode));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_sb);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_mapping);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_mutex);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_flock);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_data);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dentry
#define WRAPPER_FOR_struct_dentry
TYPE_WRAPPER(struct dentry*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dentry\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dentry));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->d_parent);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->d_inode);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->d_sb);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_vfsmount
#define WRAPPER_FOR_struct_vfsmount
TYPE_WRAPPER(struct vfsmount*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct vfsmount\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct vfsmount));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mnt_root);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mnt_sb);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_path
#define WRAPPER_FOR_struct_path
TYPE_WRAPPER(struct path*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct path\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct path));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mnt);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dentry);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_fown_struct
#define WRAPPER_FOR_struct_fown_struct
TYPE_WRAPPER(struct fown_struct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct fown_struct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct fown_struct));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pid);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_file
#define WRAPPER_FOR_struct_file
TYPE_WRAPPER(struct file*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct file\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct file));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->f_path);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->f_owner);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->f_mapping);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_aio_ring_info
#define WRAPPER_FOR_struct_aio_ring_info
TYPE_WRAPPER(struct aio_ring_info*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct aio_ring_info\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct aio_ring_info));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ring_pages);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_kioctx
#define WRAPPER_FOR_struct_kioctx
TYPE_WRAPPER(struct kioctx*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct kioctx\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct kioctx));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mm);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ring_info);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->wq);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->callback_head);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_kiocb
#define WRAPPER_FOR_struct_kiocb
TYPE_WRAPPER(struct kiocb*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct kiocb\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct kiocb));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ki_filp);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ki_ctx);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ki_cancel);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ki_retry);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ki_dtor);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_request_sock
#define WRAPPER_FOR_struct_request_sock
TYPE_WRAPPER(struct request_sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct request_sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct request_sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dl_next);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_request_sock_ops
#define WRAPPER_FOR_struct_request_sock_ops
TYPE_WRAPPER(struct request_sock_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct request_sock_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct request_sock_ops));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->slab);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rtx_syn_ack);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->send_ack);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->send_reset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->destructor);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->syn_ack_timeout);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_timewait_sock_ops
#define WRAPPER_FOR_struct_timewait_sock_ops
TYPE_WRAPPER(struct timewait_sock_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct timewait_sock_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct timewait_sock_ops));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->twsk_slab);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->twsk_unique);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->twsk_destructor);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_proto
#define WRAPPER_FOR_struct_proto
TYPE_WRAPPER(struct proto*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct proto\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct proto));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->close);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->connect);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->disconnect);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->accept);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ioctl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->destroy);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->shutdown);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setsockopt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getsockopt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->compat_setsockopt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->compat_getsockopt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->compat_ioctl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sendmsg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->recvmsg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sendpage);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bind);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->backlog_rcv);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release_cb);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mtu_reduced);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->hash);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->unhash);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rehash);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_port);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->clear_sk);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->enter_memory_pressure);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->slab);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rsk_prot);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->twsk_prot);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_sock_common
#define WRAPPER_FOR_struct_sock_common
TYPE_WRAPPER(struct sock_common*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct sock_common\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct sock_common));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->skc_prot);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->skc_net);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_sk_filter
#define WRAPPER_FOR_struct_sk_filter
TYPE_WRAPPER(struct sk_filter*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct sk_filter\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct sk_filter));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bpf_func);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rcu);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_socket_wq
#define WRAPPER_FOR_struct_socket_wq
TYPE_WRAPPER(struct socket_wq*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct socket_wq\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct socket_wq));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->fasync_list);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rcu);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_proto_ops
#define WRAPPER_FOR_struct_proto_ops
TYPE_WRAPPER(struct proto_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct proto_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct proto_ops));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bind);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->connect);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->socketpair);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->accept);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getname);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->poll);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ioctl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->compat_ioctl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->listen);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->shutdown);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setsockopt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getsockopt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->compat_setsockopt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->compat_getsockopt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sendmsg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->recvmsg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mmap);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sendpage);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->splice_read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_peek_off);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_socket
#define WRAPPER_FOR_struct_socket
TYPE_WRAPPER(struct socket*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct socket\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct socket));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->wq);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->file);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cg_proto
#define WRAPPER_FOR_struct_cg_proto
TYPE_WRAPPER(struct cg_proto*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cg_proto\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cg_proto));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->enter_memory_pressure);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_sock
#define WRAPPER_FOR_struct_sock
TYPE_WRAPPER(struct sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->__sk_common);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk_receive_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk_filter);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk_wq);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk_async_wait_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk_rx_dst);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk_dst_cache);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk_write_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk_error_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk_prot_creator);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk_peer_pid);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk_timer);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk_socket);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk_frag);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk_send_head);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk_cgrp);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sk_state_change);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sk_data_ready);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sk_write_space);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sk_error_report);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sk_backlog_rcv);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sk_destruct);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_nf_bridge_info
#define WRAPPER_FOR_struct_nf_bridge_info
TYPE_WRAPPER(struct nf_bridge_info*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct nf_bridge_info\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct nf_bridge_info));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->physindev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->physoutdev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_sk_buff
#define WRAPPER_FOR_struct_sk_buff
TYPE_WRAPPER(struct sk_buff*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct sk_buff\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct sk_buff));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->prev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->destructor);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->nfct_reasm);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->nf_bridge);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netlink_callback
#define WRAPPER_FOR_struct_netlink_callback
TYPE_WRAPPER(struct netlink_callback*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netlink_callback\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netlink_callback));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->skb);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dump);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->done);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->module);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_net_device_ops
#define WRAPPER_FOR_struct_net_device_ops
TYPE_WRAPPER(struct net_device_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct net_device_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct net_device_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_uninit);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_open);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_stop);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_start_xmit);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_select_queue);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_change_rx_flags);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_set_rx_mode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_set_mac_address);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_validate_addr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_do_ioctl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_set_config);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_change_mtu);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_neigh_setup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_tx_timeout);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_get_stats64);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_get_stats);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_vlan_rx_add_vid);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_vlan_rx_kill_vid);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_poll_controller);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_netpoll_setup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_netpoll_cleanup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_set_vf_mac);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_set_vf_vlan);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_set_vf_tx_rate);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_set_vf_spoofchk);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_get_vf_config);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_set_vf_port);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_get_vf_port);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_setup_tc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_fcoe_enable);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_fcoe_disable);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_fcoe_ddp_setup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_fcoe_ddp_done);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_fcoe_ddp_target);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_fcoe_get_hbainfo);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_fcoe_get_wwn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_rx_flow_steer);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_add_slave);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_del_slave);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_fix_features);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_set_features);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_neigh_construct);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_neigh_destroy);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_fdb_add);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_fdb_del);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_fdb_dump);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_bridge_setlink);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ndo_bridge_getlink);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ethtool_ops
#define WRAPPER_FOR_struct_ethtool_ops
TYPE_WRAPPER(struct ethtool_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ethtool_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ethtool_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_settings);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_settings);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_drvinfo);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_regs_len);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_regs);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_wol);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_wol);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_msglevel);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_msglevel);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->nway_reset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_link);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_eeprom_len);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_eeprom);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_eeprom);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_coalesce);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_coalesce);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_ringparam);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_ringparam);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_pauseparam);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_pauseparam);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->self_test);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_strings);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_phys_id);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_ethtool_stats);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->begin);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->complete);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_priv_flags);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_priv_flags);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_sset_count);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_rxnfc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_rxnfc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->flash_device);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->reset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_rxfh_indir_size);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_rxfh_indir);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_rxfh_indir);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_channels);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_channels);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_dump_flag);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_dump_data);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_dump);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_ts_info);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_module_info);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_module_eeprom);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_eee);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_eee);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_header_ops
#define WRAPPER_FOR_struct_header_ops
TYPE_WRAPPER(struct header_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct header_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct header_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->create);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->parse);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rebuild);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cache);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cache_update);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dsa_chip_data
#define WRAPPER_FOR_struct_dsa_chip_data
TYPE_WRAPPER(struct dsa_chip_data*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dsa_chip_data\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dsa_chip_data));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mii_bus);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dsa_platform_data
#define WRAPPER_FOR_struct_dsa_platform_data
TYPE_WRAPPER(struct dsa_platform_data*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dsa_platform_data\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dsa_platform_data));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->netdev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->chip);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_phy_driver
#define WRAPPER_FOR_struct_phy_driver
TYPE_WRAPPER(struct phy_driver*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct phy_driver\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct phy_driver));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->config_init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->probe);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->suspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->config_aneg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_status);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ack_interrupt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->config_intr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->did_interrupt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->remove);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->match_phy_device);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ts_info);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->hwtstamp);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rxtstamp);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->txtstamp);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->driver);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_phy_device
#define WRAPPER_FOR_struct_phy_device
TYPE_WRAPPER(struct phy_device*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct phy_device\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct phy_device));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->drv);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bus);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->phy_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->state_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->lock);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->attached_dev);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->adjust_link);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->adjust_state);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_mii_bus
#define WRAPPER_FOR_struct_mii_bus
TYPE_WRAPPER(struct mii_bus*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct mii_bus\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct mii_bus));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->reset);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mdio_lock);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->parent);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dsa_switch_driver
#define WRAPPER_FOR_struct_dsa_switch_driver
TYPE_WRAPPER(struct dsa_switch_driver*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dsa_switch_driver\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dsa_switch_driver));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->probe);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_addr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->phy_read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->phy_write);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->poll_link);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_strings);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_ethtool_stats);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_sset_count);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dsa_switch
#define WRAPPER_FOR_struct_dsa_switch
TYPE_WRAPPER(struct dsa_switch*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dsa_switch\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dsa_switch));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dst);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pd);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->drv);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->master_mii_bus);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->slave_mii_bus);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dsa_switch_tree
#define WRAPPER_FOR_struct_dsa_switch_tree
TYPE_WRAPPER(struct dsa_switch_tree*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dsa_switch_tree\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dsa_switch_tree));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pd);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->master_netdev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->link_poll_work);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->link_poll_timer);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_rps_map
#define WRAPPER_FOR_struct_rps_map
TYPE_WRAPPER(struct rps_map*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct rps_map\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct rps_map));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rcu);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_rps_dev_flow_table
#define WRAPPER_FOR_struct_rps_dev_flow_table
TYPE_WRAPPER(struct rps_dev_flow_table*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct rps_dev_flow_table\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct rps_dev_flow_table));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rcu);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->free_work);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netdev_rx_queue
#define WRAPPER_FOR_struct_netdev_rx_queue
TYPE_WRAPPER(struct netdev_rx_queue*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netdev_rx_queue\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netdev_rx_queue));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rps_map);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rps_flow_table);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->kobj);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_qdisc_walker
#define WRAPPER_FOR_struct_qdisc_walker
TYPE_WRAPPER(struct qdisc_walker*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct qdisc_walker\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct qdisc_walker));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fn);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tcf_proto_ops
#define WRAPPER_FOR_struct_tcf_proto_ops
TYPE_WRAPPER(struct tcf_proto_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tcf_proto_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tcf_proto_ops));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->classify);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->destroy);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->put);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->change);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->delete_);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->walk);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dump);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tcf_proto
#define WRAPPER_FOR_struct_tcf_proto
TYPE_WRAPPER(struct tcf_proto*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tcf_proto\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tcf_proto));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->classify);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->q);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_gnet_dump
#define WRAPPER_FOR_struct_gnet_dump
TYPE_WRAPPER(struct gnet_dump*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct gnet_dump\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct gnet_dump));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->skb);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_Qdisc_class_ops
#define WRAPPER_FOR_struct_Qdisc_class_ops
TYPE_WRAPPER(struct Qdisc_class_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct Qdisc_class_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct Qdisc_class_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->select_queue);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->graft);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->leaf);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->qlen_notify);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->put);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->change);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->delete_);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->walk);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->tcf_chain);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bind_tcf);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->unbind_tcf);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dump);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dump_stats);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_Qdisc_ops
#define WRAPPER_FOR_struct_Qdisc_ops
TYPE_WRAPPER(struct Qdisc_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct Qdisc_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct Qdisc_ops));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->enqueue);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dequeue);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->peek);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->drop);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->reset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->destroy);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->change);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->attach);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dump);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dump_stats);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_qdisc_size_table
#define WRAPPER_FOR_struct_qdisc_size_table
TYPE_WRAPPER(struct qdisc_size_table*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct qdisc_size_table\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct qdisc_size_table));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rcu);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_Qdisc
#define WRAPPER_FOR_struct_Qdisc
TYPE_WRAPPER(struct Qdisc*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct Qdisc\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct Qdisc));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->enqueue);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dequeue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->stab);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->reshape_fail);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->__parent);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next_sched);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->gso_skb);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->q);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->callback_head);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netdev_queue
#define WRAPPER_FOR_struct_netdev_queue
TYPE_WRAPPER(struct netdev_queue*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netdev_queue\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netdev_queue));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->qdisc);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->qdisc_sleeping);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->kobj);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_xps_map
#define WRAPPER_FOR_struct_xps_map
TYPE_WRAPPER(struct xps_map*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct xps_map\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct xps_map));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rcu);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_xps_dev_maps
#define WRAPPER_FOR_struct_xps_dev_maps
TYPE_WRAPPER(struct xps_dev_maps*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct xps_dev_maps\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct xps_dev_maps));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rcu);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dcbnl_rtnl_ops
#define WRAPPER_FOR_struct_dcbnl_rtnl_ops
TYPE_WRAPPER(struct dcbnl_rtnl_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dcbnl_rtnl_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dcbnl_rtnl_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ieee_getets);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ieee_setets);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ieee_getmaxrate);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ieee_setmaxrate);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ieee_getpfc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ieee_setpfc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ieee_getapp);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ieee_setapp);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ieee_delapp);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ieee_peer_getets);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ieee_peer_getpfc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getstate);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setstate);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getpermhwaddr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setpgtccfgtx);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setpgbwgcfgtx);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setpgtccfgrx);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setpgbwgcfgrx);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getpgtccfgtx);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getpgbwgcfgtx);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getpgtccfgrx);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getpgbwgcfgrx);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setpfccfg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getpfccfg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setall);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getcap);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getnumtcs);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setnumtcs);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getpfcstate);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setpfcstate);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getbcncfg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setbcncfg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getbcnrp);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setbcnrp);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setapp);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getapp);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getfeatcfg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setfeatcfg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getdcbx);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setdcbx);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->peer_getappinfo);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->peer_getapptable);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cee_peer_getpg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cee_peer_getpfc);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pm_qos_request
#define WRAPPER_FOR_struct_pm_qos_request
TYPE_WRAPPER(struct pm_qos_request*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pm_qos_request\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pm_qos_request));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->work);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_net_device
#define WRAPPER_FOR_struct_net_device
TYPE_WRAPPER(struct net_device*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct net_device\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct net_device));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dsa_ptr);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->master);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->queues_kset);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->_rx);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rx_handler);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ingress_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->_tx);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->qdisc);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->xps_maps);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->watchdog_timer);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->destructor);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->nd_net);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->phydev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pm_qos_req);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_rtnl_link_ops
#define WRAPPER_FOR_struct_rtnl_link_ops
TYPE_WRAPPER(struct rtnl_link_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct rtnl_link_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct rtnl_link_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->validate);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->newlink);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->changelink);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dellink);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_size);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fill_info);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_xstats_size);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fill_xstats);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_num_tx_queues);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_num_rx_queues);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ptr_heap
#define WRAPPER_FOR_struct_ptr_heap
TYPE_WRAPPER(struct ptr_heap*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ptr_heap\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ptr_heap));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->gt);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_preempt_notifier
#define WRAPPER_FOR_struct_preempt_notifier
TYPE_WRAPPER(struct preempt_notifier*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct preempt_notifier\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct preempt_notifier));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ops);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_preempt_ops
#define WRAPPER_FOR_struct_preempt_ops
TYPE_WRAPPER(struct preempt_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct preempt_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct preempt_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sched_in);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sched_out);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_scsi_host_template
#define WRAPPER_FOR_struct_scsi_host_template
TYPE_WRAPPER(struct scsi_host_template*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct scsi_host_template\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct scsi_host_template));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->module);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->detect);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->info);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ioctl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->compat_ioctl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->queuecommand);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->transfer_response);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->eh_abort_handler);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->eh_device_reset_handler);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->eh_target_reset_handler);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->eh_bus_reset_handler);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->eh_host_reset_handler);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->slave_alloc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->slave_configure);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->slave_destroy);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->target_alloc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->target_destroy);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->scan_finished);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->scan_start);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->change_queue_depth);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->change_queue_type);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bios_param);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->unlock_native_capacity);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->proc_info);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->eh_timed_out);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->host_reset);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->proc_dir);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->shost_attrs);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sdev_attrs);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_Scsi_Host
#define WRAPPER_FOR_struct_Scsi_Host
TYPE_WRAPPER(struct Scsi_Host*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct Scsi_Host\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct Scsi_Host));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->scan_mutex);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ehandler);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->hostt);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bqt);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->uspace_req_q);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->shost_gendev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->shost_dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dma_dev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ata_device
#define WRAPPER_FOR_struct_ata_device
TYPE_WRAPPER(struct ata_device*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ata_device\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ata_device));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->link);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tdev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ata_eh_info
#define WRAPPER_FOR_struct_ata_eh_info
TYPE_WRAPPER(struct ata_eh_info*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ata_eh_info\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ata_eh_info));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ata_eh_context
#define WRAPPER_FOR_struct_ata_eh_context
TYPE_WRAPPER(struct ata_eh_context*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ata_eh_context\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ata_eh_context));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ata_link
#define WRAPPER_FOR_struct_ata_link
TYPE_WRAPPER(struct ata_link*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ata_link\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ata_link));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ap);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tdev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->eh_info);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->eh_context);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ata_port
#define WRAPPER_FOR_struct_ata_port
TYPE_WRAPPER(struct ata_port*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ata_port\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ata_port));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->scsi_host);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sff_pio_task_link);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sff_pio_task);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->link);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->slave_link);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pmp_link);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->excl_link);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->host);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tdev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->scsi_scan_mutex);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->hotplug_task);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->scsi_rescan_task);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->fastdrain_timer);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ata_queued_cmd
#define WRAPPER_FOR_struct_ata_queued_cmd
TYPE_WRAPPER(struct ata_queued_cmd*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ata_queued_cmd\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ata_queued_cmd));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ap);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->scsidone);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->complete_fn);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ata_port_operations
#define WRAPPER_FOR_struct_ata_port_operations
TYPE_WRAPPER(struct ata_port_operations*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ata_port_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ata_port_operations));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->qc_defer);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->check_atapi_dma);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->qc_prep);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->qc_issue);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->qc_fill_rtf);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cable_detect);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mode_filter);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_piomode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_dmamode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_mode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_id);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dev_config);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->freeze);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->thaw);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->prereset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->softreset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->hardreset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->postreset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pmp_prereset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pmp_softreset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pmp_hardreset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pmp_postreset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->error_handler);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->lost_interrupt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->post_internal_cmd);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sched_eh);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->end_eh);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->scr_read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->scr_write);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pmp_attach);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pmp_detach);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_lpm);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->port_suspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->port_resume);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->port_start);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->port_stop);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->host_stop);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sff_dev_select);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sff_set_devctl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sff_check_status);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sff_check_altstatus);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sff_tf_load);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sff_tf_read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sff_exec_command);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sff_data_xfer);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sff_irq_on);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sff_irq_check);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sff_irq_clear);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sff_drain_fifo);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bmdma_setup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bmdma_start);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bmdma_stop);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bmdma_status);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->em_show);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->em_store);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sw_activity_show);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sw_activity_store);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->phy_reset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->eng_timeout);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ata_host
#define WRAPPER_FOR_struct_ata_host
TYPE_WRAPPER(struct ata_host*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ata_host\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ata_host));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->eh_mutex);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->eh_owner);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->simplex_claimed);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_irq_data
#define WRAPPER_FOR_struct_irq_data
TYPE_WRAPPER(struct irq_data*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct irq_data\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct irq_data));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->chip);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_irq_chip
#define WRAPPER_FOR_struct_irq_chip
TYPE_WRAPPER(struct irq_chip*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct irq_chip\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct irq_chip));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_startup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_shutdown);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_enable);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_disable);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_ack);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_mask);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_mask_ack);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_unmask);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_eoi);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_set_affinity);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_retrigger);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_set_type);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_set_wake);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_bus_lock);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_bus_sync_unlock);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_cpu_online);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_cpu_offline);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_suspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_resume);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_pm_shutdown);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_print_chip);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_irqaction
#define WRAPPER_FOR_struct_irqaction
TYPE_WRAPPER(struct irqaction*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct irqaction\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct irqaction));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->handler);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->thread_fn);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->thread);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dir);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_irq_affinity_notify
#define WRAPPER_FOR_struct_irq_affinity_notify
TYPE_WRAPPER(struct irq_affinity_notify*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct irq_affinity_notify\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct irq_affinity_notify));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->work);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->notify);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_irq_desc
#define WRAPPER_FOR_struct_irq_desc
TYPE_WRAPPER(struct irq_desc*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct irq_desc\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct irq_desc));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->irq_data);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->handle_irq);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->action);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->affinity_notify);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dir);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_irq_chip_type
#define WRAPPER_FOR_struct_irq_chip_type
TYPE_WRAPPER(struct irq_chip_type*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct irq_chip_type\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct irq_chip_type));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->chip);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->handler);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_nfq_ct_hook
#define WRAPPER_FOR_struct_nfq_ct_hook
TYPE_WRAPPER(struct nfq_ct_hook*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct nfq_ct_hook\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct nfq_ct_hook));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->build_size);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->build);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->parse);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pv_lazy_ops
#define WRAPPER_FOR_struct_pv_lazy_ops
TYPE_WRAPPER(struct pv_lazy_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pv_lazy_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pv_lazy_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->enter);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->leave);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_crypto_ablkcipher
#define WRAPPER_FOR_struct_crypto_ablkcipher
TYPE_WRAPPER(struct crypto_ablkcipher*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct crypto_ablkcipher\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct crypto_ablkcipher));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_crypto_async_request
#define WRAPPER_FOR_struct_crypto_async_request
TYPE_WRAPPER(struct crypto_async_request*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct crypto_async_request\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct crypto_async_request));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->complete);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tfm);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ablkcipher_request
#define WRAPPER_FOR_struct_ablkcipher_request
TYPE_WRAPPER(struct ablkcipher_request*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ablkcipher_request\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ablkcipher_request));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ablkcipher_tfm
#define WRAPPER_FOR_struct_ablkcipher_tfm
TYPE_WRAPPER(struct ablkcipher_tfm*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ablkcipher_tfm\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ablkcipher_tfm));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setkey);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->encrypt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->decrypt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->givencrypt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->givdecrypt);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_crypto_aead
#define WRAPPER_FOR_struct_crypto_aead
TYPE_WRAPPER(struct crypto_aead*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct crypto_aead\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct crypto_aead));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_aead_request
#define WRAPPER_FOR_struct_aead_request
TYPE_WRAPPER(struct aead_request*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct aead_request\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct aead_request));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_aead_tfm
#define WRAPPER_FOR_struct_aead_tfm
TYPE_WRAPPER(struct aead_tfm*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct aead_tfm\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct aead_tfm));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setkey);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->encrypt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->decrypt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->givencrypt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->givdecrypt);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_crypto_blkcipher
#define WRAPPER_FOR_struct_crypto_blkcipher
TYPE_WRAPPER(struct crypto_blkcipher*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct crypto_blkcipher\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct crypto_blkcipher));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_blkcipher_desc
#define WRAPPER_FOR_struct_blkcipher_desc
TYPE_WRAPPER(struct blkcipher_desc*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct blkcipher_desc\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct blkcipher_desc));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tfm);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_blkcipher_tfm
#define WRAPPER_FOR_struct_blkcipher_tfm
TYPE_WRAPPER(struct blkcipher_tfm*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct blkcipher_tfm\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct blkcipher_tfm));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setkey);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->encrypt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->decrypt);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cipher_tfm
#define WRAPPER_FOR_struct_cipher_tfm
TYPE_WRAPPER(struct cipher_tfm*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cipher_tfm\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cipher_tfm));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cit_setkey);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cit_encrypt_one);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cit_decrypt_one);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_crypto_hash
#define WRAPPER_FOR_struct_crypto_hash
TYPE_WRAPPER(struct crypto_hash*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct crypto_hash\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct crypto_hash));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_hash_desc
#define WRAPPER_FOR_struct_hash_desc
TYPE_WRAPPER(struct hash_desc*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct hash_desc\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct hash_desc));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tfm);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_hash_tfm
#define WRAPPER_FOR_struct_hash_tfm
TYPE_WRAPPER(struct hash_tfm*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct hash_tfm\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct hash_tfm));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->update);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->final);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->digest);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setkey);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_compress_tfm
#define WRAPPER_FOR_struct_compress_tfm
TYPE_WRAPPER(struct compress_tfm*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct compress_tfm\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct compress_tfm));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cot_compress);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cot_decompress);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_crypto_rng
#define WRAPPER_FOR_struct_crypto_rng
TYPE_WRAPPER(struct crypto_rng*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct crypto_rng\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct crypto_rng));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_rng_tfm
#define WRAPPER_FOR_struct_rng_tfm
TYPE_WRAPPER(struct rng_tfm*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct rng_tfm\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct rng_tfm));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rng_gen_random);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rng_reset);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ablkcipher_alg
#define WRAPPER_FOR_struct_ablkcipher_alg
TYPE_WRAPPER(struct ablkcipher_alg*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ablkcipher_alg\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ablkcipher_alg));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setkey);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->encrypt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->decrypt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->givencrypt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->givdecrypt);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_aead_alg
#define WRAPPER_FOR_struct_aead_alg
TYPE_WRAPPER(struct aead_alg*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct aead_alg\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct aead_alg));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setkey);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setauthsize);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->encrypt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->decrypt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->givencrypt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->givdecrypt);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_blkcipher_alg
#define WRAPPER_FOR_struct_blkcipher_alg
TYPE_WRAPPER(struct blkcipher_alg*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct blkcipher_alg\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct blkcipher_alg));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setkey);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->encrypt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->decrypt);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cipher_alg
#define WRAPPER_FOR_struct_cipher_alg
TYPE_WRAPPER(struct cipher_alg*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cipher_alg\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cipher_alg));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cia_setkey);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cia_encrypt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cia_decrypt);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_compress_alg
#define WRAPPER_FOR_struct_compress_alg
TYPE_WRAPPER(struct compress_alg*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct compress_alg\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct compress_alg));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->coa_compress);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->coa_decompress);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_rng_alg
#define WRAPPER_FOR_struct_rng_alg
TYPE_WRAPPER(struct rng_alg*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct rng_alg\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct rng_alg));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rng_make_random);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rng_reset);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_crypto_alg
#define WRAPPER_FOR_struct_crypto_alg
TYPE_WRAPPER(struct crypto_alg*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct crypto_alg\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct crypto_alg));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cra_init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cra_exit);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cra_destroy);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->cra_module);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_crypto_tfm
#define WRAPPER_FOR_struct_crypto_tfm
TYPE_WRAPPER(struct crypto_tfm*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct crypto_tfm\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct crypto_tfm));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->exit);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->__crt_alg);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_crypto_cipher
#define WRAPPER_FOR_struct_crypto_cipher
TYPE_WRAPPER(struct crypto_cipher*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct crypto_cipher\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct crypto_cipher));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ipv6_pinfo
#define WRAPPER_FOR_struct_ipv6_pinfo
TYPE_WRAPPER(struct ipv6_pinfo*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ipv6_pinfo\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ipv6_pinfo));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pktoptions);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rxpmtu);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ip_options_rcu
#define WRAPPER_FOR_struct_ip_options_rcu
TYPE_WRAPPER(struct ip_options_rcu*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ip_options_rcu\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ip_options_rcu));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rcu);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_inet_cork
#define WRAPPER_FOR_struct_inet_cork
TYPE_WRAPPER(struct inet_cork*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct inet_cork\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct inet_cork));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dst);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_inet_cork_full
#define WRAPPER_FOR_struct_inet_cork_full
TYPE_WRAPPER(struct inet_cork_full*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct inet_cork_full\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct inet_cork_full));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_inet_sock
#define WRAPPER_FOR_struct_inet_sock
TYPE_WRAPPER(struct inet_sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct inet_sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct inet_sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pinet6);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->inet_opt);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->cork);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_udp_sock
#define WRAPPER_FOR_struct_udp_sock
TYPE_WRAPPER(struct udp_sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct udp_sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct udp_sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->inet);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->encap_rcv);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_udp6_sock
#define WRAPPER_FOR_struct_udp6_sock
TYPE_WRAPPER(struct udp6_sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct udp6_sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct udp6_sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->udp);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->inet6);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_x86_init_irqs
#define WRAPPER_FOR_struct_x86_init_irqs
TYPE_WRAPPER(struct x86_init_irqs*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct x86_init_irqs\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct x86_init_irqs));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pre_vector_init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->intr_init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->trap_init);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_seq_net_private
#define WRAPPER_FOR_struct_seq_net_private
TYPE_WRAPPER(struct seq_net_private*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct seq_net_private\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct seq_net_private));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->net);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_neigh_seq_state
#define WRAPPER_FOR_struct_neigh_seq_state
TYPE_WRAPPER(struct neigh_seq_state*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct neigh_seq_state\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct neigh_seq_state));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->p);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tbl);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->nht);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->neigh_sub_iter);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_vm_region
#define WRAPPER_FOR_struct_vm_region
TYPE_WRAPPER(struct vm_region*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct vm_region\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct vm_region));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->vm_file);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pnp_driver
#define WRAPPER_FOR_struct_pnp_driver
TYPE_WRAPPER(struct pnp_driver*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pnp_driver\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pnp_driver));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->probe);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->remove);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->shutdown);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->suspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->driver);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pnp_dev
#define WRAPPER_FOR_struct_pnp_dev
TYPE_WRAPPER(struct pnp_dev*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pnp_dev\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pnp_dev));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->protocol);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->card);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->driver);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->card_link);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->procent);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pnp_protocol
#define WRAPPER_FOR_struct_pnp_protocol
TYPE_WRAPPER(struct pnp_protocol*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pnp_protocol\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pnp_protocol));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->disable);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->can_wakeup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->suspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pnp_card
#define WRAPPER_FOR_struct_pnp_card
TYPE_WRAPPER(struct pnp_card*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pnp_card\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pnp_card));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->protocol);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->procdir);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pnp_card_link
#define WRAPPER_FOR_struct_pnp_card_link
TYPE_WRAPPER(struct pnp_card_link*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pnp_card_link\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pnp_card_link));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->card);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->driver);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pnp_card_driver
#define WRAPPER_FOR_struct_pnp_card_driver
TYPE_WRAPPER(struct pnp_card_driver*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pnp_card_driver\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pnp_card_driver));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->probe);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->remove);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->suspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->link);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netdev_hw_addr
#define WRAPPER_FOR_struct_netdev_hw_addr
TYPE_WRAPPER(struct netdev_hw_addr*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netdev_hw_addr\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netdev_hw_addr));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->callback_head);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_rq_map_data
#define WRAPPER_FOR_struct_rq_map_data
TYPE_WRAPPER(struct rq_map_data*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct rq_map_data\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct rq_map_data));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pages);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_skb_shared_info
#define WRAPPER_FOR_struct_skb_shared_info
TYPE_WRAPPER(struct skb_shared_info*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct skb_shared_info\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct skb_shared_info));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->frag_list);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_scm_cookie
#define WRAPPER_FOR_struct_scm_cookie
TYPE_WRAPPER(struct scm_cookie*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct scm_cookie\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct scm_cookie));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pid);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_sock_iocb
#define WRAPPER_FOR_struct_sock_iocb
TYPE_WRAPPER(struct sock_iocb*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct sock_iocb\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct sock_iocb));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sock);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sk);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->scm);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->kiocb);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_x86_init_mapping
#define WRAPPER_FOR_struct_x86_init_mapping
TYPE_WRAPPER(struct x86_init_mapping*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct x86_init_mapping\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct x86_init_mapping));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pagetable_reserve);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_exec_domain
#define WRAPPER_FOR_struct_exec_domain
TYPE_WRAPPER(struct exec_domain*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct exec_domain\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct exec_domain));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->handler);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->module);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_buffer_head
#define WRAPPER_FOR_struct_buffer_head
TYPE_WRAPPER(struct buffer_head*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct buffer_head\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct buffer_head));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_this_page);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_page);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_bdev);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->b_end_io);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_assoc_map);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_crypto_shash
#define WRAPPER_FOR_struct_crypto_shash
TYPE_WRAPPER(struct crypto_shash*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct crypto_shash\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct crypto_shash));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_journal_s
#define WRAPPER_FOR_struct_journal_s
TYPE_WRAPPER(struct journal_s*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct journal_s\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct journal_s));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->j_sb_buffer);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->j_barrier);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->j_running_transaction);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->j_committing_transaction);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->j_checkpoint_transactions);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->j_checkpoint_mutex);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->j_dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->j_fs_dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->j_inode);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->j_task);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->j_commit_timer);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->j_wbuf);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->j_commit_callback);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->j_proc_entry);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->j_chksum_driver);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_transaction_s
#define WRAPPER_FOR_struct_transaction_s
TYPE_WRAPPER(struct transaction_s*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct transaction_s\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct transaction_s));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->t_journal);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->t_reserved_list);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->t_buffers);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->t_forget);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->t_checkpoint_list);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->t_checkpoint_io_list);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->t_iobuf_list);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->t_shadow_list);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->t_log_list);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->t_cpnext);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->t_cpprev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_jbd2_buffer_trigger_type
#define WRAPPER_FOR_struct_jbd2_buffer_trigger_type
TYPE_WRAPPER(struct jbd2_buffer_trigger_type*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct jbd2_buffer_trigger_type\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct jbd2_buffer_trigger_type));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->t_frozen);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->t_abort);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_journal_head
#define WRAPPER_FOR_struct_journal_head
TYPE_WRAPPER(struct journal_head*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct journal_head\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct journal_head));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_bh);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_transaction);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_next_transaction);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_tnext);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_tprev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_cp_transaction);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_cpnext);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_cpprev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_triggers);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->b_frozen_triggers);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_x86_init_pci
#define WRAPPER_FOR_struct_x86_init_pci
TYPE_WRAPPER(struct x86_init_pci*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct x86_init_pci\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct x86_init_pci));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->arch_init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init_irq);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fixup_irqs);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pv_cpu_ops
#define WRAPPER_FOR_struct_pv_cpu_ops
TYPE_WRAPPER(struct pv_cpu_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pv_cpu_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pv_cpu_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_debugreg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_debugreg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->clts);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_cr0);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_cr0);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_cr4_safe);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_cr4);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_cr4);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_cr8);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_cr8);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->load_tr_desc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->load_gdt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->load_idt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->store_gdt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->store_idt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_ldt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->store_tr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->load_tls);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->load_gs_index);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_ldt_entry);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_gdt_entry);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_idt_entry);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->alloc_ldt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->free_ldt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->load_sp0);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_iopl_mask);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->wbinvd);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->io_delay);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cpuid);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_msr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_msr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_tsc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_pmc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_tscp);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->irq_enable_sysexit);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->usergs_sysret64);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->usergs_sysret32);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->iret);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->swapgs);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->start_context_switch);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->end_context_switch);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_socket_alloc
#define WRAPPER_FOR_struct_socket_alloc
TYPE_WRAPPER(struct socket_alloc*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct socket_alloc\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct socket_alloc));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->socket);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->vfs_inode);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_klist
#define WRAPPER_FOR_struct_klist
TYPE_WRAPPER(struct klist*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct klist\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct klist));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->put);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_inet6_request_sock
#define WRAPPER_FOR_struct_inet6_request_sock
TYPE_WRAPPER(struct inet6_request_sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct inet6_request_sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct inet6_request_sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pktopts);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pci_slot
#define WRAPPER_FOR_struct_pci_slot
TYPE_WRAPPER(struct pci_slot*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pci_slot\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pci_slot));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bus);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->kobj);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pci_error_handlers
#define WRAPPER_FOR_struct_pci_error_handlers
TYPE_WRAPPER(struct pci_error_handlers*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pci_error_handlers\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pci_error_handlers));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->error_detected);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mmio_enabled);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->link_reset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->slot_reset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pci_driver
#define WRAPPER_FOR_struct_pci_driver
TYPE_WRAPPER(struct pci_driver*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pci_driver\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pci_driver));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->probe);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->remove);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->suspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->suspend_late);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume_early);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->shutdown);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sriov_configure);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->driver);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pci_dev
#define WRAPPER_FOR_struct_pci_dev
TYPE_WRAPPER(struct pci_dev*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pci_dev\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pci_dev));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bus);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->subordinate);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->procent);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->slot);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->driver);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rom_attr);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->msi_kset);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pci_bus
#define WRAPPER_FOR_struct_pci_bus
TYPE_WRAPPER(struct pci_bus*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pci_bus\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pci_bus));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->parent);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->self);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->procdir);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bridge);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->legacy_io);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->legacy_mem);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pci_ops
#define WRAPPER_FOR_struct_pci_ops
TYPE_WRAPPER(struct pci_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pci_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pci_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_proc_ns_operations
#define WRAPPER_FOR_struct_proc_ns_operations
TYPE_WRAPPER(struct proc_ns_operations*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct proc_ns_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct proc_ns_operations));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->put);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->install);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->inum);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_nfq_ct_nat_hook
#define WRAPPER_FOR_struct_nfq_ct_nat_hook
TYPE_WRAPPER(struct nfq_ct_nat_hook*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct nfq_ct_nat_hook\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct nfq_ct_nat_hook));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->seq_adjust);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_jbd2_inode
#define WRAPPER_FOR_struct_jbd2_inode
TYPE_WRAPPER(struct jbd2_inode*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct jbd2_inode\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct jbd2_inode));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_transaction);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_next_transaction);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_vfs_inode);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pernet_operations
#define WRAPPER_FOR_struct_pernet_operations
TYPE_WRAPPER(struct pernet_operations*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pernet_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pernet_operations));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->exit);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->exit_batch);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_jbd2_journal_handle
#define WRAPPER_FOR_struct_jbd2_journal_handle
TYPE_WRAPPER(struct jbd2_journal_handle*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct jbd2_journal_handle\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct jbd2_journal_handle));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->h_transaction);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_mm_walk
#define WRAPPER_FOR_struct_mm_walk
TYPE_WRAPPER(struct mm_walk*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct mm_walk\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct mm_walk));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pgd_entry);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pud_entry);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pmd_entry);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pte_entry);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pte_hole);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->hugetlb_entry);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mm);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cdrom_device_info
#define WRAPPER_FOR_struct_cdrom_device_info
TYPE_WRAPPER(struct cdrom_device_info*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cdrom_device_info\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cdrom_device_info));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->disk);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->exit);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cdrom_device_ops
#define WRAPPER_FOR_struct_cdrom_device_ops
TYPE_WRAPPER(struct cdrom_device_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cdrom_device_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cdrom_device_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->open);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->drive_status);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->check_events);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->media_changed);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->tray_move);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->lock_door);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->select_speed);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->select_disc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_last_session);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_mcn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->reset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->audio_ioctl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->generic_packet);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dm_dev
#define WRAPPER_FOR_struct_dm_dev
TYPE_WRAPPER(struct dm_dev*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dm_dev\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dm_dev));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bdev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_x86_platform_ops
#define WRAPPER_FOR_struct_x86_platform_ops
TYPE_WRAPPER(struct x86_platform_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct x86_platform_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct x86_platform_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->calibrate_tsc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_wallclock);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_wallclock);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->iommu_shutdown);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->is_untracked_pat_range);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->nmi_init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_nmi_reason);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->i8042_detect);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->save_sched_clock_state);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->restore_sched_clock_state);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->apic_post_init);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_nf_afinfo
#define WRAPPER_FOR_struct_nf_afinfo
TYPE_WRAPPER(struct nf_afinfo*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct nf_afinfo\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct nf_afinfo));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->checksum);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->checksum_partial);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->route);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->saveroute);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->reroute);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct___wait_queue
#define WRAPPER_FOR_struct___wait_queue
TYPE_WRAPPER(struct __wait_queue*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct __wait_queue\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct __wait_queue));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->func);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_poll_table_entry
#define WRAPPER_FOR_struct_poll_table_entry
TYPE_WRAPPER(struct poll_table_entry*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct poll_table_entry\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct poll_table_entry));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->filp);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->wait);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_poll_wqueues
#define WRAPPER_FOR_struct_poll_wqueues
TYPE_WRAPPER(struct poll_wqueues*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct poll_wqueues\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct poll_wqueues));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pt);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->polling_task);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dev_ext_attribute
#define WRAPPER_FOR_struct_dev_ext_attribute
TYPE_WRAPPER(struct dev_ext_attribute*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dev_ext_attribute\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dev_ext_attribute));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->attr);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pv_apic_ops
#define WRAPPER_FOR_struct_pv_apic_ops
TYPE_WRAPPER(struct pv_apic_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pv_apic_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pv_apic_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->startup_ipi_hook);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_atomic_notifier_head
#define WRAPPER_FOR_struct_atomic_notifier_head
TYPE_WRAPPER(struct atomic_notifier_head*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct atomic_notifier_head\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct atomic_notifier_head));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->head);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_inet_connection_sock_af_ops
#define WRAPPER_FOR_struct_inet_connection_sock_af_ops
TYPE_WRAPPER(struct inet_connection_sock_af_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct inet_connection_sock_af_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct inet_connection_sock_af_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->queue_xmit);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->send_check);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rebuild_header);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sk_rx_dst_set);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->conn_request);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->syn_recv_sock);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setsockopt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getsockopt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->compat_setsockopt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->compat_getsockopt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->addr2sockaddr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bind_conflict);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tree_descr
#define WRAPPER_FOR_struct_tree_descr
TYPE_WRAPPER(struct tree_descr*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tree_descr\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tree_descr));
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_restart_block
#define WRAPPER_FOR_struct_restart_block
TYPE_WRAPPER(struct restart_block*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct restart_block\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct restart_block));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fn);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_napi_gro_cb
#define WRAPPER_FOR_struct_napi_gro_cb
TYPE_WRAPPER(struct napi_gro_cb*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct napi_gro_cb\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct napi_gro_cb));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->last);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_fastopen_queue
#define WRAPPER_FOR_struct_fastopen_queue
TYPE_WRAPPER(struct fastopen_queue*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct fastopen_queue\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct fastopen_queue));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rskq_rst_head);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rskq_rst_tail);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_request_sock_queue
#define WRAPPER_FOR_struct_request_sock_queue
TYPE_WRAPPER(struct request_sock_queue*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct request_sock_queue\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct request_sock_queue));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rskq_accept_head);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rskq_accept_tail);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->fastopenq);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_inet_connection_sock
#define WRAPPER_FOR_struct_inet_connection_sock
TYPE_WRAPPER(struct inet_connection_sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct inet_connection_sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct inet_connection_sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->icsk_inet);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->icsk_accept_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->icsk_retransmit_timer);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->icsk_delack_timer);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->icsk_sync_mss);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dma_async_tx_descriptor
#define WRAPPER_FOR_struct_dma_async_tx_descriptor
TYPE_WRAPPER(struct dma_async_tx_descriptor*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dma_async_tx_descriptor\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dma_async_tx_descriptor));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->chan);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->tx_submit);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->callback);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dma_device
#define WRAPPER_FOR_struct_dma_device
TYPE_WRAPPER(struct dma_device*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dma_device\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dma_device));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_alloc_chan_resources);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_free_chan_resources);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_prep_dma_memcpy);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_prep_dma_xor);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_prep_dma_xor_val);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_prep_dma_pq);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_prep_dma_pq_val);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_prep_dma_memset);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_prep_dma_interrupt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_prep_dma_sg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_prep_slave_sg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_prep_dma_cyclic);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_prep_interleaved_dma);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_control);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_tx_status);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->device_issue_pending);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dma_chan_dev
#define WRAPPER_FOR_struct_dma_chan_dev
TYPE_WRAPPER(struct dma_chan_dev*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dma_chan_dev\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dma_chan_dev));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->chan);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->device);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dma_chan
#define WRAPPER_FOR_struct_dma_chan
TYPE_WRAPPER(struct dma_chan*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dma_chan\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dma_chan));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->device);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dma_page_list
#define WRAPPER_FOR_struct_dma_page_list
TYPE_WRAPPER(struct dma_page_list*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dma_page_list\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dma_page_list));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pages);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tcp_sock
#define WRAPPER_FOR_struct_tcp_sock
TYPE_WRAPPER(struct tcp_sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tcp_sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tcp_sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->inet_conn);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->lost_skb_hint);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->scoreboard_skb_hint);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->retransmit_skb_hint);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->out_of_order_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->highest_sack);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->fastopen_rsk);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_inet_frag_queue
#define WRAPPER_FOR_struct_inet_frag_queue
TYPE_WRAPPER(struct inet_frag_queue*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct inet_frag_queue\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct inet_frag_queue));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->timer);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->fragments);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->fragments_tail);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_inet_frags
#define WRAPPER_FOR_struct_inet_frags
TYPE_WRAPPER(struct inet_frags*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct inet_frags\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct inet_frags));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->secret_timer);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->hashfn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->constructor);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->destructor);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->skb_free);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->match);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->frag_expire);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ff_device
#define WRAPPER_FOR_struct_ff_device
TYPE_WRAPPER(struct ff_device*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ff_device\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ff_device));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->upload);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->erase);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->playback);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_gain);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_autocenter);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->destroy);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mutex);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_input_handler
#define WRAPPER_FOR_struct_input_handler
TYPE_WRAPPER(struct input_handler*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct input_handler\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct input_handler));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->event);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->events);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->filter);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->match);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->connect);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->disconnect);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->start);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_input_handle
#define WRAPPER_FOR_struct_input_handle
TYPE_WRAPPER(struct input_handle*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct input_handle\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct input_handle));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->handler);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_input_dev
#define WRAPPER_FOR_struct_input_dev
TYPE_WRAPPER(struct input_dev*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct input_dev\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct input_dev));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setkeycode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->getkeycode);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ff);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->timer);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->open);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->close);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->flush);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->event);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->grab);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mutex);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_sg_mapping_iter
#define WRAPPER_FOR_struct_sg_mapping_iter
TYPE_WRAPPER(struct sg_mapping_iter*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct sg_mapping_iter\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct sg_mapping_iter));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->page);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_mutex_waiter
#define WRAPPER_FOR_struct_mutex_waiter
TYPE_WRAPPER(struct mutex_waiter*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct mutex_waiter\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct mutex_waiter));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->task);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tracepoint
#define WRAPPER_FOR_struct_tracepoint
TYPE_WRAPPER(struct tracepoint*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tracepoint\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tracepoint));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->regfunc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->unregfunc);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_task_migration_notifier
#define WRAPPER_FOR_struct_task_migration_notifier
TYPE_WRAPPER(struct task_migration_notifier*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct task_migration_notifier\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct task_migration_notifier));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->task);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_flow_cache_object
#define WRAPPER_FOR_struct_flow_cache_object
TYPE_WRAPPER(struct flow_cache_object*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct flow_cache_object\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct flow_cache_object));
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_flow_cache_ops
#define WRAPPER_FOR_struct_flow_cache_ops
TYPE_WRAPPER(struct flow_cache_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct flow_cache_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct flow_cache_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->check);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->delete_);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_blk_scsi_cmd_filter
#define WRAPPER_FOR_struct_blk_scsi_cmd_filter
TYPE_WRAPPER(struct blk_scsi_cmd_filter*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct blk_scsi_cmd_filter\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct blk_scsi_cmd_filter));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->kobj);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_req_iterator
#define WRAPPER_FOR_struct_req_iterator
TYPE_WRAPPER(struct req_iterator*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct req_iterator\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct req_iterator));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bio);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_acpi_device_dir
#define WRAPPER_FOR_struct_acpi_device_dir
TYPE_WRAPPER(struct acpi_device_dir*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct acpi_device_dir\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct acpi_device_dir));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->entry);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cgroup_map_cb
#define WRAPPER_FOR_struct_cgroup_map_cb
TYPE_WRAPPER(struct cgroup_map_cb*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cgroup_map_cb\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cgroup_map_cb));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fill);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_node
#define WRAPPER_FOR_struct_node
TYPE_WRAPPER(struct node*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct node\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct node));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->node_work);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_clock_event_device
#define WRAPPER_FOR_struct_clock_event_device
TYPE_WRAPPER(struct clock_event_device*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct clock_event_device\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct clock_event_device));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->event_handler);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_next_event);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_next_ktime);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->broadcast);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_mode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->suspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tick_device
#define WRAPPER_FOR_struct_tick_device
TYPE_WRAPPER(struct tick_device*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tick_device\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tick_device));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->evtdev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_zone
#define WRAPPER_FOR_struct_zone
TYPE_WRAPPER(struct zone*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct zone\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct zone));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->zone_pgdat);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_zoneref
#define WRAPPER_FOR_struct_zoneref
TYPE_WRAPPER(struct zoneref*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct zoneref\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct zoneref));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->zone);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pglist_data
#define WRAPPER_FOR_struct_pglist_data
TYPE_WRAPPER(struct pglist_data*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pglist_data\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pglist_data));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->kswapd);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ahash_request
#define WRAPPER_FOR_struct_ahash_request
TYPE_WRAPPER(struct ahash_request*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ahash_request\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ahash_request));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_crypto_ahash
#define WRAPPER_FOR_struct_crypto_ahash
TYPE_WRAPPER(struct crypto_ahash*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct crypto_ahash\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct crypto_ahash));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->update);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->final);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->finup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->digest);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->export_);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->import);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setkey);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_raw_notifier_head
#define WRAPPER_FOR_struct_raw_notifier_head
TYPE_WRAPPER(struct raw_notifier_head*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct raw_notifier_head\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct raw_notifier_head));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->head);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_net_proto_family
#define WRAPPER_FOR_struct_net_proto_family
TYPE_WRAPPER(struct net_proto_family*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct net_proto_family\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct net_proto_family));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->create);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_offload_callbacks
#define WRAPPER_FOR_struct_offload_callbacks
TYPE_WRAPPER(struct offload_callbacks*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct offload_callbacks\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct offload_callbacks));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->gso_segment);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->gso_send_check);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->gro_receive);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->gro_complete);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_class_attribute_string
#define WRAPPER_FOR_struct_class_attribute_string
TYPE_WRAPPER(struct class_attribute_string*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct class_attribute_string\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct class_attribute_string));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->attr);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_subsys_interface
#define WRAPPER_FOR_struct_subsys_interface
TYPE_WRAPPER(struct subsys_interface*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct subsys_interface\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct subsys_interface));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->subsys);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->add_dev);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->remove_dev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ubuf_info
#define WRAPPER_FOR_struct_ubuf_info
TYPE_WRAPPER(struct ubuf_info*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ubuf_info\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ubuf_info));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->callback);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_disk_part_iter
#define WRAPPER_FOR_struct_disk_part_iter
TYPE_WRAPPER(struct disk_part_iter*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct disk_part_iter\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct disk_part_iter));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->disk);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->part);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_idr_layer
#define WRAPPER_FOR_struct_idr_layer
TYPE_WRAPPER(struct idr_layer*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct idr_layer\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct idr_layer));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->callback_head);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_idr
#define WRAPPER_FOR_struct_idr
TYPE_WRAPPER(struct idr*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct idr\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct idr));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->top);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->id_free);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cftype
#define WRAPPER_FOR_struct_cftype
TYPE_WRAPPER(struct cftype*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cftype\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cftype));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->open);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_u64);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_s64);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_map);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_seq_string);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_u64);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_s64);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_string);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->trigger);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->register_event);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->unregister_event);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cftype_set
#define WRAPPER_FOR_struct_cftype_set
TYPE_WRAPPER(struct cftype_set*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cftype_set\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cftype_set));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->cfts);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cgroup_subsys
#define WRAPPER_FOR_struct_cgroup_subsys
TYPE_WRAPPER(struct cgroup_subsys*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cgroup_subsys\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cgroup_subsys));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->css_alloc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->css_online);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->css_offline);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->css_free);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->can_attach);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cancel_attach);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->attach);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fork);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->exit);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bind);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->idr);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base_cftypes);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base_cftset);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->module);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_acpi_device_ops
#define WRAPPER_FOR_struct_acpi_device_ops
TYPE_WRAPPER(struct acpi_device_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct acpi_device_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct acpi_device_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->add);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->remove);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->start);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bind);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->unbind);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->notify);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_acpi_driver
#define WRAPPER_FOR_struct_acpi_driver
TYPE_WRAPPER(struct acpi_driver*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct acpi_driver\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct acpi_driver));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->drv);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_acpi_device
#define WRAPPER_FOR_struct_acpi_device
TYPE_WRAPPER(struct acpi_device*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct acpi_device\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct acpi_device));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->parent);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dir);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->driver);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->physical_node_lock);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_acpi_pci_root
#define WRAPPER_FOR_struct_acpi_pci_root
TYPE_WRAPPER(struct acpi_pci_root*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct acpi_pci_root\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct acpi_pci_root));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->device);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bus);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ip_options_data
#define WRAPPER_FOR_struct_ip_options_data
TYPE_WRAPPER(struct ip_options_data*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ip_options_data\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ip_options_data));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->opt);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_napi_struct
#define WRAPPER_FOR_struct_napi_struct
TYPE_WRAPPER(struct napi_struct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct napi_struct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct napi_struct));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->poll);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->gro_list);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->skb);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pv_lock_ops
#define WRAPPER_FOR_struct_pv_lock_ops
TYPE_WRAPPER(struct pv_lock_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pv_lock_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pv_lock_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->spin_is_locked);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->spin_is_contended);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->spin_lock);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->spin_lock_flags);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->spin_trylock);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->spin_unlock);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pci_host_bridge
#define WRAPPER_FOR_struct_pci_host_bridge
TYPE_WRAPPER(struct pci_host_bridge*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pci_host_bridge\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pci_host_bridge));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bus);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release_fn);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_x86_init_paging
#define WRAPPER_FOR_struct_x86_init_paging
TYPE_WRAPPER(struct x86_init_paging*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct x86_init_paging\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct x86_init_paging));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pagetable_init);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_softirq_action
#define WRAPPER_FOR_struct_softirq_action
TYPE_WRAPPER(struct softirq_action*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct softirq_action\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct softirq_action));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->action);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_mb_cache
#define WRAPPER_FOR_struct_mb_cache
TYPE_WRAPPER(struct mb_cache*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct mb_cache\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct mb_cache));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->c_entry_cache);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_nf_sockopt_ops
#define WRAPPER_FOR_struct_nf_sockopt_ops
TYPE_WRAPPER(struct nf_sockopt_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct nf_sockopt_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct nf_sockopt_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->compat_set);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->compat_get);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ts_config
#define WRAPPER_FOR_struct_ts_config
TYPE_WRAPPER(struct ts_config*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ts_config\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ts_config));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ops);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_next_block);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->finish);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ts_ops
#define WRAPPER_FOR_struct_ts_ops
TYPE_WRAPPER(struct ts_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ts_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ts_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->find);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->destroy);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_pattern);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_pattern_len);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pnp_fixup
#define WRAPPER_FOR_struct_pnp_fixup
TYPE_WRAPPER(struct pnp_fixup*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pnp_fixup\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pnp_fixup));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->quirk_function);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pv_init_ops
#define WRAPPER_FOR_struct_pv_init_ops
TYPE_WRAPPER(struct pv_init_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pv_init_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pv_init_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->patch);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_qtree_fmt_operations
#define WRAPPER_FOR_struct_qtree_fmt_operations
TYPE_WRAPPER(struct qtree_fmt_operations*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct qtree_fmt_operations\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct qtree_fmt_operations));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mem2disk_dqblk);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->disk2mem_dqblk);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->is_id);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_qtree_mem_dqinfo
#define WRAPPER_FOR_struct_qtree_mem_dqinfo
TYPE_WRAPPER(struct qtree_mem_dqinfo*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct qtree_mem_dqinfo\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct qtree_mem_dqinfo));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dqi_sb);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dqi_ops);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_inet_request_sock
#define WRAPPER_FOR_struct_inet_request_sock
TYPE_WRAPPER(struct inet_request_sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct inet_request_sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct inet_request_sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->req);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->opt);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tcp_request_sock
#define WRAPPER_FOR_struct_tcp_request_sock
TYPE_WRAPPER(struct tcp_request_sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tcp_request_sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tcp_request_sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->req);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->listener);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tcp6_request_sock
#define WRAPPER_FOR_struct_tcp6_request_sock
TYPE_WRAPPER(struct tcp6_request_sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tcp6_request_sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tcp6_request_sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tcp6rsk_tcp);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tcp6rsk_inet6);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_x86_init_timers
#define WRAPPER_FOR_struct_x86_init_timers
TYPE_WRAPPER(struct x86_init_timers*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct x86_init_timers\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct x86_init_timers));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setup_percpu_clockev);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->tsc_pre_init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->timer_init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->wallclock_init);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cyclecounter
#define WRAPPER_FOR_struct_cyclecounter
TYPE_WRAPPER(struct cyclecounter*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cyclecounter\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cyclecounter));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_timecounter
#define WRAPPER_FOR_struct_timecounter
TYPE_WRAPPER(struct timecounter*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct timecounter\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct timecounter));
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_x86_init_oem
#define WRAPPER_FOR_struct_x86_init_oem
TYPE_WRAPPER(struct x86_init_oem*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct x86_init_oem\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct x86_init_oem));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->arch_setup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->banner);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_hash_alg_common
#define WRAPPER_FOR_struct_hash_alg_common
TYPE_WRAPPER(struct hash_alg_common*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct hash_alg_common\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct hash_alg_common));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_rcu_batch
#define WRAPPER_FOR_struct_rcu_batch
TYPE_WRAPPER(struct rcu_batch*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct rcu_batch\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct rcu_batch));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->head);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tail);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_srcu_struct
#define WRAPPER_FOR_struct_srcu_struct
TYPE_WRAPPER(struct srcu_struct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct srcu_struct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct srcu_struct));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->batch_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->batch_check0);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->batch_check1);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->batch_done);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->work);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_srcu_notifier_head
#define WRAPPER_FOR_struct_srcu_notifier_head
TYPE_WRAPPER(struct srcu_notifier_head*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct srcu_notifier_head\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct srcu_notifier_head));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mutex);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->srcu);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->head);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tp_module
#define WRAPPER_FOR_struct_tp_module
TYPE_WRAPPER(struct tp_module*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tp_module\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tp_module));
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tracepoint_iter
#define WRAPPER_FOR_struct_tracepoint_iter
TYPE_WRAPPER(struct tracepoint_iter*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tracepoint_iter\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tracepoint_iter));
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_phy_fixup
#define WRAPPER_FOR_struct_phy_fixup
TYPE_WRAPPER(struct phy_fixup*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct phy_fixup\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct phy_fixup));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->run);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_acpi_sleep_functions
#define WRAPPER_FOR_struct_acpi_sleep_functions
TYPE_WRAPPER(struct acpi_sleep_functions*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct acpi_sleep_functions\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct acpi_sleep_functions));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->legacy_function);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->extended_function);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_smp_ops
#define WRAPPER_FOR_struct_smp_ops
TYPE_WRAPPER(struct smp_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct smp_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct smp_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->smp_prepare_boot_cpu);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->smp_prepare_cpus);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->smp_cpus_done);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->stop_other_cpus);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->smp_send_reschedule);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cpu_up);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cpu_disable);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cpu_die);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->play_dead);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->send_call_func_ipi);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->send_call_func_single_ipi);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_kthread_work
#define WRAPPER_FOR_struct_kthread_work
TYPE_WRAPPER(struct kthread_work*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct kthread_work\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct kthread_work));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->func);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->worker);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_kthread_worker
#define WRAPPER_FOR_struct_kthread_worker
TYPE_WRAPPER(struct kthread_worker*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct kthread_worker\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct kthread_worker));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->task);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->current_work);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tcp6_sock
#define WRAPPER_FOR_struct_tcp6_sock
TYPE_WRAPPER(struct tcp6_sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tcp6_sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tcp6_sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tcp);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->inet6);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_x86_init_resources
#define WRAPPER_FOR_struct_x86_init_resources
TYPE_WRAPPER(struct x86_init_resources*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct x86_init_resources\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct x86_init_resources));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->probe_roms);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->reserve_resources);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->memory_setup);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_acpi_bus_type
#define WRAPPER_FOR_struct_acpi_bus_type
TYPE_WRAPPER(struct acpi_bus_type*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct acpi_bus_type\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct acpi_bus_type));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bus);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->find_device);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->find_bridge);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_crypto_comp
#define WRAPPER_FOR_struct_crypto_comp
TYPE_WRAPPER(struct crypto_comp*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct crypto_comp\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct crypto_comp));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dmi_system_id
#define WRAPPER_FOR_struct_dmi_system_id
TYPE_WRAPPER(struct dmi_system_id*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dmi_system_id\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dmi_system_id));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->callback);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_target_type
#define WRAPPER_FOR_struct_target_type
TYPE_WRAPPER(struct target_type*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct target_type\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct target_type));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->module);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ctr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dtr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->map);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->map_rq);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->end_io);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->rq_end_io);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->presuspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->postsuspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->preresume);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->status);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->message);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ioctl);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->merge);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->busy);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->iterate_devices);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->io_hints);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dm_target
#define WRAPPER_FOR_struct_dm_target
TYPE_WRAPPER(struct dm_target*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dm_target\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dm_target));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->type);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_apic
#define WRAPPER_FOR_struct_apic
TYPE_WRAPPER(struct apic*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct apic\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct apic));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->probe);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->acpi_madt_oem_check);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->apic_id_valid);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->apic_id_registered);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->target_cpus);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->check_apicid_used);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->check_apicid_present);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->vector_allocation_domain);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init_apic_ldr);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ioapic_phys_id_map);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setup_apic_routing);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->multi_timer_check);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cpu_present_to_apicid);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->apicid_to_cpu_present);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setup_portio_remap);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->check_phys_apicid_present);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->enable_apic_mode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->phys_pkg_id);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mps_oem_check);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_apic_id);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_apic_id);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cpu_mask_to_apicid_and);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->send_IPI_mask);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->send_IPI_mask_allbutself);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->send_IPI_allbutself);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->send_IPI_all);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->send_IPI_self);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->wakeup_secondary_cpu);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->wait_for_init_deassert);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->smp_callin_clear_local_apic);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->inquire_remote_apic);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->eoi_write);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->icr_read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->icr_write);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->wait_icr_idle);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->safe_wait_icr_idle);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pv_mmu_ops
#define WRAPPER_FOR_struct_pv_mmu_ops
TYPE_WRAPPER(struct pv_mmu_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pv_mmu_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pv_mmu_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_cr2);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_cr2);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read_cr3);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write_cr3);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->activate_mm);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dup_mmap);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->exit_mmap);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->flush_tlb_user);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->flush_tlb_kernel);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->flush_tlb_single);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->flush_tlb_others);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pgd_alloc);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pgd_free);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->alloc_pte);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->alloc_pmd);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->alloc_pud);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release_pte);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release_pmd);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->release_pud);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_pte);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_pte_at);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_pmd);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_pmd_at);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pte_update);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pte_update_defer);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pmd_update);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->pmd_update_defer);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ptep_modify_prot_start);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->ptep_modify_prot_commit);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_pud);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_pgd);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->lazy_mode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_fixmap);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_proc_inode
#define WRAPPER_FOR_struct_proc_inode
TYPE_WRAPPER(struct proc_inode*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct proc_inode\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct proc_inode));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pid);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pde);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sysctl);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sysctl_entry);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->vfs_inode);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pci_fixup
#define WRAPPER_FOR_struct_pci_fixup
TYPE_WRAPPER(struct pci_fixup*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pci_fixup\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pci_fixup));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->hook);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dm_target_callbacks
#define WRAPPER_FOR_struct_dm_target_callbacks
TYPE_WRAPPER(struct dm_target_callbacks*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dm_target_callbacks\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dm_target_callbacks));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->congested_fn);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netlink_notify
#define WRAPPER_FOR_struct_netlink_notify
TYPE_WRAPPER(struct netlink_notify*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netlink_notify\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netlink_notify));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->net);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_inet_timewait_sock
#define WRAPPER_FOR_struct_inet_timewait_sock
TYPE_WRAPPER(struct inet_timewait_sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct inet_timewait_sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct inet_timewait_sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->__tw_common);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_shash_desc
#define WRAPPER_FOR_struct_shash_desc
TYPE_WRAPPER(struct shash_desc*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct shash_desc\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct shash_desc));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tfm);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_shash_alg
#define WRAPPER_FOR_struct_shash_alg
TYPE_WRAPPER(struct shash_alg*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct shash_alg\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct shash_alg));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->update);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->final);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->finup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->digest);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->export_);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->import);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setkey);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->base);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_hrtimer_sleeper
#define WRAPPER_FOR_struct_hrtimer_sleeper
TYPE_WRAPPER(struct hrtimer_sleeper*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct hrtimer_sleeper\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct hrtimer_sleeper));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->timer);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->task);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_acpi_dock_ops
#define WRAPPER_FOR_struct_acpi_dock_ops
TYPE_WRAPPER(struct acpi_dock_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct acpi_dock_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct acpi_dock_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->handler);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->uevent);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tcp_timewait_sock
#define WRAPPER_FOR_struct_tcp_timewait_sock
TYPE_WRAPPER(struct tcp_timewait_sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tcp_timewait_sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tcp_timewait_sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tw_sk);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tcp6_timewait_sock
#define WRAPPER_FOR_struct_tcp6_timewait_sock
TYPE_WRAPPER(struct tcp6_timewait_sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tcp6_timewait_sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tcp6_timewait_sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tcp6tw_tcp);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_klist_iter
#define WRAPPER_FOR_struct_klist_iter
TYPE_WRAPPER(struct klist_iter*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct klist_iter\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct klist_iter));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->i_klist);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_inet_timewait_death_row
#define WRAPPER_FOR_struct_inet_timewait_death_row
TYPE_WRAPPER(struct inet_timewait_death_row*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct inet_timewait_death_row\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct inet_timewait_death_row));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->twcal_timer);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->twkill_work);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tw_timer);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_class_interface
#define WRAPPER_FOR_struct_class_interface
TYPE_WRAPPER(struct class_interface*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct class_interface\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct class_interface));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->class_);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->add_dev);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->remove_dev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_wait_bit_queue
#define WRAPPER_FOR_struct_wait_bit_queue
TYPE_WRAPPER(struct wait_bit_queue*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct wait_bit_queue\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct wait_bit_queue));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->wait);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_skb_seq_state
#define WRAPPER_FOR_struct_skb_seq_state
TYPE_WRAPPER(struct skb_seq_state*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct skb_seq_state\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct skb_seq_state));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->root_skb);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->cur_skb);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_acpi_pci_driver
#define WRAPPER_FOR_struct_acpi_pci_driver
TYPE_WRAPPER(struct acpi_pci_driver*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct acpi_pci_driver\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct acpi_pci_driver));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->add);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->remove);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_mii_if_info
#define WRAPPER_FOR_struct_mii_if_info
TYPE_WRAPPER(struct mii_if_info*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct mii_if_info\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct mii_if_info));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mdio_read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mdio_write);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_subsys_dev_iter
#define WRAPPER_FOR_struct_subsys_dev_iter
TYPE_WRAPPER(struct subsys_dev_iter*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct subsys_dev_iter\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct subsys_dev_iter));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ki);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netlink_kernel_cfg
#define WRAPPER_FOR_struct_netlink_kernel_cfg
TYPE_WRAPPER(struct netlink_kernel_cfg*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netlink_kernel_cfg\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netlink_kernel_cfg));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->input);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->cb_mutex);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->bind);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_module_version_attribute
#define WRAPPER_FOR_struct_module_version_attribute
TYPE_WRAPPER(struct module_version_attribute*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct module_version_attribute\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct module_version_attribute));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mattr);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_prop_descriptor
#define WRAPPER_FOR_struct_prop_descriptor
TYPE_WRAPPER(struct prop_descriptor*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct prop_descriptor\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct prop_descriptor));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mutex);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tasklet_struct
#define WRAPPER_FOR_struct_tasklet_struct
TYPE_WRAPPER(struct tasklet_struct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tasklet_struct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tasklet_struct));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->func);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_softnet_data
#define WRAPPER_FOR_struct_softnet_data
TYPE_WRAPPER(struct softnet_data*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct softnet_data\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct softnet_data));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->output_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->output_queue_tailp);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->completion_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->process_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rps_ipi_list);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->csd);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->rps_ipi_next);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->input_pkt_queue);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->backlog);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_rtnl_af_ops
#define WRAPPER_FOR_struct_rtnl_af_ops
TYPE_WRAPPER(struct rtnl_af_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct rtnl_af_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct rtnl_af_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fill_link_af);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_link_af_size);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->validate_link_af);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->set_link_af);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pv_time_ops
#define WRAPPER_FOR_struct_pv_time_ops
TYPE_WRAPPER(struct pv_time_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pv_time_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pv_time_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->sched_clock);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->steal_clock);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_tsc_khz);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_x86_init_mpparse
#define WRAPPER_FOR_struct_x86_init_mpparse
TYPE_WRAPPER(struct x86_init_mpparse*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct x86_init_mpparse\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct x86_init_mpparse));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mpc_record);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setup_ioapic_ids);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mpc_apic_id);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->smp_read_mpc_oem);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mpc_oem_pci_bus);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->mpc_oem_bus_info);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->find_smp_config);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_smp_config);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_dm_target_io
#define WRAPPER_FOR_struct_dm_target_io
TYPE_WRAPPER(struct dm_target_io*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct dm_target_io\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct dm_target_io));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ti);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->clone);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_obs_kernel_param
#define WRAPPER_FOR_struct_obs_kernel_param
TYPE_WRAPPER(struct obs_kernel_param*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct obs_kernel_param\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct obs_kernel_param));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setup_func);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_clocksource
#define WRAPPER_FOR_struct_clocksource
TYPE_WRAPPER(struct clocksource*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct clocksource\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct clocksource));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->enable);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->disable);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->suspend);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->resume);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_vm_struct
#define WRAPPER_FOR_struct_vm_struct
TYPE_WRAPPER(struct vm_struct*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct vm_struct\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct vm_struct));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pages);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_miscdevice
#define WRAPPER_FOR_struct_miscdevice
TYPE_WRAPPER(struct miscdevice*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct miscdevice\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct miscdevice));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->parent);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->this_device);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pv_irq_ops
#define WRAPPER_FOR_struct_pv_irq_ops
TYPE_WRAPPER(struct pv_irq_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pv_irq_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pv_irq_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->safe_halt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->halt);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->adjust_exception_frame);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cleancache_ops
#define WRAPPER_FOR_struct_cleancache_ops
TYPE_WRAPPER(struct cleancache_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cleancache_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cleancache_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init_fs);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init_shared_fs);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->get_page);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->put_page);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->invalidate_page);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->invalidate_inode);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->invalidate_fs);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_client_extension
#define WRAPPER_FOR_struct_client_extension
TYPE_WRAPPER(struct client_extension*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct client_extension\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct client_extension));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->iret_handler);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_thread_info
#define WRAPPER_FOR_struct_thread_info
TYPE_WRAPPER(struct thread_info*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct thread_info\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct thread_info));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->task);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->exec_domain);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->restart_block);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->client_data);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_mem_cgroup_reclaim_cookie
#define WRAPPER_FOR_struct_mem_cgroup_reclaim_cookie
TYPE_WRAPPER(struct mem_cgroup_reclaim_cookie*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct mem_cgroup_reclaim_cookie\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct mem_cgroup_reclaim_cookie));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->zone);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_acpi_device_physical_node
#define WRAPPER_FOR_struct_acpi_device_physical_node
TYPE_WRAPPER(struct acpi_device_physical_node*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct acpi_device_physical_node\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct acpi_device_physical_node));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_debug_obj_descr
#define WRAPPER_FOR_struct_debug_obj_descr
TYPE_WRAPPER(struct debug_obj_descr*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct debug_obj_descr\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct debug_obj_descr));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->debug_hint);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fixup_init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fixup_activate);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fixup_destroy);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fixup_free);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fixup_assert_init);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_nl_info
#define WRAPPER_FOR_struct_nl_info
TYPE_WRAPPER(struct nl_info*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct nl_info\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct nl_info));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->nl_net);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ata_port_info
#define WRAPPER_FOR_struct_ata_port_info
TYPE_WRAPPER(struct ata_port_info*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ata_port_info\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ata_port_info));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->port_ops);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_module_use
#define WRAPPER_FOR_struct_module_use
TYPE_WRAPPER(struct module_use*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct module_use\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct module_use));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->source);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->target);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_firmware
#define WRAPPER_FOR_struct_firmware
TYPE_WRAPPER(struct firmware*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct firmware\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct firmware));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pages);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_blk_plug_cb
#define WRAPPER_FOR_struct_blk_plug_cb
TYPE_WRAPPER(struct blk_plug_cb*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct blk_plug_cb\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct blk_plug_cb));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->callback);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_debug_obj
#define WRAPPER_FOR_struct_debug_obj
TYPE_WRAPPER(struct debug_obj*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct debug_obj\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct debug_obj));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->descr);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_x86_init_iommu
#define WRAPPER_FOR_struct_x86_init_iommu
TYPE_WRAPPER(struct x86_init_iommu*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct x86_init_iommu\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct x86_init_iommu));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->iommu_init);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cgroup_scanner
#define WRAPPER_FOR_struct_cgroup_scanner
TYPE_WRAPPER(struct cgroup_scanner*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cgroup_scanner\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cgroup_scanner));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->cg);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->test_task);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->process_task);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->heap);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ida
#define WRAPPER_FOR_struct_ida
TYPE_WRAPPER(struct ida*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ida\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ida));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->idr);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_execute_work
#define WRAPPER_FOR_struct_execute_work
TYPE_WRAPPER(struct execute_work*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct execute_work\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct execute_work));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->work);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_x86_msi_ops
#define WRAPPER_FOR_struct_x86_msi_ops
TYPE_WRAPPER(struct x86_msi_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct x86_msi_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct x86_msi_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setup_msi_irqs);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->teardown_msi_irq);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->teardown_msi_irqs);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->restore_msi_irqs);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_raw6_sock
#define WRAPPER_FOR_struct_raw6_sock
TYPE_WRAPPER(struct raw6_sock*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct raw6_sock\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct raw6_sock));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->inet);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->inet6);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_biovec_slab
#define WRAPPER_FOR_struct_biovec_slab
TYPE_WRAPPER(struct biovec_slab*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct biovec_slab\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct biovec_slab));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->slab);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_packet_offload
#define WRAPPER_FOR_struct_packet_offload
TYPE_WRAPPER(struct packet_offload*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct packet_offload\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct packet_offload));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->callbacks);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tasklet_hrtimer
#define WRAPPER_FOR_struct_tasklet_hrtimer
TYPE_WRAPPER(struct tasklet_hrtimer*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tasklet_hrtimer\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tasklet_hrtimer));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->timer);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tasklet);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->function);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_bio_pair
#define WRAPPER_FOR_struct_bio_pair
TYPE_WRAPPER(struct bio_pair*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct bio_pair\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct bio_pair));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bio1);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bio2);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bv1);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bv2);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bip1);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->bip2);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->iv1);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->iv2);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_rt_mutex
#define WRAPPER_FOR_struct_rt_mutex
TYPE_WRAPPER(struct rt_mutex*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct rt_mutex\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct rt_mutex));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_class_dev_iter
#define WRAPPER_FOR_struct_class_dev_iter
TYPE_WRAPPER(struct class_dev_iter*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct class_dev_iter\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct class_dev_iter));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ki);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_qdisc_watchdog
#define WRAPPER_FOR_struct_qdisc_watchdog
TYPE_WRAPPER(struct qdisc_watchdog*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct qdisc_watchdog\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct qdisc_watchdog));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->timer);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->qdisc);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netlink_skb_parms
#define WRAPPER_FOR_struct_netlink_skb_parms
TYPE_WRAPPER(struct netlink_skb_parms*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netlink_skb_parms\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netlink_skb_parms));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->ssk);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_nf_hook_ops
#define WRAPPER_FOR_struct_nf_hook_ops
TYPE_WRAPPER(struct nf_hook_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct nf_hook_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct nf_hook_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->hook);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->owner);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_uprobe_consumer
#define WRAPPER_FOR_struct_uprobe_consumer
TYPE_WRAPPER(struct uprobe_consumer*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct uprobe_consumer\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct uprobe_consumer));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->handler);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->filter);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->next);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_pm_domain_data
#define WRAPPER_FOR_struct_pm_domain_data
TYPE_WRAPPER(struct pm_domain_data*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct pm_domain_data\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct pm_domain_data));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_cipher_desc
#define WRAPPER_FOR_struct_cipher_desc
TYPE_WRAPPER(struct cipher_desc*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct cipher_desc\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct cipher_desc));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->tfm);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->crfn);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->prfn);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_netlink_dump_control
#define WRAPPER_FOR_struct_netlink_dump_control
TYPE_WRAPPER(struct netlink_dump_control*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct netlink_dump_control\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct netlink_dump_control));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->dump);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->done);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->module);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_x86_io_apic_ops
#define WRAPPER_FOR_struct_x86_io_apic_ops
TYPE_WRAPPER(struct x86_io_apic_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct x86_io_apic_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct x86_io_apic_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->read);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->write);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->modify);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_packet_type
#define WRAPPER_FOR_struct_packet_type
TYPE_WRAPPER(struct packet_type*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct packet_type\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct packet_type));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->dev);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->func);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->id_match);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_subprocess_info
#define WRAPPER_FOR_struct_subprocess_info
TYPE_WRAPPER(struct subprocess_info*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct subprocess_info\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct subprocess_info));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->work);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->cleanup);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_x86_init_ops
#define WRAPPER_FOR_struct_x86_init_ops
TYPE_WRAPPER(struct x86_init_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct x86_init_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct x86_init_ops));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->resources);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mpparse);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->irqs);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->oem);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->mapping);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->paging);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->timers);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->iommu);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pci);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_zap_details
#define WRAPPER_FOR_struct_zap_details
TYPE_WRAPPER(struct zap_details*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct zap_details\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct zap_details));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->nonlinear_vma);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->check_mapping);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_x86_cpuinit_ops
#define WRAPPER_FOR_struct_x86_cpuinit_ops
TYPE_WRAPPER(struct x86_cpuinit_ops*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct x86_cpuinit_ops\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct x86_cpuinit_ops));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setup_percpu_clockev);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->early_percpu_clock_init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->fixup_cpu_id);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_mb_cache_entry
#define WRAPPER_FOR_struct_mb_cache_entry
TYPE_WRAPPER(struct mb_cache_entry*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct mb_cache_entry\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct mb_cache_entry));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->e_cache);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->e_bdev);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_kobj_attribute
#define WRAPPER_FOR_struct_kobj_attribute
TYPE_WRAPPER(struct kobj_attribute*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct kobj_attribute\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct kobj_attribute));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->show);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->store);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_ahash_alg
#define WRAPPER_FOR_struct_ahash_alg
TYPE_WRAPPER(struct ahash_alg*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct ahash_alg\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct ahash_alg));
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->init);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->update);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->final);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->finup);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->digest);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->export_);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->import);
        WRAP_FUNCTION(TO_UNWATCHED_ADDRESS(arg)->setkey);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->halg);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_tick_sched
#define WRAPPER_FOR_struct_tick_sched
TYPE_WRAPPER(struct tick_sched*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct tick_sched\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct tick_sched));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->sched_timer);
    }
   NO_POST
    NO_RETURN
})
#endif


#ifndef WRAPPER_FOR_struct_paravirt_patch_template
#define WRAPPER_FOR_struct_paravirt_patch_template
TYPE_WRAPPER(struct paravirt_patch_template*, {
   PRE{
	     PRE_WRAPPER_KERNEL(arg);
	     D(kern_printk( "kernel wrapperstruct paravirt_patch_template\n");)
	     ADD_TO_HASH( arg, SCAN_HEAD_FUNC(struct paravirt_patch_template));
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pv_init_ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pv_time_ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pv_cpu_ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pv_irq_ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pv_apic_ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pv_mmu_ops);
        WRAP_RECURSIVE(TO_UNWATCHED_ADDRESS(arg)->pv_lock_ops);
    }
   NO_POST
    NO_RETURN
})
#endif


