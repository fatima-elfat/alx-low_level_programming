#include "function_pointers.h"
#include <stddef.h>
/**
  * int_index -  searches for an integer.
  * @array: input array.
  * @size: the size of array.
  * @cmp: pointer to function.
  * Return: index of found element.
  */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size > 0)
	{
		if (array != NULL && cmp != NULL)
		{
			for (i = 0; i < size; i++)
			{
				if (cmp(array[i]) != 0)
					return (i);
			}
		}
	}
	return (-1);
}
