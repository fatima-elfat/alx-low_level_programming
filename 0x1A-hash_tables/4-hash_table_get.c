#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: the hash table you want to look into.
 * @key: the key you are looking for.
 * Return: the value associated with the element,
 * or NULL if key couldn’t be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int a;

	if (!ht || !key || !ht->size || !*key)
		return (NULL);
	a = key_index((const unsigned char *)key, ht->size);
	node = (ht->array)[a];
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->next;
	if (!node)
		return (NULL);
	else
		return (node->value);
}