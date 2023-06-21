#include "monty.h"

/**
 * read_file - reads and process each line of the
 *	file read as an argument.
 * @stack: a stack_t type linked list.
 * Return: EXIT_SUCCESS if successful else EXIT_FAILURE.
 */
int read_file(stack_t **stack)
{
	FILE *stream = NULL;
	char *line = NULL;
	size_t len = -1;
	int nread = -1, num = 1;

	stream = fopen(filename, "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", filename);
		return (EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		if (find_opcode(stack, line, num) == EXIT_FAILURE)
		{
			fclose(stream);
			exit(EXIT_FAILURE);
		}
		num++;
	}
	free(line);
	free_stack(*stack);
	fclose(stream);
	return (EXIT_SUCCESS);
}

/**
 * find_opcode - reads each line and process the line
 *	with the correct opcode function.
 * @stack: a stack_t type linked list.
 * @line: the string to process.
 * @num: the line number of line in the file.
 * Return: EXIT_SUCCESS if successful else EXIT_FAILURE.
 */
int find_opcode(stack_t **stack, char *line, int num)
{
	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL},
	};
	int i = 0, found;
	char *opcode = NULL;

	(void)found;
	opcode = strtok(line, "\t \n");
	if (opcode != NULL)
	{
		for (i = 0; opcodes[i].opcode; i++)
		{
			found = 0;
			if (strncmp(opcodes[i].opcode, opcode, strlen(opcode)) == 0)
			{
				opcodes[i].f(stack, num);
				found = 1;
				break;
			}
		}

	}
	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", num, opcode);
		free(line);
		free_stack(*stack);
		return (EXIT_FAILURE);
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
 * get_line_by_number - gets a line of string from a file
 *	based on its line number.
 * @line_number: the line number of the line of string in
 *	the file to get.
 * Return: returns the line if successful else NULL.
 */
char *get_line_by_number(unsigned int line_number)
{
	unsigned int num = 1;
	int nread = -1;
	size_t len = 0;
	FILE *stream = NULL;
	char *line = NULL, *cmd = NULL;

	stream = fopen(filename, "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", filename);
		return (NULL);
	}

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		if (line_number == num)
		{
			cmd = strdup(line);
			break;
		}
		num++;
	}
	free(line);
	fclose(stream);
	return (cmd);
}
