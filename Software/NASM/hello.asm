; Assembling and Running in Linux:
;
;  - Open a terminal
;  - Navigate to the same directory as hello.asm
;      cd ~/Documents/Programs/jkwalter.github.io/Software/NASM
;  - Type the following to assemble hello.asm
;      nasm -f elf hello.asm
;      gcc -m32 -o hello.out hello.o
;  - Type the following to run the assembled code
;      ./hello.out 

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
