#include "main.h"
/**
 * _isalpha - check if the letter is lowercase or uppercase
 * @c: character to test
 * Return: 1 if lower 0 if not
 */
int _isalpha(int c)
{
	if (c >= 'A' && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
