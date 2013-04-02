/*
 * cfi_address_logger.c
 *
 *  Created on: 2012-11-07
 *      Author: akshayk
 */

#include "cfi_atomic.h"
#include "cfi_module.h"
#include "cfi_address_logger.h"

uint64 ADDRESS_LOG_BEGIN = MODULE_SHADOW_END;
static uint64 ADDRESS_LOG_END = MODULE_SHADOW_END_EXTENDED;
volatile uint64 ADDRESS_LOG_NEXT = MODULE_SHADOW_END;

static mem_t add8(mem_t val) {
	return val + 8;
}

void log_address(uint64 addr) {
	uint64 *allocated_address = NULL;

	if(ADDRESS_LOG_NEXT >= ADDRESS_LOG_END) {
		ADDRESS_LOG_NEXT = ADDRESS_LOG_BEGIN; // racy, oh well :-P
	}

	allocated_address = (uint64 *) cfi_atomic_change((volatile mem_t *) &ADDRESS_LOG_NEXT, add8);
	*allocated_address = addr;
}
