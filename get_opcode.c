#include "monty.h"
/**
 * get_opcode - function pointer to map opcode to function
 * @op : pointer to a string of characters referencing opcodes
 *
 * Return: Nothing
 */
void (*get_opcode(char *op))(stack_t **top, unsigned int line)
{
	int line = 1, isUNKNOWN = 0;

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
		isUNKNOWN = 1;
		count++;
	}
	if (op == NULL || isUNKNOWN)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			line, op);
		exit(EXIT_FAILURE);

	}
	exit(EXIT_SUCCESS);
}
