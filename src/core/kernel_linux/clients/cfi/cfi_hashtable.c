/*
 * cfi_hashtable.c
 *
 *  Created on: 2013-01-31
 *      Author: akshayk
 */



#include "cfi_hashtable.h"
#include "cfi_module.h"
#include "slub_interface.h"
#include <linux/hash.h>
//#include "murmurhash.h"


////////////////////////////////////////////////////////////////////////
//hashing function

inline uint32_t rotl32 ( uint32_t x, int8_t r )
{
  return (x << r) | (x >> (32 - r));
}

inline uint64_t rotl64 ( uint64_t x, int8_t r )
{
  return (x << r) | (x >> (64 - r));
}

#define ROTL32(x,y) rotl32(x,y)
#define ROTL64(x,y) rotl64(x,y)

#define BIG_CONSTANT(x) (x##LLU)


inline uint32_t getblock ( uint32_t * p, int i )
{
    p = (uint32_t*)((unsigned long long)p | 0xffff000000000000ULL);
    return p[i];
}


//-----------------------------------------------------------------------------
// Finalization mix - force all bits of a hash block to avalanche

inline uint32_t fmix ( uint32_t h )
{
  h ^= h >> 16;
  h *= 0x85ebca6b;
  h ^= h >> 13;
  h *= 0xc2b2ae35;
  h ^= h >> 16;

  return h;
}

//-----------------------------------------------------------------------------

inline
void MurmurHash3_x86_32 ( const void * key, int len,
                          uint32_t seed, void * out )
{
  const uint8_t * data = (const uint8_t*)key;
  const int nblocks = len / 4;
  int i;

  uint32_t h1 = seed;


  const uint32_t c1 = 0xcc9e2d51;
  const uint32_t c2 = 0x1b873593;

  //----------
  // body

  const uint32_t * blocks = (const uint32_t *)(data + nblocks*4);

  for(i = -nblocks; i; i++)
  {
    uint32_t k1 = getblock(blocks,i);

    k1 *= c1;
    k1 = ROTL32(k1,15);
    k1 *= c2;

    h1 ^= k1;
    h1 = ROTL32(h1,13);
    h1 = h1*5+0xe6546b64;
  }

  //----------
  // tail

  const uint8_t * tail = (const uint8_t*)(data + nblocks*4);

  uint32_t k1 = 0;

  switch(len & 3)
  {
  case 3: k1 ^= tail[2] << 16;
  case 2: k1 ^= tail[1] << 8;
  case 1: k1 ^= tail[0];
          k1 *= c1; k1 = ROTL32(k1,15); k1 *= c2; h1 ^= k1;
  };

  //----------
  // finalization

  h1 ^= len;

  h1 = fmix(h1);

  *(uint32_t*)out = h1;
}

inline static uint32_t hash(void *key){
    uint32_t hash_value = 0;
    MurmurHash3_x86_32(&key, sizeof key, 0xDEADBEEFU, &hash_value);
    return hash_value;
}

// Basic hash entry.
typedef struct hashtable_entry_t {
    void *key;
    void *value;
    struct hashtable_entry_t *next;
} hashtable_entry_t;

typedef struct hash_bucket {
    struct hashtable_entry_t *head;
    unsigned int bucket_count;
    spinlock_t bucket_lock;
}hash_bucket_t;

typedef struct hashtable_t {
    int count;      // Number of entries
    int table_size; // Size of table in nodes
    int max_size;   // Max size before we resize
    spinlock_t hash_lock;
    hash_bucket_t *bucket_table;
}hashtable_t;



int hashmap_get_item_count(struct hashtable_t *htable){
    return htable->count;
}

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

	struct hashtable_t *ht = cfi_kmalloc(sizeof(struct hashtable_t), GFP_KERNEL);

	ht->count = 0;
	ht->table_size = initial_size;
	ht->max_size = (MAX_CAPACITY*initial_size);

	ht->bucket_table = kmalloc(initial_size*sizeof(hash_bucket_t), GFP_KERNEL);

	for(idx = 0; idx < initial_size; idx++){
	    hash_bucket_t *bucket = ht->bucket_table+idx;
	    bucket->head = NULL;
	    bucket->bucket_count = 0;
	    spin_lock_init(&(bucket->bucket_lock));
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
    hash_bucket_t *bucket;
    hashtable_entry_t *hentry, *old_entry;
    unsigned int in_table, idx = 0;
    if(htable == NULL){
        return 0;
    }

    for (idx=0; idx < htable->table_size; idx++) {
        bucket = htable->bucket_table+idx;

        spin_lock(&(bucket->bucket_lock));
        hentry = bucket->head;

        while(hentry){
            old_entry = hentry;
            hentry = hentry->next;
            cfi_kfree(old_entry);
        }
        spin_unlock(&(bucket->bucket_lock));
    }

    cfi_kfree(htable->bucket_table);
    cfi_kfree(htable);
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

    hash_bucket_t *bucket;
    hashtable_entry_t *hentry;
    unsigned int index;

    unsigned long hash_index;

    hash_index = hash(key);
    index = hash_index % htable->table_size;

    bucket = htable->bucket_table+index;

    spin_lock(&(bucket->bucket_lock));

    hentry = bucket->head;
    while(hentry){
        if(hentry->key == key){
            *value = hentry->value;
            spin_unlock(&(bucket->bucket_lock));
            return 1;
        }
        hentry = hentry->next;
    }
    spin_unlock(&(bucket->bucket_lock));

    return 0;
}


extern bool is_watchpoint(uint64_t value);

void debug_hashmap(hashtable_entry_t *hentry){
    printk("%s,", __FUNCTION__);
}

/**
 * Internal method to insert into a hash table
 * @return 1 if the key is new, 0 if updated.
 */
# if 0
static int hashmap_insert_table(hashtable_entry_t *table, int table_size, void *key, int key_len,
                                void *value, int should_cmp, int should_dup) {
    uint32_t out = 0;
    unsigned int index;
    hashtable_entry_t *hentry, *last_entry = NULL;
    unsigned long hash_index;
    hash_index = hash(key);
    index = hash_index % table_size;

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
            hentry = cfi_kmalloc(sizeof(hashtable_entry_t), GFP_ATOMIC);
            if(is_watchpoint(hentry)){
                debug_hashmap(hentry);
            }
            hentry->key = key;
            hentry->value = value;
            hentry->next = NULL;
            last_entry->next = hentry;
    }

    return 1;
}
#endif

static int
hashmap_insert(struct hashtable_t *htable, void *key, void *value, int should_dup) {

    unsigned int found = 0;
    unsigned int index;
    hash_bucket_t *bucket;
    hashtable_entry_t *hentry, *last_entry = NULL, *new_entry = NULL;
    unsigned long hash_index;

    new_entry = cfi_kmalloc(sizeof(hashtable_entry_t), GFP_ATOMIC);

    new_entry->key = key;
    new_entry->value = value;
    new_entry->next = NULL;

    hash_index = hash(key);
    index = hash_index % htable->table_size;
    bucket = htable->bucket_table+index;

    spin_lock(&(bucket->bucket_lock));
    hentry = bucket->head;
    while (hentry) {
        if(hentry->key == key){
            found = 1;
            break;
        }
        last_entry = hentry;
        hentry = hentry->next;
    }
    if(!found){
        if(last_entry == NULL){
            bucket->head = new_entry;
        } else {
            last_entry->next = new_entry;
        }
        bucket->bucket_count += 1;
    }
    spin_unlock(&(bucket->bucket_lock));

    if(found) {
        new_entry->key = NULL;
        new_entry->value = NULL;
        new_entry->next = NULL;
        cfi_kfree(new_entry);
    }
    return 1;
}

/**
 * Internal method to double the size of a hashmap
 */
# if 0
static void
hashmap_double_size(struct hashtable_t *htable) {
	unsigned int i = 0;
    int new_size = htable->table_size * 2;
    int new_max_size = htable->max_size * 2;
    hashtable_entry_t *hentry, *old_entry;
    int in_table;

    // Allocate the new table
    hashtable_entry_t *new_table = (hashtable_entry_t*)cfi_kmalloc(new_size*sizeof(hashtable_entry_t), GFP_ATOMIC);
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
#endif
/**
 * Puts a key/value pair. Replaces existing values.
 * @arg key The key to set. This is copied, and a seperate
 * version is owned by the hashmap. The caller the key at will.
 * 0 if updated, 1 if added.
 */
#if 0
int hashmap_put_internal(struct hashtable_t *htable, void *key, void *value) {
    int new;
#if 0
    if (htable->count + 1 > htable->max_size) {
        hashmap_double_size(htable);
        return hashmap_put_internal(htable, key, value);
    }

    new = hashmap_insert_table(htable->table, htable->table_size, key, sizeof(uint64_t), value, 1, 1);
    if (new) {
        htable->count += 1;
    }
#endif
    new = hashmap_insert(htable, key, value, 1);
    return new;
}
#endif

int hashmap_put(struct hashtable_t *htable, void *key, void *value) {
    int new;
    new = hashmap_insert(htable, key, value, 0);
    return new;
}


/**
 * Deletes a key/value pair.
 * 0 on success. -1 if not found.
 */
int
hashmap_delete(struct hashtable_t *htable, void *key) {

    unsigned int index;
    hash_bucket_t *bucket;

    hashtable_entry_t *hentry, *last_entry = NULL, *d_entry= NULL;
    unsigned long hash_index;

    hash_index = hash(key);
    index = hash_index % htable->table_size;

    bucket = htable->bucket_table+index;

    // scan the table
    spin_lock(&(bucket->bucket_lock));
    hentry = bucket->head;

    while(hentry){
        if(hentry->key == key){
            d_entry = hentry;
            if(last_entry == NULL){
                hentry = hentry->next;
                bucket->head = hentry;
            } else {
                last_entry->next = hentry->next;
            }
            break;
        }
        last_entry = hentry;
        hentry = hentry->next;
    }

    if(d_entry != NULL){
        bucket->bucket_count -= 1;
    }

    spin_unlock(&(bucket->bucket_lock));

    if(d_entry != NULL) {
        d_entry->key = NULL;
        d_entry->value = NULL;
        d_entry->next = NULL;
        cfi_kfree(d_entry);
    }

    return 0;
}

/**
 * Clears all the key/value pairs.
 * 0 on success. -1 if not found.
 */

#if 0
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

#endif
/**
 * Iterates through the key/value pairs in the map,
 * invoking a callback for each.
 * @return 0 on success
 */
int
hashmap_iter(struct hashtable_t *htable, hashtable_callback cb, void *data) {
    hash_bucket_t *bucket;
    hashtable_entry_t *hentry;
    unsigned int i =0;
    int should_break = 0;

    for (i=0; i < htable->table_size && !should_break; i++) {
        bucket = htable->bucket_table+i;

        spin_lock(&(bucket->bucket_lock));
        if(bucket->bucket_count != 0) {
            hentry = bucket->head;
            while (hentry && !should_break) {
                should_break = cb(data, hentry->key, hentry->value);
                hentry = hentry->next;
            }
        }
        spin_unlock(&(bucket->bucket_lock));
    }

    return should_break;
}


#if 0

int hashmap_get_item_count(struct hashtable_t *htable){
    return htable->count;
}

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

    struct hashtable_t *ht = cfi_kmalloc(sizeof(struct hashtable_t), GFP_ATOMIC);

    ht->count = 0;
    ht->table_size = initial_size;
    ht->max_size = (MAX_CAPACITY*initial_size);

    ht->bucket_table = kmalloc(initial_size*sizeof(hash_bucket_t), GFP_ATOMIC);

    for(idx = 0; idx < initial_size; idx++){
        hash_bucket_t *bucket = ht->bucket_table+idx;
        //hashtable_entry_t **hentry = ht->table+idx;
        bucket->head = NULL;
        spin_lock_init(&(bucket->bucket_lock));
    }

    *table = ht;

    spin_lock_init(&(ht->hash_lock));

    return 0;
}

/**
 * Destroys a map and cleans up all associated memory
 * @arg map The struct hashtable_t to destroy. Frees memory.
 */

#if 0
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
#endif

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
    unsigned int index;
    return 0;
}


extern bool is_watchpoint(uint64_t value);

void debug_hashmap(hashtable_entry_t *hentry){
    printk("%s,", __FUNCTION__);
}

/**
 * Internal method to insert into a hash table
 * @return 1 if the key is new, 0 if updated.
 */

static int hashmap_insert_table(hashtable_entry_t *table, int table_size, void *key, int key_len,
                                void *value, int should_cmp, int should_dup) {
    return 1;
}


static int hashmap_insert(struct hashtable_t *htable, void *key,
                                void *value, int should_dup) {

   return 1;
}

/**
 * Internal method to double the size of a hashmap
 */

static void
hashmap_double_size(struct hashtable_t *htable) {
    (void)htable;
}

/**
 * Puts a key/value pair. Replaces existing values.
 * @arg key The key to set. This is copied, and a seperate
 * version is owned by the hashmap. The caller the key at will.
 * 0 if updated, 1 if added.
 */
int hashmap_put_internal(struct hashtable_t *htable, void *key, void *value) {
    (void)htable;
    (void)key;
    (void)value;
    return 0;
}

int hashmap_put(struct hashtable_t *htable, void *key, void *value) {
    (void)htable;
    (void)key;
    (void)value;
    return 0;
}


/**
 * Deletes a key/value pair.
 * 0 on success. -1 if not found.
 */
int
hashmap_delete(struct hashtable_t *htable, void *key) {
    (void)htable;
    (void)key;
    return 0;
}

/**
 * Clears all the key/value pairs.
 * 0 on success. -1 if not found.
 */

int
hashmap_clear(struct hashtable_t *htable) {
    (void)htable;
    return 0;
}

/**
 * Iterates through the key/value pairs in the map,
 * invoking a callback for each.
 * @return 0 on success
 */
int
hashmap_iter(struct hashtable_t *htable, hashtable_callback cb, void *data) {
    (void)htable;
    (void)cb;
    (void)data;

    return 0;
}
#endif
