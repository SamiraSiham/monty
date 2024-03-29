#include "monty.h"

/**
 * nop - nothing.
 * @stack: pointer to pointer on stack
 * @ln: line number
 */
void nop(stack_t **stack, unsigned int ln)
{
	(void)stack;
	(void)ln;
}

/**
 * swap_nodes - swap the top two nodes
 * @stack: pointer to pointer on stack
 * @ln: line number
 */
void swap_nodes(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	if (!stack || !*stack || !(*stack)->next)
		more_err(8, ln, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

/**
 * add_nodes - add the two top nodes to stack
 * @stack: pointer to pointer on stack
 * @ln: line number
 */
void add_nodes(stack_t **stack, unsigned int ln)
{
	int sum;

	if (!stack || !*stack || !(*stack)->next)
		more_err(8, ln, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nodes - subs the first two elements of stack
 * @stack: pointer to pointer on stack
 * @ln: line number
 */
void sub_nodes(stack_t **stack, unsigned int ln)
{
	int sub;

	if (!stack || !*stack || !(*stack)->next)
		more_err(8, ln, "sub");

	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - divs the first 2 nodes of stack
 * @stack: pointer to pointer on stack
 * @ln: line number
 */
void div_nodes(stack_t **stack, unsigned int ln)
{
	int div;

	if (!stack || !*stack || !(*stack)->next)
		more_err(8, ln, "div");
	if ((*stack)->n == 0)
		more_err(9, ln);
	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
