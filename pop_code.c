#include "monty.h"

/**
 * pop - Removes the top element.
 * @h_stack: the head of the stack.
 * @line_number: Line number in the input file.
 *
 * Return: void.
 */
void pop(stack_t **h_stack, unsigned int line_number)
{
	stack_t *new_node;

	new_node = *h_stack;

	if (*h_stack == NULL)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*h_stack = (*h_stack)->next;
	if (*h_stack != NULL)
		(*h_stack)->prev = NULL;
	free(new_node);
	(void)line_number;
}
