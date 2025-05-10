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

       //set up isr handlers
       idt_set_gate(0, (unsigned long)isr0, 0x08, 0x8E);
       idt_set_gate(1, (unsigned long)isr1, 0x08, 0x8E);
       idt_set_gate(2, (unsigned long)isr2, 0x08, 0x8E);
       idt_set_gate(3, (unsigned long)isr3, 0x08, 0x8E);
       idt_set_gate(4, (unsigned long)isr4, 0x08, 0x8E);
       idt_set_gate(5, (unsigned long)isr5, 0x08, 0x8E);
       idt_set_gate(6, (unsigned long)isr6, 0x08, 0x8E);
       idt_set_gate(7, (unsigned long)isr7, 0x08, 0x8E);
       idt_set_gate(8, (unsigned long)isr8, 0x08, 0x8E);
       idt_set_gate(9, (unsigned long)isr9, 0x08, 0x8E);
       idt_set_gate(10, (unsigned long)isr10, 0x08, 0x8E);
       idt_set_gate(11, (unsigned long)isr11, 0x08, 0x8E);
       idt_set_gate(12, (unsigned long)isr12, 0x08, 0x8E);
       idt_set_gate(13, (unsigned long)isr13, 0x08, 0x8E);
       idt_set_gate(14, (unsigned long)isr14, 0x08, 0x8E);
       idt_set_gate(15, (unsigned long)isr15, 0x08, 0x8E);
       idt_set_gate(16, (unsigned long)isr16, 0x08, 0x8E);
       idt_set_gate(17, (unsigned long)isr17, 0x08, 0x8E);
       idt_set_gate(18, (unsigned long)isr18, 0x08, 0x8E);
       idt_set_gate(19, (unsigned long)isr19, 0x08, 0x8E);
       idt_set_gate(20, (unsigned long)isr20, 0x08, 0x8E);
       idt_set_gate(21, (unsigned long)isr21, 0x08, 0x8E);
       idt_set_gate(22, (unsigned long)isr22, 0x08, 0x8E);
       idt_set_gate(23, (unsigned long)isr23, 0x08, 0x8E);
       idt_set_gate(24, (unsigned long)isr24, 0x08, 0x8E);
       idt_set_gate(25, (unsigned long)isr25, 0x08, 0x8E);
       idt_set_gate(26, (unsigned long)isr26, 0x08, 0x8E);
       idt_set_gate(27, (unsigned long)isr27, 0x08, 0x8E);
       idt_set_gate(28, (unsigned long)isr28, 0x08, 0x8E);
       idt_set_gate(29, (unsigned long)isr29, 0x08, 0x8E);
       idt_set_gate(30, (unsigned long)isr30, 0x08, 0x8E);
       idt_set_gate(31, (unsigned long)isr31, 0x08, 0x8E);

       asm volatile("lidt %0" : : "m" (idtp));
       serial_write_string("Initialized IDT\n");
}