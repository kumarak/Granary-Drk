
/*
 * includes.h
 *
 *  Created on: 2013-01-17
 *      Author: akshayk
 */

#ifndef DRK_WRAPPER_INCLUDES_H_
#define DRK_WRAPPER_INCLUDES_H_

/*
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
*/

#define DECLARE_HASH(name) struct hashtable_t *htable
#define HASHMAP_PUT //hashmap_put

extern struct module *target_module;
struct kernsym;

extern struct hashtable_t *alloc_pointer_hash;

extern struct hashtable_t *kernel_pointer_hash;

extern struct cfi_list_head atomic_sweep_list;

extern struct hashtable_t *module_watchpoint_map;

extern struct hashtable_t *kernel_variable_hash;

extern int hashmap_init(int initial_size, struct hashtable_t **htable);

extern int hashmap_destroy(struct hashtable_t *htable);

extern int hashmap_size(struct hashtable_t *htable);

extern int hashmap_get(struct hashtable_t *map, void *key, void **value);

extern int hashmap_put(struct hashtable_t *map, void *key, void *value);

extern int hashmap_delete(struct hashtable_t *map, void *key);

extern int hashmap_clear(struct hashtable_t *map);

extern int hashmap_iter(struct hashtable_t *map, void *cb, void *data);


extern void
granary_lc_handle_alloc(struct module *mod, const void *addr, unsigned long size,
        const void *caller_address);

extern void
granary_lc_handle_free(struct module *mod, const void *addr,
        const void *caller_address);

extern void
cfi_handler_alloc(struct module *mod, const void *addr, unsigned long size,
        const void *caller_address);

extern void
cfi_handler_free(struct module *mod, const void *addr,
        const void *caller_address);

extern void
cfi_handler_lost(struct module *mod, const void *addr,
        const void *caller_address);

extern void
cfi_collect_watcpoint(const void *src, const void *wp);

extern void cfi_dump_stack();

 struct file_operations;
 extern int __register_chrdev(unsigned int major, unsigned int baseminor,
                              unsigned int count, const char *name,
                              const struct file_operations *fops);
 extern void __unregister_chrdev(unsigned int major, unsigned int baseminor,
                                 unsigned int count, const char *name);

extern int
 cfi_print_symbol_name(void *symbol_addr);

#endif /* DRK_WRAPPER_INCLUDES_H_ */
