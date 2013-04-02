/*
 * kernel_globals.h
 *
 *  Created on: 2013-03-06
 *      Author: akshayk
 */

#ifndef KERNEL_GLOBALS_H_
#define KERNEL_GLOBALS_H_




/*

#define VARIABLE_HASH_START(name) void init_kernel_variable_hash(name) {
#define VARIABLE_HASH_END() }
#define HASHMAP_PUT(key, value) hashmap_put(kernel_variable_hash, (void*)key, (void*)value)

VARIABLE_HASH_START(void)
    HASHMAP_PUT(&pv_info, sizeof(struct pv_info));
    //HASHMAP_PUT(&pv_init_ops, sizeof(struct pv_init_ops));
    HASHMAP_PUT(&pv_time_ops, sizeof(struct pv_time_ops));
    HASHMAP_PUT(&pv_cpu_ops, sizeof(struct pv_cpu_ops));
VARIABLE_HASH_END()


*/

#endif /* KERNEL_GLOBALS_H_ */
