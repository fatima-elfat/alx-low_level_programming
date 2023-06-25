#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts -  prints a string, followed by a new line.
 * @s: string to write
 */
void _puts(char *s)
{
	if (*s == '\0')
		_putchar('\n');
	else
	{
		_putchar(*s);
		s++;
		_puts(s);
	}
}
/**
 * _strcat - concatenates two strings
 * @dest: input string t append to
 * @src: input string to be appended
 * Return: resulting string
 */
char *_strcat(char *dest, char *src)
{
	int i, l1, l2;

	l1 = _strlen(dest);
	l2 = _strlen(src);

	for (i = 0; i < l2 ; i++)
		dest[l1 + i] += src[i];
	dest[l1 + i] = '\0';
	return (dest);
}
/**
 * _strcmp - compare two string
 * @s1: first string
 * @s2: second string
 * Return: 0: equal, negative: s1 smaller than s2, positive: bigger
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
