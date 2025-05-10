CC 	= gcc
AS 	= nasm
LD 	= ld
QEMU	= qemu-system-i386

CFLAGS = -m32 -ffreestanding -nostdlib -nostartfiles -fno-stack-protector -nodefaultlibs -Wall -Wextra -Iinclude
LDFLAGS = -m elf_i386 -T linker.ld -nostdlib
QEMUFLAGS = -cdrom

SRC_DIR = src
BUILD_DIR = build
ISO_DIR = iso

OBJS = $(patsubst $(SRC_DIR)/%.asm, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR)/*.asm)) \
       $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(wildcard $(SRC_DIR)/*.c))

all: $(BUILD_DIR)/kernel.bin create_iso

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.asm
	$(AS) -f elf32 $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/kernel.bin: $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@

create_iso: $(BUILD_DIR)/kernel.bin
	mkdir -p $(ISO_DIR)/boot/grub
	cp $< $(ISO_DIR)/boot/
	cp grub/grub.cfg $(ISO_DIR)/boot/grub/
	grub-mkrescue -o xorisos.iso $(ISO_DIR)

run:
	$(QEMU) $(QEMUFLAGS) xorisos.iso

clean:
	rm -rf $(BUILD_DIR)/* $(ISO_DIR)/* xorisos.iso

.PHONY: all clean create_iso 
