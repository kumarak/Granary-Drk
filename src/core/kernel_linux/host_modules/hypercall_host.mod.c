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
	{ 0x8495e121, "module_layout" },
	{ 0xc966a971, "kvm_remove_hypercall_callback" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xb518d0c9, "kvm_register_hypercall_callback" },
	{ 0x57089f98, "__register_chrdev" },
	{ 0x71e3cecb, "up" },
	{ 0xcbdea725, "kvm_read_guest" },
	{ 0x5a34a45c, "__kmalloc" },
	{ 0x4f8b5ddb, "_copy_to_user" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0xf22449ae, "down_interruptible" },
	{ 0x8f64aa4, "_raw_spin_unlock_irqrestore" },
	{ 0x37a0cba, "kfree" },
	{ 0x9327f5ce, "_raw_spin_lock_irqsave" },
	{ 0x27e1a049, "printk" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=kvm";


MODULE_INFO(srcversion, "DAF787D343DA10BEE1793CD");
