#include "main.h"
#include <stdio.h>
/**
 * print_array - printn element of an array of int
 * @a: input array
 * @n: input int
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", *a);
		a++;
		if (i == n-1)
			printf("\n");
		else
			printf(", ");
	}	

}
