#include "monty.h"
/**
 * err - prints appropriate error messages
 * @err_code: the error codes
 * (1) => missing file(s)
 * (2) => unable to open or read the provided file
 * (3) => the provided file contains an invalid instruction
 * (4) => unable to allocate more memory
 * (5) => the parameter passed to "push" is not an int
 */
void err(int err_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "ERROR: can't open file %s\n", va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "ERROR: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: USAGE: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
/**
 * more_err - more error handling
 * @err_code: error code
 * (6) => stack is empty for pint
 * (7) => stack is empty for pop
 * (8) => stack is too short for operation
 * (9) => division by 0
 */
void more_err(int err_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, err_code);
	switch (err_code)
	{
		case 6:
			fprintf(stderr, "L%d: stack is empty\n", va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: stack is empty\n", va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: stack is too short for %s\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by 0\n", va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - string error handling
 * @err_code: error codes:
 * (10) => number is outside ASCII limits
 * (11) => stack is empty
 */
void string_err(int err_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, err_code);
	l_num = va_arg(ag, int);
	switch (err_code)
	{
		case 10:
			fprintf(stderr, "L%d: value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: stack is empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

