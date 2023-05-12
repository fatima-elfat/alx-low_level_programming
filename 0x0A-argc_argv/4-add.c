#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry function prints the addition of positive numbers.
 * @argc: nummber of command line.
 * @argv: array of command line.
 * Return: 0 for success and 1 for error.
 */
int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		int i, a, s = 0;

		for (i = 1; i < argc; i++)
		{
			a = atoi(argv[i]);
			if (a <= 0)
			{
				printf("Error\n");
				return (1);
			}
			else
				s += a;
		}
		printf("%d\n", s);
		return (0);
	}
	else
	{
		printf("0\n");
		return (0);
	}
}
