#include "3-calc.h"

/**
 * op_add - adds two numbers.
 * @a: the first number.
 * @b: the second number.
 * Return: the result of the addition.
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subctracts two numbers.
 * @a: the first number.
 * @b: the second number.
 * Return: the result of the substaction.
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiplies two numbers.
 * @a: the first number.
 * @b: the second number.
 * Return: the result of the multiplication.
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divides two numbers.
 * @a: the first number.
 * @b: the second number.
 * Return: the result of the division.
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - calculates the module of two numbers.
 * @a: the first number.
 * @b: the second number.
 * Return: the remaing result of the division.
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
