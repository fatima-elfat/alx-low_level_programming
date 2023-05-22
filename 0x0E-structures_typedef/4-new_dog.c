#include "dog.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * _strlen_recursion - returns the length of a string.
 * @s: input string
 * Return: length
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0' || *s == '\n' || *s == 0)
		return (0);
	s++;
	return (1 + _strlen_recursion(s));
}
/**
 * _strcpy - copy the string
 * @dest: destination of the string
 * @src: souece of the string
 * Return: copied string
 */
char *_strcpy(char *dest, char *src)
{
	int l, i;

	l = _strlen_recursion(src);

	for (i = 0; i <= l; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * new_dog - creates a new dog.
 * @name: the name of the dog.
 * @age: the age of the dog.
 * @owner: the owner of the dog.
 * Return: struct dog.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	if (name == NULL || age < 0 || owner == NULL)
		return (NULL);
	d = malloc(sizeof(*d));
	if (d == NULL)
		return (NULL);
	d->name = malloc(sizeof(char) * (_strlen_recursion(name) + 1));
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}
	d->owner = malloc(sizeof(char) * (_strlen_recursion(owner) + 1));
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}
	d->name = _strcpy(d->name, name);
	d->owner = _strcpy(d->owner, owner);
	d->age = age;
	return (d);
}
