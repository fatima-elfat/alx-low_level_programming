#include "main.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: pointer to the memory previously allocated.
 * @old_size: size of space of ptr.
 * @new_size: new size of the new memory.
 * Return: pointer.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *p;

	if (new_size == 0)
	{
		if (ptr != NULL)
			free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size > old_size)
	{
		i = 0;
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		while (i < old_size)
		{
			p[i] = ((char *)ptr)[i];
			i++;
		}
		free(ptr);
		return (p);
	}
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	while (i < new_size)
	{
		p[i] = ((char *)ptr)[i];
		i++;
	}
	free(ptr);
	return (p);
}
