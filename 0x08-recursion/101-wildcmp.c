#include "main.h"
/**
 * wildcmp - compares strings and returns 1 when identical, otherwise return 0.
 * @s1: first string
 * @s2: second string
 * Return: 1 for true 0 for false
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && (*s2 == '\0' || *s2 == 42))
		return (1);
	else if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	else if (*s2 == 42)
	{
		if (*s1 != *(s2 + 1))
			return (wildcmp(s1 + 1, s2));
		else
			return (wildcmp(s1 + 1, s2 + 2));
	}
	else
		return (0);
}
