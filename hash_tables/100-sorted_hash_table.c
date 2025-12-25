#include "hash_tables.h"
/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 *
 * Return: pointer to the new table, or NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *ht;
unsigned long int i;
if (size == 0)
return (NULL);
ht = malloc(sizeof(shash_table_t));
if (ht == NULL)
return (NULL);
ht->size = size;
ht->shead = NULL;
ht->stail = NULL;
ht->array = malloc(sizeof(shash_node_t *) * size);
if (ht->array == NULL)
{
free(ht);
return (NULL);
}
for (i = 0; i < size; i++)
ht->array[i] = NULL;
return (ht);
}
/**
 * add_to_sorted_list - inserts node in sorted linked list
 * @ht: sorted hash table
 * @node: new node
 */
void add_to_sorted_list(shash_table_t *ht, shash_node_t *node)
{
shash_node_t *tmp;
if (ht->shead == NULL)
{
ht->shead = node;
ht->stail = node;
return;
}
tmp = ht->shead;
while (tmp && strcmp(node->key, tmp->key) > 0)
tmp = tmp->snext;
if (tmp == ht->shead)
{
node->snext = ht->shead;
ht->shead->sprev = node;
ht->shead = node;
}
else if (tmp == NULL)
{
node->sprev = ht->stail;
ht->stail->snext = node;
ht->stail = node;
}
else
{
node->snext = tmp;
node->sprev = tmp->sprev;
tmp->sprev->snext = node;
tmp->sprev = node;
}
}
/**
 * shash_table_set - adds or updates an element
 * @ht: sorted hash table
 * @key: key
 * @value: value
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
shash_node_t *node;
shash_node_t *tmp;
char *k, *v;
if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
return (0);
index = key_index((unsigned char *)key, ht->size);
tmp = ht->array[index];
while (tmp)
{
if (strcmp(tmp->key, key) == 0)
{
free(tmp->value);
tmp->value = strdup(value);
return (1);
}
tmp = tmp->next;
}
node = malloc(sizeof(shash_node_t));
if (node == NULL)
return (0);
k = strdup(key);
v = strdup(value);
if (k == NULL || v == NULL)
{
free(k);
free(v);
free(node);
return (0);
}
node->key = k;
node->value = v;
node->next = ht->array[index];
node->sprev = NULL;
node->snext = NULL;
ht->array[index] = node;
add_to_sorted_list(ht, node);
return (1);
}
/**
 * shash_table_get - retrieves a value by key
 * @ht: sorted hash table
 * @key: key
 *
 * Return: value or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
shash_node_t *node;
unsigned long int index;
if (ht == NULL || key == NULL || *key == '\0')
return (NULL);
index = key_index((unsigned char *)key, ht->size);
node = ht->array[index];
while (node)
{
if (strcmp(node->key, key) == 0)
return (node->value);
node = node->next;
}
return (NULL);
}
/**
 * shash_table_print - prints sorted hash table
 * @ht: sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *node;
int first = 1;
if (ht == NULL)
return;
printf("{");
node = ht->shead;
while (node)
{
if (!first)
printf(", ");
printf("'%s': '%s'", node->key, node->value);
first = 0;
node = node->snext;
}
printf("}\n");
}
/**
 * shash_table_print_rev - prints sorted hash table in reverse
 * @ht: sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *node;
int first = 1;
if (ht == NULL)
return;
printf("{");
node = ht->stail;
while (node)
{
if (!first)
printf(", ");
printf("'%s': '%s'", node->key, node->value);
first = 0;
node = node->sprev;
}
printf("}\n");
}
/**
 * shash_table_delete - deletes sorted hash table
 * @ht: sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
shash_node_t *node;
shash_node_t *tmp;
if (ht == NULL)
return;
node = ht->shead;
while (node)
{
tmp = node;
node = node->snext;
free(tmp->key);
free(tmp->value);
free(tmp);
}
free(ht->array);
free(ht);
}
