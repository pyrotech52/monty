#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to the top of stack.
 * @line_no: line index of the file
 * Return: empty
*/

void pint(stack_t **stack, unsigned int line_no)
{
	stack_t *curr = *stack;

	if (curr == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", curr->n);
}
