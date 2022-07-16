#include "monty.h"
/**
 * split_string - split strings separated by whitespaces
 * @str: string of characters
 *
 * Return: extracted strings
 */
char **split_string(char *str)
{
	char **splits = NULL;
	char *token = NULL;
	int spaces = 0;

	token = strtok(str, " ");
	while (token)
	{
		splits = realloc(splits, sizeof(char *) * ++spaces);
		if (!splits)
			return (splits);
		splits[spaces - 1] = token;
		token = strtok(NULL, " ");
	}
	return (splits);
}
