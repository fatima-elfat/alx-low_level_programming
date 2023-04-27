#include <stdio.h>

/**
 * main - print largest prime factor of 612852475143
 * Return: 0 on success
 */

int main(void)
{
	unsigned long n = 612852475143;
	unsigned long i, j;
	for (i = n - 1; i > 1; i--)
	{
		j = n % i;
		if (j == 0)
		{
			n = i;
		}
	}
	printf("%lu\n", n);
	return (0);
}	
