# 1 "x86/x86.asm"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "x86/x86.asm"
# 67 "x86/x86.asm"
# 1 "x86/asm_defines.asm" 1
# 41 "x86/asm_defines.asm"
# 1 "/home/akshayk/GranaryCode/Granary-Drk/src/core/configure.h" 1
# 42 "x86/asm_defines.asm" 2
# 68 "x86/x86.asm" 2
.text


# 1 "/home/akshayk/GranaryCode/Granary-Drk/src/core/kernel_linux/syscall.h" 1
# 72 "x86/x86.asm" 2
# 189 "x86/x86.asm"







































# 267 "x86/x86.asm"
        .align 0 
.global get_pic_xax 
.hidden get_pic_xax 
.type get_pic_xax, %function
get_pic_xax:
        mov rax, qword ptr [rsp]

       

        .align 0 
.global get_pic_xdi 
.hidden get_pic_xdi 
.type get_pic_xdi, %function
get_pic_xdi:
        mov rdi, qword ptr [rsp]

       
# 294 "x86/x86.asm"
        .align 0 
.global call_switch_stack 
.hidden call_switch_stack 
.type call_switch_stack, %function
call_switch_stack:







        lea rsp, [-5*8 + rsp]

        lea rax, [-8 + rsp]
        mov [5*8 + rax], r8

        mov [1*8 + rax], rdi
        mov [2*8 + rax], rsi
        mov [3*8 + rax], rdx
        mov [4*8 + rax], rcx




        push rbx
        push rdi
        mov rbx, rax
        mov rdi, rsp

        mov rdx, [3*8 + rax]
        mov rcx, [1*8 + rax]
        mov rsp, [2*8 + rax]
        cmp dword ptr [4*8 + rax], 0
        je call_dispatch_alt_stack_no_free
# 335 "x86/x86.asm"
        mov dword ptr [rip + initstack_mutex], 0

call_dispatch_alt_stack_no_free:
        
 mov rdi, rcx 
 call rdx 

        mov rsp, rdi
        mov rax, rbx
        cmp dword ptr [5*8 + rax], 0
        je unexpected_return
        pop rdi
        pop rbx




        lea rsp, [5*8 + rsp]




        ret
       





        .align 0 
.global unexpected_return 
.hidden unexpected_return 
.type unexpected_return, %function
unexpected_return:

        
 mov rdx, 0 
 mov rsi, -99 
 mov rdi, 0 
 call internal_error 





        jmp unexpected_return
       







        .align 0 
.global clone_and_swap_stack 
.hidden clone_and_swap_stack 
.type clone_and_swap_stack, %function
clone_and_swap_stack:
        mov rax, rdi
        mov rcx, rsi
        mov rdx, rsp

        push rsi
        push rdi

        sub rcx, rdx
        mov rsi, rdx
        mov rdi, rax
        sub rdi, rcx
        sub rax, rcx

        cld
        rep movsb

        pop rdi
        pop rsi
        mov rsp, rax
        ret
       





        .align 0 
.global dr_app_start 
.type dr_app_start, %function
dr_app_start:


        push [rsp] 
 pushfq 
 lea rsp, [rsp - ((16)*16)] 
 push r15 
 push r14 
 push r13 
 push r12 
 push r11 
 push r10 
 push r9 
 push r8 
 push rax 
 push rcx 
 push rdx 
 push rbx 
 
 push rsp 
 push rbp 
 push rsi 
 push rdi 
 lea rax, [rsp] 
 
 mov rdi, rax 
 call get_xmm_vals 
 
 lea rax, [(18*8 + ((16)*16)) + rsp] 
 mov [(3*8) + rsp], rax


        lea rax, [rsp]
  pushfq
  cli
        
 mov rdi, rax 
 call dr_app_start_helper 

     popfq


        add rsp, (18*8 + ((16)*16))
        ret
       

        .align 0 
.global dr_app_start_after_iret 
.type dr_app_start_after_iret, %function
dr_app_start_after_iret:
  nop
  nop
  nop

        .align 0 
.global dr_app_start_on_return 
.type dr_app_start_on_return, %function
dr_app_start_on_return:


        lea rsp, [rsp - 8]


        pushfq
        cli


        lea rsp, [rsp - ((16)*16)] 
 push r15 
 push r14 
 push r13 
 push r12 
 push r11 
 push r10 
 push r9 
 push r8 
 push rax 
 push rcx 
 push rdx 
 push rbx 
 
 push rsp 
 push rbp 
 push rsi 
 push rdi
        mov rdi, rsp
        call get_xmm_vals



        lea rax, [(18*8 + ((16)*16)) - 8 + rsp]
        mov [(3*8) + rsp], rax




        call dr_get_client_return_address_from_thread
        mov [rsp + (18*8 + ((16)*16)) - 8], rax


        mov rdi, rsp
        call dynamo_start
        hlt



       







        .align 0 
.global dr_app_take_over 
.type dr_app_take_over, %function
dr_app_take_over:
        jmp dynamorio_app_take_over
       






        .align 0 
.global dynamorio_app_take_over 
.type dynamorio_app_take_over, %function
dynamorio_app_take_over:


        push [rsp] 
 pushfq 
 lea rsp, [rsp - ((16)*16)] 
 push r15 
 push r14 
 push r13 
 push r12 
 push r11 
 push r10 
 push r9 
 push r8 
 push rax 
 push rcx 
 push rdx 
 push rbx 
 
 push rsp 
 push rbp 
 push rsi 
 push rdi 
 lea rax, [rsp] 
 
 mov rdi, rax 
 call get_xmm_vals 
 
 lea rax, [(18*8 + ((16)*16)) + rsp] 
 mov [(3*8) + rsp], rax


        lea rax, [rsp]
 pushfq
 cli
        
 mov rdi, rax 
 call dynamorio_app_take_over_helper 




 popfq
        add rsp, (18*8 + ((16)*16))
        ret
       
# 522 "x86/x86.asm"
        .align 0 
.global cleanup_and_terminate 
.hidden cleanup_and_terminate 
.type cleanup_and_terminate, %function
cleanup_and_terminate:
# 533 "x86/x86.asm"
        lea rsp, [-5*8 + rsp]

        lea rbp, [-8 + rsp]
        mov [5*8 + rbp], r8

        mov [1*8 + rbp], rdi
        mov [2*8 + rbp], rsi
        mov [3*8 + rbp], rdx
        mov [4*8 + rbp], rcx
# 556 "x86/x86.asm"
        lock inc dword ptr [rip + exiting_thread_count]


        mov rbx, rdi
        mov qword ptr [(((18*8 + ((16)*16))+8 +3*8)+3*8 +4) + rbx], 1
        
 mov rdi, rbx 
 call is_currently_on_dstack 

        cmp rax, 0
        jnz cat_save_dstack
        mov rbx, 0
        jmp cat_done_saving_dstack
cat_save_dstack:
        mov rbx, qword ptr [((18*8 + ((16)*16))+8 +3*8) + rbx]
cat_done_saving_dstack:





        
 call get_cleanup_and_terminate_global_do_syscall_entry 

        push rbx
        push rax

        mov esi, dword ptr [5*8 + rbp]
        cmp esi, 0
        jz cat_thread_only
        
 call dynamo_process_exit 

        jmp cat_no_thread
cat_thread_only:
        
 call dynamo_thread_exit 

cat_no_thread:



        mov ecx, 1




cat_spin:



        xchg dword ptr [rip + initstack_mutex], ecx

        jecxz cat_have_lock

        pause
        jmp cat_spin
cat_have_lock:

        mov rsi, [2*8 + rbp]
        pop rax
        pop rcx
        mov rbx, [3*8 + rbp]
        mov rdx, [4*8 + rbp]






        mov rsp, qword ptr [rip + initstack]


        push rdx
        push rbx
        push rax
        push rsi

        
 mov rdi, rcx 
 call dynamo_thread_stack_free_and_exit 


        pop rax


        pop r10

        pop rdi
        pop rsi
# 665 "x86/x86.asm"
        mov dword ptr [rip + initstack_mutex], 0
# 674 "x86/x86.asm"
        lock dec dword ptr [rip + exiting_thread_count]


        jmp r10



       
# 691 "x86/x86.asm"
        .align 0 
.global global_do_syscall_int 
.hidden global_do_syscall_int 
.type global_do_syscall_int, %function
global_do_syscall_int:



        int 0x80






        jmp dynamorio_sys_exit_group

       
# 727 "x86/x86.asm"
        .align 0 
.global global_do_syscall_sysenter 
.hidden global_do_syscall_sysenter 
.type global_do_syscall_sysenter, %function
global_do_syscall_sysenter:



        sysenter







       
# 779 "x86/x86.asm"
       .align 0 
.global global_do_syscall_syscall 
.hidden global_do_syscall_syscall 
.type global_do_syscall_syscall, %function
global_do_syscall_syscall:
        mov r10, rcx
        syscall





        jmp dynamorio_sys_exit_group

       
# 1047 "x86/x86.asm"
        .align 0 
.global dynamorio_syscall 
.hidden dynamorio_syscall 
.type dynamorio_syscall, %function
dynamorio_syscall:

        push rbx


        mov rbx, rsi
        mov rax, rdi
        cmp rbx, 0
        je syscall_ready
        mov rdi, rdx
        cmp rbx, 1
        je syscall_ready
        mov rsi, rcx
        cmp rbx, 2
        je syscall_ready
        mov rdx, r8
        cmp rbx, 3
        je syscall_ready
        mov rcx, r9
        cmp rbx, 4
        je syscall_ready
        mov r8, [2*8 + rsp]
        cmp rbx, 5
        je syscall_ready
        mov r9, [3*8 + rsp]
syscall_ready:
        mov r10, rcx
        syscall
# 1116 "x86/x86.asm"
        pop rbx

        ret
       
# 1129 "x86/x86.asm"
        .align 0 
.global dynamorio_sigreturn 
.hidden dynamorio_sigreturn 
.type dynamorio_sigreturn, %function
dynamorio_sigreturn:

        mov eax, 0xf
        mov r10, rcx
        syscall







        jmp unexpected_return
       




        .align 0 
.global dynamorio_sys_exit 
.hidden dynamorio_sys_exit 
.type dynamorio_sys_exit, %function
dynamorio_sys_exit:

        mov edi, 0
        mov eax, 0x3c
        mov r10, rcx
        syscall
# 1163 "x86/x86.asm"
        jmp unexpected_return
       




        .align 0 
.global dynamorio_sys_exit_group 
.hidden dynamorio_sys_exit_group 
.type dynamorio_sys_exit_group, %function
dynamorio_sys_exit_group:

        mov edi, 0
        mov eax, 0xe7
        mov r10, rcx
        syscall
# 1184 "x86/x86.asm"
        jmp unexpected_return
       
# 1208 "x86/x86.asm"
        .align 0 
.global master_signal_handler 
.hidden master_signal_handler 
.type master_signal_handler, %function
master_signal_handler:
        mov rcx, rsp
        jmp master_signal_handler_C

       
# 1304 "x86/x86.asm"
        .align 0 
.global dynamorio_clone 
.hidden dynamorio_clone 
.type dynamorio_clone, %function
dynamorio_clone:




        sub rsi, 8
        mov [rsi], r9

        mov r10, rcx
        mov rax, 56
        syscall
# 1334 "x86/x86.asm"
        cmp rax, 0
        jne dynamorio_clone_parent

        mov gs, ax
        pop rcx
        call rcx

        jmp unexpected_return
dynamorio_clone_parent:







        ret
       
# 1388 "x86/x86.asm"
        .align 0 
.global back_from_native 
.hidden back_from_native 
.type back_from_native, %function
back_from_native:




        push 0 
 pushfq 
 lea rsp, [rsp - ((16)*16)] 
 push r15 
 push r14 
 push r13 
 push r12 
 push r11 
 push r10 
 push r9 
 push r8 
 push rax 
 push rcx 
 push rdx 
 push rbx 
 
 push rsp 
 push rbp 
 push rsi 
 push rdi 
 lea rax, [rsp] 
 
 mov rdi, rax 
 call get_xmm_vals 
 
 lea rax, [(18*8 + ((16)*16)) + rsp] 
 mov [(3*8) + rsp], rax
        lea rax, [rsp]





        
 mov rdi, rax 
 call back_from_native_C 


        jmp unexpected_return
       
# 1433 "x86/x86.asm"
        .align 0 
.global dr_setjmp 
.hidden dr_setjmp 
.type dr_setjmp, %function
dr_setjmp:
        mov rdx, rdi
        mov [ 0 + rdx], rbx
        mov [ 8 + rdx], rcx
        mov [2*8 + rdx], rdi
        mov [3*8 + rdx], rsi
        mov [4*8 + rdx], rbp
        mov [5*8 + rdx], rsp
        mov rax, [rsp]
        mov [6*8 + rdx], rax

        mov [ 7*8 + rdx], r8
        mov [ 8*8 + rdx], r9
        mov [ 9*8 + rdx], r10
        mov [10*8 + rdx], r11
        mov [11*8 + rdx], r12
        mov [12*8 + rdx], r13
        mov [13*8 + rdx], r14
        mov [14*8 + rdx], r15

        xor eax, eax
        ret
       



        .align 0 
.global dr_longjmp 
.hidden dr_longjmp 
.type dr_longjmp, %function
dr_longjmp:
        mov rdx, rdi
        mov rax, rsi

        mov rbx, [ 0 + rdx]
        mov rdi, [2*8 + rdx]
        mov rsi, [3*8 + rdx]
        mov rbp, [4*8 + rdx]
        mov rsp, [5*8 + rdx]
        mov rcx, [6*8 + rdx]
        mov [rsp], rcx
        mov rcx, [ 8 + rdx]

        mov r8, [ 7*8 + rdx]
        mov r9, [ 8*8 + rdx]
        mov r10, [ 9*8 + rdx]
        mov r11, [10*8 + rdx]
        mov r12, [11*8 + rdx]
        mov r13, [12*8 + rdx]
        mov r14, [13*8 + rdx]
        mov r15, [14*8 + rdx]

        ret
       
# 1497 "x86/x86.asm"
        .align 0 
.global atomic_swap 
.hidden atomic_swap 
.type atomic_swap, %function
atomic_swap:
        mov rax, rsi
        mov rcx, rdi
        xchg [rcx], eax
        ret
       




        .align 0 
.global cpuid_supported 
.hidden cpuid_supported 
.type cpuid_supported, %function
cpuid_supported:
        pushfq
        pop rax
        mov ecx, eax
        xor eax, 0x200000
        push rax
        popfq
        pushfq
        pop rax
        cmp ecx, eax
        mov eax, 0
        setne al
        push rcx
        popfq
        ret
       





        .align 0 
.global our_cpuid 
.hidden our_cpuid 
.type our_cpuid, %function
our_cpuid:
        mov rdx, rdi
        mov rax, rsi
        push rbx
        push rdi

        mov rdi, rdx
        cpuid
        mov [ 0 + rdi], eax
        mov [ 4 + rdi], ebx
        mov [ 8 + rdi], ecx
        mov [12 + rdi], edx
        pop rdi
        pop rbx
        ret
       
# 1750 "x86/x86.asm"
        .align 0 
.global get_xmm_caller_saved 
.hidden get_xmm_caller_saved 
.type get_xmm_caller_saved, %function
get_xmm_caller_saved:
        mov rax, rdi
        movups [rax + 0*16], xmm0
        movups [rax + 1*16], xmm1
        movups [rax + 2*16], xmm2
        movups [rax + 3*16], xmm3
        movups [rax + 4*16], xmm4
        movups [rax + 5*16], xmm5

        movups [rax + 6*16], xmm6
        movups [rax + 7*16], xmm7


        movups [rax + 8*16], xmm8
        movups [rax + 9*16], xmm9
        movups [rax + 10*16], xmm10
        movups [rax + 11*16], xmm11
        movups [rax + 12*16], xmm12
        movups [rax + 13*16], xmm13
        movups [rax + 14*16], xmm14
        movups [rax + 15*16], xmm15

        ret
       





        .align 0 
.global hashlookup_null_handler 
.hidden hashlookup_null_handler 
.type hashlookup_null_handler, %function
hashlookup_null_handler:
# 1791 "x86/x86.asm"
        jmp qword ptr [rip + hashlookup_null_target]

       
# 1946 "x86/x86.asm"
        .align 0 
.global enter_interrupt_vector 
.hidden enter_interrupt_vector 
.type enter_interrupt_vector, %function
enter_interrupt_vector:
       


        .align 0 
.global handle_interrupt_native 
.hidden handle_interrupt_native 
.type handle_interrupt_native, %function
handle_interrupt_native:
# 1963 "x86/x86.asm"
     pushfq
     lea rsp, [rsp - 0x100]
     push r15
     push r14
     push r13
     push r12
     push r11
     push r10
     push r9
     push r8
     push rax
     push rcx
     push rdx
     push rbx
     push rbp
     push rsi
     push rdi
     mov rcx, 0xc0000101
  rdmsr
  shl rdx, 0x20
  or rdx, rax
  mov rbx, rdx
  push rbx
  mov rcx, 0xc0000102
  rdmsr
  shl rdx, 0x20
  or rdx, rax
  push rdx
  cmp rbx, rdx
  je no_swapgs1
  swapgs
  mov rcx, 0xef
  
 mov rdi, rcx 
 call get_kernel_vector_entry 

no_swapgs1:
  pop rdx
  pop rbx
  cmp rbx, rdx
  je no_swapgs2
  swapgs
no_swapgs2:

  pop rdi
  pop rsi
  pop rbp
  pop rbx
  pop rdx
  pop rcx
  pop rax
  pop r8
  pop r9
  pop r10
  pop r11
  pop r12
  pop r13
  pop r14
  pop r15
  lea rsp, [rsp + 0x100]
  popfq
  ret
       

        .align 0 
.global return_to_module_from_interrupt 
.type return_to_module_from_interrupt, %function
return_to_module_from_interrupt:
  push rbp
  push rbp
  mov rbp, rsp
  pushfq
  cli
  push rdi
  push rsi
  push rdx
  push rbx
  push rcx
  push rax
  push r8
  push r9
  push r10
  push r11
  push r12
  push r13
  push r14
  push r15
  call dr_get_client_return_address
  mov [8 + rbp], rax
  pop r15
  pop r14
  pop r13
  pop r12
  pop r11
  pop r10
  pop r9
  pop r8
  pop rax
  pop rcx
  pop rbx
  pop rdx
  pop rsi
  pop rdi
  popfq
  pop rbp
  jmp dr_app_start_after_iret
 



        .align 0 
.global mecontext_snapshot_native 
.hidden mecontext_snapshot_native 
.type mecontext_snapshot_native, %function
mecontext_snapshot_native:

        push r15
        push r14
        push r13
        push r12
        push r11
        push r10
        push r9
        push r8
        push rax
        push rcx
        push rdx
        push rbx
        push rsi
        push rdi
        push rbp
        mov rdi, rsp
        call dr_get_mcontext_snapshot
        pop rbp
        pop rdi
        pop rsi
        pop rbx
        pop rdx
        pop rcx
        pop rax
        pop r8
        pop r9
        pop r10
        pop r11
        pop r12
        pop r13
        pop r14
        pop r15
        ret
       




        .align 0 
.global native_sysret 
.hidden native_sysret 
.type native_sysret, %function
native_sysret:
        swapgs
        sysretq
       

        .align 0 
.global dr_native_iret 
.hidden dr_native_iret 
.type dr_native_iret, %function
dr_native_iret:
        swapgs
        iretq
       



    .align 0 
.global get_return_address 
.hidden get_return_address 
.type get_return_address, %function
get_return_address:
    mov rax, [rbp + 8]
    ret
   

    .align 0 
.global set_return_address 
.hidden set_return_address 
.type set_return_address, %function
set_return_address:
    mov [rbp + 8], rdi
    ret
   



