/*
 * cfi_wrapper.h
 *
 *  Created on: 2012-04-12
 *      Author: pag
 *     Version: $Id$
 */

#ifndef DRK_CFI_WRAPPER_H_
#define DRK_CFI_WRAPPER_H_


#ifdef __cplusplus
extern "C" {
#endif

typedef void (*cfi_type_erased_func_ptr)(void);

/// return a pointer to the function we should be calling, or 0 if the function
/// is not exported by the kernel.
cfi_type_erased_func_ptr cfi_get_kernel_wrapper(cfi_type_erased_func_ptr);
cfi_type_erased_func_ptr cfi_to_shadow_address(cfi_type_erased_func_ptr);
cfi_type_erased_func_ptr cfi_get_hotpatch_wrapper(cfi_type_erased_func_ptr);

#ifdef __cplusplus
}
#endif


#endif /* DRK_CFI_WRAPPER_H_ */
