#include "main.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * _calloc -  allocates memory for an array, using malloc.
 * @nmemb: nember of elements.
 * @size: size of byte.
 * Return: pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i, a;

	if (nmemb == 0 || size == 0)
		return (NULL);
	a = nmemb * size;
	p = malloc(a);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < a; i++)
		p[i] = 0;
	return (p);
}

