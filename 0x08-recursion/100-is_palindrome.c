#include "main.h"
/**
 * len_string - returns length of string.
 * @s: string
 * Return: length
 */
int len_string(char *s)
{
	if (*s == '\0')
		return (0);
	s++;
	return (1 + len_string(s));
}
/**
 * _compare - returns if the string is an palindrome.
 * @s: string
 * @l: length of string
 * Return: 1 is polandrome 0 if not
 */
int _compare(char *s, int l)
{
	if ((l == 0) || (l == 1))
		return (1);
	if (*s == *(s + l - 1) && *s != '\0')
		return (_compare(s + 1, (l - 2)));
	else if (*s == '\0')
		return (1);
	else
		return (0);
}
/**
 * is_palindrome - returns if the string is an palindrome.
 * @s: string
 * Return: 1 is polandrome 0 if not
 */
int is_palindrome(char *s)
{
	int l;

	l =  len_string(s);
	return (_compare(s, l));
}
