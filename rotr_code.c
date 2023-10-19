#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @h_stack: the head of the stack.
 * @line_number: Line number in the input file.
 *
 * Return: void.
 */
void rotr(stack_t **h_stack, unsigned int line_number)
{
	stack_t *last = *h_stack;

	if (*h_stack == NULL || (*h_stack)->next == NULL)
		return;

	while (last->next != NULL)
		last = last->next;

	last->prev->next = NULL;
	last->next = *h_stack;
	last->prev = NULL;
	(*h_stack)->prev = last;
	*h_stack = last;
	(void)line_number;
}
