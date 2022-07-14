#include "monty.h"
/**
 * main - Monty Bytecode file interpretor
 * @ac : arguments count
 * @av : arguments array
 *
 * Return: 0 if exited successfully, otherwise 1
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		return (EXIT_FAILURE);
	}

	file_stream(ac, av);
	return (EXIT_SUCCESS);
}
