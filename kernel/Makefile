SRCDIR=src
OBJDIR=obj
TARGETDIR=iso/boot

SRC=$(shell find $(SRCDIR) -name *.c)
ASM=$(shell find $(SRCDIR) -name *.s)
COBJ=$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
CDEP=$(COBJ:%.o=%.d)
SOBJ=$(patsubst $(SRCDIR)/%.s, $(OBJDIR)/%.o, $(ASM))
OBJECTS=$(COBJ) $(SOBJ)

CC = gcc
CFLAGS = -g -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
LDFLAGS = -T $(SRCDIR)/link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

.PHONY: all
all: directories os.iso

.PHONY: directories

directories:
	@mkdir -p $(OBJDIR)

$(TARGETDIR)/kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o $(TARGETDIR)/kernel.elf

$(TARGETDIR)/initrd.img:
	echo "Simple Ram Disk Data" > $@

-include $(CDEP)

.PHONY: depend
depend: $(CDEP)

os.iso: $(TARGETDIR)/kernel.elf $(TARGETDIR)/initrd.img
	grub-mkrescue /usr/lib/grub/i386-pc -o os.iso iso

run: os.iso
	qemu-system-i386 -cdrom os.iso

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	$(AS) $(ASFLAGS) $< -o $@

$(OBJDIR)/%.d: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -MMD -MF $@ -c $^ -o $(@:.d=.o)

clean:
	rm -rf os.iso $(OBJDIR)/*.o $(OBJDIR)/*.d $(TARGETDIR)/kernel.elf $(TARGETDIR)/initrd.img


