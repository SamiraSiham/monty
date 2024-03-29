#include "monty.h"

/**
 * print_char - print ascii value
 * @stack: pointer to pointer on stack
 * @ln: line number
 */
void print_char(stack_t **stack, unsigned int ln)
{
	int ascii;

	if (!stack || !*stack)
		string_err(11, ln);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, ln);
	printf("%c\n", ascii);
}

/**
 * print_str - print string
 * @stack: pointer to pointer on stack
 * @ln: line number
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (!stack || !*stack)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - rotate the 1st node to the bottom
 * @stack: pointer to pointer on stack
 * @ln: line number
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (!stack || !*stack || !(*stack)->next)
		return;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - rotate the last node to the top
 * @stack: pointer to pointer on stack
 * @ln: line number
 */

void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (!stack || !*stack || !(*stack)->next)
		return;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
