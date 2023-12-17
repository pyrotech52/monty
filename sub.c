#include "monty.h"
/**
 * _sub - substracts the top element from the secon element
 * @stack: points to the top of the stack
 * @line_number: line index
 */

void _sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		error = 1;
		return;
	}
	(*stack)->next->n -= (*stack)->n;
	_pop(stack, line_number);
}
