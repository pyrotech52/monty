#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

char *global(char *nothing);
extern char *value;
extern FILE *file_d;
extern int isstack;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue).
 * @n: integer.
 * @prev: This points to the previous element of the stack (or queue).
 * @next: This points to the next element of the stack (or queue).
 *
 * Description: describs the doubly linked list node structure
 * for stack, queues, LIFO, FIFO.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and all its function.
 * @opcode: the opcode.
 * @f: the function to handle the opcode.
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void _read(FILE *file_d);
void instructions(stack_t **stack, char *inst, unsigned int line_no);
void push(stack_t **stack, unsigned int line_no);
void pall(stack_t **stack, unsigned int line_no);
void pint(stack_t **stack, unsigned int line_no);
void pop(stack_t **stack, unsigned int line_no);
void swap(stack_t **stack, unsigned int line_no);
void add(stack_t **stack, unsigned int line_no);
void nop(stack_t **stack, unsigned int line_no);
void sub(stack_t **stack, unsigned int line_no);
void div(stack_t **stack, unsigned int line_no);
void mod(stack_t **stack, unsigned int line_no);
void mul(stack_t **stack, unsigned int line_no);
void free_stack(stack_t *stack);
int check_value(stack_t **stack, unsigned int line_no);
void pchar(stack_t **stack, unsigned int line_no);
void pstr(stack_t **stack, unsigned int line_no);
void rotl(stack_t **stack, unsigned int line_no);
void rotr(stack_t **stack, unsigned int line_no);
void stack_queue(stack_t **stack, stack_t *new);


#endif
