#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry function prints the multiplication of two numbers.
 * @argc: nummber of command line.
 * @argv: array of command line.
 * Return: 0 for success and 1 for error.
 */
int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int a, b;

		a = atoi(argv[1]);
		b = atoi(argv[2]);
		printf("%d\n", (a * b));
		return (0);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
}
