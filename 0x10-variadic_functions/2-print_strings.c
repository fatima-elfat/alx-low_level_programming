#include "variadic_functions.h"
/**
  * print_strings - prints strings, followed by a new line.
  * @separator:  the string to be printed between the strings.
  * @n: the number of strings passed to the function.
  * Return: string separeted by separator.
  */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *a;
	va_list l;

	if (n > 0)
	{
		va_start(l, n);
		for (i = 0; i < n; i++)
		{
			a = va_arg(l, char *);
			if (a == NULL)
				printf("%s", "(nil)");
			else
				printf("%s", a);

			if (i != n - 1 && separator != NULL)
				printf("%s", separator);
		}
		va_end(l);
	}

	printf("\n");
}
