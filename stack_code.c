#include "monty.h"

/**
 * f_stack - free all nodes in the stack
 * @h_stack: the head of the stack
 *
 * Return: void.
 */
void f_stack(stack_t *h_stack)
{
	stack_t *crnt;

	crnt = h_stack;

	while (h_stack != NULL)
	{
		crnt = h_stack->next;
		free(h_stack);
		h_stack = crnt;
	}
}
