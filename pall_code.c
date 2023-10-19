#include "monty.h"
/**
 * pall - Print all values in the stack
 * @h_stack: the head of the stack
 * @line_number: Line number in the bytecode file
 * Return: no return
 */
void pall(stack_t **h_stack, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;

	h = *h_stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
