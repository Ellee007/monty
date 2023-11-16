#include "monty.h"
stack_t *top = NULL;

/**
 * main - driver function for monty program
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success
 */

int main(int ac, char *av[])
{
	stack_t *stack;

	stack = NULL;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (read_execute_file(av[1], &stack) == -1)
		exit(EXIT_FAILURE);
	return (0);
}
