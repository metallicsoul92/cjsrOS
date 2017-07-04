section .init
global _init:function
	pop	ebx
	pop	ebp
	ret



section .fini
global _fini:function
	pop	ebx
	pop	ebp
	ret
