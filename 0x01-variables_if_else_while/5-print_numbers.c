#include <stdio.h>

/**
 *main - Write 0-9
 *Return: Return 0
 */

int main(void)
{
	int n = 0;

	while (n < 10)
	{
		printf("%i", n);
		n++;
	}
	putchar('\n');

	return (0);
}
