#include "monty.h"
int num_store = 0;
/**
 * file_stream - get tokens from monty bytecode file
 * @av : arguments array
 *
 * Return: 0 if exited successfully, otherwise 1
 */
int file_stream(char **av)
{
	FILE *instream = NULL;
	ssize_t numchar = 0;
	size_t len = MAXLEN;
	int line = 1, opDONE = 0, numberDONE = 0;
	stack_t **top = malloc(sizeof(stack_t) * STACK_SIZE);
	char *op_instruction = NULL, *delim = " \r\f\v\t\n";
	char **lineptr = malloc(sizeof(char) * MAXLEN);
	char **token_str = malloc(sizeof(char) * MAXLEN);

	if (lineptr == NULL || token_str == NULL)
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
	while ((numchar = getline(lineptr, &len, instream)) != -1)
	{
		while ((*token_str = strtok(*lineptr++, delim)) != NULL)
		{
			if (!is_alpha(token_str[0]))
			{
				fprintf(stdout, "OP Instruction:=> %s\n",
					token_str[0]);
				op_instruction = token_str[0];
				opDONE = 1;
			}
			if (!is_digit(token_str[0]))
			{
				fprintf(stdout, "Processed Int:=> %s\n",
					token_str[0]);
				num_store = atoi(token_str[0]);
				fprintf(stdout, "File_stream Int:=> %d\n",
					num_store);
				numberDONE = 1;
			}
			if (opDONE && numberDONE)
				break;
		}
		get_opcode(op_instruction)(top, line);
		opDONE = numberDONE = 0;
		line++;
	}

	free_stack_t(top);
	free(lineptr);
	free(token_str);
	fclose(instream);
	return (EXIT_SUCCESS);
}
