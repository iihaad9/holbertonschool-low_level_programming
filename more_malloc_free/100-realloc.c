#include <stdlib.h>
/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to previously allocated memory
 * @old_size: size of ptr in bytes
 * @new_size: new size in bytes
 *
 * Return: pointer to new memory block, or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
unsigned int i, min_size;
char *new_ptr, *old_ptr;
if (new_size == old_size)
return (ptr);
if (ptr == NULL)
return (malloc(new_size));
if (new_size == 0)
{
free(ptr);
return (NULL);
}
new_ptr = malloc(new_size);
if (new_ptr == NULL)
return (NULL);
old_ptr = ptr;
min_size = (new_size < old_size) ? new_size : old_size;
for (i = 0; i < min_size; i++)
new_ptr[i] = old_ptr[i];
free(ptr);
return (new_ptr);
}
