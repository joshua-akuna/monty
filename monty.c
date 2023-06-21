#include "monty.h"

char *filename = NULL;
/**
 * main - the monty program
 * @argv: an arrays of strings passed from the command line.
 * @argc: the length of argv
 * Return: return EXIT_SUCCESS if successful else EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		return (EXIT_FAILURE);
	}
	filename = argv[1];
	if (filename)
		return (read_file(&stack));
	free_stack(stack);
	return (EXIT_SUCCESS);
}
