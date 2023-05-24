#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point.
 * @argc: size of array.
 * @argv: arry of arguments.
 * Return: on success 0.
 */
int main(int argc, char *argv[])
{
	char *a = (char *) main;
	int i, n;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	n = atoi(argv[1]);
	if (n < 0)
	{
		printf("Error\n");
		exit(2);
	}
	for (i = 0; i < n; i++)
	{
		printf("%02hhx", a[i]);
		if (i != nbytes - 1)
			printf(" ");
	}

	printf("\n");
	return (0);
}
