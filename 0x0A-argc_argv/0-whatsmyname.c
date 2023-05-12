#include "main.h"
#include <stdio.h>
/**
 * main - entry function prints its name, followed by a new line.
 * @argc: nummber of command line.
 * @argv: array of command line.
 * Return: 0 for success.
 */
int main(int argc, char *argv[])
{
	printf("%s\n", argv[argc - 1]);
	return (0);
}
