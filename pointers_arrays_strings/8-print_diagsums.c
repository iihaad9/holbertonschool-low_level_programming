#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - prints the sums of the two diagonals of a square matrix
 * @a: pointer to the first element of the matrix (as a 1D array)
 * @size: size of the square matrix (size x size)
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
int i;
int sum1 = 0;
int sum2 = 0;
for (i = 0; i < size; i++)
{
sum1 += a[i * size + i];
sum2 += a[i * size + (size - 1 - i)];
}
printf("%d, %d\n", sum1, sum2);
}
