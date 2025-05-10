#include "idt.h"
#include "serial.h"
const char *exception_messages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",
    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",
    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "SIMD Floating-Point Exception",
    "Virtualization Exception",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

void isr_handler(struct regs *r) {
       if(r->int_no < 32) {
              serial_write_string("Exception occurred: ");
              serial_write_string(exception_messages[r->int_no]);
              serial_write_string("\n");
              while(1);
       }
}

void isr0() { asm volatile("cli; push $0; push $0; jmp isr_common_stub"); }
void isr1() { asm volatile("cli; push $0; push $1; jmp isr_common_stub"); }
void isr2() { asm volatile("cli; push $0; push $2; jmp isr_common_stub"); }
void isr3() { asm volatile("cli; push $0; push $3; jmp isr_common_stub"); }
void isr4() { asm volatile("cli; push $0; push $4; jmp isr_common_stub"); }
void isr5() { asm volatile("cli; push $0; push $5; jmp isr_common_stub"); }
void isr6() { asm volatile("cli; push $0; push $6; jmp isr_common_stub"); }
void isr7() { asm volatile("cli; push $0; push $7; jmp isr_common_stub"); }
void isr8() { asm volatile("cli; push $8; jmp isr_common_stub"); }
void isr9() { asm volatile("cli; push $0; push $9; jmp isr_common_stub"); }
void isr10() { asm volatile("cli; push $10; jmp isr_common_stub"); }
void isr11() { asm volatile("cli; push $11; jmp isr_common_stub"); }
void isr12() { asm volatile("cli; push $12; jmp isr_common_stub"); }
void isr13() { asm volatile("cli; push $13; jmp isr_common_stub"); }
void isr14() { asm volatile("cli; push $14; jmp isr_common_stub"); }
void isr15() { asm volatile("cli; push $0; push $15; jmp isr_common_stub"); }
void isr16() { asm volatile("cli; push $0; push $16; jmp isr_common_stub"); }
void isr17() { asm volatile("cli; push $17; jmp isr_common_stub"); }
void isr18() { asm volatile("cli; push $0; push $18; jmp isr_common_stub"); }
void isr19() { asm volatile("cli; push $0; push $19; jmp isr_common_stub"); }
void isr20() { asm volatile("cli; push $0; push $20; jmp isr_common_stub"); }
void isr21() { asm volatile("cli; push $0; push $21; jmp isr_common_stub"); }
void isr22() { asm volatile("cli; push $0; push $22; jmp isr_common_stub"); }
void isr23() { asm volatile("cli; push $0; push $23; jmp isr_common_stub"); }
void isr24() { asm volatile("cli; push $0; push $24; jmp isr_common_stub"); }
void isr25() { asm volatile("cli; push $0; push $25; jmp isr_common_stub"); }
void isr26() { asm volatile("cli; push $0; push $26; jmp isr_common_stub"); }
void isr27() { asm volatile("cli; push $0; push $27; jmp isr_common_stub"); }
void isr28() { asm volatile("cli; push $0; push $28; jmp isr_common_stub"); }
void isr29() { asm volatile("cli; push $0; push $29; jmp isr_common_stub"); }
void isr30() { asm volatile("cli; push $0; push $30; jmp isr_common_stub"); }
void isr31() { asm volatile("cli; push $0; push $31; jmp isr_common_stub"); }