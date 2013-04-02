# 1 "kernel_linux/simple_tests/eflags_asm.asm"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "kernel_linux/simple_tests/eflags_asm.asm"
# 1 "/home/akshayk/GranaryCode/Granary-Drk/src/core/x86/asm_defines.asm" 1
# 41 "/home/akshayk/GranaryCode/Granary-Drk/src/core/x86/asm_defines.asm"
# 1 "/home/akshayk/GranaryCode/Granary-Drk/src/core/configure.h" 1
# 42 "/home/akshayk/GranaryCode/Granary-Drk/src/core/x86/asm_defines.asm" 2
# 2 "kernel_linux/simple_tests/eflags_asm.asm" 2
.text




        .align 0 
.global test_eflags_pos 
.hidden test_eflags_pos 
.type test_eflags_pos, %function
test_eflags_pos:

        mov rcx, rdi
        push rcx
        
 mov rdi, rcx 
 call set_flag 

        mov rcx, qword ptr [rsp]
        pushfq
        pop rax

        push 0
        popfq
        
 mov rdx, 1 
 mov rsi, rcx 
 mov rdi, rax 
 call test_flag 


        mov rcx, qword ptr [rsp]
        
 mov rdi, rcx 
 call clear_flag 

        mov rcx, qword ptr [rsp]
        pushfq
        pop rax

        push 0
        popfq
        
 mov rdx, 0 
 mov rsi, rcx 
 mov rdi, rax 
 call test_flag 


        pop rcx
        ret
       




        .align 0 
.global set_flag 
.hidden set_flag 
.type set_flag, %function
set_flag:

        pushfq
        pop rax
        mov rcx, rdi
        mov rdx, 1
        shl rdx, cl
        or rax, rdx
        push rax
        popfq
        ret
       




        .align 0 
.global clear_flag 
.hidden clear_flag 
.type clear_flag, %function
clear_flag:

        pushfq
        pop rax
        mov rcx, rdi
        mov rdx, 1
        shl rdx, cl
        not rdx
        and rax, rdx
        push rax
        popfq
        ret
       


