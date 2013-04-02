#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xc6800fde, "module_layout" },
	{ 0xddd58dc0, "ring_buffer_reset" },
	{ 0xd9ecb670, "ring_buffer_overruns" },
	{ 0xfa66f77c, "finish_wait" },
	{ 0x1000e51, "schedule" },
	{ 0xf1bea6f1, "schedule_delayed_work" },
	{ 0x6d27ef64, "__bitmap_empty" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0x96f9e02e, "mutex_lock_killable" },
	{ 0xd87601cc, "ring_buffer_unlock_commit" },
	{ 0x9621849f, "ring_buffer_event_data" },
	{ 0x918ad429, "ring_buffer_lock_reserve" },
	{ 0x838b13e7, "ring_buffer_free" },
	{ 0xfb5f846a, "cancel_delayed_work_sync" },
	{ 0xfb0e29f, "init_timer_key" },
	{ 0x6395be94, "__init_waitqueue_head" },
	{ 0xfe7c4287, "nr_cpu_ids" },
	{ 0xc0a3d105, "find_next_bit" },
	{ 0xf4fc2d6c, "__ring_buffer_alloc" },
	{ 0x4b5814ef, "kmalloc_order_trace" },
	{ 0x8f64aa4, "_raw_spin_unlock_irqrestore" },
	{ 0x9327f5ce, "_raw_spin_lock_irqsave" },
	{ 0x4c4fef19, "kernel_stack" },
	{ 0xc87c1f84, "ktime_get" },
	{ 0x5860aad4, "add_wait_queue" },
	{ 0xcf21d241, "__wake_up" },
	{ 0x3cbbfcf, "mutex_lock" },
	{ 0x5e9ffa98, "__mutex_init" },
	{ 0xa886a958, "krealloc" },
	{ 0x4f8b5ddb, "_copy_to_user" },
	{ 0x8e109868, "mutex_lock_interruptible" },
	{ 0x8223cea0, "mutex_unlock" },
	{ 0x236c8c64, "memcpy" },
	{ 0xe914e41e, "strcpy" },
	{ 0x7ec9bfbc, "strncpy" },
	{ 0x7852bba7, "pid_vnr" },
	{ 0x6d622e78, "current_task" },
	{ 0x3c80c06c, "kstrtoull" },
	{ 0x4f6b400b, "_copy_from_user" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0x87c441ad, "nonseekable_open" },
	{ 0x5a5e7ea3, "simple_read_from_buffer" },
	{ 0x510f417b, "debugfs_create_file" },
	{ 0xfdf9b5eb, "debugfs_create_dir" },
	{ 0xef21232c, "debugfs_remove" },
	{ 0x25ec1b28, "strlen" },
	{ 0x4cf9efc5, "sysfs_create_file" },
	{ 0x50720c5f, "snprintf" },
	{ 0x5a34a45c, "__kmalloc" },
	{ 0xb9249d16, "cpu_possible_mask" },
	{ 0xbbaacecd, "kobject_add" },
	{ 0x1b386fbf, "kobject_init" },
	{ 0xb47d9bba, "kmem_cache_alloc_trace" },
	{ 0x5a56b781, "kmalloc_caches" },
	{ 0x4cbbd171, "__bitmap_weight" },
	{ 0x341cbed2, "cpu_present_mask" },
	{ 0x9f46ced8, "__sw_hweight64" },
	{ 0x27e1a049, "printk" },
	{ 0x37a0cba, "kfree" },
	{ 0x619e82bd, "kobject_put" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "1C49A0E1E51F5A696D0726C");
