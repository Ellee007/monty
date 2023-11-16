#include "monty.h"

/**
 * read_tokenize_execute - As the name implies
 * @file: file id
 * @stack: Address of stack
 * Return: void
 */
void read_tokenize_execute(FILE *file, stack_t **stack)
{
	char *token = NULL, *line = NULL;
	size_t buff = 0;
	int line_number = 0, size_read = 0;
	op_funcs op_func = NULL;

	while ((size_read = getline(&line, &buff, file)) != -1)
	{
		token = strtok(line, "\n");
		if (token == NULL || token[0] == '#')
		{
			line_number++;
			continue;
		}
		token = strip(token);
		line_number++;
		op_func = get_opcode_func(token, line_number);
		if (op_func == NULL)
		{
			free(token);
			free(line);
			exit(EXIT_FAILURE);
		}
		num_global.num = get_push_arg(token, line_number);
		op_func(stack, line_number);
	}
	free(line);
}
