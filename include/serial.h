#ifndef SERIAL_H
#define SERIAL_H

void init_serial();
void serial_write(char c);
void serial_write_string(const char *str);

#endif