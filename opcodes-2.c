#include "monty.h"
/**
 * swap - swaps the two top elements of the stack.
 * @stack: the stack.
 * @line_number: an int.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	if (stack == NULL
		|| *stack == NULL
		|| (*stack)->next == NULL)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't swap, stack to short", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
