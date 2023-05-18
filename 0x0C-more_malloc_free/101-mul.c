#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * _atoi - convert string to int.
 * @s: string to convert.
 * Return: integer.
 */

int _atoi(char *s)
{
	int n;
	unsigned long int l, m, b = 0;

	l = 0;
	while (*s != '\0')
	{
		l++;
		s++;
	}
	n = 1;
	for (m = 0; m < l; m++)
	{
		if (s[m] == '-')
		{
			n *= -1;
		}
		else if (s[m] >= '0' && s[m] <= '9')
		{
			if (b != 0)
			{
				b *= 10;
			}
			b += s[m] - '0';
		}
		else if (b != 0)
		{
			break;
		}
	}
	return (n * b);
}
/**
 * _putchar - writes the character c to stdout.
 * @c: The character to print.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
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
 * print - prints int.
 * @n: int.
 */
void print(unsigned long int n)
{
	unsigned long int i, a, b = 1;

	for (i = 0; (n / b) > 9; i++)
		b *= 10;
	for (; b >= 1; n %= b)
	{
		a = n / b;
		_putchar('0' + a);
		b /= 10;
	}
}
/**
 * main - Entry point that multiplies two positive numbers.
 * @argc: number of arguments.
 * @argv: arguments.
 * Return: 0 - success.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		_puts("Error");
		exit(98);
	}
	print(_atoi(argv[1]) * _atoi(argv[2]));
	_putchar('\n');
	return (0);
}
