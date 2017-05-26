; ASSEMBLING INSTRUCTIONS FOR LINUX
; At the command line, type the following to assemble your code:
;	nasm -f elf file.asm
;	gcc -m32 -o file.out file.o
; NOTE: Replace "file" with the actual file name.

SECTION .data	;initialized data

msg: db "Hello world!", 10, 0

SECTION .bss	;uninitialized data

SECTION .text	;asm code

extern printf
global main
main:
	push ebp
	mov ebp, esp

	push msg
	call printf

	mov esp, ebp
	pop ebp
	ret
