#include <stdio.h>

/**
 * main - print a num pair from 00-99
 *
 * Return: 0
 */

int main(void)
{
	int a;
	int b;
	int aa;
	int bb;

for (a = 0 ; a < 10 ; a++)
{
	b = 0;

	for (; b <= 10 ; b++)
	{
		aa = 0;

		for (; aa < 10 ; aa++)
		{
			bb = 0;

			for (; bb < 10 ; bb++)
			{
				putchar('0' + a);
				putchar('0' + b);
				putchar(' ');
				putchar('0' + aa);
				putchar('0' + bb);
				putchar(',');
				putchar(' ');
			}bb = aa + 1;

		}aa = b + 1;

	}b = a + 1;

}
	putchar('\n');
	return (0);
}
