/*
 * cfi_atomic_list.h
 *
 *  Created on: 2013-01-29
 *      Author: akshayk
 */

#ifndef CFI_ATOMIC_LIST_H_
#define CFI_ATOMIC_LIST_H_

#include <linux/slab.h>
#include "cfi_module.h"


struct list_item {
	uint64_t node;
	volatile struct list_item *next;
};

struct cfi_list_head {
	volatile struct list_item *head;
	spinlock_t list_lock;
	unsigned int count;
};

#define CFI_LIST_DECLARE(name) \
    struct cfi_list_head name = { .head = NULL, .count = 0 }

static __inline__ void cfi_list_init(struct cfi_list_head *list_head){
    list_head->head = NULL;
    list_head->count = 0;
    spin_lock_init(&(list_head->list_lock));
}

static __inline__ void cfi_list_append(struct cfi_list_head *list_head, void *node)
{
    struct list_item *ptr;
    struct list_item *head;
    unsigned int exist = 0;
    struct list_item *list = kmalloc(sizeof(struct list_item), GFP_ATOMIC);

    if(list == NULL){
        return;
    }

    list->node = node;
    list->next = NULL;

    spin_lock(&(list_head->list_lock));
    if( !list_head->head) {
        list_head->head = list;
        list_head->count++;
        spin_unlock(&(list_head->list_lock));
        return;
        //do compare and swap
        /*do{
            head = list_head->head;
        }while(!__sync_bool_compare_and_swap(&list_head->head, head, list));
        return;*/
    }

    ptr = list_head->head;
    while(ptr->next != NULL) {
        if(ptr->node == node){
            exist = 1;
            break;
        }
        ptr = ptr->next;
    }

    if(!exist) {
        ptr->next = list;
        list_head->count++;
    } else {
        kfree(list);
    }
    spin_unlock(&(list_head->list_lock));
}

static __inline__ unsigned int cfi_list_item_exist(struct cfi_list_head *list_head, void *node)
{
    struct list_item *ptr;
    struct list_item *temp_ptr;
    struct list_item *temp_node;
    struct list_item *prev_ptr;
    unsigned int flag = 0;

    spin_lock(&(list_head->list_lock));
    if( !list_head->head) {
        spin_unlock(&(list_head->list_lock));
        return flag;
    }

    ptr = list_head->head;
    if(ptr->node == node){
        flag = 1;
        spin_unlock(&(list_head->list_lock));
        return flag;
    }

    if(ptr->next != NULL){
        while(ptr->next->next != NULL){
            if(ptr->next->node == node) {
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }

        if(ptr->next->next == NULL){
            if(ptr->next->node == node) {
                flag = 1;
            }
        }
    }


    spin_unlock(&(list_head->list_lock));
    return flag;
}

static __inline__ void cfi_list_item_print(struct cfi_list_head *list_head)
{
    struct list_item *ptr;
    struct list_item *temp_ptr;
    struct list_item *temp_node;
    struct list_item *prev_ptr;
    unsigned int flag = 0;

    spin_lock(&(list_head->list_lock));
    dr_printf("collected watchpoint : ");
    ptr = list_head->head;
    while(ptr != NULL){
        dr_printf("%lx\t", ptr->node);
        ptr = ptr->next;
    }
    dr_printf("\n");
    spin_unlock(&(list_head->list_lock));
}



/*

static __inline__ void cfi_list_append(struct cfi_list_head *list_head, void *node)
{
	struct list_item *ptr;
	struct list_item *head;
	struct list_item *list = kmalloc(sizeof(struct list_item), GFP_ATOMIC);

	if(list == NULL){
		return;
	}

	list->node = node;
	list->next = NULL;

	if( !list_head->head) {
		//list_head->head = list;	//do compare and swap
	    do{
	        head = list_head->head;
	    }while(!__sync_bool_compare_and_swap(&list_head->head, head, list));
		return;
	}

	ptr = list_head->head;
	while(ptr->next != NULL) {
		ptr = ptr->next;
	}

	//ptr->next = list;
	do {
	    head = ptr->next;
	}while (!__sync_bool_compare_and_swap(&ptr->next, head, list));
}
*/
static __inline__ void cfi_list_prepend(volatile struct cfi_list_head *list_head, void *node)
{
	struct list_item *ptr;
	volatile struct list_item *head;
	volatile struct list_item *list = kmalloc(sizeof(struct list_item), GFP_ATOMIC);

	if(list == NULL){
		return;
	}

	list->node = node;

	/* fix this atomic compare exchange issue*/
	do {
	    head = list_head->head;
	    list->next = head;

	} while (!__sync_bool_compare_and_swap(&(list_head->head), head, list));
}

static __inline__ void cfi_list_del_item(struct cfi_list_head *list_head, void *node)
{
	struct list_item *ptr;
	struct list_item *temp_ptr;
	struct list_item *temp_node;
	struct list_item *prev_ptr;
	//printk("item to be freed : %lx\n", node);

	spin_lock(&(list_head->list_lock));
	if( !list_head->head) {
	    //printk("head is null : %lx\n", node);
		spin_unlock(&(list_head->list_lock));
		return;
	}

	ptr = list_head->head;
	if(ptr->node == node){
		list_head->head = ptr->next;
		list_head->count--;
		kfree(ptr);
		//printk("item is freed : %lx\n", node);
		spin_unlock(&(list_head->list_lock));
		return;
	}

	if(ptr->next != NULL){
		while(ptr->next->next != NULL){
		    if(ptr->next->node == node) {
		        temp_ptr = ptr->next;
		        ptr->next = temp_ptr->next;
		        temp_ptr->next = NULL;
                list_head->count--;
                kfree(temp_ptr);
                //printk("item is freed : %lx\n", node);
                break;
		    }
			ptr = ptr->next;
		}

		if(ptr->next->next == NULL){
		    if(ptr->next->node == node) {
		        temp_ptr = ptr->next;
		        ptr->next= NULL;
		        temp_ptr->next = NULL;
		        kfree(temp_ptr);
		       // printk("item is freed : %lx\n", node);
		    }
		}
	}


	spin_unlock(&(list_head->list_lock));
	return;
	/*
	if(ptr->next == NULL){
		if(ptr->node == node){
			list_head->head = ptr->next;
		*/	/*
		    do{
		      temp_node = ptr->next;
		    }while (__sync_bool_compare_and_swap(&list_head->head, temp_node, NULL) == false);
			kfree(ptr);*/
		/*}
	}

	while((ptr->next->node != node) && (ptr->next->next != NULL)){
		ptr = ptr->next;
	}

	if(ptr->next->node == node){
	    do {
	        temp_ptr = ptr->next;
	    } while (__sync_bool_compare_and_swap(&ptr->next, temp_ptr, temp_ptr->next) == false);

	    kfree(temp_ptr);
	}*/

}

/*
static __inline__ void cfi_list_del(struct cfi_list_head *list_head)
{
    struct list_item *ptr;
    struct list_item *temp_ptr;

    ptr = list_head->head;

    while(ptr){
        temp_ptr = ptr;
        ptr = ptr->next;
        do{

        }while (__sync_bool_compare_and_swap(&list_head->head, list_head->head, ptr) == false);
        kfree(temp_ptr);
    }

}
*/
static __inline__ void cfi_for_each_item(struct cfi_list_head *list_head, int(*list_callback)(void*, void*), void *data)
{
    struct list_item *ptr;

    int ret = 0;

    ptr = list_head->head;

    //dr_printf("%s : %lx\n", __FUNCTION__, list_head->count);

    while((ptr != NULL) && (ret == 0)){
        ret = list_callback((void*)ptr->node, data);
        ptr = ptr->next;
    }
}



#endif /* CFI_ATOMIC_LIST_H_ */
