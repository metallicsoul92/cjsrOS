#include "../include/ports.h"
#include "../include/idt.h"
struct idt_entry idt[IDT_SIZE];
struct idt_ptr idtp;

void setInterrupt(int i, unsigned long base) {
    idt[i].base_lo = (base & 0xFFFF);
    idt[i].base_hi = (base >> 16) & 0xFFFF;
    idt[i].sel = 0x10;
    idt[i].always0 = 0;
    idt[i].flags = 0x8E;
}

extern void irq_defaulte();
void defaulte(){}

//
// FROM: https://github.com/arjun024/mkeykernel/blob/master/kernel.c 
//

void start_idt(){

	// PROGRAMMABLE INTERUPT CONTROLLER INIT

	// ICW1 start init
	outportb(0x20,0x11);
	outportb(0xA0,0x11);
	// ICW2 remap offset IDT
	outportb(0x21,0x20);
	outportb(0xA1,0x28);
	//ICW3 setup cascading
	outportb(0x21,0x00);
	outportb(0xA1,0x00);
	//ICW4 - env info
	outportb(0x21,0x01);
	outportb(0xA1,0x01);
	// DEFINES INTS
	int i = 0;
	for(i = 0 ; i < IDT_SIZE ; i++){
		setInterrupt(i,(unsigned long)irq_defaulte);
	}
	idtp.limit = (sizeof (struct idt_entry) * IDT_SIZE) - 1;
    	idtp.base = (unsigned int) &idt;
	asm volatile("lidt idtp\nsti");
}
