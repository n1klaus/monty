#include "monty.h"
/**
 * is_digit - check if all characters in a string are integer numbers
 * @str: string of characters
 *
 * Return: 0 if exited successfully, otherwise 1
 */
int is_digit(char *str)
{
	unsigned int i;

	for (i = 0; i < strlen(str); i++)
		if (!isdigit(str[i]))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
