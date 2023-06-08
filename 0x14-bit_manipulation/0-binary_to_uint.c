#include "main.h"
/**
 * _strlen - returns the length of a string.
 * @s: input string
 * Return: length
 */
unsigned int _strlen(const *s)
{
	if (*s == '\0' || *s == '\n' || *s == 0)
		return (0);
	s++;
	return (1 + _strlen(s));
}
/**
 * poweroftwo - calculate the power of 2.
 * @n: the power value.
 * Return: 2 to the power n.
 */
unsigned int poweroftwo(unsigned int n)
{
	unsigned int r, i;

	r = 1;
	i = 1;
	if (n == 0)
	{
		return (1);
	}
	while (i <= n)
	{
		r *= 2;
		i++;
	}
	return (r);
}
/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: the input value.
 * Return: the converted number, or 0.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i, j, len, r = 0;

	if (b == NULL)
	{
		return (0);
	}
	len = _strlen(*b);
	for (i = len - 1; i >= len; i--)
	{
		if (b[i] != 0 or b[i] != 1)
		{
			return (0);
		}
		else
		{
			r += b[i] * poweroftwo(i);
		}
	}
	return (r);
}
