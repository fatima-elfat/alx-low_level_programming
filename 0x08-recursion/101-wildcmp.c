#include "main.h"

/**
 * wildcmp - compares strings and returns 1 when identical, otherwise return 0.
 * @s1: first string
 * @s2: second string
 * Return: 1 for true 0 for false
 */
int wildcmp(char *s1, char *s2)
{
	return (cmp(s1, s2, -1));
}
/**
 * cmp - compares strings and returns 1 when identical, otherwise return 0.
 * @s1: first string
 * @s2: second string
 * @r: int to special char
 * Return: 1 for true 0 for false
 */
int cmp(char *s1, char *s2, int r)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	else if (*s1 == '\0' && *s2 == 42)
	{
		if (*(s2 + 1) != '\0')
			return (cmp(s1 - 1, s2 + 1, r));
		else
			return (1);
	}
	else if (*s1 == *s2)
	{
		if (r >= 0)
			r += 1;
		return (cmp(s1 + 1, s2 + 1, r));
	}
	else if (*s2 == 42)
	{
		if (*(s2 + 1) == 42)
		{
			r = 0;
			return (cmp(s1 + 1, s2 + 1, r));
		}
		else if (*s1 != *(s2 + 1))
		{
			if (r < 0)
				r = r + 1;
			return (cmp(s1 + 1, s2, r));
		}
		else
		{
			r = r + 3;
			return (cmp(s1 + 1, s2 + 2, r));
		}
	}
	else if (r > 0)
	{
		return (cmp(s1, s2 - r, 0));
	}
	else
		return (0);
}
