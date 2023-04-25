#include "main.h"
#include <stdio.h>
/**
 * print_to_98 - list natural numbers to 98
 * @n: number from where to start
 * Return: void
 */
void print_to_98(int n)
{
	int i;

	if (n <= 98)
	{
		for (i = n; i < 98; i++)
		{
			printf("%d, ", i);
		}
		printf("98 \n");
	}
	else
	{
		for (i = n; i >= n; i--)
		{
                        printf("%d, ", i);
                }

	}
}
