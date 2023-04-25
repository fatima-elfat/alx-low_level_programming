#include <stdio.h>
#include <string.h>
#include <main.h>
/**
 * main - print "_putchar"
 * Return: 0
 */
int main(void)
{
	char l[] = "_putchar";

	for(i=0; i<strlen(l); i++)
	{
	       _putchar(l[i]);
	}
	_putchar("\n");
	return (0);
}		
