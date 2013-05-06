/*
 * cfi_notifier.h
 *
 *  Created on: 2013-04-09
 *      Author: akshayk
 */

#ifndef CFI_NOTIFIER_H_
#define CFI_NOTIFIER_H_


struct kernel_module {
    int is_instrumented;
	void *mod;

	void *text_begin;
	void *text_end;

	void *rodata_begin;
	void *rodata_end;

	void *ro_init_begin;
	void *ro_init_end;

	void *data_begin;
	void *data_end;

	void *bss_begin;
	void *bss_end;

	/// The next module object in the list of module objects.
	struct kernel_module *next;
};




#endif /* CFI_NOTIFIER_H_ */
