#include "monty.h"

int main(int argc, char *argv[]);
global_t global = {NULL, NULL, NULL, 0};

/**
 * main - the Monty code interpreter
 * @argc: Number of arguments
 * @argv: Array of argument strings
 *
 * Return: On succes (0).
 */
int main(int argc, char *argv[])
{
	stack_t *n_node = NULL;

	if (argc != 2)
	{
		fflush(stdout);
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	global.file = fopen(argv[1], "r");

	if (global.file == NULL)
	{
		fflush(stdout);
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	call_op(&n_node);
	fclose(global.file);
	free(global.line);
	f_stack(n_node);
	exit(EXIT_SUCCESS);
}
