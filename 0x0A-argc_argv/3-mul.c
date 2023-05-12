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
		int a, b;

		a = (int) argv[1] - '0';
		b = (int) argv[2] - '0';
		printf("%d\n", (a * b));
		return (0);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
}
