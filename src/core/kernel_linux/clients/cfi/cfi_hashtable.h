/*
 * cfi_hashtable.h
 *
 *  Created on: 2013-01-31
 *      Author: akshayk
 */

#ifndef CFI_HASHTABLE_H_
#define CFI_HASHTABLE_H_

#include "cfi_module.h"


#define LC_HASH_BITS 10

#define MAX_CAPACITY 0.75
#define DEFAULT_CAPACITY (1<<LC_HASH_BITS)

typedef struct hashtable_t hashtable_t;

#define DEFINE_HASHTABLE(name)	\
	struct hashtable_t	name;

typedef int(*hashtable_callback)(void *data, const char *key, void *value);

/**
 * Creates a new hashtable and allocates space for it.
 * @return 0 on success.
 */
int
hashmap_init(int initial_size, struct hashtable_t **htable);

/**
 * Destroys a map and cleans up all associated memory
 * @arg map The hashmap to destroy. Frees memory.
 */
int
hashmap_destroy(struct hashtable_t *htable);

/**
 * Returns the size of the hashmap in items
 */
int hashmap_size(struct hashtable_t *htable);

/**
 * Gets a value.
 * 0 on success. -1 if not found.
 */
int
hashmap_get(struct hashtable_t *map, void *key, void **value);

/**
 * Puts a key/value pair.
 * 0 if updated, 1 if added.
 */
int
hashmap_put(struct hashtable_t *map, void *key, void *value);

/**
 * Deletes a key/value pair.
 * 0 on success. -1 if not found.
 */
int
hashmap_delete(struct hashtable_t *htable, void *key);

/**
 * Clears all the key/value pairs.
 * 0 on success. -1 if not found.
 */
int
hashmap_clear(struct hashtable_t *htable);

/**
 * Iterates through the key/value pairs in the map,
 * invoking a callback for each. The call back gets a
 * key, value for each and returns an integer stop value.
 * If the callback returns 1, then the iteration stops.
 * @return 0 on success, or the return of the callback.
 */
int
hashmap_iter(struct hashtable_t *htable, hashtable_callback cb, void *data);


#endif /* CFI_HASHTABLE_H_ */
