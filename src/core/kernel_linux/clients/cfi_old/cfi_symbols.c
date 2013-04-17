/*
 * cfi_symbols.c
 *
 *  Created on: 2012-04-08
 *      Author: akshayk
 */



#include "cfi_module.h"


// callback for find_symbol_address

static int find_symbol_callback(struct kernsym *sym, const char *name, struct module *mod, unsigned long addr) {

	if (sym->found) {
		sym->end_addr = (unsigned long *)addr;
		return 1;
	}


	// this symbol was found. the next callback will be the address of the next symbol
	if (name && sym->name && !strcmp(name, sym->name)) {
		sym->addr = (unsigned long *)addr;
		sym->found = true;
	}

	return 0;
}

// find this symbol

int find_symbol_address(struct kernsym *sym, const char *symbol_name) {

	int ret;

	sym->name = (char *)symbol_name;
	sym->found = 0;

	ret = kallsyms_on_each_symbol((void *)find_symbol_callback, sym);

	if (!ret)
		return -EFAULT;

	sym->size = sym->end_addr - sym->addr;
	sym->new_size = sym->size;
	sym->run = sym->addr;

	return 0;
}
