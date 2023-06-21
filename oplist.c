#include "monty.h"
/**
 * free_stack - frees up the dynamic memory of the
 *	nodes of a doubly linked list.
 * @head: a pointer to a node of a doubly linked list.
 * Return: Nothing.
 */
void free_stack(stack_t *head)

{
	if (head == NULL)
		return;
	free_stack(head->next);
	free(head);
}
