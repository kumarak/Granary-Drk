/*
 * cfi_utils.h
 *
 *  Created on: 2013-01-19
 *      Author: akshayk
 */

#ifndef CFI_UTILS_H_
#define CFI_UTILS_H_

#include <linux/list.h>
#include <linux/spinlock.h>
#include <linux/hash.h>
#include <linux/mutex.h>

#include "cfi_module.h"

#define CFI_ASSERT(x, msg) //{if(!(x)) { break_on_fault(); /* asm("movq 0, %rax;"); */ } }
#define XSP_SZ (sizeof(reg_t))

#define XMM_REG_SIZE  16
#define XMM_SLOTS_SIZE  (NUM_XMM_SLOTS*XMM_REG_SIZE)

/* An output buffer that accumulates strings sent to it by
 * klc_print_string().
 * The buffer grows automatically when necessary.
 * The operations with each such buffer (granary_output_buffer*(), etc.)
 * should be performed with the corresponding mutex locked (see 'lock'
 * field in the structure).
 *
 * The caller must also ensure that no other operations with a buffer can
 * occur during the creation and descruction of the buffer. */
struct granary_output_buffer
{
	/* the buffer itself */
	char *buf;

	/* size of the buffer */
	size_t size;

	/* length of the data stored (excluding the terminating '\0')*/
	size_t data_len;

	/* a mutex to guard access to the buffer */
	struct mutex lock;
};


enum granary_output_type {
	/* possible leaks */
	GRANARY_UNFREED_ALLOC,
	/* bad frees */
	GRANARY_BAD_FREE,
	/* other info: parameters of the target module, totals, ... */
	GRANARY_OTHER
};


/* The structure for the output objects. */
struct granary_ld_output
{
	/* A subdirectory for the output files in debugfs. */
	struct dentry *dir_klc;

	/* The files in debugfs where the output will go. */
	struct dentry *file_leaks;
	struct dentry *file_bad_frees;
	struct dentry *file_stats;

	/* Output buffers for each type of output resource. */
	struct granary_output_buffer ob_leaks;
	struct granary_output_buffer ob_bad_frees;
	struct granary_output_buffer ob_other;
};

static inline uint64_t get_hash_index(uint64_t val, unsigned int bits)
{
    uint64_t hash = val;

    uint64_t n = hash;
    n <<= 18;
    hash -= n;
    n <<= 33;
    hash -= n;
    n <<= 3;
    hash += n;
    n <<= 3;
    hash -= n;
    n <<= 4;
    hash += n;
    n <<= 2;
    hash += n;
    return hash >> (64 - bits);
}

void
granary_print_string(struct granary_ld_output *output,
		enum granary_output_type output_type, const char *s);

void
granary_print_module_info(struct granary_ld_output *output,
		struct module *target);


#endif /* CFI_UTILS_H_ */
