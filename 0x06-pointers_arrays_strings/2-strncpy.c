#include "main.h"
/**
 * _strlen - returns the length of a string
 * @s: input string
 * Return: length
 */

int _strlen(char *s)
{
	int l = 0;

	while (*s != '\0')
	{
		l++;
		s++;
	}

	return (l);
}

/**
 * _strncpy - copy a n byte from a string
 * @dest: input string
 * @src: input string to copy from
 * @n: number of bytes to copy
 * Return: the copied string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, l2;

	/*l1 = _strlen(dest);*/
	l2 = _strlen(src);

	if (n > l2)
		n = l2;
	for (i = 0; i < n ; i++)
		dest[i] = src[i];
	return (dest);
}
