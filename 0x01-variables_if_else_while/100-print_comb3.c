#include <stdio.h>

/**
 *main - print 00 to 99 with no duplicate digits
 *Return: 0
 */

int main(void)
{
	int a;
	int b;

	for (b = '0'; b <= '9'; b++)
	{
		for (a = (b + 1); a <= '9'; a++)
		{
			putchar(b);
			putchar(a);

			if (b != '8' || a != '9')
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');

	return (0);
}
