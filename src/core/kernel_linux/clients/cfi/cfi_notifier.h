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

	/// Various module addresses.
	void *address;

	void *text_begin;
	void *text_end;

	void *ro_text_begin;
	void *ro_text_end;

	void *ro_init_begin;
	void *ro_init_end;

	/// The name.
	const char *name;

	/// The current module state.
	enum {
		STATE_LIVE,
		STATE_COMING,
		STATE_GOING
	} state;

	/// The next module object in the list of module objects.
	struct kernel_module *next;
};

#define MODULE_COUNT 5

struct kernel_module loaded_modules[MODULE_COUNT] = {0,};



#endif /* CFI_NOTIFIER_H_ */
