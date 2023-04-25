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

	for(i = 0; i < (int)strlen(l); i++)
	{
	       _putchar(l[i]);
	}
	_putchar('\n');
	return (0);
}		
