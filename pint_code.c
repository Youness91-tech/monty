#include "monty.h"
/**
 * pint - Prints the value of the top element of a stack
 * @h_stack: The head of the stack
 * @line_number: line_number counter
 * Return: no return
 */
void pint(stack_t **h_stack, unsigned int line_number)
{
	if (*h_stack == NULL)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(global.file);
		free(global.line);
		f_stack(*h_stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h_stack)->n);
}
