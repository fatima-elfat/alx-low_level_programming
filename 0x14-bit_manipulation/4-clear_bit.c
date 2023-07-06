#include "main.h"
/**
 * clear_bit - sets the value of a bit to 0
 * at a given index.
 * @n: the input value.
 * @index: is the index, starting from 0
 * of the bit you want to set
 * Return: 1 if success, or -1 if error.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int size;
	unsigned long int a;

	/*which is  64*/
	size = (sizeof(unsigned long int) * 8);
	if (index > size)
	{
		return (-1);
	}
	/* for 8 bit and index 2 it will be 11111011*/
	a = ~(1 << index);
	*n = (*n & a);
	return (1);
}
