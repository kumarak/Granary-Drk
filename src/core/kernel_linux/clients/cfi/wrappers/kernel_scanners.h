/* Auto-generated scanning functions. */
#define S(...) __VA_ARGS__

#ifndef SCANNER_FOR_struct_callback_head
#define SCANNER_FOR_struct_callback_head
TYPE_SCAN_WRAPPER(struct callback_head, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct callback_head);
    }
    SCAN {
        S(kern_printk( "struct callback_head\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_FUNCTION(arg.func);
    }
})
#endif


#ifndef SCANNER_FOR_struct_nameidata
#define SCANNER_FOR_struct_nameidata
TYPE_SCAN_WRAPPER(struct nameidata, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct nameidata);
    }
    SCAN {
        S(kern_printk( "struct nameidata\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.path);
        SCAN_RECURSIVE(arg.last);
        SCAN_RECURSIVE(arg.root);
        SCAN_RECURSIVE_PTR(arg.inode);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.seq);
        SCAN_FUNCTION(arg.last_type);
        SCAN_FUNCTION(arg.depth);
//  Array(Pointer(BuiltIn(char))) arg.saved_names
    }
})
#endif



#ifndef SCANNER_FOR_struct_iattr
#define SCANNER_FOR_struct_iattr
TYPE_SCAN_WRAPPER(struct iattr, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct iattr);
    }
    SCAN {
        S(kern_printk( "struct iattr\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.ia_valid);
        SCAN_FUNCTION(arg.ia_mode);
        SCAN_FUNCTION(arg.ia_uid);
        SCAN_FUNCTION(arg.ia_gid);
        SCAN_FUNCTION(arg.ia_size);
        SCAN_RECURSIVE(arg.ia_atime);
        SCAN_RECURSIVE(arg.ia_mtime);
        SCAN_RECURSIVE(arg.ia_ctime);
        SCAN_RECURSIVE_PTR(arg.ia_file);
    }
})
#endif


#ifndef SCANNER_FOR_struct_inode_operations
#define SCANNER_FOR_struct_inode_operations
TYPE_SCAN_WRAPPER(struct inode_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct inode_operations);
    }
    SCAN {
        S(kern_printk( "struct inode_operations\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.lookup);
        SCAN_FUNCTION(arg.follow_link);
        SCAN_FUNCTION(arg.permission);
        SCAN_FUNCTION(arg.get_acl);
        SCAN_FUNCTION(arg.readlink);
        SCAN_FUNCTION(arg.put_link);
        SCAN_FUNCTION(arg.create);
        SCAN_FUNCTION(arg.link);
        SCAN_FUNCTION(arg.unlink);
        SCAN_FUNCTION(arg.symlink);
        SCAN_FUNCTION(arg.mkdir);
        SCAN_FUNCTION(arg.rmdir);
        SCAN_FUNCTION(arg.mknod);
        SCAN_FUNCTION(arg.rename);
        SCAN_FUNCTION(arg.setattr);
        SCAN_FUNCTION(arg.getattr);
        SCAN_FUNCTION(arg.setxattr);
        SCAN_FUNCTION(arg.getxattr);
        SCAN_FUNCTION(arg.listxattr);
        SCAN_FUNCTION(arg.removexattr);
        SCAN_FUNCTION(arg.fiemap);
        SCAN_FUNCTION(arg.update_time);
        SCAN_FUNCTION(arg.atomic_open);
    }
})
#endif


#ifndef SCANNER_FOR_struct_kset_uevent_ops
#define SCANNER_FOR_struct_kset_uevent_ops
TYPE_SCAN_WRAPPER(struct kset_uevent_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct kset_uevent_ops);
    }
    SCAN {
        S(kern_printk( "struct kset_uevent_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.filter);
        SCAN_FUNCTION(arg.name);
        SCAN_FUNCTION(arg.uevent);
    }
})
#endif


//#define SCANNER_FOR_struct_kset
#ifndef SCANNER_FOR_struct_kset
#define SCANNER_FOR_struct_kset
TYPE_SCAN_WRAPPER(struct kset, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct kset);
    }
    SCAN {
        S(kern_printk( "struct kset\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_RECURSIVE(arg.list_lock);
        SCAN_RECURSIVE(arg.kobj);
        SCAN_RECURSIVE_PTR(arg.uevent_ops);
    }
})
#endif


//#define SCANNER_FOR_struct_sysfs_ops
#ifndef SCANNER_FOR_struct_sysfs_ops
#define SCANNER_FOR_struct_sysfs_ops
TYPE_SCAN_WRAPPER(struct sysfs_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct sysfs_ops);
    }
    SCAN {
        S(kern_printk( "struct sysfs_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.show);
        SCAN_FUNCTION(arg.store);
        SCAN_FUNCTION(arg.namespace_);
    }
})
#endif


//#define SCANNER_FOR_struct_kobj_ns_type_operations
#ifndef SCANNER_FOR_struct_kobj_ns_type_operations
#define SCANNER_FOR_struct_kobj_ns_type_operations
TYPE_SCAN_WRAPPER(struct kobj_ns_type_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct kobj_ns_type_operations);
    }
    SCAN {
        S(kern_printk( "struct kobj_ns_type_operations\n");)
        S(SCAN_OBJECT(arg);)
//  Enum(enum kobj_ns_type) arg.type
        SCAN_FUNCTION(arg.grab_current_ns);
        SCAN_FUNCTION(arg.netlink_ns);
        SCAN_FUNCTION(arg.initial_ns);
        SCAN_FUNCTION(arg.drop_ns);
    }
})
#endif


#ifndef SCANNER_FOR_struct_kobj_type
#define SCANNER_FOR_struct_kobj_type
TYPE_SCAN_WRAPPER(struct kobj_type, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct kobj_type);
    }
    SCAN {
        S(kern_printk( "struct kobj_type\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.release);
        SCAN_RECURSIVE_PTR(arg.sysfs_ops);
//  Pointer(Pointer(Use(Struct(struct attribute)))) arg.default_attrs
        SCAN_FUNCTION(arg.child_ns_type);
        SCAN_FUNCTION(arg.namespace_);
    }
})
#endif


#ifndef SCANNER_FOR_struct_kobject
#define SCANNER_FOR_struct_kobject
TYPE_SCAN_WRAPPER(struct kobject, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct kobject);
    }
    SCAN {
        S(kern_printk( "struct kobject\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE(arg.entry);
        SCAN_RECURSIVE_PTR(arg.parent);
        SCAN_RECURSIVE_PTR(arg.kset);
        SCAN_RECURSIVE_PTR(arg.ktype);
        SCAN_RECURSIVE_PTR(arg.sd);
        SCAN_RECURSIVE(arg.kref);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.state_initialized
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.state_in_sysfs
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.state_add_uevent_sent
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.state_remove_uevent_sent
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.uevent_suppress
    }
})
#endif

#ifndef SCANNER_FOR_struct_module_kobject
#define SCANNER_FOR_struct_module_kobject
TYPE_SCAN_WRAPPER(struct module_kobject, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct module_kobject);
    }
    SCAN {
        S(kern_printk( "struct module_kobject\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.kobj);
        SCAN_RECURSIVE_PTR(arg.mod);
        SCAN_RECURSIVE_PTR(arg.drivers_dir);
        SCAN_RECURSIVE_PTR(arg.mp);
    }
})
#endif


#ifndef SCANNER_FOR_struct_module_attribute
#define SCANNER_FOR_struct_module_attribute
TYPE_SCAN_WRAPPER(struct module_attribute, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct module_attribute);
    }
    SCAN {
        S(kern_printk( "struct module_attribute\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.attr);
        SCAN_FUNCTION(arg.show);
        SCAN_FUNCTION(arg.store);
        SCAN_FUNCTION(arg.setup);
        SCAN_FUNCTION(arg.test);
        SCAN_FUNCTION(arg.free);
    }
})
#endif


//#define SCANNER_FOR_struct_kernel_param_ops
#ifndef SCANNER_FOR_struct_kernel_param_ops
#define SCANNER_FOR_struct_kernel_param_ops
TYPE_SCAN_WRAPPER(struct kernel_param_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct kernel_param_ops);
    }
    SCAN {
        S(kern_printk( "struct kernel_param_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.set);
        SCAN_FUNCTION(arg.get);
        SCAN_FUNCTION(arg.free);
    }
})
#endif


//#define SCANNER_FOR_struct_kparam_array
#ifndef SCANNER_FOR_struct_kparam_array
#define SCANNER_FOR_struct_kparam_array
TYPE_SCAN_WRAPPER(struct kparam_array, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct kparam_array);
    }
    SCAN {
        S(kern_printk( "struct kparam_array\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.max);
        SCAN_FUNCTION(arg.elemsize);
        SCAN_FUNCTION(arg.num);
        SCAN_RECURSIVE_PTR(arg.ops);
        SCAN_FUNCTION(arg.elem);
    }
})
#endif


#ifndef SCANNER_FOR_struct_kernel_param
#define SCANNER_FOR_struct_kernel_param
TYPE_SCAN_WRAPPER(struct kernel_param, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct kernel_param);
    }
    SCAN {
        S(kern_printk( "struct kernel_param\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE_PTR(arg.ops);
        SCAN_FUNCTION(arg.perm);
        SCAN_FUNCTION(arg.level);
        SCAN_FUNCTION(arg.arg);
        SCAN_RECURSIVE_PTR(arg.str);
        SCAN_RECURSIVE_PTR(arg.arr);
//  Union(union anon_union_27) None
    }
})
#endif


#ifndef SCANNER_FOR_struct_tracepoint
#define SCANNER_FOR_struct_tracepoint
TYPE_SCAN_WRAPPER(struct tracepoint, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tracepoint);
    }
    SCAN {
        S(kern_printk( "struct tracepoint\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE(arg.key);
        SCAN_FUNCTION(arg.regfunc);
        SCAN_FUNCTION(arg.unregfunc);
        SCAN_RECURSIVE_PTR(arg.funcs);
    }
})
#endif


#ifndef SCANNER_FOR_struct_sched_class
#define SCANNER_FOR_struct_sched_class
TYPE_SCAN_WRAPPER(struct sched_class, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct sched_class);
    }
    SCAN {
        S(kern_printk( "struct sched_class\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_FUNCTION(arg.enqueue_task);
        SCAN_FUNCTION(arg.dequeue_task);
        SCAN_FUNCTION(arg.yield_task);
        SCAN_FUNCTION(arg.yield_to_task);
        SCAN_FUNCTION(arg.check_preempt_curr);
        SCAN_FUNCTION(arg.pick_next_task);
        SCAN_FUNCTION(arg.put_prev_task);
        SCAN_FUNCTION(arg.select_task_rq);
        SCAN_FUNCTION(arg.migrate_task_rq);
        SCAN_FUNCTION(arg.pre_schedule);
        SCAN_FUNCTION(arg.post_schedule);
        SCAN_FUNCTION(arg.task_waking);
        SCAN_FUNCTION(arg.task_woken);
        SCAN_FUNCTION(arg.set_cpus_allowed);
        SCAN_FUNCTION(arg.rq_online);
        SCAN_FUNCTION(arg.rq_offline);
        SCAN_FUNCTION(arg.set_curr_task);
        SCAN_FUNCTION(arg.task_tick);
        SCAN_FUNCTION(arg.task_fork);
        SCAN_FUNCTION(arg.switched_from);
        SCAN_FUNCTION(arg.switched_to);
        SCAN_FUNCTION(arg.prio_changed);
        SCAN_FUNCTION(arg.get_rr_interval);
        SCAN_FUNCTION(arg.task_move_group);
    }
})
#endif


#ifndef SCANNER_FOR_struct_mutex
#define SCANNER_FOR_struct_mutex
TYPE_SCAN_WRAPPER(struct mutex, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct mutex);
    }
    SCAN {
        S(kern_printk( "struct mutex\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.count);
        SCAN_RECURSIVE(arg.wait_lock);
        SCAN_RECURSIVE(arg.wait_list);
        SCAN_RECURSIVE_PTR(arg.owner);
    }
})
#endif


#ifndef SCANNER_FOR_struct_attribute_group
#define SCANNER_FOR_struct_attribute_group
TYPE_SCAN_WRAPPER(struct attribute_group, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct attribute_group);
    }
    SCAN {
        S(kern_printk( "struct attribute_group\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_FUNCTION(arg.is_visible);
        struct attribute *attr = (struct attribute*)*(arg.attrs);
        while(attr != NULL){
            SCAN_RECURSIVE_PTR(attr);
            attr++;
        }
//  Pointer(Pointer(Use(Struct(struct attribute)))) arg.attrs
    }
})
#endif


#ifndef SCANNER_FOR_struct_dev_pm_ops
#define SCANNER_FOR_struct_dev_pm_ops
TYPE_SCAN_WRAPPER(struct dev_pm_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dev_pm_ops);
    }
    SCAN {
        S(kern_printk( "struct dev_pm_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.prepare);
        SCAN_FUNCTION(arg.complete);
        SCAN_FUNCTION(arg.suspend);
        SCAN_FUNCTION(arg.resume);
        SCAN_FUNCTION(arg.freeze);
        SCAN_FUNCTION(arg.thaw);
        SCAN_FUNCTION(arg.poweroff);
        SCAN_FUNCTION(arg.restore);
        SCAN_FUNCTION(arg.suspend_late);
        SCAN_FUNCTION(arg.resume_early);
        SCAN_FUNCTION(arg.freeze_late);
        SCAN_FUNCTION(arg.thaw_early);
        SCAN_FUNCTION(arg.poweroff_late);
        SCAN_FUNCTION(arg.restore_early);
        SCAN_FUNCTION(arg.suspend_noirq);
        SCAN_FUNCTION(arg.resume_noirq);
        SCAN_FUNCTION(arg.freeze_noirq);
        SCAN_FUNCTION(arg.thaw_noirq);
        SCAN_FUNCTION(arg.poweroff_noirq);
        SCAN_FUNCTION(arg.restore_noirq);
        SCAN_FUNCTION(arg.runtime_suspend);
        SCAN_FUNCTION(arg.runtime_resume);
        SCAN_FUNCTION(arg.runtime_idle);
    }
})
#endif


#ifndef SCANNER_FOR_struct_device_type
#define SCANNER_FOR_struct_device_type
TYPE_SCAN_WRAPPER(struct device_type, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct device_type);
    }
    SCAN {
        S(kern_printk( "struct device_type\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        struct attribute_group *attr_group = (struct attribute_group*)*(arg.groups);
        while(attr_group != NULL){
            SCAN_RECURSIVE_PTR(attr_group);
            attr_group++;
        }
//  Pointer(Pointer(Attributed(const , Use(Struct(struct attribute_group))))) arg.groups
        SCAN_FUNCTION(arg.uevent);
        SCAN_FUNCTION(arg.devnode);
        SCAN_FUNCTION(arg.release);
        SCAN_RECURSIVE_PTR(arg.pm);
    }
})
#endif


#ifndef SCANNER_FOR_struct_bus_attribute
#define SCANNER_FOR_struct_bus_attribute
TYPE_SCAN_WRAPPER(struct bus_attribute, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct bus_attribute);
    }
    SCAN {
        S(kern_printk( "struct bus_attribute\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.attr);
        SCAN_FUNCTION(arg.show);
        SCAN_FUNCTION(arg.store);
    }
})
#endif


#ifndef SCANNER_FOR_struct_device_attribute
#define SCANNER_FOR_struct_device_attribute
TYPE_SCAN_WRAPPER(struct device_attribute, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct device_attribute);
    }
    SCAN {
        S(kern_printk( "struct device_attribute\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.attr);
        SCAN_FUNCTION(arg.show);
        SCAN_FUNCTION(arg.store);
    }
})
#endif


#ifndef SCANNER_FOR_struct_device_driver
#define SCANNER_FOR_struct_device_driver
TYPE_SCAN_WRAPPER(struct device_driver, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct device_driver);
    }
    SCAN {
        S(kern_printk( "struct device_driver\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE_PTR(arg.bus);
        SCAN_RECURSIVE_PTR(arg.owner);
        SCAN_FUNCTION(arg.mod_name);
        SCAN_FUNCTION(arg.suppress_bind_attrs);
        SCAN_RECURSIVE_PTR(arg.of_match_table);
        SCAN_RECURSIVE_PTR(arg.acpi_match_table);
        SCAN_FUNCTION(arg.probe);
        SCAN_FUNCTION(arg.remove);
        SCAN_FUNCTION(arg.shutdown);
        SCAN_FUNCTION(arg.suspend);
        SCAN_FUNCTION(arg.resume);
        struct attribute_group *attr_group = (struct attribute_group*)*(arg.groups);
        while(attr_group != NULL){
            SCAN_RECURSIVE_PTR(attr_group);
            attr_group++;
        }
//  Pointer(Pointer(Attributed(const , Use(Struct(struct attribute_group))))) arg.groups
        SCAN_RECURSIVE_PTR(arg.pm);
        SCAN_RECURSIVE_PTR(arg.p);
    }
})
#endif


#ifndef SCANNER_FOR_struct_driver_attribute
#define SCANNER_FOR_struct_driver_attribute
TYPE_SCAN_WRAPPER(struct driver_attribute, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct driver_attribute);
    }
    SCAN {
        S(kern_printk( "struct driver_attribute\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.attr);
        SCAN_FUNCTION(arg.show);
        SCAN_FUNCTION(arg.store);
    }
})
#endif


#ifndef SCANNER_FOR_struct_bus_type
#define SCANNER_FOR_struct_bus_type
TYPE_SCAN_WRAPPER(struct bus_type, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct bus_type);
    }
    SCAN {
        S(kern_printk( "struct bus_type\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_FUNCTION(arg.dev_name);
        SCAN_RECURSIVE_PTR(arg.dev_root);
        SCAN_RECURSIVE_PTR(arg.bus_attrs);
        SCAN_RECURSIVE_PTR(arg.dev_attrs);
        SCAN_RECURSIVE_PTR(arg.drv_attrs);
        SCAN_FUNCTION(arg.match);
        SCAN_FUNCTION(arg.uevent);
        SCAN_FUNCTION(arg.probe);
        SCAN_FUNCTION(arg.remove);
        SCAN_FUNCTION(arg.shutdown);
        SCAN_FUNCTION(arg.suspend);
        SCAN_FUNCTION(arg.resume);
        SCAN_RECURSIVE_PTR(arg.pm);
        SCAN_RECURSIVE_PTR(arg.iommu_ops);
        SCAN_RECURSIVE_PTR(arg.p);
    }
})
#endif


#ifndef SCANNER_FOR_struct_timer_list
#define SCANNER_FOR_struct_timer_list
TYPE_SCAN_WRAPPER(struct timer_list, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct timer_list);
    }
    SCAN {
        S(kern_printk( "struct timer_list\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.entry);
        SCAN_FUNCTION(arg.expires);
        SCAN_RECURSIVE_PTR(arg.base);
        SCAN_FUNCTION(arg.function);
        SCAN_FUNCTION(arg.data);
        SCAN_FUNCTION(arg.slack);
        SCAN_FUNCTION(arg.start_pid);
        SCAN_FUNCTION(arg.start_site);
//  Array(BuiltIn(char)) arg.start_comm
    }
})
#endif


//#define SCANNER_FOR_struct_wakeup_source
#ifndef SCANNER_FOR_struct_wakeup_source
#define SCANNER_FOR_struct_wakeup_source
TYPE_SCAN_WRAPPER(struct wakeup_source, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct wakeup_source);
    }
    SCAN {
        S(kern_printk( "struct wakeup_source\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE(arg.entry);
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE(arg.timer);
        SCAN_FUNCTION(arg.timer_expires);
//  Union(union ktime) arg.total_time
//  Union(union ktime) arg.max_time
//  Union(union ktime) arg.last_time
//  Union(union ktime) arg.start_prevent_time
//  Union(union ktime) arg.prevent_sleep_time
        SCAN_FUNCTION(arg.event_count);
        SCAN_FUNCTION(arg.active_count);
        SCAN_FUNCTION(arg.relax_count);
        SCAN_FUNCTION(arg.expire_count);
        SCAN_FUNCTION(arg.wakeup_count);
//  Bitfield(Use(TypeDef(bool, Use(TypeDef(K_Bool, BuiltIn(int)))))) arg.active
//  Bitfield(Use(TypeDef(bool, Use(TypeDef(K_Bool, BuiltIn(int)))))) arg.autosleep_enabled
    }
})
#endif


//#define SCANNER_FOR_struct_work_struct
#ifndef SCANNER_FOR_struct_work_struct
#define SCANNER_FOR_struct_work_struct
TYPE_SCAN_WRAPPER(struct work_struct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct work_struct);
    }
    SCAN {
        S(kern_printk( "struct work_struct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.data);
        SCAN_RECURSIVE(arg.entry);
        SCAN_FUNCTION(arg.func);
    }
})
#endif


//#define SCANNER_FOR_struct_notifier_block
#ifndef SCANNER_FOR_struct_notifier_block
#define SCANNER_FOR_struct_notifier_block
TYPE_SCAN_WRAPPER(struct notifier_block, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct notifier_block);
    }
    SCAN {
        S(kern_printk( "struct notifier_block\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.notifier_call);
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_FUNCTION(arg.priority);
    }
})
#endif


//#define SCANNER_FOR_struct_blocking_notifier_head
#ifndef SCANNER_FOR_struct_blocking_notifier_head
#define SCANNER_FOR_struct_blocking_notifier_head
TYPE_SCAN_WRAPPER(struct blocking_notifier_head, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct blocking_notifier_head);
    }
    SCAN {
        S(kern_printk( "struct blocking_notifier_head\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.rwsem);
        SCAN_RECURSIVE_PTR(arg.head);
    }
})
#endif


//#define SCANNER_FOR_struct_pm_qos_constraints
#ifndef SCANNER_FOR_struct_pm_qos_constraints
#define SCANNER_FOR_struct_pm_qos_constraints
TYPE_SCAN_WRAPPER(struct pm_qos_constraints, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pm_qos_constraints);
    }
    SCAN {
        S(kern_printk( "struct pm_qos_constraints\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_FUNCTION(arg.target_value);
        SCAN_FUNCTION(arg.default_value);
//  Enum(enum pm_qos_type) arg.type
        SCAN_RECURSIVE_PTR(arg.notifiers);
    }
})
#endif


//#define SCANNER_FOR_struct_dev_pm_qos_request
#ifndef SCANNER_FOR_struct_dev_pm_qos_request
#define SCANNER_FOR_struct_dev_pm_qos_request
TYPE_SCAN_WRAPPER(struct dev_pm_qos_request, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dev_pm_qos_request);
    }
    SCAN {
        S(kern_printk( "struct dev_pm_qos_request\n");)
        S(SCAN_OBJECT(arg);)
//  Enum(enum dev_pm_qos_req_type) arg.type
//  Union(union anon_union_61) arg.data
        SCAN_RECURSIVE_PTR(arg.dev);
    }
})
#endif


//#define SCANNER_FOR_struct_dev_pm_qos
#ifndef SCANNER_FOR_struct_dev_pm_qos
#define SCANNER_FOR_struct_dev_pm_qos
TYPE_SCAN_WRAPPER(struct dev_pm_qos, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dev_pm_qos);
    }
    SCAN {
        S(kern_printk( "struct dev_pm_qos\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.latency);
        SCAN_RECURSIVE(arg.flags);
        SCAN_RECURSIVE_PTR(arg.latency_req);
        SCAN_RECURSIVE_PTR(arg.flags_req);
    }
})
#endif


//#define SCANNER_FOR_struct_dev_pm_info
#ifndef SCANNER_FOR_struct_dev_pm_info
#define SCANNER_FOR_struct_dev_pm_info
TYPE_SCAN_WRAPPER(struct dev_pm_info, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dev_pm_info);
    }
    SCAN {
        S(kern_printk( "struct dev_pm_info\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.power_state);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.can_wakeup
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.async_suspend
//  Bitfield(Use(TypeDef(bool, Use(TypeDef(K_Bool, BuiltIn(int)))))) arg.is_prepared
//  Bitfield(Use(TypeDef(bool, Use(TypeDef(K_Bool, BuiltIn(int)))))) arg.is_suspended
//  Bitfield(Use(TypeDef(bool, Use(TypeDef(K_Bool, BuiltIn(int)))))) arg.ignore_children
//  Bitfield(Use(TypeDef(bool, Use(TypeDef(K_Bool, BuiltIn(int)))))) arg.early_init
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE(arg.entry);
        SCAN_RECURSIVE(arg.completion);
        SCAN_RECURSIVE_PTR(arg.wakeup);
//  Bitfield(Use(TypeDef(bool, Use(TypeDef(K_Bool, BuiltIn(int)))))) arg.wakeup_path
//  Bitfield(Use(TypeDef(bool, Use(TypeDef(K_Bool, BuiltIn(int)))))) arg.syscore
        SCAN_RECURSIVE(arg.suspend_timer);
        SCAN_FUNCTION(arg.timer_expires);
        SCAN_RECURSIVE(arg.work);
        SCAN_RECURSIVE(arg.wait_queue);
        SCAN_RECURSIVE(arg.usage_count);
        SCAN_RECURSIVE(arg.child_count);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.disable_depth
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.idle_notification
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.request_pending
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.deferred_resume
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.run_wake
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.runtime_auto
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.no_callbacks
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.irq_safe
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.use_autosuspend
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.timer_autosuspends
//  Enum(enum rpm_request) arg.request
//  Enum(enum rpm_status) arg.runtime_status
        SCAN_FUNCTION(arg.runtime_error);
        SCAN_FUNCTION(arg.autosuspend_delay);
        SCAN_FUNCTION(arg.last_busy);
        SCAN_FUNCTION(arg.active_jiffies);
        SCAN_FUNCTION(arg.suspended_jiffies);
        SCAN_FUNCTION(arg.accounting_timestamp);
        SCAN_RECURSIVE_PTR(arg.subsys_data);
        SCAN_RECURSIVE_PTR(arg.qos);
    }
})
#endif


//#define SCANNER_FOR_struct_dev_pm_domain
#ifndef SCANNER_FOR_struct_dev_pm_domain
#define SCANNER_FOR_struct_dev_pm_domain
TYPE_SCAN_WRAPPER(struct dev_pm_domain, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dev_pm_domain);
    }
    SCAN {
        S(kern_printk( "struct dev_pm_domain\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.ops);
    }
})
#endif


//#define SCANNER_FOR_struct_dma_map_ops
#ifndef SCANNER_FOR_struct_dma_map_ops
#define SCANNER_FOR_struct_dma_map_ops
TYPE_SCAN_WRAPPER(struct dma_map_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dma_map_ops);
    }
    SCAN {
        S(kern_printk( "struct dma_map_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.alloc);
        SCAN_FUNCTION(arg.free);
        SCAN_FUNCTION(arg.mmap);
        SCAN_FUNCTION(arg.get_sgtable);
        SCAN_FUNCTION(arg.map_page);
        SCAN_FUNCTION(arg.unmap_page);
        SCAN_FUNCTION(arg.map_sg);
        SCAN_FUNCTION(arg.unmap_sg);
        SCAN_FUNCTION(arg.sync_single_for_cpu);
        SCAN_FUNCTION(arg.sync_single_for_device);
        SCAN_FUNCTION(arg.sync_sg_for_cpu);
        SCAN_FUNCTION(arg.sync_sg_for_device);
        SCAN_FUNCTION(arg.mapping_error);
        SCAN_FUNCTION(arg.dma_supported);
        SCAN_FUNCTION(arg.set_dma_mask);
        SCAN_FUNCTION(arg.is_phys);
    }
})
#endif


//#define SCANNER_FOR_struct_dev_archdata
#ifndef SCANNER_FOR_struct_dev_archdata
#define SCANNER_FOR_struct_dev_archdata
TYPE_SCAN_WRAPPER(struct dev_archdata, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dev_archdata);
    }
    SCAN {
        S(kern_printk( "struct dev_archdata\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.dma_ops);
        SCAN_FUNCTION(arg.iommu);
    }
})
#endif


//#define SCANNER_FOR_struct_class_attribute
#ifndef SCANNER_FOR_struct_class_attribute
#define SCANNER_FOR_struct_class_attribute
TYPE_SCAN_WRAPPER(struct class_attribute, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct class_attribute);
    }
    SCAN {
        S(kern_printk( "struct class_attribute\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.attr);
        SCAN_FUNCTION(arg.show);
        SCAN_FUNCTION(arg.store);
        SCAN_FUNCTION(arg.namespace_);
    }
})
#endif


//#define SCANNER_FOR_struct_bin_attribute
#ifndef SCANNER_FOR_struct_bin_attribute
#define SCANNER_FOR_struct_bin_attribute
TYPE_SCAN_WRAPPER(struct bin_attribute, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct bin_attribute);
    }
    SCAN {
        S(kern_printk( "struct bin_attribute\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.attr);
        SCAN_FUNCTION(arg.size);
        SCAN_FUNCTION(arg.private_);
        SCAN_FUNCTION(arg.read);
        SCAN_FUNCTION(arg.write);
        SCAN_FUNCTION(arg.mmap);
    }
})
#endif


//#define SCANNER_FOR_struct_class_
#ifndef SCANNER_FOR_struct_class_
#define SCANNER_FOR_struct_class_
TYPE_SCAN_WRAPPER(struct class_, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct class_);
    }
    SCAN {
        S(kern_printk( "struct class_\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE_PTR(arg.owner);
        SCAN_RECURSIVE_PTR(arg.class_attrs);
        SCAN_RECURSIVE_PTR(arg.dev_attrs);
        SCAN_RECURSIVE_PTR(arg.dev_bin_attrs);
        SCAN_RECURSIVE_PTR(arg.dev_kobj);
        SCAN_FUNCTION(arg.dev_uevent);
        SCAN_FUNCTION(arg.devnode);
        SCAN_FUNCTION(arg.class_release);
        SCAN_FUNCTION(arg.dev_release);
        SCAN_FUNCTION(arg.suspend);
        SCAN_FUNCTION(arg.resume);
        SCAN_RECURSIVE_PTR(arg.ns_type);
        SCAN_FUNCTION(arg.namespace_);
        SCAN_RECURSIVE_PTR(arg.pm);
        SCAN_RECURSIVE_PTR(arg.p);
    }
})
#endif


//#define SCANNER_FOR_struct_device
#ifndef SCANNER_FOR_struct_device
#define SCANNER_FOR_struct_device
TYPE_SCAN_WRAPPER(struct device, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct device);
    }
    SCAN {
        S(kern_printk( "struct device\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.parent);
        SCAN_RECURSIVE_PTR(arg.p);
        SCAN_RECURSIVE(arg.kobj);
        SCAN_FUNCTION(arg.init_name);
        SCAN_RECURSIVE_PTR(arg.type);
        SCAN_RECURSIVE(arg.mutex);
        SCAN_RECURSIVE_PTR(arg.bus);
        SCAN_RECURSIVE_PTR(arg.driver);
        SCAN_FUNCTION(arg.platform_data);
        SCAN_RECURSIVE(arg.power);
        SCAN_RECURSIVE_PTR(arg.pm_domain);
        SCAN_FUNCTION(arg.numa_node);
        SCAN_FUNCTION(arg.dma_mask);
        SCAN_FUNCTION(arg.coherent_dma_mask);
        SCAN_RECURSIVE_PTR(arg.dma_parms);
        SCAN_RECURSIVE(arg.dma_pools);
        SCAN_RECURSIVE_PTR(arg.dma_mem);
        SCAN_RECURSIVE(arg.archdata);
        SCAN_RECURSIVE_PTR(arg.of_node);
        SCAN_RECURSIVE(arg.acpi_node);
        SCAN_FUNCTION(arg.devt);
        SCAN_FUNCTION(arg.id);
        SCAN_RECURSIVE(arg.devres_lock);
        SCAN_RECURSIVE(arg.devres_head);
        SCAN_RECURSIVE(arg.knode_class);
        SCAN_RECURSIVE_PTR(arg.class_);
//  Pointer(Pointer(Attributed(const , Use(Struct(struct attribute_group))))) arg.groups
        SCAN_FUNCTION(arg.release);
        SCAN_RECURSIVE_PTR(arg.iommu_group);
    }
})
#endif


//#define SCANNER_FOR_struct_hd_struct
#ifndef SCANNER_FOR_struct_hd_struct
#define SCANNER_FOR_struct_hd_struct
TYPE_SCAN_WRAPPER(struct hd_struct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct hd_struct);
    }
    SCAN {
        S(kern_printk( "struct hd_struct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.start_sect);
        SCAN_FUNCTION(arg.nr_sects);
        SCAN_RECURSIVE(arg.nr_sects_seq);
        SCAN_FUNCTION(arg.alignment_offset);
        SCAN_FUNCTION(arg.discard_alignment);
        SCAN_RECURSIVE(arg.__dev);
        SCAN_RECURSIVE_PTR(arg.holder_dir);
        SCAN_FUNCTION(arg.policy);
        SCAN_FUNCTION(arg.partno);
        SCAN_RECURSIVE_PTR(arg.info);
        SCAN_FUNCTION(arg.stamp);
//  Array(Use(TypeDef(atomic_t, Struct(atomic_t)))) arg.in_flight
        SCAN_RECURSIVE_PTR(arg.dkstats);
        SCAN_RECURSIVE(arg.ref);
        SCAN_RECURSIVE(arg.callback_head);
    }
})
#endif


//#define SCANNER_FOR_struct_disk_part_tbl
#ifndef SCANNER_FOR_struct_disk_part_tbl
#define SCANNER_FOR_struct_disk_part_tbl
TYPE_SCAN_WRAPPER(struct disk_part_tbl, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct disk_part_tbl);
    }
    SCAN {
        S(kern_printk( "struct disk_part_tbl\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.callback_head);
        SCAN_FUNCTION(arg.len);
        SCAN_RECURSIVE_PTR(arg.last_lookup);
//  Array(Pointer(Use(Struct(struct hd_struct)))) arg.part
    }
})
#endif


//#define SCANNER_FOR_struct_block_device_operations
#ifndef SCANNER_FOR_struct_block_device_operations
#define SCANNER_FOR_struct_block_device_operations
TYPE_SCAN_WRAPPER(struct block_device_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct block_device_operations);
    }
    SCAN {
        S(kern_printk( "struct block_device_operations\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.open);
        SCAN_FUNCTION(arg.release);
        SCAN_FUNCTION(arg.ioctl);
        SCAN_FUNCTION(arg.compat_ioctl);
        SCAN_FUNCTION(arg.direct_access);
        SCAN_FUNCTION(arg.check_events);
        SCAN_FUNCTION(arg.media_changed);
        SCAN_FUNCTION(arg.unlock_native_capacity);
        SCAN_FUNCTION(arg.revalidate_disk);
        SCAN_FUNCTION(arg.getgeo);
        SCAN_FUNCTION(arg.swap_slot_free_notify);
        SCAN_RECURSIVE_PTR(arg.owner);
    }
})
#endif


//#define SCANNER_FOR_struct_call_single_data
#ifndef SCANNER_FOR_struct_call_single_data
#define SCANNER_FOR_struct_call_single_data
TYPE_SCAN_WRAPPER(struct call_single_data, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct call_single_data);
    }
    SCAN {
        S(kern_printk( "struct call_single_data\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_FUNCTION(arg.func);
        SCAN_FUNCTION(arg.info);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.priv);
    }
})
#endif


//#define SCANNER_FOR_struct_kmem_cache_cpu
#ifndef SCANNER_FOR_struct_kmem_cache_cpu
#define SCANNER_FOR_struct_kmem_cache_cpu
TYPE_SCAN_WRAPPER(struct kmem_cache_cpu, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct kmem_cache_cpu);
    }
    SCAN {
        S(kern_printk( "struct kmem_cache_cpu\n");)
        S(SCAN_OBJECT(arg);)
//  Pointer(Pointer(BuiltIn(void))) arg.freelist
        SCAN_FUNCTION(arg.tid);
        SCAN_RECURSIVE_PTR(arg.page);
        SCAN_RECURSIVE_PTR(arg.partial);
    }
})
#endif


//#define SCANNER_FOR_struct_kmem_cache
#ifndef SCANNER_FOR_struct_kmem_cache
#define SCANNER_FOR_struct_kmem_cache
TYPE_SCAN_WRAPPER(struct kmem_cache, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct kmem_cache);
    }
    SCAN {
        S(kern_printk( "struct kmem_cache\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.cpu_slab);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.min_partial);
        SCAN_FUNCTION(arg.size);
        SCAN_FUNCTION(arg.object_size);
        SCAN_FUNCTION(arg.offset);
        SCAN_FUNCTION(arg.cpu_partial);
        SCAN_RECURSIVE(arg.oo);
        SCAN_RECURSIVE(arg.max);
        SCAN_RECURSIVE(arg.min);
        SCAN_FUNCTION(arg.allocflags);
        SCAN_FUNCTION(arg.refcount);
        SCAN_FUNCTION(arg.ctor);
        SCAN_FUNCTION(arg.inuse);
        SCAN_FUNCTION(arg.align);
        SCAN_FUNCTION(arg.reserved);
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE(arg.list);
        SCAN_RECURSIVE(arg.kobj);
        SCAN_FUNCTION(arg.remote_node_defrag_ratio);
//  Array(Pointer(Use(Struct(struct kmem_cache_node)))) arg.node
    }
})
#endif


//#define SCANNER_FOR_struct_io_cq
#ifndef SCANNER_FOR_struct_io_cq
#define SCANNER_FOR_struct_io_cq
TYPE_SCAN_WRAPPER(struct io_cq, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct io_cq);
    }
    SCAN {
        S(kern_printk( "struct io_cq\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.q);
        SCAN_RECURSIVE_PTR(arg.ioc);
//  Union(union anon_union_70) None
//  Union(union anon_union_71) None
        SCAN_FUNCTION(arg.flags);
    }
})
#endif


//#define SCANNER_FOR_struct_io_context
#ifndef SCANNER_FOR_struct_io_context
#define SCANNER_FOR_struct_io_context
TYPE_SCAN_WRAPPER(struct io_context, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct io_context);
    }
    SCAN {
        S(kern_printk( "struct io_context\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.refcount);
        SCAN_RECURSIVE(arg.active_ref);
        SCAN_RECURSIVE(arg.nr_tasks);
        SCAN_RECURSIVE(arg.lock);
        SCAN_FUNCTION(arg.ioprio);
        SCAN_FUNCTION(arg.nr_batch_requests);
        SCAN_FUNCTION(arg.last_waited);
        SCAN_RECURSIVE(arg.icq_tree);
        SCAN_RECURSIVE_PTR(arg.icq_hint);
        SCAN_RECURSIVE(arg.icq_list);
        SCAN_RECURSIVE(arg.release_work);
    }
})
#endif


//#define SCANNER_FOR_struct_cgroup
#ifndef SCANNER_FOR_struct_cgroup
#define SCANNER_FOR_struct_cgroup
TYPE_SCAN_WRAPPER(struct cgroup, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cgroup);
    }
    SCAN {
        S(kern_printk( "struct cgroup\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.flags);
        SCAN_RECURSIVE(arg.count);
        SCAN_FUNCTION(arg.id);
        SCAN_RECURSIVE(arg.sibling);
        SCAN_RECURSIVE(arg.children);
        SCAN_RECURSIVE(arg.files);
        SCAN_RECURSIVE_PTR(arg.parent);
        SCAN_RECURSIVE_PTR(arg.dentry);
//  Array(Pointer(Use(Struct(struct cgroup_subsys_state)))) arg.subsys
        SCAN_RECURSIVE_PTR(arg.root);
        SCAN_RECURSIVE_PTR(arg.top_cgroup);
        SCAN_RECURSIVE(arg.css_sets);
        SCAN_RECURSIVE(arg.allcg_node);
        SCAN_RECURSIVE(arg.cft_q_node);
        SCAN_RECURSIVE(arg.release_list);
        SCAN_RECURSIVE(arg.pidlists);
        SCAN_RECURSIVE(arg.pidlist_mutex);
        SCAN_RECURSIVE(arg.callback_head);
        SCAN_RECURSIVE(arg.event_list);
        SCAN_RECURSIVE(arg.event_list_lock);
        SCAN_RECURSIVE(arg.xattrs);
    }
})
#endif


//#define SCANNER_FOR_struct_cgroup_subsys_state
#ifndef SCANNER_FOR_struct_cgroup_subsys_state
#define SCANNER_FOR_struct_cgroup_subsys_state
TYPE_SCAN_WRAPPER(struct cgroup_subsys_state, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cgroup_subsys_state);
    }
    SCAN {
        S(kern_printk( "struct cgroup_subsys_state\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.cgroup);
        SCAN_RECURSIVE(arg.refcnt);
        SCAN_FUNCTION(arg.flags);
        SCAN_RECURSIVE_PTR(arg.id);
        SCAN_RECURSIVE(arg.dput_work);
    }
})
#endif


//#define SCANNER_FOR_struct_bio_vec
#ifndef SCANNER_FOR_struct_bio_vec
#define SCANNER_FOR_struct_bio_vec
TYPE_SCAN_WRAPPER(struct bio_vec, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct bio_vec);
    }
    SCAN {
        S(kern_printk( "struct bio_vec\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.bv_page);
        SCAN_FUNCTION(arg.bv_len);
        SCAN_FUNCTION(arg.bv_offset);
    }
})
#endif


//#define SCANNER_FOR_struct_bio_integrity_payload
#ifndef SCANNER_FOR_struct_bio_integrity_payload
#define SCANNER_FOR_struct_bio_integrity_payload
TYPE_SCAN_WRAPPER(struct bio_integrity_payload, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct bio_integrity_payload);
    }
    SCAN {
        S(kern_printk( "struct bio_integrity_payload\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.bip_bio);
        SCAN_FUNCTION(arg.bip_sector);
        SCAN_FUNCTION(arg.bip_buf);
        SCAN_FUNCTION(arg.bip_end_io);
        SCAN_FUNCTION(arg.bip_size);
        SCAN_FUNCTION(arg.bip_slab);
        SCAN_FUNCTION(arg.bip_vcnt);
        SCAN_FUNCTION(arg.bip_idx);
        SCAN_RECURSIVE(arg.bip_work);
//  Array(Use(Struct(struct bio_vec))) arg.bip_vec
    }
})
#endif


//#define SCANNER_FOR_struct_mempool_s
#ifndef SCANNER_FOR_struct_mempool_s
#define SCANNER_FOR_struct_mempool_s
TYPE_SCAN_WRAPPER(struct mempool_s, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct mempool_s);
    }
    SCAN {
        S(kern_printk( "struct mempool_s\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.lock);
        SCAN_FUNCTION(arg.min_nr);
        SCAN_FUNCTION(arg.curr_nr);
//  Pointer(Pointer(BuiltIn(void))) arg.elements
        SCAN_FUNCTION(arg.pool_data);
        SCAN_FUNCTION(arg.alloc);
        SCAN_FUNCTION(arg.free);
        SCAN_RECURSIVE(arg.wait);
    }
})
#endif


//#define SCANNER_FOR_struct_bio_set
#ifndef SCANNER_FOR_struct_bio_set
#define SCANNER_FOR_struct_bio_set
TYPE_SCAN_WRAPPER(struct bio_set, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct bio_set);
    }
    SCAN {
        S(kern_printk( "struct bio_set\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.bio_slab);
        SCAN_FUNCTION(arg.front_pad);
        SCAN_RECURSIVE_PTR(arg.bio_pool);
        SCAN_RECURSIVE_PTR(arg.bio_integrity_pool);
        SCAN_RECURSIVE_PTR(arg.bvec_pool);
    }
})
#endif


//#define SCANNER_FOR_struct_bio
#ifndef SCANNER_FOR_struct_bio
#define SCANNER_FOR_struct_bio
TYPE_SCAN_WRAPPER(struct bio, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct bio);
    }
    SCAN {
        S(kern_printk( "struct bio\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.bi_sector);
        SCAN_RECURSIVE_PTR(arg.bi_next);
        SCAN_RECURSIVE_PTR(arg.bi_bdev);
        SCAN_FUNCTION(arg.bi_flags);
        SCAN_FUNCTION(arg.bi_rw);
        SCAN_FUNCTION(arg.bi_vcnt);
        SCAN_FUNCTION(arg.bi_idx);
        SCAN_FUNCTION(arg.bi_phys_segments);
        SCAN_FUNCTION(arg.bi_size);
        SCAN_FUNCTION(arg.bi_seg_front_size);
        SCAN_FUNCTION(arg.bi_seg_back_size);
        SCAN_FUNCTION(arg.bi_end_io);
        SCAN_FUNCTION(arg.bi_private);
        SCAN_RECURSIVE_PTR(arg.bi_ioc);
        SCAN_RECURSIVE_PTR(arg.bi_css);
        SCAN_RECURSIVE_PTR(arg.bi_integrity);
        SCAN_FUNCTION(arg.bi_max_vecs);
        SCAN_RECURSIVE(arg.bi_cnt);
        SCAN_RECURSIVE_PTR(arg.bi_io_vec);
        SCAN_RECURSIVE_PTR(arg.bi_pool);
//  Array(Use(Struct(struct bio_vec))) arg.bi_inline_vecs
    }
})
#endif


//#define SCANNER_FOR_struct_request_list
#ifndef SCANNER_FOR_struct_request_list
#define SCANNER_FOR_struct_request_list
TYPE_SCAN_WRAPPER(struct request_list, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct request_list);
    }
    SCAN {
        S(kern_printk( "struct request_list\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.q);
        SCAN_RECURSIVE_PTR(arg.blkg);
//  Array(BuiltIn(int)) arg.count
//  Array(BuiltIn(int)) arg.starved
        SCAN_RECURSIVE_PTR(arg.rq_pool);
//  Array(Use(TypeDef(wait_queue_head_t, Use(Struct(struct __wait_queue_head))))) arg.wait
        SCAN_FUNCTION(arg.flags);
    }
})
#endif


//#define SCANNER_FOR_struct_request
#ifndef SCANNER_FOR_struct_request
#define SCANNER_FOR_struct_request
TYPE_SCAN_WRAPPER(struct request, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct request);
    }
    SCAN {
        S(kern_printk( "struct request\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.queuelist);
        SCAN_RECURSIVE(arg.csd);
        SCAN_RECURSIVE_PTR(arg.q);
        SCAN_FUNCTION(arg.cmd_flags);
//  Enum(enum rq_cmd_type_bits) arg.cmd_type
        SCAN_FUNCTION(arg.atomic_flags);
        SCAN_FUNCTION(arg.cpu);
        SCAN_FUNCTION(arg.__data_len);
        SCAN_FUNCTION(arg.__sector);
        SCAN_RECURSIVE_PTR(arg.bio);
        SCAN_RECURSIVE_PTR(arg.biotail);
        SCAN_RECURSIVE(arg.hash);
//  Union(union anon_union_89) None
//  Union(union anon_union_90) None
        SCAN_RECURSIVE_PTR(arg.rq_disk);
        SCAN_RECURSIVE_PTR(arg.part);
        SCAN_FUNCTION(arg.start_time);
        SCAN_RECURSIVE_PTR(arg.rl);
        SCAN_FUNCTION(arg.start_time_ns);
        SCAN_FUNCTION(arg.io_start_time_ns);
        SCAN_FUNCTION(arg.nr_phys_segments);
        SCAN_FUNCTION(arg.nr_integrity_segments);
        SCAN_FUNCTION(arg.ioprio);
        SCAN_FUNCTION(arg.ref_count);
        SCAN_FUNCTION(arg.special);
        SCAN_FUNCTION(arg.buffer);
        SCAN_FUNCTION(arg.tag);
        SCAN_FUNCTION(arg.errors);
//  Array(Attributed(unsigned , BuiltIn(char))) arg.__cmd
        SCAN_FUNCTION(arg.cmd);
        SCAN_FUNCTION(arg.cmd_len);
        SCAN_FUNCTION(arg.extra_len);
        SCAN_FUNCTION(arg.sense_len);
        SCAN_FUNCTION(arg.resid_len);
        SCAN_FUNCTION(arg.sense);
        SCAN_FUNCTION(arg.deadline);
        SCAN_RECURSIVE(arg.timeout_list);
        SCAN_FUNCTION(arg.timeout);
        SCAN_FUNCTION(arg.retries);
        SCAN_FUNCTION(arg.end_io);
        SCAN_FUNCTION(arg.end_io_data);
        SCAN_RECURSIVE_PTR(arg.next_rq);
    }
})
#endif


//#define SCANNER_FOR_struct_elevator_ops
#ifndef SCANNER_FOR_struct_elevator_ops
#define SCANNER_FOR_struct_elevator_ops
TYPE_SCAN_WRAPPER(struct elevator_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct elevator_ops);
    }
    SCAN {
        S(kern_printk( "struct elevator_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.elevator_merge_fn);
        SCAN_FUNCTION(arg.elevator_merged_fn);
        SCAN_FUNCTION(arg.elevator_merge_req_fn);
        SCAN_FUNCTION(arg.elevator_allow_merge_fn);
        SCAN_FUNCTION(arg.elevator_bio_merged_fn);
        SCAN_FUNCTION(arg.elevator_dispatch_fn);
        SCAN_FUNCTION(arg.elevator_add_req_fn);
        SCAN_FUNCTION(arg.elevator_activate_req_fn);
        SCAN_FUNCTION(arg.elevator_deactivate_req_fn);
        SCAN_FUNCTION(arg.elevator_completed_req_fn);
        SCAN_FUNCTION(arg.elevator_former_req_fn);
        SCAN_FUNCTION(arg.elevator_latter_req_fn);
        SCAN_FUNCTION(arg.elevator_init_icq_fn);
        SCAN_FUNCTION(arg.elevator_exit_icq_fn);
        SCAN_FUNCTION(arg.elevator_set_req_fn);
        SCAN_FUNCTION(arg.elevator_put_req_fn);
        SCAN_FUNCTION(arg.elevator_may_queue_fn);
        SCAN_FUNCTION(arg.elevator_init_fn);
        SCAN_FUNCTION(arg.elevator_exit_fn);
    }
})
#endif


//#define SCANNER_FOR_struct_elv_fs_entry
#ifndef SCANNER_FOR_struct_elv_fs_entry
#define SCANNER_FOR_struct_elv_fs_entry
TYPE_SCAN_WRAPPER(struct elv_fs_entry, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct elv_fs_entry);
    }
    SCAN {
        S(kern_printk( "struct elv_fs_entry\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.attr);
        SCAN_FUNCTION(arg.show);
        SCAN_FUNCTION(arg.store);
    }
})
#endif


//#define SCANNER_FOR_struct_elevator_type
#ifndef SCANNER_FOR_struct_elevator_type
#define SCANNER_FOR_struct_elevator_type
TYPE_SCAN_WRAPPER(struct elevator_type, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct elevator_type);
    }
    SCAN {
        S(kern_printk( "struct elevator_type\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.icq_cache);
        SCAN_RECURSIVE(arg.ops);
        SCAN_FUNCTION(arg.icq_size);
        SCAN_FUNCTION(arg.icq_align);
        SCAN_RECURSIVE_PTR(arg.elevator_attrs);
//  Array(BuiltIn(char)) arg.elevator_name
        SCAN_RECURSIVE_PTR(arg.elevator_owner);
//  Array(BuiltIn(char)) arg.icq_cache_name
        SCAN_RECURSIVE(arg.list);
    }
})
#endif


//#define SCANNER_FOR_struct_elevator_queue
#ifndef SCANNER_FOR_struct_elevator_queue
#define SCANNER_FOR_struct_elevator_queue
TYPE_SCAN_WRAPPER(struct elevator_queue, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct elevator_queue);
    }
    SCAN {
        S(kern_printk( "struct elevator_queue\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.type);
        SCAN_FUNCTION(arg.elevator_data);
        SCAN_RECURSIVE(arg.kobj);
        SCAN_RECURSIVE(arg.sysfs_lock);
        SCAN_RECURSIVE_PTR(arg.hash);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.registered
    }
})
#endif


//#define SCANNER_FOR_struct_bvec_merge_data
#ifndef SCANNER_FOR_struct_bvec_merge_data
#define SCANNER_FOR_struct_bvec_merge_data
TYPE_SCAN_WRAPPER(struct bvec_merge_data, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct bvec_merge_data);
    }
    SCAN {
        S(kern_printk( "struct bvec_merge_data\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.bi_bdev);
        SCAN_FUNCTION(arg.bi_sector);
        SCAN_FUNCTION(arg.bi_size);
        SCAN_FUNCTION(arg.bi_rw);
    }
})
#endif


//#define SCANNER_FOR_struct_delayed_work
#ifndef SCANNER_FOR_struct_delayed_work
#define SCANNER_FOR_struct_delayed_work
TYPE_SCAN_WRAPPER(struct delayed_work, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct delayed_work);
    }
    SCAN {
        S(kern_printk( "struct delayed_work\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.work);
        SCAN_RECURSIVE(arg.timer);
        SCAN_FUNCTION(arg.cpu);
    }
})
#endif


//#define SCANNER_FOR_struct_bdi_writeback
#ifndef SCANNER_FOR_struct_bdi_writeback
#define SCANNER_FOR_struct_bdi_writeback
TYPE_SCAN_WRAPPER(struct bdi_writeback, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct bdi_writeback);
    }
    SCAN {
        S(kern_printk( "struct bdi_writeback\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.bdi);
        SCAN_FUNCTION(arg.nr);
        SCAN_FUNCTION(arg.last_old_flush);
        SCAN_FUNCTION(arg.last_active);
        SCAN_RECURSIVE_PTR(arg.task);
        SCAN_RECURSIVE(arg.wakeup_timer);
        SCAN_RECURSIVE(arg.b_dirty);
        SCAN_RECURSIVE(arg.b_io);
        SCAN_RECURSIVE(arg.b_more_io);
        SCAN_RECURSIVE(arg.list_lock);
    }
})
#endif


//#define SCANNER_FOR_struct_backing_dev_info
#ifndef SCANNER_FOR_struct_backing_dev_info
#define SCANNER_FOR_struct_backing_dev_info
TYPE_SCAN_WRAPPER(struct backing_dev_info, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct backing_dev_info);
    }
    SCAN {
        S(kern_printk( "struct backing_dev_info\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.bdi_list);
        SCAN_FUNCTION(arg.ra_pages);
        SCAN_FUNCTION(arg.state);
        SCAN_FUNCTION(arg.capabilities);
        SCAN_FUNCTION(arg.congested_fn);
        SCAN_FUNCTION(arg.congested_data);
        SCAN_FUNCTION(arg.name);
//  Array(Use(Struct(struct percpu_counter))) arg.bdi_stat
        SCAN_FUNCTION(arg.bw_time_stamp);
        SCAN_FUNCTION(arg.dirtied_stamp);
        SCAN_FUNCTION(arg.written_stamp);
        SCAN_FUNCTION(arg.write_bandwidth);
        SCAN_FUNCTION(arg.avg_write_bandwidth);
        SCAN_FUNCTION(arg.dirty_ratelimit);
        SCAN_FUNCTION(arg.balanced_dirty_ratelimit);
        SCAN_RECURSIVE(arg.completions);
        SCAN_FUNCTION(arg.dirty_exceeded);
        SCAN_FUNCTION(arg.min_ratio);
        SCAN_FUNCTION(arg.max_ratio);
        SCAN_FUNCTION(arg.max_prop_frac);
        SCAN_RECURSIVE(arg.wb);
        SCAN_RECURSIVE(arg.wb_lock);
        SCAN_RECURSIVE(arg.work_list);
        SCAN_RECURSIVE_PTR(arg.dev);
        SCAN_RECURSIVE(arg.laptop_mode_wb_timer);
        SCAN_RECURSIVE_PTR(arg.debug_dir);
        SCAN_RECURSIVE_PTR(arg.debug_stats);
    }
})
#endif


//#define SCANNER_FOR_struct_blk_queue_tag
#ifndef SCANNER_FOR_struct_blk_queue_tag
#define SCANNER_FOR_struct_blk_queue_tag
TYPE_SCAN_WRAPPER(struct blk_queue_tag, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct blk_queue_tag);
    }
    SCAN {
        S(kern_printk( "struct blk_queue_tag\n");)
        S(SCAN_OBJECT(arg);)
//  Pointer(Pointer(Use(Struct(struct request)))) arg.tag_index
        SCAN_FUNCTION(arg.tag_map);
        SCAN_FUNCTION(arg.busy);
        SCAN_FUNCTION(arg.max_depth);
        SCAN_FUNCTION(arg.real_max_depth);
        SCAN_RECURSIVE(arg.refcnt);
    }
})
#endif


//#define SCANNER_FOR_struct_bsg_class_device
#ifndef SCANNER_FOR_struct_bsg_class_device
#define SCANNER_FOR_struct_bsg_class_device
TYPE_SCAN_WRAPPER(struct bsg_class_device, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct bsg_class_device);
    }
    SCAN {
        S(kern_printk( "struct bsg_class_device\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.class_dev);
        SCAN_RECURSIVE_PTR(arg.parent);
        SCAN_FUNCTION(arg.minor);
        SCAN_RECURSIVE_PTR(arg.queue);
        SCAN_RECURSIVE(arg.ref);
        SCAN_FUNCTION(arg.release);
    }
})
#endif


//#define SCANNER_FOR_struct_request_queue
#ifndef SCANNER_FOR_struct_request_queue
#define SCANNER_FOR_struct_request_queue
TYPE_SCAN_WRAPPER(struct request_queue, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct request_queue);
    }
    SCAN {
        S(kern_printk( "struct request_queue\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.queue_head);
        SCAN_RECURSIVE_PTR(arg.last_merge);
        SCAN_RECURSIVE_PTR(arg.elevator);
//  Array(BuiltIn(int)) arg.nr_rqs
        SCAN_FUNCTION(arg.nr_rqs_elvpriv);
        SCAN_RECURSIVE(arg.root_rl);
        SCAN_FUNCTION(arg.request_fn);
        SCAN_FUNCTION(arg.make_request_fn);
        SCAN_FUNCTION(arg.prep_rq_fn);
        SCAN_FUNCTION(arg.unprep_rq_fn);
        SCAN_FUNCTION(arg.merge_bvec_fn);
        SCAN_FUNCTION(arg.softirq_done_fn);
        SCAN_FUNCTION(arg.rq_timed_out_fn);
        SCAN_FUNCTION(arg.dma_drain_needed);
        SCAN_FUNCTION(arg.lld_busy_fn);
        SCAN_FUNCTION(arg.end_sector);
        SCAN_RECURSIVE_PTR(arg.boundary_rq);
        SCAN_RECURSIVE(arg.delay_work);
        SCAN_RECURSIVE(arg.backing_dev_info);
        SCAN_FUNCTION(arg.queuedata);
        SCAN_FUNCTION(arg.queue_flags);
        SCAN_FUNCTION(arg.id);
        SCAN_FUNCTION(arg.bounce_gfp);
        SCAN_RECURSIVE(arg.__queue_lock);
        SCAN_RECURSIVE_PTR(arg.queue_lock);
        SCAN_RECURSIVE(arg.kobj);
        SCAN_FUNCTION(arg.nr_requests);
        SCAN_FUNCTION(arg.nr_congestion_on);
        SCAN_FUNCTION(arg.nr_congestion_off);
        SCAN_FUNCTION(arg.nr_batching);
        SCAN_FUNCTION(arg.dma_drain_size);
        SCAN_FUNCTION(arg.dma_drain_buffer);
        SCAN_FUNCTION(arg.dma_pad_mask);
        SCAN_FUNCTION(arg.dma_alignment);
        SCAN_RECURSIVE_PTR(arg.queue_tags);
        SCAN_RECURSIVE(arg.tag_busy_list);
        SCAN_FUNCTION(arg.nr_sorted);
//  Array(Attributed(unsigned , BuiltIn(int))) arg.in_flight
        SCAN_FUNCTION(arg.request_fn_active);
        SCAN_FUNCTION(arg.rq_timeout);
        SCAN_RECURSIVE(arg.timeout);
        SCAN_RECURSIVE(arg.timeout_list);
        SCAN_RECURSIVE(arg.icq_list);
//  Array(Attributed(unsigned , BuiltIn(long))) arg.blkcg_pols
        SCAN_RECURSIVE_PTR(arg.root_blkg);
        SCAN_RECURSIVE(arg.blkg_list);
        SCAN_RECURSIVE(arg.limits);
        SCAN_FUNCTION(arg.sg_timeout);
        SCAN_FUNCTION(arg.sg_reserved_size);
        SCAN_FUNCTION(arg.node);
        SCAN_RECURSIVE_PTR(arg.blk_trace);
        SCAN_FUNCTION(arg.flush_flags);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.flush_not_queueable
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.flush_queue_delayed
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.flush_pending_idx
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.flush_running_idx
        SCAN_FUNCTION(arg.flush_pending_since);
//  Array(Use(Struct(struct list_head))) arg.flush_queue
        SCAN_RECURSIVE(arg.flush_data_in_flight);
        SCAN_RECURSIVE(arg.flush_rq);
        SCAN_RECURSIVE(arg.sysfs_lock);
        SCAN_FUNCTION(arg.bypass_depth);
        SCAN_FUNCTION(arg.bsg_job_fn);
        SCAN_FUNCTION(arg.bsg_job_size);
        SCAN_RECURSIVE(arg.bsg_dev);
        SCAN_RECURSIVE(arg.all_q_node);
        SCAN_RECURSIVE_PTR(arg.td);
    }
})
#endif


//#define SCANNER_FOR_struct_blk_integrity
#ifndef SCANNER_FOR_struct_blk_integrity
#define SCANNER_FOR_struct_blk_integrity
TYPE_SCAN_WRAPPER(struct blk_integrity, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct blk_integrity);
    }
    SCAN {
        S(kern_printk( "struct blk_integrity\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.generate_fn);
        SCAN_FUNCTION(arg.verify_fn);
        SCAN_FUNCTION(arg.set_tag_fn);
        SCAN_FUNCTION(arg.get_tag_fn);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.tuple_size);
        SCAN_FUNCTION(arg.sector_size);
        SCAN_FUNCTION(arg.tag_size);
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE(arg.kobj);
    }
})
#endif


//#define SCANNER_FOR_struct_gendisk
#ifndef SCANNER_FOR_struct_gendisk
#define SCANNER_FOR_struct_gendisk
TYPE_SCAN_WRAPPER(struct gendisk, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct gendisk);
    }
    SCAN {
        S(kern_printk( "struct gendisk\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.major);
        SCAN_FUNCTION(arg.first_minor);
        SCAN_FUNCTION(arg.minors);
//  Array(BuiltIn(char)) arg.disk_name
        SCAN_FUNCTION(arg.devnode);
        SCAN_FUNCTION(arg.events);
        SCAN_FUNCTION(arg.async_events);
        SCAN_RECURSIVE_PTR(arg.part_tbl);
        SCAN_RECURSIVE(arg.part0);
        SCAN_RECURSIVE_PTR(arg.fops);
        SCAN_RECURSIVE_PTR(arg.queue);
        SCAN_FUNCTION(arg.private_data);
        SCAN_FUNCTION(arg.flags);
        SCAN_RECURSIVE_PTR(arg.driverfs_dev);
        SCAN_RECURSIVE_PTR(arg.slave_dir);
        SCAN_RECURSIVE_PTR(arg.random);
        SCAN_RECURSIVE(arg.sync_io);
        SCAN_RECURSIVE_PTR(arg.ev);
        SCAN_RECURSIVE_PTR(arg.integrity);
        SCAN_FUNCTION(arg.node_id);
    }
})
#endif


//#define SCANNER_FOR_struct_block_device
#ifndef SCANNER_FOR_struct_block_device
#define SCANNER_FOR_struct_block_device
TYPE_SCAN_WRAPPER(struct block_device, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct block_device);
    }
    SCAN {
        S(kern_printk( "struct block_device\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.bd_dev);
        SCAN_FUNCTION(arg.bd_openers);
        SCAN_RECURSIVE_PTR(arg.bd_inode);
        SCAN_RECURSIVE_PTR(arg.bd_super);
        SCAN_RECURSIVE(arg.bd_mutex);
        SCAN_RECURSIVE(arg.bd_inodes);
        SCAN_FUNCTION(arg.bd_claiming);
        SCAN_FUNCTION(arg.bd_holder);
        SCAN_FUNCTION(arg.bd_holders);
        SCAN_FUNCTION(arg.bd_write_holder);
        SCAN_RECURSIVE(arg.bd_holder_disks);
        SCAN_RECURSIVE_PTR(arg.bd_contains);
        SCAN_FUNCTION(arg.bd_block_size);
        SCAN_RECURSIVE_PTR(arg.bd_part);
        SCAN_FUNCTION(arg.bd_part_count);
        SCAN_FUNCTION(arg.bd_invalidated);
        SCAN_RECURSIVE_PTR(arg.bd_disk);
        SCAN_RECURSIVE_PTR(arg.bd_queue);
        SCAN_RECURSIVE(arg.bd_list);
        SCAN_FUNCTION(arg.bd_private);
        SCAN_FUNCTION(arg.bd_fsfreeze_count);
        SCAN_RECURSIVE(arg.bd_fsfreeze_mutex);
    }
})
#endif


//#define SCANNER_FOR_struct_swap_info_struct
#ifndef SCANNER_FOR_struct_swap_info_struct
#define SCANNER_FOR_struct_swap_info_struct
TYPE_SCAN_WRAPPER(struct swap_info_struct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct swap_info_struct);
    }
    SCAN {
        S(kern_printk( "struct swap_info_struct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.prio);
        SCAN_FUNCTION(arg.type);
        SCAN_FUNCTION(arg.next);
        SCAN_FUNCTION(arg.max);
        SCAN_FUNCTION(arg.swap_map);
        SCAN_FUNCTION(arg.lowest_bit);
        SCAN_FUNCTION(arg.highest_bit);
        SCAN_FUNCTION(arg.pages);
        SCAN_FUNCTION(arg.inuse_pages);
        SCAN_FUNCTION(arg.cluster_next);
        SCAN_FUNCTION(arg.cluster_nr);
        SCAN_FUNCTION(arg.lowest_alloc);
        SCAN_FUNCTION(arg.highest_alloc);
        SCAN_RECURSIVE_PTR(arg.curr_swap_extent);
        SCAN_RECURSIVE(arg.first_swap_extent);
        SCAN_RECURSIVE_PTR(arg.bdev);
        SCAN_RECURSIVE_PTR(arg.swap_file);
        SCAN_FUNCTION(arg.old_block_size);
    }
})
#endif


//#define SCANNER_FOR_struct_address_space_operations
#ifndef SCANNER_FOR_struct_address_space_operations
#define SCANNER_FOR_struct_address_space_operations
TYPE_SCAN_WRAPPER(struct address_space_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct address_space_operations);
    }
    SCAN {
        S(kern_printk( "struct address_space_operations\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.writepage);
        SCAN_FUNCTION(arg.readpage);
        SCAN_FUNCTION(arg.writepages);
        SCAN_FUNCTION(arg.set_page_dirty);
        SCAN_FUNCTION(arg.readpages);
        SCAN_FUNCTION(arg.write_begin);
        SCAN_FUNCTION(arg.write_end);
        SCAN_FUNCTION(arg.bmap);
        SCAN_FUNCTION(arg.invalidatepage);
        SCAN_FUNCTION(arg.releasepage);
        SCAN_FUNCTION(arg.freepage);
        SCAN_FUNCTION(arg.direct_IO);
        SCAN_FUNCTION(arg.get_xip_mem);
        SCAN_FUNCTION(arg.migratepage);
        SCAN_FUNCTION(arg.launder_page);
        SCAN_FUNCTION(arg.is_partially_uptodate);
        SCAN_FUNCTION(arg.error_remove_page);
        SCAN_FUNCTION(arg.swap_activate);
        SCAN_FUNCTION(arg.swap_deactivate);
    }
})
#endif


//#define SCANNER_FOR_struct_address_space
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


//#define SCANNER_FOR_struct_page
#ifndef SCANNER_FOR_struct_page
#define SCANNER_FOR_struct_page
TYPE_SCAN_WRAPPER(struct page, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct page);
    }
    SCAN {
        S(kern_printk( "struct page\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.flags);
        SCAN_RECURSIVE_PTR(arg.mapping);
      //  SCAN_RECURSIVE(None);
//  Union(union anon_union_119) None
//  Union(union anon_union_120) None
    }
})
#endif


//#define SCANNER_FOR_struct_vm_fault
#ifndef SCANNER_FOR_struct_vm_fault
#define SCANNER_FOR_struct_vm_fault
TYPE_SCAN_WRAPPER(struct vm_fault, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct vm_fault);
    }
    SCAN {
        S(kern_printk( "struct vm_fault\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.pgoff);
        SCAN_FUNCTION(arg.virtual_address);
        SCAN_RECURSIVE_PTR(arg.page);
    }
})
#endif


//#define SCANNER_FOR_struct_vm_operations_struct
#ifndef SCANNER_FOR_struct_vm_operations_struct
#define SCANNER_FOR_struct_vm_operations_struct
TYPE_SCAN_WRAPPER(struct vm_operations_struct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct vm_operations_struct);
    }
    SCAN {
        S(kern_printk( "struct vm_operations_struct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.open);
        SCAN_FUNCTION(arg.close);
        SCAN_FUNCTION(arg.fault);
        SCAN_FUNCTION(arg.page_mkwrite);
        SCAN_FUNCTION(arg.access);
        SCAN_FUNCTION(arg.set_policy);
        SCAN_FUNCTION(arg.get_policy);
        SCAN_FUNCTION(arg.migrate);
        SCAN_FUNCTION(arg.remap_pages);
    }
})
#endif


//#define SCANNER_FOR_struct_vm_area_struct
#ifndef SCANNER_FOR_struct_vm_area_struct
#define SCANNER_FOR_struct_vm_area_struct
TYPE_SCAN_WRAPPER(struct vm_area_struct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct vm_area_struct);
    }
    SCAN {
        S(kern_printk( "struct vm_area_struct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.vm_start);
        SCAN_FUNCTION(arg.vm_end);
        SCAN_RECURSIVE_PTR(arg.vm_next);
        SCAN_RECURSIVE_PTR(arg.vm_prev);
        SCAN_RECURSIVE(arg.vm_rb);
        SCAN_FUNCTION(arg.rb_subtree_gap);
        SCAN_RECURSIVE_PTR(arg.vm_mm);
        SCAN_RECURSIVE(arg.vm_page_prot);
        SCAN_FUNCTION(arg.vm_flags);
//  Union(union anon_union_58) arg.shared
        SCAN_RECURSIVE(arg.anon_vma_chain);
        SCAN_RECURSIVE_PTR(arg.anon_vma);
        SCAN_RECURSIVE_PTR(arg.vm_ops);
        SCAN_FUNCTION(arg.vm_pgoff);
        SCAN_RECURSIVE_PTR(arg.vm_file);
        SCAN_FUNCTION(arg.vm_private_data);
        SCAN_RECURSIVE_PTR(arg.vm_policy);
    }
})
#endif


//#define SCANNER_FOR_mm_context_t
#ifndef SCANNER_FOR_mm_context_t
#define SCANNER_FOR_mm_context_t
TYPE_SCAN_WRAPPER(mm_context_t, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(mm_context_t);
    }
    SCAN {
        S(kern_printk( "mm_context_t\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.ldt);
        SCAN_FUNCTION(arg.size);
        SCAN_FUNCTION(arg.ia32_compat);
        SCAN_RECURSIVE(arg.lock);
        SCAN_FUNCTION(arg.vdso);
    }
})
#endif


//#define SCANNER_FOR_struct_core_thread
#ifndef SCANNER_FOR_struct_core_thread
#define SCANNER_FOR_struct_core_thread
TYPE_SCAN_WRAPPER(struct core_thread, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct core_thread);
    }
    SCAN {
        S(kern_printk( "struct core_thread\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.task);
        SCAN_RECURSIVE_PTR(arg.next);
    }
})
#endif


//#define SCANNER_FOR_struct_core_state
#ifndef SCANNER_FOR_struct_core_state
#define SCANNER_FOR_struct_core_state
TYPE_SCAN_WRAPPER(struct core_state, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct core_state);
    }
    SCAN {
        S(kern_printk( "struct core_state\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.nr_threads);
        SCAN_RECURSIVE(arg.dumper);
        SCAN_RECURSIVE(arg.startup);
    }
})
#endif


//#define SCANNER_FOR_struct_mm_struct
#ifndef SCANNER_FOR_struct_mm_struct
#define SCANNER_FOR_struct_mm_struct
TYPE_SCAN_WRAPPER(struct mm_struct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct mm_struct);
    }
    SCAN {
        S(kern_printk( "struct mm_struct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.mmap);
        SCAN_RECURSIVE(arg.mm_rb);
        SCAN_RECURSIVE_PTR(arg.mmap_cache);
        SCAN_FUNCTION(arg.get_unmapped_area);
        SCAN_FUNCTION(arg.unmap_area);
        SCAN_FUNCTION(arg.mmap_base);
        SCAN_FUNCTION(arg.task_size);
        SCAN_FUNCTION(arg.cached_hole_size);
        SCAN_FUNCTION(arg.free_area_cache);
        SCAN_FUNCTION(arg.highest_vm_end);
        SCAN_RECURSIVE_PTR(arg.pgd);
        SCAN_RECURSIVE(arg.mm_users);
        SCAN_RECURSIVE(arg.mm_count);
        SCAN_FUNCTION(arg.map_count);
        SCAN_RECURSIVE(arg.page_table_lock);
        SCAN_RECURSIVE(arg.mmap_sem);
        SCAN_RECURSIVE(arg.mmlist);
        SCAN_FUNCTION(arg.hiwater_rss);
        SCAN_FUNCTION(arg.hiwater_vm);
        SCAN_FUNCTION(arg.total_vm);
        SCAN_FUNCTION(arg.locked_vm);
        SCAN_FUNCTION(arg.pinned_vm);
        SCAN_FUNCTION(arg.shared_vm);
        SCAN_FUNCTION(arg.exec_vm);
        SCAN_FUNCTION(arg.stack_vm);
        SCAN_FUNCTION(arg.def_flags);
        SCAN_FUNCTION(arg.nr_ptes);
        SCAN_FUNCTION(arg.start_code);
        SCAN_FUNCTION(arg.end_code);
        SCAN_FUNCTION(arg.start_data);
        SCAN_FUNCTION(arg.end_data);
        SCAN_FUNCTION(arg.start_brk);
        SCAN_FUNCTION(arg.brk);
        SCAN_FUNCTION(arg.start_stack);
        SCAN_FUNCTION(arg.arg_start);
        SCAN_FUNCTION(arg.arg_end);
        SCAN_FUNCTION(arg.env_start);
        SCAN_FUNCTION(arg.env_end);
//  Array(Attributed(unsigned , BuiltIn(long))) arg.saved_auxv
        SCAN_RECURSIVE(arg.rss_stat);
        SCAN_RECURSIVE_PTR(arg.binfmt);
//  Array(Use(Struct(struct cpumask))) arg.cpu_vm_mask_var
        SCAN_RECURSIVE(arg.context);
        SCAN_FUNCTION(arg.flags);
        SCAN_RECURSIVE_PTR(arg.core_state);
        SCAN_RECURSIVE(arg.ioctx_lock);
        SCAN_RECURSIVE(arg.ioctx_list);
        SCAN_RECURSIVE_PTR(arg.exe_file);
        SCAN_RECURSIVE_PTR(arg.mmu_notifier_mm);
        SCAN_RECURSIVE(arg.pmd_huge_pte);
        SCAN_RECURSIVE(arg.uprobes_state);
    }
})
#endif


//#define SCANNER_FOR_struct_pid
#ifndef SCANNER_FOR_struct_pid
#define SCANNER_FOR_struct_pid
TYPE_SCAN_WRAPPER(struct pid, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pid);
    }
    SCAN {
        S(kern_printk( "struct pid\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.count);
        SCAN_FUNCTION(arg.level);
//  Array(Use(Struct(struct hlist_head))) arg.tasks
        SCAN_RECURSIVE(arg.rcu);
//  Array(Use(Struct(struct upid))) arg.numbers
    }
})
#endif


//#define SCANNER_FOR_struct_pid_link
#ifndef SCANNER_FOR_struct_pid_link
#define SCANNER_FOR_struct_pid_link
TYPE_SCAN_WRAPPER(struct pid_link, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pid_link);
    }
    SCAN {
        S(kern_printk( "struct pid_link\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.node);
        SCAN_RECURSIVE_PTR(arg.pid);
    }
})
#endif


//#define SCANNER_FOR_struct_cred
#ifndef SCANNER_FOR_struct_cred
#define SCANNER_FOR_struct_cred
TYPE_SCAN_WRAPPER(struct cred, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cred);
    }
    SCAN {
        S(kern_printk( "struct cred\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.usage);
        SCAN_FUNCTION(arg.uid);
        SCAN_FUNCTION(arg.gid);
        SCAN_FUNCTION(arg.suid);
        SCAN_FUNCTION(arg.sgid);
        SCAN_FUNCTION(arg.euid);
        SCAN_FUNCTION(arg.egid);
        SCAN_FUNCTION(arg.fsuid);
        SCAN_FUNCTION(arg.fsgid);
        SCAN_FUNCTION(arg.securebits);
        SCAN_RECURSIVE(arg.cap_inheritable);
        SCAN_RECURSIVE(arg.cap_permitted);
        SCAN_RECURSIVE(arg.cap_effective);
        SCAN_RECURSIVE(arg.cap_bset);
        SCAN_FUNCTION(arg.jit_keyring);
        SCAN_RECURSIVE_PTR(arg.session_keyring);
        SCAN_RECURSIVE_PTR(arg.process_keyring);
        SCAN_RECURSIVE_PTR(arg.thread_keyring);
        SCAN_RECURSIVE_PTR(arg.request_key_auth);
        SCAN_FUNCTION(arg.security);
        SCAN_RECURSIVE_PTR(arg.user);
        SCAN_RECURSIVE_PTR(arg.user_ns);
        SCAN_RECURSIVE_PTR(arg.group_info);
        SCAN_RECURSIVE(arg.rcu);
    }
})
#endif


//#define SCANNER_FOR_struct_poll_table_struct
#ifndef SCANNER_FOR_struct_poll_table_struct
#define SCANNER_FOR_struct_poll_table_struct
TYPE_SCAN_WRAPPER(struct poll_table_struct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct poll_table_struct);
    }
    SCAN {
        S(kern_printk( "struct poll_table_struct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg._qproc);
        SCAN_FUNCTION(arg._key);
    }
})
#endif


//#define SCANNER_FOR_struct_fasync_struct
#ifndef SCANNER_FOR_struct_fasync_struct
#define SCANNER_FOR_struct_fasync_struct
TYPE_SCAN_WRAPPER(struct fasync_struct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct fasync_struct);
    }
    SCAN {
        S(kern_printk( "struct fasync_struct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.fa_lock);
        SCAN_FUNCTION(arg.magic);
        SCAN_FUNCTION(arg.fa_fd);
        SCAN_RECURSIVE_PTR(arg.fa_next);
        SCAN_RECURSIVE_PTR(arg.fa_file);
        SCAN_RECURSIVE(arg.fa_rcu);
    }
})
#endif


//#define SCANNER_FOR_struct_file_lock_operations
#ifndef SCANNER_FOR_struct_file_lock_operations
#define SCANNER_FOR_struct_file_lock_operations
TYPE_SCAN_WRAPPER(struct file_lock_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct file_lock_operations);
    }
    SCAN {
        S(kern_printk( "struct file_lock_operations\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.fl_copy_lock);
        SCAN_FUNCTION(arg.fl_release_private);
    }
})
#endif


//#define SCANNER_FOR_struct_lock_manager_operations
#ifndef SCANNER_FOR_struct_lock_manager_operations
#define SCANNER_FOR_struct_lock_manager_operations
TYPE_SCAN_WRAPPER(struct lock_manager_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct lock_manager_operations);
    }
    SCAN {
        S(kern_printk( "struct lock_manager_operations\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.lm_compare_owner);
        SCAN_FUNCTION(arg.lm_notify);
        SCAN_FUNCTION(arg.lm_grant);
        SCAN_FUNCTION(arg.lm_break);
        SCAN_FUNCTION(arg.lm_change);
    }
})
#endif


//#define SCANNER_FOR_struct_file_lock
#ifndef SCANNER_FOR_struct_file_lock
#define SCANNER_FOR_struct_file_lock
TYPE_SCAN_WRAPPER(struct file_lock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct file_lock);
    }
    SCAN {
        S(kern_printk( "struct file_lock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.fl_next);
        SCAN_RECURSIVE(arg.fl_link);
        SCAN_RECURSIVE(arg.fl_block);
        SCAN_RECURSIVE(arg.fl_owner);
        SCAN_FUNCTION(arg.fl_flags);
        SCAN_FUNCTION(arg.fl_type);
        SCAN_FUNCTION(arg.fl_pid);
        SCAN_RECURSIVE_PTR(arg.fl_nspid);
        SCAN_RECURSIVE(arg.fl_wait);
        SCAN_RECURSIVE_PTR(arg.fl_file);
        SCAN_FUNCTION(arg.fl_start);
        SCAN_FUNCTION(arg.fl_end);
        SCAN_RECURSIVE_PTR(arg.fl_fasync);
        SCAN_FUNCTION(arg.fl_break_time);
        SCAN_FUNCTION(arg.fl_downgrade_time);
        SCAN_RECURSIVE_PTR(arg.fl_ops);
        SCAN_RECURSIVE_PTR(arg.fl_lmops);
//  Union(union anon_union_124) arg.fl_u
    }
})
#endif


//#define SCANNER_FOR_struct_seq_operations
#ifndef SCANNER_FOR_struct_seq_operations
#define SCANNER_FOR_struct_seq_operations
TYPE_SCAN_WRAPPER(struct seq_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct seq_operations);
    }
    SCAN {
        S(kern_printk( "struct seq_operations\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.start);
        SCAN_FUNCTION(arg.stop);
        SCAN_FUNCTION(arg.next);
        SCAN_FUNCTION(arg.show);
    }
})
#endif


//#define SCANNER_FOR_struct_seq_file
#ifndef SCANNER_FOR_struct_seq_file
#define SCANNER_FOR_struct_seq_file
TYPE_SCAN_WRAPPER(struct seq_file, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct seq_file);
    }
    SCAN {
        S(kern_printk( "struct seq_file\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.buf);
        SCAN_FUNCTION(arg.size);
        SCAN_FUNCTION(arg.from);
        SCAN_FUNCTION(arg.count);
        SCAN_FUNCTION(arg.index);
        SCAN_FUNCTION(arg.read_pos);
        SCAN_FUNCTION(arg.version);
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE_PTR(arg.op);
        SCAN_FUNCTION(arg.poll_event);
        SCAN_FUNCTION(arg.private_);
    }
})
#endif


//#define SCANNER_FOR_struct_file_operations
#ifndef SCANNER_FOR_struct_file_operations
#define SCANNER_FOR_struct_file_operations
TYPE_SCAN_WRAPPER(struct file_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct file_operations);
    }
    SCAN {
        S(kern_printk( "struct file_operations\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.owner);
        SCAN_FUNCTION(arg.llseek);
        SCAN_FUNCTION(arg.read);
        SCAN_FUNCTION(arg.write);
        SCAN_FUNCTION(arg.aio_read);
        SCAN_FUNCTION(arg.aio_write);
        SCAN_FUNCTION(arg.readdir);
        SCAN_FUNCTION(arg.poll);
        SCAN_FUNCTION(arg.unlocked_ioctl);
        SCAN_FUNCTION(arg.compat_ioctl);
        SCAN_FUNCTION(arg.mmap);
        SCAN_FUNCTION(arg.open);
        SCAN_FUNCTION(arg.flush);
        SCAN_FUNCTION(arg.release);
        SCAN_FUNCTION(arg.fsync);
        SCAN_FUNCTION(arg.aio_fsync);
        SCAN_FUNCTION(arg.fasync);
        SCAN_FUNCTION(arg.lock);
        SCAN_FUNCTION(arg.sendpage);
        SCAN_FUNCTION(arg.get_unmapped_area);
        SCAN_FUNCTION(arg.check_flags);
        SCAN_FUNCTION(arg.flock);
        SCAN_FUNCTION(arg.splice_write);
        SCAN_FUNCTION(arg.splice_read);
        SCAN_FUNCTION(arg.setlease);
        SCAN_FUNCTION(arg.fallocate);
        SCAN_FUNCTION(arg.show_fdinfo);
    }
})
#endif


//#define SCANNER_FOR_struct_proc_dir_entry
#ifndef SCANNER_FOR_struct_proc_dir_entry
#define SCANNER_FOR_struct_proc_dir_entry
TYPE_SCAN_WRAPPER(struct proc_dir_entry, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct proc_dir_entry);
    }
    SCAN {
        S(kern_printk( "struct proc_dir_entry\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.low_ino);
        SCAN_FUNCTION(arg.mode);
        SCAN_FUNCTION(arg.nlink);
        SCAN_FUNCTION(arg.uid);
        SCAN_FUNCTION(arg.gid);
        SCAN_FUNCTION(arg.size);
        SCAN_RECURSIVE_PTR(arg.proc_iops);
        SCAN_RECURSIVE_PTR(arg.proc_fops);
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_RECURSIVE_PTR(arg.parent);
        SCAN_RECURSIVE_PTR(arg.subdir);
        SCAN_FUNCTION(arg.data);
        SCAN_FUNCTION(arg.read_proc);
        SCAN_FUNCTION(arg.write_proc);
        SCAN_RECURSIVE(arg.count);
        SCAN_FUNCTION(arg.pde_users);
        SCAN_RECURSIVE_PTR(arg.pde_unload_completion);
        SCAN_RECURSIVE(arg.pde_openers);
        SCAN_RECURSIVE(arg.pde_unload_lock);
        SCAN_FUNCTION(arg.namelen);
//  Array(BuiltIn(char)) arg.name
    }
})
#endif


//#define SCANNER_FOR_struct_ctl_table
#ifndef SCANNER_FOR_struct_ctl_table
#define SCANNER_FOR_struct_ctl_table
TYPE_SCAN_WRAPPER(struct ctl_table, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ctl_table);
    }
    SCAN {
        S(kern_printk( "struct ctl_table\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.procname);
        SCAN_FUNCTION(arg.data);
        SCAN_FUNCTION(arg.maxlen);
        SCAN_FUNCTION(arg.mode);
        SCAN_RECURSIVE_PTR(arg.child);
        SCAN_FUNCTION(arg.proc_handler);
        SCAN_RECURSIVE_PTR(arg.poll);
        SCAN_FUNCTION(arg.extra1);
        SCAN_FUNCTION(arg.extra2);
    }
})
#endif


//#define SCANNER_FOR_struct_ctl_table_root
#ifndef SCANNER_FOR_struct_ctl_table_root
#define SCANNER_FOR_struct_ctl_table_root
TYPE_SCAN_WRAPPER(struct ctl_table_root, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ctl_table_root);
    }
    SCAN {
        S(kern_printk( "struct ctl_table_root\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.default_set);
        SCAN_FUNCTION(arg.lookup);
        SCAN_FUNCTION(arg.permissions);
    }
})
#endif


//#define SCANNER_FOR_struct_ctl_node
#ifndef SCANNER_FOR_struct_ctl_node
#define SCANNER_FOR_struct_ctl_node
TYPE_SCAN_WRAPPER(struct ctl_node, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ctl_node);
    }
    SCAN {
        S(kern_printk( "struct ctl_node\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.node);
        SCAN_RECURSIVE_PTR(arg.header);
    }
})
#endif


//#define SCANNER_FOR_struct_ctl_table_header
#ifndef SCANNER_FOR_struct_ctl_table_header
#define SCANNER_FOR_struct_ctl_table_header
TYPE_SCAN_WRAPPER(struct ctl_table_header, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ctl_table_header);
    }
    SCAN {
        S(kern_printk( "struct ctl_table_header\n");)
        S(SCAN_OBJECT(arg);)
//  Union(union anon_union_55) None
        SCAN_RECURSIVE_PTR(arg.unregistering);
        SCAN_RECURSIVE_PTR(arg.ctl_table_arg);
        SCAN_RECURSIVE_PTR(arg.root);
        SCAN_RECURSIVE_PTR(arg.set);
        SCAN_RECURSIVE_PTR(arg.parent);
        SCAN_RECURSIVE_PTR(arg.node);
    }
})
#endif


//#define SCANNER_FOR_struct_ctl_dir
#ifndef SCANNER_FOR_struct_ctl_dir
#define SCANNER_FOR_struct_ctl_dir
TYPE_SCAN_WRAPPER(struct ctl_dir, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ctl_dir);
    }
    SCAN {
        S(kern_printk( "struct ctl_dir\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.header);
        SCAN_RECURSIVE(arg.root);
    }
})
#endif


//#define SCANNER_FOR_struct_ctl_table_set
#ifndef SCANNER_FOR_struct_ctl_table_set
#define SCANNER_FOR_struct_ctl_table_set
TYPE_SCAN_WRAPPER(struct ctl_table_set, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ctl_table_set);
    }
    SCAN {
        S(kern_printk( "struct ctl_table_set\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.is_seen);
        SCAN_RECURSIVE(arg.dir);
    }
})
#endif


//#define SCANNER_FOR_struct_netns_core
#ifndef SCANNER_FOR_struct_netns_core
#define SCANNER_FOR_struct_netns_core
TYPE_SCAN_WRAPPER(struct netns_core, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netns_core);
    }
    SCAN {
        S(kern_printk( "struct netns_core\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.sysctl_hdr);
        SCAN_FUNCTION(arg.sysctl_somaxconn);
        SCAN_RECURSIVE_PTR(arg.inuse);
    }
})
#endif


//#define SCANNER_FOR_struct_netns_mib
#ifndef SCANNER_FOR_struct_netns_mib
#define SCANNER_FOR_struct_netns_mib
TYPE_SCAN_WRAPPER(struct netns_mib, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netns_mib);
    }
    SCAN {
        S(kern_printk( "struct netns_mib\n");)
        S(SCAN_OBJECT(arg);)
//  Array(Pointer(Expr)) arg.tcp_statistics
//  Array(Pointer(Expr)) arg.ip_statistics
//  Array(Pointer(Expr)) arg.net_statistics
//  Array(Pointer(Expr)) arg.udp_statistics
//  Array(Pointer(Expr)) arg.udplite_statistics
//  Array(Pointer(Expr)) arg.icmp_statistics
//  Pointer(Expr) arg.icmpmsg_statistics
        SCAN_RECURSIVE_PTR(arg.proc_net_devsnmp6);
//  Array(Pointer(Expr)) arg.udp_stats_in6
//  Array(Pointer(Expr)) arg.udplite_stats_in6
//  Array(Pointer(Expr)) arg.ipv6_statistics
//  Array(Pointer(Expr)) arg.icmpv6_statistics
//  Pointer(Expr) arg.icmpv6msg_statistics
    }
})
#endif


//#define SCANNER_FOR_struct_netns_packet
#ifndef SCANNER_FOR_struct_netns_packet
#define SCANNER_FOR_struct_netns_packet
TYPE_SCAN_WRAPPER(struct netns_packet, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netns_packet);
    }
    SCAN {
        S(kern_printk( "struct netns_packet\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.sklist_lock);
        SCAN_RECURSIVE(arg.sklist);
    }
})
#endif


//#define SCANNER_FOR_struct_netns_unix
#ifndef SCANNER_FOR_struct_netns_unix
#define SCANNER_FOR_struct_netns_unix
TYPE_SCAN_WRAPPER(struct netns_unix, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netns_unix);
    }
    SCAN {
        S(kern_printk( "struct netns_unix\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.sysctl_max_dgram_qlen);
        SCAN_RECURSIVE_PTR(arg.ctl);
    }
})
#endif


//#define SCANNER_FOR_struct_netns_ipv4
#ifndef SCANNER_FOR_struct_netns_ipv4
#define SCANNER_FOR_struct_netns_ipv4
TYPE_SCAN_WRAPPER(struct netns_ipv4, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netns_ipv4);
    }
    SCAN {
        S(kern_printk( "struct netns_ipv4\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.forw_hdr);
        SCAN_RECURSIVE_PTR(arg.frags_hdr);
        SCAN_RECURSIVE_PTR(arg.ipv4_hdr);
        SCAN_RECURSIVE_PTR(arg.route_hdr);
        SCAN_RECURSIVE_PTR(arg.devconf_all);
        SCAN_RECURSIVE_PTR(arg.devconf_dflt);
        SCAN_RECURSIVE_PTR(arg.rules_ops);
        SCAN_FUNCTION(arg.fib_has_custom_rules);
        SCAN_RECURSIVE_PTR(arg.fib_local);
        SCAN_RECURSIVE_PTR(arg.fib_main);
        SCAN_RECURSIVE_PTR(arg.fib_default);
        SCAN_FUNCTION(arg.fib_num_tclassid_users);
        SCAN_RECURSIVE_PTR(arg.fib_table_hash);
        SCAN_RECURSIVE_PTR(arg.fibnl);
//  Pointer(Pointer(Use(Struct(struct sock)))) arg.icmp_sk
        SCAN_RECURSIVE_PTR(arg.peers);
        SCAN_RECURSIVE_PTR(arg.tcp_metrics_hash);
        SCAN_FUNCTION(arg.tcp_metrics_hash_log);
        SCAN_RECURSIVE(arg.frags);
        SCAN_RECURSIVE_PTR(arg.iptable_filter);
        SCAN_RECURSIVE_PTR(arg.iptable_mangle);
        SCAN_RECURSIVE_PTR(arg.iptable_raw);
        SCAN_RECURSIVE_PTR(arg.arptable_filter);
        SCAN_RECURSIVE_PTR(arg.iptable_security);
        SCAN_RECURSIVE_PTR(arg.nat_table);
        SCAN_FUNCTION(arg.sysctl_icmp_echo_ignore_all);
        SCAN_FUNCTION(arg.sysctl_icmp_echo_ignore_broadcasts);
        SCAN_FUNCTION(arg.sysctl_icmp_ignore_bogus_error_responses);
        SCAN_FUNCTION(arg.sysctl_icmp_ratelimit);
        SCAN_FUNCTION(arg.sysctl_icmp_ratemask);
        SCAN_FUNCTION(arg.sysctl_icmp_errors_use_inbound_ifaddr);
//  Array(Use(TypeDef(kgid_t, Use(TypeDef(gid_t, Use(TypeDef(__kernel_gid32_t, Use(TypeDef(__kernel_gid_t, Attributed(unsigned , BuiltIn(int))))))))))) arg.sysctl_ping_group_range
//  Array(BuiltIn(long)) arg.sysctl_tcp_mem
        SCAN_RECURSIVE(arg.dev_addr_genid);
        SCAN_RECURSIVE_PTR(arg.mrt);
    }
})
#endif


//#define SCANNER_FOR_struct_netns_sysctl_ipv6
#ifndef SCANNER_FOR_struct_netns_sysctl_ipv6
#define SCANNER_FOR_struct_netns_sysctl_ipv6
TYPE_SCAN_WRAPPER(struct netns_sysctl_ipv6, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netns_sysctl_ipv6);
    }
    SCAN {
        S(kern_printk( "struct netns_sysctl_ipv6\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.hdr);
        SCAN_RECURSIVE_PTR(arg.route_hdr);
        SCAN_RECURSIVE_PTR(arg.icmp_hdr);
        SCAN_RECURSIVE_PTR(arg.frags_hdr);
        SCAN_FUNCTION(arg.bindv6only);
        SCAN_FUNCTION(arg.flush_delay);
        SCAN_FUNCTION(arg.ip6_rt_max_size);
        SCAN_FUNCTION(arg.ip6_rt_gc_min_interval);
        SCAN_FUNCTION(arg.ip6_rt_gc_timeout);
        SCAN_FUNCTION(arg.ip6_rt_gc_interval);
        SCAN_FUNCTION(arg.ip6_rt_gc_elasticity);
        SCAN_FUNCTION(arg.ip6_rt_mtu_expires);
        SCAN_FUNCTION(arg.ip6_rt_min_advmss);
        SCAN_FUNCTION(arg.icmpv6_time);
    }
})
#endif


//#define SCANNER_FOR_struct_dst_entry
#ifndef SCANNER_FOR_struct_dst_entry
#define SCANNER_FOR_struct_dst_entry
TYPE_SCAN_WRAPPER(struct dst_entry, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dst_entry);
    }
    SCAN {
        S(kern_printk( "struct dst_entry\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.callback_head);
        SCAN_RECURSIVE_PTR(arg.child);
        SCAN_RECURSIVE_PTR(arg.dev);
        SCAN_RECURSIVE_PTR(arg.ops);
        SCAN_FUNCTION(arg._metrics);
        SCAN_FUNCTION(arg.expires);
        SCAN_RECURSIVE_PTR(arg.path);
        SCAN_RECURSIVE_PTR(arg.from);
        SCAN_RECURSIVE_PTR(arg.xfrm);
        SCAN_FUNCTION(arg.input);
        SCAN_FUNCTION(arg.output);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.pending_confirm);
        SCAN_FUNCTION(arg.error);
        SCAN_FUNCTION(arg.obsolete);
        SCAN_FUNCTION(arg.header_len);
        SCAN_FUNCTION(arg.trailer_len);
        SCAN_FUNCTION(arg.tclassid);
//  Array(BuiltIn(long)) arg.__pad_to_align_refcnt
        SCAN_RECURSIVE(arg.__refcnt);
        SCAN_FUNCTION(arg.__use);
        SCAN_FUNCTION(arg.lastuse);
//  Union(union anon_union_37) None
    }
})
#endif


//#define SCANNER_FOR_struct_pneigh_entry
#ifndef SCANNER_FOR_struct_pneigh_entry
#define SCANNER_FOR_struct_pneigh_entry
TYPE_SCAN_WRAPPER(struct pneigh_entry, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pneigh_entry);
    }
    SCAN {
        S(kern_printk( "struct pneigh_entry\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_RECURSIVE_PTR(arg.net);
        SCAN_RECURSIVE_PTR(arg.dev);
        SCAN_FUNCTION(arg.flags);
//  Array(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.key
    }
})
#endif


//#define SCANNER_FOR_struct_neigh_parms
#ifndef SCANNER_FOR_struct_neigh_parms
#define SCANNER_FOR_struct_neigh_parms
TYPE_SCAN_WRAPPER(struct neigh_parms, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct neigh_parms);
    }
    SCAN {
        S(kern_printk( "struct neigh_parms\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.net);
        SCAN_RECURSIVE_PTR(arg.dev);
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_FUNCTION(arg.neigh_setup);
        SCAN_FUNCTION(arg.neigh_cleanup);
        SCAN_RECURSIVE_PTR(arg.tbl);
        SCAN_FUNCTION(arg.sysctl_table);
        SCAN_FUNCTION(arg.dead);
        SCAN_RECURSIVE(arg.refcnt);
        SCAN_RECURSIVE(arg.callback_head);
        SCAN_FUNCTION(arg.base_reachable_time);
        SCAN_FUNCTION(arg.retrans_time);
        SCAN_FUNCTION(arg.gc_staletime);
        SCAN_FUNCTION(arg.reachable_time);
        SCAN_FUNCTION(arg.delay_probe_time);
        SCAN_FUNCTION(arg.queue_len_bytes);
        SCAN_FUNCTION(arg.ucast_probes);
        SCAN_FUNCTION(arg.app_probes);
        SCAN_FUNCTION(arg.mcast_probes);
        SCAN_FUNCTION(arg.anycast_delay);
        SCAN_FUNCTION(arg.proxy_delay);
        SCAN_FUNCTION(arg.proxy_qlen);
        SCAN_FUNCTION(arg.locktime);
    }
})
#endif


//#define SCANNER_FOR_struct_sk_buff_head
#ifndef SCANNER_FOR_struct_sk_buff_head
#define SCANNER_FOR_struct_sk_buff_head
TYPE_SCAN_WRAPPER(struct sk_buff_head, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct sk_buff_head);
    }
    SCAN {
        S(kern_printk( "struct sk_buff_head\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_RECURSIVE_PTR(arg.prev);
        SCAN_FUNCTION(arg.qlen);
        SCAN_RECURSIVE(arg.lock);
    }
})
#endif


//#define SCANNER_FOR_struct_neigh_hash_table
#ifndef SCANNER_FOR_struct_neigh_hash_table
#define SCANNER_FOR_struct_neigh_hash_table
TYPE_SCAN_WRAPPER(struct neigh_hash_table, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct neigh_hash_table);
    }
    SCAN {
        S(kern_printk( "struct neigh_hash_table\n");)
        S(SCAN_OBJECT(arg);)
//  Pointer(Pointer(Use(Struct(struct neighbour)))) arg.hash_buckets
        SCAN_FUNCTION(arg.hash_shift);
//  Array(Use(TypeDef(__u32, Attributed(unsigned , BuiltIn(int))))) arg.hash_rnd
        SCAN_RECURSIVE(arg.rcu);
    }
})
#endif


//#define SCANNER_FOR_struct_neigh_table
#ifndef SCANNER_FOR_struct_neigh_table
#define SCANNER_FOR_struct_neigh_table
TYPE_SCAN_WRAPPER(struct neigh_table, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct neigh_table);
    }
    SCAN {
        S(kern_printk( "struct neigh_table\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_FUNCTION(arg.family);
        SCAN_FUNCTION(arg.entry_size);
        SCAN_FUNCTION(arg.key_len);
        SCAN_FUNCTION(arg.hash);
        SCAN_FUNCTION(arg.constructor);
        SCAN_FUNCTION(arg.pconstructor);
        SCAN_FUNCTION(arg.pdestructor);
        SCAN_FUNCTION(arg.proxy_redo);
        SCAN_FUNCTION(arg.id);
        SCAN_RECURSIVE(arg.parms);
        SCAN_FUNCTION(arg.gc_interval);
        SCAN_FUNCTION(arg.gc_thresh1);
        SCAN_FUNCTION(arg.gc_thresh2);
        SCAN_FUNCTION(arg.gc_thresh3);
        SCAN_FUNCTION(arg.last_flush);
        SCAN_RECURSIVE(arg.gc_work);
        SCAN_RECURSIVE(arg.proxy_timer);
        SCAN_RECURSIVE(arg.proxy_queue);
        SCAN_RECURSIVE(arg.entries);
        SCAN_RECURSIVE(arg.lock);
        SCAN_FUNCTION(arg.last_rand);
        SCAN_RECURSIVE_PTR(arg.stats);
        SCAN_RECURSIVE_PTR(arg.nht);
//  Pointer(Pointer(Use(Struct(struct pneigh_entry)))) arg.phash_buckets
    }
})
#endif


//#define SCANNER_FOR_struct_neigh_ops
#ifndef SCANNER_FOR_struct_neigh_ops
#define SCANNER_FOR_struct_neigh_ops
TYPE_SCAN_WRAPPER(struct neigh_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct neigh_ops);
    }
    SCAN {
        S(kern_printk( "struct neigh_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.family);
        SCAN_FUNCTION(arg.solicit);
        SCAN_FUNCTION(arg.error_report);
        SCAN_FUNCTION(arg.output);
        SCAN_FUNCTION(arg.connected_output);
    }
})
#endif


//#define SCANNER_FOR_struct_neighbour
#ifndef SCANNER_FOR_struct_neighbour
#define SCANNER_FOR_struct_neighbour
TYPE_SCAN_WRAPPER(struct neighbour, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct neighbour);
    }
    SCAN {
        S(kern_printk( "struct neighbour\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_RECURSIVE_PTR(arg.tbl);
        SCAN_RECURSIVE_PTR(arg.parms);
        SCAN_FUNCTION(arg.confirmed);
        SCAN_FUNCTION(arg.updated);
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE(arg.refcnt);
        SCAN_RECURSIVE(arg.arp_queue);
        SCAN_FUNCTION(arg.arp_queue_len_bytes);
        SCAN_RECURSIVE(arg.timer);
        SCAN_FUNCTION(arg.used);
        SCAN_RECURSIVE(arg.probes);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.nud_state);
        SCAN_FUNCTION(arg.type);
        SCAN_FUNCTION(arg.dead);
        SCAN_RECURSIVE(arg.ha_lock);
//  Array(Attributed(unsigned , BuiltIn(char))) arg.ha
        SCAN_RECURSIVE(arg.hh);
        SCAN_FUNCTION(arg.output);
        SCAN_RECURSIVE_PTR(arg.ops);
        SCAN_RECURSIVE(arg.rcu);
        SCAN_RECURSIVE_PTR(arg.dev);
//  Array(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.primary_key
    }
})
#endif


//#define SCANNER_FOR_struct_dst_ops
#ifndef SCANNER_FOR_struct_dst_ops
#define SCANNER_FOR_struct_dst_ops
TYPE_SCAN_WRAPPER(struct dst_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dst_ops);
    }
    SCAN {
        S(kern_printk( "struct dst_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.family);
        SCAN_FUNCTION(arg.protocol);
        SCAN_FUNCTION(arg.gc_thresh);
        SCAN_FUNCTION(arg.gc);
        SCAN_FUNCTION(arg.check);
        SCAN_FUNCTION(arg.default_advmss);
        SCAN_FUNCTION(arg.mtu);
        SCAN_FUNCTION(arg.cow_metrics);
        SCAN_FUNCTION(arg.destroy);
        SCAN_FUNCTION(arg.ifdown);
        SCAN_FUNCTION(arg.negative_advice);
        SCAN_FUNCTION(arg.link_failure);
        SCAN_FUNCTION(arg.update_pmtu);
        SCAN_FUNCTION(arg.redirect);
        SCAN_FUNCTION(arg.local_out);
        SCAN_FUNCTION(arg.neigh_lookup);
        SCAN_RECURSIVE_PTR(arg.kmem_cachep);
        SCAN_RECURSIVE(arg.pcpuc_entries);
    }
})
#endif


//#define SCANNER_FOR_struct_netns_ipv6
#ifndef SCANNER_FOR_struct_netns_ipv6
#define SCANNER_FOR_struct_netns_ipv6
TYPE_SCAN_WRAPPER(struct netns_ipv6, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netns_ipv6);
    }
    SCAN {
        S(kern_printk( "struct netns_ipv6\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.sysctl);
        SCAN_RECURSIVE_PTR(arg.devconf_all);
        SCAN_RECURSIVE_PTR(arg.devconf_dflt);
        SCAN_RECURSIVE_PTR(arg.peers);
        SCAN_RECURSIVE(arg.frags);
        SCAN_RECURSIVE_PTR(arg.ip6table_filter);
        SCAN_RECURSIVE_PTR(arg.ip6table_mangle);
        SCAN_RECURSIVE_PTR(arg.ip6table_raw);
        SCAN_RECURSIVE_PTR(arg.ip6table_security);
        SCAN_RECURSIVE_PTR(arg.ip6table_nat);
        SCAN_RECURSIVE_PTR(arg.ip6_null_entry);
        SCAN_RECURSIVE_PTR(arg.rt6_stats);
        SCAN_RECURSIVE(arg.ip6_fib_timer);
        SCAN_RECURSIVE_PTR(arg.fib_table_hash);
        SCAN_RECURSIVE_PTR(arg.fib6_main_tbl);
        SCAN_RECURSIVE(arg.ip6_dst_ops);
        SCAN_FUNCTION(arg.ip6_rt_gc_expire);
        SCAN_FUNCTION(arg.ip6_rt_last_gc);
        SCAN_RECURSIVE_PTR(arg.ip6_prohibit_entry);
        SCAN_RECURSIVE_PTR(arg.ip6_blk_hole_entry);
        SCAN_RECURSIVE_PTR(arg.fib6_local_tbl);
        SCAN_RECURSIVE_PTR(arg.fib6_rules_ops);
//  Pointer(Pointer(Use(Struct(struct sock)))) arg.icmp_sk
        SCAN_RECURSIVE_PTR(arg.ndisc_sk);
        SCAN_RECURSIVE_PTR(arg.tcp_sk);
        SCAN_RECURSIVE_PTR(arg.igmp_sk);
        SCAN_RECURSIVE(arg.mr6_tables);
        SCAN_RECURSIVE_PTR(arg.mr6_rules_ops);
    }
})
#endif


//#define SCANNER_FOR_struct_netns_sctp
#ifndef SCANNER_FOR_struct_netns_sctp
#define SCANNER_FOR_struct_netns_sctp
TYPE_SCAN_WRAPPER(struct netns_sctp, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netns_sctp);
    }
    SCAN {
        S(kern_printk( "struct netns_sctp\n");)
        S(SCAN_OBJECT(arg);)
//  Array(Pointer(Expr)) arg.sctp_statistics
        SCAN_RECURSIVE_PTR(arg.proc_net_sctp);
        SCAN_RECURSIVE_PTR(arg.sysctl_header);
        SCAN_RECURSIVE_PTR(arg.ctl_sock);
        SCAN_RECURSIVE(arg.local_addr_list);
        SCAN_RECURSIVE(arg.addr_waitq);
        SCAN_RECURSIVE(arg.addr_wq_timer);
        SCAN_RECURSIVE(arg.auto_asconf_splist);
        SCAN_RECURSIVE(arg.addr_wq_lock);
        SCAN_RECURSIVE(arg.local_addr_lock);
        SCAN_FUNCTION(arg.rto_initial);
        SCAN_FUNCTION(arg.rto_min);
        SCAN_FUNCTION(arg.rto_max);
        SCAN_FUNCTION(arg.rto_alpha);
        SCAN_FUNCTION(arg.rto_beta);
        SCAN_FUNCTION(arg.max_burst);
        SCAN_FUNCTION(arg.cookie_preserve_enable);
        SCAN_FUNCTION(arg.sctp_hmac_alg);
        SCAN_FUNCTION(arg.valid_cookie_life);
        SCAN_FUNCTION(arg.sack_timeout);
        SCAN_FUNCTION(arg.hb_interval);
        SCAN_FUNCTION(arg.max_retrans_association);
        SCAN_FUNCTION(arg.max_retrans_path);
        SCAN_FUNCTION(arg.max_retrans_init);
        SCAN_FUNCTION(arg.pf_retrans);
        SCAN_FUNCTION(arg.sndbuf_policy);
        SCAN_FUNCTION(arg.rcvbuf_policy);
        SCAN_FUNCTION(arg.default_auto_asconf);
        SCAN_FUNCTION(arg.addip_enable);
        SCAN_FUNCTION(arg.addip_noauth);
        SCAN_FUNCTION(arg.prsctp_enable);
        SCAN_FUNCTION(arg.auth_enable);
        SCAN_FUNCTION(arg.scope_policy);
        SCAN_FUNCTION(arg.rwnd_upd_shift);
        SCAN_FUNCTION(arg.max_autoclose);
    }
})
#endif


//#define SCANNER_FOR_struct_netns_dccp
#ifndef SCANNER_FOR_struct_netns_dccp
#define SCANNER_FOR_struct_netns_dccp
TYPE_SCAN_WRAPPER(struct netns_dccp, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netns_dccp);
    }
    SCAN {
        S(kern_printk( "struct netns_dccp\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.v4_ctl_sk);
        SCAN_RECURSIVE_PTR(arg.v6_ctl_sk);
    }
})
#endif


//#define SCANNER_FOR_struct_nf_proto_net
#ifndef SCANNER_FOR_struct_nf_proto_net
#define SCANNER_FOR_struct_nf_proto_net
TYPE_SCAN_WRAPPER(struct nf_proto_net, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct nf_proto_net);
    }
    SCAN {
        S(kern_printk( "struct nf_proto_net\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.ctl_table_header);
        SCAN_RECURSIVE_PTR(arg.ctl_table);
        SCAN_RECURSIVE_PTR(arg.ctl_compat_header);
        SCAN_RECURSIVE_PTR(arg.ctl_compat_table);
        SCAN_FUNCTION(arg.users);
    }
})
#endif


//#define SCANNER_FOR_struct_nf_generic_net
#ifndef SCANNER_FOR_struct_nf_generic_net
#define SCANNER_FOR_struct_nf_generic_net
TYPE_SCAN_WRAPPER(struct nf_generic_net, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct nf_generic_net);
    }
    SCAN {
        S(kern_printk( "struct nf_generic_net\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.pn);
        SCAN_FUNCTION(arg.timeout);
    }
})
#endif


//#define SCANNER_FOR_struct_nf_tcp_net
#ifndef SCANNER_FOR_struct_nf_tcp_net
#define SCANNER_FOR_struct_nf_tcp_net
TYPE_SCAN_WRAPPER(struct nf_tcp_net, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct nf_tcp_net);
    }
    SCAN {
        S(kern_printk( "struct nf_tcp_net\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.pn);
//  Array(Attributed(unsigned , BuiltIn(int))) arg.timeouts
        SCAN_FUNCTION(arg.tcp_loose);
        SCAN_FUNCTION(arg.tcp_be_liberal);
        SCAN_FUNCTION(arg.tcp_max_retrans);
    }
})
#endif


//#define SCANNER_FOR_struct_nf_udp_net
#ifndef SCANNER_FOR_struct_nf_udp_net
#define SCANNER_FOR_struct_nf_udp_net
TYPE_SCAN_WRAPPER(struct nf_udp_net, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct nf_udp_net);
    }
    SCAN {
        S(kern_printk( "struct nf_udp_net\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.pn);
//  Array(Attributed(unsigned , BuiltIn(int))) arg.timeouts
    }
})
#endif


//#define SCANNER_FOR_struct_nf_icmp_net
#ifndef SCANNER_FOR_struct_nf_icmp_net
#define SCANNER_FOR_struct_nf_icmp_net
TYPE_SCAN_WRAPPER(struct nf_icmp_net, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct nf_icmp_net);
    }
    SCAN {
        S(kern_printk( "struct nf_icmp_net\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.pn);
        SCAN_FUNCTION(arg.timeout);
    }
})
#endif


//#define SCANNER_FOR_struct_nf_ip_net
#ifndef SCANNER_FOR_struct_nf_ip_net
#define SCANNER_FOR_struct_nf_ip_net
TYPE_SCAN_WRAPPER(struct nf_ip_net, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct nf_ip_net);
    }
    SCAN {
        S(kern_printk( "struct nf_ip_net\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.generic);
        SCAN_RECURSIVE(arg.tcp);
        SCAN_RECURSIVE(arg.udp);
        SCAN_RECURSIVE(arg.icmp);
        SCAN_RECURSIVE(arg.icmpv6);
        SCAN_RECURSIVE_PTR(arg.ctl_table_header);
        SCAN_RECURSIVE_PTR(arg.ctl_table);
    }
})
#endif


//#define SCANNER_FOR_struct_netns_ct
#ifndef SCANNER_FOR_struct_netns_ct
#define SCANNER_FOR_struct_netns_ct
TYPE_SCAN_WRAPPER(struct netns_ct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netns_ct);
    }
    SCAN {
        S(kern_printk( "struct netns_ct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.count);
        SCAN_FUNCTION(arg.expect_count);
        SCAN_FUNCTION(arg.htable_size);
        SCAN_RECURSIVE_PTR(arg.nf_conntrack_cachep);
        SCAN_RECURSIVE_PTR(arg.hash);
        SCAN_RECURSIVE_PTR(arg.expect_hash);
        SCAN_RECURSIVE(arg.unconfirmed);
        SCAN_RECURSIVE(arg.dying);
        SCAN_RECURSIVE(arg.tmpl);
        SCAN_RECURSIVE_PTR(arg.stat);
        SCAN_RECURSIVE_PTR(arg.nf_conntrack_event_cb);
        SCAN_RECURSIVE_PTR(arg.nf_expect_event_cb);
        SCAN_FUNCTION(arg.sysctl_events);
        SCAN_FUNCTION(arg.sysctl_events_retry_timeout);
        SCAN_FUNCTION(arg.sysctl_acct);
        SCAN_FUNCTION(arg.sysctl_tstamp);
        SCAN_FUNCTION(arg.sysctl_checksum);
        SCAN_FUNCTION(arg.sysctl_log_invalid);
        SCAN_FUNCTION(arg.sysctl_auto_assign_helper);
        SCAN_FUNCTION(arg.auto_assign_helper_warned);
        SCAN_RECURSIVE(arg.nf_ct_proto);
        SCAN_RECURSIVE_PTR(arg.sysctl_header);
        SCAN_RECURSIVE_PTR(arg.acct_sysctl_header);
        SCAN_RECURSIVE_PTR(arg.tstamp_sysctl_header);
        SCAN_RECURSIVE_PTR(arg.event_sysctl_header);
        SCAN_RECURSIVE_PTR(arg.helper_sysctl_header);
        SCAN_FUNCTION(arg.slabname);
    }
})
#endif


//#define SCANNER_FOR_struct_netns_nf_frag
#ifndef SCANNER_FOR_struct_netns_nf_frag
#define SCANNER_FOR_struct_netns_nf_frag
TYPE_SCAN_WRAPPER(struct netns_nf_frag, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netns_nf_frag);
    }
    SCAN {
        S(kern_printk( "struct netns_nf_frag\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.sysctl);
        SCAN_RECURSIVE(arg.frags);
    }
})
#endif


//#define SCANNER_FOR_struct_netns_xfrm
#ifndef SCANNER_FOR_struct_netns_xfrm
#define SCANNER_FOR_struct_netns_xfrm
TYPE_SCAN_WRAPPER(struct netns_xfrm, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netns_xfrm);
    }
    SCAN {
        S(kern_printk( "struct netns_xfrm\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.state_all);
        SCAN_RECURSIVE_PTR(arg.state_bydst);
        SCAN_RECURSIVE_PTR(arg.state_bysrc);
        SCAN_RECURSIVE_PTR(arg.state_byspi);
        SCAN_FUNCTION(arg.state_hmask);
        SCAN_FUNCTION(arg.state_num);
        SCAN_RECURSIVE(arg.state_hash_work);
        SCAN_RECURSIVE(arg.state_gc_list);
        SCAN_RECURSIVE(arg.state_gc_work);
        SCAN_RECURSIVE(arg.km_waitq);
        SCAN_RECURSIVE(arg.policy_all);
        SCAN_RECURSIVE_PTR(arg.policy_byidx);
        SCAN_FUNCTION(arg.policy_idx_hmask);
//  Array(Use(Struct(struct hlist_head))) arg.policy_inexact
//  Array(Use(Struct(struct xfrm_policy_hash))) arg.policy_bydst
//  Array(Attributed(unsigned , BuiltIn(int))) arg.policy_count
        SCAN_RECURSIVE(arg.policy_hash_work);
        SCAN_RECURSIVE_PTR(arg.nlsk);
        SCAN_RECURSIVE_PTR(arg.nlsk_stash);
        SCAN_FUNCTION(arg.sysctl_aevent_etime);
        SCAN_FUNCTION(arg.sysctl_aevent_rseqth);
        SCAN_FUNCTION(arg.sysctl_larval_drop);
        SCAN_FUNCTION(arg.sysctl_acq_expires);
        SCAN_RECURSIVE_PTR(arg.sysctl_hdr);
        SCAN_RECURSIVE(arg.xfrm4_dst_ops);
        SCAN_RECURSIVE(arg.xfrm6_dst_ops);
    }
})
#endif


//#define SCANNER_FOR_struct_net
#ifndef SCANNER_FOR_struct_net
#define SCANNER_FOR_struct_net
TYPE_SCAN_WRAPPER(struct net, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct net);
    }
    SCAN {
        S(kern_printk( "struct net\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.passive);
        SCAN_RECURSIVE(arg.count);
        SCAN_RECURSIVE(arg.rules_mod_lock);
        SCAN_RECURSIVE(arg.list);
        SCAN_RECURSIVE(arg.cleanup_list);
        SCAN_RECURSIVE(arg.exit_list);
        SCAN_RECURSIVE_PTR(arg.user_ns);
        SCAN_FUNCTION(arg.proc_inum);
        SCAN_RECURSIVE_PTR(arg.proc_net);
        SCAN_RECURSIVE_PTR(arg.proc_net_stat);
        SCAN_RECURSIVE(arg.sysctls);
        SCAN_RECURSIVE_PTR(arg.rtnl);
        SCAN_RECURSIVE_PTR(arg.genl_sock);
        SCAN_RECURSIVE(arg.dev_base_head);
        SCAN_RECURSIVE_PTR(arg.dev_name_head);
        SCAN_RECURSIVE_PTR(arg.dev_index_head);
        SCAN_FUNCTION(arg.dev_base_seq);
        SCAN_FUNCTION(arg.ifindex);
        SCAN_RECURSIVE(arg.rules_ops);
        SCAN_RECURSIVE_PTR(arg.loopback_dev);
        SCAN_RECURSIVE(arg.core);
        SCAN_RECURSIVE(arg.mib);
        SCAN_RECURSIVE(arg.packet);
        SCAN_RECURSIVE(arg.unx);
        SCAN_RECURSIVE(arg.ipv4);
        SCAN_RECURSIVE(arg.ipv6);
        SCAN_RECURSIVE(arg.sctp);
        SCAN_RECURSIVE(arg.dccp);
        SCAN_RECURSIVE(arg.xt);
        SCAN_RECURSIVE(arg.ct);
        SCAN_RECURSIVE(arg.nf_frag);
        SCAN_RECURSIVE_PTR(arg.nfnl);
        SCAN_RECURSIVE_PTR(arg.nfnl_stash);
        SCAN_RECURSIVE(arg.wext_nlevents);
        SCAN_RECURSIVE_PTR(arg.gen);
        SCAN_RECURSIVE(arg.xfrm);
        SCAN_RECURSIVE_PTR(arg.ipvs);
        SCAN_RECURSIVE_PTR(arg.diag_nlsk);
        SCAN_RECURSIVE(arg.rt_genid);
    }
})
#endif


//#define SCANNER_FOR_struct_nsproxy
#ifndef SCANNER_FOR_struct_nsproxy
#define SCANNER_FOR_struct_nsproxy
TYPE_SCAN_WRAPPER(struct nsproxy, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct nsproxy);
    }
    SCAN {
        S(kern_printk( "struct nsproxy\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.count);
        SCAN_RECURSIVE_PTR(arg.uts_ns);
        SCAN_RECURSIVE_PTR(arg.ipc_ns);
        SCAN_RECURSIVE_PTR(arg.mnt_ns);
        SCAN_RECURSIVE_PTR(arg.pid_ns);
        SCAN_RECURSIVE_PTR(arg.net_ns);
    }
})
#endif


//#define SCANNER_FOR_struct_hrtimer_clock_base
#ifndef SCANNER_FOR_struct_hrtimer_clock_base
#define SCANNER_FOR_struct_hrtimer_clock_base
TYPE_SCAN_WRAPPER(struct hrtimer_clock_base, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct hrtimer_clock_base);
    }
    SCAN {
        S(kern_printk( "struct hrtimer_clock_base\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.cpu_base);
        SCAN_FUNCTION(arg.index);
        SCAN_FUNCTION(arg.clockid);
        SCAN_RECURSIVE(arg.active);
//  Union(union ktime) arg.resolution
        SCAN_FUNCTION(arg.get_time);
//  Union(union ktime) arg.softirq_time
//  Union(union ktime) arg.offset
    }
})
#endif


//#define SCANNER_FOR_struct_hrtimer
#ifndef SCANNER_FOR_struct_hrtimer
#define SCANNER_FOR_struct_hrtimer
TYPE_SCAN_WRAPPER(struct hrtimer, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct hrtimer);
    }
    SCAN {
        S(kern_printk( "struct hrtimer\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.node);
//  Union(union ktime) arg._softexpires
        SCAN_FUNCTION(arg.function);
        SCAN_RECURSIVE_PTR(arg.base);
        SCAN_FUNCTION(arg.state);
        SCAN_FUNCTION(arg.start_pid);
        SCAN_FUNCTION(arg.start_site);
//  Array(BuiltIn(char)) arg.start_comm
    }
})
#endif


//#define SCANNER_FOR_struct_signal_struct
#ifndef SCANNER_FOR_struct_signal_struct
#define SCANNER_FOR_struct_signal_struct
TYPE_SCAN_WRAPPER(struct signal_struct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct signal_struct);
    }
    SCAN {
        S(kern_printk( "struct signal_struct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.sigcnt);
        SCAN_RECURSIVE(arg.live);
        SCAN_FUNCTION(arg.nr_threads);
        SCAN_RECURSIVE(arg.wait_chldexit);
        SCAN_RECURSIVE_PTR(arg.curr_target);
        SCAN_RECURSIVE(arg.shared_pending);
        SCAN_FUNCTION(arg.group_exit_code);
        SCAN_FUNCTION(arg.notify_count);
        SCAN_RECURSIVE_PTR(arg.group_exit_task);
        SCAN_FUNCTION(arg.group_stop_count);
        SCAN_FUNCTION(arg.flags);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.is_child_subreaper
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.has_child_subreaper
        SCAN_RECURSIVE(arg.posix_timers);
        SCAN_RECURSIVE(arg.real_timer);
        SCAN_RECURSIVE_PTR(arg.leader_pid);
//  Union(union ktime) arg.it_real_incr
//  Array(Use(Struct(struct cpu_itimer))) arg.it
        SCAN_RECURSIVE(arg.cputimer);
        SCAN_RECURSIVE(arg.cputime_expires);
//  Array(Use(Struct(struct list_head))) arg.cpu_timers
        SCAN_RECURSIVE_PTR(arg.tty_old_pgrp);
        SCAN_FUNCTION(arg.leader);
        SCAN_RECURSIVE_PTR(arg.tty);
        SCAN_RECURSIVE_PTR(arg.autogroup);
        SCAN_FUNCTION(arg.utime);
        SCAN_FUNCTION(arg.stime);
        SCAN_FUNCTION(arg.cutime);
        SCAN_FUNCTION(arg.cstime);
        SCAN_FUNCTION(arg.gtime);
        SCAN_FUNCTION(arg.cgtime);
        SCAN_RECURSIVE(arg.prev_cputime);
        SCAN_FUNCTION(arg.nvcsw);
        SCAN_FUNCTION(arg.nivcsw);
        SCAN_FUNCTION(arg.cnvcsw);
        SCAN_FUNCTION(arg.cnivcsw);
        SCAN_FUNCTION(arg.min_flt);
        SCAN_FUNCTION(arg.maj_flt);
        SCAN_FUNCTION(arg.cmin_flt);
        SCAN_FUNCTION(arg.cmaj_flt);
        SCAN_FUNCTION(arg.inblock);
        SCAN_FUNCTION(arg.oublock);
        SCAN_FUNCTION(arg.cinblock);
        SCAN_FUNCTION(arg.coublock);
        SCAN_FUNCTION(arg.maxrss);
        SCAN_FUNCTION(arg.cmaxrss);
        SCAN_RECURSIVE(arg.ioac);
        SCAN_FUNCTION(arg.sum_sched_runtime);
//  Array(Use(Struct(struct rlimit))) arg.rlim
        SCAN_RECURSIVE(arg.pacct);
        SCAN_RECURSIVE_PTR(arg.stats);
        SCAN_FUNCTION(arg.audit_tty);
        SCAN_RECURSIVE_PTR(arg.tty_audit_buf);
        SCAN_RECURSIVE(arg.group_rwsem);
        SCAN_FUNCTION(arg.oom_flags);
        SCAN_FUNCTION(arg.oom_score_adj);
        SCAN_FUNCTION(arg.oom_score_adj_min);
        SCAN_RECURSIVE(arg.cred_guard_mutex);
    }
})
#endif


//#define SCANNER_FOR_struct_sigaction
#ifndef SCANNER_FOR_struct_sigaction
#define SCANNER_FOR_struct_sigaction
TYPE_SCAN_WRAPPER(struct sigaction, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct sigaction);
    }
    SCAN {
        S(kern_printk( "struct sigaction\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.sa_handler);
        SCAN_FUNCTION(arg.sa_flags);
        SCAN_FUNCTION(arg.sa_restorer);
        SCAN_RECURSIVE(arg.sa_mask);
    }
})
#endif


//#define SCANNER_FOR_struct_k_sigaction
#ifndef SCANNER_FOR_struct_k_sigaction
#define SCANNER_FOR_struct_k_sigaction
TYPE_SCAN_WRAPPER(struct k_sigaction, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct k_sigaction);
    }
    SCAN {
        S(kern_printk( "struct k_sigaction\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.sa);
    }
})
#endif


//#define SCANNER_FOR_struct_bio_list
#ifndef SCANNER_FOR_struct_bio_list
#define SCANNER_FOR_struct_bio_list
TYPE_SCAN_WRAPPER(struct bio_list, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct bio_list);
    }
    SCAN {
        S(kern_printk( "struct bio_list\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.head);
        SCAN_RECURSIVE_PTR(arg.tail);
    }
})
#endif


//#define SCANNER_FOR_struct_css_set
#ifndef SCANNER_FOR_struct_css_set
#define SCANNER_FOR_struct_css_set
TYPE_SCAN_WRAPPER(struct css_set, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct css_set);
    }
    SCAN {
        S(kern_printk( "struct css_set\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.refcount);
        SCAN_RECURSIVE(arg.hlist);
        SCAN_RECURSIVE(arg.tasks);
        SCAN_RECURSIVE(arg.cg_links);
//  Array(Pointer(Use(Struct(struct cgroup_subsys_state)))) arg.subsys
        SCAN_RECURSIVE(arg.callback_head);
    }
})
#endif


//#define SCANNER_FOR_struct_page_frag
#ifndef SCANNER_FOR_struct_page_frag
#define SCANNER_FOR_struct_page_frag
TYPE_SCAN_WRAPPER(struct page_frag, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct page_frag);
    }
    SCAN {
        S(kern_printk( "struct page_frag\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.page);
        SCAN_FUNCTION(arg.offset);
        SCAN_FUNCTION(arg.size);
    }
})
#endif


//#define SCANNER_FOR_struct_task_struct
#ifndef SCANNER_FOR_struct_task_struct
#define SCANNER_FOR_struct_task_struct
TYPE_SCAN_WRAPPER(struct task_struct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct task_struct);
    }
    SCAN {
        S(kern_printk( "struct task_struct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.state);
        SCAN_FUNCTION(arg.stack);
        SCAN_RECURSIVE(arg.usage);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.ptrace);
        SCAN_RECURSIVE(arg.wake_entry);
        SCAN_FUNCTION(arg.on_cpu);
        SCAN_FUNCTION(arg.on_rq);
        SCAN_FUNCTION(arg.prio);
        SCAN_FUNCTION(arg.static_prio);
        SCAN_FUNCTION(arg.normal_prio);
        SCAN_FUNCTION(arg.rt_priority);
        SCAN_RECURSIVE_PTR(arg.sched_class);
        SCAN_RECURSIVE(arg.se);
        SCAN_RECURSIVE(arg.rt);
        SCAN_RECURSIVE_PTR(arg.sched_task_group);
        SCAN_RECURSIVE(arg.preempt_notifiers);
        SCAN_FUNCTION(arg.fpu_counter);
        SCAN_FUNCTION(arg.btrace_seq);
        SCAN_FUNCTION(arg.policy);
        SCAN_FUNCTION(arg.nr_cpus_allowed);
        SCAN_RECURSIVE(arg.cpus_allowed);
        SCAN_RECURSIVE(arg.sched_info);
        SCAN_RECURSIVE(arg.tasks);
        SCAN_RECURSIVE(arg.pushable_tasks);
        SCAN_RECURSIVE_PTR(arg.mm);
        SCAN_RECURSIVE_PTR(arg.active_mm);
        SCAN_RECURSIVE(arg.rss_stat);
        SCAN_FUNCTION(arg.exit_state);
        SCAN_FUNCTION(arg.exit_code);
        SCAN_FUNCTION(arg.exit_signal);
        SCAN_FUNCTION(arg.pdeath_signal);
        SCAN_FUNCTION(arg.jobctl);
        SCAN_FUNCTION(arg.personality);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.did_exec
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.in_execve
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.in_iowait
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.no_new_privs
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.sched_reset_on_fork
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.sched_contributes_to_load
        SCAN_FUNCTION(arg.pid);
        SCAN_FUNCTION(arg.tgid);
        SCAN_FUNCTION(arg.stack_canary);
        SCAN_RECURSIVE_PTR(arg.real_parent);
        SCAN_RECURSIVE_PTR(arg.parent);
        SCAN_RECURSIVE(arg.children);
        SCAN_RECURSIVE(arg.sibling);
        SCAN_RECURSIVE_PTR(arg.group_leader);
        SCAN_RECURSIVE(arg.ptraced);
        SCAN_RECURSIVE(arg.ptrace_entry);
//  Array(Use(Struct(struct pid_link))) arg.pids
        SCAN_RECURSIVE(arg.thread_group);
        SCAN_RECURSIVE_PTR(arg.vfork_done);
        SCAN_FUNCTION(arg.set_child_tid);
        SCAN_FUNCTION(arg.clear_child_tid);
        SCAN_FUNCTION(arg.utime);
        SCAN_FUNCTION(arg.stime);
        SCAN_FUNCTION(arg.utimescaled);
        SCAN_FUNCTION(arg.stimescaled);
        SCAN_FUNCTION(arg.gtime);
        SCAN_RECURSIVE(arg.prev_cputime);
        SCAN_FUNCTION(arg.nvcsw);
        SCAN_FUNCTION(arg.nivcsw);
        SCAN_RECURSIVE(arg.start_time);
        SCAN_RECURSIVE(arg.real_start_time);
        SCAN_FUNCTION(arg.min_flt);
        SCAN_FUNCTION(arg.maj_flt);
        SCAN_RECURSIVE(arg.cputime_expires);
//  Array(Use(Struct(struct list_head))) arg.cpu_timers
        SCAN_RECURSIVE_PTR(arg.real_cred);
        SCAN_RECURSIVE_PTR(arg.cred);
//  Array(BuiltIn(char)) arg.comm
        SCAN_FUNCTION(arg.link_count);
        SCAN_FUNCTION(arg.total_link_count);
        SCAN_RECURSIVE(arg.sysvsem);
        SCAN_FUNCTION(arg.last_switch_count);
        SCAN_RECURSIVE(arg.thread);
        SCAN_RECURSIVE_PTR(arg.fs);
        SCAN_RECURSIVE_PTR(arg.files);
        SCAN_RECURSIVE_PTR(arg.nsproxy);
        SCAN_RECURSIVE_PTR(arg.signal);
        SCAN_RECURSIVE_PTR(arg.sighand);
        SCAN_RECURSIVE(arg.blocked);
        SCAN_RECURSIVE(arg.real_blocked);
        SCAN_RECURSIVE(arg.saved_sigmask);
        SCAN_RECURSIVE(arg.pending);
        SCAN_FUNCTION(arg.sas_ss_sp);
        SCAN_FUNCTION(arg.sas_ss_size);
        SCAN_FUNCTION(arg.notifier);
        SCAN_FUNCTION(arg.notifier_data);
        SCAN_RECURSIVE_PTR(arg.notifier_mask);
        SCAN_RECURSIVE_PTR(arg.task_works);
        SCAN_RECURSIVE_PTR(arg.audit_context);
        SCAN_FUNCTION(arg.loginuid);
        SCAN_FUNCTION(arg.sessionid);
        SCAN_RECURSIVE(arg.seccomp);
        SCAN_FUNCTION(arg.parent_exec_id);
        SCAN_FUNCTION(arg.self_exec_id);
        SCAN_RECURSIVE(arg.alloc_lock);
        SCAN_RECURSIVE(arg.pi_lock);
        SCAN_RECURSIVE(arg.pi_waiters);
        SCAN_RECURSIVE_PTR(arg.pi_blocked_on);
        SCAN_FUNCTION(arg.journal_info);
        SCAN_RECURSIVE_PTR(arg.bio_list);
        SCAN_RECURSIVE_PTR(arg.plug);
        SCAN_RECURSIVE_PTR(arg.reclaim_state);
        SCAN_RECURSIVE_PTR(arg.backing_dev_info);
        SCAN_RECURSIVE_PTR(arg.io_context);
        SCAN_FUNCTION(arg.ptrace_message);
        SCAN_RECURSIVE_PTR(arg.last_siginfo);
        SCAN_RECURSIVE(arg.ioac);
        SCAN_FUNCTION(arg.acct_rss_mem1);
        SCAN_FUNCTION(arg.acct_vm_mem1);
        SCAN_FUNCTION(arg.acct_timexpd);
        SCAN_RECURSIVE(arg.mems_allowed);
        SCAN_RECURSIVE(arg.mems_allowed_seq);
        SCAN_FUNCTION(arg.cpuset_mem_spread_rotor);
        SCAN_FUNCTION(arg.cpuset_slab_spread_rotor);
        SCAN_RECURSIVE_PTR(arg.cgroups);
        SCAN_RECURSIVE(arg.cg_list);
        SCAN_RECURSIVE_PTR(arg.robust_list);
        SCAN_RECURSIVE_PTR(arg.compat_robust_list);
        SCAN_RECURSIVE(arg.pi_state_list);
        SCAN_RECURSIVE_PTR(arg.pi_state_cache);
//  Array(Pointer(Use(Struct(struct perf_event_context)))) arg.perf_event_ctxp
        SCAN_RECURSIVE(arg.perf_event_mutex);
        SCAN_RECURSIVE(arg.perf_event_list);
        SCAN_RECURSIVE_PTR(arg.mempolicy);
        SCAN_FUNCTION(arg.il_next);
        SCAN_FUNCTION(arg.pref_node_fork);
        SCAN_RECURSIVE(arg.rcu);
        SCAN_RECURSIVE_PTR(arg.splice_pipe);
        SCAN_RECURSIVE(arg.task_frag);
        SCAN_RECURSIVE_PTR(arg.delays);
        SCAN_FUNCTION(arg.nr_dirtied);
        SCAN_FUNCTION(arg.nr_dirtied_pause);
        SCAN_FUNCTION(arg.dirty_paused_when);
        SCAN_FUNCTION(arg.latency_record_count);
//  Array(Use(Struct(struct latency_record))) arg.latency_record
        SCAN_FUNCTION(arg.timer_slack_ns);
        SCAN_FUNCTION(arg.default_timer_slack_ns);
        SCAN_FUNCTION(arg.curr_ret_stack);
        SCAN_RECURSIVE_PTR(arg.ret_stack);
        SCAN_FUNCTION(arg.ftrace_timestamp);
        SCAN_RECURSIVE(arg.trace_overrun);
        SCAN_RECURSIVE(arg.tracing_graph_pause);
        SCAN_FUNCTION(arg.trace);
        SCAN_FUNCTION(arg.trace_recursion);
        SCAN_RECURSIVE(arg.ptrace_bp_refcnt);
    }
})
#endif


//#define SCANNER_FOR_struct_module
#ifndef SCANNER_FOR_struct_module
#define SCANNER_FOR_struct_module
TYPE_SCAN_WRAPPER(struct module, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct module);
    }
    SCAN {
        S(kern_printk( "struct module\n");)
        S(SCAN_OBJECT(arg);)
//  Enum(enum module_state) arg.state
        SCAN_RECURSIVE(arg.list);
//  Array(BuiltIn(char)) arg.name
        SCAN_RECURSIVE(arg.mkobj);
        SCAN_RECURSIVE_PTR(arg.modinfo_attrs);
        SCAN_FUNCTION(arg.version);
        SCAN_FUNCTION(arg.srcversion);
        SCAN_RECURSIVE_PTR(arg.holders_dir);
        SCAN_RECURSIVE_PTR(arg.syms);
        SCAN_FUNCTION(arg.crcs);
        SCAN_FUNCTION(arg.num_syms);
        SCAN_RECURSIVE_PTR(arg.kp);
        SCAN_FUNCTION(arg.num_kp);
        SCAN_FUNCTION(arg.num_gpl_syms);
        SCAN_RECURSIVE_PTR(arg.gpl_syms);
        SCAN_FUNCTION(arg.gpl_crcs);
        SCAN_RECURSIVE_PTR(arg.unused_syms);
        SCAN_FUNCTION(arg.unused_crcs);
        SCAN_FUNCTION(arg.num_unused_syms);
        SCAN_FUNCTION(arg.num_unused_gpl_syms);
        SCAN_RECURSIVE_PTR(arg.unused_gpl_syms);
        SCAN_FUNCTION(arg.unused_gpl_crcs);
        SCAN_RECURSIVE_PTR(arg.gpl_future_syms);
        SCAN_FUNCTION(arg.gpl_future_crcs);
        SCAN_FUNCTION(arg.num_gpl_future_syms);
        SCAN_FUNCTION(arg.num_exentries);
        SCAN_RECURSIVE_PTR(arg.extable);
        SCAN_FUNCTION(arg.init);
        SCAN_FUNCTION(arg.module_init);
        SCAN_FUNCTION(arg.module_core);
        SCAN_FUNCTION(arg.init_size);
        SCAN_FUNCTION(arg.core_size);
        SCAN_FUNCTION(arg.init_text_size);
        SCAN_FUNCTION(arg.core_text_size);
        SCAN_FUNCTION(arg.init_ro_size);
        SCAN_FUNCTION(arg.core_ro_size);
        SCAN_RECURSIVE(arg.arch);
        SCAN_FUNCTION(arg.taints);
        SCAN_FUNCTION(arg.num_bugs);
        SCAN_RECURSIVE(arg.bug_list);
        SCAN_RECURSIVE_PTR(arg.bug_table);
        SCAN_RECURSIVE_PTR(arg.symtab);
        SCAN_RECURSIVE_PTR(arg.core_symtab);
        SCAN_FUNCTION(arg.num_symtab);
        SCAN_FUNCTION(arg.core_num_syms);
        SCAN_FUNCTION(arg.strtab);
        SCAN_FUNCTION(arg.core_strtab);
        SCAN_RECURSIVE_PTR(arg.sect_attrs);
        SCAN_RECURSIVE_PTR(arg.notes_attrs);
        SCAN_FUNCTION(arg.args);
        SCAN_FUNCTION(arg.percpu);
        SCAN_FUNCTION(arg.percpu_size);
        SCAN_FUNCTION(arg.num_tracepoints);
//  Pointer(Pointer(const Use(Struct(struct tracepoint)))) arg.tracepoints_ptrs
        SCAN_FUNCTION(arg.num_trace_bprintk_fmt);
//  Pointer(Pointer(Attributed(const , BuiltIn(char)))) arg.trace_bprintk_fmt_start
//  Pointer(Pointer(Use(Struct(struct ftrace_event_call)))) arg.trace_events
        SCAN_FUNCTION(arg.num_trace_events);
        SCAN_FUNCTION(arg.num_ftrace_callsites);
        SCAN_FUNCTION(arg.ftrace_callsites);
        SCAN_RECURSIVE(arg.source_list);
        SCAN_RECURSIVE(arg.target_list);
        SCAN_RECURSIVE_PTR(arg.waiter);
        SCAN_FUNCTION(arg.exit);
        SCAN_RECURSIVE_PTR(arg.refptr);
    }
})
#endif


//#define SCANNER_FOR_struct_file_system_type
#ifndef SCANNER_FOR_struct_file_system_type
#define SCANNER_FOR_struct_file_system_type
TYPE_SCAN_WRAPPER(struct file_system_type, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct file_system_type);
    }
    SCAN {
        S(kern_printk( "struct file_system_type\n");)
        uint64_t *addr = (uint64_t*)(&arg);
        if(addr == NULL){
            return;
        }
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_FUNCTION(arg.fs_flags);
        SCAN_FUNCTION(arg.mount);
        SCAN_FUNCTION(arg.kill_sb);
        SCAN_RECURSIVE_PTR(arg.owner);
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_RECURSIVE(arg.fs_supers);
        SCAN_RECURSIVE(arg.s_lock_key);
        SCAN_RECURSIVE(arg.s_umount_key);
        SCAN_RECURSIVE(arg.s_vfs_rename_key);
//  Array(Use(Struct(struct lock_class_key))) arg.s_writers_key
        SCAN_RECURSIVE(arg.i_lock_key);
        SCAN_RECURSIVE(arg.i_mutex_key);
        SCAN_RECURSIVE(arg.i_mutex_dir_key);
    }
})
#endif


//#define SCANNER_FOR_struct_super_operations
#ifndef SCANNER_FOR_struct_super_operations
#define SCANNER_FOR_struct_super_operations
TYPE_SCAN_WRAPPER(struct super_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct super_operations);
    }
    SCAN {
        S(kern_printk( "struct super_operations\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.alloc_inode);
        SCAN_FUNCTION(arg.destroy_inode);
        SCAN_FUNCTION(arg.dirty_inode);
        SCAN_FUNCTION(arg.write_inode);
        SCAN_FUNCTION(arg.drop_inode);
        SCAN_FUNCTION(arg.evict_inode);
        SCAN_FUNCTION(arg.put_super);
        SCAN_FUNCTION(arg.sync_fs);
        SCAN_FUNCTION(arg.freeze_fs);
        SCAN_FUNCTION(arg.unfreeze_fs);
        SCAN_FUNCTION(arg.statfs);
        SCAN_FUNCTION(arg.remount_fs);
        SCAN_FUNCTION(arg.umount_begin);
        SCAN_FUNCTION(arg.show_options);
        SCAN_FUNCTION(arg.show_devname);
        SCAN_FUNCTION(arg.show_path);
        SCAN_FUNCTION(arg.show_stats);
        SCAN_FUNCTION(arg.quota_read);
        SCAN_FUNCTION(arg.quota_write);
        SCAN_FUNCTION(arg.bdev_try_to_free_page);
        SCAN_FUNCTION(arg.nr_cached_objects);
        SCAN_FUNCTION(arg.free_cached_objects);
    }
})
#endif


//#define SCANNER_FOR_struct_dquot
#ifndef SCANNER_FOR_struct_dquot
#define SCANNER_FOR_struct_dquot
TYPE_SCAN_WRAPPER(struct dquot, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dquot);
    }
    SCAN {
        S(kern_printk( "struct dquot\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.dq_hash);
        SCAN_RECURSIVE(arg.dq_inuse);
        SCAN_RECURSIVE(arg.dq_free);
        SCAN_RECURSIVE(arg.dq_dirty);
        SCAN_RECURSIVE(arg.dq_lock);
        SCAN_RECURSIVE(arg.dq_count);
        SCAN_RECURSIVE(arg.dq_wait_unused);
        SCAN_RECURSIVE_PTR(arg.dq_sb);
        SCAN_RECURSIVE(arg.dq_id);
        SCAN_FUNCTION(arg.dq_off);
        SCAN_FUNCTION(arg.dq_flags);
        SCAN_RECURSIVE(arg.dq_dqb);
    }
})
#endif


//#define SCANNER_FOR_struct_dquot_operations
#ifndef SCANNER_FOR_struct_dquot_operations
#define SCANNER_FOR_struct_dquot_operations
TYPE_SCAN_WRAPPER(struct dquot_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dquot_operations);
    }
    SCAN {
        S(kern_printk( "struct dquot_operations\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.write_dquot);
        SCAN_FUNCTION(arg.alloc_dquot);
        SCAN_FUNCTION(arg.destroy_dquot);
        SCAN_FUNCTION(arg.acquire_dquot);
        SCAN_FUNCTION(arg.release_dquot);
        SCAN_FUNCTION(arg.mark_dirty);
        SCAN_FUNCTION(arg.write_info);
        SCAN_FUNCTION(arg.get_reserved_space);
    }
})
#endif


//#define SCANNER_FOR_struct_quotactl_ops
#ifndef SCANNER_FOR_struct_quotactl_ops
#define SCANNER_FOR_struct_quotactl_ops
TYPE_SCAN_WRAPPER(struct quotactl_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct quotactl_ops);
    }
    SCAN {
        S(kern_printk( "struct quotactl_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.quota_on);
        SCAN_FUNCTION(arg.quota_on_meta);
        SCAN_FUNCTION(arg.quota_off);
        SCAN_FUNCTION(arg.quota_sync);
        SCAN_FUNCTION(arg.get_info);
        SCAN_FUNCTION(arg.set_info);
        SCAN_FUNCTION(arg.get_dqblk);
        SCAN_FUNCTION(arg.set_dqblk);
        SCAN_FUNCTION(arg.get_xstate);
        SCAN_FUNCTION(arg.set_xstate);
    }
})
#endif


//#define SCANNER_FOR_struct_export_operations
#ifndef SCANNER_FOR_struct_export_operations
#define SCANNER_FOR_struct_export_operations
TYPE_SCAN_WRAPPER(struct export_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct export_operations);
    }
    SCAN {
        S(kern_printk( "struct export_operations\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.encode_fh);
        SCAN_FUNCTION(arg.fh_to_dentry);
        SCAN_FUNCTION(arg.fh_to_parent);
        SCAN_FUNCTION(arg.get_name);
        SCAN_FUNCTION(arg.get_parent);
        SCAN_FUNCTION(arg.commit_metadata);
    }
})
#endif


//#define SCANNER_FOR_struct_xattr_handler
#ifndef SCANNER_FOR_struct_xattr_handler
#define SCANNER_FOR_struct_xattr_handler
TYPE_SCAN_WRAPPER(struct xattr_handler, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct xattr_handler);
    }
    SCAN {
        S(kern_printk( "struct xattr_handler\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.prefix);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.list);
        SCAN_FUNCTION(arg.get);
        SCAN_FUNCTION(arg.set);
    }
})
#endif


//#define SCANNER_FOR_struct_quota_format_ops
#ifndef SCANNER_FOR_struct_quota_format_ops
#define SCANNER_FOR_struct_quota_format_ops
TYPE_SCAN_WRAPPER(struct quota_format_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct quota_format_ops);
    }
    SCAN {
        S(kern_printk( "struct quota_format_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.check_quota_file);
        SCAN_FUNCTION(arg.read_file_info);
        SCAN_FUNCTION(arg.write_file_info);
        SCAN_FUNCTION(arg.free_file_info);
        SCAN_FUNCTION(arg.read_dqblk);
        SCAN_FUNCTION(arg.commit_dqblk);
        SCAN_FUNCTION(arg.release_dqblk);
    }
})
#endif


//#define SCANNER_FOR_struct_quota_format_type
#ifndef SCANNER_FOR_struct_quota_format_type
#define SCANNER_FOR_struct_quota_format_type
TYPE_SCAN_WRAPPER(struct quota_format_type, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct quota_format_type);
    }
    SCAN {
        S(kern_printk( "struct quota_format_type\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.qf_fmt_id);
        SCAN_RECURSIVE_PTR(arg.qf_ops);
        SCAN_RECURSIVE_PTR(arg.qf_owner);
        SCAN_RECURSIVE_PTR(arg.qf_next);
    }
})
#endif


//#define SCANNER_FOR_struct_mem_dqinfo
#ifndef SCANNER_FOR_struct_mem_dqinfo
#define SCANNER_FOR_struct_mem_dqinfo
TYPE_SCAN_WRAPPER(struct mem_dqinfo, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct mem_dqinfo);
    }
    SCAN {
        S(kern_printk( "struct mem_dqinfo\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.dqi_format);
        SCAN_FUNCTION(arg.dqi_fmt_id);
        SCAN_RECURSIVE(arg.dqi_dirty_list);
        SCAN_FUNCTION(arg.dqi_flags);
        SCAN_FUNCTION(arg.dqi_bgrace);
        SCAN_FUNCTION(arg.dqi_igrace);
        SCAN_FUNCTION(arg.dqi_maxblimit);
        SCAN_FUNCTION(arg.dqi_maxilimit);
        SCAN_FUNCTION(arg.dqi_priv);
    }
})
#endif


//#define SCANNER_FOR_struct_quota_info
#ifndef SCANNER_FOR_struct_quota_info
#define SCANNER_FOR_struct_quota_info
TYPE_SCAN_WRAPPER(struct quota_info, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct quota_info);
    }
    SCAN {
        S(kern_printk( "struct quota_info\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.flags);
        SCAN_RECURSIVE(arg.dqio_mutex);
        SCAN_RECURSIVE(arg.dqonoff_mutex);
        SCAN_RECURSIVE(arg.dqptr_sem);
//  Array(Pointer(Use(Struct(struct inode)))) arg.files
//  Array(Use(Struct(struct mem_dqinfo))) arg.info
//  Array(Pointer(Attributed(const , Use(Struct(struct quota_format_ops))))) arg.ops
    }
})
#endif


//#define SCANNER_FOR_struct_dentry_operations
#ifndef SCANNER_FOR_struct_dentry_operations
#define SCANNER_FOR_struct_dentry_operations
TYPE_SCAN_WRAPPER(struct dentry_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dentry_operations);
    }
    SCAN {
        S(kern_printk( "struct dentry_operations\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.d_revalidate);
        SCAN_FUNCTION(arg.d_hash);
        SCAN_FUNCTION(arg.d_compare);
        SCAN_FUNCTION(arg.d_delete);
        SCAN_FUNCTION(arg.d_release);
        SCAN_FUNCTION(arg.d_prune);
        SCAN_FUNCTION(arg.d_iput);
        SCAN_FUNCTION(arg.d_dname);
        SCAN_FUNCTION(arg.d_automount);
        SCAN_FUNCTION(arg.d_manage);
    }
})
#endif


//#define SCANNER_FOR_struct_shrinker
#ifndef SCANNER_FOR_struct_shrinker
#define SCANNER_FOR_struct_shrinker
TYPE_SCAN_WRAPPER(struct shrinker, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct shrinker);
    }
    SCAN {
        S(kern_printk( "struct shrinker\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.shrink);
        SCAN_FUNCTION(arg.seeks);
        SCAN_FUNCTION(arg.batch);
        SCAN_RECURSIVE(arg.list);
        SCAN_RECURSIVE(arg.nr_in_batch);
    }
})
#endif



#ifndef SCANNER_FOR_struct_super_block
#define SCANNER_FOR_struct_super_block
TYPE_SCAN_WRAPPER(struct super_block, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct super_block);
        VOID(htable);
    }
    SCAN {
        S(kern_printk( "struct super_block\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.s_list);
        SCAN_FUNCTION(arg.s_dev);
        SCAN_FUNCTION(arg.s_blocksize_bits);
        SCAN_FUNCTION(arg.s_blocksize);
        SCAN_FUNCTION(arg.s_maxbytes);
        SCAN_RECURSIVE_PTR(arg.s_type);
        SCAN_RECURSIVE_PTR(arg.s_op);
        SCAN_RECURSIVE_PTR(arg.dq_op);
        SCAN_RECURSIVE_PTR(arg.s_qcop);
        SCAN_RECURSIVE_PTR(arg.s_export_op);
        SCAN_FUNCTION(arg.s_flags);
        SCAN_FUNCTION(arg.s_magic);
        SCAN_RECURSIVE_PTR(arg.s_root);
        SCAN_RECURSIVE(arg.s_umount);
        SCAN_FUNCTION(arg.s_count);
        SCAN_RECURSIVE(arg.s_active);
        SCAN_FUNCTION(arg.s_security);
 /*       const struct xattr_handler **handlers(arg.s_xattr);
        const struct xattr_handler *handler(nullptr);
        if(handlers != nullptr){
            for((handler) = *(handlers)++;
                    handler;
                    (handler) = *(handlers)++) {
                SCAN_RECURSIVE_PTR(handler);
            }
        }*/
//  Pointer(Pointer(Attributed(const , Use(Struct(struct xattr_handler))))) arg.s_xattr
        SCAN_RECURSIVE(arg.s_inodes);
        SCAN_RECURSIVE(arg.s_anon);
        SCAN_RECURSIVE_PTR(arg.s_files);
        SCAN_RECURSIVE(arg.s_mounts);
        SCAN_RECURSIVE(arg.s_dentry_lru);
        SCAN_FUNCTION(arg.s_nr_dentry_unused);
        SCAN_RECURSIVE(arg.s_inode_lru_lock);
        SCAN_RECURSIVE(arg.s_inode_lru);
        SCAN_FUNCTION(arg.s_nr_inodes_unused);
        SCAN_RECURSIVE_PTR(arg.s_bdev);
        SCAN_RECURSIVE_PTR(arg.s_bdi);
        SCAN_RECURSIVE_PTR(arg.s_mtd);
        SCAN_RECURSIVE(arg.s_instances);
        SCAN_RECURSIVE(arg.s_dquot);
        SCAN_RECURSIVE(arg.s_writers);
//  Array(BuiltIn(char)) arg.s_id
//  Array(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.s_uuid
        SCAN_FUNCTION(arg.s_fs_info);
        SCAN_FUNCTION(arg.s_max_links);
        SCAN_FUNCTION(arg.s_mode);
        SCAN_FUNCTION(arg.s_time_gran);
        SCAN_RECURSIVE(arg.s_vfs_rename_mutex);
        SCAN_FUNCTION(arg.s_subtype);
        SCAN_FUNCTION(arg.s_options);
        SCAN_RECURSIVE_PTR(arg.s_d_op);
        SCAN_FUNCTION(arg.cleancache_poolid);
        SCAN_RECURSIVE(arg.s_shrink);
        SCAN_RECURSIVE(arg.s_remove_count);
        SCAN_FUNCTION(arg.s_readonly_remount);
    }
})
#endif


#ifndef SCANNER_FOR_struct_inode
#define SCANNER_FOR_struct_inode
TYPE_SCAN_WRAPPER(struct inode, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct inode);
    }
    SCAN {
        S(kern_printk( "struct inode : %lx\n", ((uint64_t*)&arg));)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.i_mode);
        SCAN_FUNCTION(arg.i_opflags);
        SCAN_FUNCTION(arg.i_uid);
        SCAN_FUNCTION(arg.i_gid);
        SCAN_FUNCTION(arg.i_flags);
        SCAN_RECURSIVE_PTR(arg.i_acl);
        SCAN_RECURSIVE_PTR(arg.i_default_acl);
        SCAN_RECURSIVE_PTR(arg.i_op);
        SCAN_RECURSIVE_PTR(arg.i_sb);
        SCAN_RECURSIVE_PTR(arg.i_mapping);
        SCAN_FUNCTION(arg.i_security);
        SCAN_FUNCTION(arg.i_ino);
//  Union(union anon_union_121) None
        SCAN_FUNCTION(arg.i_rdev);
        SCAN_FUNCTION(arg.i_size);
        SCAN_RECURSIVE(arg.i_atime);
        SCAN_RECURSIVE(arg.i_mtime);
        SCAN_RECURSIVE(arg.i_ctime);
        SCAN_RECURSIVE(arg.i_lock);
        SCAN_FUNCTION(arg.i_bytes);
        SCAN_FUNCTION(arg.i_blkbits);
        SCAN_FUNCTION(arg.i_blocks);
        SCAN_FUNCTION(arg.i_state);
        SCAN_RECURSIVE(arg.i_mutex);
        SCAN_FUNCTION(arg.dirtied_when);
        SCAN_RECURSIVE(arg.i_hash);
        SCAN_RECURSIVE(arg.i_wb_list);
        SCAN_RECURSIVE(arg.i_lru);
        SCAN_RECURSIVE(arg.i_sb_list);
//  Union(union anon_union_122) None
        SCAN_FUNCTION(arg.i_version);
        SCAN_RECURSIVE(arg.i_count);
        SCAN_RECURSIVE(arg.i_dio_count);
        SCAN_RECURSIVE(arg.i_writecount);
        SCAN_RECURSIVE_PTR(arg.i_fop);
        SCAN_RECURSIVE_PTR(arg.i_flock);
        SCAN_RECURSIVE(arg.i_data);
        SCAN_RECURSIVE_PTR(arg.i_dquot[0]);
        SCAN_RECURSIVE_PTR(arg.i_dquot[1]);
//  Array(Pointer(Use(Struct(struct dquot)))) arg.i_dquot
        SCAN_RECURSIVE(arg.i_devices);
//  Union(union anon_union_123) None
        SCAN_FUNCTION(arg.i_generation);
        SCAN_FUNCTION(arg.i_fsnotify_mask);
        SCAN_RECURSIVE(arg.i_fsnotify_marks);
        SCAN_FUNCTION(arg.i_private);
    }
})
#endif


//#define SCANNER_FOR_struct_dentry
#ifndef SCANNER_FOR_struct_dentry
#define SCANNER_FOR_struct_dentry
TYPE_SCAN_WRAPPER(struct dentry, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dentry);
    }
    SCAN {
        S(kern_printk( "struct dentry\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.d_flags);
        SCAN_RECURSIVE(arg.d_seq);
        SCAN_RECURSIVE(arg.d_hash);
        SCAN_RECURSIVE_PTR(arg.d_parent);
        SCAN_RECURSIVE(arg.d_name);
        SCAN_RECURSIVE_PTR(arg.d_inode);
//  Array(Attributed(unsigned , BuiltIn(char))) arg.d_iname
        SCAN_FUNCTION(arg.d_count);
        SCAN_RECURSIVE(arg.d_lock);
        SCAN_RECURSIVE_PTR(arg.d_op);
        SCAN_RECURSIVE_PTR(arg.d_sb);
        SCAN_FUNCTION(arg.d_time);
        SCAN_FUNCTION(arg.d_fsdata);
        SCAN_RECURSIVE(arg.d_lru);
//  Union(union anon_union_114) arg.d_u
        SCAN_RECURSIVE(arg.d_subdirs);
        SCAN_RECURSIVE(arg.d_alias);
    }
})
#endif


#ifndef SCANNER_FOR_struct_vfsmount
#define SCANNER_FOR_struct_vfsmount
TYPE_SCAN_WRAPPER(struct vfsmount, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct vfsmount);
    }
    SCAN {
        S(kern_printk( "struct vfsmount\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.mnt_root);
        SCAN_RECURSIVE_PTR(arg.mnt_sb);
        SCAN_FUNCTION(arg.mnt_flags);
    }
})
#endif



#ifndef SCANNER_FOR_struct_path
#define SCANNER_FOR_struct_path
TYPE_SCAN_WRAPPER(struct path, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct path);
    }
    SCAN {
        S(kern_printk( "struct path\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.mnt);
        SCAN_RECURSIVE_PTR(arg.dentry);
    }
})
#endif



#ifndef SCANNER_FOR_struct_fown_struct
#define SCANNER_FOR_struct_fown_struct
TYPE_SCAN_WRAPPER(struct fown_struct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct fown_struct);
    }
    SCAN {
        S(kern_printk( "struct fown_struct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE_PTR(arg.pid);
//  Enum(enum pid_type) arg.pid_type
        SCAN_FUNCTION(arg.uid);
        SCAN_FUNCTION(arg.euid);
        SCAN_FUNCTION(arg.signum);
    }
})
#endif



#ifndef SCANNER_FOR_struct_file
#define SCANNER_FOR_struct_file
TYPE_SCAN_WRAPPER(struct file, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct file);
    }
    SCAN {
        S(kern_printk( "struct file\n");)
        S(SCAN_OBJECT(arg);)
//  Union(union anon_union_115) arg.f_u
        SCAN_RECURSIVE(arg.f_path);
        SCAN_RECURSIVE_PTR(arg.f_op);
        SCAN_RECURSIVE(arg.f_lock);
        SCAN_FUNCTION(arg.f_sb_list_cpu);
        SCAN_RECURSIVE(arg.f_count);
        SCAN_FUNCTION(arg.f_flags);
        SCAN_FUNCTION(arg.f_mode);
        SCAN_FUNCTION(arg.f_pos);
        SCAN_RECURSIVE(arg.f_owner);
        SCAN_RECURSIVE_PTR(arg.f_cred);
        SCAN_RECURSIVE(arg.f_ra);
        SCAN_FUNCTION(arg.f_version);
        SCAN_FUNCTION(arg.f_security);
        SCAN_FUNCTION(arg.private_data);
        SCAN_RECURSIVE(arg.f_ep_links);
        SCAN_RECURSIVE(arg.f_tfile_llink);
        SCAN_RECURSIVE_PTR(arg.f_mapping);
    }
})
#endif


#ifndef SCANNER_FOR_struct_aio_ring_info
#define SCANNER_FOR_struct_aio_ring_info
TYPE_SCAN_WRAPPER(struct aio_ring_info, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct aio_ring_info);
    }
    SCAN {
        S(kern_printk( "struct aio_ring_info\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.mmap_base);
        SCAN_FUNCTION(arg.mmap_size);
//  Pointer(Pointer(Use(Struct(struct page)))) arg.ring_pages
        SCAN_RECURSIVE(arg.ring_lock);
        SCAN_FUNCTION(arg.nr_pages);
        SCAN_FUNCTION(arg.nr);
        SCAN_FUNCTION(arg.tail);
//  Array(Pointer(Use(Struct(struct page)))) arg.internal_pages
    }
})
#endif


//#define SCANNER_FOR_struct_kioctx
#ifndef SCANNER_FOR_struct_kioctx
#define SCANNER_FOR_struct_kioctx
TYPE_SCAN_WRAPPER(struct kioctx, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct kioctx);
    }
    SCAN {
        S(kern_printk( "struct kioctx\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.users);
        SCAN_FUNCTION(arg.dead);
        SCAN_RECURSIVE_PTR(arg.mm);
        SCAN_FUNCTION(arg.user_id);
        SCAN_RECURSIVE(arg.list);
        SCAN_RECURSIVE(arg.wait);
        SCAN_RECURSIVE(arg.ctx_lock);
        SCAN_FUNCTION(arg.reqs_active);
        SCAN_RECURSIVE(arg.active_reqs);
        SCAN_RECURSIVE(arg.run_list);
        SCAN_FUNCTION(arg.max_reqs);
        SCAN_RECURSIVE(arg.ring_info);
        SCAN_RECURSIVE(arg.wq);
        SCAN_RECURSIVE(arg.callback_head);
    }
})
#endif


//#define SCANNER_FOR_struct_kiocb
#ifndef SCANNER_FOR_struct_kiocb
#define SCANNER_FOR_struct_kiocb
TYPE_SCAN_WRAPPER(struct kiocb, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct kiocb);
    }
    SCAN {
        S(kern_printk( "struct kiocb\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.ki_run_list);
        SCAN_FUNCTION(arg.ki_flags);
        SCAN_FUNCTION(arg.ki_users);
        SCAN_FUNCTION(arg.ki_key);
        SCAN_RECURSIVE_PTR(arg.ki_filp);
        SCAN_RECURSIVE_PTR(arg.ki_ctx);
        SCAN_FUNCTION(arg.ki_cancel);
        SCAN_FUNCTION(arg.ki_retry);
        SCAN_FUNCTION(arg.ki_dtor);
//  Union(union anon_union_59) arg.ki_obj
        SCAN_FUNCTION(arg.ki_user_data);
        SCAN_FUNCTION(arg.ki_pos);
        SCAN_FUNCTION(arg.private_);
        SCAN_FUNCTION(arg.ki_opcode);
        SCAN_FUNCTION(arg.ki_nbytes);
        SCAN_FUNCTION(arg.ki_buf);
        SCAN_FUNCTION(arg.ki_left);
        SCAN_RECURSIVE(arg.ki_inline_vec);
        SCAN_RECURSIVE_PTR(arg.ki_iovec);
        SCAN_FUNCTION(arg.ki_nr_segs);
        SCAN_FUNCTION(arg.ki_cur_seg);
        SCAN_RECURSIVE(arg.ki_list);
        SCAN_RECURSIVE(arg.ki_batch);
        SCAN_RECURSIVE_PTR(arg.ki_eventfd);
    }
})
#endif


//#define SCANNER_FOR_struct_request_sock
#ifndef SCANNER_FOR_struct_request_sock
#define SCANNER_FOR_struct_request_sock
TYPE_SCAN_WRAPPER(struct request_sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct request_sock);
    }
    SCAN {
        S(kern_printk( "struct request_sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.dl_next);
        SCAN_FUNCTION(arg.mss);
        SCAN_FUNCTION(arg.num_retrans);
//  Bitfield(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.cookie_ts
//  Bitfield(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.num_timeout
        SCAN_FUNCTION(arg.window_clamp);
        SCAN_FUNCTION(arg.rcv_wnd);
        SCAN_FUNCTION(arg.ts_recent);
        SCAN_FUNCTION(arg.expires);
        SCAN_RECURSIVE_PTR(arg.rsk_ops);
        SCAN_RECURSIVE_PTR(arg.sk);
        SCAN_FUNCTION(arg.secid);
        SCAN_FUNCTION(arg.peer_secid);
    }
})
#endif


//#define SCANNER_FOR_struct_request_sock_ops
#ifndef SCANNER_FOR_struct_request_sock_ops
#define SCANNER_FOR_struct_request_sock_ops
TYPE_SCAN_WRAPPER(struct request_sock_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct request_sock_ops);
    }
    SCAN {
        S(kern_printk( "struct request_sock_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.family);
        SCAN_FUNCTION(arg.obj_size);
        SCAN_RECURSIVE_PTR(arg.slab);
        SCAN_FUNCTION(arg.slab_name);
        SCAN_FUNCTION(arg.rtx_syn_ack);
        SCAN_FUNCTION(arg.send_ack);
        SCAN_FUNCTION(arg.send_reset);
        SCAN_FUNCTION(arg.destructor);
        SCAN_FUNCTION(arg.syn_ack_timeout);
    }
})
#endif


//#define SCANNER_FOR_struct_timewait_sock_ops
#ifndef SCANNER_FOR_struct_timewait_sock_ops
#define SCANNER_FOR_struct_timewait_sock_ops
TYPE_SCAN_WRAPPER(struct timewait_sock_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct timewait_sock_ops);
    }
    SCAN {
        S(kern_printk( "struct timewait_sock_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.twsk_slab);
        SCAN_FUNCTION(arg.twsk_slab_name);
        SCAN_FUNCTION(arg.twsk_obj_size);
        SCAN_FUNCTION(arg.twsk_unique);
        SCAN_FUNCTION(arg.twsk_destructor);
    }
})
#endif


////#define SCANNER_FOR_struct_proto
#ifndef SCANNER_FOR_struct_proto
#define SCANNER_FOR_struct_proto
TYPE_SCAN_WRAPPER(struct proto, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct proto);
    }
    SCAN {
        S(kern_printk( "struct proto\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.close);
        SCAN_FUNCTION(arg.connect);
        SCAN_FUNCTION(arg.disconnect);
        SCAN_FUNCTION(arg.accept);
        SCAN_FUNCTION(arg.ioctl);
        SCAN_FUNCTION(arg.init);
        SCAN_FUNCTION(arg.destroy);
        SCAN_FUNCTION(arg.shutdown);
        SCAN_FUNCTION(arg.setsockopt);
        SCAN_FUNCTION(arg.getsockopt);
        SCAN_FUNCTION(arg.compat_setsockopt);
        SCAN_FUNCTION(arg.compat_getsockopt);
        SCAN_FUNCTION(arg.compat_ioctl);
        SCAN_FUNCTION(arg.sendmsg);
        SCAN_FUNCTION(arg.recvmsg);
        SCAN_FUNCTION(arg.sendpage);
        SCAN_FUNCTION(arg.bind);
        SCAN_FUNCTION(arg.backlog_rcv);
        SCAN_FUNCTION(arg.release_cb);
        SCAN_FUNCTION(arg.mtu_reduced);
        SCAN_FUNCTION(arg.hash);
        SCAN_FUNCTION(arg.unhash);
        SCAN_FUNCTION(arg.rehash);
        SCAN_FUNCTION(arg.get_port);
        SCAN_FUNCTION(arg.clear_sk);
        SCAN_FUNCTION(arg.inuse_idx);
        SCAN_FUNCTION(arg.enter_memory_pressure);
        SCAN_RECURSIVE_PTR(arg.memory_allocated);
        SCAN_RECURSIVE_PTR(arg.sockets_allocated);
        SCAN_FUNCTION(arg.memory_pressure);
        SCAN_FUNCTION(arg.sysctl_mem);
        SCAN_FUNCTION(arg.sysctl_wmem);
        SCAN_FUNCTION(arg.sysctl_rmem);
        SCAN_FUNCTION(arg.max_header);
        SCAN_FUNCTION(arg.no_autobind);
        SCAN_RECURSIVE_PTR(arg.slab);
        SCAN_FUNCTION(arg.obj_size);
        SCAN_FUNCTION(arg.slab_flags);
        SCAN_RECURSIVE_PTR(arg.orphan_count);
        SCAN_RECURSIVE_PTR(arg.rsk_prot);
        SCAN_RECURSIVE_PTR(arg.twsk_prot);
//  Union(union anon_union_69) arg.h
        SCAN_RECURSIVE_PTR(arg.owner);
//  Array(BuiltIn(char)) arg.name
        SCAN_RECURSIVE(arg.node);
    }
})
#endif


//#define SCANNER_FOR_struct_sock_common
#ifndef SCANNER_FOR_struct_sock_common
#define SCANNER_FOR_struct_sock_common
TYPE_SCAN_WRAPPER(struct sock_common, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct sock_common);
    }
    SCAN {
        S(kern_printk( "struct sock_common\n");)
        S(SCAN_OBJECT(arg);)
//  Union(union anon_union_84) None
//  Union(union anon_union_85) None
//  Union(union anon_union_86) None
        SCAN_FUNCTION(arg.skc_family);
        SCAN_FUNCTION(arg.skc_state);
        SCAN_FUNCTION(arg.skc_reuse);
        SCAN_FUNCTION(arg.skc_bound_dev_if);
//  Union(union anon_union_87) None
        SCAN_RECURSIVE_PTR(arg.skc_prot);
        SCAN_RECURSIVE_PTR(arg.skc_net);
//  Array(BuiltIn(int)) arg.skc_dontcopy_begin
//  Union(union anon_union_88) None
        SCAN_FUNCTION(arg.skc_tx_queue_mapping);
        SCAN_RECURSIVE(arg.skc_refcnt);
//  Array(BuiltIn(int)) arg.skc_dontcopy_end
    }
})
#endif


//#define SCANNER_FOR_struct_sk_filter
#ifndef SCANNER_FOR_struct_sk_filter
#define SCANNER_FOR_struct_sk_filter
TYPE_SCAN_WRAPPER(struct sk_filter, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct sk_filter);
    }
    SCAN {
        S(kern_printk( "struct sk_filter\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.refcnt);
        SCAN_FUNCTION(arg.len);
        SCAN_FUNCTION(arg.bpf_func);
        SCAN_RECURSIVE(arg.rcu);
//  Array(Use(Struct(struct sock_filter))) arg.insns
    }
})
#endif


//#define SCANNER_FOR_struct_socket_wq
#ifndef SCANNER_FOR_struct_socket_wq
#define SCANNER_FOR_struct_socket_wq
TYPE_SCAN_WRAPPER(struct socket_wq, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct socket_wq);
    }
    SCAN {
        S(kern_printk( "struct socket_wq\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.wait);
        SCAN_RECURSIVE_PTR(arg.fasync_list);
        SCAN_RECURSIVE(arg.rcu);
    }
})
#endif


//#define SCANNER_FOR_struct_proto_ops
#ifndef SCANNER_FOR_struct_proto_ops
#define SCANNER_FOR_struct_proto_ops
TYPE_SCAN_WRAPPER(struct proto_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct proto_ops);
    }
    SCAN {
        S(kern_printk( "struct proto_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.family);
        SCAN_RECURSIVE_PTR(arg.owner);
        SCAN_FUNCTION(arg.release);
        SCAN_FUNCTION(arg.bind);
        SCAN_FUNCTION(arg.connect);
        SCAN_FUNCTION(arg.socketpair);
        SCAN_FUNCTION(arg.accept);
        SCAN_FUNCTION(arg.getname);
        SCAN_FUNCTION(arg.poll);
        SCAN_FUNCTION(arg.ioctl);
        SCAN_FUNCTION(arg.compat_ioctl);
        SCAN_FUNCTION(arg.listen);
        SCAN_FUNCTION(arg.shutdown);
        SCAN_FUNCTION(arg.setsockopt);
        SCAN_FUNCTION(arg.getsockopt);
        SCAN_FUNCTION(arg.compat_setsockopt);
        SCAN_FUNCTION(arg.compat_getsockopt);
        SCAN_FUNCTION(arg.sendmsg);
        SCAN_FUNCTION(arg.recvmsg);
        SCAN_FUNCTION(arg.mmap);
        SCAN_FUNCTION(arg.sendpage);
        SCAN_FUNCTION(arg.splice_read);
        SCAN_FUNCTION(arg.set_peek_off);
    }
})
#endif


//#define SCANNER_FOR_struct_socket
#ifndef SCANNER_FOR_struct_socket
#define SCANNER_FOR_struct_socket
TYPE_SCAN_WRAPPER(struct socket, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct socket);
    }
    SCAN {
        S(kern_printk( "struct socket\n");)
        S(SCAN_OBJECT(arg);)
//  Enum(socket_state) arg.state
        SCAN_FUNCTION(arg.type);
        SCAN_FUNCTION(arg.flags);
        SCAN_RECURSIVE_PTR(arg.wq);
        SCAN_RECURSIVE_PTR(arg.file);
        SCAN_RECURSIVE_PTR(arg.sk);
        SCAN_RECURSIVE_PTR(arg.ops);
    }
})
#endif


//#define SCANNER_FOR_struct_cg_proto
#ifndef SCANNER_FOR_struct_cg_proto
#define SCANNER_FOR_struct_cg_proto
TYPE_SCAN_WRAPPER(struct cg_proto, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cg_proto);
    }
    SCAN {
        S(kern_printk( "struct cg_proto\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.enter_memory_pressure);
        SCAN_RECURSIVE_PTR(arg.memory_allocated);
        SCAN_RECURSIVE_PTR(arg.sockets_allocated);
        SCAN_FUNCTION(arg.memory_pressure);
        SCAN_FUNCTION(arg.sysctl_mem);
        SCAN_FUNCTION(arg.flags);
        SCAN_RECURSIVE_PTR(arg.memcg);
    }
})
#endif


//#define SCANNER_FOR_struct_sock
#ifndef SCANNER_FOR_struct_sock
#define SCANNER_FOR_struct_sock
TYPE_SCAN_WRAPPER(struct sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct sock);
    }
    SCAN {
        S(kern_printk( "struct sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.__sk_common);
        SCAN_RECURSIVE(arg.sk_lock);
        SCAN_RECURSIVE(arg.sk_receive_queue);
        SCAN_RECURSIVE(arg.sk_backlog);
        SCAN_FUNCTION(arg.sk_forward_alloc);
        SCAN_FUNCTION(arg.sk_rxhash);
        SCAN_RECURSIVE(arg.sk_drops);
        SCAN_FUNCTION(arg.sk_rcvbuf);
        SCAN_RECURSIVE_PTR(arg.sk_filter);
        SCAN_RECURSIVE_PTR(arg.sk_wq);
        SCAN_RECURSIVE(arg.sk_async_wait_queue);
//  Array(Pointer(Use(Struct(struct xfrm_policy)))) arg.sk_policy
        SCAN_FUNCTION(arg.sk_flags);
        SCAN_RECURSIVE_PTR(arg.sk_rx_dst);
        SCAN_RECURSIVE_PTR(arg.sk_dst_cache);
        SCAN_RECURSIVE(arg.sk_dst_lock);
        SCAN_RECURSIVE(arg.sk_wmem_alloc);
        SCAN_RECURSIVE(arg.sk_omem_alloc);
        SCAN_FUNCTION(arg.sk_sndbuf);
        SCAN_RECURSIVE(arg.sk_write_queue);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.sk_shutdown
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.sk_no_check
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.sk_userlocks
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.sk_protocol
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.sk_type
        SCAN_FUNCTION(arg.sk_wmem_queued);
        SCAN_FUNCTION(arg.sk_allocation);
        SCAN_FUNCTION(arg.sk_route_caps);
        SCAN_FUNCTION(arg.sk_route_nocaps);
        SCAN_FUNCTION(arg.sk_gso_type);
        SCAN_FUNCTION(arg.sk_gso_max_size);
        SCAN_FUNCTION(arg.sk_gso_max_segs);
        SCAN_FUNCTION(arg.sk_rcvlowat);
        SCAN_FUNCTION(arg.sk_lingertime);
        SCAN_RECURSIVE(arg.sk_error_queue);
        SCAN_RECURSIVE_PTR(arg.sk_prot_creator);
        SCAN_RECURSIVE(arg.sk_callback_lock);
        SCAN_FUNCTION(arg.sk_err);
        SCAN_FUNCTION(arg.sk_err_soft);
        SCAN_FUNCTION(arg.sk_ack_backlog);
        SCAN_FUNCTION(arg.sk_max_ack_backlog);
        SCAN_FUNCTION(arg.sk_priority);
        SCAN_RECURSIVE_PTR(arg.sk_peer_pid);
        SCAN_RECURSIVE_PTR(arg.sk_peer_cred);
        SCAN_FUNCTION(arg.sk_rcvtimeo);
        SCAN_FUNCTION(arg.sk_sndtimeo);
        SCAN_FUNCTION(arg.sk_protinfo);
        SCAN_RECURSIVE(arg.sk_timer);
//  Union(union ktime) arg.sk_stamp
        SCAN_RECURSIVE_PTR(arg.sk_socket);
        SCAN_FUNCTION(arg.sk_user_data);
        SCAN_RECURSIVE(arg.sk_frag);
        SCAN_RECURSIVE_PTR(arg.sk_send_head);
        SCAN_FUNCTION(arg.sk_peek_off);
        SCAN_FUNCTION(arg.sk_write_pending);
        SCAN_FUNCTION(arg.sk_security);
        SCAN_FUNCTION(arg.sk_mark);
        SCAN_FUNCTION(arg.sk_classid);
        SCAN_RECURSIVE_PTR(arg.sk_cgrp);
        SCAN_FUNCTION(arg.sk_state_change);
        SCAN_FUNCTION(arg.sk_data_ready);
        SCAN_FUNCTION(arg.sk_write_space);
        SCAN_FUNCTION(arg.sk_error_report);
        SCAN_FUNCTION(arg.sk_backlog_rcv);
        SCAN_FUNCTION(arg.sk_destruct);
    }
})
#endif


//#define SCANNER_FOR_struct_nf_bridge_info
#ifndef SCANNER_FOR_struct_nf_bridge_info
#define SCANNER_FOR_struct_nf_bridge_info
TYPE_SCAN_WRAPPER(struct nf_bridge_info, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct nf_bridge_info);
    }
    SCAN {
        S(kern_printk( "struct nf_bridge_info\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.use);
        SCAN_FUNCTION(arg.mask);
        SCAN_RECURSIVE_PTR(arg.physindev);
        SCAN_RECURSIVE_PTR(arg.physoutdev);
//  Array(Attributed(unsigned , BuiltIn(long))) arg.data
    }
})
#endif


//#define SCANNER_FOR_struct_sk_buff
#ifndef SCANNER_FOR_struct_sk_buff
#define SCANNER_FOR_struct_sk_buff
TYPE_SCAN_WRAPPER(struct sk_buff, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct sk_buff);
    }
    SCAN {
        S(kern_printk( "struct sk_buff\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_RECURSIVE_PTR(arg.prev);
//  Union(union ktime) arg.tstamp
        SCAN_RECURSIVE_PTR(arg.sk);
        SCAN_RECURSIVE_PTR(arg.dev);
//  Array(BuiltIn(char)) arg.cb
        SCAN_FUNCTION(arg._skb_refdst);
        SCAN_RECURSIVE_PTR(arg.sp);
        SCAN_FUNCTION(arg.len);
        SCAN_FUNCTION(arg.data_len);
        SCAN_FUNCTION(arg.mac_len);
        SCAN_FUNCTION(arg.hdr_len);
//  Union(union anon_union_63) None
        SCAN_FUNCTION(arg.priority);
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.local_df
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.cloned
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.ip_summed
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.nohdr
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.nfctinfo
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.pkt_type
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.fclone
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.ipvs_property
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.peeked
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.nf_trace
        SCAN_FUNCTION(arg.protocol);
        SCAN_FUNCTION(arg.destructor);
        SCAN_RECURSIVE_PTR(arg.nfct);
        SCAN_RECURSIVE_PTR(arg.nfct_reasm);
        SCAN_RECURSIVE_PTR(arg.nf_bridge);
        SCAN_FUNCTION(arg.skb_iif);
        SCAN_FUNCTION(arg.rxhash);
        SCAN_FUNCTION(arg.vlan_tci);
        SCAN_FUNCTION(arg.tc_index);
        SCAN_FUNCTION(arg.tc_verd);
        SCAN_FUNCTION(arg.queue_mapping);
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.ndisc_nodetype
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.pfmemalloc
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.ooo_okay
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.l4_rxhash
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.wifi_acked_valid
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.wifi_acked
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.no_fcs
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.head_frag
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.encapsulation
        SCAN_FUNCTION(arg.dma_cookie);
        SCAN_FUNCTION(arg.secmark);
//  Union(union anon_union_64) None
        SCAN_FUNCTION(arg.inner_transport_header);
        SCAN_FUNCTION(arg.inner_network_header);
        SCAN_FUNCTION(arg.transport_header);
        SCAN_FUNCTION(arg.network_header);
        SCAN_FUNCTION(arg.mac_header);
        SCAN_FUNCTION(arg.tail);
        SCAN_FUNCTION(arg.end);
        SCAN_FUNCTION(arg.head);
        SCAN_FUNCTION(arg.data);
        SCAN_FUNCTION(arg.truesize);
        SCAN_RECURSIVE(arg.users);
    }
})
#endif


//#define SCANNER_FOR_struct_netlink_callback
#ifndef SCANNER_FOR_struct_netlink_callback
#define SCANNER_FOR_struct_netlink_callback
TYPE_SCAN_WRAPPER(struct netlink_callback, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netlink_callback);
    }
    SCAN {
        S(kern_printk( "struct netlink_callback\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.skb);
        SCAN_RECURSIVE_PTR(arg.nlh);
        SCAN_FUNCTION(arg.dump);
        SCAN_FUNCTION(arg.done);
        SCAN_FUNCTION(arg.data);
        SCAN_RECURSIVE_PTR(arg.module);
        SCAN_FUNCTION(arg.family);
        SCAN_FUNCTION(arg.min_dump_alloc);
        SCAN_FUNCTION(arg.prev_seq);
        SCAN_FUNCTION(arg.seq);
//  Array(BuiltIn(long)) arg.args
    }
})
#endif


//#define SCANNER_FOR_struct_net_device_ops
#ifndef SCANNER_FOR_struct_net_device_ops
#define SCANNER_FOR_struct_net_device_ops
TYPE_SCAN_WRAPPER(struct net_device_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct net_device_ops);
    }
    SCAN {
        S(kern_printk( "struct net_device_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.ndo_init);
        SCAN_FUNCTION(arg.ndo_uninit);
        SCAN_FUNCTION(arg.ndo_open);
        SCAN_FUNCTION(arg.ndo_stop);
        SCAN_FUNCTION(arg.ndo_start_xmit);
        SCAN_FUNCTION(arg.ndo_select_queue);
        SCAN_FUNCTION(arg.ndo_change_rx_flags);
        SCAN_FUNCTION(arg.ndo_set_rx_mode);
        SCAN_FUNCTION(arg.ndo_set_mac_address);
        SCAN_FUNCTION(arg.ndo_validate_addr);
        SCAN_FUNCTION(arg.ndo_do_ioctl);
        SCAN_FUNCTION(arg.ndo_set_config);
        SCAN_FUNCTION(arg.ndo_change_mtu);
        SCAN_FUNCTION(arg.ndo_neigh_setup);
        SCAN_FUNCTION(arg.ndo_tx_timeout);
        SCAN_FUNCTION(arg.ndo_get_stats64);
        SCAN_FUNCTION(arg.ndo_get_stats);
        SCAN_FUNCTION(arg.ndo_vlan_rx_add_vid);
        SCAN_FUNCTION(arg.ndo_vlan_rx_kill_vid);
        SCAN_FUNCTION(arg.ndo_poll_controller);
        SCAN_FUNCTION(arg.ndo_netpoll_setup);
        SCAN_FUNCTION(arg.ndo_netpoll_cleanup);
        SCAN_FUNCTION(arg.ndo_set_vf_mac);
        SCAN_FUNCTION(arg.ndo_set_vf_vlan);
        SCAN_FUNCTION(arg.ndo_set_vf_tx_rate);
        SCAN_FUNCTION(arg.ndo_set_vf_spoofchk);
        SCAN_FUNCTION(arg.ndo_get_vf_config);
        SCAN_FUNCTION(arg.ndo_set_vf_port);
        SCAN_FUNCTION(arg.ndo_get_vf_port);
        SCAN_FUNCTION(arg.ndo_setup_tc);
        SCAN_FUNCTION(arg.ndo_fcoe_enable);
        SCAN_FUNCTION(arg.ndo_fcoe_disable);
        SCAN_FUNCTION(arg.ndo_fcoe_ddp_setup);
        SCAN_FUNCTION(arg.ndo_fcoe_ddp_done);
        SCAN_FUNCTION(arg.ndo_fcoe_ddp_target);
        SCAN_FUNCTION(arg.ndo_fcoe_get_hbainfo);
        SCAN_FUNCTION(arg.ndo_fcoe_get_wwn);
        SCAN_FUNCTION(arg.ndo_rx_flow_steer);
        SCAN_FUNCTION(arg.ndo_add_slave);
        SCAN_FUNCTION(arg.ndo_del_slave);
        SCAN_FUNCTION(arg.ndo_fix_features);
        SCAN_FUNCTION(arg.ndo_set_features);
        SCAN_FUNCTION(arg.ndo_neigh_construct);
        SCAN_FUNCTION(arg.ndo_neigh_destroy);
        SCAN_FUNCTION(arg.ndo_fdb_add);
        SCAN_FUNCTION(arg.ndo_fdb_del);
        SCAN_FUNCTION(arg.ndo_fdb_dump);
        SCAN_FUNCTION(arg.ndo_bridge_setlink);
        SCAN_FUNCTION(arg.ndo_bridge_getlink);
    }
})
#endif


//#define SCANNER_FOR_struct_ethtool_ops
#ifndef SCANNER_FOR_struct_ethtool_ops
#define SCANNER_FOR_struct_ethtool_ops
TYPE_SCAN_WRAPPER(struct ethtool_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ethtool_ops);
    }
    SCAN {
        S(kern_printk( "struct ethtool_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.get_settings);
        SCAN_FUNCTION(arg.set_settings);
        SCAN_FUNCTION(arg.get_drvinfo);
        SCAN_FUNCTION(arg.get_regs_len);
        SCAN_FUNCTION(arg.get_regs);
        SCAN_FUNCTION(arg.get_wol);
        SCAN_FUNCTION(arg.set_wol);
        SCAN_FUNCTION(arg.get_msglevel);
        SCAN_FUNCTION(arg.set_msglevel);
        SCAN_FUNCTION(arg.nway_reset);
        SCAN_FUNCTION(arg.get_link);
        SCAN_FUNCTION(arg.get_eeprom_len);
        SCAN_FUNCTION(arg.get_eeprom);
        SCAN_FUNCTION(arg.set_eeprom);
        SCAN_FUNCTION(arg.get_coalesce);
        SCAN_FUNCTION(arg.set_coalesce);
        SCAN_FUNCTION(arg.get_ringparam);
        SCAN_FUNCTION(arg.set_ringparam);
        SCAN_FUNCTION(arg.get_pauseparam);
        SCAN_FUNCTION(arg.set_pauseparam);
        SCAN_FUNCTION(arg.self_test);
        SCAN_FUNCTION(arg.get_strings);
        SCAN_FUNCTION(arg.set_phys_id);
        SCAN_FUNCTION(arg.get_ethtool_stats);
        SCAN_FUNCTION(arg.begin);
        SCAN_FUNCTION(arg.complete);
        SCAN_FUNCTION(arg.get_priv_flags);
        SCAN_FUNCTION(arg.set_priv_flags);
        SCAN_FUNCTION(arg.get_sset_count);
        SCAN_FUNCTION(arg.get_rxnfc);
        SCAN_FUNCTION(arg.set_rxnfc);
        SCAN_FUNCTION(arg.flash_device);
        SCAN_FUNCTION(arg.reset);
        SCAN_FUNCTION(arg.get_rxfh_indir_size);
        SCAN_FUNCTION(arg.get_rxfh_indir);
        SCAN_FUNCTION(arg.set_rxfh_indir);
        SCAN_FUNCTION(arg.get_channels);
        SCAN_FUNCTION(arg.set_channels);
        SCAN_FUNCTION(arg.get_dump_flag);
        SCAN_FUNCTION(arg.get_dump_data);
        SCAN_FUNCTION(arg.set_dump);
        SCAN_FUNCTION(arg.get_ts_info);
        SCAN_FUNCTION(arg.get_module_info);
        SCAN_FUNCTION(arg.get_module_eeprom);
        SCAN_FUNCTION(arg.get_eee);
        SCAN_FUNCTION(arg.set_eee);
    }
})
#endif


//#define SCANNER_FOR_struct_header_ops
#ifndef SCANNER_FOR_struct_header_ops
#define SCANNER_FOR_struct_header_ops
TYPE_SCAN_WRAPPER(struct header_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct header_ops);
    }
    SCAN {
        S(kern_printk( "struct header_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.create);
        SCAN_FUNCTION(arg.parse);
        SCAN_FUNCTION(arg.rebuild);
        SCAN_FUNCTION(arg.cache);
        SCAN_FUNCTION(arg.cache_update);
    }
})
#endif


//#define SCANNER_FOR_struct_dsa_chip_data
#ifndef SCANNER_FOR_struct_dsa_chip_data
#define SCANNER_FOR_struct_dsa_chip_data
TYPE_SCAN_WRAPPER(struct dsa_chip_data, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dsa_chip_data);
    }
    SCAN {
        S(kern_printk( "struct dsa_chip_data\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.mii_bus);
        SCAN_FUNCTION(arg.sw_addr);
//  Array(Pointer(BuiltIn(char))) arg.port_names
        SCAN_FUNCTION(arg.rtable);
    }
})
#endif


//#define SCANNER_FOR_struct_dsa_platform_data
#ifndef SCANNER_FOR_struct_dsa_platform_data
#define SCANNER_FOR_struct_dsa_platform_data
TYPE_SCAN_WRAPPER(struct dsa_platform_data, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dsa_platform_data);
    }
    SCAN {
        S(kern_printk( "struct dsa_platform_data\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.netdev);
        SCAN_FUNCTION(arg.nr_chips);
        SCAN_RECURSIVE_PTR(arg.chip);
    }
})
#endif


//#define SCANNER_FOR_struct_phy_driver
#ifndef SCANNER_FOR_struct_phy_driver
#define SCANNER_FOR_struct_phy_driver
TYPE_SCAN_WRAPPER(struct phy_driver, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct phy_driver);
    }
    SCAN {
        S(kern_printk( "struct phy_driver\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.phy_id);
        SCAN_FUNCTION(arg.name);
        SCAN_FUNCTION(arg.phy_id_mask);
        SCAN_FUNCTION(arg.features);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.config_init);
        SCAN_FUNCTION(arg.probe);
        SCAN_FUNCTION(arg.suspend);
        SCAN_FUNCTION(arg.resume);
        SCAN_FUNCTION(arg.config_aneg);
        SCAN_FUNCTION(arg.read_status);
        SCAN_FUNCTION(arg.ack_interrupt);
        SCAN_FUNCTION(arg.config_intr);
        SCAN_FUNCTION(arg.did_interrupt);
        SCAN_FUNCTION(arg.remove);
        SCAN_FUNCTION(arg.match_phy_device);
        SCAN_FUNCTION(arg.ts_info);
        SCAN_FUNCTION(arg.hwtstamp);
        SCAN_FUNCTION(arg.rxtstamp);
        SCAN_FUNCTION(arg.txtstamp);
        SCAN_RECURSIVE(arg.driver);
    }
})
#endif


//#define SCANNER_FOR_struct_phy_device
#ifndef SCANNER_FOR_struct_phy_device
#define SCANNER_FOR_struct_phy_device
TYPE_SCAN_WRAPPER(struct phy_device, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct phy_device);
    }
    SCAN {
        S(kern_printk( "struct phy_device\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.drv);
        SCAN_RECURSIVE_PTR(arg.bus);
        SCAN_RECURSIVE(arg.dev);
        SCAN_FUNCTION(arg.phy_id);
        SCAN_RECURSIVE(arg.c45_ids);
        SCAN_FUNCTION(arg.is_c45);
//  Enum(enum phy_state) arg.state
        SCAN_FUNCTION(arg.dev_flags);
//  Enum(phy_interface_t) arg.interface
        SCAN_FUNCTION(arg.addr);
        SCAN_FUNCTION(arg.speed);
        SCAN_FUNCTION(arg.duplex);
        SCAN_FUNCTION(arg.pause);
        SCAN_FUNCTION(arg.asym_pause);
        SCAN_FUNCTION(arg.link);
        SCAN_FUNCTION(arg.interrupts);
        SCAN_FUNCTION(arg.supported);
        SCAN_FUNCTION(arg.advertising);
        SCAN_FUNCTION(arg.autoneg);
        SCAN_FUNCTION(arg.link_timeout);
        SCAN_FUNCTION(arg.irq);
        SCAN_FUNCTION(arg.priv);
        SCAN_RECURSIVE(arg.phy_queue);
        SCAN_RECURSIVE(arg.state_queue);
        SCAN_RECURSIVE(arg.irq_disable);
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE_PTR(arg.attached_dev);
        SCAN_FUNCTION(arg.adjust_link);
        SCAN_FUNCTION(arg.adjust_state);
    }
})
#endif


//#define SCANNER_FOR_struct_mii_bus
#ifndef SCANNER_FOR_struct_mii_bus
#define SCANNER_FOR_struct_mii_bus
TYPE_SCAN_WRAPPER(struct mii_bus, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct mii_bus);
    }
    SCAN {
        S(kern_printk( "struct mii_bus\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
//  Array(BuiltIn(char)) arg.id
        SCAN_FUNCTION(arg.priv);
        SCAN_FUNCTION(arg.read);
        SCAN_FUNCTION(arg.write);
        SCAN_FUNCTION(arg.reset);
        SCAN_RECURSIVE(arg.mdio_lock);
        SCAN_RECURSIVE_PTR(arg.parent);
//  Enum(enum anon_enum_420) arg.state
        SCAN_RECURSIVE(arg.dev);
//  Array(Pointer(Use(Struct(struct phy_device)))) arg.phy_map
        SCAN_FUNCTION(arg.phy_mask);
        SCAN_FUNCTION(arg.irq);
    }
})
#endif


//#define SCANNER_FOR_struct_dsa_switch_driver
#ifndef SCANNER_FOR_struct_dsa_switch_driver
#define SCANNER_FOR_struct_dsa_switch_driver
TYPE_SCAN_WRAPPER(struct dsa_switch_driver, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dsa_switch_driver);
    }
    SCAN {
        S(kern_printk( "struct dsa_switch_driver\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_FUNCTION(arg.tag_protocol);
        SCAN_FUNCTION(arg.priv_size);
        SCAN_FUNCTION(arg.probe);
        SCAN_FUNCTION(arg.setup);
        SCAN_FUNCTION(arg.set_addr);
        SCAN_FUNCTION(arg.phy_read);
        SCAN_FUNCTION(arg.phy_write);
        SCAN_FUNCTION(arg.poll_link);
        SCAN_FUNCTION(arg.get_strings);
        SCAN_FUNCTION(arg.get_ethtool_stats);
        SCAN_FUNCTION(arg.get_sset_count);
    }
})
#endif


//#define SCANNER_FOR_struct_dsa_switch
#ifndef SCANNER_FOR_struct_dsa_switch
#define SCANNER_FOR_struct_dsa_switch
TYPE_SCAN_WRAPPER(struct dsa_switch, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dsa_switch);
    }
    SCAN {
        S(kern_printk( "struct dsa_switch\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.dst);
        SCAN_FUNCTION(arg.index);
        SCAN_RECURSIVE_PTR(arg.pd);
        SCAN_RECURSIVE_PTR(arg.drv);
        SCAN_RECURSIVE_PTR(arg.master_mii_bus);
        SCAN_FUNCTION(arg.dsa_port_mask);
        SCAN_FUNCTION(arg.phys_port_mask);
        SCAN_RECURSIVE_PTR(arg.slave_mii_bus);
//  Array(Pointer(Use(Struct(struct net_device)))) arg.ports
    }
})
#endif


//#define SCANNER_FOR_struct_dsa_switch_tree
#ifndef SCANNER_FOR_struct_dsa_switch_tree
#define SCANNER_FOR_struct_dsa_switch_tree
TYPE_SCAN_WRAPPER(struct dsa_switch_tree, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dsa_switch_tree);
    }
    SCAN {
        S(kern_printk( "struct dsa_switch_tree\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.pd);
        SCAN_RECURSIVE_PTR(arg.master_netdev);
        SCAN_FUNCTION(arg.tag_protocol);
        SCAN_FUNCTION(arg.cpu_switch);
        SCAN_FUNCTION(arg.cpu_port);
        SCAN_FUNCTION(arg.link_poll_needed);
        SCAN_RECURSIVE(arg.link_poll_work);
        SCAN_RECURSIVE(arg.link_poll_timer);
//  Array(Pointer(Use(Struct(struct dsa_switch)))) arg.ds
    }
})
#endif


//#define SCANNER_FOR_struct_rps_map
#ifndef SCANNER_FOR_struct_rps_map
#define SCANNER_FOR_struct_rps_map
TYPE_SCAN_WRAPPER(struct rps_map, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct rps_map);
    }
    SCAN {
        S(kern_printk( "struct rps_map\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.len);
        SCAN_RECURSIVE(arg.rcu);
//  Array(Use(TypeDef(u16, Attributed(unsigned , BuiltIn(short))))) arg.cpus
    }
})
#endif


//#define SCANNER_FOR_struct_rps_dev_flow_table
#ifndef SCANNER_FOR_struct_rps_dev_flow_table
#define SCANNER_FOR_struct_rps_dev_flow_table
TYPE_SCAN_WRAPPER(struct rps_dev_flow_table, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct rps_dev_flow_table);
    }
    SCAN {
        S(kern_printk( "struct rps_dev_flow_table\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.mask);
        SCAN_RECURSIVE(arg.rcu);
        SCAN_RECURSIVE(arg.free_work);
//  Array(Use(Struct(struct rps_dev_flow))) arg.flows
    }
})
#endif


//#define SCANNER_FOR_struct_netdev_rx_queue
#ifndef SCANNER_FOR_struct_netdev_rx_queue
#define SCANNER_FOR_struct_netdev_rx_queue
TYPE_SCAN_WRAPPER(struct netdev_rx_queue, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netdev_rx_queue);
    }
    SCAN {
        S(kern_printk( "struct netdev_rx_queue\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.rps_map);
        SCAN_RECURSIVE_PTR(arg.rps_flow_table);
        SCAN_RECURSIVE(arg.kobj);
        SCAN_RECURSIVE_PTR(arg.dev);
    }
})
#endif


//#define SCANNER_FOR_struct_qdisc_walker
#ifndef SCANNER_FOR_struct_qdisc_walker
#define SCANNER_FOR_struct_qdisc_walker
TYPE_SCAN_WRAPPER(struct qdisc_walker, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct qdisc_walker);
    }
    SCAN {
        S(kern_printk( "struct qdisc_walker\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.stop);
        SCAN_FUNCTION(arg.skip);
        SCAN_FUNCTION(arg.count);
        SCAN_FUNCTION(arg.fn);
    }
})
#endif


//#define SCANNER_FOR_struct_tcf_proto_ops
#ifndef SCANNER_FOR_struct_tcf_proto_ops
#define SCANNER_FOR_struct_tcf_proto_ops
TYPE_SCAN_WRAPPER(struct tcf_proto_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tcf_proto_ops);
    }
    SCAN {
        S(kern_printk( "struct tcf_proto_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.next);
//  Array(BuiltIn(char)) arg.kind
        SCAN_FUNCTION(arg.classify);
        SCAN_FUNCTION(arg.init);
        SCAN_FUNCTION(arg.destroy);
        SCAN_FUNCTION(arg.get);
        SCAN_FUNCTION(arg.put);
        SCAN_FUNCTION(arg.change);
        SCAN_FUNCTION(arg.delete_);
        SCAN_FUNCTION(arg.walk);
        SCAN_FUNCTION(arg.dump);
        SCAN_RECURSIVE_PTR(arg.owner);
    }
})
#endif


//#define SCANNER_FOR_struct_tcf_proto
#ifndef SCANNER_FOR_struct_tcf_proto
#define SCANNER_FOR_struct_tcf_proto
TYPE_SCAN_WRAPPER(struct tcf_proto, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tcf_proto);
    }
    SCAN {
        S(kern_printk( "struct tcf_proto\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_FUNCTION(arg.root);
        SCAN_FUNCTION(arg.classify);
        SCAN_FUNCTION(arg.protocol);
        SCAN_FUNCTION(arg.prio);
        SCAN_FUNCTION(arg.classid);
        SCAN_RECURSIVE_PTR(arg.q);
        SCAN_FUNCTION(arg.data);
        SCAN_RECURSIVE_PTR(arg.ops);
    }
})
#endif


//#define SCANNER_FOR_struct_gnet_dump
#ifndef SCANNER_FOR_struct_gnet_dump
#define SCANNER_FOR_struct_gnet_dump
TYPE_SCAN_WRAPPER(struct gnet_dump, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct gnet_dump);
    }
    SCAN {
        S(kern_printk( "struct gnet_dump\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.lock);
        SCAN_RECURSIVE_PTR(arg.skb);
        SCAN_RECURSIVE_PTR(arg.tail);
        SCAN_FUNCTION(arg.compat_tc_stats);
        SCAN_FUNCTION(arg.compat_xstats);
        SCAN_FUNCTION(arg.xstats);
        SCAN_FUNCTION(arg.xstats_len);
        SCAN_RECURSIVE(arg.tc_stats);
    }
})
#endif


//#define SCANNER_FOR_struct_Qdisc_class_ops
#ifndef SCANNER_FOR_struct_Qdisc_class_ops
#define SCANNER_FOR_struct_Qdisc_class_ops
TYPE_SCAN_WRAPPER(struct Qdisc_class_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct Qdisc_class_ops);
    }
    SCAN {
        S(kern_printk( "struct Qdisc_class_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.select_queue);
        SCAN_FUNCTION(arg.graft);
        SCAN_FUNCTION(arg.leaf);
        SCAN_FUNCTION(arg.qlen_notify);
        SCAN_FUNCTION(arg.get);
        SCAN_FUNCTION(arg.put);
        SCAN_FUNCTION(arg.change);
        SCAN_FUNCTION(arg.delete_);
        SCAN_FUNCTION(arg.walk);
        SCAN_FUNCTION(arg.tcf_chain);
        SCAN_FUNCTION(arg.bind_tcf);
        SCAN_FUNCTION(arg.unbind_tcf);
        SCAN_FUNCTION(arg.dump);
        SCAN_FUNCTION(arg.dump_stats);
    }
})
#endif


//#define SCANNER_FOR_struct_Qdisc_ops
#ifndef SCANNER_FOR_struct_Qdisc_ops
#define SCANNER_FOR_struct_Qdisc_ops
TYPE_SCAN_WRAPPER(struct Qdisc_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct Qdisc_ops);
    }
    SCAN {
        S(kern_printk( "struct Qdisc_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_RECURSIVE_PTR(arg.cl_ops);
//  Array(BuiltIn(char)) arg.id
        SCAN_FUNCTION(arg.priv_size);
        SCAN_FUNCTION(arg.enqueue);
        SCAN_FUNCTION(arg.dequeue);
        SCAN_FUNCTION(arg.peek);
        SCAN_FUNCTION(arg.drop);
        SCAN_FUNCTION(arg.init);
        SCAN_FUNCTION(arg.reset);
        SCAN_FUNCTION(arg.destroy);
        SCAN_FUNCTION(arg.change);
        SCAN_FUNCTION(arg.attach);
        SCAN_FUNCTION(arg.dump);
        SCAN_FUNCTION(arg.dump_stats);
        SCAN_RECURSIVE_PTR(arg.owner);
    }
})
#endif


//#define SCANNER_FOR_struct_qdisc_size_table
#ifndef SCANNER_FOR_struct_qdisc_size_table
#define SCANNER_FOR_struct_qdisc_size_table
TYPE_SCAN_WRAPPER(struct qdisc_size_table, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct qdisc_size_table);
    }
    SCAN {
        S(kern_printk( "struct qdisc_size_table\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.rcu);
        SCAN_RECURSIVE(arg.list);
        SCAN_RECURSIVE(arg.szopts);
        SCAN_FUNCTION(arg.refcnt);
//  Array(Use(TypeDef(u16, Attributed(unsigned , BuiltIn(short))))) arg.data
    }
})
#endif


//#define SCANNER_FOR_struct_Qdisc
#ifndef SCANNER_FOR_struct_Qdisc
#define SCANNER_FOR_struct_Qdisc
TYPE_SCAN_WRAPPER(struct Qdisc, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct Qdisc);
    }
    SCAN {
        S(kern_printk( "struct Qdisc\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.enqueue);
        SCAN_FUNCTION(arg.dequeue);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.padded);
        SCAN_RECURSIVE_PTR(arg.ops);
        SCAN_RECURSIVE_PTR(arg.stab);
        SCAN_RECURSIVE(arg.list);
        SCAN_FUNCTION(arg.handle);
        SCAN_FUNCTION(arg.parent);
        SCAN_RECURSIVE(arg.refcnt);
        SCAN_RECURSIVE(arg.rate_est);
        SCAN_FUNCTION(arg.reshape_fail);
        SCAN_FUNCTION(arg.u32_node);
        SCAN_RECURSIVE_PTR(arg.__parent);
        SCAN_RECURSIVE_PTR(arg.dev_queue);
        SCAN_RECURSIVE_PTR(arg.next_sched);
        SCAN_RECURSIVE_PTR(arg.gso_skb);
        SCAN_FUNCTION(arg.state);
        SCAN_RECURSIVE(arg.q);
        SCAN_RECURSIVE(arg.bstats);
        SCAN_FUNCTION(arg.__state);
        SCAN_RECURSIVE(arg.qstats);
        SCAN_RECURSIVE(arg.callback_head);
        SCAN_RECURSIVE(arg.busylock);
        SCAN_FUNCTION(arg.limit);
    }
})
#endif


//#define SCANNER_FOR_struct_netdev_queue
#ifndef SCANNER_FOR_struct_netdev_queue
#define SCANNER_FOR_struct_netdev_queue
TYPE_SCAN_WRAPPER(struct netdev_queue, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netdev_queue);
    }
    SCAN {
        S(kern_printk( "struct netdev_queue\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.dev);
        SCAN_RECURSIVE_PTR(arg.qdisc);
        SCAN_RECURSIVE_PTR(arg.qdisc_sleeping);
        SCAN_RECURSIVE(arg.kobj);
        SCAN_FUNCTION(arg.numa_node);
        SCAN_RECURSIVE(arg._xmit_lock);
        SCAN_FUNCTION(arg.xmit_lock_owner);
        SCAN_FUNCTION(arg.trans_start);
        SCAN_FUNCTION(arg.trans_timeout);
        SCAN_FUNCTION(arg.state);
        SCAN_RECURSIVE(arg.dql);
    }
})
#endif


//#define SCANNER_FOR_struct_xps_map
#ifndef SCANNER_FOR_struct_xps_map
#define SCANNER_FOR_struct_xps_map
TYPE_SCAN_WRAPPER(struct xps_map, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct xps_map);
    }
    SCAN {
        S(kern_printk( "struct xps_map\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.len);
        SCAN_FUNCTION(arg.alloc_len);
        SCAN_RECURSIVE(arg.rcu);
//  Array(Use(TypeDef(u16, Attributed(unsigned , BuiltIn(short))))) arg.queues
    }
})
#endif


//#define SCANNER_FOR_struct_xps_dev_maps
#ifndef SCANNER_FOR_struct_xps_dev_maps
#define SCANNER_FOR_struct_xps_dev_maps
TYPE_SCAN_WRAPPER(struct xps_dev_maps, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct xps_dev_maps);
    }
    SCAN {
        S(kern_printk( "struct xps_dev_maps\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.rcu);
//  Array(Pointer(Use(Struct(struct xps_map)))) arg.cpu_map
    }
})
#endif


#ifndef SCANNER_FOR_struct_dcbnl_rtnl_ops
#define SCANNER_FOR_struct_dcbnl_rtnl_ops
TYPE_SCAN_WRAPPER(struct dcbnl_rtnl_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dcbnl_rtnl_ops);
    }
    SCAN {
        S(kern_printk( "struct dcbnl_rtnl_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.ieee_getets);
        SCAN_FUNCTION(arg.ieee_setets);
        SCAN_FUNCTION(arg.ieee_getmaxrate);
        SCAN_FUNCTION(arg.ieee_setmaxrate);
        SCAN_FUNCTION(arg.ieee_getpfc);
        SCAN_FUNCTION(arg.ieee_setpfc);
        SCAN_FUNCTION(arg.ieee_getapp);
        SCAN_FUNCTION(arg.ieee_setapp);
        SCAN_FUNCTION(arg.ieee_delapp);
        SCAN_FUNCTION(arg.ieee_peer_getets);
        SCAN_FUNCTION(arg.ieee_peer_getpfc);
        SCAN_FUNCTION(arg.getstate);
        SCAN_FUNCTION(arg.setstate);
        SCAN_FUNCTION(arg.getpermhwaddr);
        SCAN_FUNCTION(arg.setpgtccfgtx);
        SCAN_FUNCTION(arg.setpgbwgcfgtx);
        SCAN_FUNCTION(arg.setpgtccfgrx);
        SCAN_FUNCTION(arg.setpgbwgcfgrx);
        SCAN_FUNCTION(arg.getpgtccfgtx);
        SCAN_FUNCTION(arg.getpgbwgcfgtx);
        SCAN_FUNCTION(arg.getpgtccfgrx);
        SCAN_FUNCTION(arg.getpgbwgcfgrx);
        SCAN_FUNCTION(arg.setpfccfg);
        SCAN_FUNCTION(arg.getpfccfg);
        SCAN_FUNCTION(arg.setall);
        SCAN_FUNCTION(arg.getcap);
        SCAN_FUNCTION(arg.getnumtcs);
        SCAN_FUNCTION(arg.setnumtcs);
        SCAN_FUNCTION(arg.getpfcstate);
        SCAN_FUNCTION(arg.setpfcstate);
        SCAN_FUNCTION(arg.getbcncfg);
        SCAN_FUNCTION(arg.setbcncfg);
        SCAN_FUNCTION(arg.getbcnrp);
        SCAN_FUNCTION(arg.setbcnrp);
        SCAN_FUNCTION(arg.setapp);
        SCAN_FUNCTION(arg.getapp);
        SCAN_FUNCTION(arg.getfeatcfg);
        SCAN_FUNCTION(arg.setfeatcfg);
        SCAN_FUNCTION(arg.getdcbx);
        SCAN_FUNCTION(arg.setdcbx);
        SCAN_FUNCTION(arg.peer_getappinfo);
        SCAN_FUNCTION(arg.peer_getapptable);
        SCAN_FUNCTION(arg.cee_peer_getpg);
        SCAN_FUNCTION(arg.cee_peer_getpfc);
    }
})
#endif


#ifndef SCANNER_FOR_struct_pm_qos_request
#define SCANNER_FOR_struct_pm_qos_request
TYPE_SCAN_WRAPPER(struct pm_qos_request, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pm_qos_request);
    }
    SCAN {
        S(kern_printk( "struct pm_qos_request\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.node);
        SCAN_FUNCTION(arg.pm_qos_class);
        SCAN_RECURSIVE(arg.work);
    }
})
#endif


//#define SCANNER_FOR_struct_net_device
#ifndef SCANNER_FOR_struct_net_device
#define SCANNER_FOR_struct_net_device
TYPE_SCAN_WRAPPER(struct net_device, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct net_device);
    }
    SCAN {
        S(kern_printk( "struct net_device\n");)
        S(SCAN_OBJECT(arg);)
//  Array(BuiltIn(char)) arg.name
        SCAN_RECURSIVE(arg.name_hlist);
        SCAN_FUNCTION(arg.ifalias);
        SCAN_FUNCTION(arg.mem_end);
        SCAN_FUNCTION(arg.mem_start);
        SCAN_FUNCTION(arg.base_addr);
        SCAN_FUNCTION(arg.irq);
        SCAN_FUNCTION(arg.state);
        SCAN_RECURSIVE(arg.dev_list);
        SCAN_RECURSIVE(arg.napi_list);
        SCAN_RECURSIVE(arg.unreg_list);
        SCAN_FUNCTION(arg.features);
        SCAN_FUNCTION(arg.hw_features);
        SCAN_FUNCTION(arg.wanted_features);
        SCAN_FUNCTION(arg.vlan_features);
        SCAN_FUNCTION(arg.hw_enc_features);
        SCAN_FUNCTION(arg.ifindex);
        SCAN_FUNCTION(arg.iflink);
        SCAN_RECURSIVE(arg.stats);
        SCAN_RECURSIVE(arg.rx_dropped);
        SCAN_RECURSIVE_PTR(arg.wireless_handlers);
        SCAN_RECURSIVE_PTR(arg.wireless_data);
        SCAN_RECURSIVE_PTR(arg.netdev_ops);
        SCAN_RECURSIVE_PTR(arg.ethtool_ops);
        SCAN_RECURSIVE_PTR(arg.header_ops);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.priv_flags);
        SCAN_FUNCTION(arg.gflags);
        SCAN_FUNCTION(arg.padded);
        SCAN_FUNCTION(arg.operstate);
        SCAN_FUNCTION(arg.link_mode);
        SCAN_FUNCTION(arg.if_port);
        SCAN_FUNCTION(arg.dma);
        SCAN_FUNCTION(arg.mtu);
        SCAN_FUNCTION(arg.type);
        SCAN_FUNCTION(arg.hard_header_len);
        SCAN_FUNCTION(arg.needed_headroom);
        SCAN_FUNCTION(arg.needed_tailroom);
//  Array(Attributed(unsigned , BuiltIn(char))) arg.perm_addr
        SCAN_FUNCTION(arg.addr_assign_type);
        SCAN_FUNCTION(arg.addr_len);
        SCAN_FUNCTION(arg.neigh_priv_len);
        SCAN_FUNCTION(arg.dev_id);
        SCAN_RECURSIVE(arg.addr_list_lock);
        SCAN_RECURSIVE(arg.uc);
        SCAN_RECURSIVE(arg.mc);
        SCAN_FUNCTION(arg.uc_promisc);
        SCAN_FUNCTION(arg.promiscuity);
        SCAN_FUNCTION(arg.allmulti);
        SCAN_RECURSIVE_PTR(arg.vlan_info);
        SCAN_RECURSIVE_PTR(arg.dsa_ptr);
        SCAN_FUNCTION(arg.atalk_ptr);
        SCAN_RECURSIVE_PTR(arg.ip_ptr);
        SCAN_RECURSIVE_PTR(arg.dn_ptr);
        SCAN_RECURSIVE_PTR(arg.ip6_ptr);
        SCAN_FUNCTION(arg.ax25_ptr);
        SCAN_RECURSIVE_PTR(arg.ieee80211_ptr);
        SCAN_FUNCTION(arg.last_rx);
        SCAN_RECURSIVE_PTR(arg.master);
        SCAN_FUNCTION(arg.dev_addr);
        SCAN_RECURSIVE(arg.dev_addrs);
//  Array(Attributed(unsigned , BuiltIn(char))) arg.broadcast
        SCAN_RECURSIVE_PTR(arg.queues_kset);
        SCAN_RECURSIVE_PTR(arg._rx);
        SCAN_FUNCTION(arg.num_rx_queues);
        SCAN_FUNCTION(arg.real_num_rx_queues);
        SCAN_RECURSIVE_PTR(arg.rx_cpu_rmap);
        SCAN_FUNCTION(arg.rx_handler);
        SCAN_FUNCTION(arg.rx_handler_data);
        SCAN_RECURSIVE_PTR(arg.ingress_queue);
        SCAN_RECURSIVE(arg._tx);
        SCAN_FUNCTION(arg.num_tx_queues);
        SCAN_FUNCTION(arg.real_num_tx_queues);
        SCAN_RECURSIVE_PTR(arg.qdisc);
        SCAN_FUNCTION(arg.tx_queue_len);
        SCAN_RECURSIVE(arg.tx_global_lock);
        SCAN_RECURSIVE_PTR(arg.xps_maps);
        SCAN_FUNCTION(arg.trans_start);
        SCAN_FUNCTION(arg.watchdog_timeo);
        SCAN_RECURSIVE(arg.watchdog_timer);
        SCAN_FUNCTION(arg.pcpu_refcnt);
        SCAN_RECURSIVE(arg.todo_list);
        SCAN_RECURSIVE(arg.index_hlist);
        SCAN_RECURSIVE(arg.link_watch_list);
//  Bitfield(Enum(enum anon_enum_418)) arg.reg_state
        SCAN_FUNCTION(arg.dismantle);
//  Bitfield(Enum(enum anon_enum_419)) arg.rtnl_link_state
        SCAN_FUNCTION(arg.destructor);
        SCAN_RECURSIVE_PTR(arg.npinfo);
        SCAN_RECURSIVE_PTR(arg.nd_net);
//  Union(union anon_union_126) None
        SCAN_RECURSIVE_PTR(arg.garp_port);
        SCAN_RECURSIVE(arg.dev);
//  Array(Pointer(Attributed(const , Use(Struct(struct attribute_group))))) arg.sysfs_groups
        SCAN_RECURSIVE_PTR(arg.rtnl_link_ops);
        SCAN_FUNCTION(arg.gso_max_size);
        SCAN_FUNCTION(arg.gso_max_segs);
        SCAN_RECURSIVE_PTR(arg.dcbnl_ops);
        SCAN_FUNCTION(arg.num_tc);
//  Array(Use(Struct(struct netdev_tc_txq))) arg.tc_to_txq
//  Array(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.prio_tc_map
        SCAN_FUNCTION(arg.fcoe_ddp_xid);
        SCAN_RECURSIVE_PTR(arg.phydev);
        SCAN_RECURSIVE_PTR(arg.qdisc_tx_busylock);
        SCAN_FUNCTION(arg.group);
        SCAN_RECURSIVE(arg.pm_qos_req);
    }
})
#endif


#ifndef SCANNER_FOR_struct_rtnl_link_ops
#define SCANNER_FOR_struct_rtnl_link_ops
TYPE_SCAN_WRAPPER(struct rtnl_link_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct rtnl_link_ops);
    }
    SCAN {
        S(kern_printk( "struct rtnl_link_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_FUNCTION(arg.kind);
        SCAN_FUNCTION(arg.priv_size);
        SCAN_FUNCTION(arg.setup);
        SCAN_FUNCTION(arg.maxtype);
        SCAN_RECURSIVE_PTR(arg.policy);
        SCAN_FUNCTION(arg.validate);
        SCAN_FUNCTION(arg.newlink);
        SCAN_FUNCTION(arg.changelink);
        SCAN_FUNCTION(arg.dellink);
        SCAN_FUNCTION(arg.get_size);
        SCAN_FUNCTION(arg.fill_info);
        SCAN_FUNCTION(arg.get_xstats_size);
        SCAN_FUNCTION(arg.fill_xstats);
        SCAN_FUNCTION(arg.get_num_tx_queues);
        SCAN_FUNCTION(arg.get_num_rx_queues);
    }
})
#endif


#ifndef SCANNER_FOR_struct_irq_data
#define SCANNER_FOR_struct_irq_data
TYPE_SCAN_WRAPPER(struct irq_data, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct irq_data);
    }
    SCAN {
        S(kern_printk( "struct irq_data\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.irq);
        SCAN_FUNCTION(arg.hwirq);
        SCAN_FUNCTION(arg.node);
        SCAN_FUNCTION(arg.state_use_accessors);
        SCAN_RECURSIVE_PTR(arg.chip);
        SCAN_RECURSIVE_PTR(arg.domain);
        SCAN_FUNCTION(arg.handler_data);
        SCAN_FUNCTION(arg.chip_data);
        SCAN_RECURSIVE_PTR(arg.msi_desc);
//  Array(Use(Struct(struct cpumask))) arg.affinity
    }
})
#endif


//#define SCANNER_FOR_struct_irq_chip
#ifndef SCANNER_FOR_struct_irq_chip
#define SCANNER_FOR_struct_irq_chip
TYPE_SCAN_WRAPPER(struct irq_chip, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct irq_chip);
    }
    SCAN {
        S(kern_printk( "struct irq_chip\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_FUNCTION(arg.irq_startup);
        SCAN_FUNCTION(arg.irq_shutdown);
        SCAN_FUNCTION(arg.irq_enable);
        SCAN_FUNCTION(arg.irq_disable);
        SCAN_FUNCTION(arg.irq_ack);
        SCAN_FUNCTION(arg.irq_mask);
        SCAN_FUNCTION(arg.irq_mask_ack);
        SCAN_FUNCTION(arg.irq_unmask);
        SCAN_FUNCTION(arg.irq_eoi);
        SCAN_FUNCTION(arg.irq_set_affinity);
        SCAN_FUNCTION(arg.irq_retrigger);
        SCAN_FUNCTION(arg.irq_set_type);
        SCAN_FUNCTION(arg.irq_set_wake);
        SCAN_FUNCTION(arg.irq_bus_lock);
        SCAN_FUNCTION(arg.irq_bus_sync_unlock);
        SCAN_FUNCTION(arg.irq_cpu_online);
        SCAN_FUNCTION(arg.irq_cpu_offline);
        SCAN_FUNCTION(arg.irq_suspend);
        SCAN_FUNCTION(arg.irq_resume);
        SCAN_FUNCTION(arg.irq_pm_shutdown);
        SCAN_FUNCTION(arg.irq_print_chip);
        SCAN_FUNCTION(arg.flags);
    }
})
#endif


//#define SCANNER_FOR_struct_scsi_host_template
#ifndef SCANNER_FOR_struct_scsi_host_template
#define SCANNER_FOR_struct_scsi_host_template
TYPE_SCAN_WRAPPER(struct scsi_host_template, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct scsi_host_template);
    }
    SCAN {
        S(kern_printk( "struct scsi_host_template\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.module);
        SCAN_FUNCTION(arg.name);
        SCAN_FUNCTION(arg.detect);
        SCAN_FUNCTION(arg.release);
        SCAN_FUNCTION(arg.info);
        SCAN_FUNCTION(arg.ioctl);
        SCAN_FUNCTION(arg.compat_ioctl);
        SCAN_FUNCTION(arg.queuecommand);
        SCAN_FUNCTION(arg.transfer_response);
        SCAN_FUNCTION(arg.eh_abort_handler);
        SCAN_FUNCTION(arg.eh_device_reset_handler);
        SCAN_FUNCTION(arg.eh_target_reset_handler);
        SCAN_FUNCTION(arg.eh_bus_reset_handler);
        SCAN_FUNCTION(arg.eh_host_reset_handler);
        SCAN_FUNCTION(arg.slave_alloc);
        SCAN_FUNCTION(arg.slave_configure);
        SCAN_FUNCTION(arg.slave_destroy);
        SCAN_FUNCTION(arg.target_alloc);
        SCAN_FUNCTION(arg.target_destroy);
        SCAN_FUNCTION(arg.scan_finished);
        SCAN_FUNCTION(arg.scan_start);
        SCAN_FUNCTION(arg.change_queue_depth);
        SCAN_FUNCTION(arg.change_queue_type);
        SCAN_FUNCTION(arg.bios_param);
        SCAN_FUNCTION(arg.unlock_native_capacity);
        SCAN_FUNCTION(arg.proc_info);
        SCAN_FUNCTION(arg.eh_timed_out);
        SCAN_FUNCTION(arg.host_reset);
        SCAN_FUNCTION(arg.proc_name);
        SCAN_RECURSIVE_PTR(arg.proc_dir);
        SCAN_FUNCTION(arg.can_queue);
        SCAN_FUNCTION(arg.this_id);
        SCAN_FUNCTION(arg.sg_tablesize);
        SCAN_FUNCTION(arg.sg_prot_tablesize);
        SCAN_FUNCTION(arg.max_sectors);
        SCAN_FUNCTION(arg.dma_boundary);
        SCAN_FUNCTION(arg.cmd_per_lun);
        SCAN_FUNCTION(arg.present);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.supported_mode
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.unchecked_isa_dma
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.use_clustering
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.emulated
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.skip_settle_delay
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.ordered_tag
        SCAN_FUNCTION(arg.max_host_blocked);
//  Pointer(Pointer(Use(Struct(struct device_attribute)))) arg.shost_attrs
//  Pointer(Pointer(Use(Struct(struct device_attribute)))) arg.sdev_attrs
        SCAN_RECURSIVE(arg.legacy_hosts);
        SCAN_FUNCTION(arg.vendor_id);
    }
})
#endif


//#define SCANNER_FOR_struct_Scsi_Host
#ifndef SCANNER_FOR_struct_Scsi_Host
#define SCANNER_FOR_struct_Scsi_Host
TYPE_SCAN_WRAPPER(struct Scsi_Host, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct Scsi_Host);
    }
    SCAN {
        S(kern_printk( "struct Scsi_Host\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.__devices);
        SCAN_RECURSIVE(arg.__targets);
        SCAN_RECURSIVE_PTR(arg.cmd_pool);
        SCAN_RECURSIVE(arg.free_list_lock);
        SCAN_RECURSIVE(arg.free_list);
        SCAN_RECURSIVE(arg.starved_list);
        SCAN_RECURSIVE(arg.default_lock);
        SCAN_RECURSIVE_PTR(arg.host_lock);
        SCAN_RECURSIVE(arg.scan_mutex);
        SCAN_RECURSIVE(arg.eh_cmd_q);
        SCAN_RECURSIVE_PTR(arg.ehandler);
        SCAN_RECURSIVE_PTR(arg.eh_action);
        SCAN_RECURSIVE(arg.host_wait);
        SCAN_RECURSIVE_PTR(arg.hostt);
        SCAN_RECURSIVE_PTR(arg.transportt);
        SCAN_RECURSIVE_PTR(arg.bqt);
        SCAN_FUNCTION(arg.host_busy);
        SCAN_FUNCTION(arg.host_failed);
        SCAN_FUNCTION(arg.host_eh_scheduled);
        SCAN_FUNCTION(arg.host_no);
        SCAN_FUNCTION(arg.resetting);
        SCAN_FUNCTION(arg.last_reset);
        SCAN_FUNCTION(arg.max_id);
        SCAN_FUNCTION(arg.max_lun);
        SCAN_FUNCTION(arg.max_channel);
        SCAN_FUNCTION(arg.unique_id);
        SCAN_FUNCTION(arg.max_cmd_len);
        SCAN_FUNCTION(arg.this_id);
        SCAN_FUNCTION(arg.can_queue);
        SCAN_FUNCTION(arg.cmd_per_lun);
        SCAN_FUNCTION(arg.sg_tablesize);
        SCAN_FUNCTION(arg.sg_prot_tablesize);
        SCAN_FUNCTION(arg.max_sectors);
        SCAN_FUNCTION(arg.dma_boundary);
        SCAN_FUNCTION(arg.cmd_serial_number);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.active_mode
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.unchecked_isa_dma
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.use_clustering
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.use_blk_tcq
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.host_self_blocked
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.reverse_ordering
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.ordered_tag
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.tmf_in_progress
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.async_scan
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.eh_noresume
//  Array(BuiltIn(char)) arg.work_q_name
        SCAN_RECURSIVE_PTR(arg.work_q);
        SCAN_FUNCTION(arg.host_blocked);
        SCAN_FUNCTION(arg.max_host_blocked);
        SCAN_FUNCTION(arg.prot_capabilities);
        SCAN_FUNCTION(arg.prot_guard_type);
        SCAN_RECURSIVE_PTR(arg.uspace_req_q);
        SCAN_FUNCTION(arg.base);
        SCAN_FUNCTION(arg.io_port);
        SCAN_FUNCTION(arg.n_io_port);
        SCAN_FUNCTION(arg.dma_channel);
        SCAN_FUNCTION(arg.irq);
//  Enum(enum scsi_host_state) arg.shost_state
        SCAN_RECURSIVE(arg.shost_gendev);
        SCAN_RECURSIVE(arg.shost_dev);
        SCAN_RECURSIVE(arg.sht_legacy_list);
        SCAN_FUNCTION(arg.shost_data);
        SCAN_RECURSIVE_PTR(arg.dma_dev);
//  Array(Attributed(unsigned , BuiltIn(long))) arg.hostdata
    }
})
#endif


//#define SCANNER_FOR_struct_ata_device
#ifndef SCANNER_FOR_struct_ata_device
#define SCANNER_FOR_struct_ata_device
TYPE_SCAN_WRAPPER(struct ata_device, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ata_device);
    }
    SCAN {
        S(kern_printk( "struct ata_device\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.link);
        SCAN_FUNCTION(arg.devno);
        SCAN_FUNCTION(arg.horkage);
        SCAN_FUNCTION(arg.flags);
        SCAN_RECURSIVE_PTR(arg.sdev);
        SCAN_FUNCTION(arg.private_data);
//  Pointer(Use(Union(union acpi_object))) arg.gtf_cache
        SCAN_FUNCTION(arg.gtf_filter);
        SCAN_RECURSIVE(arg.tdev);
        SCAN_FUNCTION(arg.n_sectors);
        SCAN_FUNCTION(arg.n_native_sectors);
        SCAN_FUNCTION(arg.class_);
        SCAN_FUNCTION(arg.unpark_deadline);
        SCAN_FUNCTION(arg.pio_mode);
        SCAN_FUNCTION(arg.dma_mode);
        SCAN_FUNCTION(arg.xfer_mode);
        SCAN_FUNCTION(arg.xfer_shift);
        SCAN_FUNCTION(arg.multi_count);
        SCAN_FUNCTION(arg.max_sectors);
        SCAN_FUNCTION(arg.cdb_len);
        SCAN_FUNCTION(arg.pio_mask);
        SCAN_FUNCTION(arg.mwdma_mask);
        SCAN_FUNCTION(arg.udma_mask);
        SCAN_FUNCTION(arg.cylinders);
        SCAN_FUNCTION(arg.heads);
        SCAN_FUNCTION(arg.sectors);
//  Union(union anon_union_127) None
//  Array(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.devslp_timing
        SCAN_FUNCTION(arg.spdn_cnt);
        SCAN_RECURSIVE(arg.ering);
    }
})
#endif


//#define SCANNER_FOR_struct_ata_eh_info
#ifndef SCANNER_FOR_struct_ata_eh_info
#define SCANNER_FOR_struct_ata_eh_info
TYPE_SCAN_WRAPPER(struct ata_eh_info, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ata_eh_info);
    }
    SCAN {
        S(kern_printk( "struct ata_eh_info\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.dev);
        SCAN_FUNCTION(arg.serror);
        SCAN_FUNCTION(arg.err_mask);
        SCAN_FUNCTION(arg.action);
//  Array(Attributed(unsigned , BuiltIn(int))) arg.dev_action
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.probe_mask);
//  Array(BuiltIn(char)) arg.desc
        SCAN_FUNCTION(arg.desc_len);
    }
})
#endif


//#define SCANNER_FOR_struct_ata_eh_context
#ifndef SCANNER_FOR_struct_ata_eh_context
#define SCANNER_FOR_struct_ata_eh_context
TYPE_SCAN_WRAPPER(struct ata_eh_context, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ata_eh_context);
    }
    SCAN {
        S(kern_printk( "struct ata_eh_context\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.i);
//  Array(BuiltIn(int)) arg.tries
//  Array(Array(BuiltIn(int))) arg.cmd_timeout_idx
//  Array(Attributed(unsigned , BuiltIn(int))) arg.classes
        SCAN_FUNCTION(arg.did_probe_mask);
        SCAN_FUNCTION(arg.unloaded_mask);
        SCAN_FUNCTION(arg.saved_ncq_enabled);
//  Array(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.saved_xfer_mode
        SCAN_FUNCTION(arg.last_reset);
    }
})
#endif


//#define SCANNER_FOR_struct_ata_link
#ifndef SCANNER_FOR_struct_ata_link
#define SCANNER_FOR_struct_ata_link
TYPE_SCAN_WRAPPER(struct ata_link, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ata_link);
    }
    SCAN {
        S(kern_printk( "struct ata_link\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.ap);
        SCAN_FUNCTION(arg.pmp);
        SCAN_RECURSIVE(arg.tdev);
        SCAN_FUNCTION(arg.active_tag);
        SCAN_FUNCTION(arg.sactive);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.saved_scontrol);
        SCAN_FUNCTION(arg.hw_sata_spd_limit);
        SCAN_FUNCTION(arg.sata_spd_limit);
        SCAN_FUNCTION(arg.sata_spd);
//  Enum(enum ata_lpm_policy) arg.lpm_policy
        SCAN_RECURSIVE(arg.eh_info);
        SCAN_RECURSIVE(arg.eh_context);
//  Array(Use(Struct(struct ata_device))) arg.device
    }
})
#endif


//#define SCANNER_FOR_struct_ata_port
#ifndef SCANNER_FOR_struct_ata_port
#define SCANNER_FOR_struct_ata_port
TYPE_SCAN_WRAPPER(struct ata_port, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ata_port);
    }
    SCAN {
        S(kern_printk( "struct ata_port\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.scsi_host);
        SCAN_RECURSIVE_PTR(arg.ops);
        SCAN_RECURSIVE_PTR(arg.lock);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.pflags);
        SCAN_FUNCTION(arg.print_id);
        SCAN_FUNCTION(arg.port_no);
        SCAN_RECURSIVE(arg.ioaddr);
        SCAN_FUNCTION(arg.ctl);
        SCAN_FUNCTION(arg.last_ctl);
        SCAN_RECURSIVE_PTR(arg.sff_pio_task_link);
        SCAN_RECURSIVE(arg.sff_pio_task);
        SCAN_RECURSIVE_PTR(arg.bmdma_prd);
        SCAN_FUNCTION(arg.bmdma_prd_dma);
        SCAN_FUNCTION(arg.pio_mask);
        SCAN_FUNCTION(arg.mwdma_mask);
        SCAN_FUNCTION(arg.udma_mask);
        SCAN_FUNCTION(arg.cbl);
//  Array(Use(Struct(struct ata_queued_cmd))) arg.qcmd
        SCAN_FUNCTION(arg.qc_allocated);
        SCAN_FUNCTION(arg.qc_active);
        SCAN_FUNCTION(arg.nr_active_links);
        SCAN_RECURSIVE(arg.link);
        SCAN_RECURSIVE_PTR(arg.slave_link);
        SCAN_FUNCTION(arg.nr_pmp_links);
        SCAN_RECURSIVE_PTR(arg.pmp_link);
        SCAN_RECURSIVE_PTR(arg.excl_link);
        SCAN_RECURSIVE(arg.stats);
        SCAN_RECURSIVE_PTR(arg.host);
        SCAN_RECURSIVE_PTR(arg.dev);
        SCAN_RECURSIVE(arg.tdev);
        SCAN_RECURSIVE(arg.scsi_scan_mutex);
        SCAN_RECURSIVE(arg.hotplug_task);
        SCAN_RECURSIVE(arg.scsi_rescan_task);
        SCAN_FUNCTION(arg.hsm_task_state);
        SCAN_FUNCTION(arg.msg_enable);
        SCAN_RECURSIVE(arg.eh_done_q);
        SCAN_RECURSIVE(arg.eh_wait_q);
        SCAN_FUNCTION(arg.eh_tries);
        SCAN_RECURSIVE(arg.park_req_pending);
        SCAN_RECURSIVE(arg.pm_mesg);
        SCAN_FUNCTION(arg.pm_result);
//  Enum(enum ata_lpm_policy) arg.target_lpm_policy
        SCAN_RECURSIVE(arg.fastdrain_timer);
        SCAN_FUNCTION(arg.fastdrain_cnt);
        SCAN_FUNCTION(arg.em_message_type);
        SCAN_FUNCTION(arg.private_data);
        SCAN_RECURSIVE(arg.__acpi_init_gtm);
//  Array(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.sector_buf
    }
})
#endif


//#define SCANNER_FOR_struct_ata_queued_cmd
#ifndef SCANNER_FOR_struct_ata_queued_cmd
#define SCANNER_FOR_struct_ata_queued_cmd
TYPE_SCAN_WRAPPER(struct ata_queued_cmd, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ata_queued_cmd);
    }
    SCAN {
        S(kern_printk( "struct ata_queued_cmd\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.ap);
        SCAN_RECURSIVE_PTR(arg.dev);
        SCAN_RECURSIVE_PTR(arg.scsicmd);
        SCAN_FUNCTION(arg.scsidone);
        SCAN_RECURSIVE(arg.tf);
//  Array(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.cdb
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.tag);
        SCAN_FUNCTION(arg.n_elem);
        SCAN_FUNCTION(arg.orig_n_elem);
        SCAN_FUNCTION(arg.dma_dir);
        SCAN_FUNCTION(arg.sect_size);
        SCAN_FUNCTION(arg.nbytes);
        SCAN_FUNCTION(arg.extrabytes);
        SCAN_FUNCTION(arg.curbytes);
        SCAN_RECURSIVE(arg.sgent);
        SCAN_RECURSIVE_PTR(arg.sg);
        SCAN_RECURSIVE_PTR(arg.cursg);
        SCAN_FUNCTION(arg.cursg_ofs);
        SCAN_FUNCTION(arg.err_mask);
        SCAN_RECURSIVE(arg.result_tf);
        SCAN_FUNCTION(arg.complete_fn);
        SCAN_FUNCTION(arg.private_data);
        SCAN_FUNCTION(arg.lldd_task);
    }
})
#endif


//#define SCANNER_FOR_struct_ata_port_operations
#ifndef SCANNER_FOR_struct_ata_port_operations
#define SCANNER_FOR_struct_ata_port_operations
TYPE_SCAN_WRAPPER(struct ata_port_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ata_port_operations);
    }
    SCAN {
        S(kern_printk( "struct ata_port_operations\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.qc_defer);
        SCAN_FUNCTION(arg.check_atapi_dma);
        SCAN_FUNCTION(arg.qc_prep);
        SCAN_FUNCTION(arg.qc_issue);
        SCAN_FUNCTION(arg.qc_fill_rtf);
        SCAN_FUNCTION(arg.cable_detect);
        SCAN_FUNCTION(arg.mode_filter);
        SCAN_FUNCTION(arg.set_piomode);
        SCAN_FUNCTION(arg.set_dmamode);
        SCAN_FUNCTION(arg.set_mode);
        SCAN_FUNCTION(arg.read_id);
        SCAN_FUNCTION(arg.dev_config);
        SCAN_FUNCTION(arg.freeze);
        SCAN_FUNCTION(arg.thaw);
        SCAN_FUNCTION(arg.prereset);
        SCAN_FUNCTION(arg.softreset);
        SCAN_FUNCTION(arg.hardreset);
        SCAN_FUNCTION(arg.postreset);
        SCAN_FUNCTION(arg.pmp_prereset);
        SCAN_FUNCTION(arg.pmp_softreset);
        SCAN_FUNCTION(arg.pmp_hardreset);
        SCAN_FUNCTION(arg.pmp_postreset);
        SCAN_FUNCTION(arg.error_handler);
        SCAN_FUNCTION(arg.lost_interrupt);
        SCAN_FUNCTION(arg.post_internal_cmd);
        SCAN_FUNCTION(arg.sched_eh);
        SCAN_FUNCTION(arg.end_eh);
        SCAN_FUNCTION(arg.scr_read);
        SCAN_FUNCTION(arg.scr_write);
        SCAN_FUNCTION(arg.pmp_attach);
        SCAN_FUNCTION(arg.pmp_detach);
        SCAN_FUNCTION(arg.set_lpm);
        SCAN_FUNCTION(arg.port_suspend);
        SCAN_FUNCTION(arg.port_resume);
        SCAN_FUNCTION(arg.port_start);
        SCAN_FUNCTION(arg.port_stop);
        SCAN_FUNCTION(arg.host_stop);
        SCAN_FUNCTION(arg.sff_dev_select);
        SCAN_FUNCTION(arg.sff_set_devctl);
        SCAN_FUNCTION(arg.sff_check_status);
        SCAN_FUNCTION(arg.sff_check_altstatus);
        SCAN_FUNCTION(arg.sff_tf_load);
        SCAN_FUNCTION(arg.sff_tf_read);
        SCAN_FUNCTION(arg.sff_exec_command);
        SCAN_FUNCTION(arg.sff_data_xfer);
        SCAN_FUNCTION(arg.sff_irq_on);
        SCAN_FUNCTION(arg.sff_irq_check);
        SCAN_FUNCTION(arg.sff_irq_clear);
        SCAN_FUNCTION(arg.sff_drain_fifo);
        SCAN_FUNCTION(arg.bmdma_setup);
        SCAN_FUNCTION(arg.bmdma_start);
        SCAN_FUNCTION(arg.bmdma_stop);
        SCAN_FUNCTION(arg.bmdma_status);
        SCAN_FUNCTION(arg.em_show);
        SCAN_FUNCTION(arg.em_store);
        SCAN_FUNCTION(arg.sw_activity_show);
        SCAN_FUNCTION(arg.sw_activity_store);
        SCAN_FUNCTION(arg.phy_reset);
        SCAN_FUNCTION(arg.eng_timeout);
        SCAN_RECURSIVE_PTR(arg.inherits);
    }
})
#endif


//#define SCANNER_FOR_struct_ata_host
#ifndef SCANNER_FOR_struct_ata_host
#define SCANNER_FOR_struct_ata_host
TYPE_SCAN_WRAPPER(struct ata_host, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ata_host);
    }
    SCAN {
        S(kern_printk( "struct ata_host\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE_PTR(arg.dev);
//  Pointer(Pointer(const BuiltIn(void))) arg.iomap
        SCAN_FUNCTION(arg.n_ports);
        SCAN_FUNCTION(arg.private_data);
        SCAN_RECURSIVE_PTR(arg.ops);
        SCAN_FUNCTION(arg.flags);
        SCAN_RECURSIVE(arg.eh_mutex);
        SCAN_RECURSIVE_PTR(arg.eh_owner);
        SCAN_RECURSIVE_PTR(arg.simplex_claimed);
//  Array(Pointer(Use(Struct(struct ata_port)))) arg.ports
    }
})
#endif


//#define SCANNER_FOR_struct_irqaction
#ifndef SCANNER_FOR_struct_irqaction
#define SCANNER_FOR_struct_irqaction
TYPE_SCAN_WRAPPER(struct irqaction, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct irqaction);
    }
    SCAN {
        S(kern_printk( "struct irqaction\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.handler);
        SCAN_FUNCTION(arg.dev_id);
        SCAN_FUNCTION(arg.percpu_dev_id);
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_FUNCTION(arg.thread_fn);
        SCAN_RECURSIVE_PTR(arg.thread);
        SCAN_FUNCTION(arg.irq);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.thread_flags);
        SCAN_FUNCTION(arg.thread_mask);
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE_PTR(arg.dir);
    }
})
#endif


//#define SCANNER_FOR_struct_irq_affinity_notify
#ifndef SCANNER_FOR_struct_irq_affinity_notify
#define SCANNER_FOR_struct_irq_affinity_notify
TYPE_SCAN_WRAPPER(struct irq_affinity_notify, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct irq_affinity_notify);
    }
    SCAN {
        S(kern_printk( "struct irq_affinity_notify\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.irq);
        SCAN_RECURSIVE(arg.kref);
        SCAN_RECURSIVE(arg.work);
        SCAN_FUNCTION(arg.notify);
        SCAN_FUNCTION(arg.release);
    }
})
#endif


//#define SCANNER_FOR_struct_irq_desc
#ifndef SCANNER_FOR_struct_irq_desc
#define SCANNER_FOR_struct_irq_desc
TYPE_SCAN_WRAPPER(struct irq_desc, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct irq_desc);
    }
    SCAN {
        S(kern_printk( "struct irq_desc\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.irq_data);
        SCAN_FUNCTION(arg.kstat_irqs);
        SCAN_FUNCTION(arg.handle_irq);
        SCAN_RECURSIVE_PTR(arg.action);
        SCAN_FUNCTION(arg.status_use_accessors);
        SCAN_FUNCTION(arg.core_internal_state__do_not_mess_with_it);
        SCAN_FUNCTION(arg.depth);
        SCAN_FUNCTION(arg.wake_depth);
        SCAN_FUNCTION(arg.irq_count);
        SCAN_FUNCTION(arg.last_unhandled);
        SCAN_FUNCTION(arg.irqs_unhandled);
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE_PTR(arg.percpu_enabled);
        SCAN_RECURSIVE_PTR(arg.affinity_hint);
        SCAN_RECURSIVE_PTR(arg.affinity_notify);
//  Array(Use(Struct(struct cpumask))) arg.pending_mask
        SCAN_FUNCTION(arg.threads_oneshot);
        SCAN_RECURSIVE(arg.threads_active);
        SCAN_RECURSIVE(arg.wait_for_threads);
        SCAN_RECURSIVE_PTR(arg.dir);
        SCAN_FUNCTION(arg.parent_irq);
        SCAN_RECURSIVE_PTR(arg.owner);
        SCAN_FUNCTION(arg.name);
    }
})
#endif


#ifndef SCANNER_FOR_struct_irq_chip_type
#define SCANNER_FOR_struct_irq_chip_type
TYPE_SCAN_WRAPPER(struct irq_chip_type, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct irq_chip_type);
    }
    SCAN {
        S(kern_printk( "struct irq_chip_type\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.chip);
        SCAN_RECURSIVE(arg.regs);
        SCAN_FUNCTION(arg.handler);
        SCAN_FUNCTION(arg.type);
    }
})
#endif


#ifndef SCANNER_FOR_struct_nfq_ct_hook
#define SCANNER_FOR_struct_nfq_ct_hook
TYPE_SCAN_WRAPPER(struct nfq_ct_hook, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct nfq_ct_hook);
    }
    SCAN {
        S(kern_printk( "struct nfq_ct_hook\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.build_size);
        SCAN_FUNCTION(arg.build);
        SCAN_FUNCTION(arg.parse);
    }
})
#endif


//#define SCANNER_FOR_struct_pv_lazy_ops
#ifndef SCANNER_FOR_struct_pv_lazy_ops
#define SCANNER_FOR_struct_pv_lazy_ops
TYPE_SCAN_WRAPPER(struct pv_lazy_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pv_lazy_ops);
    }
    SCAN {
        S(kern_printk( "struct pv_lazy_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.enter);
        SCAN_FUNCTION(arg.leave);
    }
})
#endif


#ifndef SCANNER_FOR_struct_ipv6_pinfo
#define SCANNER_FOR_struct_ipv6_pinfo
TYPE_SCAN_WRAPPER(struct ipv6_pinfo, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ipv6_pinfo);
    }
    SCAN {
        S(kern_printk( "struct ipv6_pinfo\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.saddr);
        SCAN_RECURSIVE(arg.rcv_saddr);
        SCAN_RECURSIVE(arg.daddr);
        SCAN_RECURSIVE(arg.sticky_pktinfo);
        SCAN_RECURSIVE_PTR(arg.daddr_cache);
        SCAN_RECURSIVE_PTR(arg.saddr_cache);
        SCAN_FUNCTION(arg.flow_label);
        SCAN_FUNCTION(arg.frag_size);
//  Bitfield(Use(TypeDef(__u16, Attributed(unsigned , BuiltIn(short))))) arg.__unused_1
//  Bitfield(Use(TypeDef(__s16, Attributed(signed , BuiltIn(short))))) arg.hop_limit
//  Bitfield(Use(TypeDef(__u16, Attributed(unsigned , BuiltIn(short))))) arg.mc_loop
//  Bitfield(Use(TypeDef(__u16, Attributed(unsigned , BuiltIn(short))))) arg.__unused_2
//  Bitfield(Use(TypeDef(__s16, Attributed(signed , BuiltIn(short))))) arg.mcast_hops
        SCAN_FUNCTION(arg.ucast_oif);
        SCAN_FUNCTION(arg.mcast_oif);
//  Union(union anon_union_102) arg.rxopt
//  Bitfield(Use(TypeDef(__u16, Attributed(unsigned , BuiltIn(short))))) arg.recverr
//  Bitfield(Use(TypeDef(__u16, Attributed(unsigned , BuiltIn(short))))) arg.sndflow
//  Bitfield(Use(TypeDef(__u16, Attributed(unsigned , BuiltIn(short))))) arg.pmtudisc
//  Bitfield(Use(TypeDef(__u16, Attributed(unsigned , BuiltIn(short))))) arg.ipv6only
//  Bitfield(Use(TypeDef(__u16, Attributed(unsigned , BuiltIn(short))))) arg.srcprefs
//  Bitfield(Use(TypeDef(__u16, Attributed(unsigned , BuiltIn(short))))) arg.dontfrag
        SCAN_FUNCTION(arg.min_hopcount);
        SCAN_FUNCTION(arg.tclass);
        SCAN_FUNCTION(arg.rcv_tclass);
        SCAN_FUNCTION(arg.dst_cookie);
        SCAN_FUNCTION(arg.rx_dst_cookie);
        SCAN_RECURSIVE_PTR(arg.ipv6_mc_list);
        SCAN_RECURSIVE_PTR(arg.ipv6_ac_list);
        SCAN_RECURSIVE_PTR(arg.ipv6_fl_list);
        SCAN_RECURSIVE_PTR(arg.opt);
        SCAN_RECURSIVE_PTR(arg.pktoptions);
        SCAN_RECURSIVE_PTR(arg.rxpmtu);
        SCAN_RECURSIVE(arg.cork);
    }
})
#endif


#ifndef SCANNER_FOR_struct_ip_options_rcu
#define SCANNER_FOR_struct_ip_options_rcu
TYPE_SCAN_WRAPPER(struct ip_options_rcu, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ip_options_rcu);
    }
    SCAN {
        S(kern_printk( "struct ip_options_rcu\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.rcu);
        SCAN_RECURSIVE(arg.opt);
    }
})
#endif


//#define SCANNER_FOR_struct_inet_cork
#ifndef SCANNER_FOR_struct_inet_cork
#define SCANNER_FOR_struct_inet_cork
TYPE_SCAN_WRAPPER(struct inet_cork, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct inet_cork);
    }
    SCAN {
        S(kern_printk( "struct inet_cork\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.addr);
        SCAN_RECURSIVE_PTR(arg.opt);
        SCAN_FUNCTION(arg.fragsize);
        SCAN_FUNCTION(arg.length);
        SCAN_RECURSIVE_PTR(arg.dst);
        SCAN_FUNCTION(arg.tx_flags);
    }
})
#endif


#ifndef SCANNER_FOR_struct_inet_cork_full
#define SCANNER_FOR_struct_inet_cork_full
TYPE_SCAN_WRAPPER(struct inet_cork_full, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct inet_cork_full);
    }
    SCAN {
        S(kern_printk( "struct inet_cork_full\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.base);
        SCAN_RECURSIVE(arg.fl);
    }
})
#endif


#ifndef SCANNER_FOR_struct_inet_sock
#define SCANNER_FOR_struct_inet_sock
TYPE_SCAN_WRAPPER(struct inet_sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct inet_sock);
    }
    SCAN {
        S(kern_printk( "struct inet_sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.sk);
        SCAN_RECURSIVE_PTR(arg.pinet6);
        SCAN_FUNCTION(arg.inet_saddr);
        SCAN_FUNCTION(arg.uc_ttl);
        SCAN_FUNCTION(arg.cmsg_flags);
        SCAN_FUNCTION(arg.inet_sport);
        SCAN_FUNCTION(arg.inet_id);
        SCAN_RECURSIVE_PTR(arg.inet_opt);
        SCAN_FUNCTION(arg.rx_dst_ifindex);
        SCAN_FUNCTION(arg.tos);
        SCAN_FUNCTION(arg.min_ttl);
        SCAN_FUNCTION(arg.mc_ttl);
        SCAN_FUNCTION(arg.pmtudisc);
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.recverr
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.is_icsk
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.freebind
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.hdrincl
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.mc_loop
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.transparent
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.mc_all
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.nodefrag
        SCAN_FUNCTION(arg.rcv_tos);
        SCAN_FUNCTION(arg.uc_index);
        SCAN_FUNCTION(arg.mc_index);
        SCAN_FUNCTION(arg.mc_addr);
        SCAN_RECURSIVE_PTR(arg.mc_list);
        SCAN_RECURSIVE(arg.cork);
    }
})
#endif


#ifndef SCANNER_FOR_struct_udp_sock
#define SCANNER_FOR_struct_udp_sock
TYPE_SCAN_WRAPPER(struct udp_sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct udp_sock);
    }
    SCAN {
        S(kern_printk( "struct udp_sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.inet);
        SCAN_FUNCTION(arg.pending);
        SCAN_FUNCTION(arg.corkflag);
        SCAN_FUNCTION(arg.encap_type);
        SCAN_FUNCTION(arg.len);
        SCAN_FUNCTION(arg.pcslen);
        SCAN_FUNCTION(arg.pcrlen);
        SCAN_FUNCTION(arg.pcflag);
//  Array(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.unused
        SCAN_FUNCTION(arg.encap_rcv);
    }
})
#endif


#ifndef SCANNER_FOR_struct_udp6_sock
#define SCANNER_FOR_struct_udp6_sock
TYPE_SCAN_WRAPPER(struct udp6_sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct udp6_sock);
    }
    SCAN {
        S(kern_printk( "struct udp6_sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.udp);
        SCAN_RECURSIVE(arg.inet6);
    }
})
#endif


#ifndef SCANNER_FOR_struct_crypto_ablkcipher
#define SCANNER_FOR_struct_crypto_ablkcipher
TYPE_SCAN_WRAPPER(struct crypto_ablkcipher, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct crypto_ablkcipher);
    }
    SCAN {
        S(kern_printk( "struct crypto_ablkcipher\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.base);
    }
})
#endif


#ifndef SCANNER_FOR_struct_crypto_async_request
#define SCANNER_FOR_struct_crypto_async_request
TYPE_SCAN_WRAPPER(struct crypto_async_request, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct crypto_async_request);
    }
    SCAN {
        S(kern_printk( "struct crypto_async_request\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_FUNCTION(arg.complete);
        SCAN_FUNCTION(arg.data);
        SCAN_RECURSIVE_PTR(arg.tfm);
        SCAN_FUNCTION(arg.flags);
    }
})
#endif


#define SCANNER_FOR_struct_ablkcipher_request
#ifndef SCANNER_FOR_struct_ablkcipher_request
#define SCANNER_FOR_struct_ablkcipher_request
TYPE_SCAN_WRAPPER(struct ablkcipher_request, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ablkcipher_request);
    }
    SCAN {
        S(kern_printk( "struct ablkcipher_request\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.base);
        SCAN_FUNCTION(arg.nbytes);
        SCAN_FUNCTION(arg.info);
        SCAN_RECURSIVE_PTR(arg.src);
        SCAN_RECURSIVE_PTR(arg.dst);
//  Array(Pointer(BuiltIn(void))) arg.__ctx
    }
})
#endif


#define SCANNER_FOR_struct_ablkcipher_tfm
#ifndef SCANNER_FOR_struct_ablkcipher_tfm
#define SCANNER_FOR_struct_ablkcipher_tfm
TYPE_SCAN_WRAPPER(struct ablkcipher_tfm, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ablkcipher_tfm);
    }
    SCAN {
        S(kern_printk( "struct ablkcipher_tfm\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.setkey);
        SCAN_FUNCTION(arg.encrypt);
        SCAN_FUNCTION(arg.decrypt);
        SCAN_FUNCTION(arg.givencrypt);
        SCAN_FUNCTION(arg.givdecrypt);
        SCAN_RECURSIVE_PTR(arg.base);
        SCAN_FUNCTION(arg.ivsize);
        SCAN_FUNCTION(arg.reqsize);
    }
})
#endif


#define SCANNER_FOR_struct_crypto_aead
#ifndef SCANNER_FOR_struct_crypto_aead
#define SCANNER_FOR_struct_crypto_aead
TYPE_SCAN_WRAPPER(struct crypto_aead, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct crypto_aead);
    }
    SCAN {
        S(kern_printk( "struct crypto_aead\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.base);
    }
})
#endif


#define SCANNER_FOR_struct_aead_request
#ifndef SCANNER_FOR_struct_aead_request
#define SCANNER_FOR_struct_aead_request
TYPE_SCAN_WRAPPER(struct aead_request, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct aead_request);
    }
    SCAN {
        S(kern_printk( "struct aead_request\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.base);
        SCAN_FUNCTION(arg.assoclen);
        SCAN_FUNCTION(arg.cryptlen);
        SCAN_FUNCTION(arg.iv);
        SCAN_RECURSIVE_PTR(arg.assoc);
        SCAN_RECURSIVE_PTR(arg.src);
        SCAN_RECURSIVE_PTR(arg.dst);
//  Array(Pointer(BuiltIn(void))) arg.__ctx
    }
})
#endif


#ifndef SCANNER_FOR_struct_aead_tfm
#define SCANNER_FOR_struct_aead_tfm
TYPE_SCAN_WRAPPER(struct aead_tfm, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct aead_tfm);
    }
    SCAN {
        S(kern_printk( "struct aead_tfm\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.setkey);
        SCAN_FUNCTION(arg.encrypt);
        SCAN_FUNCTION(arg.decrypt);
        SCAN_FUNCTION(arg.givencrypt);
        SCAN_FUNCTION(arg.givdecrypt);
        SCAN_RECURSIVE_PTR(arg.base);
        SCAN_FUNCTION(arg.ivsize);
        SCAN_FUNCTION(arg.authsize);
        SCAN_FUNCTION(arg.reqsize);
    }
})
#endif


#ifndef SCANNER_FOR_struct_crypto_blkcipher
#define SCANNER_FOR_struct_crypto_blkcipher
TYPE_SCAN_WRAPPER(struct crypto_blkcipher, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct crypto_blkcipher);
    }
    SCAN {
        S(kern_printk( "struct crypto_blkcipher\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.base);
    }
})
#endif



#ifndef SCANNER_FOR_struct_blkcipher_desc
#define SCANNER_FOR_struct_blkcipher_desc
TYPE_SCAN_WRAPPER(struct blkcipher_desc, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct blkcipher_desc);
    }
    SCAN {
        S(kern_printk( "struct blkcipher_desc\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.tfm);
        SCAN_FUNCTION(arg.info);
        SCAN_FUNCTION(arg.flags);
    }
})
#endif



#ifndef SCANNER_FOR_struct_blkcipher_tfm
#define SCANNER_FOR_struct_blkcipher_tfm
TYPE_SCAN_WRAPPER(struct blkcipher_tfm, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct blkcipher_tfm);
    }
    SCAN {
        S(kern_printk( "struct blkcipher_tfm\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.iv);
        SCAN_FUNCTION(arg.setkey);
        SCAN_FUNCTION(arg.encrypt);
        SCAN_FUNCTION(arg.decrypt);
    }
})
#endif



#ifndef SCANNER_FOR_struct_cipher_tfm
#define SCANNER_FOR_struct_cipher_tfm
TYPE_SCAN_WRAPPER(struct cipher_tfm, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cipher_tfm);
    }
    SCAN {
        S(kern_printk( "struct cipher_tfm\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.cit_setkey);
        SCAN_FUNCTION(arg.cit_encrypt_one);
        SCAN_FUNCTION(arg.cit_decrypt_one);
    }
})
#endif



#ifndef SCANNER_FOR_struct_crypto_hash
#define SCANNER_FOR_struct_crypto_hash
TYPE_SCAN_WRAPPER(struct crypto_hash, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct crypto_hash);
    }
    SCAN {
        S(kern_printk( "struct crypto_hash\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.base);
    }
})
#endif



#ifndef SCANNER_FOR_struct_hash_desc
#define SCANNER_FOR_struct_hash_desc
TYPE_SCAN_WRAPPER(struct hash_desc, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct hash_desc);
    }
    SCAN {
        S(kern_printk( "struct hash_desc\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.tfm);
        SCAN_FUNCTION(arg.flags);
    }
})
#endif



#ifndef SCANNER_FOR_struct_hash_tfm
#define SCANNER_FOR_struct_hash_tfm
TYPE_SCAN_WRAPPER(struct hash_tfm, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct hash_tfm);
    }
    SCAN {
        S(kern_printk( "struct hash_tfm\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.init);
        SCAN_FUNCTION(arg.update);
        SCAN_FUNCTION(arg.final);
        SCAN_FUNCTION(arg.digest);
        SCAN_FUNCTION(arg.setkey);
        SCAN_FUNCTION(arg.digestsize);
    }
})
#endif


#ifndef SCANNER_FOR_struct_compress_tfm
#define SCANNER_FOR_struct_compress_tfm
TYPE_SCAN_WRAPPER(struct compress_tfm, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct compress_tfm);
    }
    SCAN {
        S(kern_printk( "struct compress_tfm\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.cot_compress);
        SCAN_FUNCTION(arg.cot_decompress);
    }
})
#endif



#ifndef SCANNER_FOR_struct_crypto_rng
#define SCANNER_FOR_struct_crypto_rng
TYPE_SCAN_WRAPPER(struct crypto_rng, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct crypto_rng);
    }
    SCAN {
        S(kern_printk( "struct crypto_rng\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.base);
    }
})
#endif


#define SCANNER_FOR_struct_rng_tfm
#ifndef SCANNER_FOR_struct_rng_tfm
#define SCANNER_FOR_struct_rng_tfm
TYPE_SCAN_WRAPPER(struct rng_tfm, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct rng_tfm);
    }
    SCAN {
        S(kern_printk( "struct rng_tfm\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.rng_gen_random);
        SCAN_FUNCTION(arg.rng_reset);
    }
})
#endif


#define SCANNER_FOR_struct_ablkcipher_alg
#ifndef SCANNER_FOR_struct_ablkcipher_alg
#define SCANNER_FOR_struct_ablkcipher_alg
TYPE_SCAN_WRAPPER(struct ablkcipher_alg, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ablkcipher_alg);
    }
    SCAN {
        S(kern_printk( "struct ablkcipher_alg\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.setkey);
        SCAN_FUNCTION(arg.encrypt);
        SCAN_FUNCTION(arg.decrypt);
        SCAN_FUNCTION(arg.givencrypt);
        SCAN_FUNCTION(arg.givdecrypt);
        SCAN_FUNCTION(arg.geniv);
        SCAN_FUNCTION(arg.min_keysize);
        SCAN_FUNCTION(arg.max_keysize);
        SCAN_FUNCTION(arg.ivsize);
    }
})
#endif


#define SCANNER_FOR_struct_aead_alg
#ifndef SCANNER_FOR_struct_aead_alg
#define SCANNER_FOR_struct_aead_alg
TYPE_SCAN_WRAPPER(struct aead_alg, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct aead_alg);
    }
    SCAN {
        S(kern_printk( "struct aead_alg\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.setkey);
        SCAN_FUNCTION(arg.setauthsize);
        SCAN_FUNCTION(arg.encrypt);
        SCAN_FUNCTION(arg.decrypt);
        SCAN_FUNCTION(arg.givencrypt);
        SCAN_FUNCTION(arg.givdecrypt);
        SCAN_FUNCTION(arg.geniv);
        SCAN_FUNCTION(arg.ivsize);
        SCAN_FUNCTION(arg.maxauthsize);
    }
})
#endif


#define SCANNER_FOR_struct_blkcipher_alg
#ifndef SCANNER_FOR_struct_blkcipher_alg
#define SCANNER_FOR_struct_blkcipher_alg
TYPE_SCAN_WRAPPER(struct blkcipher_alg, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct blkcipher_alg);
    }
    SCAN {
        S(kern_printk( "struct blkcipher_alg\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.setkey);
        SCAN_FUNCTION(arg.encrypt);
        SCAN_FUNCTION(arg.decrypt);
        SCAN_FUNCTION(arg.geniv);
        SCAN_FUNCTION(arg.min_keysize);
        SCAN_FUNCTION(arg.max_keysize);
        SCAN_FUNCTION(arg.ivsize);
    }
})
#endif


#define SCANNER_FOR_struct_cipher_alg
#ifndef SCANNER_FOR_struct_cipher_alg
#define SCANNER_FOR_struct_cipher_alg
TYPE_SCAN_WRAPPER(struct cipher_alg, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cipher_alg);
    }
    SCAN {
        S(kern_printk( "struct cipher_alg\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.cia_min_keysize);
        SCAN_FUNCTION(arg.cia_max_keysize);
        SCAN_FUNCTION(arg.cia_setkey);
        SCAN_FUNCTION(arg.cia_encrypt);
        SCAN_FUNCTION(arg.cia_decrypt);
    }
})
#endif


#define SCANNER_FOR_struct_rng_alg
#ifndef SCANNER_FOR_struct_rng_alg
#define SCANNER_FOR_struct_rng_alg
TYPE_SCAN_WRAPPER(struct rng_alg, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct rng_alg);
    }
    SCAN {
        S(kern_printk( "struct rng_alg\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.rng_make_random);
        SCAN_FUNCTION(arg.rng_reset);
        SCAN_FUNCTION(arg.seedsize);
    }
})
#endif


#define SCANNER_FOR_struct_crypto_alg
#ifndef SCANNER_FOR_struct_crypto_alg
#define SCANNER_FOR_struct_crypto_alg
TYPE_SCAN_WRAPPER(struct crypto_alg, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct crypto_alg);
    }
    SCAN {
        S(kern_printk( "struct crypto_alg\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.cra_list);
        SCAN_RECURSIVE(arg.cra_users);
        SCAN_FUNCTION(arg.cra_flags);
        SCAN_FUNCTION(arg.cra_blocksize);
        SCAN_FUNCTION(arg.cra_ctxsize);
        SCAN_FUNCTION(arg.cra_alignmask);
        SCAN_FUNCTION(arg.cra_priority);
        SCAN_RECURSIVE(arg.cra_refcnt);
//  Array(BuiltIn(char)) arg.cra_name
//  Array(BuiltIn(char)) arg.cra_driver_name
        SCAN_RECURSIVE_PTR(arg.cra_type);
//  Union(union anon_union_91) arg.cra_u
        SCAN_FUNCTION(arg.cra_init);
        SCAN_FUNCTION(arg.cra_exit);
        SCAN_FUNCTION(arg.cra_destroy);
        SCAN_RECURSIVE_PTR(arg.cra_module);
    }
})
#endif


#define SCANNER_FOR_struct_crypto_tfm
#ifndef SCANNER_FOR_struct_crypto_tfm
#define SCANNER_FOR_struct_crypto_tfm
TYPE_SCAN_WRAPPER(struct crypto_tfm, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct crypto_tfm);
    }
    SCAN {
        S(kern_printk( "struct crypto_tfm\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.crt_flags);
//  Union(union anon_union_92) arg.crt_u
        SCAN_FUNCTION(arg.exit);
        SCAN_RECURSIVE_PTR(arg.__crt_alg);
//  Array(Pointer(BuiltIn(void))) arg.__crt_ctx
    }
})
#endif


#define SCANNER_FOR_struct_compress_alg
#ifndef SCANNER_FOR_struct_compress_alg
#define SCANNER_FOR_struct_compress_alg
TYPE_SCAN_WRAPPER(struct compress_alg, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct compress_alg);
    }
    SCAN {
        S(kern_printk( "struct compress_alg\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.coa_compress);
        SCAN_FUNCTION(arg.coa_decompress);
    }
})
#endif


#define SCANNER_FOR_struct_x86_init_irqs
#ifndef SCANNER_FOR_struct_x86_init_irqs
#define SCANNER_FOR_struct_x86_init_irqs
TYPE_SCAN_WRAPPER(struct x86_init_irqs, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct x86_init_irqs);
    }
    SCAN {
        S(kern_printk( "struct x86_init_irqs\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.pre_vector_init);
        SCAN_FUNCTION(arg.intr_init);
        SCAN_FUNCTION(arg.trap_init);
    }
})
#endif


#define SCANNER_FOR_struct_seq_net_private
#ifndef SCANNER_FOR_struct_seq_net_private
#define SCANNER_FOR_struct_seq_net_private
TYPE_SCAN_WRAPPER(struct seq_net_private, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct seq_net_private);
    }
    SCAN {
        S(kern_printk( "struct seq_net_private\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.net);
    }
})
#endif


#define SCANNER_FOR_struct_neigh_seq_state
#ifndef SCANNER_FOR_struct_neigh_seq_state
#define SCANNER_FOR_struct_neigh_seq_state
TYPE_SCAN_WRAPPER(struct neigh_seq_state, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct neigh_seq_state);
    }
    SCAN {
        S(kern_printk( "struct neigh_seq_state\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.p);
        SCAN_RECURSIVE_PTR(arg.tbl);
        SCAN_RECURSIVE_PTR(arg.nht);
        SCAN_FUNCTION(arg.neigh_sub_iter);
        SCAN_FUNCTION(arg.bucket);
        SCAN_FUNCTION(arg.flags);
    }
})
#endif


#define SCANNER_FOR_struct_zone
#ifndef SCANNER_FOR_struct_zone
#define SCANNER_FOR_struct_zone
TYPE_SCAN_WRAPPER(struct zone, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct zone);
    }
    SCAN {
        S(kern_printk( "struct zone\n");)
        S(SCAN_OBJECT(arg);)
//  Array(Attributed(unsigned , BuiltIn(long))) arg.watermark
        SCAN_FUNCTION(arg.percpu_drift_mark);
//  Array(Attributed(unsigned , BuiltIn(long))) arg.lowmem_reserve
        SCAN_FUNCTION(arg.dirty_balance_reserve);
        SCAN_FUNCTION(arg.node);
        SCAN_FUNCTION(arg.min_unmapped_pages);
        SCAN_FUNCTION(arg.min_slab_pages);
        SCAN_RECURSIVE_PTR(arg.pageset);
        SCAN_RECURSIVE(arg.lock);
        SCAN_FUNCTION(arg.all_unreclaimable);
        SCAN_FUNCTION(arg.compact_blockskip_flush);
        SCAN_FUNCTION(arg.compact_cached_free_pfn);
        SCAN_FUNCTION(arg.compact_cached_migrate_pfn);
        SCAN_RECURSIVE(arg.span_seqlock);
//  Array(Use(Struct(struct free_area))) arg.free_area
        SCAN_FUNCTION(arg.compact_considered);
        SCAN_FUNCTION(arg.compact_defer_shift);
        SCAN_FUNCTION(arg.compact_order_failed);
        SCAN_RECURSIVE(arg._pad1_);
        SCAN_RECURSIVE(arg.lru_lock);
        SCAN_RECURSIVE(arg.lruvec);
        SCAN_FUNCTION(arg.pages_scanned);
        SCAN_FUNCTION(arg.flags);
//  Array(Use(TypeDef(atomic_long_t, Use(TypeDef(atomic64_t, Struct(atomic64_t)))))) arg.vm_stat
        SCAN_FUNCTION(arg.inactive_ratio);
        SCAN_RECURSIVE(arg._pad2_);
        SCAN_RECURSIVE_PTR(arg.wait_table);
        SCAN_FUNCTION(arg.wait_table_hash_nr_entries);
        SCAN_FUNCTION(arg.wait_table_bits);
        SCAN_RECURSIVE_PTR(arg.zone_pgdat);
        SCAN_FUNCTION(arg.zone_start_pfn);
        SCAN_FUNCTION(arg.spanned_pages);
        SCAN_FUNCTION(arg.present_pages);
        SCAN_FUNCTION(arg.managed_pages);
        SCAN_FUNCTION(arg.name);
    }
})
#endif


#define SCANNER_FOR_struct_zoneref
#ifndef SCANNER_FOR_struct_zoneref
#define SCANNER_FOR_struct_zoneref
TYPE_SCAN_WRAPPER(struct zoneref, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct zoneref);
    }
    SCAN {
        S(kern_printk( "struct zoneref\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.zone);
        SCAN_FUNCTION(arg.zone_idx);
    }
})
#endif


#define SCANNER_FOR_struct_pglist_data
#ifndef SCANNER_FOR_struct_pglist_data
#define SCANNER_FOR_struct_pglist_data
TYPE_SCAN_WRAPPER(struct pglist_data, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pglist_data);
    }
    SCAN {
        S(kern_printk( "struct pglist_data\n");)
        S(SCAN_OBJECT(arg);)
//  Array(Use(Struct(struct zone))) arg.node_zones
//  Array(Use(Struct(struct zonelist))) arg.node_zonelists
        SCAN_FUNCTION(arg.nr_zones);
        SCAN_RECURSIVE(arg.node_size_lock);
        SCAN_FUNCTION(arg.node_start_pfn);
        SCAN_FUNCTION(arg.node_present_pages);
        SCAN_FUNCTION(arg.node_spanned_pages);
        SCAN_FUNCTION(arg.node_id);
        SCAN_RECURSIVE(arg.reclaim_nodes);
        SCAN_RECURSIVE(arg.kswapd_wait);
        SCAN_RECURSIVE(arg.pfmemalloc_wait);
        SCAN_RECURSIVE_PTR(arg.kswapd);
        SCAN_FUNCTION(arg.kswapd_max_order);
//  Enum(enum zone_type) arg.classzone_idx
    }
})
#endif


#define SCANNER_FOR_struct_vm_region
#ifndef SCANNER_FOR_struct_vm_region
#define SCANNER_FOR_struct_vm_region
TYPE_SCAN_WRAPPER(struct vm_region, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct vm_region);
    }
    SCAN {
        S(kern_printk( "struct vm_region\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.vm_rb);
        SCAN_FUNCTION(arg.vm_flags);
        SCAN_FUNCTION(arg.vm_start);
        SCAN_FUNCTION(arg.vm_end);
        SCAN_FUNCTION(arg.vm_top);
        SCAN_FUNCTION(arg.vm_pgoff);
        SCAN_RECURSIVE_PTR(arg.vm_file);
        SCAN_FUNCTION(arg.vm_usage);
//  Bitfield(Use(TypeDef(bool, Use(TypeDef(K_Bool, BuiltIn(int)))))) arg.vm_icache_flushed
    }
})
#endif


#define SCANNER_FOR_struct_pnp_driver
#ifndef SCANNER_FOR_struct_pnp_driver
#define SCANNER_FOR_struct_pnp_driver
TYPE_SCAN_WRAPPER(struct pnp_driver, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pnp_driver);
    }
    SCAN {
        S(kern_printk( "struct pnp_driver\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE_PTR(arg.id_table);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.probe);
        SCAN_FUNCTION(arg.remove);
        SCAN_FUNCTION(arg.shutdown);
        SCAN_FUNCTION(arg.suspend);
        SCAN_FUNCTION(arg.resume);
        SCAN_RECURSIVE(arg.driver);
    }
})
#endif


#define SCANNER_FOR_struct_pnp_dev
#ifndef SCANNER_FOR_struct_pnp_dev
#define SCANNER_FOR_struct_pnp_dev
TYPE_SCAN_WRAPPER(struct pnp_dev, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pnp_dev);
    }
    SCAN {
        S(kern_printk( "struct pnp_dev\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.dev);
        SCAN_FUNCTION(arg.dma_mask);
        SCAN_FUNCTION(arg.number);
        SCAN_FUNCTION(arg.status);
        SCAN_RECURSIVE(arg.global_list);
        SCAN_RECURSIVE(arg.protocol_list);
        SCAN_RECURSIVE(arg.card_list);
        SCAN_RECURSIVE(arg.rdev_list);
        SCAN_RECURSIVE_PTR(arg.protocol);
        SCAN_RECURSIVE_PTR(arg.card);
        SCAN_RECURSIVE_PTR(arg.driver);
        SCAN_RECURSIVE_PTR(arg.card_link);
        SCAN_RECURSIVE_PTR(arg.id);
        SCAN_FUNCTION(arg.active);
        SCAN_FUNCTION(arg.capabilities);
        SCAN_FUNCTION(arg.num_dependent_sets);
        SCAN_RECURSIVE(arg.resources);
        SCAN_RECURSIVE(arg.options);
//  Array(BuiltIn(char)) arg.name
        SCAN_FUNCTION(arg.flags);
        SCAN_RECURSIVE_PTR(arg.procent);
        SCAN_FUNCTION(arg.data);
    }
})
#endif


#define SCANNER_FOR_struct_pnp_protocol
#ifndef SCANNER_FOR_struct_pnp_protocol
#define SCANNER_FOR_struct_pnp_protocol
TYPE_SCAN_WRAPPER(struct pnp_protocol, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pnp_protocol);
    }
    SCAN {
        S(kern_printk( "struct pnp_protocol\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.protocol_list);
        SCAN_FUNCTION(arg.name);
        SCAN_FUNCTION(arg.get);
        SCAN_FUNCTION(arg.set);
        SCAN_FUNCTION(arg.disable);
        SCAN_FUNCTION(arg.can_wakeup);
        SCAN_FUNCTION(arg.suspend);
        SCAN_FUNCTION(arg.resume);
        SCAN_FUNCTION(arg.number);
        SCAN_RECURSIVE(arg.dev);
        SCAN_RECURSIVE(arg.cards);
        SCAN_RECURSIVE(arg.devices);
    }
})
#endif


#define SCANNER_FOR_struct_pnp_card
#ifndef SCANNER_FOR_struct_pnp_card
#define SCANNER_FOR_struct_pnp_card
TYPE_SCAN_WRAPPER(struct pnp_card, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pnp_card);
    }
    SCAN {
        S(kern_printk( "struct pnp_card\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.dev);
        SCAN_FUNCTION(arg.number);
        SCAN_RECURSIVE(arg.global_list);
        SCAN_RECURSIVE(arg.protocol_list);
        SCAN_RECURSIVE(arg.devices);
        SCAN_RECURSIVE_PTR(arg.protocol);
        SCAN_RECURSIVE_PTR(arg.id);
//  Array(BuiltIn(char)) arg.name
        SCAN_FUNCTION(arg.pnpver);
        SCAN_FUNCTION(arg.productver);
        SCAN_FUNCTION(arg.serial);
        SCAN_FUNCTION(arg.checksum);
        SCAN_RECURSIVE_PTR(arg.procdir);
    }
})
#endif


#define SCANNER_FOR_struct_pnp_card_link
#ifndef SCANNER_FOR_struct_pnp_card_link
#define SCANNER_FOR_struct_pnp_card_link
TYPE_SCAN_WRAPPER(struct pnp_card_link, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pnp_card_link);
    }
    SCAN {
        S(kern_printk( "struct pnp_card_link\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.card);
        SCAN_RECURSIVE_PTR(arg.driver);
        SCAN_FUNCTION(arg.driver_data);
        SCAN_RECURSIVE(arg.pm_state);
    }
})
#endif


#define SCANNER_FOR_struct_pnp_card_driver
#ifndef SCANNER_FOR_struct_pnp_card_driver
#define SCANNER_FOR_struct_pnp_card_driver
TYPE_SCAN_WRAPPER(struct pnp_card_driver, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pnp_card_driver);
    }
    SCAN {
        S(kern_printk( "struct pnp_card_driver\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.global_list);
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE_PTR(arg.id_table);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.probe);
        SCAN_FUNCTION(arg.remove);
        SCAN_FUNCTION(arg.suspend);
        SCAN_FUNCTION(arg.resume);
        SCAN_RECURSIVE(arg.link);
    }
})
#endif


#define SCANNER_FOR_struct_netdev_hw_addr
#ifndef SCANNER_FOR_struct_netdev_hw_addr
#define SCANNER_FOR_struct_netdev_hw_addr
TYPE_SCAN_WRAPPER(struct netdev_hw_addr, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netdev_hw_addr);
    }
    SCAN {
        S(kern_printk( "struct netdev_hw_addr\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
//  Array(Attributed(unsigned , BuiltIn(char))) arg.addr
        SCAN_FUNCTION(arg.type);
        SCAN_FUNCTION(arg.synced);
        SCAN_FUNCTION(arg.global_use);
        SCAN_FUNCTION(arg.refcount);
        SCAN_RECURSIVE(arg.callback_head);
    }
})
#endif


#define SCANNER_FOR_struct_rq_map_data
#ifndef SCANNER_FOR_struct_rq_map_data
#define SCANNER_FOR_struct_rq_map_data
TYPE_SCAN_WRAPPER(struct rq_map_data, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct rq_map_data);
    }
    SCAN {
        S(kern_printk( "struct rq_map_data\n");)
        S(SCAN_OBJECT(arg);)
//  Pointer(Pointer(Use(Struct(struct page)))) arg.pages
        SCAN_FUNCTION(arg.page_order);
        SCAN_FUNCTION(arg.nr_entries);
        SCAN_FUNCTION(arg.offset);
        SCAN_FUNCTION(arg.null_mapped);
        SCAN_FUNCTION(arg.from_user);
    }
})
#endif


#define SCANNER_FOR_struct_scm_cookie
#ifndef SCANNER_FOR_struct_scm_cookie
#define SCANNER_FOR_struct_scm_cookie
TYPE_SCAN_WRAPPER(struct scm_cookie, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct scm_cookie);
    }
    SCAN {
        S(kern_printk( "struct scm_cookie\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.pid);
        SCAN_RECURSIVE_PTR(arg.cred);
        SCAN_RECURSIVE_PTR(arg.fp);
        SCAN_RECURSIVE(arg.creds);
        SCAN_FUNCTION(arg.secid);
    }
})
#endif


#define SCANNER_FOR_struct_sock_iocb
#ifndef SCANNER_FOR_struct_sock_iocb
#define SCANNER_FOR_struct_sock_iocb
TYPE_SCAN_WRAPPER(struct sock_iocb, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct sock_iocb);
    }
    SCAN {
        S(kern_printk( "struct sock_iocb\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.size);
        SCAN_RECURSIVE_PTR(arg.sock);
        SCAN_RECURSIVE_PTR(arg.sk);
        SCAN_RECURSIVE_PTR(arg.scm);
        SCAN_RECURSIVE_PTR(arg.msg);
        SCAN_RECURSIVE(arg.async_msg);
        SCAN_RECURSIVE_PTR(arg.kiocb);
    }
})
#endif


#define SCANNER_FOR_struct_x86_init_mapping
#ifndef SCANNER_FOR_struct_x86_init_mapping
#define SCANNER_FOR_struct_x86_init_mapping
TYPE_SCAN_WRAPPER(struct x86_init_mapping, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct x86_init_mapping);
    }
    SCAN {
        S(kern_printk( "struct x86_init_mapping\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.pagetable_reserve);
    }
})
#endif



#ifndef SCANNER_FOR_struct_exec_domain
#define SCANNER_FOR_struct_exec_domain
TYPE_SCAN_WRAPPER(struct exec_domain, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct exec_domain);
    }
    SCAN {
        S(kern_printk( "struct exec_domain\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_FUNCTION(arg.handler);
        SCAN_FUNCTION(arg.pers_low);
        SCAN_FUNCTION(arg.pers_high);
        SCAN_FUNCTION(arg.signal_map);
        SCAN_FUNCTION(arg.signal_invmap);
        SCAN_RECURSIVE_PTR(arg.err_map);
        SCAN_RECURSIVE_PTR(arg.socktype_map);
        SCAN_RECURSIVE_PTR(arg.sockopt_map);
        SCAN_RECURSIVE_PTR(arg.af_map);
        SCAN_RECURSIVE_PTR(arg.module);
        SCAN_RECURSIVE_PTR(arg.next);
    }
})
#endif


//#define SCANNER_FOR_struct_buffer_head
#ifndef SCANNER_FOR_struct_buffer_head
#define SCANNER_FOR_struct_buffer_head
TYPE_SCAN_WRAPPER(struct buffer_head, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct buffer_head);
    }
    SCAN {
        S(kern_printk( "struct buffer_head\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.b_state);
        kern_printk("buffer head next ptr : %lx\n",arg.b_this_page);
        /*TODO: the next pointer to buffer cache is taking garbage value; look for this*/
       // SCAN_RECURSIVE_PTR(arg.b_this_page);
        SCAN_RECURSIVE_PTR(arg.b_page);
        SCAN_FUNCTION(arg.b_blocknr);
        SCAN_FUNCTION(arg.b_size);
        SCAN_FUNCTION(arg.b_data);
        SCAN_RECURSIVE_PTR(arg.b_bdev);
        SCAN_FUNCTION(arg.b_end_io);
        SCAN_FUNCTION(arg.b_private);
        SCAN_RECURSIVE(arg.b_assoc_buffers);
        SCAN_RECURSIVE_PTR(arg.b_assoc_map);
        SCAN_RECURSIVE(arg.b_count);
    }
})
#endif


#ifndef SCANNER_FOR_struct_crypto_shash
#define SCANNER_FOR_struct_crypto_shash
TYPE_SCAN_WRAPPER(struct crypto_shash, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct crypto_shash);
    }
    SCAN {
        S(kern_printk( "struct crypto_shash\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.descsize);
        SCAN_RECURSIVE(arg.base);
    }
})
#endif



#ifndef SCANNER_FOR_struct_journal_s
#define SCANNER_FOR_struct_journal_s
TYPE_SCAN_WRAPPER(struct journal_s, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct journal_s);
    }
    SCAN {
        S(kern_printk( "struct journal_s\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.j_flags);
        SCAN_FUNCTION(arg.j_errno);
        SCAN_RECURSIVE_PTR(arg.j_sb_buffer);
        SCAN_RECURSIVE_PTR(arg.j_superblock);
        SCAN_FUNCTION(arg.j_format_version);
        SCAN_RECURSIVE(arg.j_state_lock);
        SCAN_FUNCTION(arg.j_barrier_count);
        SCAN_RECURSIVE(arg.j_barrier);
        SCAN_RECURSIVE_PTR(arg.j_running_transaction);
        SCAN_RECURSIVE_PTR(arg.j_committing_transaction);
        SCAN_RECURSIVE_PTR(arg.j_checkpoint_transactions);
        SCAN_RECURSIVE(arg.j_wait_transaction_locked);
        SCAN_RECURSIVE(arg.j_wait_logspace);
        SCAN_RECURSIVE(arg.j_wait_done_commit);
        SCAN_RECURSIVE(arg.j_wait_checkpoint);
        SCAN_RECURSIVE(arg.j_wait_commit);
        SCAN_RECURSIVE(arg.j_wait_updates);
        SCAN_RECURSIVE(arg.j_checkpoint_mutex);
//  Array(Pointer(Use(Struct(struct buffer_head)))) arg.j_chkpt_bhs
        SCAN_FUNCTION(arg.j_head);
        SCAN_FUNCTION(arg.j_tail);
        SCAN_FUNCTION(arg.j_free);
        SCAN_FUNCTION(arg.j_first);
        SCAN_FUNCTION(arg.j_last);
        SCAN_RECURSIVE_PTR(arg.j_dev);
        SCAN_FUNCTION(arg.j_blocksize);
        SCAN_FUNCTION(arg.j_blk_offset);
//  Array(BuiltIn(char)) arg.j_devname
        SCAN_RECURSIVE_PTR(arg.j_fs_dev);
        SCAN_FUNCTION(arg.j_maxlen);
        SCAN_RECURSIVE(arg.j_list_lock);
        SCAN_RECURSIVE_PTR(arg.j_inode);
        SCAN_FUNCTION(arg.j_tail_sequence);
        SCAN_FUNCTION(arg.j_transaction_sequence);
        SCAN_FUNCTION(arg.j_commit_sequence);
        SCAN_FUNCTION(arg.j_commit_request);
//  Array(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.j_uuid
        SCAN_RECURSIVE_PTR(arg.j_task);
        SCAN_FUNCTION(arg.j_max_transaction_buffers);
        SCAN_FUNCTION(arg.j_commit_interval);
        SCAN_RECURSIVE(arg.j_commit_timer);
        SCAN_RECURSIVE(arg.j_revoke_lock);
        SCAN_RECURSIVE_PTR(arg.j_revoke);
//  Array(Pointer(Use(Struct(struct jbd2_revoke_table_s)))) arg.j_revoke_table
//  Pointer(Pointer(Use(Struct(struct buffer_head)))) arg.j_wbuf
        SCAN_FUNCTION(arg.j_wbufsize);
        SCAN_FUNCTION(arg.j_last_sync_writer);
        SCAN_FUNCTION(arg.j_average_commit_time);
        SCAN_FUNCTION(arg.j_min_batch_time);
        SCAN_FUNCTION(arg.j_max_batch_time);
        SCAN_FUNCTION(arg.j_commit_callback);
        SCAN_RECURSIVE(arg.j_history_lock);
        SCAN_RECURSIVE_PTR(arg.j_proc_entry);
        SCAN_RECURSIVE(arg.j_stats);
        SCAN_FUNCTION(arg.j_failed_commit);
        SCAN_FUNCTION(arg.j_private);
        SCAN_RECURSIVE_PTR(arg.j_chksum_driver);
        SCAN_FUNCTION(arg.j_csum_seed);
    }
})
#endif


#define SCANNER_FOR_struct_transaction_s
#ifndef SCANNER_FOR_struct_transaction_s
#define SCANNER_FOR_struct_transaction_s
TYPE_SCAN_WRAPPER(struct transaction_s, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct transaction_s);
    }
    SCAN {
        S(kern_printk( "struct transaction_s\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.t_journal);
        SCAN_FUNCTION(arg.t_tid);
//  Enum(enum anon_enum_417) arg.t_state
        SCAN_FUNCTION(arg.t_log_start);
        SCAN_FUNCTION(arg.t_nr_buffers);
        SCAN_RECURSIVE_PTR(arg.t_reserved_list);
        SCAN_RECURSIVE_PTR(arg.t_buffers);
        SCAN_RECURSIVE_PTR(arg.t_forget);
        SCAN_RECURSIVE_PTR(arg.t_checkpoint_list);
        SCAN_RECURSIVE_PTR(arg.t_checkpoint_io_list);
        SCAN_RECURSIVE_PTR(arg.t_iobuf_list);
        SCAN_RECURSIVE_PTR(arg.t_shadow_list);
        SCAN_RECURSIVE_PTR(arg.t_log_list);
        SCAN_RECURSIVE(arg.t_inode_list);
        SCAN_RECURSIVE(arg.t_handle_lock);
        SCAN_FUNCTION(arg.t_max_wait);
        SCAN_FUNCTION(arg.t_start);
        SCAN_RECURSIVE(arg.t_chp_stats);
        SCAN_RECURSIVE(arg.t_updates);
        SCAN_RECURSIVE(arg.t_outstanding_credits);
        SCAN_RECURSIVE_PTR(arg.t_cpnext);
        SCAN_RECURSIVE_PTR(arg.t_cpprev);
        SCAN_FUNCTION(arg.t_expires);
//  Union(union ktime) arg.t_start_time
        SCAN_RECURSIVE(arg.t_handle_count);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.t_synchronous_commit
        SCAN_FUNCTION(arg.t_need_data_flush);
        SCAN_RECURSIVE(arg.t_private_list);
    }
})
#endif


#define SCANNER_FOR_struct_jbd2_buffer_trigger_type
#ifndef SCANNER_FOR_struct_jbd2_buffer_trigger_type
#define SCANNER_FOR_struct_jbd2_buffer_trigger_type
TYPE_SCAN_WRAPPER(struct jbd2_buffer_trigger_type, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct jbd2_buffer_trigger_type);
    }
    SCAN {
        S(kern_printk( "struct jbd2_buffer_trigger_type\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.t_frozen);
        SCAN_FUNCTION(arg.t_abort);
    }
})
#endif


//#define SCANNER_FOR_struct_journal_head
#ifndef SCANNER_FOR_struct_journal_head
#define SCANNER_FOR_struct_journal_head
TYPE_SCAN_WRAPPER(struct journal_head, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct journal_head);
    }
    SCAN {
        S(kern_printk( "struct journal_head\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.b_bh);
        SCAN_FUNCTION(arg.b_jcount);
        SCAN_FUNCTION(arg.b_jlist);
        SCAN_FUNCTION(arg.b_modified);
        SCAN_FUNCTION(arg.b_cow_tid);
        SCAN_FUNCTION(arg.b_frozen_data);
        SCAN_FUNCTION(arg.b_committed_data);
        SCAN_RECURSIVE_PTR(arg.b_transaction);
        SCAN_RECURSIVE_PTR(arg.b_next_transaction);
        SCAN_RECURSIVE_PTR(arg.b_tnext);
        SCAN_RECURSIVE_PTR(arg.b_tprev);
        SCAN_RECURSIVE_PTR(arg.b_cp_transaction);
        SCAN_RECURSIVE_PTR(arg.b_cpnext);
        SCAN_RECURSIVE_PTR(arg.b_cpprev);
        SCAN_RECURSIVE_PTR(arg.b_triggers);
        SCAN_RECURSIVE_PTR(arg.b_frozen_triggers);
    }
})
#endif


#define SCANNER_FOR_struct_x86_init_pci
#ifndef SCANNER_FOR_struct_x86_init_pci
#define SCANNER_FOR_struct_x86_init_pci
TYPE_SCAN_WRAPPER(struct x86_init_pci, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct x86_init_pci);
    }
    SCAN {
        S(kern_printk( "struct x86_init_pci\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.arch_init);
        SCAN_FUNCTION(arg.init);
        SCAN_FUNCTION(arg.init_irq);
        SCAN_FUNCTION(arg.fixup_irqs);
    }
})
#endif


#define SCANNER_FOR_struct_pv_cpu_ops
#ifndef SCANNER_FOR_struct_pv_cpu_ops
#define SCANNER_FOR_struct_pv_cpu_ops
TYPE_SCAN_WRAPPER(struct pv_cpu_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pv_cpu_ops);
    }
    SCAN {
        S(kern_printk( "struct pv_cpu_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.get_debugreg);
        SCAN_FUNCTION(arg.set_debugreg);
        SCAN_FUNCTION(arg.clts);
        SCAN_FUNCTION(arg.read_cr0);
        SCAN_FUNCTION(arg.write_cr0);
        SCAN_FUNCTION(arg.read_cr4_safe);
        SCAN_FUNCTION(arg.read_cr4);
        SCAN_FUNCTION(arg.write_cr4);
        SCAN_FUNCTION(arg.read_cr8);
        SCAN_FUNCTION(arg.write_cr8);
        SCAN_FUNCTION(arg.load_tr_desc);
        SCAN_FUNCTION(arg.load_gdt);
        SCAN_FUNCTION(arg.load_idt);
        SCAN_FUNCTION(arg.store_gdt);
        SCAN_FUNCTION(arg.store_idt);
        SCAN_FUNCTION(arg.set_ldt);
        SCAN_FUNCTION(arg.store_tr);
        SCAN_FUNCTION(arg.load_tls);
        SCAN_FUNCTION(arg.load_gs_index);
        SCAN_FUNCTION(arg.write_ldt_entry);
        SCAN_FUNCTION(arg.write_gdt_entry);
        SCAN_FUNCTION(arg.write_idt_entry);
        SCAN_FUNCTION(arg.alloc_ldt);
        SCAN_FUNCTION(arg.free_ldt);
        SCAN_FUNCTION(arg.load_sp0);
        SCAN_FUNCTION(arg.set_iopl_mask);
        SCAN_FUNCTION(arg.wbinvd);
        SCAN_FUNCTION(arg.io_delay);
        SCAN_FUNCTION(arg.cpuid);
        SCAN_FUNCTION(arg.read_msr);
        SCAN_FUNCTION(arg.write_msr);
        SCAN_FUNCTION(arg.read_tsc);
        SCAN_FUNCTION(arg.read_pmc);
        SCAN_FUNCTION(arg.read_tscp);
        SCAN_FUNCTION(arg.irq_enable_sysexit);
        SCAN_FUNCTION(arg.usergs_sysret64);
        SCAN_FUNCTION(arg.usergs_sysret32);
        SCAN_FUNCTION(arg.iret);
        SCAN_FUNCTION(arg.swapgs);
        SCAN_FUNCTION(arg.start_context_switch);
        SCAN_FUNCTION(arg.end_context_switch);
    }
})
#endif


#define SCANNER_FOR_struct_socket_alloc
#ifndef SCANNER_FOR_struct_socket_alloc
#define SCANNER_FOR_struct_socket_alloc
TYPE_SCAN_WRAPPER(struct socket_alloc, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct socket_alloc);
    }
    SCAN {
        S(kern_printk( "struct socket_alloc\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.socket);
        SCAN_RECURSIVE(arg.vfs_inode);
    }
})
#endif


#define SCANNER_FOR_struct_klist
#ifndef SCANNER_FOR_struct_klist
#define SCANNER_FOR_struct_klist
TYPE_SCAN_WRAPPER(struct klist, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct klist);
    }
    SCAN {
        S(kern_printk( "struct klist\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.k_lock);
        SCAN_RECURSIVE(arg.k_list);
        SCAN_FUNCTION(arg.get);
        SCAN_FUNCTION(arg.put);
    }
})
#endif


#define SCANNER_FOR_struct_inet6_request_sock
#ifndef SCANNER_FOR_struct_inet6_request_sock
#define SCANNER_FOR_struct_inet6_request_sock
TYPE_SCAN_WRAPPER(struct inet6_request_sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct inet6_request_sock);
    }
    SCAN {
        S(kern_printk( "struct inet6_request_sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.loc_addr);
        SCAN_RECURSIVE(arg.rmt_addr);
        SCAN_RECURSIVE_PTR(arg.pktopts);
        SCAN_FUNCTION(arg.iif);
    }
})
#endif


#define SCANNER_FOR_struct_pci_slot
#ifndef SCANNER_FOR_struct_pci_slot
#define SCANNER_FOR_struct_pci_slot
TYPE_SCAN_WRAPPER(struct pci_slot, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pci_slot);
    }
    SCAN {
        S(kern_printk( "struct pci_slot\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.bus);
        SCAN_RECURSIVE(arg.list);
        SCAN_RECURSIVE_PTR(arg.hotplug);
        SCAN_FUNCTION(arg.number);
        SCAN_RECURSIVE(arg.kobj);
    }
})
#endif


#define SCANNER_FOR_struct_pci_error_handlers
#ifndef SCANNER_FOR_struct_pci_error_handlers
#define SCANNER_FOR_struct_pci_error_handlers
TYPE_SCAN_WRAPPER(struct pci_error_handlers, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pci_error_handlers);
    }
    SCAN {
        S(kern_printk( "struct pci_error_handlers\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.error_detected);
        SCAN_FUNCTION(arg.mmio_enabled);
        SCAN_FUNCTION(arg.link_reset);
        SCAN_FUNCTION(arg.slot_reset);
        SCAN_FUNCTION(arg.resume);
    }
})
#endif


#define SCANNER_FOR_struct_pci_driver
#ifndef SCANNER_FOR_struct_pci_driver
#define SCANNER_FOR_struct_pci_driver
TYPE_SCAN_WRAPPER(struct pci_driver, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pci_driver);
    }
    SCAN {
        S(kern_printk( "struct pci_driver\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.node);
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE_PTR(arg.id_table);
        SCAN_FUNCTION(arg.probe);
        SCAN_FUNCTION(arg.remove);
        SCAN_FUNCTION(arg.suspend);
        SCAN_FUNCTION(arg.suspend_late);
        SCAN_FUNCTION(arg.resume_early);
        SCAN_FUNCTION(arg.resume);
        SCAN_FUNCTION(arg.shutdown);
        SCAN_FUNCTION(arg.sriov_configure);
        SCAN_RECURSIVE_PTR(arg.err_handler);
        SCAN_RECURSIVE(arg.driver);
        SCAN_RECURSIVE(arg.dynids);
    }
})
#endif


#define SCANNER_FOR_struct_pci_dev
#ifndef SCANNER_FOR_struct_pci_dev
#define SCANNER_FOR_struct_pci_dev
TYPE_SCAN_WRAPPER(struct pci_dev, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pci_dev);
    }
    SCAN {
        S(kern_printk( "struct pci_dev\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.bus_list);
        SCAN_RECURSIVE_PTR(arg.bus);
        SCAN_RECURSIVE_PTR(arg.subordinate);
        SCAN_FUNCTION(arg.sysdata);
        SCAN_RECURSIVE_PTR(arg.procent);
        SCAN_RECURSIVE_PTR(arg.slot);
        SCAN_FUNCTION(arg.devfn);
        SCAN_FUNCTION(arg.vendor);
        SCAN_FUNCTION(arg.device);
        SCAN_FUNCTION(arg.subsystem_vendor);
        SCAN_FUNCTION(arg.subsystem_device);
        SCAN_FUNCTION(arg.class_);
        SCAN_FUNCTION(arg.revision);
        SCAN_FUNCTION(arg.hdr_type);
        SCAN_FUNCTION(arg.pcie_cap);
//  Bitfield(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.pcie_mpss
        SCAN_FUNCTION(arg.rom_base_reg);
        SCAN_FUNCTION(arg.pin);
        SCAN_FUNCTION(arg.pcie_flags_reg);
        SCAN_RECURSIVE_PTR(arg.driver);
        SCAN_FUNCTION(arg.dma_mask);
        SCAN_RECURSIVE(arg.dma_parms);
        SCAN_FUNCTION(arg.current_state);
        SCAN_FUNCTION(arg.pm_cap);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.pme_support
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.pme_interrupt
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.pme_poll
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.d1_support
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.d2_support
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.no_d1d2
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.no_d3cold
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.d3cold_allowed
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.mmio_always_on
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.wakeup_prepared
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.runtime_d3cold
        SCAN_FUNCTION(arg.d3_delay);
        SCAN_FUNCTION(arg.d3cold_delay);
        SCAN_RECURSIVE_PTR(arg.link_state);
        SCAN_FUNCTION(arg.error_state);
        SCAN_RECURSIVE(arg.dev);
        SCAN_FUNCTION(arg.cfg_size);
        SCAN_FUNCTION(arg.irq);
//  Array(Use(Struct(struct resource))) arg.resource
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.transparent
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.multifunction
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.is_added
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.is_busmaster
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.no_msi
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.block_cfg_access
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.broken_parity_status
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.irq_reroute_variant
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.msi_enabled
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.msix_enabled
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.ari_enabled
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.is_managed
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.is_pcie
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.needs_freset
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.state_saved
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.is_physfn
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.is_virtfn
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.reset_fn
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.is_hotplug_bridge
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.__aer_firmware_first_valid
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.__aer_firmware_first
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.broken_intx_masking
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.io_window_1k
        SCAN_FUNCTION(arg.dev_flags);
        SCAN_RECURSIVE(arg.enable_cnt);
//  Array(Use(TypeDef(u32, Attributed(unsigned , BuiltIn(int))))) arg.saved_config_space
        SCAN_RECURSIVE(arg.saved_cap_space);
        SCAN_RECURSIVE_PTR(arg.rom_attr);
        SCAN_FUNCTION(arg.rom_attr_enabled);
//  Array(Pointer(Use(Struct(struct bin_attribute)))) arg.res_attr
//  Array(Pointer(Use(Struct(struct bin_attribute)))) arg.res_attr_wc
        SCAN_RECURSIVE(arg.msi_list);
        SCAN_RECURSIVE_PTR(arg.msi_kset);
        SCAN_RECURSIVE_PTR(arg.vpd);
//  Union(union anon_union_125) None
        SCAN_RECURSIVE_PTR(arg.ats);
        SCAN_FUNCTION(arg.rom);
        SCAN_FUNCTION(arg.romlen);
    }
})
#endif


#define SCANNER_FOR_struct_pci_bus
#ifndef SCANNER_FOR_struct_pci_bus
#define SCANNER_FOR_struct_pci_bus
TYPE_SCAN_WRAPPER(struct pci_bus, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pci_bus);
    }
    SCAN {
        S(kern_printk( "struct pci_bus\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.node);
        SCAN_RECURSIVE_PTR(arg.parent);
        SCAN_RECURSIVE(arg.children);
        SCAN_RECURSIVE(arg.devices);
        SCAN_RECURSIVE_PTR(arg.self);
        SCAN_RECURSIVE(arg.slots);
//  Array(Pointer(Use(Struct(struct resource)))) arg.resource
        SCAN_RECURSIVE(arg.resources);
        SCAN_RECURSIVE(arg.busn_res);
        SCAN_RECURSIVE_PTR(arg.ops);
        SCAN_FUNCTION(arg.sysdata);
        SCAN_RECURSIVE_PTR(arg.procdir);
        SCAN_FUNCTION(arg.number);
        SCAN_FUNCTION(arg.primary);
        SCAN_FUNCTION(arg.max_bus_speed);
        SCAN_FUNCTION(arg.cur_bus_speed);
//  Array(BuiltIn(char)) arg.name
        SCAN_FUNCTION(arg.bridge_ctl);
        SCAN_FUNCTION(arg.bus_flags);
        SCAN_RECURSIVE_PTR(arg.bridge);
        SCAN_RECURSIVE(arg.dev);
        SCAN_RECURSIVE_PTR(arg.legacy_io);
        SCAN_RECURSIVE_PTR(arg.legacy_mem);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.is_added
    }
})
#endif


#define SCANNER_FOR_struct_pci_ops
#ifndef SCANNER_FOR_struct_pci_ops
#define SCANNER_FOR_struct_pci_ops
TYPE_SCAN_WRAPPER(struct pci_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pci_ops);
    }
    SCAN {
        S(kern_printk( "struct pci_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.read);
        SCAN_FUNCTION(arg.write);
    }
})
#endif


#define SCANNER_FOR_struct_proc_ns_operations
#ifndef SCANNER_FOR_struct_proc_ns_operations
#define SCANNER_FOR_struct_proc_ns_operations
TYPE_SCAN_WRAPPER(struct proc_ns_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct proc_ns_operations);
    }
    SCAN {
        S(kern_printk( "struct proc_ns_operations\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_FUNCTION(arg.type);
        SCAN_FUNCTION(arg.get);
        SCAN_FUNCTION(arg.put);
        SCAN_FUNCTION(arg.install);
        SCAN_FUNCTION(arg.inum);
    }
})
#endif


#define SCANNER_FOR_struct_nfq_ct_nat_hook
#ifndef SCANNER_FOR_struct_nfq_ct_nat_hook
#define SCANNER_FOR_struct_nfq_ct_nat_hook
TYPE_SCAN_WRAPPER(struct nfq_ct_nat_hook, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct nfq_ct_nat_hook);
    }
    SCAN {
        S(kern_printk( "struct nfq_ct_nat_hook\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.seq_adjust);
    }
})
#endif


#define SCANNER_FOR_struct_jbd2_inode
#ifndef SCANNER_FOR_struct_jbd2_inode
#define SCANNER_FOR_struct_jbd2_inode
TYPE_SCAN_WRAPPER(struct jbd2_inode, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct jbd2_inode);
    }
    SCAN {
        S(kern_printk( "struct jbd2_inode\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.i_transaction);
        SCAN_RECURSIVE_PTR(arg.i_next_transaction);
        SCAN_RECURSIVE(arg.i_list);
        SCAN_RECURSIVE_PTR(arg.i_vfs_inode);
        SCAN_FUNCTION(arg.i_flags);
    }
})
#endif


#define SCANNER_FOR_struct_pernet_operations
#ifndef SCANNER_FOR_struct_pernet_operations
#define SCANNER_FOR_struct_pernet_operations
TYPE_SCAN_WRAPPER(struct pernet_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pernet_operations);
    }
    SCAN {
        S(kern_printk( "struct pernet_operations\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_FUNCTION(arg.init);
        SCAN_FUNCTION(arg.exit);
        SCAN_FUNCTION(arg.exit_batch);
        SCAN_FUNCTION(arg.id);
        SCAN_FUNCTION(arg.size);
    }
})
#endif


#define SCANNER_FOR_struct_mm_walk
#ifndef SCANNER_FOR_struct_mm_walk
#define SCANNER_FOR_struct_mm_walk
TYPE_SCAN_WRAPPER(struct mm_walk, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct mm_walk);
    }
    SCAN {
        S(kern_printk( "struct mm_walk\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.pgd_entry);
        SCAN_FUNCTION(arg.pud_entry);
        SCAN_FUNCTION(arg.pmd_entry);
        SCAN_FUNCTION(arg.pte_entry);
        SCAN_FUNCTION(arg.pte_hole);
        SCAN_FUNCTION(arg.hugetlb_entry);
        SCAN_RECURSIVE_PTR(arg.mm);
        SCAN_FUNCTION(arg.private_);
    }
})
#endif


#define SCANNER_FOR_struct_cdrom_device_info
#ifndef SCANNER_FOR_struct_cdrom_device_info
#define SCANNER_FOR_struct_cdrom_device_info
TYPE_SCAN_WRAPPER(struct cdrom_device_info, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cdrom_device_info);
    }
    SCAN {
        S(kern_printk( "struct cdrom_device_info\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.ops);
        SCAN_RECURSIVE(arg.list);
        SCAN_RECURSIVE_PTR(arg.disk);
        SCAN_FUNCTION(arg.handle);
        SCAN_FUNCTION(arg.mask);
        SCAN_FUNCTION(arg.speed);
        SCAN_FUNCTION(arg.capacity);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.options
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.mc_flags
        SCAN_FUNCTION(arg.vfs_events);
        SCAN_FUNCTION(arg.ioctl_events);
        SCAN_FUNCTION(arg.use_count);
//  Array(BuiltIn(char)) arg.name
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.sanyo_slot
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.keeplocked
//  Bitfield(Use(TypeDef(__u8, Attributed(unsigned , BuiltIn(char))))) arg.reserved
        SCAN_FUNCTION(arg.cdda_method);
        SCAN_FUNCTION(arg.last_sense);
        SCAN_FUNCTION(arg.media_written);
        SCAN_FUNCTION(arg.mmc3_profile);
        SCAN_FUNCTION(arg.for_data);
        SCAN_FUNCTION(arg.exit);
        SCAN_FUNCTION(arg.mrw_mode_page);
    }
})
#endif


#define SCANNER_FOR_struct_cdrom_device_ops
#ifndef SCANNER_FOR_struct_cdrom_device_ops
#define SCANNER_FOR_struct_cdrom_device_ops
TYPE_SCAN_WRAPPER(struct cdrom_device_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cdrom_device_ops);
    }
    SCAN {
        S(kern_printk( "struct cdrom_device_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.open);
        SCAN_FUNCTION(arg.release);
        SCAN_FUNCTION(arg.drive_status);
        SCAN_FUNCTION(arg.check_events);
        SCAN_FUNCTION(arg.media_changed);
        SCAN_FUNCTION(arg.tray_move);
        SCAN_FUNCTION(arg.lock_door);
        SCAN_FUNCTION(arg.select_speed);
        SCAN_FUNCTION(arg.select_disc);
        SCAN_FUNCTION(arg.get_last_session);
        SCAN_FUNCTION(arg.get_mcn);
        SCAN_FUNCTION(arg.reset);
        SCAN_FUNCTION(arg.audio_ioctl);
        SCAN_FUNCTION(arg.capability);
        SCAN_FUNCTION(arg.n_minors);
        SCAN_FUNCTION(arg.generic_packet);
    }
})
#endif


#define SCANNER_FOR_struct_dm_dev
#ifndef SCANNER_FOR_struct_dm_dev
#define SCANNER_FOR_struct_dm_dev
TYPE_SCAN_WRAPPER(struct dm_dev, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dm_dev);
    }
    SCAN {
        S(kern_printk( "struct dm_dev\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.bdev);
        SCAN_FUNCTION(arg.mode);
//  Array(BuiltIn(char)) arg.name
    }
})
#endif


#define SCANNER_FOR_struct_x86_platform_ops
#ifndef SCANNER_FOR_struct_x86_platform_ops
#define SCANNER_FOR_struct_x86_platform_ops
TYPE_SCAN_WRAPPER(struct x86_platform_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct x86_platform_ops);
    }
    SCAN {
        S(kern_printk( "struct x86_platform_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.calibrate_tsc);
        SCAN_FUNCTION(arg.get_wallclock);
        SCAN_FUNCTION(arg.set_wallclock);
        SCAN_FUNCTION(arg.iommu_shutdown);
        SCAN_FUNCTION(arg.is_untracked_pat_range);
        SCAN_FUNCTION(arg.nmi_init);
        SCAN_FUNCTION(arg.get_nmi_reason);
        SCAN_FUNCTION(arg.i8042_detect);
        SCAN_FUNCTION(arg.save_sched_clock_state);
        SCAN_FUNCTION(arg.restore_sched_clock_state);
        SCAN_FUNCTION(arg.apic_post_init);
    }
})
#endif


#define SCANNER_FOR_struct_nf_afinfo
#ifndef SCANNER_FOR_struct_nf_afinfo
#define SCANNER_FOR_struct_nf_afinfo
TYPE_SCAN_WRAPPER(struct nf_afinfo, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct nf_afinfo);
    }
    SCAN {
        S(kern_printk( "struct nf_afinfo\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.family);
        SCAN_FUNCTION(arg.checksum);
        SCAN_FUNCTION(arg.checksum_partial);
        SCAN_FUNCTION(arg.route);
        SCAN_FUNCTION(arg.saveroute);
        SCAN_FUNCTION(arg.reroute);
        SCAN_FUNCTION(arg.route_key_size);
    }
})
#endif


#define SCANNER_FOR_struct_hrtimer_sleeper
#ifndef SCANNER_FOR_struct_hrtimer_sleeper
#define SCANNER_FOR_struct_hrtimer_sleeper
TYPE_SCAN_WRAPPER(struct hrtimer_sleeper, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct hrtimer_sleeper);
    }
    SCAN {
        S(kern_printk( "struct hrtimer_sleeper\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.timer);
        SCAN_RECURSIVE_PTR(arg.task);
    }
})
#endif


#define SCANNER_FOR_struct_inet_frag_queue
#ifndef SCANNER_FOR_struct_inet_frag_queue
#define SCANNER_FOR_struct_inet_frag_queue
TYPE_SCAN_WRAPPER(struct inet_frag_queue, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct inet_frag_queue);
    }
    SCAN {
        S(kern_printk( "struct inet_frag_queue\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_RECURSIVE_PTR(arg.net);
        SCAN_RECURSIVE(arg.lru_list);
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE(arg.refcnt);
        SCAN_RECURSIVE(arg.timer);
        SCAN_RECURSIVE_PTR(arg.fragments);
        SCAN_RECURSIVE_PTR(arg.fragments_tail);
//  Union(union ktime) arg.stamp
        SCAN_FUNCTION(arg.len);
        SCAN_FUNCTION(arg.meat);
        SCAN_FUNCTION(arg.last_in);
        SCAN_FUNCTION(arg.max_size);
    }
})
#endif


#define SCANNER_FOR_struct___wait_queue
#ifndef SCANNER_FOR_struct___wait_queue
#define SCANNER_FOR_struct___wait_queue
TYPE_SCAN_WRAPPER(struct __wait_queue, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct __wait_queue);
    }
    SCAN {
        S(kern_printk( "struct __wait_queue\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.private_);
        SCAN_FUNCTION(arg.func);
        SCAN_RECURSIVE(arg.task_list);
    }
})
#endif


#define SCANNER_FOR_struct_poll_table_entry
#ifndef SCANNER_FOR_struct_poll_table_entry
#define SCANNER_FOR_struct_poll_table_entry
TYPE_SCAN_WRAPPER(struct poll_table_entry, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct poll_table_entry);
    }
    SCAN {
        S(kern_printk( "struct poll_table_entry\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.filp);
        SCAN_FUNCTION(arg.key);
        SCAN_RECURSIVE(arg.wait);
        SCAN_RECURSIVE_PTR(arg.wait_address);
    }
})
#endif


#define SCANNER_FOR_struct_poll_wqueues
#ifndef SCANNER_FOR_struct_poll_wqueues
#define SCANNER_FOR_struct_poll_wqueues
TYPE_SCAN_WRAPPER(struct poll_wqueues, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct poll_wqueues);
    }
    SCAN {
        S(kern_printk( "struct poll_wqueues\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.pt);
        SCAN_RECURSIVE_PTR(arg.table);
        SCAN_RECURSIVE_PTR(arg.polling_task);
        SCAN_FUNCTION(arg.triggered);
        SCAN_FUNCTION(arg.error);
        SCAN_FUNCTION(arg.inline_index);
//  Array(Use(Struct(struct poll_table_entry))) arg.inline_entries
    }
})
#endif


#define SCANNER_FOR_struct_dev_ext_attribute
#ifndef SCANNER_FOR_struct_dev_ext_attribute
#define SCANNER_FOR_struct_dev_ext_attribute
TYPE_SCAN_WRAPPER(struct dev_ext_attribute, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dev_ext_attribute);
    }
    SCAN {
        S(kern_printk( "struct dev_ext_attribute\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.attr);
        SCAN_FUNCTION(arg.var);
    }
})
#endif


#define SCANNER_FOR_struct_pv_apic_ops
#ifndef SCANNER_FOR_struct_pv_apic_ops
#define SCANNER_FOR_struct_pv_apic_ops
TYPE_SCAN_WRAPPER(struct pv_apic_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pv_apic_ops);
    }
    SCAN {
        S(kern_printk( "struct pv_apic_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.startup_ipi_hook);
    }
})
#endif


#define SCANNER_FOR_struct_atomic_notifier_head
#ifndef SCANNER_FOR_struct_atomic_notifier_head
#define SCANNER_FOR_struct_atomic_notifier_head
TYPE_SCAN_WRAPPER(struct atomic_notifier_head, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct atomic_notifier_head);
    }
    SCAN {
        S(kern_printk( "struct atomic_notifier_head\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE_PTR(arg.head);
    }
})
#endif


#define SCANNER_FOR_struct_inet_connection_sock_af_ops
#ifndef SCANNER_FOR_struct_inet_connection_sock_af_ops
#define SCANNER_FOR_struct_inet_connection_sock_af_ops
TYPE_SCAN_WRAPPER(struct inet_connection_sock_af_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct inet_connection_sock_af_ops);
    }
    SCAN {
        S(kern_printk( "struct inet_connection_sock_af_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.queue_xmit);
        SCAN_FUNCTION(arg.send_check);
        SCAN_FUNCTION(arg.rebuild_header);
        SCAN_FUNCTION(arg.sk_rx_dst_set);
        SCAN_FUNCTION(arg.conn_request);
        SCAN_FUNCTION(arg.syn_recv_sock);
        SCAN_FUNCTION(arg.net_header_len);
        SCAN_FUNCTION(arg.net_frag_header_len);
        SCAN_FUNCTION(arg.sockaddr_len);
        SCAN_FUNCTION(arg.setsockopt);
        SCAN_FUNCTION(arg.getsockopt);
        SCAN_FUNCTION(arg.compat_setsockopt);
        SCAN_FUNCTION(arg.compat_getsockopt);
        SCAN_FUNCTION(arg.addr2sockaddr);
        SCAN_FUNCTION(arg.bind_conflict);
    }
})
#endif


#define SCANNER_FOR_struct_tree_descr
#ifndef SCANNER_FOR_struct_tree_descr
#define SCANNER_FOR_struct_tree_descr
TYPE_SCAN_WRAPPER(struct tree_descr, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tree_descr);
    }
    SCAN {
        S(kern_printk( "struct tree_descr\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE_PTR(arg.ops);
        SCAN_FUNCTION(arg.mode);
    }
})
#endif


#define SCANNER_FOR_struct_restart_block
#ifndef SCANNER_FOR_struct_restart_block
#define SCANNER_FOR_struct_restart_block
TYPE_SCAN_WRAPPER(struct restart_block, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct restart_block);
    }
    SCAN {
        S(kern_printk( "struct restart_block\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.fn);
//  Union(union anon_union_74) None
    }
})
#endif


#define SCANNER_FOR_struct_napi_gro_cb
#ifndef SCANNER_FOR_struct_napi_gro_cb
#define SCANNER_FOR_struct_napi_gro_cb
TYPE_SCAN_WRAPPER(struct napi_gro_cb, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct napi_gro_cb);
    }
    SCAN {
        S(kern_printk( "struct napi_gro_cb\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.frag0);
        SCAN_FUNCTION(arg.frag0_len);
        SCAN_FUNCTION(arg.data_offset);
        SCAN_FUNCTION(arg.flush);
        SCAN_FUNCTION(arg.count);
        SCAN_FUNCTION(arg.same_flow);
        SCAN_FUNCTION(arg.free);
        SCAN_FUNCTION(arg.age);
        SCAN_FUNCTION(arg.proto);
        SCAN_RECURSIVE_PTR(arg.last);
    }
})
#endif


#define SCANNER_FOR_struct_inet_request_sock
#ifndef SCANNER_FOR_struct_inet_request_sock
#define SCANNER_FOR_struct_inet_request_sock
TYPE_SCAN_WRAPPER(struct inet_request_sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct inet_request_sock);
    }
    SCAN {
        S(kern_printk( "struct inet_request_sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.req);
        SCAN_FUNCTION(arg.inet6_rsk_offset);
        SCAN_FUNCTION(arg.loc_port);
        SCAN_FUNCTION(arg.loc_addr);
        SCAN_FUNCTION(arg.rmt_addr);
        SCAN_FUNCTION(arg.rmt_port);
//  Bitfield(Use(TypeDef(u16, Attributed(unsigned , BuiltIn(short))))) arg.snd_wscale
//  Bitfield(Use(TypeDef(u16, Attributed(unsigned , BuiltIn(short))))) arg.rcv_wscale
//  Bitfield(Use(TypeDef(u16, Attributed(unsigned , BuiltIn(short))))) arg.tstamp_ok
//  Bitfield(Use(TypeDef(u16, Attributed(unsigned , BuiltIn(short))))) arg.sack_ok
//  Bitfield(Use(TypeDef(u16, Attributed(unsigned , BuiltIn(short))))) arg.wscale_ok
//  Bitfield(Use(TypeDef(u16, Attributed(unsigned , BuiltIn(short))))) arg.ecn_ok
//  Bitfield(Use(TypeDef(u16, Attributed(unsigned , BuiltIn(short))))) arg.acked
//  Bitfield(Use(TypeDef(u16, Attributed(unsigned , BuiltIn(short))))) arg.no_srccheck
        SCAN_RECURSIVE_PTR(arg.opt);
    }
})
#endif


#define SCANNER_FOR_struct_tcp_request_sock
#ifndef SCANNER_FOR_struct_tcp_request_sock
#define SCANNER_FOR_struct_tcp_request_sock
TYPE_SCAN_WRAPPER(struct tcp_request_sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tcp_request_sock);
    }
    SCAN {
        S(kern_printk( "struct tcp_request_sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.req);
        SCAN_RECURSIVE_PTR(arg.af_specific);
        SCAN_RECURSIVE_PTR(arg.listener);
        SCAN_FUNCTION(arg.rcv_isn);
        SCAN_FUNCTION(arg.snt_isn);
        SCAN_FUNCTION(arg.snt_synack);
        SCAN_FUNCTION(arg.rcv_nxt);
    }
})
#endif


#define SCANNER_FOR_struct_fastopen_queue
#ifndef SCANNER_FOR_struct_fastopen_queue
#define SCANNER_FOR_struct_fastopen_queue
TYPE_SCAN_WRAPPER(struct fastopen_queue, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct fastopen_queue);
    }
    SCAN {
        S(kern_printk( "struct fastopen_queue\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.rskq_rst_head);
        SCAN_RECURSIVE_PTR(arg.rskq_rst_tail);
        SCAN_RECURSIVE(arg.lock);
        SCAN_FUNCTION(arg.qlen);
        SCAN_FUNCTION(arg.max_qlen);
    }
})
#endif


#define SCANNER_FOR_struct_request_sock_queue
#ifndef SCANNER_FOR_struct_request_sock_queue
#define SCANNER_FOR_struct_request_sock_queue
TYPE_SCAN_WRAPPER(struct request_sock_queue, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct request_sock_queue);
    }
    SCAN {
        S(kern_printk( "struct request_sock_queue\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.rskq_accept_head);
        SCAN_RECURSIVE_PTR(arg.rskq_accept_tail);
        SCAN_RECURSIVE(arg.syn_wait_lock);
        SCAN_FUNCTION(arg.rskq_defer_accept);
        SCAN_RECURSIVE_PTR(arg.listen_opt);
        SCAN_RECURSIVE_PTR(arg.fastopenq);
    }
})
#endif


#define SCANNER_FOR_struct_inet_connection_sock
#ifndef SCANNER_FOR_struct_inet_connection_sock
#define SCANNER_FOR_struct_inet_connection_sock
TYPE_SCAN_WRAPPER(struct inet_connection_sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct inet_connection_sock);
    }
    SCAN {
        S(kern_printk( "struct inet_connection_sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.icsk_inet);
        SCAN_RECURSIVE(arg.icsk_accept_queue);
        SCAN_RECURSIVE_PTR(arg.icsk_bind_hash);
        SCAN_FUNCTION(arg.icsk_timeout);
        SCAN_RECURSIVE(arg.icsk_retransmit_timer);
        SCAN_RECURSIVE(arg.icsk_delack_timer);
        SCAN_FUNCTION(arg.icsk_rto);
        SCAN_FUNCTION(arg.icsk_pmtu_cookie);
        SCAN_RECURSIVE_PTR(arg.icsk_ca_ops);
        SCAN_RECURSIVE_PTR(arg.icsk_af_ops);
        SCAN_FUNCTION(arg.icsk_sync_mss);
        SCAN_FUNCTION(arg.icsk_ca_state);
        SCAN_FUNCTION(arg.icsk_retransmits);
        SCAN_FUNCTION(arg.icsk_pending);
        SCAN_FUNCTION(arg.icsk_backoff);
        SCAN_FUNCTION(arg.icsk_syn_retries);
        SCAN_FUNCTION(arg.icsk_probes_out);
        SCAN_FUNCTION(arg.icsk_ext_hdr_len);
        SCAN_RECURSIVE(arg.icsk_ack);
        SCAN_RECURSIVE(arg.icsk_mtup);
//  Array(Use(TypeDef(u32, Attributed(unsigned , BuiltIn(int))))) arg.icsk_ca_priv
        SCAN_FUNCTION(arg.icsk_user_timeout);
    }
})
#endif


#define SCANNER_FOR_struct_dma_async_tx_descriptor
#ifndef SCANNER_FOR_struct_dma_async_tx_descriptor
#define SCANNER_FOR_struct_dma_async_tx_descriptor
TYPE_SCAN_WRAPPER(struct dma_async_tx_descriptor, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dma_async_tx_descriptor);
    }
    SCAN {
        S(kern_printk( "struct dma_async_tx_descriptor\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.cookie);
//  Enum(enum dma_ctrl_flags) arg.flags
        SCAN_FUNCTION(arg.phys);
        SCAN_RECURSIVE_PTR(arg.chan);
        SCAN_FUNCTION(arg.tx_submit);
        SCAN_FUNCTION(arg.callback);
        SCAN_FUNCTION(arg.callback_param);
    }
})
#endif


#define SCANNER_FOR_struct_dma_device
#ifndef SCANNER_FOR_struct_dma_device
#define SCANNER_FOR_struct_dma_device
TYPE_SCAN_WRAPPER(struct dma_device, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dma_device);
    }
    SCAN {
        S(kern_printk( "struct dma_device\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.chancnt);
        SCAN_FUNCTION(arg.privatecnt);
        SCAN_RECURSIVE(arg.channels);
        SCAN_RECURSIVE(arg.global_node);
        SCAN_RECURSIVE(arg.cap_mask);
        SCAN_FUNCTION(arg.max_xor);
        SCAN_FUNCTION(arg.max_pq);
        SCAN_FUNCTION(arg.copy_align);
        SCAN_FUNCTION(arg.xor_align);
        SCAN_FUNCTION(arg.pq_align);
        SCAN_FUNCTION(arg.fill_align);
        SCAN_FUNCTION(arg.dev_id);
        SCAN_RECURSIVE_PTR(arg.dev);
        SCAN_FUNCTION(arg.device_alloc_chan_resources);
        SCAN_FUNCTION(arg.device_free_chan_resources);
        SCAN_FUNCTION(arg.device_prep_dma_memcpy);
        SCAN_FUNCTION(arg.device_prep_dma_xor);
        SCAN_FUNCTION(arg.device_prep_dma_xor_val);
        SCAN_FUNCTION(arg.device_prep_dma_pq);
        SCAN_FUNCTION(arg.device_prep_dma_pq_val);
        SCAN_FUNCTION(arg.device_prep_dma_memset);
        SCAN_FUNCTION(arg.device_prep_dma_interrupt);
        SCAN_FUNCTION(arg.device_prep_dma_sg);
        SCAN_FUNCTION(arg.device_prep_slave_sg);
        SCAN_FUNCTION(arg.device_prep_dma_cyclic);
        SCAN_FUNCTION(arg.device_prep_interleaved_dma);
        SCAN_FUNCTION(arg.device_control);
        SCAN_FUNCTION(arg.device_tx_status);
        SCAN_FUNCTION(arg.device_issue_pending);
    }
})
#endif


#define SCANNER_FOR_struct_dma_chan_dev
#ifndef SCANNER_FOR_struct_dma_chan_dev
#define SCANNER_FOR_struct_dma_chan_dev
TYPE_SCAN_WRAPPER(struct dma_chan_dev, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dma_chan_dev);
    }
    SCAN {
        S(kern_printk( "struct dma_chan_dev\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.chan);
        SCAN_RECURSIVE(arg.device);
        SCAN_FUNCTION(arg.dev_id);
        SCAN_RECURSIVE_PTR(arg.idr_ref);
    }
})
#endif


#define SCANNER_FOR_struct_dma_chan
#ifndef SCANNER_FOR_struct_dma_chan
#define SCANNER_FOR_struct_dma_chan
TYPE_SCAN_WRAPPER(struct dma_chan, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dma_chan);
    }
    SCAN {
        S(kern_printk( "struct dma_chan\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.device);
        SCAN_FUNCTION(arg.cookie);
        SCAN_FUNCTION(arg.completed_cookie);
        SCAN_FUNCTION(arg.chan_id);
        SCAN_RECURSIVE_PTR(arg.dev);
        SCAN_RECURSIVE(arg.device_node);
        SCAN_RECURSIVE_PTR(arg.local);
        SCAN_FUNCTION(arg.client_count);
        SCAN_FUNCTION(arg.table_count);
        SCAN_FUNCTION(arg.private_);
    }
})
#endif


#define SCANNER_FOR_struct_dma_page_list
#ifndef SCANNER_FOR_struct_dma_page_list
#define SCANNER_FOR_struct_dma_page_list
TYPE_SCAN_WRAPPER(struct dma_page_list, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dma_page_list);
    }
    SCAN {
        S(kern_printk( "struct dma_page_list\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.base_address);
        SCAN_FUNCTION(arg.nr_pages);
//  Pointer(Pointer(Use(Struct(struct page)))) arg.pages
    }
})
#endif


#define SCANNER_FOR_struct_tcp_sock
#ifndef SCANNER_FOR_struct_tcp_sock
#define SCANNER_FOR_struct_tcp_sock
TYPE_SCAN_WRAPPER(struct tcp_sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tcp_sock);
    }
    SCAN {
        S(kern_printk( "struct tcp_sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.inet_conn);
        SCAN_FUNCTION(arg.tcp_header_len);
        SCAN_FUNCTION(arg.xmit_size_goal_segs);
        SCAN_FUNCTION(arg.pred_flags);
        SCAN_FUNCTION(arg.rcv_nxt);
        SCAN_FUNCTION(arg.copied_seq);
        SCAN_FUNCTION(arg.rcv_wup);
        SCAN_FUNCTION(arg.snd_nxt);
        SCAN_FUNCTION(arg.snd_una);
        SCAN_FUNCTION(arg.snd_sml);
        SCAN_FUNCTION(arg.rcv_tstamp);
        SCAN_FUNCTION(arg.lsndtime);
        SCAN_RECURSIVE(arg.tsq_node);
        SCAN_FUNCTION(arg.tsq_flags);
        SCAN_RECURSIVE(arg.ucopy);
        SCAN_FUNCTION(arg.snd_wl1);
        SCAN_FUNCTION(arg.snd_wnd);
        SCAN_FUNCTION(arg.max_window);
        SCAN_FUNCTION(arg.mss_cache);
        SCAN_FUNCTION(arg.window_clamp);
        SCAN_FUNCTION(arg.rcv_ssthresh);
        SCAN_FUNCTION(arg.frto_highmark);
        SCAN_FUNCTION(arg.advmss);
        SCAN_FUNCTION(arg.frto_counter);
//  Bitfield(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.nonagle
//  Bitfield(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.thin_lto
//  Bitfield(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.thin_dupack
//  Bitfield(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.repair
//  Bitfield(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.unused
        SCAN_FUNCTION(arg.repair_queue);
//  Bitfield(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.do_early_retrans
//  Bitfield(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.early_retrans_delayed
//  Bitfield(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.syn_data
//  Bitfield(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.syn_fastopen
//  Bitfield(Use(TypeDef(u8, Attributed(unsigned , BuiltIn(char))))) arg.syn_data_acked
        SCAN_FUNCTION(arg.srtt);
        SCAN_FUNCTION(arg.mdev);
        SCAN_FUNCTION(arg.mdev_max);
        SCAN_FUNCTION(arg.rttvar);
        SCAN_FUNCTION(arg.rtt_seq);
        SCAN_FUNCTION(arg.packets_out);
        SCAN_FUNCTION(arg.retrans_out);
        SCAN_FUNCTION(arg.urg_data);
        SCAN_FUNCTION(arg.ecn_flags);
        SCAN_FUNCTION(arg.reordering);
        SCAN_FUNCTION(arg.snd_up);
        SCAN_FUNCTION(arg.keepalive_probes);
        SCAN_RECURSIVE(arg.rx_opt);
        SCAN_FUNCTION(arg.snd_ssthresh);
        SCAN_FUNCTION(arg.snd_cwnd);
        SCAN_FUNCTION(arg.snd_cwnd_cnt);
        SCAN_FUNCTION(arg.snd_cwnd_clamp);
        SCAN_FUNCTION(arg.snd_cwnd_used);
        SCAN_FUNCTION(arg.snd_cwnd_stamp);
        SCAN_FUNCTION(arg.prior_cwnd);
        SCAN_FUNCTION(arg.prr_delivered);
        SCAN_FUNCTION(arg.prr_out);
        SCAN_FUNCTION(arg.rcv_wnd);
        SCAN_FUNCTION(arg.write_seq);
        SCAN_FUNCTION(arg.pushed_seq);
        SCAN_FUNCTION(arg.lost_out);
        SCAN_FUNCTION(arg.sacked_out);
        SCAN_FUNCTION(arg.fackets_out);
        SCAN_FUNCTION(arg.tso_deferred);
        SCAN_FUNCTION(arg.bytes_acked);
        SCAN_RECURSIVE_PTR(arg.lost_skb_hint);
        SCAN_RECURSIVE_PTR(arg.scoreboard_skb_hint);
        SCAN_RECURSIVE_PTR(arg.retransmit_skb_hint);
        SCAN_RECURSIVE(arg.out_of_order_queue);
//  Array(Use(Struct(struct tcp_sack_block))) arg.duplicate_sack
//  Array(Use(Struct(struct tcp_sack_block))) arg.selective_acks
//  Array(Use(Struct(struct tcp_sack_block))) arg.recv_sack_cache
        SCAN_RECURSIVE_PTR(arg.highest_sack);
        SCAN_FUNCTION(arg.lost_cnt_hint);
        SCAN_FUNCTION(arg.retransmit_high);
        SCAN_FUNCTION(arg.lost_retrans_low);
        SCAN_FUNCTION(arg.prior_ssthresh);
        SCAN_FUNCTION(arg.high_seq);
        SCAN_FUNCTION(arg.retrans_stamp);
        SCAN_FUNCTION(arg.undo_marker);
        SCAN_FUNCTION(arg.undo_retrans);
        SCAN_FUNCTION(arg.total_retrans);
        SCAN_FUNCTION(arg.urg_seq);
        SCAN_FUNCTION(arg.keepalive_time);
        SCAN_FUNCTION(arg.keepalive_intvl);
        SCAN_FUNCTION(arg.linger2);
        SCAN_RECURSIVE(arg.rcv_rtt_est);
        SCAN_RECURSIVE(arg.rcvq_space);
        SCAN_RECURSIVE(arg.mtu_probe);
        SCAN_FUNCTION(arg.mtu_info);
        SCAN_RECURSIVE_PTR(arg.af_specific);
        SCAN_RECURSIVE_PTR(arg.md5sig_info);
        SCAN_RECURSIVE_PTR(arg.cookie_values);
        SCAN_RECURSIVE_PTR(arg.fastopen_req);
        SCAN_RECURSIVE_PTR(arg.fastopen_rsk);
    }
})
#endif


#define SCANNER_FOR_struct_inet_frags
#ifndef SCANNER_FOR_struct_inet_frags
#define SCANNER_FOR_struct_inet_frags
TYPE_SCAN_WRAPPER(struct inet_frags, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct inet_frags);
    }
    SCAN {
        S(kern_printk( "struct inet_frags\n");)
        S(SCAN_OBJECT(arg);)
//  Array(Use(Struct(struct hlist_head))) arg.hash
        SCAN_RECURSIVE(arg.lock);
        SCAN_FUNCTION(arg.rnd);
        SCAN_FUNCTION(arg.qsize);
        SCAN_FUNCTION(arg.secret_interval);
        SCAN_RECURSIVE(arg.secret_timer);
        SCAN_FUNCTION(arg.hashfn);
        SCAN_FUNCTION(arg.constructor);
        SCAN_FUNCTION(arg.destructor);
        SCAN_FUNCTION(arg.skb_free);
        SCAN_FUNCTION(arg.match);
        SCAN_FUNCTION(arg.frag_expire);
    }
})
#endif


#define SCANNER_FOR_struct_ff_device
#ifndef SCANNER_FOR_struct_ff_device
#define SCANNER_FOR_struct_ff_device
TYPE_SCAN_WRAPPER(struct ff_device, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ff_device);
    }
    SCAN {
        S(kern_printk( "struct ff_device\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.upload);
        SCAN_FUNCTION(arg.erase);
        SCAN_FUNCTION(arg.playback);
        SCAN_FUNCTION(arg.set_gain);
        SCAN_FUNCTION(arg.set_autocenter);
        SCAN_FUNCTION(arg.destroy);
        SCAN_FUNCTION(arg.private_);
//  Array(Attributed(unsigned , BuiltIn(long))) arg.ffbit
        SCAN_RECURSIVE(arg.mutex);
        SCAN_FUNCTION(arg.max_effects);
        SCAN_RECURSIVE_PTR(arg.effects);
//  Array(Pointer(Use(Struct(struct file)))) arg.effect_owners
    }
})
#endif


#define SCANNER_FOR_struct_input_handler
#ifndef SCANNER_FOR_struct_input_handler
#define SCANNER_FOR_struct_input_handler
TYPE_SCAN_WRAPPER(struct input_handler, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct input_handler);
    }
    SCAN {
        S(kern_printk( "struct input_handler\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.private_);
        SCAN_FUNCTION(arg.event);
        SCAN_FUNCTION(arg.events);
        SCAN_FUNCTION(arg.filter);
        SCAN_FUNCTION(arg.match);
        SCAN_FUNCTION(arg.connect);
        SCAN_FUNCTION(arg.disconnect);
        SCAN_FUNCTION(arg.start);
        SCAN_FUNCTION(arg.legacy_minors);
        SCAN_FUNCTION(arg.minor);
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE_PTR(arg.id_table);
        SCAN_RECURSIVE(arg.h_list);
        SCAN_RECURSIVE(arg.node);
    }
})
#endif


#define SCANNER_FOR_struct_input_handle
#ifndef SCANNER_FOR_struct_input_handle
#define SCANNER_FOR_struct_input_handle
TYPE_SCAN_WRAPPER(struct input_handle, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct input_handle);
    }
    SCAN {
        S(kern_printk( "struct input_handle\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.private_);
        SCAN_FUNCTION(arg.open);
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE_PTR(arg.dev);
        SCAN_RECURSIVE_PTR(arg.handler);
        SCAN_RECURSIVE(arg.d_node);
        SCAN_RECURSIVE(arg.h_node);
    }
})
#endif


#define SCANNER_FOR_struct_input_dev
#ifndef SCANNER_FOR_struct_input_dev
#define SCANNER_FOR_struct_input_dev
TYPE_SCAN_WRAPPER(struct input_dev, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct input_dev);
    }
    SCAN {
        S(kern_printk( "struct input_dev\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_FUNCTION(arg.phys);
        SCAN_FUNCTION(arg.uniq);
        SCAN_RECURSIVE(arg.id);
//  Array(Attributed(unsigned , BuiltIn(long))) arg.propbit
//  Array(Attributed(unsigned , BuiltIn(long))) arg.evbit
//  Array(Attributed(unsigned , BuiltIn(long))) arg.keybit
//  Array(Attributed(unsigned , BuiltIn(long))) arg.relbit
//  Array(Attributed(unsigned , BuiltIn(long))) arg.absbit
//  Array(Attributed(unsigned , BuiltIn(long))) arg.mscbit
//  Array(Attributed(unsigned , BuiltIn(long))) arg.ledbit
//  Array(Attributed(unsigned , BuiltIn(long))) arg.sndbit
//  Array(Attributed(unsigned , BuiltIn(long))) arg.ffbit
//  Array(Attributed(unsigned , BuiltIn(long))) arg.swbit
        SCAN_FUNCTION(arg.hint_events_per_packet);
        SCAN_FUNCTION(arg.keycodemax);
        SCAN_FUNCTION(arg.keycodesize);
        SCAN_FUNCTION(arg.keycode);
        SCAN_FUNCTION(arg.setkeycode);
        SCAN_FUNCTION(arg.getkeycode);
        SCAN_RECURSIVE_PTR(arg.ff);
        SCAN_FUNCTION(arg.repeat_key);
        SCAN_RECURSIVE(arg.timer);
//  Array(BuiltIn(int)) arg.rep
        SCAN_RECURSIVE_PTR(arg.mt);
        SCAN_RECURSIVE_PTR(arg.absinfo);
//  Array(Attributed(unsigned , BuiltIn(long))) arg.key
//  Array(Attributed(unsigned , BuiltIn(long))) arg.led
//  Array(Attributed(unsigned , BuiltIn(long))) arg.snd
//  Array(Attributed(unsigned , BuiltIn(long))) arg.sw
        SCAN_FUNCTION(arg.open);
        SCAN_FUNCTION(arg.close);
        SCAN_FUNCTION(arg.flush);
        SCAN_FUNCTION(arg.event);
        SCAN_RECURSIVE_PTR(arg.grab);
        SCAN_RECURSIVE(arg.event_lock);
        SCAN_RECURSIVE(arg.mutex);
        SCAN_FUNCTION(arg.users);
        SCAN_FUNCTION(arg.going_away);
        SCAN_RECURSIVE(arg.dev);
        SCAN_RECURSIVE(arg.h_list);
        SCAN_RECURSIVE(arg.node);
        SCAN_FUNCTION(arg.num_vals);
        SCAN_FUNCTION(arg.max_vals);
        SCAN_RECURSIVE_PTR(arg.vals);
        SCAN_FUNCTION(arg.devres_managed);
    }
})
#endif


#define SCANNER_FOR_struct_sg_mapping_iter
#ifndef SCANNER_FOR_struct_sg_mapping_iter
#define SCANNER_FOR_struct_sg_mapping_iter
TYPE_SCAN_WRAPPER(struct sg_mapping_iter, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct sg_mapping_iter);
    }
    SCAN {
        S(kern_printk( "struct sg_mapping_iter\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.page);
        SCAN_FUNCTION(arg.addr);
        SCAN_FUNCTION(arg.length);
        SCAN_FUNCTION(arg.consumed);
        SCAN_RECURSIVE_PTR(arg.__sg);
        SCAN_FUNCTION(arg.__nents);
        SCAN_FUNCTION(arg.__offset);
        SCAN_FUNCTION(arg.__flags);
    }
})
#endif


#define SCANNER_FOR_struct_mutex_waiter
#ifndef SCANNER_FOR_struct_mutex_waiter
#define SCANNER_FOR_struct_mutex_waiter
TYPE_SCAN_WRAPPER(struct mutex_waiter, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct mutex_waiter);
    }
    SCAN {
        S(kern_printk( "struct mutex_waiter\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_RECURSIVE_PTR(arg.task);
    }
})
#endif


#define SCANNER_FOR_struct_clocksource
#ifndef SCANNER_FOR_struct_clocksource
#define SCANNER_FOR_struct_clocksource
TYPE_SCAN_WRAPPER(struct clocksource, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct clocksource);
    }
    SCAN {
        S(kern_printk( "struct clocksource\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.read);
        SCAN_FUNCTION(arg.cycle_last);
        SCAN_FUNCTION(arg.mask);
        SCAN_FUNCTION(arg.mult);
        SCAN_FUNCTION(arg.shift);
        SCAN_FUNCTION(arg.max_idle_ns);
        SCAN_FUNCTION(arg.maxadj);
        SCAN_RECURSIVE(arg.archdata);
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE(arg.list);
        SCAN_FUNCTION(arg.rating);
        SCAN_FUNCTION(arg.enable);
        SCAN_FUNCTION(arg.disable);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.suspend);
        SCAN_FUNCTION(arg.resume);
        SCAN_RECURSIVE(arg.wd_list);
        SCAN_FUNCTION(arg.cs_last);
        SCAN_FUNCTION(arg.wd_last);
    }
})
#endif


#define SCANNER_FOR_struct_task_migration_notifier
#ifndef SCANNER_FOR_struct_task_migration_notifier
#define SCANNER_FOR_struct_task_migration_notifier
TYPE_SCAN_WRAPPER(struct task_migration_notifier, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct task_migration_notifier);
    }
    SCAN {
        S(kern_printk( "struct task_migration_notifier\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.task);
        SCAN_FUNCTION(arg.from_cpu);
        SCAN_FUNCTION(arg.to_cpu);
    }
})
#endif


#define SCANNER_FOR_struct_flow_cache_object
#ifndef SCANNER_FOR_struct_flow_cache_object
#define SCANNER_FOR_struct_flow_cache_object
TYPE_SCAN_WRAPPER(struct flow_cache_object, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct flow_cache_object);
    }
    SCAN {
        S(kern_printk( "struct flow_cache_object\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.ops);
    }
})
#endif


#define SCANNER_FOR_struct_flow_cache_ops
#ifndef SCANNER_FOR_struct_flow_cache_ops
#define SCANNER_FOR_struct_flow_cache_ops
TYPE_SCAN_WRAPPER(struct flow_cache_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct flow_cache_ops);
    }
    SCAN {
        S(kern_printk( "struct flow_cache_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.get);
        SCAN_FUNCTION(arg.check);
        SCAN_FUNCTION(arg.delete_);
    }
})
#endif


#define SCANNER_FOR_struct_blk_scsi_cmd_filter
#ifndef SCANNER_FOR_struct_blk_scsi_cmd_filter
#define SCANNER_FOR_struct_blk_scsi_cmd_filter
TYPE_SCAN_WRAPPER(struct blk_scsi_cmd_filter, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct blk_scsi_cmd_filter);
    }
    SCAN {
        S(kern_printk( "struct blk_scsi_cmd_filter\n");)
        S(SCAN_OBJECT(arg);)
//  Array(Attributed(unsigned , BuiltIn(long))) arg.read_ok
//  Array(Attributed(unsigned , BuiltIn(long))) arg.write_ok
        SCAN_RECURSIVE(arg.kobj);
    }
})
#endif


#define SCANNER_FOR_struct_req_iterator
#ifndef SCANNER_FOR_struct_req_iterator
#define SCANNER_FOR_struct_req_iterator
TYPE_SCAN_WRAPPER(struct req_iterator, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct req_iterator);
    }
    SCAN {
        S(kern_printk( "struct req_iterator\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.i);
        SCAN_RECURSIVE_PTR(arg.bio);
    }
})
#endif


#define SCANNER_FOR_struct_acpi_device_dir
#ifndef SCANNER_FOR_struct_acpi_device_dir
#define SCANNER_FOR_struct_acpi_device_dir
TYPE_SCAN_WRAPPER(struct acpi_device_dir, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct acpi_device_dir);
    }
    SCAN {
        S(kern_printk( "struct acpi_device_dir\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.entry);
    }
})
#endif


#define SCANNER_FOR_struct_cgroup_map_cb
#ifndef SCANNER_FOR_struct_cgroup_map_cb
#define SCANNER_FOR_struct_cgroup_map_cb
TYPE_SCAN_WRAPPER(struct cgroup_map_cb, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cgroup_map_cb);
    }
    SCAN {
        S(kern_printk( "struct cgroup_map_cb\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.fill);
        SCAN_FUNCTION(arg.state);
    }
})
#endif


#define SCANNER_FOR_struct_node
#ifndef SCANNER_FOR_struct_node
#define SCANNER_FOR_struct_node
TYPE_SCAN_WRAPPER(struct node, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct node);
    }
    SCAN {
        S(kern_printk( "struct node\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.dev);
        SCAN_RECURSIVE(arg.node_work);
    }
})
#endif


#define SCANNER_FOR_struct_clock_event_device
#ifndef SCANNER_FOR_struct_clock_event_device
#define SCANNER_FOR_struct_clock_event_device
TYPE_SCAN_WRAPPER(struct clock_event_device, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct clock_event_device);
    }
    SCAN {
        S(kern_printk( "struct clock_event_device\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.event_handler);
        SCAN_FUNCTION(arg.set_next_event);
        SCAN_FUNCTION(arg.set_next_ktime);
//  Union(union ktime) arg.next_event
        SCAN_FUNCTION(arg.max_delta_ns);
        SCAN_FUNCTION(arg.min_delta_ns);
        SCAN_FUNCTION(arg.mult);
        SCAN_FUNCTION(arg.shift);
//  Enum(enum clock_event_mode) arg.mode
        SCAN_FUNCTION(arg.features);
        SCAN_FUNCTION(arg.retries);
        SCAN_FUNCTION(arg.broadcast);
        SCAN_FUNCTION(arg.set_mode);
        SCAN_FUNCTION(arg.suspend);
        SCAN_FUNCTION(arg.resume);
        SCAN_FUNCTION(arg.min_delta_ticks);
        SCAN_FUNCTION(arg.max_delta_ticks);
        SCAN_FUNCTION(arg.name);
        SCAN_FUNCTION(arg.rating);
        SCAN_FUNCTION(arg.irq);
        SCAN_RECURSIVE_PTR(arg.cpumask);
        SCAN_RECURSIVE(arg.list);
    }
})
#endif


#define SCANNER_FOR_struct_tick_device
#ifndef SCANNER_FOR_struct_tick_device
#define SCANNER_FOR_struct_tick_device
TYPE_SCAN_WRAPPER(struct tick_device, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tick_device);
    }
    SCAN {
        S(kern_printk( "struct tick_device\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.evtdev);
//  Enum(enum tick_device_mode) arg.mode
    }
})
#endif


#define SCANNER_FOR_struct_ahash_request
#ifndef SCANNER_FOR_struct_ahash_request
#define SCANNER_FOR_struct_ahash_request
TYPE_SCAN_WRAPPER(struct ahash_request, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ahash_request);
    }
    SCAN {
        S(kern_printk( "struct ahash_request\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.base);
        SCAN_FUNCTION(arg.nbytes);
        SCAN_RECURSIVE_PTR(arg.src);
        SCAN_FUNCTION(arg.result);
        SCAN_FUNCTION(arg.priv);
//  Array(Pointer(BuiltIn(void))) arg.__ctx
    }
})
#endif


#define SCANNER_FOR_struct_crypto_ahash
#ifndef SCANNER_FOR_struct_crypto_ahash
#define SCANNER_FOR_struct_crypto_ahash
TYPE_SCAN_WRAPPER(struct crypto_ahash, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct crypto_ahash);
    }
    SCAN {
        S(kern_printk( "struct crypto_ahash\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.init);
        SCAN_FUNCTION(arg.update);
        SCAN_FUNCTION(arg.final);
        SCAN_FUNCTION(arg.finup);
        SCAN_FUNCTION(arg.digest);
        SCAN_FUNCTION(arg.export_);
        SCAN_FUNCTION(arg.import);
        SCAN_FUNCTION(arg.setkey);
        SCAN_FUNCTION(arg.reqsize);
        SCAN_RECURSIVE(arg.base);
    }
})
#endif


#define SCANNER_FOR_struct_raw_notifier_head
#ifndef SCANNER_FOR_struct_raw_notifier_head
#define SCANNER_FOR_struct_raw_notifier_head
TYPE_SCAN_WRAPPER(struct raw_notifier_head, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct raw_notifier_head);
    }
    SCAN {
        S(kern_printk( "struct raw_notifier_head\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.head);
    }
})
#endif


#define SCANNER_FOR_struct_net_proto_family
#ifndef SCANNER_FOR_struct_net_proto_family
#define SCANNER_FOR_struct_net_proto_family
TYPE_SCAN_WRAPPER(struct net_proto_family, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct net_proto_family);
    }
    SCAN {
        S(kern_printk( "struct net_proto_family\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.family);
        SCAN_FUNCTION(arg.create);
        SCAN_RECURSIVE_PTR(arg.owner);
    }
})
#endif


#define SCANNER_FOR_struct_offload_callbacks
#ifndef SCANNER_FOR_struct_offload_callbacks
#define SCANNER_FOR_struct_offload_callbacks
TYPE_SCAN_WRAPPER(struct offload_callbacks, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct offload_callbacks);
    }
    SCAN {
        S(kern_printk( "struct offload_callbacks\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.gso_segment);
        SCAN_FUNCTION(arg.gso_send_check);
        SCAN_FUNCTION(arg.gro_receive);
        SCAN_FUNCTION(arg.gro_complete);
    }
})
#endif


#define SCANNER_FOR_struct_class_attribute_string
#ifndef SCANNER_FOR_struct_class_attribute_string
#define SCANNER_FOR_struct_class_attribute_string
TYPE_SCAN_WRAPPER(struct class_attribute_string, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct class_attribute_string);
    }
    SCAN {
        S(kern_printk( "struct class_attribute_string\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.attr);
        SCAN_FUNCTION(arg.str);
    }
})
#endif


#define SCANNER_FOR_struct_subsys_interface
#ifndef SCANNER_FOR_struct_subsys_interface
#define SCANNER_FOR_struct_subsys_interface
TYPE_SCAN_WRAPPER(struct subsys_interface, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct subsys_interface);
    }
    SCAN {
        S(kern_printk( "struct subsys_interface\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE_PTR(arg.subsys);
        SCAN_RECURSIVE(arg.node);
        SCAN_FUNCTION(arg.add_dev);
        SCAN_FUNCTION(arg.remove_dev);
    }
})
#endif


#define SCANNER_FOR_struct_ubuf_info
#ifndef SCANNER_FOR_struct_ubuf_info
#define SCANNER_FOR_struct_ubuf_info
TYPE_SCAN_WRAPPER(struct ubuf_info, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ubuf_info);
    }
    SCAN {
        S(kern_printk( "struct ubuf_info\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.callback);
        SCAN_FUNCTION(arg.ctx);
        SCAN_FUNCTION(arg.desc);
    }
})
#endif


#define SCANNER_FOR_struct_disk_part_iter
#ifndef SCANNER_FOR_struct_disk_part_iter
#define SCANNER_FOR_struct_disk_part_iter
TYPE_SCAN_WRAPPER(struct disk_part_iter, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct disk_part_iter);
    }
    SCAN {
        S(kern_printk( "struct disk_part_iter\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.disk);
        SCAN_RECURSIVE_PTR(arg.part);
        SCAN_FUNCTION(arg.idx);
        SCAN_FUNCTION(arg.flags);
    }
})
#endif


#define SCANNER_FOR_struct_idr_layer
#ifndef SCANNER_FOR_struct_idr_layer
#define SCANNER_FOR_struct_idr_layer
TYPE_SCAN_WRAPPER(struct idr_layer, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct idr_layer);
    }
    SCAN {
        S(kern_printk( "struct idr_layer\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.bitmap);
//  Array(Pointer(Use(Struct(struct idr_layer)))) arg.ary
        SCAN_FUNCTION(arg.count);
        SCAN_FUNCTION(arg.layer);
        SCAN_RECURSIVE(arg.callback_head);
    }
})
#endif


#define SCANNER_FOR_struct_idr
#ifndef SCANNER_FOR_struct_idr
#define SCANNER_FOR_struct_idr
TYPE_SCAN_WRAPPER(struct idr, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct idr);
    }
    SCAN {
        S(kern_printk( "struct idr\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.top);
        SCAN_RECURSIVE_PTR(arg.id_free);
        SCAN_FUNCTION(arg.layers);
        SCAN_FUNCTION(arg.id_free_cnt);
        SCAN_RECURSIVE(arg.lock);
    }
})
#endif


#define SCANNER_FOR_struct_cftype
#ifndef SCANNER_FOR_struct_cftype
#define SCANNER_FOR_struct_cftype
TYPE_SCAN_WRAPPER(struct cftype, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cftype);
    }
    SCAN {
        S(kern_printk( "struct cftype\n");)
        S(SCAN_OBJECT(arg);)
//  Array(BuiltIn(char)) arg.name
        SCAN_FUNCTION(arg.private_);
        SCAN_FUNCTION(arg.mode);
        SCAN_FUNCTION(arg.max_write_len);
        SCAN_FUNCTION(arg.flags);
        SCAN_RECURSIVE(arg.xattrs);
        SCAN_FUNCTION(arg.open);
        SCAN_FUNCTION(arg.read);
        SCAN_FUNCTION(arg.read_u64);
        SCAN_FUNCTION(arg.read_s64);
        SCAN_FUNCTION(arg.read_map);
        SCAN_FUNCTION(arg.read_seq_string);
        SCAN_FUNCTION(arg.write);
        SCAN_FUNCTION(arg.write_u64);
        SCAN_FUNCTION(arg.write_s64);
        SCAN_FUNCTION(arg.write_string);
        SCAN_FUNCTION(arg.trigger);
        SCAN_FUNCTION(arg.release);
        SCAN_FUNCTION(arg.register_event);
        SCAN_FUNCTION(arg.unregister_event);
    }
})
#endif


#define SCANNER_FOR_struct_cftype_set
#ifndef SCANNER_FOR_struct_cftype_set
#define SCANNER_FOR_struct_cftype_set
TYPE_SCAN_WRAPPER(struct cftype_set, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cftype_set);
    }
    SCAN {
        S(kern_printk( "struct cftype_set\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.node);
        SCAN_RECURSIVE_PTR(arg.cfts);
    }
})
#endif


#define SCANNER_FOR_struct_cgroup_subsys
#ifndef SCANNER_FOR_struct_cgroup_subsys
#define SCANNER_FOR_struct_cgroup_subsys
TYPE_SCAN_WRAPPER(struct cgroup_subsys, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cgroup_subsys);
    }
    SCAN {
        S(kern_printk( "struct cgroup_subsys\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.css_alloc);
        SCAN_FUNCTION(arg.css_online);
        SCAN_FUNCTION(arg.css_offline);
        SCAN_FUNCTION(arg.css_free);
        SCAN_FUNCTION(arg.can_attach);
        SCAN_FUNCTION(arg.cancel_attach);
        SCAN_FUNCTION(arg.attach);
        SCAN_FUNCTION(arg.fork);
        SCAN_FUNCTION(arg.exit);
        SCAN_FUNCTION(arg.bind);
        SCAN_FUNCTION(arg.subsys_id);
        SCAN_FUNCTION(arg.active);
        SCAN_FUNCTION(arg.disabled);
        SCAN_FUNCTION(arg.early_init);
        SCAN_FUNCTION(arg.use_id);
        SCAN_FUNCTION(arg.broken_hierarchy);
        SCAN_FUNCTION(arg.warned_broken_hierarchy);
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE_PTR(arg.root);
        SCAN_RECURSIVE(arg.sibling);
        SCAN_RECURSIVE(arg.idr);
        SCAN_RECURSIVE(arg.id_lock);
        SCAN_RECURSIVE(arg.cftsets);
        SCAN_RECURSIVE_PTR(arg.base_cftypes);
        SCAN_RECURSIVE(arg.base_cftset);
        SCAN_RECURSIVE_PTR(arg.module);
    }
})
#endif


#define SCANNER_FOR_struct_acpi_device_ops
#ifndef SCANNER_FOR_struct_acpi_device_ops
#define SCANNER_FOR_struct_acpi_device_ops
TYPE_SCAN_WRAPPER(struct acpi_device_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct acpi_device_ops);
    }
    SCAN {
        S(kern_printk( "struct acpi_device_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.add);
        SCAN_FUNCTION(arg.remove);
        SCAN_FUNCTION(arg.start);
        SCAN_FUNCTION(arg.bind);
        SCAN_FUNCTION(arg.unbind);
        SCAN_FUNCTION(arg.notify);
    }
})
#endif


#define SCANNER_FOR_struct_acpi_driver
#ifndef SCANNER_FOR_struct_acpi_driver
#define SCANNER_FOR_struct_acpi_driver
TYPE_SCAN_WRAPPER(struct acpi_driver, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct acpi_driver);
    }
    SCAN {
        S(kern_printk( "struct acpi_driver\n");)
        S(SCAN_OBJECT(arg);)
//  Array(BuiltIn(char)) arg.name
//  Array(BuiltIn(char)) arg.class_
        SCAN_RECURSIVE_PTR(arg.ids);
        SCAN_FUNCTION(arg.flags);
        SCAN_RECURSIVE(arg.ops);
        SCAN_RECURSIVE(arg.drv);
        SCAN_RECURSIVE_PTR(arg.owner);
    }
})
#endif


#define SCANNER_FOR_struct_acpi_device
#ifndef SCANNER_FOR_struct_acpi_device
#define SCANNER_FOR_struct_acpi_device
TYPE_SCAN_WRAPPER(struct acpi_device, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct acpi_device);
    }
    SCAN {
        S(kern_printk( "struct acpi_device\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.device_type);
        SCAN_FUNCTION(arg.handle);
        SCAN_RECURSIVE_PTR(arg.parent);
        SCAN_RECURSIVE(arg.children);
        SCAN_RECURSIVE(arg.node);
        SCAN_RECURSIVE(arg.wakeup_list);
        SCAN_RECURSIVE(arg.status);
        SCAN_RECURSIVE(arg.flags);
        SCAN_RECURSIVE(arg.pnp);
        SCAN_RECURSIVE(arg.power);
        SCAN_RECURSIVE(arg.wakeup);
        SCAN_RECURSIVE(arg.performance);
        SCAN_RECURSIVE(arg.dir);
        SCAN_RECURSIVE(arg.ops);
        SCAN_RECURSIVE_PTR(arg.driver);
        SCAN_FUNCTION(arg.driver_data);
        SCAN_RECURSIVE(arg.dev);
        SCAN_RECURSIVE(arg.bus_ops);
//  Enum(enum acpi_bus_removal_type) arg.removal_type
        SCAN_FUNCTION(arg.physical_node_count);
        SCAN_RECURSIVE(arg.physical_node_list);
        SCAN_RECURSIVE(arg.physical_node_lock);
//  Array(Attributed(unsigned , BuiltIn(long))) arg.physical_node_id_bitmap
    }
})
#endif


#define SCANNER_FOR_struct_acpi_pci_root
#ifndef SCANNER_FOR_struct_acpi_pci_root
#define SCANNER_FOR_struct_acpi_pci_root
TYPE_SCAN_WRAPPER(struct acpi_pci_root, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct acpi_pci_root);
    }
    SCAN {
        S(kern_printk( "struct acpi_pci_root\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.node);
        SCAN_RECURSIVE_PTR(arg.device);
        SCAN_RECURSIVE(arg.id);
        SCAN_RECURSIVE_PTR(arg.bus);
        SCAN_FUNCTION(arg.segment);
        SCAN_RECURSIVE(arg.secondary);
        SCAN_FUNCTION(arg.osc_support_set);
        SCAN_FUNCTION(arg.osc_control_set);
        SCAN_FUNCTION(arg.mcfg_addr);
    }
})
#endif


#define SCANNER_FOR_struct_ip_options_data
#ifndef SCANNER_FOR_struct_ip_options_data
#define SCANNER_FOR_struct_ip_options_data
TYPE_SCAN_WRAPPER(struct ip_options_data, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ip_options_data);
    }
    SCAN {
        S(kern_printk( "struct ip_options_data\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.opt);
//  Array(BuiltIn(char)) arg.data
    }
})
#endif


//#define SCANNER_FOR_struct_napi_struct
#ifndef SCANNER_FOR_struct_napi_struct
#define SCANNER_FOR_struct_napi_struct
TYPE_SCAN_WRAPPER(struct napi_struct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct napi_struct);
    }
    SCAN {
        S(kern_printk( "struct napi_struct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.poll_list);
        SCAN_FUNCTION(arg.state);
        SCAN_FUNCTION(arg.weight);
        SCAN_FUNCTION(arg.gro_count);
        SCAN_FUNCTION(arg.poll);
        SCAN_RECURSIVE(arg.poll_lock);
        SCAN_FUNCTION(arg.poll_owner);
        SCAN_RECURSIVE_PTR(arg.dev);
        SCAN_RECURSIVE_PTR(arg.gro_list);
        SCAN_RECURSIVE_PTR(arg.skb);
        SCAN_RECURSIVE(arg.dev_list);
    }
})
#endif


//#define SCANNER_FOR_struct_pv_lock_ops
#ifndef SCANNER_FOR_struct_pv_lock_ops
#define SCANNER_FOR_struct_pv_lock_ops
TYPE_SCAN_WRAPPER(struct pv_lock_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pv_lock_ops);
    }
    SCAN {
        S(kern_printk( "struct pv_lock_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.spin_is_locked);
        SCAN_FUNCTION(arg.spin_is_contended);
        SCAN_FUNCTION(arg.spin_lock);
        SCAN_FUNCTION(arg.spin_lock_flags);
        SCAN_FUNCTION(arg.spin_trylock);
        SCAN_FUNCTION(arg.spin_unlock);
    }
})
#endif


//#define SCANNER_FOR_struct_pci_host_bridge
#ifndef SCANNER_FOR_struct_pci_host_bridge
#define SCANNER_FOR_struct_pci_host_bridge
TYPE_SCAN_WRAPPER(struct pci_host_bridge, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pci_host_bridge);
    }
    SCAN {
        S(kern_printk( "struct pci_host_bridge\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.dev);
        SCAN_RECURSIVE_PTR(arg.bus);
        SCAN_RECURSIVE(arg.windows);
        SCAN_FUNCTION(arg.release_fn);
        SCAN_FUNCTION(arg.release_data);
    }
})
#endif


//#define SCANNER_FOR_struct_x86_init_paging
#ifndef SCANNER_FOR_struct_x86_init_paging
#define SCANNER_FOR_struct_x86_init_paging
TYPE_SCAN_WRAPPER(struct x86_init_paging, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct x86_init_paging);
    }
    SCAN {
        S(kern_printk( "struct x86_init_paging\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.pagetable_init);
    }
})
#endif


//#define SCANNER_FOR_struct_class_interface
#ifndef SCANNER_FOR_struct_class_interface
#define SCANNER_FOR_struct_class_interface
TYPE_SCAN_WRAPPER(struct class_interface, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct class_interface);
    }
    SCAN {
        S(kern_printk( "struct class_interface\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.node);
        SCAN_RECURSIVE_PTR(arg.class_);
        SCAN_FUNCTION(arg.add_dev);
        SCAN_FUNCTION(arg.remove_dev);
    }
})
#endif


//#define SCANNER_FOR_struct_softirq_action
#ifndef SCANNER_FOR_struct_softirq_action
#define SCANNER_FOR_struct_softirq_action
TYPE_SCAN_WRAPPER(struct softirq_action, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct softirq_action);
    }
    SCAN {
        S(kern_printk( "struct softirq_action\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.action);
    }
})
#endif


//#define SCANNER_FOR_struct_mb_cache
#ifndef SCANNER_FOR_struct_mb_cache
#define SCANNER_FOR_struct_mb_cache
TYPE_SCAN_WRAPPER(struct mb_cache, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct mb_cache);
    }
    SCAN {
        S(kern_printk( "struct mb_cache\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.c_cache_list);
        SCAN_FUNCTION(arg.c_name);
        SCAN_RECURSIVE(arg.c_entry_count);
        SCAN_FUNCTION(arg.c_max_entries);
        SCAN_FUNCTION(arg.c_bucket_bits);
        SCAN_RECURSIVE_PTR(arg.c_entry_cache);
        SCAN_RECURSIVE_PTR(arg.c_block_hash);
        SCAN_RECURSIVE_PTR(arg.c_index_hash);
    }
})
#endif


//#define SCANNER_FOR_struct_nf_sockopt_ops
#ifndef SCANNER_FOR_struct_nf_sockopt_ops
#define SCANNER_FOR_struct_nf_sockopt_ops
TYPE_SCAN_WRAPPER(struct nf_sockopt_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct nf_sockopt_ops);
    }
    SCAN {
        S(kern_printk( "struct nf_sockopt_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_FUNCTION(arg.pf);
        SCAN_FUNCTION(arg.set_optmin);
        SCAN_FUNCTION(arg.set_optmax);
        SCAN_FUNCTION(arg.set);
        SCAN_FUNCTION(arg.compat_set);
        SCAN_FUNCTION(arg.get_optmin);
        SCAN_FUNCTION(arg.get_optmax);
        SCAN_FUNCTION(arg.get);
        SCAN_FUNCTION(arg.compat_get);
        SCAN_RECURSIVE_PTR(arg.owner);
    }
})
#endif


//#define SCANNER_FOR_struct_ts_config
#ifndef SCANNER_FOR_struct_ts_config
#define SCANNER_FOR_struct_ts_config
TYPE_SCAN_WRAPPER(struct ts_config, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ts_config);
    }
    SCAN {
        S(kern_printk( "struct ts_config\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.ops);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.get_next_block);
        SCAN_FUNCTION(arg.finish);
    }
})
#endif


//#define SCANNER_FOR_struct_ts_ops
#ifndef SCANNER_FOR_struct_ts_ops
#define SCANNER_FOR_struct_ts_ops
TYPE_SCAN_WRAPPER(struct ts_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ts_ops);
    }
    SCAN {
        S(kern_printk( "struct ts_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_FUNCTION(arg.init);
        SCAN_FUNCTION(arg.find);
        SCAN_FUNCTION(arg.destroy);
        SCAN_FUNCTION(arg.get_pattern);
        SCAN_FUNCTION(arg.get_pattern_len);
        SCAN_RECURSIVE_PTR(arg.owner);
        SCAN_RECURSIVE(arg.list);
    }
})
#endif


//#define SCANNER_FOR_struct_pnp_fixup
#ifndef SCANNER_FOR_struct_pnp_fixup
#define SCANNER_FOR_struct_pnp_fixup
TYPE_SCAN_WRAPPER(struct pnp_fixup, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pnp_fixup);
    }
    SCAN {
        S(kern_printk( "struct pnp_fixup\n");)
        S(SCAN_OBJECT(arg);)
//  Array(BuiltIn(char)) arg.id
        SCAN_FUNCTION(arg.quirk_function);
    }
})
#endif


//#define SCANNER_FOR_struct_pv_init_ops
#ifndef SCANNER_FOR_struct_pv_init_ops
#define SCANNER_FOR_struct_pv_init_ops
TYPE_SCAN_WRAPPER(struct pv_init_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pv_init_ops);
    }
    SCAN {
        S(kern_printk( "struct pv_init_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.patch);
    }
})
#endif


//#define SCANNER_FOR_struct_preempt_ops
#ifndef SCANNER_FOR_struct_preempt_ops
#define SCANNER_FOR_struct_preempt_ops
TYPE_SCAN_WRAPPER(struct preempt_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct preempt_ops);
    }
    SCAN {
        S(kern_printk( "struct preempt_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.sched_in);
        SCAN_FUNCTION(arg.sched_out);
    }
})
#endif


//#define SCANNER_FOR_struct_preempt_notifier
#ifndef SCANNER_FOR_struct_preempt_notifier
#define SCANNER_FOR_struct_preempt_notifier
TYPE_SCAN_WRAPPER(struct preempt_notifier, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct preempt_notifier);
    }
    SCAN {
        S(kern_printk( "struct preempt_notifier\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.link);
        SCAN_RECURSIVE_PTR(arg.ops);
    }
})
#endif


//#define SCANNER_FOR_struct_qtree_fmt_operations
#ifndef SCANNER_FOR_struct_qtree_fmt_operations
#define SCANNER_FOR_struct_qtree_fmt_operations
TYPE_SCAN_WRAPPER(struct qtree_fmt_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct qtree_fmt_operations);
    }
    SCAN {
        S(kern_printk( "struct qtree_fmt_operations\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.mem2disk_dqblk);
        SCAN_FUNCTION(arg.disk2mem_dqblk);
        SCAN_FUNCTION(arg.is_id);
    }
})
#endif


//#define SCANNER_FOR_struct_qtree_mem_dqinfo
#ifndef SCANNER_FOR_struct_qtree_mem_dqinfo
#define SCANNER_FOR_struct_qtree_mem_dqinfo
TYPE_SCAN_WRAPPER(struct qtree_mem_dqinfo, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct qtree_mem_dqinfo);
    }
    SCAN {
        S(kern_printk( "struct qtree_mem_dqinfo\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.dqi_sb);
        SCAN_FUNCTION(arg.dqi_type);
        SCAN_FUNCTION(arg.dqi_blocks);
        SCAN_FUNCTION(arg.dqi_free_blk);
        SCAN_FUNCTION(arg.dqi_free_entry);
        SCAN_FUNCTION(arg.dqi_blocksize_bits);
        SCAN_FUNCTION(arg.dqi_entry_size);
        SCAN_FUNCTION(arg.dqi_usable_bs);
        SCAN_FUNCTION(arg.dqi_qtree_depth);
        SCAN_RECURSIVE_PTR(arg.dqi_ops);
    }
})
#endif


//#define SCANNER_FOR_struct_tcp6_request_sock
#ifndef SCANNER_FOR_struct_tcp6_request_sock
#define SCANNER_FOR_struct_tcp6_request_sock
TYPE_SCAN_WRAPPER(struct tcp6_request_sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tcp6_request_sock);
    }
    SCAN {
        S(kern_printk( "struct tcp6_request_sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.tcp6rsk_tcp);
        SCAN_RECURSIVE(arg.tcp6rsk_inet6);
    }
})
#endif


//#define SCANNER_FOR_struct_x86_init_timers
#ifndef SCANNER_FOR_struct_x86_init_timers
#define SCANNER_FOR_struct_x86_init_timers
TYPE_SCAN_WRAPPER(struct x86_init_timers, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct x86_init_timers);
    }
    SCAN {
        S(kern_printk( "struct x86_init_timers\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.setup_percpu_clockev);
        SCAN_FUNCTION(arg.tsc_pre_init);
        SCAN_FUNCTION(arg.timer_init);
        SCAN_FUNCTION(arg.wallclock_init);
    }
})
#endif


//#define SCANNER_FOR_struct_cyclecounter
#ifndef SCANNER_FOR_struct_cyclecounter
#define SCANNER_FOR_struct_cyclecounter
TYPE_SCAN_WRAPPER(struct cyclecounter, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cyclecounter);
    }
    SCAN {
        S(kern_printk( "struct cyclecounter\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.read);
        SCAN_FUNCTION(arg.mask);
        SCAN_FUNCTION(arg.mult);
        SCAN_FUNCTION(arg.shift);
    }
})
#endif


#define SCANNER_FOR_struct_timecounter
#ifndef SCANNER_FOR_struct_timecounter
#define SCANNER_FOR_struct_timecounter
TYPE_SCAN_WRAPPER(struct timecounter, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct timecounter);
    }
    SCAN {
        S(kern_printk( "struct timecounter\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.cc);
        SCAN_FUNCTION(arg.cycle_last);
        SCAN_FUNCTION(arg.nsec);
    }
})
#endif


//#define SCANNER_FOR_struct_x86_init_oem
#ifndef SCANNER_FOR_struct_x86_init_oem
#define SCANNER_FOR_struct_x86_init_oem
TYPE_SCAN_WRAPPER(struct x86_init_oem, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct x86_init_oem);
    }
    SCAN {
        S(kern_printk( "struct x86_init_oem\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.arch_setup);
        SCAN_FUNCTION(arg.banner);
    }
})
#endif


//#define SCANNER_FOR_struct_hash_alg_common
#ifndef SCANNER_FOR_struct_hash_alg_common
#define SCANNER_FOR_struct_hash_alg_common
TYPE_SCAN_WRAPPER(struct hash_alg_common, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct hash_alg_common);
    }
    SCAN {
        S(kern_printk( "struct hash_alg_common\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.digestsize);
        SCAN_FUNCTION(arg.statesize);
        SCAN_RECURSIVE(arg.base);
    }
})
#endif


//#define SCANNER_FOR_struct_tp_module
#ifndef SCANNER_FOR_struct_tp_module
#define SCANNER_FOR_struct_tp_module
TYPE_SCAN_WRAPPER(struct tp_module, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tp_module);
    }
    SCAN {
        S(kern_printk( "struct tp_module\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_FUNCTION(arg.num_tracepoints);
//  Pointer(Pointer(const Use(Struct(struct tracepoint)))) arg.tracepoints_ptrs
    }
})
#endif


//#define SCANNER_FOR_struct_tracepoint_iter
#ifndef SCANNER_FOR_struct_tracepoint_iter
#define SCANNER_FOR_struct_tracepoint_iter
TYPE_SCAN_WRAPPER(struct tracepoint_iter, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tracepoint_iter);
    }
    SCAN {
        S(kern_printk( "struct tracepoint_iter\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.module);
//  Pointer(Pointer(const Use(Struct(struct tracepoint)))) arg.tracepoint
    }
})
#endif


//#define SCANNER_FOR_struct_phy_fixup
#ifndef SCANNER_FOR_struct_phy_fixup
#define SCANNER_FOR_struct_phy_fixup
TYPE_SCAN_WRAPPER(struct phy_fixup, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct phy_fixup);
    }
    SCAN {
        S(kern_printk( "struct phy_fixup\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
//  Array(BuiltIn(char)) arg.bus_id
        SCAN_FUNCTION(arg.phy_uid);
        SCAN_FUNCTION(arg.phy_uid_mask);
        SCAN_FUNCTION(arg.run);
    }
})
#endif


//#define SCANNER_FOR_struct_acpi_sleep_functions
#ifndef SCANNER_FOR_struct_acpi_sleep_functions
#define SCANNER_FOR_struct_acpi_sleep_functions
TYPE_SCAN_WRAPPER(struct acpi_sleep_functions, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct acpi_sleep_functions);
    }
    SCAN {
        S(kern_printk( "struct acpi_sleep_functions\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.legacy_function);
        SCAN_FUNCTION(arg.extended_function);
    }
})
#endif


//#define SCANNER_FOR_struct_smp_ops
#ifndef SCANNER_FOR_struct_smp_ops
#define SCANNER_FOR_struct_smp_ops
TYPE_SCAN_WRAPPER(struct smp_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct smp_ops);
    }
    SCAN {
        S(kern_printk( "struct smp_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.smp_prepare_boot_cpu);
        SCAN_FUNCTION(arg.smp_prepare_cpus);
        SCAN_FUNCTION(arg.smp_cpus_done);
        SCAN_FUNCTION(arg.stop_other_cpus);
        SCAN_FUNCTION(arg.smp_send_reschedule);
        SCAN_FUNCTION(arg.cpu_up);
        SCAN_FUNCTION(arg.cpu_disable);
        SCAN_FUNCTION(arg.cpu_die);
        SCAN_FUNCTION(arg.play_dead);
        SCAN_FUNCTION(arg.send_call_func_ipi);
        SCAN_FUNCTION(arg.send_call_func_single_ipi);
    }
})
#endif


#ifndef SCANNER_FOR_struct_kthread_work
#define SCANNER_FOR_struct_kthread_work
TYPE_SCAN_WRAPPER(struct kthread_work, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct kthread_work);
    }
    SCAN {
        S(kern_printk( "struct kthread_work\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.node);
        SCAN_FUNCTION(arg.func);
        SCAN_RECURSIVE(arg.done);
        SCAN_RECURSIVE_PTR(arg.worker);
    }
})
#endif


#ifndef SCANNER_FOR_struct_kthread_worker
#define SCANNER_FOR_struct_kthread_worker
TYPE_SCAN_WRAPPER(struct kthread_worker, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct kthread_worker);
    }
    SCAN {
        S(kern_printk( "struct kthread_worker\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.lock);
        SCAN_RECURSIVE(arg.work_list);
        SCAN_RECURSIVE_PTR(arg.task);
        SCAN_RECURSIVE_PTR(arg.current_work);
    }
})
#endif


#define SCANNER_FOR_struct_x86_init_resources
#ifndef SCANNER_FOR_struct_x86_init_resources
#define SCANNER_FOR_struct_x86_init_resources
TYPE_SCAN_WRAPPER(struct x86_init_resources, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct x86_init_resources);
    }
    SCAN {
        S(kern_printk( "struct x86_init_resources\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.probe_roms);
        SCAN_FUNCTION(arg.reserve_resources);
        SCAN_FUNCTION(arg.memory_setup);
    }
})
#endif


#define SCANNER_FOR_struct_acpi_bus_type
#ifndef SCANNER_FOR_struct_acpi_bus_type
#define SCANNER_FOR_struct_acpi_bus_type
TYPE_SCAN_WRAPPER(struct acpi_bus_type, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct acpi_bus_type);
    }
    SCAN {
        S(kern_printk( "struct acpi_bus_type\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_RECURSIVE_PTR(arg.bus);
        SCAN_FUNCTION(arg.find_device);
        SCAN_FUNCTION(arg.find_bridge);
    }
})
#endif


#define SCANNER_FOR_struct_crypto_comp
#ifndef SCANNER_FOR_struct_crypto_comp
#define SCANNER_FOR_struct_crypto_comp
TYPE_SCAN_WRAPPER(struct crypto_comp, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct crypto_comp);
    }
    SCAN {
        S(kern_printk( "struct crypto_comp\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.base);
    }
})
#endif



#ifndef SCANNER_FOR_struct_dmi_system_id
#define SCANNER_FOR_struct_dmi_system_id
TYPE_SCAN_WRAPPER(struct dmi_system_id, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dmi_system_id);
    }
    SCAN {
        S(kern_printk( "struct dmi_system_id\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.callback);
        SCAN_FUNCTION(arg.ident);
//  Array(Use(Struct(struct dmi_strmatch))) arg.matches
        SCAN_FUNCTION(arg.driver_data);
    }
})
#endif


#define SCANNER_FOR_struct_biovec_slab
#ifndef SCANNER_FOR_struct_biovec_slab
#define SCANNER_FOR_struct_biovec_slab
TYPE_SCAN_WRAPPER(struct biovec_slab, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct biovec_slab);
    }
    SCAN {
        S(kern_printk( "struct biovec_slab\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.nr_vecs);
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE_PTR(arg.slab);
    }
})
#endif


#define SCANNER_FOR_struct_target_type
#ifndef SCANNER_FOR_struct_target_type
#define SCANNER_FOR_struct_target_type
TYPE_SCAN_WRAPPER(struct target_type, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct target_type);
    }
    SCAN {
        S(kern_printk( "struct target_type\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.features);
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE_PTR(arg.module);
//  Array(Attributed(unsigned , BuiltIn(int))) arg.version
        SCAN_FUNCTION(arg.ctr);
        SCAN_FUNCTION(arg.dtr);
        SCAN_FUNCTION(arg.map);
        SCAN_FUNCTION(arg.map_rq);
        SCAN_FUNCTION(arg.end_io);
        SCAN_FUNCTION(arg.rq_end_io);
        SCAN_FUNCTION(arg.presuspend);
        SCAN_FUNCTION(arg.postsuspend);
        SCAN_FUNCTION(arg.preresume);
        SCAN_FUNCTION(arg.resume);
        SCAN_FUNCTION(arg.status);
        SCAN_FUNCTION(arg.message);
        SCAN_FUNCTION(arg.ioctl);
        SCAN_FUNCTION(arg.merge);
        SCAN_FUNCTION(arg.busy);
        SCAN_FUNCTION(arg.iterate_devices);
        SCAN_FUNCTION(arg.io_hints);
        SCAN_RECURSIVE(arg.list);
    }
})
#endif


#define SCANNER_FOR_struct_dm_target
#ifndef SCANNER_FOR_struct_dm_target
#define SCANNER_FOR_struct_dm_target
TYPE_SCAN_WRAPPER(struct dm_target, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dm_target);
    }
    SCAN {
        S(kern_printk( "struct dm_target\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.table);
        SCAN_RECURSIVE_PTR(arg.type);
        SCAN_FUNCTION(arg.begin);
        SCAN_FUNCTION(arg.len);
        SCAN_FUNCTION(arg.max_io_len);
        SCAN_FUNCTION(arg.num_flush_requests);
        SCAN_FUNCTION(arg.num_discard_requests);
        SCAN_FUNCTION(arg.num_write_same_requests);
        SCAN_FUNCTION(arg.per_bio_data_size);
        SCAN_FUNCTION(arg.private_);
        SCAN_FUNCTION(arg.error);
//  Bitfield(Use(TypeDef(bool, Use(TypeDef(K_Bool, BuiltIn(int)))))) arg.flush_supported
//  Bitfield(Use(TypeDef(bool, Use(TypeDef(K_Bool, BuiltIn(int)))))) arg.discards_supported
//  Bitfield(Use(TypeDef(bool, Use(TypeDef(K_Bool, BuiltIn(int)))))) arg.split_discard_requests
//  Bitfield(Use(TypeDef(bool, Use(TypeDef(K_Bool, BuiltIn(int)))))) arg.discard_zeroes_data_unsupported
    }
})
#endif


#define SCANNER_FOR_struct_apic
#ifndef SCANNER_FOR_struct_apic
#define SCANNER_FOR_struct_apic
TYPE_SCAN_WRAPPER(struct apic, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct apic);
    }
    SCAN {
        S(kern_printk( "struct apic\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_FUNCTION(arg.probe);
        SCAN_FUNCTION(arg.acpi_madt_oem_check);
        SCAN_FUNCTION(arg.apic_id_valid);
        SCAN_FUNCTION(arg.apic_id_registered);
        SCAN_FUNCTION(arg.irq_delivery_mode);
        SCAN_FUNCTION(arg.irq_dest_mode);
        SCAN_FUNCTION(arg.target_cpus);
        SCAN_FUNCTION(arg.disable_esr);
        SCAN_FUNCTION(arg.dest_logical);
        SCAN_FUNCTION(arg.check_apicid_used);
        SCAN_FUNCTION(arg.check_apicid_present);
        SCAN_FUNCTION(arg.vector_allocation_domain);
        SCAN_FUNCTION(arg.init_apic_ldr);
        SCAN_FUNCTION(arg.ioapic_phys_id_map);
        SCAN_FUNCTION(arg.setup_apic_routing);
        SCAN_FUNCTION(arg.multi_timer_check);
        SCAN_FUNCTION(arg.cpu_present_to_apicid);
        SCAN_FUNCTION(arg.apicid_to_cpu_present);
        SCAN_FUNCTION(arg.setup_portio_remap);
        SCAN_FUNCTION(arg.check_phys_apicid_present);
        SCAN_FUNCTION(arg.enable_apic_mode);
        SCAN_FUNCTION(arg.phys_pkg_id);
        SCAN_FUNCTION(arg.mps_oem_check);
        SCAN_FUNCTION(arg.get_apic_id);
        SCAN_FUNCTION(arg.set_apic_id);
        SCAN_FUNCTION(arg.apic_id_mask);
        SCAN_FUNCTION(arg.cpu_mask_to_apicid_and);
        SCAN_FUNCTION(arg.send_IPI_mask);
        SCAN_FUNCTION(arg.send_IPI_mask_allbutself);
        SCAN_FUNCTION(arg.send_IPI_allbutself);
        SCAN_FUNCTION(arg.send_IPI_all);
        SCAN_FUNCTION(arg.send_IPI_self);
        SCAN_FUNCTION(arg.wakeup_secondary_cpu);
        SCAN_FUNCTION(arg.trampoline_phys_low);
        SCAN_FUNCTION(arg.trampoline_phys_high);
        SCAN_FUNCTION(arg.wait_for_init_deassert);
        SCAN_FUNCTION(arg.smp_callin_clear_local_apic);
        SCAN_FUNCTION(arg.inquire_remote_apic);
        SCAN_FUNCTION(arg.read);
        SCAN_FUNCTION(arg.write);
        SCAN_FUNCTION(arg.eoi_write);
        SCAN_FUNCTION(arg.icr_read);
        SCAN_FUNCTION(arg.icr_write);
        SCAN_FUNCTION(arg.wait_icr_idle);
        SCAN_FUNCTION(arg.safe_wait_icr_idle);
    }
})
#endif


#define SCANNER_FOR_struct_pv_mmu_ops
#ifndef SCANNER_FOR_struct_pv_mmu_ops
#define SCANNER_FOR_struct_pv_mmu_ops
TYPE_SCAN_WRAPPER(struct pv_mmu_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pv_mmu_ops);
    }
    SCAN {
        S(kern_printk( "struct pv_mmu_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.read_cr2);
        SCAN_FUNCTION(arg.write_cr2);
        SCAN_FUNCTION(arg.read_cr3);
        SCAN_FUNCTION(arg.write_cr3);
        SCAN_FUNCTION(arg.activate_mm);
        SCAN_FUNCTION(arg.dup_mmap);
        SCAN_FUNCTION(arg.exit_mmap);
        SCAN_FUNCTION(arg.flush_tlb_user);
        SCAN_FUNCTION(arg.flush_tlb_kernel);
        SCAN_FUNCTION(arg.flush_tlb_single);
        SCAN_FUNCTION(arg.flush_tlb_others);
        SCAN_FUNCTION(arg.pgd_alloc);
        SCAN_FUNCTION(arg.pgd_free);
        SCAN_FUNCTION(arg.alloc_pte);
        SCAN_FUNCTION(arg.alloc_pmd);
        SCAN_FUNCTION(arg.alloc_pud);
        SCAN_FUNCTION(arg.release_pte);
        SCAN_FUNCTION(arg.release_pmd);
        SCAN_FUNCTION(arg.release_pud);
        SCAN_FUNCTION(arg.set_pte);
        SCAN_FUNCTION(arg.set_pte_at);
        SCAN_FUNCTION(arg.set_pmd);
        SCAN_FUNCTION(arg.set_pmd_at);
        SCAN_FUNCTION(arg.pte_update);
        SCAN_FUNCTION(arg.pte_update_defer);
        SCAN_FUNCTION(arg.pmd_update);
        SCAN_FUNCTION(arg.pmd_update_defer);
        SCAN_FUNCTION(arg.ptep_modify_prot_start);
        SCAN_FUNCTION(arg.ptep_modify_prot_commit);
        SCAN_RECURSIVE(arg.pte_val);
        SCAN_RECURSIVE(arg.make_pte);
        SCAN_RECURSIVE(arg.pgd_val);
        SCAN_RECURSIVE(arg.make_pgd);
        SCAN_FUNCTION(arg.set_pud);
        SCAN_RECURSIVE(arg.pmd_val);
        SCAN_RECURSIVE(arg.make_pmd);
        SCAN_RECURSIVE(arg.pud_val);
        SCAN_RECURSIVE(arg.make_pud);
        SCAN_FUNCTION(arg.set_pgd);
        SCAN_RECURSIVE(arg.lazy_mode);
        SCAN_FUNCTION(arg.set_fixmap);
    }
})
#endif


#define SCANNER_FOR_struct_proc_inode
#ifndef SCANNER_FOR_struct_proc_inode
#define SCANNER_FOR_struct_proc_inode
TYPE_SCAN_WRAPPER(struct proc_inode, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct proc_inode);
    }
    SCAN {
        S(kern_printk( "struct proc_inode\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.pid);
        SCAN_FUNCTION(arg.fd);
//  Union(union proc_op) arg.op
        SCAN_RECURSIVE_PTR(arg.pde);
        SCAN_RECURSIVE_PTR(arg.sysctl);
        SCAN_RECURSIVE_PTR(arg.sysctl_entry);
        SCAN_FUNCTION(arg.ns);
        SCAN_RECURSIVE_PTR(arg.ns_ops);
        SCAN_RECURSIVE(arg.vfs_inode);
    }
})
#endif


#define SCANNER_FOR_struct_ptr_heap
#ifndef SCANNER_FOR_struct_ptr_heap
#define SCANNER_FOR_struct_ptr_heap
TYPE_SCAN_WRAPPER(struct ptr_heap, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ptr_heap);
    }
    SCAN {
        S(kern_printk( "struct ptr_heap\n");)
        S(SCAN_OBJECT(arg);)
//  Pointer(Pointer(BuiltIn(void))) arg.ptrs
        SCAN_FUNCTION(arg.max);
        SCAN_FUNCTION(arg.size);
        SCAN_FUNCTION(arg.gt);
    }
})
#endif


#define SCANNER_FOR_struct_skb_shared_info
#ifndef SCANNER_FOR_struct_skb_shared_info
#define SCANNER_FOR_struct_skb_shared_info
TYPE_SCAN_WRAPPER(struct skb_shared_info, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct skb_shared_info);
    }
    SCAN {
        S(kern_printk( "struct skb_shared_info\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.nr_frags);
        SCAN_FUNCTION(arg.tx_flags);
        SCAN_FUNCTION(arg.gso_size);
        SCAN_FUNCTION(arg.gso_segs);
        SCAN_FUNCTION(arg.gso_type);
        SCAN_RECURSIVE_PTR(arg.frag_list);
        SCAN_RECURSIVE(arg.hwtstamps);
        SCAN_FUNCTION(arg.ip6_frag_id);
        SCAN_RECURSIVE(arg.dataref);
        SCAN_FUNCTION(arg.destructor_arg);
//  Array(Use(TypeDef(skb_frag_t, Use(Struct(struct skb_frag_struct))))) arg.frags
    }
})
#endif


#define SCANNER_FOR_struct_dm_target_callbacks
#ifndef SCANNER_FOR_struct_dm_target_callbacks
#define SCANNER_FOR_struct_dm_target_callbacks
TYPE_SCAN_WRAPPER(struct dm_target_callbacks, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dm_target_callbacks);
    }
    SCAN {
        S(kern_printk( "struct dm_target_callbacks\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_FUNCTION(arg.congested_fn);
    }
})
#endif


#define SCANNER_FOR_struct_netlink_notify
#ifndef SCANNER_FOR_struct_netlink_notify
#define SCANNER_FOR_struct_netlink_notify
TYPE_SCAN_WRAPPER(struct netlink_notify, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netlink_notify);
    }
    SCAN {
        S(kern_printk( "struct netlink_notify\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.net);
        SCAN_FUNCTION(arg.portid);
        SCAN_FUNCTION(arg.protocol);
    }
})
#endif


#define SCANNER_FOR_struct_inet_timewait_sock
#ifndef SCANNER_FOR_struct_inet_timewait_sock
#define SCANNER_FOR_struct_inet_timewait_sock
TYPE_SCAN_WRAPPER(struct inet_timewait_sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct inet_timewait_sock);
    }
    SCAN {
        S(kern_printk( "struct inet_timewait_sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.__tw_common);
        SCAN_FUNCTION(arg.tw_timeout);
        SCAN_FUNCTION(arg.tw_substate);
        SCAN_FUNCTION(arg.tw_rcv_wscale);
        SCAN_FUNCTION(arg.tw_sport);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.tw_ipv6only
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.tw_transparent
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.tw_pad
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.tw_tos
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.tw_ipv6_offset
        SCAN_FUNCTION(arg.tw_ttd);
        SCAN_RECURSIVE_PTR(arg.tw_tb);
        SCAN_RECURSIVE(arg.tw_death_node);
    }
})
#endif


#define SCANNER_FOR_struct_shash_desc
#ifndef SCANNER_FOR_struct_shash_desc
#define SCANNER_FOR_struct_shash_desc
TYPE_SCAN_WRAPPER(struct shash_desc, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct shash_desc);
    }
    SCAN {
        S(kern_printk( "struct shash_desc\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.tfm);
        SCAN_FUNCTION(arg.flags);
//  Array(Pointer(BuiltIn(void))) arg.__ctx
    }
})
#endif


//#define SCANNER_FOR_struct_shash_alg
#ifndef SCANNER_FOR_struct_shash_alg
#define SCANNER_FOR_struct_shash_alg
TYPE_SCAN_WRAPPER(struct shash_alg, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct shash_alg);
    }
    SCAN {
        S(kern_printk( "struct shash_alg\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.init);
        SCAN_FUNCTION(arg.update);
        SCAN_FUNCTION(arg.final);
        SCAN_FUNCTION(arg.finup);
        SCAN_FUNCTION(arg.digest);
        SCAN_FUNCTION(arg.export_);
        SCAN_FUNCTION(arg.import);
        SCAN_FUNCTION(arg.setkey);
        SCAN_FUNCTION(arg.descsize);
        SCAN_FUNCTION(arg.digestsize);
        SCAN_FUNCTION(arg.statesize);
        SCAN_RECURSIVE(arg.base);
    }
})
#endif


//#define SCANNER_FOR_struct_acpi_dock_ops
#ifndef SCANNER_FOR_struct_acpi_dock_ops
#define SCANNER_FOR_struct_acpi_dock_ops
TYPE_SCAN_WRAPPER(struct acpi_dock_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct acpi_dock_ops);
    }
    SCAN {
        S(kern_printk( "struct acpi_dock_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.handler);
        SCAN_FUNCTION(arg.uevent);
    }
})
#endif


//#define SCANNER_FOR_struct_tcp_timewait_sock
#ifndef SCANNER_FOR_struct_tcp_timewait_sock
#define SCANNER_FOR_struct_tcp_timewait_sock
TYPE_SCAN_WRAPPER(struct tcp_timewait_sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tcp_timewait_sock);
    }
    SCAN {
        S(kern_printk( "struct tcp_timewait_sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.tw_sk);
        SCAN_FUNCTION(arg.tw_rcv_nxt);
        SCAN_FUNCTION(arg.tw_snd_nxt);
        SCAN_FUNCTION(arg.tw_rcv_wnd);
        SCAN_FUNCTION(arg.tw_ts_recent);
        SCAN_FUNCTION(arg.tw_ts_recent_stamp);
        SCAN_RECURSIVE_PTR(arg.tw_md5_key);
        SCAN_RECURSIVE_PTR(arg.tw_cookie_values);
    }
})
#endif


//#define SCANNER_FOR_struct_tcp6_timewait_sock
#ifndef SCANNER_FOR_struct_tcp6_timewait_sock
#define SCANNER_FOR_struct_tcp6_timewait_sock
TYPE_SCAN_WRAPPER(struct tcp6_timewait_sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tcp6_timewait_sock);
    }
    SCAN {
        S(kern_printk( "struct tcp6_timewait_sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.tcp6tw_tcp);
        SCAN_RECURSIVE(arg.tcp6tw_inet6);
    }
})
#endif


//#define SCANNER_FOR_struct_klist_iter
#ifndef SCANNER_FOR_struct_klist_iter
#define SCANNER_FOR_struct_klist_iter
TYPE_SCAN_WRAPPER(struct klist_iter, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct klist_iter);
    }
    SCAN {
        S(kern_printk( "struct klist_iter\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.i_klist);
        SCAN_RECURSIVE_PTR(arg.i_cur);
    }
})
#endif


//#define SCANNER_FOR_struct_inet_timewait_death_row
#ifndef SCANNER_FOR_struct_inet_timewait_death_row
#define SCANNER_FOR_struct_inet_timewait_death_row
TYPE_SCAN_WRAPPER(struct inet_timewait_death_row, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct inet_timewait_death_row);
    }
    SCAN {
        S(kern_printk( "struct inet_timewait_death_row\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.twcal_hand);
        SCAN_FUNCTION(arg.twcal_jiffie);
        SCAN_RECURSIVE(arg.twcal_timer);
//  Array(Use(Struct(struct hlist_head))) arg.twcal_row
        SCAN_RECURSIVE(arg.death_lock);
        SCAN_FUNCTION(arg.tw_count);
        SCAN_FUNCTION(arg.period);
        SCAN_FUNCTION(arg.thread_slots);
        SCAN_RECURSIVE(arg.twkill_work);
        SCAN_RECURSIVE(arg.tw_timer);
        SCAN_FUNCTION(arg.slot);
//  Array(Use(Struct(struct hlist_head))) arg.cells
        SCAN_RECURSIVE_PTR(arg.hashinfo);
        SCAN_FUNCTION(arg.sysctl_tw_recycle);
        SCAN_FUNCTION(arg.sysctl_max_tw_buckets);
    }
})
#endif


//#define SCANNER_FOR_struct_rcu_batch
#ifndef SCANNER_FOR_struct_rcu_batch
#define SCANNER_FOR_struct_rcu_batch
TYPE_SCAN_WRAPPER(struct rcu_batch, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct rcu_batch);
    }
    SCAN {
        S(kern_printk( "struct rcu_batch\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.head);
//  Pointer(Pointer(Use(Struct(struct callback_head)))) arg.tail
    }
})
#endif


//#define SCANNER_FOR_struct_wait_bit_queue
#ifndef SCANNER_FOR_struct_wait_bit_queue
#define SCANNER_FOR_struct_wait_bit_queue
TYPE_SCAN_WRAPPER(struct wait_bit_queue, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct wait_bit_queue);
    }
    SCAN {
        S(kern_printk( "struct wait_bit_queue\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.key);
        SCAN_RECURSIVE(arg.wait);
    }
})
#endif


//#define SCANNER_FOR_struct_skb_seq_state
#ifndef SCANNER_FOR_struct_skb_seq_state
#define SCANNER_FOR_struct_skb_seq_state
TYPE_SCAN_WRAPPER(struct skb_seq_state, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct skb_seq_state);
    }
    SCAN {
        S(kern_printk( "struct skb_seq_state\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.lower_offset);
        SCAN_FUNCTION(arg.upper_offset);
        SCAN_FUNCTION(arg.frag_idx);
        SCAN_FUNCTION(arg.stepped_offset);
        SCAN_RECURSIVE_PTR(arg.root_skb);
        SCAN_RECURSIVE_PTR(arg.cur_skb);
        SCAN_FUNCTION(arg.frag_data);
    }
})
#endif


//#define SCANNER_FOR_struct_acpi_pci_driver
#ifndef SCANNER_FOR_struct_acpi_pci_driver
#define SCANNER_FOR_struct_acpi_pci_driver
TYPE_SCAN_WRAPPER(struct acpi_pci_driver, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct acpi_pci_driver);
    }
    SCAN {
        S(kern_printk( "struct acpi_pci_driver\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.node);
        SCAN_FUNCTION(arg.add);
        SCAN_FUNCTION(arg.remove);
    }
})
#endif


//#define SCANNER_FOR_struct_mii_if_info
#ifndef SCANNER_FOR_struct_mii_if_info
#define SCANNER_FOR_struct_mii_if_info
TYPE_SCAN_WRAPPER(struct mii_if_info, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct mii_if_info);
    }
    SCAN {
        S(kern_printk( "struct mii_if_info\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.phy_id);
        SCAN_FUNCTION(arg.advertising);
        SCAN_FUNCTION(arg.phy_id_mask);
        SCAN_FUNCTION(arg.reg_num_mask);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.full_duplex
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.force_media
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.supports_gmii
        SCAN_RECURSIVE_PTR(arg.dev);
        SCAN_FUNCTION(arg.mdio_read);
        SCAN_FUNCTION(arg.mdio_write);
    }
})
#endif


//#define SCANNER_FOR_struct_subsys_dev_iter
#ifndef SCANNER_FOR_struct_subsys_dev_iter
#define SCANNER_FOR_struct_subsys_dev_iter
TYPE_SCAN_WRAPPER(struct subsys_dev_iter, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct subsys_dev_iter);
    }
    SCAN {
        S(kern_printk( "struct subsys_dev_iter\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.ki);
        SCAN_RECURSIVE_PTR(arg.type);
    }
})
#endif


//#define SCANNER_FOR_struct_tcp6_sock
#ifndef SCANNER_FOR_struct_tcp6_sock
#define SCANNER_FOR_struct_tcp6_sock
TYPE_SCAN_WRAPPER(struct tcp6_sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tcp6_sock);
    }
    SCAN {
        S(kern_printk( "struct tcp6_sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.tcp);
        SCAN_RECURSIVE(arg.inet6);
    }
})
#endif


//#define SCANNER_FOR_struct_netlink_kernel_cfg
#ifndef SCANNER_FOR_struct_netlink_kernel_cfg
#define SCANNER_FOR_struct_netlink_kernel_cfg
TYPE_SCAN_WRAPPER(struct netlink_kernel_cfg, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netlink_kernel_cfg);
    }
    SCAN {
        S(kern_printk( "struct netlink_kernel_cfg\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.groups);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.input);
        SCAN_RECURSIVE_PTR(arg.cb_mutex);
        SCAN_FUNCTION(arg.bind);
    }
})
#endif


//#define SCANNER_FOR_struct_srcu_struct
#ifndef SCANNER_FOR_struct_srcu_struct
#define SCANNER_FOR_struct_srcu_struct
TYPE_SCAN_WRAPPER(struct srcu_struct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct srcu_struct);
    }
    SCAN {
        S(kern_printk( "struct srcu_struct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.completed);
        SCAN_RECURSIVE_PTR(arg.per_cpu_ref);
        SCAN_RECURSIVE(arg.queue_lock);
        SCAN_FUNCTION(arg.running);
        SCAN_RECURSIVE(arg.batch_queue);
        SCAN_RECURSIVE(arg.batch_check0);
        SCAN_RECURSIVE(arg.batch_check1);
        SCAN_RECURSIVE(arg.batch_done);
        SCAN_RECURSIVE(arg.work);
    }
})
#endif


//#define SCANNER_FOR_struct_module_version_attribute
#ifndef SCANNER_FOR_struct_module_version_attribute
#define SCANNER_FOR_struct_module_version_attribute
TYPE_SCAN_WRAPPER(struct module_version_attribute, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct module_version_attribute);
    }
    SCAN {
        S(kern_printk( "struct module_version_attribute\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.mattr);
        SCAN_FUNCTION(arg.module_name);
        SCAN_FUNCTION(arg.version);
    }
})
#endif


//#define SCANNER_FOR_struct_prop_descriptor
#ifndef SCANNER_FOR_struct_prop_descriptor
#define SCANNER_FOR_struct_prop_descriptor
TYPE_SCAN_WRAPPER(struct prop_descriptor, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct prop_descriptor);
    }
    SCAN {
        S(kern_printk( "struct prop_descriptor\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.index);
//  Array(Use(Struct(struct prop_global))) arg.pg
        SCAN_RECURSIVE(arg.mutex);
    }
})
#endif


//#define SCANNER_FOR_struct_tasklet_struct
#ifndef SCANNER_FOR_struct_tasklet_struct
#define SCANNER_FOR_struct_tasklet_struct
TYPE_SCAN_WRAPPER(struct tasklet_struct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tasklet_struct);
    }
    SCAN {
        S(kern_printk( "struct tasklet_struct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_FUNCTION(arg.state);
        SCAN_RECURSIVE(arg.count);
        SCAN_FUNCTION(arg.func);
        SCAN_FUNCTION(arg.data);
    }
})
#endif


//#define SCANNER_FOR_struct_softnet_data
#ifndef SCANNER_FOR_struct_softnet_data
#define SCANNER_FOR_struct_softnet_data
TYPE_SCAN_WRAPPER(struct softnet_data, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct softnet_data);
    }
    SCAN {
        S(kern_printk( "struct softnet_data\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.output_queue);
//  Pointer(Pointer(Use(Struct(struct Qdisc)))) arg.output_queue_tailp
        SCAN_RECURSIVE(arg.poll_list);
        SCAN_RECURSIVE_PTR(arg.completion_queue);
        SCAN_RECURSIVE(arg.process_queue);
        SCAN_FUNCTION(arg.processed);
        SCAN_FUNCTION(arg.time_squeeze);
        SCAN_FUNCTION(arg.cpu_collision);
        SCAN_FUNCTION(arg.received_rps);
        SCAN_RECURSIVE_PTR(arg.rps_ipi_list);
        SCAN_RECURSIVE(arg.csd);
        SCAN_RECURSIVE_PTR(arg.rps_ipi_next);
        SCAN_FUNCTION(arg.cpu);
        SCAN_FUNCTION(arg.input_queue_head);
        SCAN_FUNCTION(arg.input_queue_tail);
        SCAN_FUNCTION(arg.dropped);
        SCAN_RECURSIVE(arg.input_pkt_queue);
        SCAN_RECURSIVE(arg.backlog);
    }
})
#endif


//#define SCANNER_FOR_struct_rtnl_af_ops
#ifndef SCANNER_FOR_struct_rtnl_af_ops
#define SCANNER_FOR_struct_rtnl_af_ops
TYPE_SCAN_WRAPPER(struct rtnl_af_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct rtnl_af_ops);
    }
    SCAN {
        S(kern_printk( "struct rtnl_af_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_FUNCTION(arg.family);
        SCAN_FUNCTION(arg.fill_link_af);
        SCAN_FUNCTION(arg.get_link_af_size);
        SCAN_FUNCTION(arg.validate_link_af);
        SCAN_FUNCTION(arg.set_link_af);
    }
})
#endif


//#define SCANNER_FOR_struct_pv_time_ops
#ifndef SCANNER_FOR_struct_pv_time_ops
#define SCANNER_FOR_struct_pv_time_ops
TYPE_SCAN_WRAPPER(struct pv_time_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pv_time_ops);
    }
    SCAN {
        S(kern_printk( "struct pv_time_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.sched_clock);
        SCAN_FUNCTION(arg.steal_clock);
        SCAN_FUNCTION(arg.get_tsc_khz);
    }
})
#endif


//#define SCANNER_FOR_struct_x86_init_mpparse
#ifndef SCANNER_FOR_struct_x86_init_mpparse
#define SCANNER_FOR_struct_x86_init_mpparse
TYPE_SCAN_WRAPPER(struct x86_init_mpparse, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct x86_init_mpparse);
    }
    SCAN {
        S(kern_printk( "struct x86_init_mpparse\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.mpc_record);
        SCAN_FUNCTION(arg.setup_ioapic_ids);
        SCAN_FUNCTION(arg.mpc_apic_id);
        SCAN_FUNCTION(arg.smp_read_mpc_oem);
        SCAN_FUNCTION(arg.mpc_oem_pci_bus);
        SCAN_FUNCTION(arg.mpc_oem_bus_info);
        SCAN_FUNCTION(arg.find_smp_config);
        SCAN_FUNCTION(arg.get_smp_config);
    }
})
#endif


//#define SCANNER_FOR_struct_obs_kernel_param
#ifndef SCANNER_FOR_struct_obs_kernel_param
#define SCANNER_FOR_struct_obs_kernel_param
TYPE_SCAN_WRAPPER(struct obs_kernel_param, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct obs_kernel_param);
    }
    SCAN {
        S(kern_printk( "struct obs_kernel_param\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.str);
        SCAN_FUNCTION(arg.setup_func);
        SCAN_FUNCTION(arg.early);
    }
})
#endif


//#define SCANNER_FOR_struct_pm_domain_data
#ifndef SCANNER_FOR_struct_pm_domain_data
#define SCANNER_FOR_struct_pm_domain_data
TYPE_SCAN_WRAPPER(struct pm_domain_data, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pm_domain_data);
    }
    SCAN {
        S(kern_printk( "struct pm_domain_data\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list_node);
        SCAN_RECURSIVE_PTR(arg.dev);
    }
})
#endif


//#define SCANNER_FOR_struct_vm_struct
#ifndef SCANNER_FOR_struct_vm_struct
#define SCANNER_FOR_struct_vm_struct
TYPE_SCAN_WRAPPER(struct vm_struct, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct vm_struct);
    }
    SCAN {
        S(kern_printk( "struct vm_struct\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.next);
        SCAN_FUNCTION(arg.addr);
        SCAN_FUNCTION(arg.size);
        SCAN_FUNCTION(arg.flags);
//  Pointer(Pointer(Use(Struct(struct page)))) arg.pages
        SCAN_FUNCTION(arg.nr_pages);
        SCAN_FUNCTION(arg.phys_addr);
        SCAN_FUNCTION(arg.caller);
    }
})
#endif


//#define SCANNER_FOR_struct_miscdevice
#ifndef SCANNER_FOR_struct_miscdevice
#define SCANNER_FOR_struct_miscdevice
TYPE_SCAN_WRAPPER(struct miscdevice, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct miscdevice);
    }
    SCAN {
        S(kern_printk( "struct miscdevice\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.minor);
        SCAN_FUNCTION(arg.name);
        SCAN_RECURSIVE_PTR(arg.fops);
        SCAN_RECURSIVE(arg.list);
        SCAN_RECURSIVE_PTR(arg.parent);
        SCAN_RECURSIVE_PTR(arg.this_device);
        SCAN_FUNCTION(arg.nodename);
        SCAN_FUNCTION(arg.mode);
    }
})
#endif


//#define SCANNER_FOR_struct_pv_irq_ops
#ifndef SCANNER_FOR_struct_pv_irq_ops
//#define SCANNER_FOR_struct_pv_irq_ops
TYPE_SCAN_WRAPPER(struct pv_irq_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pv_irq_ops);
    }
    SCAN {
        S(kern_printk( "struct pv_irq_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.save_fl);
        SCAN_RECURSIVE(arg.restore_fl);
        SCAN_RECURSIVE(arg.irq_disable);
        SCAN_RECURSIVE(arg.irq_enable);
        SCAN_FUNCTION(arg.safe_halt);
        SCAN_FUNCTION(arg.halt);
        SCAN_FUNCTION(arg.adjust_exception_frame);
    }
})
#endif


//#define SCANNER_FOR_struct_cleancache_ops
#ifndef SCANNER_FOR_struct_cleancache_ops
#define SCANNER_FOR_struct_cleancache_ops
TYPE_SCAN_WRAPPER(struct cleancache_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cleancache_ops);
    }
    SCAN {
        S(kern_printk( "struct cleancache_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.init_fs);
        SCAN_FUNCTION(arg.init_shared_fs);
        SCAN_FUNCTION(arg.get_page);
        SCAN_FUNCTION(arg.put_page);
        SCAN_FUNCTION(arg.invalidate_page);
        SCAN_FUNCTION(arg.invalidate_inode);
        SCAN_FUNCTION(arg.invalidate_fs);
    }
})
#endif


//#define SCANNER_FOR_struct_client_extension
#ifndef SCANNER_FOR_struct_client_extension
#define SCANNER_FOR_struct_client_extension
TYPE_SCAN_WRAPPER(struct client_extension, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct client_extension);
    }
    SCAN {
        S(kern_printk( "struct client_extension\n");)
        S(SCAN_OBJECT(arg);)
//  Array(Pointer(BuiltIn(void))) arg.return_address_stack
        SCAN_FUNCTION(arg.return_stack_size);
        SCAN_FUNCTION(arg.exit_address);
        SCAN_FUNCTION(arg.iret_handler);
        SCAN_RECURSIVE(arg.pending);
    }
})
#endif


//#define SCANNER_FOR_struct_thread_info
#ifndef SCANNER_FOR_struct_thread_info
#define SCANNER_FOR_struct_thread_info
TYPE_SCAN_WRAPPER(struct thread_info, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct thread_info);
    }
    SCAN {
        S(kern_printk( "struct thread_info\n");)
        S(SCAN_OBJECT(arg);)
//  Array(Attributed(unsigned , BuiltIn(long))) arg.spill_slot
        SCAN_RECURSIVE_PTR(arg.task);
        SCAN_RECURSIVE_PTR(arg.exec_domain);
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.status);
        SCAN_FUNCTION(arg.cpu);
        SCAN_FUNCTION(arg.preempt_count);
        SCAN_RECURSIVE(arg.addr_limit);
        SCAN_RECURSIVE(arg.restart_block);
        SCAN_FUNCTION(arg.sysenter_return);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.sig_on_uaccess_error
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.uaccess_err
        SCAN_RECURSIVE(arg.client_data);
    }
})
#endif


//#define SCANNER_FOR_struct_mem_cgroup_reclaim_cookie
#ifndef SCANNER_FOR_struct_mem_cgroup_reclaim_cookie
#define SCANNER_FOR_struct_mem_cgroup_reclaim_cookie
TYPE_SCAN_WRAPPER(struct mem_cgroup_reclaim_cookie, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct mem_cgroup_reclaim_cookie);
    }
    SCAN {
        S(kern_printk( "struct mem_cgroup_reclaim_cookie\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.zone);
        SCAN_FUNCTION(arg.priority);
        SCAN_FUNCTION(arg.generation);
    }
})
#endif


//#define SCANNER_FOR_struct_jbd2_journal_handle
#ifndef SCANNER_FOR_struct_jbd2_journal_handle
#define SCANNER_FOR_struct_jbd2_journal_handle
TYPE_SCAN_WRAPPER(struct jbd2_journal_handle, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct jbd2_journal_handle);
    }
    SCAN {
        S(kern_printk( "struct jbd2_journal_handle\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.h_transaction);
        SCAN_FUNCTION(arg.h_buffer_credits);
        SCAN_FUNCTION(arg.h_ref);
        SCAN_FUNCTION(arg.h_err);
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.h_sync
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.h_jdata
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.h_aborted
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.h_cowing
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.h_base_credits
//  Bitfield(Attributed(unsigned , BuiltIn(int))) arg.h_user_credits
    }
})
#endif


//#define SCANNER_FOR_struct_acpi_device_physical_node
#ifndef SCANNER_FOR_struct_acpi_device_physical_node
#define SCANNER_FOR_struct_acpi_device_physical_node
TYPE_SCAN_WRAPPER(struct acpi_device_physical_node, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct acpi_device_physical_node);
    }
    SCAN {
        S(kern_printk( "struct acpi_device_physical_node\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.node_id);
        SCAN_RECURSIVE(arg.node);
        SCAN_RECURSIVE_PTR(arg.dev);
    }
})
#endif


//#define SCANNER_FOR_struct_debug_obj_descr
#ifndef SCANNER_FOR_struct_debug_obj_descr
#define SCANNER_FOR_struct_debug_obj_descr
TYPE_SCAN_WRAPPER(struct debug_obj_descr, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct debug_obj_descr);
    }
    SCAN {
        S(kern_printk( "struct debug_obj_descr\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.name);
        SCAN_FUNCTION(arg.debug_hint);
        SCAN_FUNCTION(arg.fixup_init);
        SCAN_FUNCTION(arg.fixup_activate);
        SCAN_FUNCTION(arg.fixup_destroy);
        SCAN_FUNCTION(arg.fixup_free);
        SCAN_FUNCTION(arg.fixup_assert_init);
    }
})
#endif


//#define SCANNER_FOR_struct_nl_info
#ifndef SCANNER_FOR_struct_nl_info
#define SCANNER_FOR_struct_nl_info
TYPE_SCAN_WRAPPER(struct nl_info, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct nl_info);
    }
    SCAN {
        S(kern_printk( "struct nl_info\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.nlh);
        SCAN_RECURSIVE_PTR(arg.nl_net);
        SCAN_FUNCTION(arg.portid);
    }
})
#endif


//#define SCANNER_FOR_struct_ata_port_info
#ifndef SCANNER_FOR_struct_ata_port_info
#define SCANNER_FOR_struct_ata_port_info
TYPE_SCAN_WRAPPER(struct ata_port_info, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ata_port_info);
    }
    SCAN {
        S(kern_printk( "struct ata_port_info\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.flags);
        SCAN_FUNCTION(arg.link_flags);
        SCAN_FUNCTION(arg.pio_mask);
        SCAN_FUNCTION(arg.mwdma_mask);
        SCAN_FUNCTION(arg.udma_mask);
        SCAN_RECURSIVE_PTR(arg.port_ops);
        SCAN_FUNCTION(arg.private_data);
    }
})
#endif


//#define SCANNER_FOR_struct_module_use
#ifndef SCANNER_FOR_struct_module_use
#define SCANNER_FOR_struct_module_use
TYPE_SCAN_WRAPPER(struct module_use, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct module_use);
    }
    SCAN {
        S(kern_printk( "struct module_use\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.source_list);
        SCAN_RECURSIVE(arg.target_list);
        SCAN_RECURSIVE_PTR(arg.source);
        SCAN_RECURSIVE_PTR(arg.target);
    }
})
#endif


//#define SCANNER_FOR_struct_firmware
#ifndef SCANNER_FOR_struct_firmware
#define SCANNER_FOR_struct_firmware
TYPE_SCAN_WRAPPER(struct firmware, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct firmware);
    }
    SCAN {
        S(kern_printk( "struct firmware\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.size);
        SCAN_FUNCTION(arg.data);
//  Pointer(Pointer(Use(Struct(struct page)))) arg.pages
        SCAN_FUNCTION(arg.priv);
    }
})
#endif


#define SCANNER_FOR_struct_blk_plug_cb
#ifndef SCANNER_FOR_struct_blk_plug_cb
#define SCANNER_FOR_struct_blk_plug_cb
TYPE_SCAN_WRAPPER(struct blk_plug_cb, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct blk_plug_cb);
    }
    SCAN {
        S(kern_printk( "struct blk_plug_cb\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_FUNCTION(arg.callback);
        SCAN_FUNCTION(arg.data);
    }
})
#endif


//#define SCANNER_FOR_struct_debug_obj
#ifndef SCANNER_FOR_struct_debug_obj
#define SCANNER_FOR_struct_debug_obj
TYPE_SCAN_WRAPPER(struct debug_obj, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct debug_obj);
    }
    SCAN {
        S(kern_printk( "struct debug_obj\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.node);
//  Enum(enum debug_obj_state) arg.state
        SCAN_FUNCTION(arg.astate);
        SCAN_FUNCTION(arg.object);
        SCAN_RECURSIVE_PTR(arg.descr);
    }
})
#endif


#define SCANNER_FOR_struct_x86_init_iommu
#ifndef SCANNER_FOR_struct_x86_init_iommu
#define SCANNER_FOR_struct_x86_init_iommu
TYPE_SCAN_WRAPPER(struct x86_init_iommu, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct x86_init_iommu);
    }
    SCAN {
        S(kern_printk( "struct x86_init_iommu\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.iommu_init);
    }
})
#endif


//#define SCANNER_FOR_struct_cgroup_scanner
#ifndef SCANNER_FOR_struct_cgroup_scanner
#define SCANNER_FOR_struct_cgroup_scanner
TYPE_SCAN_WRAPPER(struct cgroup_scanner, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cgroup_scanner);
    }
    SCAN {
        S(kern_printk( "struct cgroup_scanner\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.cg);
        SCAN_FUNCTION(arg.test_task);
        SCAN_FUNCTION(arg.process_task);
        SCAN_RECURSIVE_PTR(arg.heap);
        SCAN_FUNCTION(arg.data);
    }
})
#endif


#define SCANNER_FOR_struct_ida
#ifndef SCANNER_FOR_struct_ida
#define SCANNER_FOR_struct_ida
TYPE_SCAN_WRAPPER(struct ida, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ida);
    }
    SCAN {
        S(kern_printk( "struct ida\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.idr);
        SCAN_RECURSIVE_PTR(arg.free_bitmap);
    }
})
#endif


//#define SCANNER_FOR_struct_security_operations
#ifndef SCANNER_FOR_struct_security_operations
#define SCANNER_FOR_struct_security_operations
TYPE_SCAN_WRAPPER(struct security_operations, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct security_operations);
    }
    SCAN {
        S(kern_printk( "struct security_operations\n");)
        S(SCAN_OBJECT(arg);)
//  Array(BuiltIn(char)) arg.name
        SCAN_FUNCTION(arg.ptrace_access_check);
        SCAN_FUNCTION(arg.ptrace_traceme);
        SCAN_FUNCTION(arg.capget);
        SCAN_FUNCTION(arg.capset);
        SCAN_FUNCTION(arg.capable);
        SCAN_FUNCTION(arg.quotactl);
        SCAN_FUNCTION(arg.quota_on);
        SCAN_FUNCTION(arg.syslog);
        SCAN_FUNCTION(arg.settime);
        SCAN_FUNCTION(arg.vm_enough_memory);
        SCAN_FUNCTION(arg.bprm_set_creds);
        SCAN_FUNCTION(arg.bprm_check_security);
        SCAN_FUNCTION(arg.bprm_secureexec);
        SCAN_FUNCTION(arg.bprm_committing_creds);
        SCAN_FUNCTION(arg.bprm_committed_creds);
        SCAN_FUNCTION(arg.sb_alloc_security);
        SCAN_FUNCTION(arg.sb_free_security);
        SCAN_FUNCTION(arg.sb_copy_data);
        SCAN_FUNCTION(arg.sb_remount);
        SCAN_FUNCTION(arg.sb_kern_mount);
        SCAN_FUNCTION(arg.sb_show_options);
        SCAN_FUNCTION(arg.sb_statfs);
        SCAN_FUNCTION(arg.sb_mount);
        SCAN_FUNCTION(arg.sb_umount);
        SCAN_FUNCTION(arg.sb_pivotroot);
        SCAN_FUNCTION(arg.sb_set_mnt_opts);
        SCAN_FUNCTION(arg.sb_clone_mnt_opts);
        SCAN_FUNCTION(arg.sb_parse_opts_str);
        SCAN_FUNCTION(arg.path_unlink);
        SCAN_FUNCTION(arg.path_mkdir);
        SCAN_FUNCTION(arg.path_rmdir);
        SCAN_FUNCTION(arg.path_mknod);
        SCAN_FUNCTION(arg.path_truncate);
        SCAN_FUNCTION(arg.path_symlink);
        SCAN_FUNCTION(arg.path_link);
        SCAN_FUNCTION(arg.path_rename);
        SCAN_FUNCTION(arg.path_chmod);
        SCAN_FUNCTION(arg.path_chown);
        SCAN_FUNCTION(arg.path_chroot);
        SCAN_FUNCTION(arg.inode_alloc_security);
        SCAN_FUNCTION(arg.inode_free_security);
        SCAN_FUNCTION(arg.inode_init_security);
        SCAN_FUNCTION(arg.inode_create);
        SCAN_FUNCTION(arg.inode_link);
        SCAN_FUNCTION(arg.inode_unlink);
        SCAN_FUNCTION(arg.inode_symlink);
        SCAN_FUNCTION(arg.inode_mkdir);
        SCAN_FUNCTION(arg.inode_rmdir);
        SCAN_FUNCTION(arg.inode_mknod);
        SCAN_FUNCTION(arg.inode_rename);
        SCAN_FUNCTION(arg.inode_readlink);
        SCAN_FUNCTION(arg.inode_follow_link);
        SCAN_FUNCTION(arg.inode_permission);
        SCAN_FUNCTION(arg.inode_setattr);
        SCAN_FUNCTION(arg.inode_getattr);
        SCAN_FUNCTION(arg.inode_setxattr);
        SCAN_FUNCTION(arg.inode_post_setxattr);
        SCAN_FUNCTION(arg.inode_getxattr);
        SCAN_FUNCTION(arg.inode_listxattr);
        SCAN_FUNCTION(arg.inode_removexattr);
        SCAN_FUNCTION(arg.inode_need_killpriv);
        SCAN_FUNCTION(arg.inode_killpriv);
        SCAN_FUNCTION(arg.inode_getsecurity);
        SCAN_FUNCTION(arg.inode_setsecurity);
        SCAN_FUNCTION(arg.inode_listsecurity);
        SCAN_FUNCTION(arg.inode_getsecid);
        SCAN_FUNCTION(arg.file_permission);
        SCAN_FUNCTION(arg.file_alloc_security);
        SCAN_FUNCTION(arg.file_free_security);
        SCAN_FUNCTION(arg.file_ioctl);
        SCAN_FUNCTION(arg.mmap_addr);
        SCAN_FUNCTION(arg.mmap_file);
        SCAN_FUNCTION(arg.file_mprotect);
        SCAN_FUNCTION(arg.file_lock);
        SCAN_FUNCTION(arg.file_fcntl);
        SCAN_FUNCTION(arg.file_set_fowner);
        SCAN_FUNCTION(arg.file_send_sigiotask);
        SCAN_FUNCTION(arg.file_receive);
        SCAN_FUNCTION(arg.file_open);
        SCAN_FUNCTION(arg.task_create);
        SCAN_FUNCTION(arg.task_free);
        SCAN_FUNCTION(arg.cred_alloc_blank);
        SCAN_FUNCTION(arg.cred_free);
        SCAN_FUNCTION(arg.cred_prepare);
        SCAN_FUNCTION(arg.cred_transfer);
        SCAN_FUNCTION(arg.kernel_act_as);
        SCAN_FUNCTION(arg.kernel_create_files_as);
        SCAN_FUNCTION(arg.kernel_module_request);
        SCAN_FUNCTION(arg.kernel_module_from_file);
        SCAN_FUNCTION(arg.task_fix_setuid);
        SCAN_FUNCTION(arg.task_setpgid);
        SCAN_FUNCTION(arg.task_getpgid);
        SCAN_FUNCTION(arg.task_getsid);
        SCAN_FUNCTION(arg.task_getsecid);
        SCAN_FUNCTION(arg.task_setnice);
        SCAN_FUNCTION(arg.task_setioprio);
        SCAN_FUNCTION(arg.task_getioprio);
        SCAN_FUNCTION(arg.task_setrlimit);
        SCAN_FUNCTION(arg.task_setscheduler);
        SCAN_FUNCTION(arg.task_getscheduler);
        SCAN_FUNCTION(arg.task_movememory);
        SCAN_FUNCTION(arg.task_kill);
        SCAN_FUNCTION(arg.task_wait);
        SCAN_FUNCTION(arg.task_prctl);
        SCAN_FUNCTION(arg.task_to_inode);
        SCAN_FUNCTION(arg.ipc_permission);
        SCAN_FUNCTION(arg.ipc_getsecid);
        SCAN_FUNCTION(arg.msg_msg_alloc_security);
        SCAN_FUNCTION(arg.msg_msg_free_security);
        SCAN_FUNCTION(arg.msg_queue_alloc_security);
        SCAN_FUNCTION(arg.msg_queue_free_security);
        SCAN_FUNCTION(arg.msg_queue_associate);
        SCAN_FUNCTION(arg.msg_queue_msgctl);
        SCAN_FUNCTION(arg.msg_queue_msgsnd);
        SCAN_FUNCTION(arg.msg_queue_msgrcv);
        SCAN_FUNCTION(arg.shm_alloc_security);
        SCAN_FUNCTION(arg.shm_free_security);
        SCAN_FUNCTION(arg.shm_associate);
        SCAN_FUNCTION(arg.shm_shmctl);
        SCAN_FUNCTION(arg.shm_shmat);
        SCAN_FUNCTION(arg.sem_alloc_security);
        SCAN_FUNCTION(arg.sem_free_security);
        SCAN_FUNCTION(arg.sem_associate);
        SCAN_FUNCTION(arg.sem_semctl);
        SCAN_FUNCTION(arg.sem_semop);
        SCAN_FUNCTION(arg.netlink_send);
        SCAN_FUNCTION(arg.d_instantiate);
        SCAN_FUNCTION(arg.getprocattr);
        SCAN_FUNCTION(arg.setprocattr);
        SCAN_FUNCTION(arg.secid_to_secctx);
        SCAN_FUNCTION(arg.secctx_to_secid);
        SCAN_FUNCTION(arg.release_secctx);
        SCAN_FUNCTION(arg.inode_notifysecctx);
        SCAN_FUNCTION(arg.inode_setsecctx);
        SCAN_FUNCTION(arg.inode_getsecctx);
        SCAN_FUNCTION(arg.unix_stream_connect);
        SCAN_FUNCTION(arg.unix_may_send);
        SCAN_FUNCTION(arg.socket_create);
        SCAN_FUNCTION(arg.socket_post_create);
        SCAN_FUNCTION(arg.socket_bind);
        SCAN_FUNCTION(arg.socket_connect);
        SCAN_FUNCTION(arg.socket_listen);
        SCAN_FUNCTION(arg.socket_accept);
        SCAN_FUNCTION(arg.socket_sendmsg);
        SCAN_FUNCTION(arg.socket_recvmsg);
        SCAN_FUNCTION(arg.socket_getsockname);
        SCAN_FUNCTION(arg.socket_getpeername);
        SCAN_FUNCTION(arg.socket_getsockopt);
        SCAN_FUNCTION(arg.socket_setsockopt);
        SCAN_FUNCTION(arg.socket_shutdown);
        SCAN_FUNCTION(arg.socket_sock_rcv_skb);
        SCAN_FUNCTION(arg.socket_getpeersec_stream);
        SCAN_FUNCTION(arg.socket_getpeersec_dgram);
        SCAN_FUNCTION(arg.sk_alloc_security);
        SCAN_FUNCTION(arg.sk_free_security);
        SCAN_FUNCTION(arg.sk_clone_security);
        SCAN_FUNCTION(arg.sk_getsecid);
        SCAN_FUNCTION(arg.sock_graft);
        SCAN_FUNCTION(arg.inet_conn_request);
        SCAN_FUNCTION(arg.inet_csk_clone);
        SCAN_FUNCTION(arg.inet_conn_established);
        SCAN_FUNCTION(arg.secmark_relabel_packet);
        SCAN_FUNCTION(arg.secmark_refcount_inc);
        SCAN_FUNCTION(arg.secmark_refcount_dec);
        SCAN_FUNCTION(arg.req_classify_flow);
        SCAN_FUNCTION(arg.tun_dev_alloc_security);
        SCAN_FUNCTION(arg.tun_dev_free_security);
        SCAN_FUNCTION(arg.tun_dev_create);
        SCAN_FUNCTION(arg.tun_dev_attach_queue);
        SCAN_FUNCTION(arg.tun_dev_attach);
        SCAN_FUNCTION(arg.tun_dev_open);
        SCAN_FUNCTION(arg.key_alloc);
        SCAN_FUNCTION(arg.key_free);
        SCAN_FUNCTION(arg.key_permission);
        SCAN_FUNCTION(arg.key_getsecurity);
        SCAN_FUNCTION(arg.audit_rule_init);
        SCAN_FUNCTION(arg.audit_rule_known);
        SCAN_FUNCTION(arg.audit_rule_match);
        SCAN_FUNCTION(arg.audit_rule_free);
    }
})
#endif


//#define SCANNER_FOR_struct_execute_work
#ifndef SCANNER_FOR_struct_execute_work
#define SCANNER_FOR_struct_execute_work
TYPE_SCAN_WRAPPER(struct execute_work, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct execute_work);
    }
    SCAN {
        S(kern_printk( "struct execute_work\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.work);
    }
})
#endif


//#define SCANNER_FOR_struct_srcu_notifier_head
#ifndef SCANNER_FOR_struct_srcu_notifier_head
#define SCANNER_FOR_struct_srcu_notifier_head
TYPE_SCAN_WRAPPER(struct srcu_notifier_head, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct srcu_notifier_head);
    }
    SCAN {
        S(kern_printk( "struct srcu_notifier_head\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.mutex);
        SCAN_RECURSIVE(arg.srcu);
        SCAN_RECURSIVE_PTR(arg.head);
    }
})
#endif


//#define SCANNER_FOR_struct_x86_msi_ops
#ifndef SCANNER_FOR_struct_x86_msi_ops
#define SCANNER_FOR_struct_x86_msi_ops
TYPE_SCAN_WRAPPER(struct x86_msi_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct x86_msi_ops);
    }
    SCAN {
        S(kern_printk( "struct x86_msi_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.setup_msi_irqs);
        SCAN_FUNCTION(arg.teardown_msi_irq);
        SCAN_FUNCTION(arg.teardown_msi_irqs);
        SCAN_FUNCTION(arg.restore_msi_irqs);
    }
})
#endif


//#define SCANNER_FOR_struct_raw6_sock
#ifndef SCANNER_FOR_struct_raw6_sock
#define SCANNER_FOR_struct_raw6_sock
TYPE_SCAN_WRAPPER(struct raw6_sock, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct raw6_sock);
    }
    SCAN {
        S(kern_printk( "struct raw6_sock\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.inet);
        SCAN_FUNCTION(arg.checksum);
        SCAN_FUNCTION(arg.offset);
        SCAN_RECURSIVE(arg.filter);
        SCAN_FUNCTION(arg.ip6mr_table);
        SCAN_RECURSIVE(arg.inet6);
    }
})
#endif


//#define SCANNER_FOR_struct_pci_fixup
#ifndef SCANNER_FOR_struct_pci_fixup
#define SCANNER_FOR_struct_pci_fixup
TYPE_SCAN_WRAPPER(struct pci_fixup, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct pci_fixup);
    }
    SCAN {
        S(kern_printk( "struct pci_fixup\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.vendor);
        SCAN_FUNCTION(arg.device);
        SCAN_FUNCTION(arg.class_);
        SCAN_FUNCTION(arg.class_shift);
        SCAN_FUNCTION(arg.hook);
    }
})
#endif


//#define SCANNER_FOR_struct_packet_offload
#ifndef SCANNER_FOR_struct_packet_offload
#define SCANNER_FOR_struct_packet_offload
TYPE_SCAN_WRAPPER(struct packet_offload, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct packet_offload);
    }
    SCAN {
        S(kern_printk( "struct packet_offload\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.type);
        SCAN_RECURSIVE(arg.callbacks);
        SCAN_RECURSIVE(arg.list);
    }
})
#endif


//#define SCANNER_FOR_struct_tasklet_hrtimer
#ifndef SCANNER_FOR_struct_tasklet_hrtimer
#define SCANNER_FOR_struct_tasklet_hrtimer
TYPE_SCAN_WRAPPER(struct tasklet_hrtimer, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tasklet_hrtimer);
    }
    SCAN {
        S(kern_printk( "struct tasklet_hrtimer\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.timer);
        SCAN_RECURSIVE(arg.tasklet);
        SCAN_FUNCTION(arg.function);
    }
})
#endif


//#define SCANNER_FOR_struct_bio_pair
#ifndef SCANNER_FOR_struct_bio_pair
#define SCANNER_FOR_struct_bio_pair
TYPE_SCAN_WRAPPER(struct bio_pair, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct bio_pair);
    }
    SCAN {
        S(kern_printk( "struct bio_pair\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.bio1);
        SCAN_RECURSIVE(arg.bio2);
        SCAN_RECURSIVE(arg.bv1);
        SCAN_RECURSIVE(arg.bv2);
        SCAN_RECURSIVE(arg.bip1);
        SCAN_RECURSIVE(arg.bip2);
        SCAN_RECURSIVE(arg.iv1);
        SCAN_RECURSIVE(arg.iv2);
        SCAN_RECURSIVE(arg.cnt);
        SCAN_FUNCTION(arg.error);
    }
})
#endif


//#define SCANNER_FOR_struct_rt_mutex
#ifndef SCANNER_FOR_struct_rt_mutex
#define SCANNER_FOR_struct_rt_mutex
TYPE_SCAN_WRAPPER(struct rt_mutex, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct rt_mutex);
    }
    SCAN {
        S(kern_printk( "struct rt_mutex\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.wait_lock);
        SCAN_RECURSIVE(arg.wait_list);
        SCAN_RECURSIVE_PTR(arg.owner);
    }
})
#endif


//#define SCANNER_FOR_struct_dm_target_io
#ifndef SCANNER_FOR_struct_dm_target_io
#define SCANNER_FOR_struct_dm_target_io
TYPE_SCAN_WRAPPER(struct dm_target_io, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct dm_target_io);
    }
    SCAN {
        S(kern_printk( "struct dm_target_io\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.io);
        SCAN_RECURSIVE_PTR(arg.ti);
//  Union(union map_info) arg.info
        SCAN_FUNCTION(arg.target_request_nr);
        SCAN_RECURSIVE(arg.clone);
    }
})
#endif


#define SCANNER_FOR_struct_class_dev_iter
#ifndef SCANNER_FOR_struct_class_dev_iter
#define SCANNER_FOR_struct_class_dev_iter
TYPE_SCAN_WRAPPER(struct class_dev_iter, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct class_dev_iter);
    }
    SCAN {
        S(kern_printk( "struct class_dev_iter\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.ki);
        SCAN_RECURSIVE_PTR(arg.type);
    }
})
#endif


#define SCANNER_FOR_struct_qdisc_watchdog
#ifndef SCANNER_FOR_struct_qdisc_watchdog
#define SCANNER_FOR_struct_qdisc_watchdog
TYPE_SCAN_WRAPPER(struct qdisc_watchdog, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct qdisc_watchdog);
    }
    SCAN {
        S(kern_printk( "struct qdisc_watchdog\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.timer);
        SCAN_RECURSIVE_PTR(arg.qdisc);
    }
})
#endif


#define SCANNER_FOR_struct_netlink_skb_parms
#ifndef SCANNER_FOR_struct_netlink_skb_parms
#define SCANNER_FOR_struct_netlink_skb_parms
TYPE_SCAN_WRAPPER(struct netlink_skb_parms, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netlink_skb_parms);
    }
    SCAN {
        S(kern_printk( "struct netlink_skb_parms\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.creds);
        SCAN_FUNCTION(arg.portid);
        SCAN_FUNCTION(arg.dst_group);
        SCAN_RECURSIVE_PTR(arg.ssk);
    }
})
#endif


#define SCANNER_FOR_struct_nf_hook_ops
#ifndef SCANNER_FOR_struct_nf_hook_ops
#define SCANNER_FOR_struct_nf_hook_ops
TYPE_SCAN_WRAPPER(struct nf_hook_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct nf_hook_ops);
    }
    SCAN {
        S(kern_printk( "struct nf_hook_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.list);
        SCAN_FUNCTION(arg.hook);
        SCAN_RECURSIVE_PTR(arg.owner);
        SCAN_FUNCTION(arg.pf);
        SCAN_FUNCTION(arg.hooknum);
        SCAN_FUNCTION(arg.priority);
    }
})
#endif


#define SCANNER_FOR_struct_cipher_desc
#ifndef SCANNER_FOR_struct_cipher_desc
#define SCANNER_FOR_struct_cipher_desc
TYPE_SCAN_WRAPPER(struct cipher_desc, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct cipher_desc);
    }
    SCAN {
        S(kern_printk( "struct cipher_desc\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.tfm);
        SCAN_FUNCTION(arg.crfn);
        SCAN_FUNCTION(arg.prfn);
        SCAN_FUNCTION(arg.info);
    }
})
#endif


#define SCANNER_FOR_struct_netlink_dump_control
#ifndef SCANNER_FOR_struct_netlink_dump_control
#define SCANNER_FOR_struct_netlink_dump_control
TYPE_SCAN_WRAPPER(struct netlink_dump_control, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct netlink_dump_control);
    }
    SCAN {
        S(kern_printk( "struct netlink_dump_control\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.dump);
        SCAN_FUNCTION(arg.done);
        SCAN_FUNCTION(arg.data);
        SCAN_RECURSIVE_PTR(arg.module);
        SCAN_FUNCTION(arg.min_dump_alloc);
    }
})
#endif


#define SCANNER_FOR_struct_x86_io_apic_ops
#ifndef SCANNER_FOR_struct_x86_io_apic_ops
#define SCANNER_FOR_struct_x86_io_apic_ops
TYPE_SCAN_WRAPPER(struct x86_io_apic_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct x86_io_apic_ops);
    }
    SCAN {
        S(kern_printk( "struct x86_io_apic_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.init);
        SCAN_FUNCTION(arg.read);
        SCAN_FUNCTION(arg.write);
        SCAN_FUNCTION(arg.modify);
    }
})
#endif


#define SCANNER_FOR_struct_packet_type
#ifndef SCANNER_FOR_struct_packet_type
#define SCANNER_FOR_struct_packet_type
TYPE_SCAN_WRAPPER(struct packet_type, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct packet_type);
    }
    SCAN {
        S(kern_printk( "struct packet_type\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.type);
        SCAN_RECURSIVE_PTR(arg.dev);
        SCAN_FUNCTION(arg.func);
        SCAN_FUNCTION(arg.id_match);
        SCAN_FUNCTION(arg.af_packet_priv);
        SCAN_RECURSIVE(arg.list);
    }
})
#endif


#define SCANNER_FOR_struct_subprocess_info
#ifndef SCANNER_FOR_struct_subprocess_info
#define SCANNER_FOR_struct_subprocess_info
TYPE_SCAN_WRAPPER(struct subprocess_info, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct subprocess_info);
    }
    SCAN {
        S(kern_printk( "struct subprocess_info\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.work);
        SCAN_RECURSIVE_PTR(arg.complete);
        SCAN_FUNCTION(arg.path);
//  Pointer(Pointer(BuiltIn(char))) arg.argv
//  Pointer(Pointer(BuiltIn(char))) arg.envp
        SCAN_FUNCTION(arg.wait);
        SCAN_FUNCTION(arg.retval);
        SCAN_FUNCTION(arg.init);
        SCAN_FUNCTION(arg.cleanup);
        SCAN_FUNCTION(arg.data);
    }
})
#endif


#define SCANNER_FOR_struct_x86_init_ops
#ifndef SCANNER_FOR_struct_x86_init_ops
#define SCANNER_FOR_struct_x86_init_ops
TYPE_SCAN_WRAPPER(struct x86_init_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct x86_init_ops);
    }
    SCAN {
        S(kern_printk( "struct x86_init_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.resources);
        SCAN_RECURSIVE(arg.mpparse);
        SCAN_RECURSIVE(arg.irqs);
        SCAN_RECURSIVE(arg.oem);
        SCAN_RECURSIVE(arg.mapping);
        SCAN_RECURSIVE(arg.paging);
        SCAN_RECURSIVE(arg.timers);
        SCAN_RECURSIVE(arg.iommu);
        SCAN_RECURSIVE(arg.pci);
    }
})
#endif


//#define SCANNER_FOR_struct_crypto_cipher
#ifndef SCANNER_FOR_struct_crypto_cipher
#define SCANNER_FOR_struct_crypto_cipher
TYPE_SCAN_WRAPPER(struct crypto_cipher, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct crypto_cipher);
    }
    SCAN {
        S(kern_printk( "struct crypto_cipher\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.base);
    }
})
#endif


//#define SCANNER_FOR_struct_zap_details
#ifndef SCANNER_FOR_struct_zap_details
#define SCANNER_FOR_struct_zap_details
TYPE_SCAN_WRAPPER(struct zap_details, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct zap_details);
    }
    SCAN {
        S(kern_printk( "struct zap_details\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE_PTR(arg.nonlinear_vma);
        SCAN_RECURSIVE_PTR(arg.check_mapping);
        SCAN_FUNCTION(arg.first_index);
        SCAN_FUNCTION(arg.last_index);
    }
})
#endif


//#define SCANNER_FOR_struct_x86_cpuinit_ops
#ifndef SCANNER_FOR_struct_x86_cpuinit_ops
#define SCANNER_FOR_struct_x86_cpuinit_ops
TYPE_SCAN_WRAPPER(struct x86_cpuinit_ops, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct x86_cpuinit_ops);
    }
    SCAN {
        S(kern_printk( "struct x86_cpuinit_ops\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.setup_percpu_clockev);
        SCAN_FUNCTION(arg.early_percpu_clock_init);
        SCAN_FUNCTION(arg.fixup_cpu_id);
    }
})
#endif


//#define SCANNER_FOR_struct_mb_cache_entry
#ifndef SCANNER_FOR_struct_mb_cache_entry
#define SCANNER_FOR_struct_mb_cache_entry
TYPE_SCAN_WRAPPER(struct mb_cache_entry, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct mb_cache_entry);
    }
    SCAN {
        S(kern_printk( "struct mb_cache_entry\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.e_lru_list);
        SCAN_RECURSIVE_PTR(arg.e_cache);
        SCAN_FUNCTION(arg.e_used);
        SCAN_FUNCTION(arg.e_queued);
        SCAN_RECURSIVE_PTR(arg.e_bdev);
        SCAN_FUNCTION(arg.e_block);
        SCAN_RECURSIVE(arg.e_block_list);
        SCAN_RECURSIVE(arg.e_index);
    }
})
#endif


//#define SCANNER_FOR_struct_kobj_attribute
#ifndef SCANNER_FOR_struct_kobj_attribute
#define SCANNER_FOR_struct_kobj_attribute
TYPE_SCAN_WRAPPER(struct kobj_attribute, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct kobj_attribute);
    }
    SCAN {
        S(kern_printk( "struct kobj_attribute\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.attr);
        SCAN_FUNCTION(arg.show);
        SCAN_FUNCTION(arg.store);
    }
})
#endif


//#define SCANNER_FOR_struct_ahash_alg
#ifndef SCANNER_FOR_struct_ahash_alg
#define SCANNER_FOR_struct_ahash_alg
TYPE_SCAN_WRAPPER(struct ahash_alg, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct ahash_alg);
    }
    SCAN {
        S(kern_printk( "struct ahash_alg\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.init);
        SCAN_FUNCTION(arg.update);
        SCAN_FUNCTION(arg.final);
        SCAN_FUNCTION(arg.finup);
        SCAN_FUNCTION(arg.digest);
        SCAN_FUNCTION(arg.export_);
        SCAN_FUNCTION(arg.import);
        SCAN_FUNCTION(arg.setkey);
        SCAN_RECURSIVE(arg.halg);
    }
})
#endif


//#define SCANNER_FOR_struct_uprobe_consumer
#ifndef SCANNER_FOR_struct_uprobe_consumer
#define SCANNER_FOR_struct_uprobe_consumer
TYPE_SCAN_WRAPPER(struct uprobe_consumer, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct uprobe_consumer);
    }
    SCAN {
        S(kern_printk( "struct uprobe_consumer\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_FUNCTION(arg.handler);
        SCAN_FUNCTION(arg.filter);
        SCAN_RECURSIVE_PTR(arg.next);
    }
})
#endif


//#define SCANNER_FOR_struct_tick_sched
#ifndef SCANNER_FOR_struct_tick_sched
#define SCANNER_FOR_struct_tick_sched
TYPE_SCAN_WRAPPER(struct tick_sched, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct tick_sched);
    }
    SCAN {
        S(kern_printk( "struct tick_sched\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.sched_timer);
        SCAN_FUNCTION(arg.check_clocks);
//  Enum(enum tick_nohz_mode) arg.nohz_mode
//  Union(union ktime) arg.last_tick
        SCAN_FUNCTION(arg.inidle);
        SCAN_FUNCTION(arg.tick_stopped);
        SCAN_FUNCTION(arg.idle_jiffies);
        SCAN_FUNCTION(arg.idle_calls);
        SCAN_FUNCTION(arg.idle_sleeps);
        SCAN_FUNCTION(arg.idle_active);
//  Union(union ktime) arg.idle_entrytime
//  Union(union ktime) arg.idle_waketime
//  Union(union ktime) arg.idle_exittime
//  Union(union ktime) arg.idle_sleeptime
//  Union(union ktime) arg.iowait_sleeptime
//  Union(union ktime) arg.sleep_length
        SCAN_FUNCTION(arg.last_jiffies);
        SCAN_FUNCTION(arg.next_jiffies);
//  Union(union ktime) arg.idle_expires
        SCAN_FUNCTION(arg.do_timer_last);
    }
})
#endif


//#define SCANNER_FOR_struct_paravirt_patch_template
#ifndef SCANNER_FOR_struct_paravirt_patch_template
#define SCANNER_FOR_struct_paravirt_patch_template
TYPE_SCAN_WRAPPER(struct paravirt_patch_template, {
    SCAN_HEAD{
        DECLARE_HASH(htable);
        SCANNER(struct paravirt_patch_template);
    }
    SCAN {
        S(kern_printk( "struct paravirt_patch_template\n");)
        S(SCAN_OBJECT(arg);)
        SCAN_RECURSIVE(arg.pv_init_ops);
        SCAN_RECURSIVE(arg.pv_time_ops);
        SCAN_RECURSIVE(arg.pv_cpu_ops);
        SCAN_RECURSIVE(arg.pv_irq_ops);
        SCAN_RECURSIVE(arg.pv_apic_ops);
        SCAN_RECURSIVE(arg.pv_mmu_ops);
        SCAN_RECURSIVE(arg.pv_lock_ops);
    }
})
#endif


