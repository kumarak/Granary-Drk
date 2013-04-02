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
	{ 0xa2c56c31, "param_ops_ulong" },
	{ 0xbf8ba54a, "vprintk" },
	{ 0x5541ea93, "on_each_cpu" },
	{ 0x47c7b0d2, "cpu_number" },
	{ 0x341cbed2, "cpu_present_mask" },
	{ 0x4b5814ef, "kmalloc_order_trace" },
	{ 0x4c4fef19, "kernel_stack" },
	{ 0x795554d7, "init_task" },
	{ 0x28065042, "find_symbol" },
	{ 0xbc15958a, "__module_address" },
	{ 0xe52592a, "panic" },
	{ 0x2699fc09, "find_module" },
	{ 0x9967be6e, "module_mutex" },
	{ 0x999e8297, "vfree" },
	{ 0x3928efe9, "__per_cpu_offset" },
	{ 0x4cbbd171, "__bitmap_weight" },
	{ 0xbd100793, "cpu_online_mask" },
	{ 0x27e1a049, "printk" },
	{ 0xee60511d, "kallsyms_on_each_symbol" },
	{ 0x37a0cba, "kfree" },
	{ 0x661601de, "sprint_symbol" },
	{ 0x5a34a45c, "__kmalloc" },
	{ 0x9f46ced8, "__sw_hweight64" },
	{ 0xe52947e7, "__phys_addr" },
	{ 0x11089ac7, "_ctype" },
	{ 0xaafdc258, "strcasecmp" },
	{ 0x2fa5a500, "memcmp" },
	{ 0x85abc85f, "strncmp" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x42224298, "sscanf" },
	{ 0x234509f3, "strncat" },
	{ 0xde0bdcff, "memset" },
	{ 0x236c8c64, "memcpy" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x7ec9bfbc, "strncpy" },
	{ 0x25ec1b28, "strlen" },
	{ 0xa3a5be95, "memmove" },
	{ 0x1e6d26a8, "strstr" },
	{ 0x349cba85, "strchr" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "3AB6770E935FBCF1F04D3C5");
