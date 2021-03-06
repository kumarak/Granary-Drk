/*
 * cfi_util.c
 *
 *  Created on: 2013-01-19
 *      Author: akshayk
 */

#include <linux/slab.h>
#include "cfi_utils.h"

/* Enlarges the buffer to make it at least 'new_size' bytes in size.
 * If 'new_size' is less than or equal to 'ob->size', the function does
 * nothing.
 * If there is not enough memory, the function outputs an error to
 * the system log, leaves the buffer intact and returns -ENOMEM.
 * 0 is returned in case of success. */
static int
granary_output_buffer_resize(struct granary_output_buffer *ob, size_t new_size)
{
	size_t size;
	void *p;
	BUG_ON(ob == NULL);

	if (ob->size >= new_size)
		return 0;

	size = ob->size;
	do {
		size *= 2;
	} while (size < new_size);

	p = vmalloc((size_t)size);
	if (p == NULL) {
		pr_warning("granary_output_buffer_resize(): "
	"not enough memory to resize the output buffer to %zu bytes\n",
			size);
		return -ENOMEM;
	}

	memcpy(p, ob->buf, ob->size);
	vfree(ob->buf);
	ob->buf = p;
	ob->buf[ob->data_len] = '\0';
	ob->size = size;
	return 0;
}

/* Appends the specified string to the buffer, enlarging the latter if
 * necessary with klc_output_buffer_resize(). */
static void
granary_output_buffer_append(struct granary_output_buffer *ob, const char *s)
{
	size_t len;
	int ret;

	BUG_ON(ob == NULL);
	BUG_ON(ob->buf[ob->data_len] != 0);
	BUG_ON(s == NULL);

	len = strlen(s);
	if (len == 0)   /* nothing to do */
		return;

	/* make sure the buffer is large enough */
	ret = granary_output_buffer_resize(ob, ob->data_len + len + 1);
	if (ret != 0)
		return; /* the error has already been reported */

	strncpy(&(ob->buf[ob->data_len]), s, len + 1);
	ob->data_len += len;
}

/* ====================================================================== */

void
granary_print_string(struct granary_ld_output *output,
		enum granary_output_type output_type, const char *s)
{
	struct granary_output_buffer *ob = NULL;

	BUG_ON(s == NULL);

	switch (output_type) {
		case GRANARY_UNFREED_ALLOC:
			ob = &output->ob_leaks;
			break;
		case GRANARY_BAD_FREE:
			ob = &output->ob_bad_frees;
			break;
		case GRANARY_OTHER:
			ob = &output->ob_other;
			break;
		default:
		pr_warning("unknown output type: %d\n",
			(int)output_type);
		return;
	}
	BUG_ON(ob->buf == NULL);

	if (mutex_lock_killable(&ob->lock) != 0)
	{
		pr_warning("granary_print_string(): "
			"got a signal while trying to acquire a mutex.\n");
		return;
	}

	granary_output_buffer_append(ob, s);
	granary_output_buffer_append(ob, "\n");

/*	if (syslog_output)
		pr_warning("%s\n", s);
*/
	mutex_unlock(&ob->lock);
}

void
granary_print_module_info(struct granary_ld_output *output, struct module *target)
{
	static const char* fmt = "Target module: \"%s\", init area at 0x%p, core area at 0x%p";
	char *buf = NULL;
	int len;
	const char *name;

	/* get module name*/
	name = module_name(target);

	len = snprintf(NULL, 0, fmt, name, target->module_init, target->module_core);

	buf = kmalloc(len + 1, GFP_KERNEL);
	if (buf == NULL) {
		pr_warning("granary_print_module_info(): "
				"not enough memory to prepare a message of size %d\n",len);
	}

	snprintf(buf, len + 1, fmt, name, target->module_init, target->module_core);
	//granary_print_string(output, GRANARY_OTHER, buf);
	//printk("%s", buf);
	kfree(buf);
}
