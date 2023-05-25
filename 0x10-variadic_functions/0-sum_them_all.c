#include "variadic_functions.h"

/**
  * sum_them_all - returns the sum of all its parameters.
  * @n: numbers of parameters inputed.
  * Return: sum of input the n arguments.
  */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i = 0;
	int r = 0;
	va_list l;

	if (n == 0)
		return (0);
	va_start(l, n);
	while (i < n)
	{
		r += va_arg(l, int);
		i++;
	}
	va_end(l);
	return (r);
}
