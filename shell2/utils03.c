#include "shell.h"
/**
 * _strcpy - copy the string.
 * @s1: the destination of the string.
 * @s2: the source of the string.
 * Return: the copieed string.
 */
char *_strcpy(char *s1, char *s2)
{
	int i = 0;

	if (s1 == s2 || s2 == 0)
		return (s1);
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
/**
 * _strncpy - copy a n byte from a string.
 * @s1: the input string.
 * @s2: the input string to copy from.
 * @n: number of bytes to copy.
 * Return: the copied string.
 */
char *_strncpy(char *s1, char *s2, int n)
{
	int i, j;
	char *s;

	i = 0;
	s = s1;
	while (s2[i] != '\0' && i < n - 1)
	{
		s1[i] = s2[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			s1[j] = '\0';
			j++;
		}
	}
	return (s);
}
/**
 * _strdup - duplicates a string and returns a pointer.
 * @s: the input string.
 * Return: a pointer.
 */
char *_strdup(const char *s)
{
	int i = 0, j;
	char *r;

	if (s == NULL)
		return (NULL);
	while (*s++)
		j++;
	r = malloc(sizeof(char) * (j + 1));
	if (r == NULL)
		return (NULL);
	while (i <= j)
	{
		r[i] = s[i];
		i++;
	}
	return (r);
}
/**
 **_strchr - locates a char in the input string.
 *@s: the input string.
 *@c: the char to be located.
 *Return: pointer to the location(adress).
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
