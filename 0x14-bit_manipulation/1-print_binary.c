#include "main.h"

/**
 * print_binary - converts unsigned int to binary
 * @n: unsigned int
 * Return: binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int a;

	if (n == 0)
	{
		putchar('0');
		return;
	}
	a = 1ul << 63;
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
