#include <stdio.h>
/**
  * main - sum even fibonacci
  * Return: Nothing.
  */
int main(void)
{
	long int a, b, c, d, s;

	a = 1;
	b = 2;
	s = 2;
	for (c = 2; c < 50; c++)
	{
		d = a + b;
		a = b;
		b = d;
		if (b % 2 == 0 && b <= 4000000)
			s = s + b;

	}
	printf("%ld\n", s);
	return (0);
}
