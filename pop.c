#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @top : element at the top of the stack
 * @line : line number in the bytecode file
 *
 * Return: Nothing
 */
void pop(stack_t **top, unsigned int line)
{
	stack_t *temp = NULL, *new_top = NULL;

	temp = *top;
	if (temp != NULL && line >= 1)
	{
		new_top = temp->next;
		new_top->prev = NULL;
		*top = new_top;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
