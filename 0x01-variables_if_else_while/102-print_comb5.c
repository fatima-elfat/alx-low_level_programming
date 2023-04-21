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
	for (b = 0 ; b <= 10 ; b++)
	{
		for (aa = 0 ; aa < 10 ; aa++)
		{
			for (bb = 0 ; bb < 10 ; bb++)
			{
				putchar(a);
				putchar(b);
				putchar(' ');
				putchar(aa);
				putchar(bb);
				if (!((a == 9 && b == 8) && (aa == 9 && bb == 8)))
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
}
	putchar('\n');
	return (0);
}
