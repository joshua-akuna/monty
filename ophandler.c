#include "monty.h"

/**
 * find_opcode - reads each line and process the line
 *	with the correct opcode function.
 * @stack: a stack_t type linked list.
 * @num: the line number of line in the file.
 * Return: EXIT_SUCCESS if successful else EXIT_FAILURE.
 */
int find_opcode(stack_t **stack, int num)
{
	instruction_t opcodes[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"div", _div},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"mul", _mul},
		{"nop", nop}, {"sub", sub}, {"mod", _mod}, {"pchar", pchar},
		{NULL, NULL},
	};
	int i = 0, found;
	char *opcode = NULL, *line = cls.line;

	opcode = strtok(line, "\t \n");
	if (opcode != NULL)
	{
		cls.num = strtok(NULL, "\t \n");
		if (opcode[0] == '#' || strncmp(opcode, "nop", strlen(opcode)) == 0)
			;
		else
		{
			for (i = 0; opcodes[i].opcode; i++)
			{
				found = 0;
				if (strcmp(opcodes[i].opcode, opcode) == 0)
				{
					opcodes[i].f(stack, num);
					found = 1;
					break;
				}
			}
			if (!found)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", num, opcode);
				free(line);
				free_stack(*stack);
				exit(EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}

/**
 * is_valid_num -checks if the argument is a valid integer.
 * @num: a string to checks if its a valid integer.
 * Return: 0 if num is not a valid integer else 1.
 */
int is_valid_num(char *num)
{
	int i = 0;

	if (num == NULL || num[i] == '\0')
		return (0);

	if (num[i] == '-')
		i++;
	if (num[i] < '0' || num[i] > '9')
		return (0);

	while (num[i] != '\0')
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

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
