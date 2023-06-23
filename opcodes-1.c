#include "monty.h"

/**
 * push - pushes a new node on the linked list.
 * @stack: a stack_t type linked list.
 * @line_number: the line number from a file with
 *	the push command to read and process.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *tok = cls.num, *line = cls.line;
	int item = 0;
	stack_t *node = *stack, *new_node = NULL;

	if (line)
	{
		if (cls.num == NULL || is_valid_num(cls.num) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free(line);
			fclose(cls.stream);
			free_stack(node);
			exit(EXIT_FAILURE);
		}
		item = atoi(tok);
		new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(line);
			fclose(cls.stream);
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
	}
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

/**
 * swap - swaps the two top elements of the stack.
 * @stack: the stack.
 * @line_number: an int.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int sum;

	if (stack == NULL
		|| *stack == NULL
		|| (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(cls.stream);
		free(cls.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	sum = temp->n;
	temp->n = temp->next->n;
	temp->next->n = sum;
}

/**
 * rotl - moves the current top node to the bottom of the 
 *	stack and the second top node to the top.
 * @stack: the stack.
 * @line_number: the line number of the current command in the file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *last = NULL;

	(void)line_number;
	if (stack && *stack && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last = *stack;

		while (last->next != NULL)
			last = last->next;
		last->next = temp;
		temp->prev = last;
		temp->next = NULL;
	}
}
