#include "monty.h"

/**
 * div - divides the second top element of the stack by the top element of the stack.
 * @stack: pointer to the top of stack.
 * @line_no: line index of the file.
 * Return: null.
*/

void div(stack_t **stack, unsigned int line_no)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_no);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	if (temp == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_no);
	(*stack)->n /= temp;
}

/**
 * mul - multiplies the second top element of the stack with the top element of the stack.
 * @stack: pointer to the top of stack.
 * @line_no: line index of the file.
 * Return: null.
*/

void mul(stack_t **stack, unsigned int line_no)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_no);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	pop(stack, line_no);
	(*stack)->n *= temp;
}

/**
 * mod - func to print all the elements in a stack
 * @stack: pointer to the top of stack.
 * @line_no: line index of the file.
 * Return: null.
*/

void mod(stack_t **stack, unsigned int line_no)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_no);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	if (temp == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	pop(stack, line_no);
	(*stack)->n %= temp;
}

/**
 * sub - func to print all the elements in a stack.
 * @stack: pointer to the top of stack.
 * @line_no: line index of the file.
 * Return: null.
*/

void sub(stack_t **stack, unsigned int line_no)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_no);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	pop(stack, line_no);
	(*stack)->n -= temp;
}

/**
 * pstr - prints the string starting at the top of the stack, followed by a new line.
 * @stack: pointer to the top of stack.
 * @line_no: line index of the file.
 * Return: empty
*/

void pstr(stack_t **stack, unsigned int line_no)
{
	stack_t *curr = *stack;

	while (curr && curr->n > 0 && curr->n <= 127)
	{
		printf("%c", curr->n);
		curr = curr->next;
	}

	printf("\n");
	(void)line_no;
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: pointer to the top of stack.
 * @line_no: line index of the file.
 * Return: null.
*/

void pchar(stack_t **stack, unsigned int line_no)
{
	stack_t *curr = *stack;

	if (curr == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (curr->n >= 0 && curr->n <= 127)
		printf("%c\n", curr->n);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
