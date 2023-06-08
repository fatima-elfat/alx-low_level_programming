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
	unsigned long int diff;

	diff = n ^ m;
	r += (diff & 1);
	diff = diff >> 1;
	while (diff > 0)
	{
		r += (diff & 1);
		diff = diff >> 1;
	}
	return (r);
}
