CC = gcc
AS = nasm
LD = ld

CFLAGS = -m32 -ffreestanding -nostdlib -nostartfiles -nodefaultlibs -Wall -Wextra -Iinclude
LDFLAGS = -m elf_i386 -T linker.ld -nostdlib

SRC_DIR = src
BUILD_DIR = build
ISO_DIR = iso

all: $(BUILD_DIR)/kernel.bin create_iso

$(BUILD_DIR)/boot.o: $(SRC_DIR)/boot.asm
	$(AS) -f elf32 $< -o $@

$(BUILD_DIR)/kernel.o: $(SRC_DIR)/kernel.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/idt.o: $(SRC_DIR)/idt.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/serial.o: $(SRC_DIR)/serial.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/kernel.bin: $(BUILD_DIR)/boot.o $(BUILD_DIR)/kernel.o $(BUILD_DIR)/idt.o $(BUILD_DIR)/serial.o
	$(LD) $(LDFLAGS) $^ -o $@

create_iso: $(BUILD_DIR)/kernel.bin
	mkdir -p $(ISO_DIR)/boot/grub
	cp $< $(ISO_DIR)/boot/
	cp grub/grub.cfg $(ISO_DIR)/boot/grub/
	grub-mkrescue -o xorisos.iso $(ISO_DIR)

clean:
	rm -rf $(BUILD_DIR)/* $(ISO_DIR)/* xorisos.iso

.PHONY: all clean create_iso 
