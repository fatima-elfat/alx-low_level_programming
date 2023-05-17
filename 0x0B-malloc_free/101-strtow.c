#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * wordcount - calculate number of words in a string.
 * @str: string.
 * Return: number of words.
 */
int wordcount(char *str)
{
	int i, w = 0;
	char pc = ' ';

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			if (pc != ' ')
			{
				w++;
			}
		}
		pc = str[i];
	}
	return (w);
}
/**
 * worbe - list of word begining and ends of words in a string.
 * @str: string.
 * @w: number of string.
 * Return: list of begin and ends.
 */
int *worbe(char *str, int w)
{
	int i, j = 0, *t;
	char pc = ' ';

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
				j++;
			}
		}
		else if ((str[i] != '\0' || str[i] != ' ') && pc == ' ')
		{
			t[j] = i;
			j++;
		}
		pc = str[i];
	}
	return (t);
}
/**
 * strtow - splits a string into words.
 * @str: string.
 * Return: splited string into array of words.
 */
char **strtow(char *str)
{
	int i, j, w, a, b, c, d, *t;
	char **p;

	if (str == NULL)
		return (NULL);
	w = wordcount(str);
	if (w == 0)
	{
		p = malloc(1);
		if (p == NULL)
			return (NULL);
		p[0] = malloc(1);
		if (p[0] == NULL)
		{
			free(p);
			return (NULL); }
		p[0][0] = '\0';
		for (i = 0; p[i] != NULL; ++i)
		{
			p[i][0] = '\0'; }
		return (p); }
	t = worbe(str, w);
	j = w * 2;
	p = malloc(sizeof(char) * (j / 2));
	if (p == NULL)
		return (NULL);
	d = (w * 2) - 1;
	for (i = 0; i < d; i += 2)
	{
		a = t[i];
		b = t[i + 1];
		c = (i + 2) / 2;
		p[c - 1] = malloc(sizeof(char) * (b - a + 2));
		if (p[c - 1] == NULL)
			return (NULL);
		for (j = a; j <= b; j++)
		{
			p[c - 1][j - a] = str[j]; }
		p[c - 1][j - a] = '\0'; }
	free(t);
	return (p); }
