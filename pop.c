#include "monty.h"
/**
 * _pop - removes the top element of the node
 * @stack: points to the top od the stack
 * @line_number: line index
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		error = 1;
		return;
	}
	*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp);
}
