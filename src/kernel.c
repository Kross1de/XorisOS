#include "kernel.h"
#include "idt.h"
#include "serial.h"
void kmain() {
       clrScr();
       print("                       ===========================\n");
       print("                       ==   Welcome to XorisOS  ==\n");
       print("                       ==   (c) kross1de  2025  ==\n");
       print("                       ===========================\n");

       InitIdt();
       init_serial();
       
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
