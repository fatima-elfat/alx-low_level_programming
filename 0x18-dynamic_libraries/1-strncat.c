#include "main.h"

/**
 * _strncat - concatenate n bytes from src
 * @dest: input string to concatenate to
 * @src: input string to tage n bytes from
 * @n: input int of the number of bytes to add to dest
 * Return: the result
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, l1, l2;

	l1 = _strlen(dest);
	l2 = _strlen(src);

	if (n > l2)
		n = l2;
	for (i = 0; i < n ; i++)
		dest[l1 + i] += src[i];
	return (dest);
}
