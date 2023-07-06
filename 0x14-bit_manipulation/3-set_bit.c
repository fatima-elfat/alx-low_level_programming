#include "main.h"
/**
 * set_bit - sets the value of a bit to 1
 * at a given index.
 * @n: the input value.
 * @index: the index, starting from 0
 * of the bit you want to set
 * Return: 1 if success, or -1 if error.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int size;
	unsigned long int a;

	size = (sizeof(unsigned long int) * 8);
	if (index > size)
	{
		return (-1);
	}

	a = 1 << index;
	*n = (*n | a);
	return (1);
}
