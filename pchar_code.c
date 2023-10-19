#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack.
 * @h_stack: the head of the stack.
 * @line_number: Line number in the input file.
 *
 * Return: void.
 */
void pchar(stack_t **h_stack, unsigned int line_number)
{
	if (*h_stack == NULL)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fflush(stdout);
		exit(EXIT_FAILURE);
	}

	if ((*h_stack)->n < 0 || (*h_stack)->n > 127)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*h_stack)->n);
}
