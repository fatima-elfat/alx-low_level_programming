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
 * print_list - prints array.
 * @array: ...
 * @size:  the number of elements in array.
*/
void print_list(int *array, size_t size)
{
	size_t i = 0;

	printf("Searching in array: ");
	for (i = 0; i < size - 1; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}
/**
 * bl_recursive - Binary search algorithm recursive.
 * @array: the pointer to the first element of the array to search in.
 * @size:  the number of elements in array.
 * @value: the value to search for.
 * @index: middle.
 * Return: the index where value is located.
 */
int bl_recursive(int *array, size_t size, int value, size_t index)
{
	int middle;

	if (!array || !size)
		return (-1);
	print_list(array, size);
	if (*array == value)
		return ((int)index);
	else if (size == 1)
		return (-1);
	middle = (size % 2 == 0) ? (int)(size / 2) : (int)((size / 2) + 1);
	if (*(array + middle - 1) > value)
		return (bl_recursive(array, middle - 1, value, index));
	else if (*(array + middle - 1) == value)
		return (middle + index - 1);
	size -= middle;
	while (middle--)
	{
		index++;
		array++;
	}
	return (bl_recursive(array, size, value, index));
}
/**
 * exponential_search - searches for a value in a
 * sorted array of integers using the Exponential
 * search algorithm.
 * @array: a pointer to the first element
 * of the array to search in.
 * @size: the number of elements in array.
 * @value: the value to search for.
 * Return:  the first index where value is located.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t b, bnd = 0, v;

	if (!array)
		return (-1);
	if (*array != value)
	{
		for (bnd = 1; bnd < size && array[bnd] <= value; bnd = bnd * 2)
			print1(array, bnd);
	}
	if (bnd < size)
		b = bnd;
	else
		b = size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", bnd / 2, b);
	v = bnd / 2;
	b = b - (bnd / 2) + 1;
	while (v--)
		array++;
	return (bl_recursive(array, b, value, bnd / 2));
}
