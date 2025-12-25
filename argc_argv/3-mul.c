#include <stdio.h>
#include <stdlib.h>
/**
 * main - multiplies two numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 if success, 1 if error
 */
int main(int argc, char *argv[])
{
int n1, n2, result;
if (argc != 3)
{
printf("Error\n");
return (1);
}
n1 = atoi(argv[1]);
n2 = atoi(argv[2]);
result=n1*n2;
printf("%d\n", result);
return (0);
}
