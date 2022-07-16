#include "monty.h"
/**
 * free_stack_t - frees elements of a stack_t stack.
 * @top : top element of the stack
 *
 * Return: Nothing
 */
void free_stack_t(stack_t **top)
{
	stack_t *head = NULL, *current = NULL;

	head = *top;
	if (head == NULL)
		exit(EXIT_SUCCESS);

	while (head->next != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
	free(head);
}
