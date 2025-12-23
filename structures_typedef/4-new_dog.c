#include <stdlib.h>
#include "dog.h"
/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *d;
int i, name_len = 0, owner_len = 0;
if (name == NULL || owner == NULL)
return (NULL);
d = malloc(sizeof(dog_t));
if (d == NULL)
return (NULL);
while (name[name_len])
name_len++;
while (owner[owner_len])
owner_len++;
d->name = malloc(sizeof(char) * (name_len + 1));
if (d->name == NULL)
{
free(d);
return (NULL);
}
d->owner = malloc(sizeof(char) * (owner_len + 1));
if (d->owner == NULL)
{
free(d->name);
free(d);
return (NULL);
}
for (i = 0; i <= name_len; i++)
d->name[i] = name[i];
for (i = 0; i <= owner_len; i++)
d->owner[i] = owner[i];
d->age = age;
return (d);
}
