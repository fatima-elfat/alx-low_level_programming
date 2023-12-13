#include "search_algos.h"
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
	if (*(array + middle - 1) == value && *(array + middle - 2) != value)
		return (middle + index - 1);
	else if (*(array + middle - 1) > value || *(array + middle - 2) == value)
		return (bl_recursive(array, middle, value, index));
	size -= middle;
	index += middle;
	array += middle;
	return (bl_recursive(array, size, value, index));
}
/**
 * advanced_binary - binary search the advanced version.
 * @array: the pointer to the first element of the array to search in.
 * @size:  the number of elements in array.
 * @value: the value to search for.
 * Return: the index where value is located.
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (bl_recursive(array, size, value, 0));
}
