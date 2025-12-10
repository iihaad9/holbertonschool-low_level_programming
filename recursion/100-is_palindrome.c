#include "main.h"
/**
 * _strlen_recursion - returns the length of a string
 * @s: string
 *
 * Return: length
 */
int _strlen_recursion(char *s)
{
if (*s == '\0')
return (0);
return (1 + _strlen_recursion(s + 1));
}
/**
 * check_palindrome - checks if string is palindrome
 * @s: string
 * @i: start index
 * @j: end index
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int check_palindrome(char *s, int i, int j)
{
if (i >= j)
return (1);
if (s[i] != s[j])
return (0);
return (check_palindrome(s, i + 1, j - 1));
}
/**
 * is_palindrome - determines if a string is a palindrome
 * @s: string to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
if (*s == '\0')
return (1);
return (check_palindrome(s, 0, _strlen_recursion(s) - 1));
}

