#include "monty.h"
/**
 * free_all - frees all
 * @stack: points to the stack
 * @line: the line to free
 * @ptr: the file to close
 */

void free_all(stack_t *stack, char *line, FILE *ptr)
{
	stack_t *temp = stack;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	free(line);
	fclose(ptr);
}
