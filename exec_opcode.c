#include "monty.h"

/**
 * exec_op - execute the operation based on opcode
 * @opcode: opcode to be executed
 * @stack: pointer to the stack
 * @line_number: line number in the bytecode file
 *
 * Return: void.
 */
void exec_op(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t inst[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{"sub", sub},
		{"div", f_div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	int i;

	for (i = 0; inst[i].opcode != NULL; i++)
	{
		if (strcmp(inst[i].opcode, opcode) == 0)
		{
			inst[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	f_stack(*stack);
	fclose(global.file);
	free(global.line);
	exit(EXIT_FAILURE);
}

/**
 * call_op - Calls operations based on bytecodes
 * @stack: Pointer to the stack
 *
 * Return: void.
 */
void call_op(stack_t **stack)
{
	char *opcode = NULL;
	size_t length = 0;
	ssize_t counter;
	unsigned int line_number = 0;

	while ((counter = getline(&global.line, &length, global.file)) != -1)
	{
		line_number++;
		opcode = strtok(global.line, " \n\t\r\a");
		global.arg = strtok(NULL, " \n\t");
		if (opcode == NULL || *opcode == '#')
			continue;
		exec_op(opcode, stack, line_number);
	}
}
