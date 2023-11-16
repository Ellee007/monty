#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: Address of stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void _add(stack_t **stack __attribute__((unused)),
	   unsigned int line_number __attribute__((unused)))
{
	int result;
	stack_t *before_top;

	if (*stack == NULL || (*stack)->next == NULL || (*stack)->next == NULL)

	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	before_top = top->prev;
	result = before_top->n + top->n;
	before_top->n = result;
	top = before_top;
}

/**
 * _nop - doesn't do anything
 * @stack: Address of stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void _nop(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{
}

/**
 * _sub - subtracts the top element of the stack from the second
 * top element of the stack
 * @stack: Address of stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void _sub(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{
	int result;
	stack_t *before_top;

	if (*stack == NULL || (*stack)->next == NULL || (*stack)->next == NULL)

	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	before_top = top->prev;
	result = before_top->n - top->n;
	before_top->n = result;
	top = before_top;
}

/**
 * _div - divides the 2nd top element of the stack by the top
 * @stack: Address of stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void _div(stack_t **stack __attribute__((unused)),
	   unsigned int line_number __attribute__((unused)))
{

	int result;
	stack_t *before_top;

	if (*stack == NULL || (*stack)->next == NULL || (*stack)->next == NULL)

	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	before_top = top->prev;
	result = before_top->n / top->n;
	before_top->n = result;
	top = before_top;
}

/**
 * _mul - multiplies the 2nd top element of the stack by the top
 * @stack: Address of stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void _mul(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{

	int result;
	stack_t *before_top;

	if (*stack == NULL || (*stack)->next == NULL || (*stack)->next == NULL)

	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	before_top = top->prev;
	result = before_top->n * top->n;
	before_top->n = result;
	top = before_top;
}
