#include <stdio.h>
/**
  * main - print the first 98 fibonacci numbers
  * Return: 0
  */
int main(void)
{
	long int i, j, k, l;

	i = 1;
	j = 2;
	printf("%ld, %ld, ", i, j);
	for (k = 3; k <= 98; k++)
	{
		l = i + j;
		i = j;
		j = l;
		printf("%ld", j);
		if (k == 98)
			putchar('\n');
		else
			printf(", ");
	}
	return (0);
}
