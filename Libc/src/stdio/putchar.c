#include "../../include/stdio.h"

#if defined(__is_libk)
#include <kernel/tty.h>
#endif

char *videomemory = (char*) 0xb8000;
int vidmempointer = 0;

int putchar(int ic) {
videomemory[vidmempointer++] = (char) ic;
videomemory[vidmempointer++] = 0x07;
//#if defined(__is_libk)
//	char c = (char) ic;
//	if(c == '\n' || c== '\r'){
//		tty_newl();
//		return ic;
//	}
//	terminal_write(&c, sizeof(c));
//#else
//	// TODO: Implement stdio and the write system call.
//#endif
	return ic;
}


int putline(char * string){
	#if defined(__is_libk)
		terminal_writeLine(string);
	#else
	// TODO : Implement stdio and the write system call.
	#endif
	return 0;
}
