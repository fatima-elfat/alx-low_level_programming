#include "variadic_functions.h"
/**
 * print_c - prints format c : char.
 * @l: input.
 * @s: seperator value.
 */
void print_c(va_list l, char *s)
{
	printf("%s%c", sep, va_arg(l, int));
}
/**
 * print_i - prints format i : integer.
 * @l: input.
 * @s: seperator value.
 */
void print_i(va_list l, char *s)
{
	printf("%s%d", s, va_arg(l, int));
}
/**
 * print_f - prints format f : float.
 * @l: input.
 * @s: seperator value.
 */
void print_f(va_list l, char *s)
{
	printf("%s%f", s, va_arg(l, double));
}
/**
 * print_s - prints format s : char*.
 * @l: input.
 * @s: seperator value.
 */
void print_s(va_list l, char *s)
{
	char *a;

	a = va_arg(l, char *);
	if (a == NULL)
		a = "(nil)";
	printf("%s%s", s, a);
}
/**
  * print_all - prints anything.
  * @format: a list of types of arguments passed to the function.
  */
void print_all(const char * const format, ...)
{
	unsigned int i = 0, j;
	char *s = "";
	va_list l;
	f_t  a[] = {
		{"c", print_c},
		{"i", print_i},
		{"f", print_f},
		{"s", print_s},
		{NULL, NULL}
	}
	va_start(l, format);
	while (format != NULL && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == a[j]->f_c)
			{
				a[j].f(l, s);
				s = ", ";
			}
			j++;
		}
		i++;
	}
	va_end(l);
	printf("\n");
}
