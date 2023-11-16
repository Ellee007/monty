#include "monty.h"

/**
 * read_execute_file - Reads and parses a file line by line and
 * executes valid opcodes
 * @fileName: File name
 * @stack: stack
 * Return: 0 on success, -1 on failure
 */

int read_execute_file(char *fileName, stack_t **stack)
{
	FILE *file = fopen(fileName, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}
	read_tokenize_execute(file, stack);
	if (fclose(file) == -1)
		exit(EXIT_FAILURE);
	return (0);
}

/**
 * get_opcode_func - Gets the function pointed to by opcode
 * @token: monty byte code read from file
 * @line_number: Line number
 * Return: function pointer to the opcode function
 */

op_funcs get_opcode_func(char *token, unsigned int line_number)
{
	size_t i = 0;
	char *token_dup = NULL;

	instruction_t op_manual[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{NULL, NULL},
	};

	token_dup = malloc(sizeof(char) * (strlen(token) + 1));
	if (token_dup == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(token_dup, token);
	token = strtok(token_dup, " \t");
	while (op_manual[i].opcode)
	{
		if (strcmp(token, op_manual[i].opcode) == 0)
		{
			free(token_dup);
			return (op_manual[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	free(token_dup);
	return (NULL);
}

/**
 * strip - removes leading whitespaces from a string
 * @str: String to be stripped
 * Return: Pointer to stripped string
 */

char *strip(char *str)
{
	char *strip_str;
	int i = 0, j = 0, idx;

	strip_str = malloc(sizeof(char) * strlen(str) + 1);
	if (strip_str == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	while (str[i] == ' ' || str[i] == '\t')
		i++;

	for (idx = i; str[idx] != '\0'; idx++)
	{
		strip_str[j] = str[idx];
		j++;
	}
	strip_str[j] = '\0';

	return (strip_str);
}

/**
 * get_push_arg - Gets the argument passed to push function
 * @token: string containing push opcode separated by space
 * @line_number: line number
 * Return: push argument converted to string, on failure -1
 */
int get_push_arg(char *token, unsigned int line_number)
{
	int num = 0, i = 0;
	char *value = NULL, sign;

	if (strstr(token, "push") != NULL)
	{
		token = strtok(token, " \n\t");
		value = strtok(NULL, " \n\t");
			if (value == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			if (value[0] == '-')
			{
				sign = '-';
				while (value[i])
				{
					value[i] = value[i + 1];
					i++;
				}
				value[i] = '\0';
			}
			if (isnumber(value) == 1)
			{
				num = atoi(value);
				if (sign == '-')
					num = (-1 * num);
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
	return (num);
}

/**
 * isnumber - Checks if a string contains only numbers
 * @str: input string
 * Return: 1 if true otherwise 0
 */

int isnumber(char *str)
{
	int i = 0, flag = 1;

	while (str[i])
	{
		if (isdigit(str[i]) == 0)
		{
			flag = 0;
			break;
		}
		i++;
	}
	return (flag);
}
