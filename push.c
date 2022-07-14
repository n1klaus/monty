#include "monty.h"
#include "extern.h"
/**
 * push - pushes an element to the stack
 * @top : element at the top of the stack
 * @line : line number in the bytecode file
 *
 * Return: Nothing
 */
void push(stack_t **top, unsigned int line)
{
	stack_t *temp = NULL, *new = malloc(sizeof(stack_t) * STACK_SIZE);

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (num_store <= 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	temp = *top;
	new->n = num_store;
	if (*top == NULL)
		new->prev = NULL;
	else
	{
		temp->next = new;
		new->prev = temp;
	}
	new->next = NULL;
	*top = new;
	exit(EXIT_SUCCESS);
}
