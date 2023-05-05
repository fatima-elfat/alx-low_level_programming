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
 * infinite_add - add two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store the result
 * @size_r: buffer size
 * Return: a pointer to the result or 0
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, l1, l2, l, a, b, c = 0;

	l1 = _strlen(n1);
	l2 = _strlen(n2);

	if (l1 > l2)
		l = l1;
	else
		l = l2;
	if (size_r < l + 1)
		return (0);

	r[l] = '\0';
	for (i = l - 1; i >= 0; i--)
	{
		l1--;
		l2--;
		if (l1 >= 0)
			a = n1[l1] - '0';
		else
			a = 0;
		if (l2 >= 0)
			b = n2[l2] - '0';
		else
			b = 0;
		r[i] = (a + b + c) % 10 + '0';
		c = (a + b + c) / 10;
	}
	if (c == 1)
	{
		r[l + 1] = '\0';
		if (l + 2 > size_r)
			return (0);
		while (l-- >= 0)
			r[l + 1] = r[l];
		r[0] = c + '0';
	}
	return (r);
}
