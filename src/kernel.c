#include "kernel.h"
#include "idt.h"
#include "serial.h"
void kmain() {
       clrScr();
       InitIdt();
       extern struct idt_ptr idtp;
       print("IDT Base Addr: ");
       printHex(idtp.base);
       print("\n\n");
       init_serial();
       print("                       ===========================\n");
       print("                       ==   Welcome to XorisOS  ==\n");
       print("                       ==   (c) kross1de  2025  ==\n");
       print("                       ===========================\n");
       
       while (1) {}
}

void clrScr() {
       unsigned short *video_memory = (unsigned short *)0xB8000;
       for (int i = 0; i < 80 * 25; i++) {
              video_memory[i] = (unsigned short)(' ' | (0x07 << 8));
       }
}

void print(const char *str) {
       unsigned short *video_memory = (unsigned short *)0xB8000;
       static int line = 0;
       static int col = 0;
       int i = 0;
       while (str[i] != '\0') {
              if (str[i] == '\n') {
                     line++;
                     col = 0;
                     i++;
                     continue;
              }
              int offset = (line * 80) + col;
              video_memory[offset] = (unsigned short)(str[i] | (0x0F << 8));
              col++;
              if (col >= 80) {
                     col = 0;
                     line++;
              }
              i++;
       }
} 

void printHex(unsigned int num)
{
       char hex[11];
       hex[0] = '0';
       hex[1] = 'x';
       for(int i = 7; i >= 0; i--){
              int digit = (num >> (i*4)) & 0xf;
              hex[2+(7-i)] = (digit < 10 ? '0' + digit : 'A' + digit - 10);
       }
       hex[10] = '\0';
       print(hex);
}
