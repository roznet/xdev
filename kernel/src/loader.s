;
; boot.s -- Kernel start location. Also defines multiboot header.
;           Based on Bran's kernel development tutorial file start.asm
;

bits 32                         ; All instructions should be 32-bit.

section .multiboot_header
header_start:
	; magic number
	dd 0xe85250d6 ; multiboot2
	; architecture
	dd 0 ; protected mode i386
	; header length
	dd header_end - header_start
	; checksum
	dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))

	; end tag
	dw 0
	dw 0
	dd 8
header_end:

section .text

extern code
extern bss
extern end

        
global start:function start.end-start ; Kernel entry point.
extern kernel_main                    ; This is the entry point of our C code

start:
    cli                         ; Disable interrupts.
    mov esp, stack              ; Set up our own stack.
    push ebx                  	; Push a pointer to the multiboot info structure.
    mov ebp, 0                  ; Initialise the base pointer to zero so we can 
                                ; terminate stack traces here.
    call kernel_main            ; call our main() function.
    jmp $                       ; Enter an infinite loop, to stop the processor
.end:                           ; from executing whatever rubbish is in the memory
                                ; after our kernel!

section .bss
    resb 32768
stack:
