#include "3-calc.h"
/**
 * get_op_func - selects the correct operation function
 * @s: operator passed as argument
 *
 * Return: pointer to the matching function or NULL
 */
int op_add(int a, int b)
{
return (a + b);
}
int op_sub(int a, int b)
{
return (a - b);
}
int op_mul(int a, int b)
{
return (a * b);
}
int op_div(int a, int b)
{
return (a / b);
}
int op_mod(int a, int b)
{
return (a % b);
}
