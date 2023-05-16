#include "main.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * strtow - splits a string into words.
 * @str: string.
 * Return: splited string into array of words.
 */
char **strtow(char *str)
{
	int i, j = 0, w = 0, b, c, *t;
	char **p, pc = ' ';

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' && pc != ' ')
			w++;
		pc = str[i]; }
	t = malloc(sizeof(int) * w * 2);
	if (t == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			if (pc != ' ')
			{
				t[j] = i - 1;
				j++; }}
		else if ((str[i] != '\0' || str[i] != ' ') && pc == ' ')
		{
			t[j] = i;
			j++; }
		pc = str[i]; }
	p = malloc(sizeof(char) * (j / 2));
	if (p == NULL)
		return (NULL);
	for (i = 0; i < ((w * 2) - 1); i += 2)
	{
		b = t[i + 1];
		c = (i + 2) / 2;
		p[c - 1] = malloc(sizeof(char) * (b - t[i] + 2));
		if (p[c - 1] == NULL)
			return (NULL);
		for (j = t[i]; j <= b; j++)
			p[c - 1][j - t[i]] = str[j]; }
	return (p); }
