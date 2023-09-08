#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 * @ht: the hash table.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
	unsigned long int a = 0;
	char *s = "";

	if (!ht || !ht->array)
		return;

	printf("{");
	while (a < ht->size)
	{
		node = ((ht->array)[a]);
		while (node)
		{
			printf("%s'%s': '%s'", s, node->key, node->value);
			s = ", ";
			node = node->next;
		}
		a++;
	}
	printf("}\n");
}
