#ifndef LISTS_H
#define LISTS_H
#include <stddef.h>
/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 */
typedef struct dlistint_s
{
int n;
struct dlistint_s *prev;
struct dlistint_s *next;
} dlistint_t;
/**
 * dlistint_len - returns the number of elements in a dlistint_t list
 * @h: pointer to the head of the list
 *
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h);
/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: pointer to the head of the list
 * @n: integer to store in the new node
 *
 * Return: address of the new node, or NULL if it fails
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
#endif
