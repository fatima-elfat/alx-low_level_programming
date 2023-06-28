#include "shell.h"
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
 * _strcmp - compare two string
 * @s1: first string
 * @s2: second string
 * Return: 0: equal, negative: s1 smaller than s2,
 * positive: bigger
 */
int _strcmp(char *s1, char *s2)
{
	int i, a = 0, b = 0, l1, l2;

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	if (l1 < l2)
		l1 = l2;
	for (i = 0; i < l1; i++)
		if (s1[i] != s2[i])
		{
			a = s1[i];
			b = s2[i];
			break;
		}

	return (a - b);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 */
int _putchar(char c)
{
    static int i;
	static char buffer[BUFFER_SIZE_W];

	if (i >= BUFFER_SIZE_W || c == BUFFER_FLSH)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != BUFFER_FLSH)
		buffer[i++] = c;
	return (1);
}
/**
 * _putinfd - prints char in fd.
 * @c: The char to print.
 * @fd: The value of file descriptor.
 * Return: ...
 */
int _putinfd(char c, int fd)
{
	static int i;
	static char buffer[BUFFER_SIZE_W];

	if (c == BUFFER_FLSH || i >= BUFFER_SIZE_W)
	{
		write(fd, buffer, i);
		i = 0;
	}
	if (c != BUFFER_FLSH)
		buffer[i++] = c;
	return (1);
}