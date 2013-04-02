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


