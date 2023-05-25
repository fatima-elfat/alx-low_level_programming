#ifndef _VARIADIC_FUNCTIONS_H
#define _VARIADIC_FUNCTIONS_H
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
void print_all(const char * const format, ...);
/**
 * struct format - Struct format of types of arguments.
 * @f_c: format of types.
 * @f: associated function.
 */
typedef struct format
{
	char *f_c;
	void (*f)(va_list l, char *s);
} f_t;
#endif
