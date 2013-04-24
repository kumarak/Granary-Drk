target remote : 1234
source ./core/gdbscript
set language c++
b panic
b show_fault_oops
b do_invalid_op
b do_general_protection
b break_on_fault
b __schedule_bug
b do_spurious_interrupt_bug
b report_bug
b bad_area_nosemaphore
b general_fault_on_granary_code
b break_on_pagefault
b watch_buffer_overflow
b break_on_address
