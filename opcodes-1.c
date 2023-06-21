#include "monty.h"

/**
 * push - pushes a new node on the linked list.
 * @stack: a stack_t type linked list.
 * @line_number: the line number from a file with
 *	the push command to read and process.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *line = NULL, *tok = NULL;
	int item = 0;
	stack_t *node = *stack, *new_node = NULL;

	line = get_line_by_number(line_number);
	if (line)
	{
		tok = strtok(line, "\t \n");
		tok = strtok(NULL, "\t \n");
		if (tok == NULL || is_valid_num(tok) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(line);
			free_stack(node);
			exit(EXIT_FAILURE);
		}
		item = atoi(tok);
		new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(line);
			free_stack(node);
			exit(EXIT_FAILURE);
		}
		new_node->n = item;
		new_node->next = new_node->prev = NULL;
		if (node == NULL)
			*stack = new_node;
		else
		{
			node->prev = new_node;
			new_node->next = node;
			*stack = new_node;
		}
		free(line);
	}
}

/**
 * pall - prints all the integers of the linked list.
 * @stack: a stack_t type linked list.
 * @line_number: the line number of the line of string
 *	from the file whose commands will be processed.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * pint - prints the value at the top of the stack.
 * @stack: a stack_t type linked list.
 * @line_number: the line number of the line of string
 *	from the file whose commands will be processed.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: a stack_t type linked list.
 * @line_number: the line number of the line of string
 *	from the file whose commands will be processed.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *del = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(del);
}
