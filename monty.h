#ifndef _MONTY_H_
#define _MONTY_H_

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

#endif /* _MONTY_H_ */
