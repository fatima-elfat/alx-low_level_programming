#include "main.h"

/**
 *print_alphabet(): Print lowercase alphabet
 *Return: Void
 */
void print_alphabet(void)
{
	char c;

	for ( c = 'a'; c <= 'z';  c++)
	{
		_putchar(c);
	}
	_putchar('\n');
}	
