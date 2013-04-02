#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xc6800fde, "module_layout" },
	{ 0xb47d9bba, "kmem_cache_alloc_trace" },
	{ 0x5a56b781, "kmalloc_caches" },
	{ 0xe52592a, "panic" },
	{ 0x10f2eb76, "vsnprintf" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x8b722ec1, "__register_chrdev" },
	{ 0x60d1064, "set_memory_ro" },
	{ 0xefdb47c6, "kmem_cache_free" },
	{ 0x999e8297, "vfree" },
	{ 0xf97666a0, "set_memory_rw" },
	{ 0x37a0cba, "kfree" },
	{ 0x9efdc5ac, "dr_hotpatch_interface" },
	{ 0x3928efe9, "__per_cpu_offset" },
	{ 0x4cbbd171, "__bitmap_weight" },
	{ 0xb9249d16, "cpu_possible_mask" },
	{ 0x4f8b5ddb, "_copy_to_user" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x5541ea93, "on_each_cpu" },
	{ 0x4f53d1f2, "dr_pre_smp_init" },
	{ 0x4f6b400b, "_copy_from_user" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0x3fa0abfa, "dr_smp_exit" },
	{ 0xc908ef0a, "dr_smp_init" },
	{ 0x7628f3c7, "this_cpu_off" },
	{ 0x27e1a049, "printk" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=dynamorio";


MODULE_INFO(srcversion, "4EB78BD2606A155E805380D");
