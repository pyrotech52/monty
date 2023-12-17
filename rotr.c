#include "monty.h"
/**
 * _rotr - rotates the stack to the bottom
 * @stack:points to thhe top of the stack
 * @line_number: line index
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (temp->next)
	{
		temp = temp->next;
	}
	temp->prev->next = NULL;
	(*stack)->prev = temp;
	temp->next = *stack;
	temp->prev = NULL;
	*stack = temp;
}
