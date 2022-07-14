#include "monty.h"
/**
 * get_opcode - function pointer to map opcode to function
 * @op : pointer to a string of characters referencing opcodes
 *
 * Return: 0 if exited successfully, otherwise 1
 */
void (*get_opcode(char *op))(stack_t **top, unsigned int line)
{
	int line = 0, isUknown = 0;

	instruction_t opcodes_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL},
	};

	int count = 0;

	while (opcodes_list[count].opcode != NULL)
	{
		if (strcmp(opcodes_list[count].opcode, op) == 0)
			return (opcodes_list[count].f);
		isUknown = 1;
		count++;
	}
	if (op == NULL || isUknown)
	{
		fprintf(stderr, "L%d: unknown instruction %s",
			line, op);
		exit (EXIT_FAILURE);

	}
	exit (EXIT_SUCCESS);
}
