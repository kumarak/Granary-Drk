/*
 * cfi_hashtable.c
 *
 *  Created on: 2013-01-31
 *      Author: akshayk
 */



#include "cfi_hashtable.h"
#include "cfi_module.h"
#include <linux/hash.h>

//#include "murmurhash.h"



// Basic hash entry.
typedef struct hashtable_entry_t {
    char *key;
    void *value;
    struct hashtable_entry_t *next;
} hashtable_entry_t;

struct hashtable_t {
    int count;      // Number of entries
    int table_size; // Size of table in nodes
    int max_size;   // Max size before we resize
    spinlock_t hash_lock;
    hashtable_entry_t *table;
};



/**
 * Creates a new struct hashtable_t and allocates space for it.
 * @return 0 on success.
 */

int
hashmap_init(int initial_size, struct hashtable_t **table) {
    unsigned int idx = 0;

	if(initial_size <= 0){
		initial_size = DEFAULT_CAPACITY;
	} else {
		// round up in power of 2
		int most_sig_bit = 0;
		for(idx = 0; idx < sizeof(initial_size)*8; idx++){
			if((initial_size >> idx) & 0x1)
				most_sig_bit = idx;
		}

		if((1 << most_sig_bit) != initial_size){
			most_sig_bit += 1;
		}

		initial_size = 1 << most_sig_bit;
	}

	struct hashtable_t *ht = kmalloc(sizeof(struct hashtable_t), GFP_ATOMIC);

	ht->count = 0;
	ht->table_size = initial_size;
	ht->max_size = (MAX_CAPACITY*initial_size);

	ht->table = kmalloc(initial_size*sizeof(hashtable_entry_t), GFP_ATOMIC);

	for(idx = 0; idx < initial_size; idx++){
	    hashtable_entry_t *hentry = ht->table+idx;
	    hentry->key = NULL;
	    hentry->value = NULL;
	    hentry->next = NULL;
	}
	*table = ht;

	spin_lock_init(&(ht->hash_lock));

	return 0;
}

/**
 * Destroys a map and cleans up all associated memory
 * @arg map The struct hashtable_t to destroy. Frees memory.
 */

int
hashmap_destroy(struct hashtable_t *htable) {
    hashtable_entry_t *hentry, *old_entry;
    unsigned int in_table, i = 0;
    if(htable == NULL){
        return 0;
    }
    spin_lock(&(htable->hash_lock));
    for (i=0; i < htable->table_size; i++) {
        hentry = htable->table+i;

        while(hentry){
            old_entry = hentry;
            hentry = hentry->next;
           // kfree(old_entry);
        }
    }

    kfree(htable->table);
    spin_unlock(&(htable->hash_lock));
    kfree(htable);
    return 0;
}

/**
 * Returns the size of the struct hashtable_t in items
 */
int hashmap_size(struct hashtable_t *htable) {
    return htable->count;
}

/**
 * Gets a value.
 * 0 on success. -1 if not found.
 */



int
hashmap_get(struct hashtable_t *htable, void *key, void **value) {
    uint32_t out = 0;
    unsigned int index;
    hashtable_entry_t *hentry;
    unsigned long hash_index;

    spin_lock(&(htable->hash_lock));

#if 1
    hash_index = hash_ptr(key, LC_HASH_BITS);
    index = hash_index % htable->table_size;

#else
    MurmurHash3_x86_32(key, sizeof(uint64_t), 0xDEADBEEF, &out);
    index = out % htable->table_size;
#endif
    hentry = htable->table+index;

    //scan the table
    while(hentry && hentry->key){
        if(hentry->key == key){
            *value = hentry->value;
            spin_unlock(&(htable->hash_lock));
            return 1;
        }
        hentry = hentry->next;
    }

    spin_unlock(&(htable->hash_lock));
    return 0;
}

/**
 * Internal method to insert into a hash table
 * @return 1 if the key is new, 0 if updated.
 */
static int hashmap_insert_table(hashtable_entry_t *table, int table_size, void *key, int key_len,
                                void *value, int should_cmp, int should_dup) {
    uint32_t out = 0;
    unsigned int index;
    hashtable_entry_t *hentry, *last_entry = NULL;
    unsigned long hash_index;

#if 1
    hash_index = hash_ptr(key, LC_HASH_BITS);
    index = hash_index % table_size;

#else
    MurmurHash3_x86_32(key, sizeof(uint64_t), 0xDEADBEEF, &out);
    index = out % table_size;
#endif
    hentry = table+index;


    //scan the table
    while (hentry && hentry->key) {
        if(hentry->key == key){
            hentry->value = value;
            return 0;
        }

        last_entry = hentry;
        hentry = hentry->next;
    }

    if(last_entry == NULL){
        hentry->key = key;
        hentry->value = value;

    } else {
       // dr_printf("%s : hash_index : %d, key : %lx, value : %lx\n", __FUNCTION__, hash_index, key, value);
       // if(htable->count < DEFAULT_CAPACITY){
            hentry = kmalloc(sizeof(hashtable_entry_t), GFP_ATOMIC);
            hentry->key = key;
            hentry->value = value;
            hentry->next = NULL;
            last_entry->next = hentry;
       // }
    }

    return 1;
}


/**
 * Internal method to double the size of a hashmap
 */
static void
hashmap_double_size(struct hashtable_t *htable) {
	unsigned int i = 0;
    int new_size = htable->table_size * 2;
    int new_max_size = htable->max_size * 2;
    hashtable_entry_t *hentry, *old_entry;
    int in_table;

    // Allocate the new table
    hashtable_entry_t *new_table = (hashtable_entry_t*)kmalloc(new_size*sizeof(hashtable_entry_t), GFP_ATOMIC);
    for(i = 0; i < new_size; i++){
        hashtable_entry_t *new_entry = new_table+i;
        new_entry->key = NULL;
        new_entry->value = NULL;
        new_entry->next = NULL;
    }


    for (i=0; i < htable->table_size; i++) {
        hentry = htable->table+i;
        in_table = 1;

        while (hentry && hentry->key) {
            old_entry = hentry;
            hentry = hentry->next;

            hashmap_insert_table(new_table, new_size, old_entry->key, sizeof(uint64_t), old_entry->value, 0, 0);

            if(!in_table){
                kfree(old_entry);
            }
            in_table = 0;
        }
    }

    kfree(htable->table);

    htable->table = new_table;
    htable->table_size = new_size;
    htable->max_size = new_max_size;
}

/**
 * Puts a key/value pair. Replaces existing values.
 * @arg key The key to set. This is copied, and a seperate
 * version is owned by the hashmap. The caller the key at will.
 * 0 if updated, 1 if added.
 */
int hashmap_put_internal(struct hashtable_t *htable, void *key, void *value) {
    int new;

    if (htable->count + 1 > htable->max_size) {
       // dr_printf("WTFFFFFFFFFFFFFFFFF size of hash table  %lx \n", htable->count);
        hashmap_double_size(htable);
        return hashmap_put_internal(htable, key, value);
    }

    new = hashmap_insert_table(htable->table, htable->table_size, key, sizeof(uint64_t), value, 1, 1);
    if (new) {
        //dr_printf("hashtable size : %lx\n", htable->count);
        htable->count += 1;
    }

    return new;
}

int hashmap_put(struct hashtable_t *htable, void *key, void *value) {
    int new;
    spin_lock(&(htable->hash_lock));
    new = hashmap_put_internal(htable, key, value);
    spin_unlock(&(htable->hash_lock));
    return new;
}


/**
 * Deletes a key/value pair.
 * 0 on success. -1 if not found.
 */
int
hashmap_delete(struct hashtable_t *htable, void *key) {
    uint32_t out = 0;
    unsigned int index;
    hashtable_entry_t *hentry, *last_entry = NULL;
    unsigned long hash_index;

    spin_lock(&(htable->hash_lock));

#if 1
    hash_index = hash_ptr(key, LC_HASH_BITS);
    index = hash_index % htable->table_size;

#else
    MurmurHash3_x86_32(key, sizeof(uint64_t), 0xDEADBEEF, &out);
    index = out % htable->table_size;
#endif

    hentry = htable->table+index;

    // scan the table
    while (hentry && hentry->key) {
        if(hentry->key == key){
            kfree(hentry->key);
            htable->count -= 1;

            if(last_entry == NULL){
                if(hentry->next){
                    hashtable_entry_t *n = hentry->next;
                    hentry->key = n->key;
                    hentry->value = n->value;
                    hentry->next = n->next;
                    kfree(n);
                } else {
                    hentry->key = NULL;
                    hentry->value = NULL;
                }
            } else {
                last_entry->next = hentry->next;
                kfree(hentry);
            }
            spin_unlock(&(htable->hash_lock));
            return 0;
        }
        hentry = hentry->next;
    }

    spin_unlock(&(htable->hash_lock));
    return -1;
}

/**
 * Clears all the key/value pairs.
 * 0 on success. -1 if not found.
 */

int
hashmap_clear(struct hashtable_t *htable) {
    hashtable_entry_t *hentry, *old_entry;
    int in_table;
    unsigned int i = 0;

    for (i=0; i < htable->table_size; i++) {
        hentry = htable->table+i;
        in_table = 1;

        // scan the table
        while (hentry && hentry->key) {
            old_entry = hentry;
            hentry = hentry->next;
            kfree(old_entry->key);

            if(!in_table){
                kfree(old_entry);
            } else {
                old_entry = NULL;
            }

            in_table = 0;
        }
    }

    htable->count = 0;
    return 0;
}

/**
 * Iterates through the key/value pairs in the map,
 * invoking a callback for each.
 * @return 0 on success
 */
int
hashmap_iter(struct hashtable_t *htable, hashtable_callback cb, void *data) {
    hashtable_entry_t *hentry;
    unsigned int i =0;
    int should_break = 0;
    spin_lock(&(htable->hash_lock));
    for (i=0; i < htable->table_size && !should_break; i++) {
        hentry = htable->table+i;
        while (hentry && hentry->key && !should_break) {
            should_break = cb(data, hentry->key, hentry->value);
            hentry = hentry->next;
        }
    }
    spin_unlock(&(htable->hash_lock));
    return should_break;
}