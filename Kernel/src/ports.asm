;
; FROM: https://github.com/arjun024/mkeykernel/blob/master/kernel.asm
;

bits 32
global inportb
global outportb

section .text
inportb:
	mov edx, [esp + 4]
			;al is the lower 8 bits of eax
	in al, dx	;dx is the lower 16 bits of edx
	ret

outportb:
	mov   edx, [esp + 4]    
	mov   al, [esp + 4 + 4]  
	out   dx, al  
	ret

global inportw

inportw:
	mov edx,[esp+4]
	in ax,dx
	ret
outportw:
