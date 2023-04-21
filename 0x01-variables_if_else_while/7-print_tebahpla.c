#include <stdio.h>

/**
 *main - print alphabet reversed using 2 putchar
 *Return: 0 
 */

int main(void)
{
	char alpha = 'z';

	while (alpha >= 'a')
	{
		putchar(alpha);
		alpha--;
	}
	putchar('\n');

	return (0);
}
