#include "../include/kernel.h"
#include "../include/ports.h"
#include "../include/idt.h"
#include "../../Libc/include/stdio.h"


int kernel_main(struct multiboot *mboot_ptr){
	printf("Kernel created by Jark and Sander.");
	start_idt();
	for(;;);
  	return 0;
}




