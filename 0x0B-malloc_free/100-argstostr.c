#include "main.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * argstostr -  concatenates all the arguments of your program.
 * @ac: size of array.
 * @av: array.
 * Return: string.
 */
char *argstostr(int ac, char **av)
{
	int i, j, k = 0, a = 0, b = 0;
	char *p;

	if (ac == 0 || av == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		if (av[i] == NULL)
			return (NULL);
		for (j = 0; av[i][j] != '\0'; j++)
			k++;
		k++;
	}
	p = malloc(sizeof(char) * k);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < k; i++)
	{
		p[i] = av[a][b];
		if (av[a][b] == '\0')
		{
			a++;
			b = 0;
		}
		else
			b++;
	}
	return (p);
}
