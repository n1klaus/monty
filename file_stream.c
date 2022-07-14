#include "monty.h"
/**
 * file_stream - get tokens from monty bytecode file
 * @ac : arguments count
 * @av : arguments array
 * Return: 0 if exited successfully, otherwise 1
 */
int file_stream(__attribute__((unused))int ac, char **av)
{
	FILE *instream = NULL;
	ssize_t numchar;
	size_t len = MAXLEN;
	int line = 1, stack_num = 0;
	char **lineptr = malloc(sizeof(char) * MAXLEN);
	char **token_str = malloc(sizeof(char) * MAXLEN);
	stack_t **top = malloc(sizeof(stack_t) * STACK_SIZE);
	char *delim = " \t", *num_store = NULL;

	if (lineptr == NULL || token_str == NULL || top == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		return (EXIT_FAILURE);
	}
	instream = fopen(av[1], "r");
	if (instream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", av[1]);
		return (EXIT_FAILURE);
	}
	while ((numchar = getline(lineptr, &len, instream)) != -1
			&& numchar != EOF)
	{
		while ((*token_str = strtok(*lineptr++, delim)) != NULL)
		{
			if (token_str[1] != NULL)
			{
				num_store = token_str[1];
				stack_num = atoi(num_store);
			}
			get_opcode(token_str[0])(top, line);
		}
		line++;
	}
	free(top);
	free(lineptr);
	free(token_str);
	fclose(instream);
	return (EXIT_SUCCESS);
}
