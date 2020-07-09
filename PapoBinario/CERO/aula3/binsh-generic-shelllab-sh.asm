section .text

global _start

_start:

	mov rax , 0x0068732f6e69622f ; /bin/sh | xxd inverte por byte e bota 00 no inicio
	push rax
	mov rdi,  rsp		;ponteiro pra pilha

	mov rax, 	59			;
	mov rsi, 	0				;
	mov rdx, 	0				;
	syscall
	
	mov rax, 60 			;exit
	
	syscall
