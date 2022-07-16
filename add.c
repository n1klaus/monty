#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @top : element at the top of the stack
 * @line : line number in the bytecode file
 *
 * Return: Nothing
 */
void add(stack_t **top, unsigned int line)
{
	stack_t *new_top = NULL, *temp = *top;

	if (temp != NULL && temp->next != NULL && line >= 1)
	{
		new_top = temp->next;
		new_top->n = new_top->n + temp->n;
		pop(&temp, line);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
