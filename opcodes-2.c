#include "monty.h"
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
		free(cls.line);
		fclose(cls.stream);
		fprintf(stderr, "L%d: can't add, stack to short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
