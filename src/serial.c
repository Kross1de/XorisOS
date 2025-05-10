#include "serial.h"
#include "kernel.h"
#include "port.h"

#define COM1 0x3f8

static void serial_configure()
{
       outb(COM1 + 1, 0x00);    
       outb(COM1 + 3, 0x80);    
       outb(COM1 + 0, 0x01);    
       outb(COM1 + 1, 0x00);    
       outb(COM1 + 3, 0x03);    
       outb(COM1 + 2, 0xC7);    
       outb(COM1 + 4, 0x0B);    
}

static int serial_is_transmit_empty() {
       return inb(COM1 + 5) & 0x20;
}

void serial_write(char c){
       while(serial_is_transmit_empty() == 0);
       outb(COM1, c);
}

void serial_write_string(const char *str){
       while(*str)
              serial_write(*str++);
       serial_write('\r');
}

void init_serial(){
       serial_configure();
       serial_write_string("Serial driver initialized\n");
}