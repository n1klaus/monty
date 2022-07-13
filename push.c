#include "monty.h"
/**
 * push - pushes an element to the stack
 * @top : element at the top of the stack
 * @line : line number in the bytecode file
 * @num : integer number to push
 *
 * Return: 0 if exited successfully, otherwise 1
 */
int push(stack_t **top, unsigned int line, char *num)
{
	stack_t *temp = NULL, *new = malloc(sizeof(stack_t) * STACK_SIZE);

	if (new == NULL)
	{
		dprintf(STD_ERR, "Error: malloc failed");
		return (EXIT_FAILURE);
	}

	if (num == NULL || !atoi(num))
	{
		dprintf(STD_ERR, "L%d: usage: push integer", line);
		return (EXIT_FAILURE);
	}

	temp = *top;
	new->n = atoi(num);
	if (*top == NULL)
		new->prev = NULL;
	else
	{
		temp->next = new;
		new->prev = temp;
	}
	new->next = NULL;
	*top = new;
	return (EXIT_SUCCESS);
}
