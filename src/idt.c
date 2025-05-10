#include "idt.h"
#include "kernel.h"
#include "serial.h"
struct idt_entry idt[IDT_SIZE];
struct idt_ptr idtp;

void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
       idt[num].base_lo = (base & 0xffff);
       idt[num].base_hi = (base >> 16) & 0xffff;
       idt[num].sel = sel;
       idt[num].always0 = 0;
       idt[num].flags = flags;
}

void InitIdt(){ 
       idtp.limit = (sizeof(struct idt_entry) * IDT_SIZE) - 1;
       idtp.base = (unsigned int)&idt;

       for(int i = 0; i < IDT_SIZE; i++) {
              idt_set_gate(i, 0, 0, 0);
       }

       asm volatile("lidt %0" : : "m" (idtp));
       serial_write_string("Initialized IDT\n");
}