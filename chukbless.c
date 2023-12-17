#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: pointer to the top of stack.
 * @line_no: line index of the file.
 * Return: empty.
*/

void rotr(stack_t **stack, unsigned int line_no)
{
	stack_t *curr = *stack;
	int temp;

	if (curr != NULL && curr->next != NULL)
		while (curr->next != NULL)
			curr = curr->next;
	else
		return;

	temp = curr->n;
	while (curr->prev != NULL)
	{
		curr->n = curr->prev->n;
		curr = curr->prev;
	}

	curr->n = temp;
	(void)line_no;
}

/**
 * rotl - rotates the stack to the top.
 * @stack: pointer to the top of stack.
 * @line_no: line index of the file.
 * Return: empty.
*/

void rotl(stack_t **stack, unsigned int line_no)
{
	stack_t *curr = *stack;
	int temp;

	if (curr != NULL && curr->next != NULL)
		temp = curr->n;
	else
		return;

	while (curr->next != NULL)
	{
		curr->n = curr->next->n;
		curr = curr->next;
	}

	curr->n = temp;
	(void)line_no;
}

/**
 * check_value - func to scan the push value
 * @stack: pointer to the stack
 * @line_no: line index of command
 * Return: the correct value
*/

int check_value(stack_t **stack, unsigned int line_no)
{
	int va1 = 0, temp = 1;

	if (value == NULL || *value == '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (*value == '-')
	{
		temp = -1;
		value++;
	}
	while (*value)
	{
		if (*value >= '0' && *value <= '9')
			va1 = va1 * 10 + (*value - '0');
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_no);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		value++;
	}
	va1 *= temp;
	return (va1);
}

/**
 * stack_queue - push for a stack.
 * @stack: pointer to the queue.
 * @new: new element.
 * Return: empty.
*/

void stack_queue(stack_t **stack, stack_t *new)
{
	stack_t *curr = *stack;

	new->next = NULL;

	while (curr && curr->next)
		curr = curr->next;

	if (!curr)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		curr->next = new;
		new->prev = curr;
	}
}
