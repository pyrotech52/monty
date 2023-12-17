#include "monty.h"

char *global(char *nothing);
FILE *file_d;
char *value;
int isstack = 1;

/**
 * free_stack - The function to free stack.
 * @stack: The stack to be freed.
 * Return: Empty return.
*/

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	fclose(file_d);
}

/**
 * instructions - scanning through the passed instructions
 * @stack: pointer to the stack
 * @inst: the passed line instructions
 * @line_no: line index of the file
 * Return: EXIT_FAILURE if instructions don't exist, else return empty
*/

void instructions(stack_t **stack, char *inst, unsigned int line_no)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", multiply},
		{"mod", modulus},
		{"#", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
		};
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, inst) == 0)
		{
			instructions[i].f(stack, line_no);
			return;
		}
		i++;
	}

	if (inst[0] == '#')
		return;
	fprintf(stderr, "L%d: unknown instruction %s\n", line_no, inst);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * _read - function to scan the passed instructions.
 * @file_d: file_d descriptor of monty file_d passed.
 * Return: return -1 if any error, or else 0.
*/

void _read(FILE *file_d)
{
	char fetch[1024], *line[1024];
	unsigned int line_no = 0;
	stack_t *stack = NULL;

	while (fgets(fetch, sizeof(fetch), file_d) != NULL)
	{
		line_no++;
		*line = strtok(fetch, " \n\t");
		if (*line == NULL)
			continue;
		value = strtok(NULL, " \n\t");
		if (strcmp(line[0], "stack") == 0)
		{
			isstack = 1;
			continue;
		}
		if (strcmp(line[0], "queue") == 0)
		{
			isstack = 0;
			continue;
		}
		instructions(&stack, line[0], line_no);

	}
	free_stack(stack);
}

/**
 * main - The funtion to implement a custom monty file.
 * @argc: an argument count.
 * @argv: an argument vectors.
 * Return: EXIT_FAILURE on any kind of error, else success.
*/

int main(int argc, char **argv)
{

	if (argc == 2)
	{
		file_d = fopen(argv[1], "r");
		if (file_d != NULL)
		{
			_read(file_d);
			exit(EXIT_SUCCESS);
		}
		else
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	}
	else
		fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
