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
	{ 0xb6d58052, "instr_is_stringop_loop" },
	{ 0x1e66639f, "instr_is_stringop" },
	{ 0x299182b8, "dr_stats_free" },
	{ 0xa6f8e07c, "dr_cpu_stat_alloc" },
	{ 0x59b6e6c4, "dr_stats_init" },
	{ 0x1e40bd2e, "dr_register_bb_event" },
	{ 0x1926b102, "dr_register_thread_exit_event" },
	{ 0x398cd26a, "dr_register_thread_init_event" },
	{ 0x2093c13a, "dr_get_options" },
	{ 0x27e1a049, "printk" },
	{ 0x1d5d69bf, "dr_thread_alloc" },
	{ 0xfd1e9485, "dr_thread_free" },
	{ 0xd0da37f3, "instrlist_meta_preinsert" },
	{ 0xf88e66fb, "instr_create_1dst_2src" },
	{ 0x6c1b6c7e, "opnd_create_immed_int" },
	{ 0x8116a007, "opnd_create_rel_addr" },
	{ 0x4b715e6, "dr_save_arith_flags" },
	{ 0xf3f7d1e1, "dr_restore_arith_flags" },
	{ 0xcf3850f5, "instr_get_arith_flags" },
	{ 0xe592208f, "instr_get_next" },
	{ 0x7628f3c7, "this_cpu_off" },
	{ 0x7993e45c, "instrlist_first" },
	{ 0x91715312, "sprintf" },
	{ 0x3928efe9, "__per_cpu_offset" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=dynamorio,dr_kernel_utils";


MODULE_INFO(srcversion, "7F3FA74B593BCF7D9E7397C");
