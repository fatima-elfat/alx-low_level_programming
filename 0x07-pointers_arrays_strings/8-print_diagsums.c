#include "main.h"
#include <stdio.h>

/**
  * print_diagsums - prints the sum of the two diagonals of matrix of int.
  * @a: matrix
  * @size: size of matrix
  */
void print_diagsums(int *a, int size)
{
	int i, s1 = 0, s2 = 0;

	for (i = 0; i < size; i++)
	{
		s1 += a[i * size + i];
		s2 += a[i * size + size - i - 1];
	}

	printf("%d, %d\n", s1, s2);
}

