#include "main.h"

/**
 * _strncpy - copy a n byte from a string
 * @dest: input string
 * @src: input string to copy from
 * @n: number of bytes to copy
 * Return: the copied string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, l2, l1 = -1;

	/*l1 = _strlen(dest);*/
	l2 = _strlen(src);

	if (n > l2)
	{
		l1 = n;
		n = l2;
	}
	for (i = 0; i < n ; i++)
		dest[i] = src[i];
	if (l1 != -1)
	{
		for (i = n; i < l1 ; i++)
			dest[i] = '\0';
	}

	return (dest);
}
