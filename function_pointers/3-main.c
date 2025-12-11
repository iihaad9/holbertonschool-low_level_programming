#include "3-calc.h"
/**
 * main - performs simple operations
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
int (*op_func)(int, int);
int a, b;
if (argc != 4)
{
printf("Error\n");
exit(98);
}
op_func = get_op_func(argv[2]);
if (op_func == NULL)
{
printf("Error\n");
exit(99);
}
a = atoi(argv[1]);
b = atoi(argv[3]);
if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
{
printf("Error\n");
exit(100);
}
printf("%d\n", op_func(a, b));
return (0);
}
