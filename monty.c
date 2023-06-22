#include "monty.h"

closeable_t cls = {NULL, NULL, NULL, NULL};
/**
 * main - the monty program
 * @argv: an arrays of strings passed from the command line.
 * @argc: the length of argv
 * Return: return EXIT_SUCCESS if successful else EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	size_t len;
	unsigned int num = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	cls.file = argv[1];
	cls.stream = fopen(cls.file, "r");
	if (cls.stream == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", cls.file);
		return (EXIT_FAILURE);
	}
	while (getline(&(cls.line), &len, cls.stream) != -1)
	{
		find_opcode(&stack, num);
		num++;
	}
	free(cls.line);
	fclose(cls.stream);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
