#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>

extern int token2_atoi;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int main(int argc, char *argv[]);
void main_f(char *str);
void select_op(char *token1, stack_t **stack, unsigned int line_number);
void push_f(stack_t **stack, unsigned int line_number);
void pall_f(stack_t **stack, unsigned int line_number);
void pint_f(stack_t **stack, unsigned int line_number);
void pop_f(stack_t **stack, unsigned int line_number);
void swap_f(stack_t **stack, unsigned int line_number);
void add_f(stack_t **stack, unsigned int line_number);
void nop_f(stack_t **stack, unsigned int line_number);
void sub_f(stack_t **stack, unsigned int line_number);
void div_f(stack_t **stack, unsigned int line_number);
void mul_f(stack_t **stack, unsigned int line_number);
void mod_f(stack_t **stack, unsigned int line_number);
void pchar_f(stack_t **stack, unsigned int line_number);
void atoi_number(char *token2, unsigned int line_number);
void free_list(stack_t *head);
void *add_node(stack_t **stack, unsigned int line_number);


#endif
