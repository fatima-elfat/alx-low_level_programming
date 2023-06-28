#include "shell.h"


/**
 * _putechar - writes error chzar.
 * @c: The char.
 * Return: 1 on success.
 */
int _putechar(char c)
{
	static char buffer[BUFFER_SIZE_W];
	static int i;

	if (i >= BUFFER_SIZE_W || c ==  -1)
	{
		write(2, buffer, i);
		i = 0;
	}
	if (c != -1)
		buffer[i++] = c;
	return (1);
}
/**
 *_eputs - puts the string of error.
 * @s: the string.
 */
void _putse(char *s)
{
	int i = 0;

	if (s == 0)
		return;
	while (s[i] != '\0')
	{
		_putechar(s[i]);
		i++;
	}
}

/**
 * _printe - prints an error message
 * @ar: the struct of args of the shell.
 * @s: the string of error.
 */
void _printe(l_ar *ar, char *s)
{
	_putse(ar->fname);
	_putechar(':');
	_putechar(' ');
	_printd(ar->iline, STDERR_FILENO);
	_putechar(':');
	_putechar(' ');
	_putse(ar->argv[0]);
	_putechar(':');
	_putechar(' ');
	_putse(s);
}
/**
 * _atoie - converts a string of error to int
 * @s: the input string.
 * Return: ...
 */
int _atoie(char *s)
{
	int i = 0;
	unsigned long int r = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			r *= 10;
			r += (s[i] - '0');
			if (r > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (r);
}