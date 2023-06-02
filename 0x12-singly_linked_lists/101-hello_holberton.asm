// Assembly printf hello, Holberton
	SECTION .text
	extern printf
	global main
main:
	mov esi, msg
	mov edi, a
	mov eax, 0
	call printf

	mov eax, 0
	ret
	SECTION .data
msg:	db "Hello, Holberton", 0
a:	db "%s", 10, 0

