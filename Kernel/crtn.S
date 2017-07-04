.section .init
global _init:function
	/* gcc will nicely put the contents of crtend.o's .init section here. */
	popl ebp
	ret

.section .fini
	global _fini:function
	/* gcc will nicely put the contents of crtend.o's .fini section here. */
	popl ebp
	ret
