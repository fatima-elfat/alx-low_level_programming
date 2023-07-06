#include "main.h"
/**
 * get_bit - returns the value of a bit at a given index.
 * @n: the input number.
 * @index: the index,
 * starting from 0 of the bit you want to get.
 * Return: the value of the bit at index
 * index or -1 if an error occured.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int size;

	/* 64 or 63*/
	size = (sizeof(unsigned long int) * 8);
	if (index > size)
	{
		return (-1);
	}
	return ((n >> index) & 1);
}

