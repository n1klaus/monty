#include "monty.h"
/**
 * pint - prints the value at the top of the stack,
 * followed by a new line
 * @top : element at the top of the stack
 * @line : line number in the bytecode file
 *
 * Return: 0 if exited successfully, otherwise 1
 */
void pint(stack_t **top, unsigned int line)
{
	stack_t *temp = NULL;

	temp = *top;
	if (*top != NULL && line >= 1)
		fprintf(stdout, "%d", temp->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
