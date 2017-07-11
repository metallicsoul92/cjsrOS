#include "../include/ports.h"
#include "../../Libc/include/stdio.h"

void error(char* a){
printf("%s\n");
asm volatile("cli\nhlt");
for(;;);
}
//
// FROM: https://github.com/AdeRegt/JamSan32/blob/master/src/main.c
// FROM: http://wiki.osdev.org/ATA_PIO_Mode
//

void readhdd(unsigned char* location, unsigned long LBA,unsigned char sectorcount){
	outportb(0x1F6, 0xE0 | ((LBA >> 24) & 0x0F));
    	outportb(0x1F1, 0);
    	outportb(0x1F2, sectorcount);
    	outportb(0x1F3, (unsigned char) LBA);
    	outportb(0x1F4, (unsigned char) (LBA >> 8));
	outportb(0x1F5, (unsigned char) (LBA >> 16));
	outportb(0x1F7, 0x20);
    	while (1) {
        	char val = inportb(0x1F7);
        	if ((val >> 0) & 1) {
            		char val = inportb(0x1F7);
            		if (val & 0x80) {
                		error("HDD: Bad sector");
            		} else if (val & 0x40) {
                		error("HDD: Uncorrectable data");
            		} else if (val & 0x20) {
                		error("HDD: No media");
            		} else if (val & 0x10) {
                		error("HDD: ID mark not found");
            		} else if (val & 0x08) {
                		error("HDD: No media");
            		} else if (val & 0x04) {
                		error("HDD: Command aborted");
            		} else if (val & 0x02) {
                		error("HDD: Track 0 not found");
            		} else if (val & 0x01) {
                		error("HDD: No address mark");
            		} else {
                		error("HDD error bit 0 is set");
            		}
        	}
        	if ((val >> 3) & 1) {
            		break;
        	}
    	}
    	int i = 0;
    	int z = 0;
    	for (i = 0; i < (512 / 2); i++) {
        	short d = inportw(0x1F0);
        	location[z++] = d;
        	location[z++] = (unsigned char) (d >> 8);
	}
}
