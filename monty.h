#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
/**
 * struct stack_s - represents a node of a doubly linked list
 *	(a stack or queue).
 * @n: stores an integer in each node.
 * @prev: a pointer to the previous element of a stack or queue.
 * @next: a pointer to the next element of a stack or queue.
 *
 * Description: a doubly linked list node structure
 *	for stack, queues, LIFO, FIFO.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function.
 * @opcode: the opcode
 * @f: function to handle the opcode.
 *
 * Description: opcode and its function for stack,
 *	queues, LIFO, FIFO.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct closeable_s - stores the closeable resources.
 * @file: a string representing a file path.
 * @stream: an open stream to a file.
 * @line: a string that stores user input as a line.
 * @num: a string of integers.
 * @mode: defines the current mode of operation. STACK or QUEUE
 */
typedef struct closeable_s
{
	char *file;
	FILE *stream;
	char *line;
	char *num;
	int mode;
} closeable_t;


extern closeable_t cls;

int find_opcode(stack_t **stack, int num);
int is_valid_num(char *num);
void free_resources(void);

void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

void push(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

stack_t *add_to_stack(stack_t **head, const int n);
void free_stack(stack_t *head);
#endif /* _MONTY_H_ */
