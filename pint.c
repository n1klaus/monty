#include "monty.h"
/**
 * pint - prints the value at the top of the stack,
 * followed by a new line
 * @top : element at the top of the stack
 * @line : line number in the bytecode file
 *
 * Return: 0 if exited successfully, otherwise 1
 */
int pint(stack_t **top, unsigned int line)
{
	stack_t *temp = NULL;

	temp = *top;
	if (*top != NULL && line >= 1)
		dprintf(STD_OUT, temp->n);
	else
	{
		dprintf(STD_ERR, "L%d: can't pint, stack empty", line);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
