#include "main.h"

/**
 * _strlen - returns the length of a string.
 * @s: input string
 * Return: length
 */
unsigned int _strlen(const char *s)
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
	i = 2;
	if (n == 1)
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
	unsigned int i, len, r = 0, t;

	if (b == NULL)
	{
		return (0);
	}
	len = _strlen(b);
	for (i = len - 1; i == 0; i--)
	{
		t = b[i] - '0';
		printf("%i\n", t);
		
		if (t == 1)
		{
			r += t * poweroftwo(i + 1);
			/* r += t << i + 1;*/
		}
		else if ((t != 0) && (t != 1))
		{
			return (0);
		}
		
		
	}
	return (r);
}
