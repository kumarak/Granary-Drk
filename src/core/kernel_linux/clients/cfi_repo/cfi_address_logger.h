/*
 * cfi_address_logger.h
 *
 *  Created on: 2012-11-07
 *      Author: akshayk
 */

#ifndef CFI_ADDRESS_LOGGER_H_
#define CFI_ADDRESS_LOGGER_H_

extern uint64 ADDRESS_LOG_BEGIN;
extern volatile uint64 ADDRESS_LOG_NEXT;

void log_address(uint64 addr);

#endif /* CFI_ADDRESS_LOGGER_H_ */
