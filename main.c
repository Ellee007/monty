#include "monty.h"
#define TOKEN_DELIMITER " \t\n\r"
int token2_atoi = 0;

/**
 * main - main
 * @argc: counter of arguments
 * @argv: arguments received from the prompt
 * Return: nothing
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	main_f(argv[1]);
	exit(EXIT_SUCCESS);
}

/**
 * main_f - tokenize and executing all functions
 * @str: arguments received from the prompt
 * Return: nothing
 */

void main_f(char *str)
{
	FILE *stream;
	size_t len = 0;
	ssize_t read;
	char *token1 = NULL, *token2 = NULL, *line = NULL;
	stack_t *head = NULL;
	unsigned int linecheck = 1;
	int count = 0;

	stream = fopen(str, "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", str);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, stream)) != -1)
	{
		while (line[0] == 32 || line[0] == 9)
		{
			line++;
			count++;
		}
		if (line[0] == '\n' || line[0] == '\0')
		{
			linecheck++;
			continue;
		}
		token1 = strtok(line, TOKEN_DELIMITER);
		token2 = strtok(NULL, TOKEN_DELIMITER);
		if (strcmp(token1, "push") == 0)
			atoi_number(token2, linecheck);
		select_op(token1, &head, linecheck);
		linecheck++;
	}
	for (; count > 0; count--)
		line--;
	free(line);
	free_list(head);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
