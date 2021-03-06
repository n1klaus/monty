#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @top : element at the top of the stack
 * @line : line number in the bytecode file
 *
 * Return: Nothing
 */
void swap(stack_t **top, unsigned int line)
{
	stack_t *old_top = NULL, *new_top = NULL;

	old_top = *top;
	if (old_top != NULL && old_top->next != NULL && line >= 1)
	{
		new_top = old_top->next;
		if (new_top->next == NULL)
			old_top->next = NULL;
		else
		{
			new_top->next->prev = old_top;
			old_top->next = new_top->next;
		}
		old_top->prev = new_top;
		new_top->next = old_top;
		new_top->prev = NULL;
		*top = new_top;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
