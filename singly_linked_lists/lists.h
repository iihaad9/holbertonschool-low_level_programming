#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct list_s - singly linked list
 * @str: string (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/* Task 0 */
size_t print_list(const list_t *h);

/* Task 1 */
size_t list_len(const list_t *h);

/* Task 2 */
list_t *add_node(list_t **head, const char *str);

/* Task 3 (إذا وصلت له) */
list_t *add_node_end(list_t **head, const char *str);

/* باقي التاسكات تضيف prototypes هنا */

#endif /* LISTS_H */

