// Assembly printf hello, Holberton
section .text
extern printf
global main

main:
	mov eax, 1
	mov edi, 1
	mov esi, a
	mov edx, alen
	call printf

section .data
	a: db "Hello, Holberton", 10
	alen: equ $ - a
