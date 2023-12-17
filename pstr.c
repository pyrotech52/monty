#include "monty.h"
/**
 * _pstr - prints the string starting at the top of the stack, followed by a new line.
 * @stack:points to the top of the stack
 * @line_number: line index
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}
	while (temp && temp->n != 0 && temp->n < 127 && temp->n > 0)
	{
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
