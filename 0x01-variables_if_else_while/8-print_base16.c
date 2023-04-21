#include <stdio.h>

/**
 *main - prints hexadecimal
 *Return: 0
 */

int main(void)
{
	int n = '0';
	int l = 'a';

	while (n <= '9')
	{
		putchar(n);
		n++;
	}

	while (l <= 'f')
	{
		putchar(l);
		l++;
	}

	putchar('\n');

	return (0);
}
