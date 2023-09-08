#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table.
 * @size: the size of the array.
 * Return:  pointer to the newly created hash table.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i = 0;
	hash_table_t *ht = NULL;
	hash_node_t **arr = NULL;

	if (!size)
		return (NULL);

	ht = malloc(sizeof(hash_table_t));
	if (!ht)
		return (NULL);
	arr = malloc(sizeof(*arr) * size);
	if (!arr)
	{
		free(ht);
		return (NULL);
	}
	while (i < size)
	{
		arr[i] = NULL;
		i++;
	}

	ht->size = size;
	ht->array = arr;

	return (ht);
}
