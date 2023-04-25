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

	for (i = 0; i<l_max; i++)
	{
	       _putchar(l[i]);
	}
	_putchar('\n');
	return (0);
}
