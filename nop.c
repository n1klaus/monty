#include "monty.h"
/**
 * nop - Does nothing
 * @top : element at the top of the stack
 * @line : line number in the bytecode file
 *
 * Return: Always 0
 */
void nop(stack_t **top, unsigned int line)
{
	if (top && line)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}
