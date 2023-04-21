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

for ( a = 0 ; a < 10 ; a++)
{	

	for (b = 0 ; b <= 10 ; b++)
	{
	
		for (aa = 0 ; aa < 10 ; aa++)
		{
			for ( bb = 0 ; bb < 10 ; bb++)
			{
				putchar('0' + a);
				putchar('0' + b);
				putchar(32);
				putchar('0' + aa);
				putchar('0' + bb);
				if (!(a == 9 && b == 8))
				{
					putchar(',');
					putchar(32);
				}
				bb++;
			}
		}
	}
}
	putchar('\n');
	return (0);
}
