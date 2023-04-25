#include <stdio.h>
/**
  * main - computes and prints the sum of multiples of 3 or 5 below 1024.
  * Return:void
  */

int main(void)
{
	int i, s;

	for (i = 0; i < 1024; i++)
		if (i % 3 == 0 || i % 5 == 0)
			s += i;
	printf("%d\n", s);
	return (0);
}
