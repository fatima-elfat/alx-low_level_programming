#include "main.h"

/**
 * print_binary - converts unsigned int to binary
 * @n: unsigned int
 * Return: binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int a;

	a = n;
	if (n == 0)
	{
		_putchar('0');
		return;
	}
	if (n == 1)
	{
		_putchar('1');
		return;
	}
	while (a > 0)
	{
		if ((a & n) == 0)
		{
			_putchar('0');
		}
		else
		{
			_putchar('1');
		}
		a = (a >> 1);
	}
}
