#include <stdlib.h>
/**
 * argstostr - concatenates all arguments of the program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to the new string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
int i, j, k = 0, len = 0;
char *str;
if (ac == 0 || av == NULL)
return (NULL);
/* Calculate total length needed */
for (i = 0; i < ac; i++)
{
j = 0;
while (av[i][j] != '\0')
{
len++;
j++;
}
len++; /* for the newline */
}
str = malloc(sizeof(char) * (len + 1)); /* +1 for '\0' */
if (str == NULL)
return (NULL);
/* Copy the arguments into the new string */
for (i = 0; i < ac; i++)
{
j = 0;
while (av[i][j] != '\0')
{
str[k++] = av[i][j++];
}
str[k++] = '\n';
}
str[k] = '\0';
return (str);
}
