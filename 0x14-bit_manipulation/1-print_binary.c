#include "main.h"

/**
 * print_binary - converts unsigned int to binary
 * @n: unsigned int
 * Return: binary
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
	{
		putchar('0');
	}
	if (n >> 1)
	{
		print_binary(n >> 1);
	}
	
	if ((1 & n) == 0)
	{
		putchar('0');
	}
	else
	{
	_putchar('1');
	}
}
