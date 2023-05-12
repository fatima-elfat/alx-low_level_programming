#include "main.h"
#include <stdio.h>
/**
 * main - entry function prints the number of arguments passed into it.
 * @argc: nummber of command line.
 * @argv: array of command line.
 * Return: 0 for success.
 */
int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
