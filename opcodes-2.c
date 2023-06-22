#include "monty.h"
/**
 * swap - swaps the two top elements of the stack.
 * @stack: the stack.
 * @line_number: an int.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL
		|| *stack == NULL
		|| (*stack)->next == NULL)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't swap, stack to short", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * adds - adds the top 2 elements of the stack.
 * @stack: the stack.
 * @line_number: an int.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL
		|| *stack == NULL
		|| (*stack)->next == NULL)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't add, stack to short", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
