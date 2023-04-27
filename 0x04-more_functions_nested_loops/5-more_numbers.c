#include "main.h"
/**
 * more_numbers - print 0 to 14 ten times
 */

void more_numbers(void)
{
	int i, j;

	for (i = 0; i < 11; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (j / 10 > 0)
				_putchar('0' + (j / 10));
			_putchar('0' + (j % 10));
		}
	_putchar('\n');
	}
}
