#include "main.h"
/**
 * _strpbrk - searches a string for any of a set of bytes.
 * @s: the string
 * @accept: set of bytes
 *
 * Return: a pointer to the byte in s that matches one of the bytes in accept
 */
char *_strpbrk(char *s, char *accept)
{
	unsigned int i, j, l1, l2;

	l1 = _strlen(s);
	l2 = _strlen(accept);
	for (i = 0; i < l1; i++)
	{
		for (j = 0; j < l2; j++)
		{
			if (s[i] == accept[j])
			{
				s += i;
				return (s);
			}
		}
	}
	return ('\0');

}
