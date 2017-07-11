bits 32
section .text

%macro interrupt 1
global irq_%1
extern %1
irq_%1:
    pusha
    push ds
    push es
    push fs
    push gs
    push eax
    call %1
    mov al,0x20
    out 0x20,al
    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa
    iret
%endmacro


interrupt defaulte


