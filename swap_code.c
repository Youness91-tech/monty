#include "monty.h"

/**
 * swap - adds the top two elements of the stack.
 * @h_stack: to the head of the stack.
 * @line_number: Line number in the input file.
 *
 * Return: void.
 */
void swap(stack_t **h_stack, unsigned int line_number)
{
	stack_t *o_head;
	unsigned int length = 0, tmp;

	o_head = *h_stack;

	while (o_head != NULL)
	{
		length++;
		o_head = o_head->next;
	}
	if (length < 2)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	o_head = *h_stack;
	tmp = o_head->n;
	o_head->n = o_head->next->n;
	o_head->next->n = tmp;
}
