#include "main.h"
/**
 * _memcpy - copies memory area.
 * @dest: pointer of the where to copy
 * @src: pointer to the source
 * @n: numbers of bytes to copy
 * Return: the pointer to copied bytes
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
