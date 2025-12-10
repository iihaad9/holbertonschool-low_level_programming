#include <stdlib.h>
/**
 * array_range - creates an array of integers from min to max
 * @min: starting integer
 * @max: ending integer
 *
 * Return: pointer to the array, or NULL if min > max or malloc fails
 */
int *array_range(int min, int max)
{
int *arr;
int i, len;
if (min > max)
return (NULL);
len = max - min + 1;
arr = malloc(sizeof(int) * len);
if (arr == NULL)
return (NULL);
for (i = 0; i < len; i++)
arr[i] = min + i;
return (arr);
}
