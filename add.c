#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @top : element at the top of the stack
 * @line : line number in the bytecode file
 *
 * Return: 0 if exited successfully, otherwise 1
 */
int add(stack_t **top, unsigned int line)
{
	stack_t *new_top = NULL;

	if ((*top) != NULL && temp->prev != NULL && line >= 1)
	{
		new_top = (*top)->prev;
		new_top->n = new_top->n + (*top)->n;
		pop(top, line);
	}
	else
	{
		dprintf(STD_ERR, "L%d: can't add, stack too short", line);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
