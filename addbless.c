#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: pointer to the top of stack.
 * @line_no: line index of the file.
 * Return: null.
*/

void add(stack_t **stack, unsigned int line_no)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	pop(stack, line_no);
	(*stack)->n += temp;
}
