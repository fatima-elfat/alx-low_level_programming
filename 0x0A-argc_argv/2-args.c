#include "main.h"
#include <stdio.h>
/**
 * print - prints arrays one argument for aline.
 * @a: input array.
 * @l: length of array.
 */
void print(char *a[], int l)
{
	if (l == 1)
		printf("%s\n", a[0]);
	else
	{
		print(a, l - 1);
		printf("%s\n", a[l - 1]);
	}
}
/**
 * main - entry function prints all arguments it receives.
 * @argc: nummber of command line.
 * @argv: array of command line.
 * Return: 0 for success.
 */
int main(int argc, char *argv[])
{
	print(argv, argc);
	return (0);
}
