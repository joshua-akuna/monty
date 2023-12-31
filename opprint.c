#include "monty.h"

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
		fclose(cls.stream);
		free(cls.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * nop - does nothing.
 * @stack: a stack_t type linked list.
 * @line_number: the line number of the line of string
 *	from the file whose commands will be processed.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * pchar - prints the char at the top of the stack
 *	followed by a new line.
 * @stack: a stack_t type linked list.
 * @line_number: the line number of the line of string
 *	from the file whose commands will be processed.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(cls.stream);
		free(cls.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(cls.stream);
		free(cls.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 *	followed by a new line.
 * @stack: a stack_t type linked list.
 * @line_number: the line number of the line of string
 *	from the file whose commands will be processed.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;

	(void)line_number;
	while (stack && node)
	{
		if (node->n <= 0 || node->n > 127)
			break;
		printf("%c", (node)->n);
		node = node->next;
	}
	printf("\n");
}
