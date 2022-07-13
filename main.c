#include "monty.h"
/**
 * main - Monty Bytecode file interpretor
 * @ac : arguments count
 * @av : arguments array
 * Return: 0 if exited successfully, otherwise 1
 */
int main(int ac, char **av)
{
	int wstate;
	pid_t parent_pid, child_pid;

	parent_pid = getpid();
	child_pid = fork();

	if (ac != 2)
	{
		dprintf(STD_ERR, "USAGE: monty file");
		return (EXIT_FAILURE);
	}

	if (child_pid == -1)
	{
		perror("Child Process Error");
		return (EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		dprintf(STD_OUT, "(%u) child process spawned !!\n", parent_pid);
		file_stream(ac, av);
	}
	else
	{
		wait(&wstate);
		dprintf(STD_OUT, "(%u) child process exited!!\n", child_pid);
		dprintf(STD_OUT, "(%u) parent process exited !!\n", parent_pid);
	}
	return (EXIT_SUCCESS);
}
