#include "hash_tables.h"
/**
 * hash_table_set - adds or updates an element in the hash table
 * @ht: hash table
 * @key: key (cannot be empty)
 * @value: value associated with key
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
hash_node_t *node;
unsigned long int index;
char *value_copy;
if (!ht || !key || *key == '\0' || !value)
return (0);
value_copy = strdup(value);
if (!value_copy)
return (0);
index = key_index((const unsigned char *)key, ht->size);
node = ht->array[index];
while (node)
{
if (strcmp(node->key, key) == 0)
{
free(node->value);
node->value = value_copy;
return (1);
}
node = node->next;
}
node = malloc(sizeof(hash_node_t));
if (!node)
{
free(value_copy);
return (0);
}
node->key = strdup(key);
if (!node->key)
{
free(value_copy);
free(node);
return (0);
}
node->value = value_copy;
node->next = ht->array[index];
ht->array[index] = node;
return (1);
}
