#include "main.h"
/**
 * get_endianness - checks the endianness.
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	int n, r;
    char *c;

    n = 1;
    c = (char *)&n;
    r = *c + '0';
	return (r);
}