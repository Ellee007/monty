#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack
 * @stack: Address of stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void _pchar(stack_t **stack __attribute__((unused)),
	   unsigned int line_number __attribute__((unused)))
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!isprint(top->n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	putchar(top->n);
}

/**
 * _pstr - prints the string starting at the top of stack
 * @stack: Address of stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void _pstr(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{
	stack_t *top_dup = top;

	if (*stack == NULL)
		putchar('\n');

	while (top)
	{
		if (!isprint(top->n))
		{
			putchar('\n');
			exit(EXIT_SUCCESS);
		}
		if (top->n == 0)
			exit(EXIT_SUCCESS);
		putchar(top->n);
		top = top->prev;
	}
	putchar('\n');
	top = top_dup;
}

/**
 * _rotl - Rotates the stack to the top
 * @stack: Address of stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void _rotl(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{
}

/**
 * _rotr - Rotate the stack to the bottom
 * @stack: Address of stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void _rotr(stack_t **stack __attribute__((unused)),
	   unsigned int line_number __attribute__((unused)))
{

}

/**
 * _stack - sets the format of the data to a stack (LIFO)
 * @stack: Address of stack
 * @line_number: opcode line number
 * Return: Nothing
 */
void _stack(stack_t **stack __attribute__((unused)),
		unsigned int line_number __attribute__((unused)))
{

}
