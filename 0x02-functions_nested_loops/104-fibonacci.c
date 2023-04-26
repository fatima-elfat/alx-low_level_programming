#include <stdio.h>
/**
  * main - print the first 98 fibonacci numbers
  * Return: 0
  */
int main(void)
{
	long int i, j, k, l, a, b, c, d;

	i = 1;
	j = 2;
	printf("%ld, %ld, ", i, j);
	for (k = 3; k <= 90; k++)
	{
		l = i + j;
		i = j;
		j = l;
		printf("%ld", j);
		printf(", ");
	}
	a = i % 100000;
	i = (i - a) / 100000;
	b = j % 100000;
	j = (j - b) / 100000;
	for (k = 91; k <= 98; k++)
	{
		c = a + b;
		l = i + j;
		if (c > 99999)
		{
			d = c % 1000000;
			l = l + ((c - d) / 1000000);
			c = d;
		}
		a = b;
		i = j;
		b = c;
		j = l;
		printf("%ld%ld", j, b);
		if (k == 98)
			putchar('\n');
		else
			printf(", ");
	}
	return (0);
}
