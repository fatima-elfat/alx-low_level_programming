// Assembly printf hello, Holberton
	SECTION .text
	extern printf
	global main
main:
	mov esi, str
	mov eax, 0
	call printf

	SECTION .data
str:	db "Hello, Holberton", 0xa, 0
