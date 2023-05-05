#include "main.h"
#include <stdio.h>

/**
 * print_buffer - Prints a buffer
 * @b: char
 * @size: int
 */
void print_buffer(char *b, int size)
{
	int i, j, k = 0, l = 0, m;

	if (size > 0)
	{
		for (i = 0; i < size; i += 10)
		{
			if (size - i < 10)
				j = size - i;
			else
				j = 10;
			printf("%08x: ", i);
			while (k < 10)
			{
				if (k < j)
					printf("%02x", *(b + start + i));
				else
					printf(" ");
				if (k % 2)
					printf(" ");
				k++;
			}
			while (l < j)
			{
				m = *(b + l + i);
				if (!(m >= 32 && m <= 126))
					m = 46;
				printf("%c", m);
				l++
			}
			printf("\n");


		}
	}
	else
		printf('\n');
}
