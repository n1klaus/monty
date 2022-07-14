#include "monty.h"
/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack
 * @top : element at the top of the stack
 * @line : line number in the bytecode file
 *
 * Return: 0 if exited successfully, otherwise 1
 */
void pall(stack_t **top, unsigned int line)
{
	stack_t *temp = NULL;

	temp = *top;
	if (*top != NULL && line >= 1)
	{
		while (temp->prev != NULL)
		{
			fprintf(stdout, "%d", temp->n);
			temp = temp->prev;
		}
	}
	exit (EXIT_SUCCESS);
}
