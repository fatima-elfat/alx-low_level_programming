#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/**
 * _isdigit - Define if a string is a number.
 * @n: string.
 * Return: success (0).
 **/
int _isdigit(char n)
{
	if (n < 48 || n > 57)
		return (1);
	return (0);
}
/**
 * _puts -  prints a string, followed by a new line.
 * @s: string to write.
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
 * _strlen_isnum - returns the length of a string.
 * @s: input string
 * Return: length
 */
int _strlen_isnum(char *s)
{
	if (*s == '\0' || *s == '\n' || *s == 0)
		return (0);
	else if (_isdigit(*s) != 0)
	{
		_puts("Error\n");
		exit(98);
	}
	s++;
	return (1 + _strlen_isnum(s));
}
/**
 * cal_mul - calcule a multiplication of two int as string.
 * @s1: input int in array of char.
 * @s2: second number as char.
 * @p: pointer to previous mul.
 * @l: length of s1.
 * @pos: position of s2 in the second number.
 * @lp: lenght of p.
 * Return: pointer to result in string array.
*/
void *cal_mul(char *s1, char s2, char *p, int l, int pos, int lp)
{
	int i, a = 0, sr;
	unsigned long int r = 0, pos2 = 1;

	for (i = l - 1; i >= 0; i--)
	{
		r += (s1[i] - '0') * (s2 - '0') * pos2;
		pos2 *= 10;
	}
	for (i = 1; i <= pos; i++)
	{
		r *= 10;
	}
	while (r != 0)
	{
		lp--;
		sr = r % 10;
		a = (p[lp] - '0') + sr;
		if (a > 10)
		{
			p[lp] = a % 10 + '0';
			r = ((r - sr) / 10) + ((a - (a % 10)) / 10);
		}
		else
		{
			p[lp] = a + '0';
			r = (r - sr) / 10;
		}
	}
	return (p);
}

/**
 * main - Entry point that multiplies two positive numbers.
 * @argc: number of arguments.
 * @argv: arguments.
 * Return: 0 - success.
 */
int main(int argc, char *argv[])
{
	int i, l, l1, l2, pos, t = -1;
	char *p;

	if (argc != 3)
	{
		_puts("Error");
		exit(98);
	}
	l1 = _strlen_isnum(argv[1]);
	l2 = _strlen_isnum(argv[2]);
	l = l1 + l2;
	p = malloc(l + 1);
	if (p == NULL)
	{
		_puts("Error");
		exit(98);
	}
	for (i = 0; i < l; i++)
		p[i] = '0';
	p[i] = '\0';
	pos = 0;
	for (i = l2 - 1; i >= 0; i--)
	{
		p = cal_mul(argv[1], argv[2][i], p, l1, pos, l);
		pos++;
	}
	for (i = 0; i < l; i++)
	{
		if (p[i] != '0')
			t = 0;
		if (t == 0)
			_putchar(p[i]);
	}
	_putchar('\n');
	return (0);
}
