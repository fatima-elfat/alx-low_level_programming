#include "main.h"
#include <stdio.h>
/**
 * print_binary - converts unsigned int to binary
 * @n: unsigned int
 * Return: binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int a, b;

	if (n == 0)
	{
		_putchar('0');
	}
	a = n;
	b = 1ul << 63;
	while (b != 0 && (a & b) == 0)
	{
		b = (b >> 1);
	}
	while (b > 0)
	{

		if ((a & b) == 0)
		{
			_putchar('0');
		}
		else
		{
			_putchar('1');
		}
		b = (b >> 1);
	}
}

