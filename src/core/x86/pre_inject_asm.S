# 1 "x86/pre_inject_asm.asm"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "x86/pre_inject_asm.asm"
# 33 "x86/pre_inject_asm.asm"
# 1 "x86/asm_defines.asm" 1
# 41 "x86/asm_defines.asm"
# 1 "/home/akshayk/GranaryCode/Granary-Drk/src/core/configure.h" 1
# 42 "x86/asm_defines.asm" 2
# 34 "x86/pre_inject_asm.asm" 2
.text








# 73 "x86/pre_inject_asm.asm"
        .align 0 
.global DllMain 
.hidden DllMain 
.type DllMain, %function
DllMain:
        cmp rsi, 1
        jne DllMain_not_pattach


        push rcx

        
 call process_attach 






        pop rcx
# 102 "x86/pre_inject_asm.asm"
        jmp FreeLibrary
DllMain_not_pattach:
        mov eax, 1

        ret



       
# 215 "x86/pre_inject_asm.asm"

