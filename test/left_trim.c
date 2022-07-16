#include "monty.h"
/**
 * ltrim - remove all whitespaces on the left
 * @str: string of characters
 *
 * Return: modified string on success,
 * or old string on failure
 */
char *ltrim(char *str)
{
	if (!str)
		return ('\0');

	if (!*str)
		return (str);

	while (*str != '\0' && isspace(*str))
		str++;
	return (str);
}
