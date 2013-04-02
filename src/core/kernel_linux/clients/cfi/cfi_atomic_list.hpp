/*
 * cfi_atomic_list.hpp
 *
 *  Created on: 2013-01-29
 *      Author: akshayk
 */

#ifndef CFI_ATOMIC_LIST_HPP_
#define CFI_ATOMIC_LIST_HPP_

#include <stdint.h>
#include <string.h>
//#include <atomic>

template <typename T>
struct list {
    std::atomic<list<T> *> next;
    T value;
};


template <typename T>
struct atomic_list {
    typedef list<T> list_item;
    std::atomic<list_item *> list_head;

    std::atomic<list_item *> head;

    // Append the item in the list
    T *append() throw() {
        list_item *list_head(nullptr);
        list_item *item(new list_item);

        do{
            list_head = head.load();
            item->next = list_head;
        }while(!head.compare_exchange_weak(list_head, item));

        return &(head->value);
    }
};


#endif /* CFI_ATOMIC_LIST_HPP_ */
