#include "monty.h"

/**
 * push - Push node to the stack
 * @h_stack: The head of the stack
 * @line_number: Line number in the bytecode file
 *
 * Return: void.
 */
void push(stack_t **h_stack, unsigned int line_number)
{
	stack_t *new_node;

	if (global.arg == NULL || !_isdigit(global.arg))
	{
		fflush(stdout);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		f_stack(*h_stack);
		fclose(global.file);
		free(global.line);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fflush(stdout);
		fprintf(stderr, "Error: malloc failed\n");
		f_stack(*h_stack);
		fclose(global.file);
		free(global.line);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(global.arg);

	if (*h_stack == NULL)
	{
		(*h_stack) = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		(*h_stack)->prev = new_node;
		new_node->next = *h_stack;
		(*h_stack) = new_node;
	}
}


/**
 * _isdigit - checks if parameter is a number between 0 to 9.
 * @str: The string to check.
 * Return: 1 if is a number (0 to 9), 0 in other case.
 */
int _isdigit(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}

	return (1);
}
