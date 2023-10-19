#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @h_stack: the head of the stack.
 * @line_number: Line number in the input file.
 *
 * Return: void.
 */
void rotl(stack_t **h_stack, unsigned int line_number)
{
	stack_t *top = *h_stack;
	stack_t *second = *h_stack;

	if (top == NULL || top->next == NULL)
		return;

	while (second->next != NULL)
		second = second->next;

	*h_stack = top->next;
	(*h_stack)->prev = NULL;
	second->next = top;
	top->prev = second;
	top->next = NULL;

	(void)line_number;
}
