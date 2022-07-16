#include "monty.h"
extern int num_store;
/**
 * push - pushes an element to the beginning of the stack
 * @top : element at the top/beginning of the stack
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

	fprintf(stdout, "Push Int:=> %d\n", num_store);
	if (!num_store)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}

	temp = *top;
	new->n = num_store;
	if (temp != NULL)
		temp->prev = new;
	new->next = temp;
	new->prev = NULL;
	*top = new;
	exit(EXIT_SUCCESS);
}
