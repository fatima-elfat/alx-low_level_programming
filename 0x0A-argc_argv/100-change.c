#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * change_m - change money using coins
 * @m: input value of money.
 * @r: change.
 * @p: list of acceptable coins.
 */
void change_m(int m, int r, int *p)
{
	int temp;

	if (m >= *p)
	{
		if (m % *p == 0)
		{
			r += m / *p;
			printf("%d\n", r);
		}
		else
		{
			temp = m % *p;
			r += (m - temp) / *p;
			p++;
			change_m(temp, r, p);
		}
	}
	else
	{
		p++;
		change_m(m, r, p);
	}
}
/**
 * main - entry function prints the minimum number of coins to make change for
 * an amount of money.We can use an unlimited number of coins of values 25, 10
 * , 5, 2, and 1 cent.
 * @argc: nummber of command line.
 * @argv: array of command line.
 * Return: 0 for success and 1 for error.
 */
int main(int argc, char *argv[])
{
	int c[5] = {25, 10, 5, 2, 1};
	int *p = c;

	if (argc == 2)
	{
		int a;

		a = atoi(argv[1]);
		if (a <= 0)
		{
			printf("0\n");
			return (0);
		}
		change_m(a, 0, p);
		return (0);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
}
