// Assembly printf hello, Holberton
section .text
global main

main:
	mov rax, 1
	mov rdi, 1
	mov rsi, a
	mov rdx, alen
	syscall

	mov rax, 60
	mov rdi, 0
	syscall

section .rodata
	a: db "Hello, Holberton", 10
	alen: equ $ - a
