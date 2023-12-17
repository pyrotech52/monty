#include "monty.h"
/**
 * _push - pushes elements to the stack
 * @stack: pointer to the top of the stack
 * @line_number: line index
 * @token: string representation
 */

void _push(char *token, stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	int i;

	if (token == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		error = 1;
		return;
	}
	for (i = 0; token[i] != '\0'; i++)
	{
		if (token[i] == '-')
			i++;
		if (isdigit(token[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			error = 1;
			return;
		}
	}
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		perror("Error: malloc failed\n");
		error = 1;
		return;
	}
	new->n = atoi(token);
	new->prev = NULL;
	new->next = NULL;

	if (*stack)
	{
		(*stack)->prev = new;
		new->next = *stack;
	}
	*stack = new;
}
