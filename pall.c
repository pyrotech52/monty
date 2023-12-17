#include "monty.h"
/**
 * _pall - prints all the value on the stack
 * @stack: pointer to the top of the stack
 * @line_number: line index
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
