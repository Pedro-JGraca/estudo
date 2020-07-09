section .text

global _start

mensagem db 'Hello world', 0x0a


_start:
	mov rax, 	1				;
	mov rdi,  1 			;
	mov rsi, mensagem	;
	mov rdx, 12				;
	syscall
	
	mov rax, 60 			;exit
	
	syscall
