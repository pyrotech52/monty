#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: pointer to the stack top.
 * @line_no: line index of file
 * Return: null
*/

void push(stack_t **stack, unsigned int line_no)
{
	stack_t *new;
	int va1;

	va1 = check_value(stack, line_no);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new->n = va1;
	if (isstack == 1)
	{
		new->prev = NULL;
		if (*stack != NULL)
		{
			new->next = *stack;
			(*stack)->prev = new;
		}
		else
			new->next = NULL;
		*stack = new;
	}
	else
		stack_queue(stack, new);
}

/**
 * pall - prints all the values on the stack, starting from the top of the stack.
 * @stack: pointer to the top of stack.
 * @line_no: line index of the file.
 * Return: null
*/

void pall(stack_t **stack, unsigned int line_no)
{
	stack_t *curr;

	curr = *stack;

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}

	(void)line_no;
}
