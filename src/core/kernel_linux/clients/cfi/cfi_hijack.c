#include "cfi_module.h"
#if 0
struct kernsym locale_sys_init_module;

#define OP_JMP_REL32	0xe9
#define OP_CALL_REL32	0xe8

#ifdef CONFIG_X86_64
# define CODE_ADDR_FROM_OFFSET(insn_addr, insn_len, offset) \
	(void*)((s64)(insn_addr) + (s64)(insn_len) + (s64)(s32)(offset))
#else
# define CODE_ADDR_FROM_OFFSET(insn_addr, insn_len, offset) \
	(void*)((u32)(insn_addr) + (u32)(insn_len) + (u32)(offset))
#endif

#define CODE_OFFSET_FROM_ADDR(insn_addr, insn_len, dest_addr) \
	(u32)(dest_addr - (insn_addr + (u32)insn_len))

void copy_and_fixup_insn(struct insn *src_insn, void *dest,
	const struct kernsym *func) {

	u32 *to_fixup;
	unsigned long addr;
	BUG_ON(src_insn->length == 0);

	memcpy((void *)dest, (const void *)src_insn->kaddr,
		src_insn->length);

	if (src_insn->opcode.bytes[0] == OP_CALL_REL32 ||
	    src_insn->opcode.bytes[0] == OP_JMP_REL32) {

		addr = (unsigned long)CODE_ADDR_FROM_OFFSET(
			src_insn->kaddr,
			src_insn->length,
			src_insn->immediate.value);

		if (addr >= (unsigned long)func->addr &&
		    addr < (unsigned long)func->addr + func->size)
			return;

		to_fixup = (u32 *)((unsigned long)dest +
			insn_offset_immediate(src_insn));
		*to_fixup = CODE_OFFSET_FROM_ADDR(dest, src_insn->length,
			(void *)addr);
		return;
	}

#ifdef CONFIG_X86_64
	if (!insn_rip_relative(src_insn))
		return;

	addr = (unsigned long)CODE_ADDR_FROM_OFFSET(
		src_insn->kaddr,
		src_insn->length,
		src_insn->displacement.value);

	if (addr >= (unsigned long)func->addr &&
	    addr < (unsigned long)func->addr + func->size)
		return;

	to_fixup = (u32 *)((unsigned long)dest +
		insn_offset_displacement(src_insn));
	*to_fixup = CODE_OFFSET_FROM_ADDR(dest, src_insn->length,
		(void *)addr);
#endif
	return;
}



void set_addr_rw(unsigned long addr, bool *flag) {
	unsigned int level;
	pte_t *pte;
	*flag = true;

	pte = lookup_address(addr, &level);
	if (pte->pte & _PAGE_RW)
		*flag = false;
	else
		pte->pte |= _PAGE_RW;


}

void set_addr_rx(unsigned long addr, bool flag) {

	unsigned int level;
	pte_t *pte;

	// only set back to readonly if it was readonly before
	//if (flag) {
		pte = lookup_address(addr, &level);
		//pte->pte = pte->pte _PAGE_RW;
		pte->pte = pte->pte & (~_PAGE_NX);
	//}

}


asmlinkage long cfi_sys_init_module(void* umod, unsigned long len, const char* uargs)
{
	asmlinkage long (*run)(void*, unsigned long, const char*) = locale_sys_init_module.run;
	printk("inside cfi_sys_init_module\n");
	return run(umod, len, uargs);
}

int symbol_hijack(struct kernsym *sym, const char *symbol_name, unsigned long *code) {

	int ret;
	unsigned long orig_addr;
	unsigned long dest_addr;
	unsigned long end_addr;
	u32 *poffset;
	struct insn insn;
	bool pte_ro;

	(void) poffset;

	ret = find_symbol_address(sym, symbol_name);


	sym->new_addr = vmalloc(sym->size);

	if (sym->new_addr == NULL) {
		printk("Failed to allocate buffer of size %lu for %s\n",
			sym->size, sym->name);
		return -ENOMEM;
	}

	memset(sym->new_addr, 0, (size_t)sym->size);

	if (sym->size < OP_JMP_SIZE)
		return -EFAULT;

	orig_addr = (unsigned long)sym->addr;
	dest_addr = (unsigned long)sym->new_addr;

	end_addr = orig_addr + sym->size;
	while (end_addr > orig_addr && *(u8 *)(end_addr - 1) == '\0')
		--end_addr;

	if (orig_addr == end_addr) {
		printk("A spurious symbol \"%s\" (address: %p) seems to contain only zeros\n",
			sym->name,
			sym->addr);
		return -EILSEQ;
	}

	while (orig_addr < end_addr) {
		kernel_insn_init(&insn, (void *)orig_addr);
		insn_get_length(&insn);
		if (insn.length == 0) {
			printk("Failed to decode instruction at %p (%s+0x%lx)\n",
				(const void *)orig_addr,
				sym->name,
				orig_addr - (unsigned long)sym->addr);
			return -EILSEQ;
		}

		copy_and_fixup_insn(&insn, (void *)dest_addr, sym);

		orig_addr += insn.length;
		dest_addr += insn.length;
	}

	sym->new_size = dest_addr - (unsigned long)sym->new_addr;

	sym->run = sym->new_addr;

	set_addr_rw((unsigned long) sym->addr, &pte_ro);

	memcpy(&sym->orig_start_bytes[0], sym->addr, OP_JMP_SIZE);

	/**(u8 *)sym->addr = OP_JMP_REL32;
	poffset = (u32 *)((unsigned long)sym->addr + 1);
	*poffset = CODE_OFFSET_FROM_ADDR((unsigned long)sym->addr,
		OP_JMP_SIZE, (unsigned long)code);
*/
	set_addr_rx((unsigned long) sym->addr, pte_ro);
	set_addr_rx((unsigned long) sym->run, pte_ro);

	sym->hijacked = true;

	return ret;
}



void hijack_kernel_calls()
{
	int ret;
	ret = symbol_hijack(&locale_sys_init_module, "sys_init_module", (unsigned long*)cfi_sys_init_module);
}
#endif

struct symhook {
	char *name;
	struct kernsym *sym;
	unsigned long *func;
};

struct symhook security2hook[] = {
	{"security_bprm_check", &sym_security_bprm_check, (unsigned long *)tpe_security_bprm_check},
	{"security_file_mmap", &sym_security_file_mmap, (unsigned long *)tpe_security_file_mmap},
	{"security_file_mprotect", &sym_security_file_mprotect, (unsigned long *)tpe_security_file_mprotect},
	{"proc_sys_write", &sym_proc_sys_write, (unsigned long *)tpe_proc_sys_write},
	{"pid_revalidate", &sym_pid_revalidate, (unsigned long *)tpe_pid_revalidate},
	{"m_show", &sym_m_show, (unsigned long *)tpe_m_show},
	{"kallsyms_open", &sym_kallsyms_open, (unsigned long *)tpe_kallsyms_open},
};

static int
symbol_callback(struct kernsym *sym, const char *name,
                        struct module *mod, unsigned long addr) {

    if(sym->addr && (sym->addr == addr)){
        sym->name = name;
        sym->found = true;
        return 1;
    }

    return 0;
}

int find_symbol_address(struct kernsym *sym, const char *symbol_name) {

	int ret;

	sym->name = (char *)symbol_name;
	sym->found = 0;

	ret = kallsyms_on_each_symbol((void *)symbol_callback, sym);

	if (!ret)
		return -EFAULT;

	sym->size = sym->end_addr - sym->addr;
	sym->new_size = sym->size;
	sym->run = sym->addr;

	return 0;
}

int cfi_symbol_hijack(struct kernsym *sym, const char *symbol_name, unsigned long *code) {

	int ret;
	unsigned long orig_addr;
	unsigned long dest_addr;
	unsigned long end_addr;
	u32 *poffset;
	instr_t *instr;
	bool pte_ro;

	ret = find_symbol_address(sym, symbol_name);

	if (IN_ERR(ret))
		return ret;


	//sym->new_addr = kmalloc(sym->size);



	memset(sym->new_addr, 0, (size_t)sym->size);

	if (sym->size < OP_JMP_SIZE) {
		ret = -EFAULT;
		goto out_error;
	}

	orig_addr = (unsigned long)sym->addr;
	dest_addr = (unsigned long)sym->new_addr;

	end_addr = orig_addr + sym->size;
	while (end_addr > orig_addr && *(u8 *)(end_addr - 1) == '\0')
		--end_addr;

	if (orig_addr == end_addr) {
		printk(PKPRE
			"A spurious symbol \"%s\" (address: %p) seems to contain only zeros\n",
			sym->name,
			sym->addr);
		ret = -EILSEQ;
		goto out_error;
	}

	while (orig_addr < end_addr) {
		kernel_insn_init(&insn, (void *)orig_addr);
		insn_get_length(&insn);
		if (insn.length == 0) {
			printk(PKPRE
				"Failed to decode instruction at %p (%s+0x%lx)\n",
				(const void *)orig_addr,
				sym->name,
				orig_addr - (unsigned long)sym->addr);
			ret = -EILSEQ;
			goto out_error;
		}

		copy_and_fixup_insn(&insn, (void *)dest_addr, sym);

		orig_addr += insn.length;
		dest_addr += insn.length;
	}

	sym->new_size = dest_addr - (unsigned long)sym->new_addr;

	sym->run = sym->new_addr;

	set_addr_rw((unsigned long) sym->addr, &pte_ro);

	memcpy(&sym->orig_start_bytes[0], sym->addr, OP_JMP_SIZE);

	*(u8 *)sym->addr = OP_JMP_REL32;
	poffset = (u32 *)((unsigned long)sym->addr + 1);
	*poffset = CODE_OFFSET_FROM_ADDR((unsigned long)sym->addr,
		OP_JMP_SIZE, (unsigned long)code);

	set_addr_ro((unsigned long) sym->addr, pte_ro);

	sym->hijacked = true;

	return 0;

out_error:
	malloc_free(sym->new_addr);

	return ret;
}

void cfi_hijack_kernel_func(void)
{
	int ret, i;
	for (i = 0; security2hook[i].func; i++) {
		ret = cfi_symbol_hijack(security2hook[i].sym, security2hook[i].name, security2hook[i].func);

		if (IN_ERR(ret))
			printk(security2hook[i].name);
	}

}

