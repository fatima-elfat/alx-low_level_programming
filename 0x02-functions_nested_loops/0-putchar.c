#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * main - print "_putchar"
 * Return: 0
 */
int main(void)
{
	char l[] = "_putchar";
	int i;
	int l_max;

	l_max = (int)strlen(l);

	for (i = 0; i < 8; i++)
	{
		_putchar(l[i]);
	}
	_putchar('\n');
	_putchar(l_max);
	return (0);
}
