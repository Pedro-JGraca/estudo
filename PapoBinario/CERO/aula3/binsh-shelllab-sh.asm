section .text

global _start

shell db '/bin/sh', 0x00


_start:
	mov rax, 	59			;
	mov rdi,  shell		;ponteiro
	mov rsi, 	0				;
	mov rdx, 	0				;
	syscall
	
	mov rax, 60 			;exit
	
	syscall
