#include "main.h"

/**
 * _strcpy - copy the string
 * @dest: destination of the string
 * @src: souece of the string
 * Return: copied string
 */
char *_strcpy(char *dest, char *src)
{
	int l, i;

	l = _strlen(src);

	for (i = 0; i <= l; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
