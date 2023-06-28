#include "shell.h"

/**
 * _puts -  prints a string.
 * @s: string to write
 */
void _puts(char *s)
{
	if (*s == '\0')
		_putchar('\0');
	else
	{
		_putchar(*s);
		s++;
		_puts(s);
	}
}
/**
 *_putsinfd - prints string.
 * @s: the input string.
 * @fd: the value of the file descriptor.
 * Return: the number of chars put
 */
int _putsinfd(char *s, int fd)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s)
	{
		i += _putinfd(*s++, fd);
	}
	return (i);
}
/**
 * _strcat - concatenates two strings.
 * @s1: the input string to append too.
 * @s2: the input string to be appended.
 * Return: the resulting string.
 */
char *_strcat(char *s1, char *s2)
{
	char *r;

	r = s1;
	while (*s1)
		s1++;
	while (*s2)
		*s1++ = *s2++;
	*s1 = *s2;
	return (r);
}
/**
 * _strncat - concatenate n bytes from src.
 * @s1: the input string to concatenate to.
 * @s2: the input string to tage n bytes from.
 * @n: the input int of the number of bytes to add to dest.
 * Return: the result
 */
char *_strncat(char *s1, char *s2, int n)
{
	int i, j;
	char *s;

	i = 0;
	j = 0;
	s = s2;
	while (s1[i] != '\0')
		i++;
	while (j < n && s1[j] != '\0')
	{
		s2[i] = s1[j];
		i++;
		j++;
	}
	if (j < n)
		s2[i] = '\0';
	return (s);
}
/**
 * _printa - prints an alias.
 * @l: the input linked list of aliases.
 * Return: ...
 */
int _printa(l_s *l)
{
	char *p1 = NULL, *p2 = NULL;

	if (l)
	{
		p1 = _strchr(l->s, '=');
		for (p2 = l->s; p2 <= p1; p2++)
			_putchar(*p2);
		_putchar('\'');
		_puts(p1 + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
