#include "search_algos.h"

/**
 * ls_recursive - linear search recursive.
 * @array: the pointer to the first element of the array to search in.
 * @size:  the number of elements in array.
 * @value: the value to search for.
 * @index: the value of index.
 * Return: the first index where value is located.
 */
int ls_recursive(int *array, size_t size, int value, size_t index)
{
	if (!array)
		return (-1);
	printf("Value checked array[%lu] = [%d]\n", index, *array);
	if (*array == value)
		return ((int)index);
	else if (size == 1)
		return (-1);
	index++;
	array++;
	if (index == size)
		return (-1);
	return (ls_recursive(array, size, value, index));
}
/**
 * linear_search - searches for a value in an array of integers
 * using the Linear search algorithm. If value is not
 * present in array or if array is NULL, your function
 * must return -1.
 * @array: the pointer to the first element of the array to search in.
 * @size:  the number of elements in array.
 * @value: the value to search for.
 * Return: the first index where value is located.
 */
int linear_search(int *array, size_t size, int value)
{
	return (ls_recursive(array, size, value, 0));
}
