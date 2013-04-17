/*
 * cfi_dynamic_wrapper.hpp
 *
 *  Created on: 2012-09-19
 *      Author: pag
 *     Version: $Id$
 */

#ifndef DRK_CFI_DYNAMIC_WRAPPER_HPP_
#define DRK_CFI_DYNAMIC_WRAPPER_HPP_


template <typename R, typename... Args>
class cfi_dynamic_wrapper {
private:

    /// allocates new taint trackers
    static atomic_region_allocator<cfi_dynamic_wrapper> allocator;

    typedef R func_type(Args...);

    // skeleton:
    //      push %rdi;
    //      movq $func_ptr_to_wrap, %rdi;
    //      call dr_set_client_return_address_from_thread;
    //      pop %rdi;
    //      push $wrapper_addr;
    //      ret;


public:

    /// generate a dynamic wrapper for a particular function pointer
    static func_type *create(
        func_type *func_ptr_to_wrap,
        func_type *wrapper_ptr
    ) throw() {

    }

};


#endif /* DRK_CFI_DYNAMIC_WRAPPER_HPP_ */
