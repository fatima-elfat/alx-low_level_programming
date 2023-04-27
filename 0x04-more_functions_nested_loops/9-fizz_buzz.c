#include <stdio.h>

/**
 * main - print 1 to 100
 * Return: 0
 */
int main(void)
{
	int i;

	printf("1");
	for (i = 2; i < 101; i++)
	{
		if (i % 3 == 0)
			printf(" Fizz");
		else if (i % 5 == 0)
			printf(" Buzz");
		else if (i % 3 == 0 && i % 5 == 0)
			printf(" FizzBuzz");
		else
			printf(" %d", i);
	}
	printf("\n");
	return (0);
}
