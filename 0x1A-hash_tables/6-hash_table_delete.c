#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_delete - deletes a hash table.
 * @ht: the hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node, *next;
	unsigned long int a;

	if (!ht)
		return;
	for (a = 0; a < ht->size; a++)
		for (node = ht->array[a]; node; node = next)
		{
			next = node->next;
			free(node->key);
			free(node->value);
			free(node);
		}
	free(ht->array);
	free(ht);
}
