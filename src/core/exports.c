/* This file was automatically generated by /home/akshayk/GranaryCode/Granary-Drk/src/core/exports.py. */
#include <linux/module.h>
extern void *reg_32_to_8;
EXPORT_SYMBOL_GPL(reg_32_to_8);
extern void *dr_prepare_for_call;
EXPORT_SYMBOL_GPL(dr_prepare_for_call);
extern void *instrlist_remove;
EXPORT_SYMBOL_GPL(instrlist_remove);
extern void *decode_trace;
EXPORT_SYMBOL_GPL(decode_trace);
extern void *opnd_get_index;
EXPORT_SYMBOL_GPL(opnd_get_index);
extern void *opnd_is_disp_short_addr;
EXPORT_SYMBOL_GPL(opnd_is_disp_short_addr);
extern void *dr_app_take_over;
EXPORT_SYMBOL_GPL(dr_app_take_over);
extern void *instr_is_undefined;
EXPORT_SYMBOL_GPL(instr_is_undefined);
extern void *dr_is_granary_code;
EXPORT_SYMBOL_GPL(dr_is_granary_code);
extern void *__wrap_malloc;
EXPORT_SYMBOL_GPL(__wrap_malloc);
extern void *dr_lookup_module_by_name;
EXPORT_SYMBOL_GPL(dr_lookup_module_by_name);
extern void *reg_set_value;
EXPORT_SYMBOL_GPL(reg_set_value);
extern void *dr_redirect_execution_native;
EXPORT_SYMBOL_GPL(dr_redirect_execution_native);
extern void *instr_cmovcc_to_jcc;
EXPORT_SYMBOL_GPL(instr_cmovcc_to_jcc);
extern void *instr_opcode_valid;
EXPORT_SYMBOL_GPL(instr_opcode_valid);
extern void *dr_safe_write;
EXPORT_SYMBOL_GPL(dr_safe_write);
extern void *opnd_is_immed_int;
EXPORT_SYMBOL_GPL(opnd_is_immed_int);
extern void *instr_is_mov;
EXPORT_SYMBOL_GPL(instr_is_mov);
extern void *opnd_get_base;
EXPORT_SYMBOL_GPL(opnd_get_base);
extern void *proc_save_fpstate;
EXPORT_SYMBOL_GPL(proc_save_fpstate);
extern void *instr_get_raw_byte;
EXPORT_SYMBOL_GPL(instr_get_raw_byte);
extern void *reg_parameter_num;
EXPORT_SYMBOL_GPL(reg_parameter_num);
extern void *instr_set_raw_bits;
EXPORT_SYMBOL_GPL(instr_set_raw_bits);
extern void *opnd_is_reg_32bit;
EXPORT_SYMBOL_GPL(opnd_is_reg_32bit);
extern void *instr_set_note;
EXPORT_SYMBOL_GPL(instr_set_note);
extern void *opnd_is_far_base_disp;
EXPORT_SYMBOL_GPL(opnd_is_far_base_disp);
extern void *dr_thread_yield;
EXPORT_SYMBOL_GPL(dr_thread_yield);
extern void *opnd_get_pc;
EXPORT_SYMBOL_GPL(opnd_get_pc);
extern void *get_l4_page_table;
EXPORT_SYMBOL_GPL(get_l4_page_table);
extern void *instr_being_modified;
EXPORT_SYMBOL_GPL(instr_being_modified);
extern void *dr_register_restore_state_event;
EXPORT_SYMBOL_GPL(dr_register_restore_state_event);
extern void *dr_unregister_exit_event;
EXPORT_SYMBOL_GPL(dr_unregister_exit_event);
extern void *opnd_is_base_disp;
EXPORT_SYMBOL_GPL(opnd_is_base_disp);
extern void *instr_create_0dst_0src;
EXPORT_SYMBOL_GPL(instr_create_0dst_0src);
extern void *proc_get_L1_icache_size;
EXPORT_SYMBOL_GPL(proc_get_L1_icache_size);
extern void *opnd_create_rel_addr;
EXPORT_SYMBOL_GPL(opnd_create_rel_addr);
extern void *__wrap_realloc;
EXPORT_SYMBOL_GPL(__wrap_realloc);
extern void *dr_sleep;
EXPORT_SYMBOL_GPL(dr_sleep);
extern void *instr_ok_to_emit;
EXPORT_SYMBOL_GPL(instr_ok_to_emit);
extern void *instr_is_call_direct;
EXPORT_SYMBOL_GPL(instr_is_call_direct);
extern void *page_table_get_page;
EXPORT_SYMBOL_GPL(page_table_get_page);
extern void *dr_set_stack_pointer_value;
EXPORT_SYMBOL_GPL(dr_set_stack_pointer_value);
extern void *dr_get_options;
EXPORT_SYMBOL_GPL(dr_get_options);
extern void *reg_is_32bit;
EXPORT_SYMBOL_GPL(reg_is_32bit);
extern void *instr_reg_in_dst;
EXPORT_SYMBOL_GPL(instr_reg_in_dst);
extern void *opnd_shrink_to_16_bits;
EXPORT_SYMBOL_GPL(opnd_shrink_to_16_bits);
extern void *instr_get_branch_target_pc;
EXPORT_SYMBOL_GPL(instr_get_branch_target_pc);
extern void *dr_unregister_end_trace_event;
EXPORT_SYMBOL_GPL(dr_unregister_end_trace_event);
extern void *dr_insert_call_instrumentation;
EXPORT_SYMBOL_GPL(dr_insert_call_instrumentation);
extern void *opnd_get_instr;
EXPORT_SYMBOL_GPL(opnd_get_instr);
extern void *dr_register_module_load_event;
EXPORT_SYMBOL_GPL(dr_register_module_load_event);
extern void *instr_create_0dst_3src;
EXPORT_SYMBOL_GPL(instr_create_0dst_3src);
extern void *dr_module_iterator_hasnext;
EXPORT_SYMBOL_GPL(dr_module_iterator_hasnext);
extern void *instrlist_meta_replace;
EXPORT_SYMBOL_GPL(instrlist_meta_replace);
extern void *instr_create_1dst_3src;
EXPORT_SYMBOL_GPL(instr_create_1dst_3src);
extern void *opnd_is_immed;
EXPORT_SYMBOL_GPL(opnd_is_immed);
extern void *instrlist_clear_and_destroy;
EXPORT_SYMBOL_GPL(instrlist_clear_and_destroy);
extern void *instr_is_mov_imm_to_tos;
EXPORT_SYMBOL_GPL(instr_is_mov_imm_to_tos);
extern void *instr_init;
EXPORT_SYMBOL_GPL(instr_init);
extern void *dr_register_post_syscall_event;
EXPORT_SYMBOL_GPL(dr_register_post_syscall_event);
extern void *dr_get_wrapper_target;
EXPORT_SYMBOL_GPL(dr_get_wrapper_target);
extern void *dr_set_native_idtr;
EXPORT_SYMBOL_GPL(dr_set_native_idtr);
extern void *instr_is_stringop;
EXPORT_SYMBOL_GPL(instr_is_stringop);
extern void *dr_get_logfile;
EXPORT_SYMBOL_GPL(dr_get_logfile);
extern void *instr_is_sse_or_sse2;
EXPORT_SYMBOL_GPL(instr_is_sse_or_sse2);
extern void *dr_get_proc_address_ex;
EXPORT_SYMBOL_GPL(dr_get_proc_address_ex);
extern void *reg_overlap;
EXPORT_SYMBOL_GPL(reg_overlap);
extern void *instr_create_0dst_1src;
EXPORT_SYMBOL_GPL(instr_create_0dst_1src);
extern void *dr_register_thread_init_event;
EXPORT_SYMBOL_GPL(dr_register_thread_init_event);
extern void *dr_get_milliseconds;
EXPORT_SYMBOL_GPL(dr_get_milliseconds);
extern void *instrlist_clone;
EXPORT_SYMBOL_GPL(instrlist_clone);
extern void *instr_compute_address;
EXPORT_SYMBOL_GPL(instr_compute_address);
extern void *dr_snprintf;
EXPORT_SYMBOL_GPL(dr_snprintf);
extern void *instrlist_meta_fault_append;
EXPORT_SYMBOL_GPL(instrlist_meta_fault_append);
extern void *instrlist_get_translation_target;
EXPORT_SYMBOL_GPL(instrlist_get_translation_target);
extern void *dr_unregister_trace_event;
EXPORT_SYMBOL_GPL(dr_unregister_trace_event);
extern void *proc_get_family;
EXPORT_SYMBOL_GPL(proc_get_family);
extern void *instr_shrink_to_32_bits;
EXPORT_SYMBOL_GPL(instr_shrink_to_32_bits);
extern void *opnd_create_immed_int;
EXPORT_SYMBOL_GPL(opnd_create_immed_int);
extern void *instr_set_prev;
EXPORT_SYMBOL_GPL(instr_set_prev);
extern void *dr_mutex_destroy;
EXPORT_SYMBOL_GPL(dr_mutex_destroy);
extern void *instr_get_dst;
EXPORT_SYMBOL_GPL(instr_get_dst);
extern void *instr_has_allocated_bits;
EXPORT_SYMBOL_GPL(instr_has_allocated_bits);
extern void *opnd_get_reg_used;
EXPORT_SYMBOL_GPL(opnd_get_reg_used);
extern void *dr_barrier_destroy;
EXPORT_SYMBOL_GPL(dr_barrier_destroy);
extern void *reg_32_to_opsz;
EXPORT_SYMBOL_GPL(reg_32_to_opsz);
extern void *dr_abort;
EXPORT_SYMBOL_GPL(dr_abort);
extern void *instr_destroy;
EXPORT_SYMBOL_GPL(instr_destroy);
extern void *instr_is_return;
EXPORT_SYMBOL_GPL(instr_is_return);
extern void *opnd_create_abs_addr;
EXPORT_SYMBOL_GPL(opnd_create_abs_addr);
extern void *instr_set_raw_word;
EXPORT_SYMBOL_GPL(instr_set_raw_word);
extern void *reg_64_to_32;
EXPORT_SYMBOL_GPL(reg_64_to_32);
extern void *proc_get_stepping;
EXPORT_SYMBOL_GPL(proc_get_stepping);
extern void *opnd_shrink_to_32_bits;
EXPORT_SYMBOL_GPL(opnd_shrink_to_32_bits);
extern void *dr_standalone_init;
EXPORT_SYMBOL_GPL(dr_standalone_init);
extern void *instr_build;
EXPORT_SYMBOL_GPL(instr_build);
extern void *dr_register_nudge_event;
EXPORT_SYMBOL_GPL(dr_register_nudge_event);
extern void *dr_insert_restore_fpstate;
EXPORT_SYMBOL_GPL(dr_insert_restore_fpstate);
extern void *dr_mcontext_xmm_fields_valid;
EXPORT_SYMBOL_GPL(dr_mcontext_xmm_fields_valid);
extern void *instrlist_length;
EXPORT_SYMBOL_GPL(instrlist_length);
extern void *instr_set_meta_may_fault;
EXPORT_SYMBOL_GPL(instr_set_meta_may_fault);
extern void *instr_clone;
EXPORT_SYMBOL_GPL(instr_clone);
extern void *instr_create_2dst_4src;
EXPORT_SYMBOL_GPL(instr_create_2dst_4src);
extern void *opnd_is_near_abs_addr;
EXPORT_SYMBOL_GPL(opnd_is_near_abs_addr);
extern void *opnd_create_base_disp;
EXPORT_SYMBOL_GPL(opnd_create_base_disp);
extern void *dr_replace_fragment;
EXPORT_SYMBOL_GPL(dr_replace_fragment);
extern void *instr_uses_reg;
EXPORT_SYMBOL_GPL(instr_uses_reg);
extern void *opnd_get_addr;
EXPORT_SYMBOL_GPL(opnd_get_addr);
extern void *instr_is_syscall;
EXPORT_SYMBOL_GPL(instr_is_syscall);
extern void *opnd_create_far_base_disp_ex;
EXPORT_SYMBOL_GPL(opnd_create_far_base_disp_ex);
extern void *disassemble;
EXPORT_SYMBOL_GPL(disassemble);
extern void *dr_get_symbol_name;
EXPORT_SYMBOL_GPL(dr_get_symbol_name);
extern void *opnd_uses_reg;
EXPORT_SYMBOL_GPL(opnd_uses_reg);
extern void *dr_unregister_thread_exit_event;
EXPORT_SYMBOL_GPL(dr_unregister_thread_exit_event);
extern void *proc_get_cache_size_str;
EXPORT_SYMBOL_GPL(proc_get_cache_size_str);
extern void *page_table_readable_without_exception;
EXPORT_SYMBOL_GPL(page_table_readable_without_exception);
extern void *dr_write_saved_reg;
EXPORT_SYMBOL_GPL(dr_write_saved_reg);
extern void *opnd_is_far_pc;
EXPORT_SYMBOL_GPL(opnd_is_far_pc);
extern void *instrlist_last;
EXPORT_SYMBOL_GPL(instrlist_last);
extern void *instr_get_app_pc;
EXPORT_SYMBOL_GPL(instr_get_app_pc);
extern void *opnd_num_regs_used;
EXPORT_SYMBOL_GPL(opnd_num_regs_used);
extern void *instrlist_append;
EXPORT_SYMBOL_GPL(instrlist_append);
extern void *instr_is_exit_cti;
EXPORT_SYMBOL_GPL(instr_is_exit_cti);
extern void *dr_get_current_drcontext;
EXPORT_SYMBOL_GPL(dr_get_current_drcontext);
extern void *decode_eflags_usage;
EXPORT_SYMBOL_GPL(decode_eflags_usage);
extern void *get_register_name;
EXPORT_SYMBOL_GPL(get_register_name);
extern void *opnd_get_scale;
EXPORT_SYMBOL_GPL(opnd_get_scale);
extern void *instr_writes_to_reg;
EXPORT_SYMBOL_GPL(instr_writes_to_reg);
extern void *opnd_create_instr;
EXPORT_SYMBOL_GPL(opnd_create_instr);
extern void *__wrap_free;
EXPORT_SYMBOL_GPL(__wrap_free);
extern void *instrlist_encode;
EXPORT_SYMBOL_GPL(instrlist_encode);
extern void *opnd_is_abs_addr;
EXPORT_SYMBOL_GPL(opnd_is_abs_addr);
extern void *opnd_create_far_rel_addr;
EXPORT_SYMBOL_GPL(opnd_create_far_rel_addr);
extern void *opnd_is_reg;
EXPORT_SYMBOL_GPL(opnd_is_reg);
extern void *instr_get_src;
EXPORT_SYMBOL_GPL(instr_get_src);
extern void *instr_get_rel_addr_dst_idx;
EXPORT_SYMBOL_GPL(instr_get_rel_addr_dst_idx);
extern void *dr_register_signal_event;
EXPORT_SYMBOL_GPL(dr_register_signal_event);
extern void *instr_is_mbr;
EXPORT_SYMBOL_GPL(instr_is_mbr);
extern void *dr_mutex_create;
EXPORT_SYMBOL_GPL(dr_mutex_create);
extern void *instr_get_prefixes;
EXPORT_SYMBOL_GPL(instr_get_prefixes);
extern void *traverse_page_table;
EXPORT_SYMBOL_GPL(traverse_page_table);
extern void *dr_lookup_module;
EXPORT_SYMBOL_GPL(dr_lookup_module);
extern void *dr_write_file;
EXPORT_SYMBOL_GPL(dr_write_file);
extern void *instr_writes_to_exact_reg;
EXPORT_SYMBOL_GPL(instr_writes_to_exact_reg);
extern void *instr_is_call_indirect;
EXPORT_SYMBOL_GPL(instr_is_call_indirect);
extern void *opnd_is_memory_reference;
EXPORT_SYMBOL_GPL(opnd_is_memory_reference);
extern void *opnd_create_immed_float;
EXPORT_SYMBOL_GPL(opnd_create_immed_float);
extern void *instrlist_postinsert;
EXPORT_SYMBOL_GPL(instrlist_postinsert);
extern void *instr_is_prefetch;
EXPORT_SYMBOL_GPL(instr_is_prefetch);
extern void *dr_unregister_nudge_event;
EXPORT_SYMBOL_GPL(dr_unregister_nudge_event);
extern void *decode_opcode_name;
EXPORT_SYMBOL_GPL(decode_opcode_name);
extern void *dr_register_module_unload_event;
EXPORT_SYMBOL_GPL(dr_register_module_unload_event);
extern void *instr_reuse;
EXPORT_SYMBOL_GPL(instr_reuse);
extern void *dr_max_opnd_accessible_spill_slot;
EXPORT_SYMBOL_GPL(dr_max_opnd_accessible_spill_slot);
extern void *dr_insert_clean_call;
EXPORT_SYMBOL_GPL(dr_insert_clean_call);
extern void *instr_replace_src_opnd;
EXPORT_SYMBOL_GPL(instr_replace_src_opnd);
extern void *instr_set_raw_bytes;
EXPORT_SYMBOL_GPL(instr_set_raw_bytes);
extern void *instr_create_2dst_1src;
EXPORT_SYMBOL_GPL(instr_create_2dst_1src);
extern void *instr_is_meta_may_fault;
EXPORT_SYMBOL_GPL(instr_is_meta_may_fault);
extern void *instr_is_label;
EXPORT_SYMBOL_GPL(instr_is_label);
extern void *reg_32_to_64;
EXPORT_SYMBOL_GPL(reg_32_to_64);
extern void *dr_unregister_pre_syscall_event;
EXPORT_SYMBOL_GPL(dr_unregister_pre_syscall_event);
extern void *instr_is_cti_loop;
EXPORT_SYMBOL_GPL(instr_is_cti_loop);
extern void *instr_compute_address_ex;
EXPORT_SYMBOL_GPL(instr_compute_address_ex);
extern void *dr_get_mcontext_snapshot;
EXPORT_SYMBOL_GPL(dr_get_mcontext_snapshot);
extern void *dr_mutex_lock;
EXPORT_SYMBOL_GPL(dr_mutex_lock);
extern void *instr_create_4dst_1src;
EXPORT_SYMBOL_GPL(instr_create_4dst_1src);
extern void *dr_raw_tls_calloc;
EXPORT_SYMBOL_GPL(dr_raw_tls_calloc);
extern void *opnd_is_immed_float;
EXPORT_SYMBOL_GPL(opnd_is_immed_float);
extern void *instr_is_floating;
EXPORT_SYMBOL_GPL(instr_is_floating);
extern void *opnd_defines_use;
EXPORT_SYMBOL_GPL(opnd_defines_use);
extern void *dr_create_dir;
EXPORT_SYMBOL_GPL(dr_create_dir);
extern void *instr_length;
EXPORT_SYMBOL_GPL(instr_length);
extern void *reg_is_segment;
EXPORT_SYMBOL_GPL(reg_is_segment);
extern void *dr_nudge_client;
EXPORT_SYMBOL_GPL(dr_nudge_client);
extern void *dr_insert_cbr_instrumentation;
EXPORT_SYMBOL_GPL(dr_insert_cbr_instrumentation);
extern void *opnd_replace_reg;
EXPORT_SYMBOL_GPL(opnd_replace_reg);
extern void *instr_get_note;
EXPORT_SYMBOL_GPL(instr_get_note);
extern void *decode_from_copy;
EXPORT_SYMBOL_GPL(decode_from_copy);
extern void *dr_memory_is_dr_internal;
EXPORT_SYMBOL_GPL(dr_memory_is_dr_internal);
extern void *our_stderr;
EXPORT_SYMBOL_GPL(our_stderr);
extern void *opnd_create_pc;
EXPORT_SYMBOL_GPL(opnd_create_pc);
extern void *instr_set_translation;
EXPORT_SYMBOL_GPL(instr_set_translation);
extern void *dr_file_exists;
EXPORT_SYMBOL_GPL(dr_file_exists);
extern void *set_x86_mode;
EXPORT_SYMBOL_GPL(set_x86_mode);
extern void *instr_create_3dst_3src;
EXPORT_SYMBOL_GPL(instr_create_3dst_3src);
extern void *instr_invert_cbr;
EXPORT_SYMBOL_GPL(instr_invert_cbr);
extern void *instr_is_nop;
EXPORT_SYMBOL_GPL(instr_is_nop);
extern void *proc_is_cache_aligned;
EXPORT_SYMBOL_GPL(proc_is_cache_aligned);
extern void *instr_set_next;
EXPORT_SYMBOL_GPL(instr_set_next);
extern void *instr_set_raw_byte;
EXPORT_SYMBOL_GPL(instr_set_raw_byte);
extern void *dr_get_itimer;
EXPORT_SYMBOL_GPL(dr_get_itimer);
extern void *instr_create_0dst_2src;
EXPORT_SYMBOL_GPL(instr_create_0dst_2src);
extern void *instr_set_prefix_flag;
EXPORT_SYMBOL_GPL(instr_set_prefix_flag);
extern void *dr_swap_to_clean_stack;
EXPORT_SYMBOL_GPL(dr_swap_to_clean_stack);
extern void *opnd_create_far_abs_addr;
EXPORT_SYMBOL_GPL(opnd_create_far_abs_addr);
extern void *opnd_create_null;
EXPORT_SYMBOL_GPL(opnd_create_null);
extern void *opnd_is_disp_force_full;
EXPORT_SYMBOL_GPL(opnd_is_disp_force_full);
extern void *instr_allocate_raw_bits;
EXPORT_SYMBOL_GPL(instr_allocate_raw_bits);
extern void *opnd_create_far_instr;
EXPORT_SYMBOL_GPL(opnd_create_far_instr);
extern void *decode;
EXPORT_SYMBOL_GPL(decode);
extern void *instr_may_return_to_user;
EXPORT_SYMBOL_GPL(instr_may_return_to_user);
extern void *proc_get_L2_cache_size;
EXPORT_SYMBOL_GPL(proc_get_L2_cache_size);
extern void *opnd_create_far_base_disp;
EXPORT_SYMBOL_GPL(opnd_create_far_base_disp);
extern void *dr_register_kernel_wrapper;
EXPORT_SYMBOL_GPL(dr_register_kernel_wrapper);
extern void *dr_get_application_name;
EXPORT_SYMBOL_GPL(dr_get_application_name);
extern void *dr_kernel_find_symbol;
EXPORT_SYMBOL_GPL(dr_kernel_find_symbol);
extern void *instr_is_call;
EXPORT_SYMBOL_GPL(instr_is_call);
extern void *opnd_set_disp;
EXPORT_SYMBOL_GPL(opnd_set_disp);
extern void *page_table_writable_without_exception;
EXPORT_SYMBOL_GPL(page_table_writable_without_exception);
extern void *proc_get_type;
EXPORT_SYMBOL_GPL(proc_get_type);
extern void *instrlist_meta_fault_preinsert;
EXPORT_SYMBOL_GPL(instrlist_meta_fault_preinsert);
extern void *opnd_size_in_bytes;
EXPORT_SYMBOL_GPL(opnd_size_in_bytes);
extern void *dr_register_address_untracker;
EXPORT_SYMBOL_GPL(dr_register_address_untracker);
extern void *instr_num_srcs;
EXPORT_SYMBOL_GPL(instr_num_srcs);
extern void *our_stdout;
EXPORT_SYMBOL_GPL(our_stdout);
extern void *opnd_is_far_rel_addr;
EXPORT_SYMBOL_GPL(opnd_is_far_rel_addr);
extern void *dr_free_module_data;
EXPORT_SYMBOL_GPL(dr_free_module_data);
extern void *dr_unregister_fork_init_event;
EXPORT_SYMBOL_GPL(dr_unregister_fork_init_event);
extern void *instrlist_meta_postinsert;
EXPORT_SYMBOL_GPL(instrlist_meta_postinsert);
extern void *proc_get_all_feature_bits;
EXPORT_SYMBOL_GPL(proc_get_all_feature_bits);
extern void *dr_print_instr;
EXPORT_SYMBOL_GPL(dr_print_instr);
extern void *dr_thread_free;
EXPORT_SYMBOL_GPL(dr_thread_free);
extern void *dr_get_stack_pointer;
EXPORT_SYMBOL_GPL(dr_get_stack_pointer);
extern void *instr_is_mmx;
EXPORT_SYMBOL_GPL(instr_is_mmx);
extern void *dr_unregister_interrupt_event;
EXPORT_SYMBOL_GPL(dr_unregister_interrupt_event);
extern void *dr_redirect_execution;
EXPORT_SYMBOL_GPL(dr_redirect_execution);
extern void *proc_get_cache_line_size;
EXPORT_SYMBOL_GPL(proc_get_cache_line_size);
extern void *opnd_disassemble;
EXPORT_SYMBOL_GPL(opnd_disassemble);
extern void *opnd_get_immed_int;
EXPORT_SYMBOL_GPL(opnd_get_immed_int);
extern void *reg_is_pointer_sized;
EXPORT_SYMBOL_GPL(reg_is_pointer_sized);
extern void *dr_emulate_restore_arith_flags;
EXPORT_SYMBOL_GPL(dr_emulate_restore_arith_flags);
extern void *dr_save_reg;
EXPORT_SYMBOL_GPL(dr_save_reg);
extern void *dr_module_iterator_start;
EXPORT_SYMBOL_GPL(dr_module_iterator_start);
extern void *opnd_is_pc;
EXPORT_SYMBOL_GPL(opnd_is_pc);
extern void *dr_get_client_return_address;
EXPORT_SYMBOL_GPL(dr_get_client_return_address);
extern void *instr_is_cti;
EXPORT_SYMBOL_GPL(instr_is_cti);
extern void *dr_mutex_unlock;
EXPORT_SYMBOL_GPL(dr_mutex_unlock);
extern void *dr_register_direct_call_exit;
EXPORT_SYMBOL_GPL(dr_register_direct_call_exit);
extern void *instr_is_stringop_loop;
EXPORT_SYMBOL_GPL(instr_is_stringop_loop);
extern void *instrlist_preinsert;
EXPORT_SYMBOL_GPL(instrlist_preinsert);
extern void *opnd_set_scale;
EXPORT_SYMBOL_GPL(opnd_set_scale);
extern void *dr_app_start_on_return;
EXPORT_SYMBOL_GPL(dr_app_start_on_return);
extern void *dr_insert_mbr_instrumentation;
EXPORT_SYMBOL_GPL(dr_insert_mbr_instrumentation);
extern void *dr_unregister_thread_init_event;
EXPORT_SYMBOL_GPL(dr_unregister_thread_init_event);
extern void *instr_reset;
EXPORT_SYMBOL_GPL(instr_reset);
extern void *dr_print_opnd;
EXPORT_SYMBOL_GPL(dr_print_opnd);
extern void *dr_app_pc_from_cache_pc;
EXPORT_SYMBOL_GPL(dr_app_pc_from_cache_pc);
extern void *dr_init_client_extension;
EXPORT_SYMBOL_GPL(dr_init_client_extension);
extern void *instr_get_prefix_flag;
EXPORT_SYMBOL_GPL(instr_get_prefix_flag);
extern void *instr_mem_usage;
EXPORT_SYMBOL_GPL(instr_mem_usage);
extern void *decode_sizeof;
EXPORT_SYMBOL_GPL(decode_sizeof);
extern void *proc_get_containing_page;
EXPORT_SYMBOL_GPL(proc_get_containing_page);
extern void *instrlist_meta_fault_postinsert;
EXPORT_SYMBOL_GPL(instrlist_meta_fault_postinsert);
extern void *opnd_create_far_pc;
EXPORT_SYMBOL_GPL(opnd_create_far_pc);
extern void *dr_flush_file;
EXPORT_SYMBOL_GPL(dr_flush_file);
extern void *dr_reg_spill_slot_opnd;
EXPORT_SYMBOL_GPL(dr_reg_spill_slot_opnd);
extern void *dr_close_file;
EXPORT_SYMBOL_GPL(dr_close_file);
extern void *dr_request_synchronized_exit;
EXPORT_SYMBOL_GPL(dr_request_synchronized_exit);
extern void *instrlist_meta_preinsert;
EXPORT_SYMBOL_GPL(instrlist_meta_preinsert);
extern void *instr_num_dsts;
EXPORT_SYMBOL_GPL(instr_num_dsts);
extern void *instr_get_x86_mode;
EXPORT_SYMBOL_GPL(instr_get_x86_mode);
extern void *reg_is_xmm;
EXPORT_SYMBOL_GPL(reg_is_xmm);
extern void *dr_file_tell;
EXPORT_SYMBOL_GPL(dr_file_tell);
extern void *dr_suspend_all_other_threads;
EXPORT_SYMBOL_GPL(dr_suspend_all_other_threads);
extern void *instr_create_1dst_1src;
EXPORT_SYMBOL_GPL(instr_create_1dst_1src);
extern void *instr_is_interrupt;
EXPORT_SYMBOL_GPL(instr_is_interrupt);
extern void *dr_insert_save_fpstate;
EXPORT_SYMBOL_GPL(dr_insert_save_fpstate);
extern void *opnd_set_size;
EXPORT_SYMBOL_GPL(opnd_set_size);
extern void *dr_register_end_trace_event;
EXPORT_SYMBOL_GPL(dr_register_end_trace_event);
extern void *instr_writes_memory;
EXPORT_SYMBOL_GPL(instr_writes_memory);
extern void *dr_bb_exists_at;
EXPORT_SYMBOL_GPL(dr_bb_exists_at);
extern void *dr_unregister_filter_syscall_event;
EXPORT_SYMBOL_GPL(dr_unregister_filter_syscall_event);
extern void *opnd_is_near_memory_reference;
EXPORT_SYMBOL_GPL(opnd_is_near_memory_reference);
extern void *dr_fragment_exists_at;
EXPORT_SYMBOL_GPL(dr_fragment_exists_at);
extern void *dr_flush_region;
EXPORT_SYMBOL_GPL(dr_flush_region);
extern void *dr_get_time;
EXPORT_SYMBOL_GPL(dr_get_time);
extern void *dr_memory_is_readable;
EXPORT_SYMBOL_GPL(dr_memory_is_readable);
extern void *mecontext_snapshot_native;
EXPORT_SYMBOL_GPL(mecontext_snapshot_native);
extern void *opnd_get_disp;
EXPORT_SYMBOL_GPL(opnd_get_disp);
extern void *dr_fragment_app_pc;
EXPORT_SYMBOL_GPL(dr_fragment_app_pc);
extern void *dr_restore_reg;
EXPORT_SYMBOL_GPL(dr_restore_reg);
extern void *opnd_is_near_base_disp;
EXPORT_SYMBOL_GPL(opnd_is_near_base_disp);
extern void *instr_needs_encoding;
EXPORT_SYMBOL_GPL(instr_needs_encoding);
extern void *dr_unregister_restore_state_event;
EXPORT_SYMBOL_GPL(dr_unregister_restore_state_event);
extern void *dr_fix_mcontext;
EXPORT_SYMBOL_GPL(dr_fix_mcontext);
extern void *instrlist_init;
EXPORT_SYMBOL_GPL(instrlist_init);
extern void *dr_insert_call;
EXPORT_SYMBOL_GPL(dr_insert_call);
extern void *dr_register_thread_exit_event;
EXPORT_SYMBOL_GPL(dr_register_thread_exit_event);
extern void *opnd_is_instr;
EXPORT_SYMBOL_GPL(opnd_is_instr);
extern void *dr_restore_app_stack;
EXPORT_SYMBOL_GPL(dr_restore_app_stack);
extern void *dr_register_exit_event;
EXPORT_SYMBOL_GPL(dr_register_exit_event);
extern void *instr_create_3dst_4src;
EXPORT_SYMBOL_GPL(instr_create_3dst_4src);
extern void *dr_file_seek;
EXPORT_SYMBOL_GPL(dr_file_seek);
extern void *instr_is_mov_constant;
EXPORT_SYMBOL_GPL(instr_is_mov_constant);
extern void *dr_register_restore_state_ex_event;
EXPORT_SYMBOL_GPL(dr_register_restore_state_ex_event);
extern void *opnd_is_near_pc;
EXPORT_SYMBOL_GPL(opnd_is_near_pc);
extern void *dr_cleanup_after_call;
EXPORT_SYMBOL_GPL(dr_cleanup_after_call);
extern void *opnd_is_far_memory_reference;
EXPORT_SYMBOL_GPL(opnd_is_far_memory_reference);
extern void *dr_query_memory;
EXPORT_SYMBOL_GPL(dr_query_memory);
extern void *dr_trace_head_at;
EXPORT_SYMBOL_GPL(dr_trace_head_at);
extern void *instr_jcc_taken;
EXPORT_SYMBOL_GPL(instr_jcc_taken);
extern void *dr_save_arith_flags;
EXPORT_SYMBOL_GPL(dr_save_arith_flags);
extern void *instr_is_cbr;
EXPORT_SYMBOL_GPL(instr_is_cbr);
extern void *instr_is_far_abs_cti;
EXPORT_SYMBOL_GPL(instr_is_far_abs_cti);
extern void *reg_get_value;
EXPORT_SYMBOL_GPL(reg_get_value);
extern void *instrlist_meta_append;
EXPORT_SYMBOL_GPL(instrlist_meta_append);
extern void *dr_global_alloc;
EXPORT_SYMBOL_GPL(dr_global_alloc);
extern void *reg_is_extended;
EXPORT_SYMBOL_GPL(reg_is_extended);
extern void *dr_barrier_wait;
EXPORT_SYMBOL_GPL(dr_barrier_wait);
extern void *dr_memory_is_in_client;
EXPORT_SYMBOL_GPL(dr_memory_is_in_client);
extern void *opnd_set_disp_ex;
EXPORT_SYMBOL_GPL(opnd_set_disp_ex);
extern void *dr_set_itimer;
EXPORT_SYMBOL_GPL(dr_set_itimer);
extern void *instr_reads_memory;
EXPORT_SYMBOL_GPL(instr_reads_memory);
extern void *instr_create;
EXPORT_SYMBOL_GPL(instr_create);
extern void *dr_get_client_extension;
EXPORT_SYMBOL_GPL(dr_get_client_extension);
extern void *proc_restore_fpstate;
EXPORT_SYMBOL_GPL(proc_restore_fpstate);
extern void *dr_module_preferred_name;
EXPORT_SYMBOL_GPL(dr_module_preferred_name);
extern void *dr_insert_write_tls_field;
EXPORT_SYMBOL_GPL(dr_insert_write_tls_field);
extern void *dr_global_free;
EXPORT_SYMBOL_GPL(dr_global_free);
extern void *opnd_set_index;
EXPORT_SYMBOL_GPL(opnd_set_index);
extern void *get_return_address;
EXPORT_SYMBOL_GPL(get_return_address);
extern void *instr_shrink_to_16_bits;
EXPORT_SYMBOL_GPL(instr_shrink_to_16_bits);
extern void *instr_valid;
EXPORT_SYMBOL_GPL(instr_valid);
extern void *opnd_is_reg_pointer_sized;
EXPORT_SYMBOL_GPL(opnd_is_reg_pointer_sized);
extern void *dr_get_client_return_address_from_thread;
EXPORT_SYMBOL_GPL(dr_get_client_return_address_from_thread);
extern void *page_table_get_physical_address;
EXPORT_SYMBOL_GPL(page_table_get_physical_address);
extern void *instr_uses_fp_reg;
EXPORT_SYMBOL_GPL(instr_uses_fp_reg);
extern void *opnd_is_near_instr;
EXPORT_SYMBOL_GPL(opnd_is_near_instr);
extern void *opnd_create_base_disp_ex;
EXPORT_SYMBOL_GPL(opnd_create_base_disp_ex);
extern void *decode_first_opcode_byte;
EXPORT_SYMBOL_GPL(decode_first_opcode_byte);
extern void *dr_thread_alloc;
EXPORT_SYMBOL_GPL(dr_thread_alloc);
extern void *proc_get_vendor;
EXPORT_SYMBOL_GPL(proc_get_vendor);
extern void *proc_has_feature;
EXPORT_SYMBOL_GPL(proc_has_feature);
extern void *instr_get_eflags;
EXPORT_SYMBOL_GPL(instr_get_eflags);
extern void *dr_register_interrupt_event;
EXPORT_SYMBOL_GPL(dr_register_interrupt_event);
extern void *instrlist_disassemble;
EXPORT_SYMBOL_GPL(instrlist_disassemble);
extern void *dr_get_proc_address;
EXPORT_SYMBOL_GPL(dr_get_proc_address);
extern void *dr_set_tls_field;
EXPORT_SYMBOL_GPL(dr_set_tls_field);
extern void *opnd_set_base;
EXPORT_SYMBOL_GPL(opnd_set_base);
extern void *dr_unregister_post_syscall_event;
EXPORT_SYMBOL_GPL(dr_unregister_post_syscall_event);
extern void *instrlist_destroy;
EXPORT_SYMBOL_GPL(instrlist_destroy);
extern void *opnd_is_far_instr;
EXPORT_SYMBOL_GPL(opnd_is_far_instr);
extern void *dr_nonheap_free;
EXPORT_SYMBOL_GPL(dr_nonheap_free);
extern void *dr_get_client_extension_from_context;
EXPORT_SYMBOL_GPL(dr_get_client_extension_from_context);
extern void *dr_register_trace_event;
EXPORT_SYMBOL_GPL(dr_register_trace_event);
extern void *dr_resume_all_other_threads;
EXPORT_SYMBOL_GPL(dr_resume_all_other_threads);
extern void *instr_ok_to_mangle;
EXPORT_SYMBOL_GPL(instr_ok_to_mangle);
extern void *dr_is_notify_on;
EXPORT_SYMBOL_GPL(dr_is_notify_on);
extern void *reg_is_gpr;
EXPORT_SYMBOL_GPL(reg_is_gpr);
extern void *dr_get_parent_id;
EXPORT_SYMBOL_GPL(dr_get_parent_id);
extern void *dr_trace_exists_at;
EXPORT_SYMBOL_GPL(dr_trace_exists_at);
extern void *opnd_same_address;
EXPORT_SYMBOL_GPL(opnd_same_address);
extern void *instr_set_dst;
EXPORT_SYMBOL_GPL(instr_set_dst);
extern void *dr_unregister_delete_event;
EXPORT_SYMBOL_GPL(dr_unregister_delete_event);
extern void *proc_fpstate_save_size;
EXPORT_SYMBOL_GPL(proc_fpstate_save_size);
extern void *instrlist_replace;
EXPORT_SYMBOL_GPL(instrlist_replace);
extern void *get_x86_mode;
EXPORT_SYMBOL_GPL(get_x86_mode);
extern void *dr_set_client_return_address_from_thread;
EXPORT_SYMBOL_GPL(dr_set_client_return_address_from_thread);
extern void *dr_get_client_extension_temp;
EXPORT_SYMBOL_GPL(dr_get_client_extension_temp);
extern void *opnd_create_reg;
EXPORT_SYMBOL_GPL(opnd_create_reg);
extern void *instr_set_num_opnds;
EXPORT_SYMBOL_GPL(instr_set_num_opnds);
extern void *reg_is_fp;
EXPORT_SYMBOL_GPL(reg_is_fp);
extern void *dr_get_gp_xflag;
EXPORT_SYMBOL_GPL(dr_get_gp_xflag);
extern void *follow_page_table_entry;
EXPORT_SYMBOL_GPL(follow_page_table_entry);
extern void *opnd_get_reg;
EXPORT_SYMBOL_GPL(opnd_get_reg);
extern void *instr_operands_valid;
EXPORT_SYMBOL_GPL(instr_operands_valid);
extern void *instr_set_opcode;
EXPORT_SYMBOL_GPL(instr_set_opcode);
extern void *proc_get_brand_string;
EXPORT_SYMBOL_GPL(proc_get_brand_string);
extern void *instrlist_create;
EXPORT_SYMBOL_GPL(instrlist_create);
extern void *reg_is_64bit;
EXPORT_SYMBOL_GPL(reg_is_64bit);
extern void *reg_32_to_16;
EXPORT_SYMBOL_GPL(reg_32_to_16);
extern void *dr_delete_fragment;
EXPORT_SYMBOL_GPL(dr_delete_fragment);
extern void *proc_get_L1_dcache_size;
EXPORT_SYMBOL_GPL(proc_get_L1_dcache_size);
extern void *instr_create_popa;
EXPORT_SYMBOL_GPL(instr_create_popa);
extern void *dr_memory_protect;
EXPORT_SYMBOL_GPL(dr_memory_protect);
extern void *instr_set_ok_to_mangle;
EXPORT_SYMBOL_GPL(instr_set_ok_to_mangle);
extern void *instr_make_persistent;
EXPORT_SYMBOL_GPL(instr_make_persistent);
extern void *instrlist_set_our_mangling;
EXPORT_SYMBOL_GPL(instrlist_set_our_mangling);
extern void *instr_free;
EXPORT_SYMBOL_GPL(instr_free);
extern void *instr_create_3dst_5src;
EXPORT_SYMBOL_GPL(instr_create_3dst_5src);
extern void *proc_get_model;
EXPORT_SYMBOL_GPL(proc_get_model);
extern void *dr_insert_read_tls_field;
EXPORT_SYMBOL_GPL(dr_insert_read_tls_field);
extern void *dr_copy_module_data;
EXPORT_SYMBOL_GPL(dr_copy_module_data);
extern void *instr_get_raw_bits;
EXPORT_SYMBOL_GPL(instr_get_raw_bits);
extern void *instr_is_encoding_possible;
EXPORT_SYMBOL_GPL(instr_is_encoding_possible);
extern void *dr_get_random_value;
EXPORT_SYMBOL_GPL(dr_get_random_value);
extern void *dr_app_start_after_iret;
EXPORT_SYMBOL_GPL(dr_app_start_after_iret);
extern void *instr_set_app_pc;
EXPORT_SYMBOL_GPL(instr_set_app_pc);
extern void *return_to_module_from_interrupt;
EXPORT_SYMBOL_GPL(return_to_module_from_interrupt);
extern void *opnd_share_reg;
EXPORT_SYMBOL_GPL(opnd_share_reg);
extern void *dr_log;
EXPORT_SYMBOL_GPL(dr_log);
extern void *dr_app_stop;
EXPORT_SYMBOL_GPL(dr_app_stop);
extern void *dr_fragment_size;
EXPORT_SYMBOL_GPL(dr_fragment_size);
extern void *reg_is_mmx;
EXPORT_SYMBOL_GPL(reg_is_mmx);
extern void *dr_restore_arith_flags;
EXPORT_SYMBOL_GPL(dr_restore_arith_flags);
extern void *dr_unregister_restore_state_ex_event;
EXPORT_SYMBOL_GPL(dr_unregister_restore_state_ex_event);
extern void *dr_mutex_trylock;
EXPORT_SYMBOL_GPL(dr_mutex_trylock);
extern void *instrlist_first;
EXPORT_SYMBOL_GPL(instrlist_first);
extern void *disassemble_with_info;
EXPORT_SYMBOL_GPL(disassemble_with_info);
extern void *dr_barrier_create;
EXPORT_SYMBOL_GPL(dr_barrier_create);
extern void *opnd_get_size;
EXPORT_SYMBOL_GPL(opnd_get_size);
extern void *dr_insert_ubr_instrumentation;
EXPORT_SYMBOL_GPL(dr_insert_ubr_instrumentation);
extern void *instr_is_far_cti;
EXPORT_SYMBOL_GPL(instr_is_far_cti);
extern void *dr_module_iterator_stop;
EXPORT_SYMBOL_GPL(dr_module_iterator_stop);
extern void *instr_get_interrupt_number;
EXPORT_SYMBOL_GPL(instr_get_interrupt_number);
extern void *traverse_page_table_contiguous;
EXPORT_SYMBOL_GPL(traverse_page_table_contiguous);
extern void *instrlist_get_our_mangling;
EXPORT_SYMBOL_GPL(instrlist_get_our_mangling);
extern void *page_table_get_region;
EXPORT_SYMBOL_GPL(page_table_get_region);
extern void *instr_change_srcs_base_disp_opnd;
EXPORT_SYMBOL_GPL(instr_change_srcs_base_disp_opnd);
extern void *dr_register_get_symbol_name;
EXPORT_SYMBOL_GPL(dr_register_get_symbol_name);
extern void *dr_set_random_seed;
EXPORT_SYMBOL_GPL(dr_set_random_seed);
extern void *dr_unregister_module_unload_event;
EXPORT_SYMBOL_GPL(dr_unregister_module_unload_event);
extern void *instr_cmovcc_triggered;
EXPORT_SYMBOL_GPL(instr_cmovcc_triggered);
extern void *dr_get_process_id;
EXPORT_SYMBOL_GPL(dr_get_process_id);
extern void *instr_create_1dst_0src;
EXPORT_SYMBOL_GPL(instr_create_1dst_0src);
extern void *instrlist_prepend;
EXPORT_SYMBOL_GPL(instrlist_prepend);
extern void *opnd_same;
EXPORT_SYMBOL_GPL(opnd_same);
extern void *opnd_is_null;
EXPORT_SYMBOL_GPL(opnd_is_null);
extern void *instr_create_pusha;
EXPORT_SYMBOL_GPL(instr_create_pusha);
extern void *instr_create_4dst_4src;
EXPORT_SYMBOL_GPL(instr_create_4dst_4src);
extern void *instr_reads_from_reg;
EXPORT_SYMBOL_GPL(instr_reads_from_reg);
extern void *proc_bump_to_end_of_cache_line;
EXPORT_SYMBOL_GPL(proc_bump_to_end_of_cache_line);
extern void *depth_first_traverse_page_table;
EXPORT_SYMBOL_GPL(depth_first_traverse_page_table);
extern void *opnd_is_disp_encode_zero;
EXPORT_SYMBOL_GPL(opnd_is_disp_encode_zero);
extern void *dr_using_all_private_caches;
EXPORT_SYMBOL_GPL(dr_using_all_private_caches);
extern void *dr_read_file;
EXPORT_SYMBOL_GPL(dr_read_file);
extern void *decode_next_pc;
EXPORT_SYMBOL_GPL(decode_next_pc);
extern void *instr_set_x86_mode;
EXPORT_SYMBOL_GPL(instr_set_x86_mode);
extern void *dr_is_emulating_interrupt_return;
EXPORT_SYMBOL_GPL(dr_is_emulating_interrupt_return);
extern void *dr_get_client_path;
EXPORT_SYMBOL_GPL(dr_get_client_path);
extern void *instr_get_target;
EXPORT_SYMBOL_GPL(instr_get_target);
extern void *instr_create_2dst_0src;
EXPORT_SYMBOL_GPL(instr_create_2dst_0src);
extern void *dr_get_random_seed;
EXPORT_SYMBOL_GPL(dr_get_random_seed);
extern void *dr_app_start;
EXPORT_SYMBOL_GPL(dr_app_start);
extern void *instr_same;
EXPORT_SYMBOL_GPL(instr_same);
extern void *instr_encode;
EXPORT_SYMBOL_GPL(instr_encode);
extern void *dr_register_module_exit;
EXPORT_SYMBOL_GPL(dr_register_module_exit);
extern void *instr_free_raw_bits;
EXPORT_SYMBOL_GPL(instr_free_raw_bits);
extern void *dr_safe_read;
EXPORT_SYMBOL_GPL(dr_safe_read);
extern void *instr_change_dsts_base_disp_opnd;
EXPORT_SYMBOL_GPL(instr_change_dsts_base_disp_opnd);
extern void *dr_fprintf;
EXPORT_SYMBOL_GPL(dr_fprintf);
extern void *decode_memory_reference_size;
EXPORT_SYMBOL_GPL(decode_memory_reference_size);
extern void *dr_register_filter_syscall_event;
EXPORT_SYMBOL_GPL(dr_register_filter_syscall_event);
extern void *instr_reg_in_src;
EXPORT_SYMBOL_GPL(instr_reg_in_src);
extern void *dr_register_fork_init_event;
EXPORT_SYMBOL_GPL(dr_register_fork_init_event);
extern void *dr_register_delete_event;
EXPORT_SYMBOL_GPL(dr_register_delete_event);
extern void *instr_create_2dst_3src;
EXPORT_SYMBOL_GPL(instr_create_2dst_3src);
extern void *dr_fragment_start_pc;
EXPORT_SYMBOL_GPL(dr_fragment_start_pc);
extern void *instr_get_prev;
EXPORT_SYMBOL_GPL(instr_get_prev);
extern void *instr_create_2dst_2src;
EXPORT_SYMBOL_GPL(instr_create_2dst_2src);
extern void *dr_printf;
EXPORT_SYMBOL_GPL(dr_printf);
extern void *instr_get_opcode;
EXPORT_SYMBOL_GPL(instr_get_opcode);
extern void *instr_set_target;
EXPORT_SYMBOL_GPL(instr_set_target);
extern void *instr_build_bits;
EXPORT_SYMBOL_GPL(instr_build_bits);
extern void *dr_register_address_return_exit;
EXPORT_SYMBOL_GPL(dr_register_address_return_exit);
extern void *instr_is_ubr;
EXPORT_SYMBOL_GPL(instr_is_ubr);
extern void *dr_open_file;
EXPORT_SYMBOL_GPL(dr_open_file);
extern void *instr_disassemble;
EXPORT_SYMBOL_GPL(instr_disassemble);
extern void *instr_is_cti_short;
EXPORT_SYMBOL_GPL(instr_is_cti_short);
extern void *instr_is_cti_short_rewrite;
EXPORT_SYMBOL_GPL(instr_is_cti_short_rewrite);
extern void *instr_create_1dst_5src;
EXPORT_SYMBOL_GPL(instr_create_1dst_5src);
extern void *decode_as_bb;
EXPORT_SYMBOL_GPL(decode_as_bb);
extern void *instr_set_src;
EXPORT_SYMBOL_GPL(instr_set_src);
extern void *opnd_is_far_abs_addr;
EXPORT_SYMBOL_GPL(opnd_is_far_abs_addr);
extern void *instr_has_rel_addr_reference;
EXPORT_SYMBOL_GPL(instr_has_rel_addr_reference);
extern void *dr_app_pc_for_decoding;
EXPORT_SYMBOL_GPL(dr_app_pc_for_decoding);
extern void *dr_takeover_idtr;
EXPORT_SYMBOL_GPL(dr_takeover_idtr);
extern void *instr_get_opcode_eflags;
EXPORT_SYMBOL_GPL(instr_get_opcode_eflags);
extern void *dr_register_exit_module_context;
EXPORT_SYMBOL_GPL(dr_register_exit_module_context);
extern void *dr_next_address;
EXPORT_SYMBOL_GPL(dr_next_address);
extern void *dr_directory_exists;
EXPORT_SYMBOL_GPL(dr_directory_exists);
extern void *opnd_compute_address;
EXPORT_SYMBOL_GPL(opnd_compute_address);
extern void *dr_dup_file_handle;
EXPORT_SYMBOL_GPL(dr_dup_file_handle);
extern void *opnd_get_segment_selector;
EXPORT_SYMBOL_GPL(opnd_get_segment_selector);
extern void *dr_mark_trace_head;
EXPORT_SYMBOL_GPL(dr_mark_trace_head);
extern void *dr_get_stack_pointer_value;
EXPORT_SYMBOL_GPL(dr_get_stack_pointer_value);
extern void *dr_register_hotpatch_callback;
EXPORT_SYMBOL_GPL(dr_register_hotpatch_callback);
extern void *dr_register_bb_event;
EXPORT_SYMBOL_GPL(dr_register_bb_event);
extern void *dr_unlink_flush_region;
EXPORT_SYMBOL_GPL(dr_unlink_flush_region);
extern void *dr_get_tls_field;
EXPORT_SYMBOL_GPL(dr_get_tls_field);
extern void *instr_create_3dst_0src;
EXPORT_SYMBOL_GPL(instr_create_3dst_0src);
extern void *instrlist_clear;
EXPORT_SYMBOL_GPL(instrlist_clear);
extern void *instr_memory_reference_size;
EXPORT_SYMBOL_GPL(instr_memory_reference_size);
extern void *instrlist_set_translation_target;
EXPORT_SYMBOL_GPL(instrlist_set_translation_target);
extern void *reg_get_size;
EXPORT_SYMBOL_GPL(reg_get_size);
extern void *instr_convert_short_meta_jmp_to_long;
EXPORT_SYMBOL_GPL(instr_convert_short_meta_jmp_to_long);
extern void *disassemble_from_copy;
EXPORT_SYMBOL_GPL(disassemble_from_copy);
extern void *dr_raw_tls_cfree;
EXPORT_SYMBOL_GPL(dr_raw_tls_cfree);
extern void *opnd_is_rel_addr;
EXPORT_SYMBOL_GPL(opnd_is_rel_addr);
extern void *dr_register_is_granary_code;
EXPORT_SYMBOL_GPL(dr_register_is_granary_code);
extern void *instr_set_branch_target_pc;
EXPORT_SYMBOL_GPL(instr_set_branch_target_pc);
extern void *instr_get_rel_addr_target;
EXPORT_SYMBOL_GPL(instr_get_rel_addr_target);
extern void *instr_set_ok_to_emit;
EXPORT_SYMBOL_GPL(instr_set_ok_to_emit);
extern void *reg_get_bits;
EXPORT_SYMBOL_GPL(reg_get_bits);
extern void *dr_get_mcontext;
EXPORT_SYMBOL_GPL(dr_get_mcontext);
extern void *opnd_is_near_rel_addr;
EXPORT_SYMBOL_GPL(opnd_is_near_rel_addr);
extern void *instr_set_raw_bits_valid;
EXPORT_SYMBOL_GPL(instr_set_raw_bits_valid);
extern void *instr_get_arith_flags;
EXPORT_SYMBOL_GPL(instr_get_arith_flags);
extern void *opnd_is_reg_64bit;
EXPORT_SYMBOL_GPL(opnd_is_reg_64bit);
extern void *dr_unregister_module_load_event;
EXPORT_SYMBOL_GPL(dr_unregister_module_load_event);
extern void *dr_register_return_path_address;
EXPORT_SYMBOL_GPL(dr_register_return_path_address);
extern void *reg_to_pointer_sized;
EXPORT_SYMBOL_GPL(reg_to_pointer_sized);
extern void *reg_64_to_opsz;
EXPORT_SYMBOL_GPL(reg_64_to_opsz);
extern void *instr_get_raw_word;
EXPORT_SYMBOL_GPL(instr_get_raw_word);
extern void *dr_is_instrumented_module_code;
EXPORT_SYMBOL_GPL(dr_is_instrumented_module_code);
extern void *dr_set_mcontext;
EXPORT_SYMBOL_GPL(dr_set_mcontext);
extern void *instr_raw_bits_valid;
EXPORT_SYMBOL_GPL(instr_raw_bits_valid);
extern void *opnd_get_segment;
EXPORT_SYMBOL_GPL(opnd_get_segment);
extern void *dr_register_is_instrumented_module_code;
EXPORT_SYMBOL_GPL(dr_register_is_instrumented_module_code);
extern void *dr_unregister_signal_event;
EXPORT_SYMBOL_GPL(dr_unregister_signal_event);
extern void *dr_tag_from_cache_pc;
EXPORT_SYMBOL_GPL(dr_tag_from_cache_pc);
extern void *instr_set_meta_no_translation;
EXPORT_SYMBOL_GPL(instr_set_meta_no_translation);
extern void *dr_register_pre_syscall_event;
EXPORT_SYMBOL_GPL(dr_register_pre_syscall_event);
extern void *dr_query_memory_ex;
EXPORT_SYMBOL_GPL(dr_query_memory_ex);
extern void *dr_module_iterator_next;
EXPORT_SYMBOL_GPL(dr_module_iterator_next);
extern void *instr_create_1dst_2src;
EXPORT_SYMBOL_GPL(instr_create_1dst_2src);
extern void *dr_nonheap_alloc;
EXPORT_SYMBOL_GPL(dr_nonheap_alloc);
extern void *is_drk_running;
EXPORT_SYMBOL_GPL(is_drk_running);
extern void *dr_get_thread_id;
EXPORT_SYMBOL_GPL(dr_get_thread_id);
extern void *instr_get_next;
EXPORT_SYMBOL_GPL(instr_get_next);
extern void *dr_delay_flush_region;
EXPORT_SYMBOL_GPL(dr_delay_flush_region);
extern void *instr_get_rel_addr_src_idx;
EXPORT_SYMBOL_GPL(instr_get_rel_addr_src_idx);
extern void *dr_read_saved_reg;
EXPORT_SYMBOL_GPL(dr_read_saved_reg);
extern void *instr_set_operands_valid;
EXPORT_SYMBOL_GPL(instr_set_operands_valid);
extern void *dr_unregister_bb_event;
EXPORT_SYMBOL_GPL(dr_unregister_bb_event);
