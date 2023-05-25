#include "variadic_functions.h"

/**
  * print_numbers - prints numbers, followed by a new line.
  * @separator: string to be printed between numbers.
  * @n: number of integers given to the function.
  */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list l;
	unsigned int i;

	if (n > 0)
	{
		va_start(l, n);
		for (i = 0; i < n; i++)
		{
			printf("%d", va_arg(l, int));
			if (i != n - 1  && separator != NULL)
				printf("%s", separator);
		}
		va_end(l);
	}
	printf("\n");
}
