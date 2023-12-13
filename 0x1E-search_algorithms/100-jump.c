#include "search_algos.h"
/**
 * print1 - ...
 * @array: ...
 * @index: ...
 */
void print1(int *array, size_t index)
{
	printf("Value checked array[%lu] = [%d]\n", index, array[index]);
}
/**
 * jump_search - searches for a value in a sorted array of
 * integers using the Jump search algorithm. If value is not
 * present in array or if array is NULL, your function must
 * return -1.
 * @array: a pointer to the first element of the
 * array to search in.
 * @size:  the number of elements in array.
 * @value:  the value to search for.
 * Return: the first index where value is located.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t a, b, block_s;

	if (!array || !size)
		return (-1);
	block_s = sqrt(size);
	for (a = b = 0; b < size && array[b] < value;)
	{
		print1(array, b);
		a = b;
		b += block_s;
	}
	printf("Value found between indexes [%ld] and [%ld]\n", a, b);
	if (b >= size)
		b = size - 1;
	for (; a < b && array[a] < value; a++)
		print1(array, a);
	print1(array, a);
	if (array[a] == value)
		return ((int)a);
	return (-1);
}
