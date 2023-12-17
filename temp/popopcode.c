#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: pointer to the top of stack.
 * @line_no: line index of file.
 * Return: null.
*/

void pop(stack_t **stack, unsigned int line_no)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
	(void)line_no;
}
