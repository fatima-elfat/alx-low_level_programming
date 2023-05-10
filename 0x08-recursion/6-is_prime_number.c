#include "main.h"
/**
 * is_prime_number - returns 1 if in is a prime number, otherwise return 0.
 * @n: input number
 * Return: 1 if prime 0 if not
 */
int is_prime_number(int n)
{
	return (_prime(n, 2));
}
/**
 * _prime - returns 1 if in is a prime number, otherwise return 0.
 * @n: input number
 * @i: input devisor
 * Return: 1 if prime 0 if not
 */
int _prime(int n, int i)
{
	if (n <= 1)
		return (0);
	if ((n % i == 0) && (n != i))
		return (0);
	else if ((n % i != 0) && (i < n))
		return (_prime(n, i + 1));
	return (1);
}
