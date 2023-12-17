#include "monty.h"
/**
 * _add - adds the top two element of the stack
 * @stack: points to the top of the stack
 * @line_number:line index
 */

void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		error = 1;
		return;
	}
	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);
}
