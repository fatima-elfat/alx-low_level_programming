#include "shell.h"

/**
 * _printd - prints a decimal.
 * @a: the input value.
 * @fd: the input filed escriptor.
 * Return: ...
 */
int _printd(int a, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _putechar;
	if (a < 0)
	{
		_abs_ = -a;
		__putchar('-');
		count++;
	}
	else
		_abs_ = a;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;
	return (count);
}

/**
 * _itoa - convertes int.
 * @n: the input number.
 * @b: the input base.
 * @f: the appropriate flags.
 * Return: ...
 */
char *_itoa(long int n, int b, int f)
{
	static char *t, buffer[B_VAL];
	char *p, sign = 0;
	unsigned long num = n;

	if (!(f & C_US) && n < 0)
	{
		num = -n;
		sign = '-';

	}
	if (!(f & C_LC))
		t = "0123456789ABCDEF";
	else
		t = "0123456789abcdef";
	p = &buffer[(B_VAL - 1)];
	*p = '\0';
	do	{
		*--p = t[num % b];
		num /= b;
	} while (num != 0);

	if (sign)
		*--p = sign;
	return (p);
}

/**
 * _ins - changes the command to buffer.
 * @ar: the struct of args of shell.
 * @s: the buffer (adress).
 * @len: the length.
 * Return: ...
 */
ssize_t _ins(l_ar *ar, char **s, size_t *len)
{
	size_t len_p = 0;
	ssize_t r = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		free(*s);
		*s = NULL;
		signal(SIGINT, _handlesig);
#if CUSTOM_GETLINE
        r = _getnextline(ar, s, &len_p);
#else
		r = getline(s, &len_p, stdin);
#endif
		if (r > 0)
		{
			if ((*s)[r - 1] == '\n')
			{
				(*s)[r - 1] = '\0'; 
				r--;
			}
			_delcom(*s);
			ar->iflag = 1;
			_addhist(ar, *s, ar->ihist++);
		}
	}
	return (r);
}
