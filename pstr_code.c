#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack.
 * @h_stack: the head of the stack.
 * @line_number: Line number in the input file.
 *
 * Return: void.
 */
void pstr(stack_t **h_stack, unsigned int line_number)
{
	stack_t *h = *h_stack;

	while (h != NULL && h->n != 0)
	{
		if (h->n >= 0 && h->n <= 127)
		{
			printf("%c", h->n);
			h = h->next;
		}
		if (h == NULL || h->n == 0 || !(h->n >= 0 && h->n <= 127))
			break;

	}

	printf("\n");
	(void)line_number;
}
