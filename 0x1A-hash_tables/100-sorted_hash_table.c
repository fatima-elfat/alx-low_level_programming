#include "hash_tables.h"
/**
 * sortht - ...
 * @ht: the hash table ...
 * @newN: ...
 */
void sortht(shash_table_t *ht, shash_node_t *newN)
{
	shash_node_t *node;

	if (newN->sprev)
		newN->sprev->snext = newN->snext;
	if (newN->snext)
		newN->snext->sprev = newN->sprev;
	if (ht->shead)
	{
		ht->shead = ht->stail = newN;
		return;
	}
	node = ht->shead;
	if (strcmp(newN->key, node->key) < 0)
	{
		newN->snext = ht->shead;
		ht->shead = ht->shead->sprev = newN;
		return;
	}
	node = node->snext;
	while (node != NULL)
	{
		if (strcmp(newN->key, node->key) < 0)
		{
			newN->sprev = node->sprev;
			newN->snext = node;
			node->sprev = newN;
			if (newN->sprev != NULL)
				newN->sprev->snext = newN;
			return;
		}
		node = node->snext;
	}
	newN->sprev = ht->stail;
	ht->stail->snext = newN;
	ht->stail = newN;
}
/**
 * shash_table_create - create sorted hash table.
 * @size: the size.
 * Return: pointer to hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int a = 0;

	if (size == 0)
		return (NULL);
	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);
	ht->array = malloc(sizeof(shash_node_t) * size);
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}
	while (a < size)
	{
		ht->array[a] = NULL;
		a++;
	}
	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}
/**
 * shash_table_set - adds element.
 * @ht: the hash table.
 * @key: the key.
 * @value: the value.
 * Return: 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t  *node = NULL, *newN = NULL;
	unsigned long int idx;
	char *s;

	if (!ht || !(ht->array) || !key || !strlen(key) || !value)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	node = ht->array[idx];
	while (node && (strcmp(key, node->key)))
		node = node->next;
	if (node)
	{
		s = strdup(value);
		if (!s)
			return (0);
		free(node->value);
		node->value = s;
		sortht(ht, node); }
	else
	{
		newN = malloc(sizeof(shash_node_t));
		if (!newN)
			return (0);
		newN->key = strdup(key);
		if (!newN->key)
		{
			free(newN);
			return (0); }
		newN->value = strdup(value);
		if (!newN->value)
		{
			free(newN->key);
			free(newN);
			return (0); }
		newN->next = (ht->array)[idx];
		(ht->array)[idx] = newN;
		newN->sprev = NULL;
		newN->snext = NULL;
		sortht(ht, newN);
	}
	return (1); }

/**
 * shash_table_get - get shash table.
 * @ht: the hash table.
 * @key: the key.
 * Return: ...
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int idx;

	if (!ht || !key)
		return (NULL);
	idx = key_index((const unsigned char *) key, ht->size);
	node = ht->array[idx];
	while (node)
		if (strcmp(node->key, key) == 0)
			return (strdup(node->value));
	return (NULL);
}
/**
 * shash_table_print - print shash tavle.
 * @ht: the shash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	char *s = "";

	if (!ht || !ht->array)
		return;
	printf("{");
	node = ht->shead;
	while (node)
	{
		printf("%s'%s': '%s'", s, node->key, node->value);
		s = ", ";
		node = node->snext;
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - prints shash table in the reverse order.
 * @ht: the hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	char *s = "";

	if (!ht || !ht->array)
		return;
	printf("{");
	node = ht->stail;
	while (node)
	{
		printf("%s'%s': '%s'", s, node->key, node->value);
		s = ", ";
		/** reverse*/
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes the hash table.
 * @ht: the shash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *next;

	if (!ht)
		return;
	node = ht->shead;
	while (node)
	{
		next = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = next;
	}
	free(ht->array);
	free(ht);
}
