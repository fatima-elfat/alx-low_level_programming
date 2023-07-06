#include "main.h"
/**
 * get_endianness - checks the endianness.
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	int n, r;
	char *c;

	/**
	 * the value of n = 1 if big endian
	 * |00000000|00000000|00000000|00000001
	 * so the c will take the first 8 bits which have value of 0
	 */
	n = 1;
	c = (char *)&n;
	r = *c + '0';
	return (r);
}
