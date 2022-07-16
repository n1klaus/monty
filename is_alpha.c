#include "monty.h"
/**
 * is_alpha - check if all characters in a string are alphabetical letters
 * @str: string of characters
 *
 * Return: 0 if exited successfully, otherwise 1
 */
int is_alpha(char *str)
{
	unsigned int i;

	for (i = 0; i < strlen(str); i++)
		if (!isalpha(str[i]))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
