#include "monty.h"

/**
 * nop_f - doesn't do anything
 * @stack: doble pointer from struct
 * @line_number: the number of every line
 * Return: always
 */

void nop_f(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * sub_f - to substract node at the beginning
 * @stack: double pointer from struct
 * @line_number: int to know the number of line from struct
 * Return: always
 */

void sub_f(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		free_list(*stack);
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(aux);
}

/**
 * div_f - to divide node at the beginning
 * @stack: double pointer from struct
 * @line_number: int to know the number of line from struct
 * Return: always
 */

void div_f(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{

		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	aux->next = NULL;
	free(aux);
}

/**
 * mul_f - to multiply node at the beginning
 * @stack: double pointer from struct
 * @line_number: int to know the number of line from struct
 * Return: always
 */

void mul_f(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		free_list(*stack);
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	aux->next = NULL;
	free(aux);
}

/**
 * mod_f - computes the rest of the division at the beginning
 * @stack: double pointer from struct
 * @line_number: int to know the number of line from struct
 * Return: always
 */

void mod_f(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	aux->next = NULL;
	free(aux);
}
