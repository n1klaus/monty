#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @top : element at the top of the stack
 * @line : line number in the bytecode file
 *
 * Return: 0 if exited successfully, otherwise 1
 */
int pop(stack_t **top, unsigned int line)
{
	stack_t *temp = NULL, *new_top = NULL;

	temp = *top;
	if (*top != NULL && line >= 1)
	{
		new_top = temp->prev;
		*top = new_top;
		new_top->next = NULL;
		free(temp);
	}
	else
	{
		dprintf(STD_ERR, "L%d: can't pop an empty stack", line);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
