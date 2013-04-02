# 1 "kernel_linux/simple_tests/exception_asm.asm"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "kernel_linux/simple_tests/exception_asm.asm"
# 1 "/home/akshayk/GranaryCode/Granary-Drk/src/core/x86/asm_defines.asm" 1
# 41 "/home/akshayk/GranaryCode/Granary-Drk/src/core/x86/asm_defines.asm"
# 1 "/home/akshayk/GranaryCode/Granary-Drk/src/core/configure.h" 1
# 42 "/home/akshayk/GranaryCode/Granary-Drk/src/core/x86/asm_defines.asm" 2
# 2 "kernel_linux/simple_tests/exception_asm.asm" 2
.text

        .align 0 
.global exception_main 
.hidden exception_main 
.type exception_main, %function
exception_main:
        mov rdi, rsp
        inc rdi
        mov rsi, 0x2
        mov rbp, 0x3

        mov rbx, 0x5
        mov rdx, 0x6
        mov rcx, 0x7
        mov rax, 0x8
        mov r8, 0x9
        mov r9, 0xa
        mov r10, 0xb
        mov r11, 0xc
        mov r12, 0xd
        mov r13, 0xe
        mov r14, 0xf
        mov r15, 0x10

        int3

        movq rdi, [rbx]
        ret

       
