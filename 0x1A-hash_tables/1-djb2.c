#include "hash_tables.h"

/**
 * hash_djb2 - implementing the djb2 algorithm.
 * @str: string used to generate hash value.
 * Return: key
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	int c;
	unsigned long hash = 5381;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return (hash);
}
