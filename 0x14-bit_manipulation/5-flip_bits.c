#include "main.h"
/**
 * flip_bits - returns the number of bits you would need
 * to flip to get from one number to another.
 * @n: the input value.
 * @m: the other value.
 * Return: the number of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int r = 0;
	unsigned long int a;

	a = n ^ m;
	r += (a & 1);
	a = a >> 1;
	while (a > 0)
	{
		r += (a & 1);
		a = a >> 1;
	}
	return (r);
}

