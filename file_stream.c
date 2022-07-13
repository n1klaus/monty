#include "monty.h"
/**
 * file_stream - get tokens from monty bytecode file
 * @ac : arguments count
 * @av : arguments array
 * Return: 0 if exited successfully, otherwise 1
 */
int file_stream(int ac, char **av)
{
	FILE *instream = NULL;
	int numchar, line = 1, len = MAXLEN;
	char **lineptr = malloc(sizeof(char) * MAXLEN);
	char **token_str = malloc(sizeof(char) * MAXLEN);
	stack_t **top = malloc(sizeof(stack_t) * STACK_SIZE);
	char *delim = " \t";

	if (lineptr == NULL || token_str == NULL || top == NULL)
	{
		dprintf(STD_ERR, "Error: malloc failed");
		return (EXIT_FAILURE);
	}

	instream = fdopen(av[1], "r");
	if (instream == NULL)
	{
		dprintf(STD_ERR, "Error: Can't open file %s", av[1]);
		return (EXIT_FAILURE);
	}

	while ((numchar = getline(lineptr, &len, instream)) != -1
			&& numchar != EOF)
	{
		while ((*token_str = strtok(*lineptr++, delim)) != NULL)
		{
			if ((get_opcode(token_str[0])(top, line)) ==
					EXIT_FAILURE)
			{
				dprintf(STD_ERR, "L%d: unknown instruction %s",
					line, token_str[0]);
				return (EXIT_FAILURE);
			}
		}
		line++;
	}
	free(top);
	free(lineptr);
	free(token_str);
	fclose(instream);
	return (EXIT_SUCCESS);
}
