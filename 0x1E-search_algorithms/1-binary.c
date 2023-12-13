#include "search_algos.h"
/**
 * print_list - prints array.
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

	if (!array)
		return (-1);
	print_list(array, size);
	printf ("%d\n", value);
	if (*array == value)
		return ((int)index);
	else if (size == 2)
	{
		if (*(array + 1) == value)
			return ((int)index);
		else
			return (-1);
	}
	middle = (int)(size / 2);
	if (*(array + middle - 1) > value)
		return (bl_recursive(array, middle - 1, value, index));
	else if (*(array + middle - 1) == value)
		return (middle);
	else
	{
		size -= middle;
		while (middle--)
		{
			index++;
			array++;
		}
		return (bl_recursive(array, size, value, index));
	}
}
/**
 * binary_search - searches for a value in a
 * sorted array of integers using the Binary search algorithm,
 * If value is not present in array or if array is NULL,
 * your function must return -1.
 * @array: the pointer to the first element of the array to search in.
 * @size:  the number of elements in array.
 * @value: the value to search for.
 * Return: the index where value is located.
 */
int binary_search(int *array, size_t size, int value)
{
	return (bl_recursive(array, size, value, 0));
}
