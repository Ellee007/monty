#include "monty.h"

/**
 * atoi_number - converts string to integer.
 * @token2: string.
 * @linecheck: line number.
 * Return: always
 */

void atoi_number(char *token2, unsigned int linecheck)
{
	unsigned int i;

	if (token2 != NULL)
	{
		for (i = 0; token2[i] != 0; i++)
		{
			if ((token2[i] < 48 && token2[i] != 45) || token2[i] > 57)
			{
				fprintf(stderr, "L%d: usage: push integer\n", linecheck);
				exit(EXIT_FAILURE);
			}
			else
				token2_atoi = atoi(token2);
		}
		return;
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", linecheck);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_list - function that frees a list.
 * @head: pointer to list.
 * Return: always.
 */

void free_list(stack_t *head)
{
	stack_t *aux = NULL;

	while (head != NULL)
	{
		aux = head;
		head = head->next;
		free(aux);
	}
	free(head);
}


/**
 * add_node - to add node at the beginning
 * @stack: doble pointer from struct
 * @number: int to know the number of line from struct
 * Return: int.
 */

void *add_node(stack_t **stack, unsigned int number)
{
	stack_t *new = NULL;

	if (stack == NULL)
	{
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	new->n = number;
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
	return (new);
}

/**
 * swap_f - swaps numbers at the beginning
 * @stack: doble pointer from struct
 * @line_number: int to know the number of line from struct
 * Return: always
 */

void swap_f(stack_t **stack, unsigned int line_number)
{
	int aux = 0;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = aux;
}

/**
 * add_f - adds numbers at the beginning
 * @stack: double pointer from struct
 * @line_number: int to know the number of line from struct
 * Return: always
 */

void add_f(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		free_list(*stack);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(aux);
}
