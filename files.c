#include "monty.h"

/**
 * open_file - opens file
 * @file_name: file namepath
 */
void open_file(char *file_name)
{
	FILE *fd = open(file_name, "r");

	if (!file_name || !fd)
		err(2, file_name);
	read_file(fd);
	fclose(fd);
}

/**
 * read_file - reads file
 * @fd: pointer to file
 */
void read_file(FILE *fd)
{
	int ln, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (ln = 1; getline(&buffer, &len, fd) != -1; ln++)
	{
		format = parse_line(buffer, ln, format);
	}
	free(buffer);
}

/**
 * parse_line - tokenize lines
 * @buffer: line fromm file
 * @ln: line number
 * @format: storage format
 * (0) => stack
 * (1) => queue
 * Return: 0 if opcode is stack, 1 if queue
 */
int parse_line(char *buffer, int ln, int format)
{
	char *opcode, *val;
	const char *lim = "\n ";

	if (!buffer)
		err(4);

	opcode =  strtok(buffer, lim);
	if (!opcode)
		return (format);
	val = strtok(NULL, lim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, val, ln, format);
	return (format);
}

/**
 * find_func - find the function for the opcode
 * @opcode: opcode
 * @val: value of opcode
 * @format: storage format, 0 => stack, 1 => queue
 * @ln: line number
 */
void find_func(char *opcode, char *val, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == "#")
		return;
	for (flag = 1, i = 0; func_list[i].opcode; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, val, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}
