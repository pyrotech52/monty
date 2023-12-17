#include "monty.h"
/**
 * _pint - prints the value at the top of the stack
 * @stack:points to the top of the stack
 * @line_number:line index
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		error = 1;
		return;
	}
	printf("%d\n", (*stack)->n);
}
