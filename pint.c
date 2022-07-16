#include "monty.h"
/**
 * pint - prints the value at the top of the stack,
 * followed by a new line
 * @top : element at the top of the stack
 * @line : line number in the bytecode file
 *
 * Return: Nothing
 */
void pint(stack_t **top, unsigned int line)
{
	stack_t *temp = NULL;

	temp = *top;
	if (temp != NULL && line >= 1)
		fprintf(stdout, "%d", temp->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
