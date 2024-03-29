#include "monty.h"

/**
 * add_to_stack - adds a node to the stack
 * @new_node: pointer to the new node.
 * @ln: line number
 */
void add_to_stack(stack **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (!new_node || !*new_node)
		exit(EXIT_FAILURE);
	if (!head)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * print_stack - print stack
 * @stack: pointer to pointer to the stack head node
 * @ln: line number of opcode
 */
void print_stack(stack_t **stack, unsigned int ln)
{
	stack_t *tmp;

	(void) ln;
	if (!stack)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pop_top - pop from stack
 * @stack: pointer to pointer to stack
 * @ln: lin number
 */
void pop_top(stack_t **stack, unsigned int ln)
{
	stack_t **tmp;

	if (!stack || !*stack)
		more_err(7, ln);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(tmp);
}
/**
 * print_top - print first node of stack
 * @stack: pointer to pointer to stack
 * @ln: line number
 */
void print_top(stack_t **stack, unsigned int ln)
{
	if (!stack || !*stack)
		more_err(6, ln);
	printf("%d\n", (*stack)->n);
}
