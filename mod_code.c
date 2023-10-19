#include "monty.h"

/**
 * mod - Computes the rest of dividing the second top element
 *         of the stack by the top element.
 * @h_stack: the head of the stack.
 * @line_number: Line number in the input file.
 *
 * Return: void.
 */
void mod(stack_t **h_stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(global.file);
		free(global.line);
		f_stack(*h_stack);
		exit(EXIT_FAILURE);
	}

	if ((*h_stack)->n == 0)
	{
		fflush(stdout);
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*h_stack)->next->n % (*h_stack)->n;
	(*h_stack)->next->n = tmp;
	o_head = *h_stack;
	(*h_stack) = (*h_stack)->next;
	free(o_head);
}
