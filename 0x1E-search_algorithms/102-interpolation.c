#include "search_algos.h"
/**
 * print1 - ...
 * @array: ...
 * @index: ...
 * @t: ...
 */
void print1(int *array, size_t index, int t)
{
	if (t == 0)
		printf("Value checked array[%lu] = [%d]\n", index, array[index]);
	else
		printf("Value checked array[%ld] is out of range\n", index);
}
/**
  * interpolation_search - searches for a value in a sorted array
  * of integers using the Interpolation search algorithm.
  * @array: a pointer to the first element of the array to search in.
  * @size:  the number of elements in array.
  * @value: the value to search for.
  * Return: the first index where value is located.
  */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low, middle, high;

	if (array == NULL)
		return (-1);

	for (low = 0, high = size - 1; high >= low;)
	{
		middle = low + (((double)(high - low) /
			(array[high] - array[low])) * (value - array[low]));
		if (middle < size)
			print1(array, middle, 0);
		else
		{
			print1(array, middle, 1);
			break;
		}
		if (array[middle] == value)
			return (middle);
		if (array[middle] < value)
			low = middle + 1;
		else
			high = middle - 1;
	}
	return (-1);
}
