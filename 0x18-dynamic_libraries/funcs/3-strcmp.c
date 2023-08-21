#include "main.h"
/**
 * _strcmp - compare two string
 * @s1: first string
 * @s2: second string
 * Return: 0: equal, negative: s1 smaller than s2, positive: bigger
 */
int _strcmp(char *s1, char *s2)
{
	int i, a = 0, b = 0, l1, l2;

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	if (l1 < l2)
		l1 = l2;
	for (i = 0; i < l1; i++)
		if (s1[i] != s2[i])
		{
			a = s1[i];
			b = s2[i];
			break;
		}

	return (a - b);
}
