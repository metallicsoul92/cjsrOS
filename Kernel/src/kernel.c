#include "../include/kernel.h"
#include "../include/ports.h"
#include "../include/idt.h"
#include "../include/hdd.h"
#include "../../Libc/include/stdio.h"

char *buffer = (char*) 0x2000;
int kernel_main(struct multiboot *mboot_ptr){
	printf("Kernel created by Jark and Sander.");
	start_idt();
	readhdd(buffer,1,1);
	int i = 0;
	printf("\nHDD CONTAINS:\n");
	for(i = 0 ; i < 512 ; i++){
		printf("%c",buffer[i]);
	}
	for(;;);
  	return 0;
}




