#include "monty.h"
/**
 * push - pushes an element to the stack
 * @top : element at the top of the stack
 * @line : line number in the bytecode file
 *
 * Return: Nothing
 * Exit status: 0 if exited successfully, otherwise 1
 */
void push(stack_t **top, unsigned int line)
{
	stack_t *temp = NULL, *new = malloc(sizeof(stack_t) * STACK_SIZE);
	char *snum = NULL;

	strcpy(snum, num_store);
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	if (!atoi(snum))
	{
		fprintf(stderr, "L%d: usage: push integer", line);
		exit(EXIT_FAILURE);
	}

	temp = *top;
	new->n = atoi(snum);
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
