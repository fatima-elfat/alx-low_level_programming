// Assembly printf hello, Holberton
section .text
extern printf
global main

main:
	mov edi, msg
	mov eax, 0
	call printf

section .data
	msg: db "Hello, Holberton", 10
	msglen: equ $ - msg 
