#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table.
 * @ht: the hash table you want to add or update the key/value.
 * @key: the key. key can not be an empty string.
 * @value: the value associated with the key.
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node = NULL, *newN = NULL;
	unsigned long int idx;
	char *s;

	if (!ht || !(ht->array) || !key || !strlen(key) || !value)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	node = (ht->array)[idx];
	while (node && (strcmp(key, node->key) != 0))
		node = node->next;
	if (node)
	{
		s = strdup(value);
		if (!s)
			return (0);
		free(node->value);
		node->value = s;
	}
	else
	{
		newN->key = malloc(sizeof(hash_node_t));
		if (!newN->key)
			return (0);
		newN->key = strdup(key);
		if (!newN->key)
		{
			free(newN);
			return (0);
		}
		newN->value = strdup(value);
		if (!newN->value)
		{
			free(newN->key);
			free(newN);
			return (0);
		}
		newN->next = (ht->array)[idx];
		(ht->array)[idx] = newN;
	}
	return (1); }