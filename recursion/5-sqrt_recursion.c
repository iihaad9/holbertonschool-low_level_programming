#include "main.h"
/**
 * find_sqrt - helper function to find natural square root
 * @n: number to find sqrt of
 * @i: current number to test
 *
 * Return: sqrt or -1
 */
int find_sqrt(int n, int i)
{
if (i * i > n)
return (-1);
if (i * i == n)
return (i);
return (find_sqrt(n, i + 1));
}
/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to compute sqrt of
 *
 * Return: sqrt or -1
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
return (find_sqrt(n, 0));
}
