#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @stack: head node of stack linked list
 * @line_number: opcode line number
 * Return: Nothing
 */
void _push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = num_global.num;
	if (*stack == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
		top = new;
	}
	else
	{
		top->next = new;
		new->next = NULL;
		new->prev = top;
		top = new;
	}
}

/**
 * _pall - prints all the values on the stack starting from the top
 * @stack: Address of stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void _pall(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{
	stack_t *top_dup = top;

	while (top)
	{
		printf("%d\n", top->n);
		top = top->prev;
	}
	top = top_dup;
}
/**
 * _pint - prints the top value followed by new line
 * @stack: Address of stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: Address of stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void _pop(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = top->prev;
}

/**
 * _swap - swaps the top two elements of the stack
 * @stack: Address of stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void _swap(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{
	stack_t *before_top;
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	before_top = top->prev;
	tmp = before_top->n;
	before_top->n = top->n;
	top->n = tmp;
}
