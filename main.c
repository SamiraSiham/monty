#include "monty.h"
stack_t *head = NULL;

/**
 * main -  entry point
 * @argc: arg count
 * @argv: arg vector
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - create a node
 * @n: node value
 * Return: pointer to node, or NULL on failure
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - frees nodes in the stack
 */
void free_nodes(void)
{
	stack_t *tmp;

	if(!head)
		return;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * add_to_queue - add a node to queue
 * @new_node: pointer to node
 * @ln: line number of opcode
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
