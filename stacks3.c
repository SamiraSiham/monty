#include "monty.h"

/**
 * mul_nodes - multiplies the 2 first nodes of stack
 * @stack: pointer to pointer on stack
 * @ln: line number
 */
void mul_nodes(stack_t **stack, unsigned int ln)
{
	int mul;

	if (!stack || !*stack || !(*stack)->next)
		more_err(8, ln, "mul");
	(*stack) = (*stack)->next;
	mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nodes - modulo of first 2 nodes of stack
 * @stack: pointer to pointer on stack
 * @ln: line number
 */
void mod_nodes(stack_t **stack, unsigned int ln)
{
	int mod;

	if (!stack || !*stack || !(*stack)->next)
		more_err(8, ln, "mod");

	if ((*stack)->n == 0)
		more_err(9, ln);
	(*stack) = (*stack)->next;
	mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
