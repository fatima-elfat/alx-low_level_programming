#include "main.h"
#include <stdio.h>

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
		printf("%d\n", (argv[1] * argv[2]));
		return (0);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
}
