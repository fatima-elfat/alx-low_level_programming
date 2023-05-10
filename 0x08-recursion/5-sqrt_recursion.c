#include "main.h"
/**
 * _sqrt_recursion -  returns the natural square root of a number.
 * @n: input number
 * Return: sqrt of n
 */
int _sqrt_recursion(int n)
{
	return (_sqrt(n, 1));
}
/**
 * _sqrt - returns sqrt.
 * @n: input numbers
 * @i: starting value
 * Return: sqrt
 */
int _sqrt(int n, int i)
{
	if (n == 0 || n == 1)
		return (n);
	else if (i * i < n)
		return (_sqrt(n, i + 1));
	else if  (i * i == n)
		return (i);
	else
		return (-1);
}
