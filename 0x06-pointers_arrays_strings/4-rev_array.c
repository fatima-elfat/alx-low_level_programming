#include <unistd.h>
#include "main.h"

/**
 * reverse_array - reverse the elements of an array
 * @a: input array
 * @n: lenght of array
 */
void reverse_array(int *a, int n)
{
	int i, t, *b;

	b = a;

	for (i = 1; i < n; i++)
	{
		b++;
	}
	if (n % 2 == 0)
		n /=  2;
	else
		n = (n - 1) / 2;
	for (i = 0; i < n; i++)
	{
		t = a[i];
		a[i] = *b;
		*b = t;
		b--;
	}
}
