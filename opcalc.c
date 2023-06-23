#include "monty.h"

/**
 * add - adds the top 2 elements of the stack.
 * @stack: the stack.
 * @line_number: an int.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		free_stack(*stack);
		free(cls.line);
		fclose(cls.stream);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * sub - adds the top 2 elements of the stack.
 * @stack: the stack.
 * @line_number: an int.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		free_stack(*stack);
		free(cls.line);
		fclose(cls.stream);
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _mul - multiples the top 2 elements of the stack.
 * @stack: the stack.
 * @line_number: an int.
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		free_stack(*stack);
		free(cls.line);
		fclose(cls.stream);
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _div - divides the top 2 elements of the stack.
 * @stack: the stack.
 * @line_number: an int.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		free_stack(*stack);
		free(cls.line);
		fclose(cls.stream);
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		free_stack(*stack);
		free(cls.line);
		fclose(cls.stream);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _mod - divides the top 2 elements of the stack.
 * @stack: the stack.
 * @line_number: an int.
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		free_stack(*stack);
		free(cls.line);
		fclose(cls.stream);
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		free_stack(*stack);
		free(cls.line);
		fclose(cls.stream);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
