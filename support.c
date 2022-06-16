#include "monty.h"

/**
 *cleaner-clean the stack
 */

void cleaner(void)
{
	free_list(args.stack);
	if (args.file)
	{
		fclose(args.file);
	}
}
/**
 *monty-getline function
 */
void monty(void)
{
	char line[128];

	args.file = fopen(args.argv[1], "r");

	if (args.file != NULL)
	{
		while (fgets(line, sizeof(line), args.file) != NULL)
		{
			args.count++;
			args.line = line;
			caller();
		}
		fclose(args.file);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", args.argv[1]);
		cleaner();
		exit(EXIT_FAILURE);
	}
}

/**
 *caller- call the exc function
 */

void caller(void)
{
	instruction_t code[] = {
		{"push", push}, {"mul", mul},
		{"pall", pall}, {"mod", mod},
		{"pint", pint}, {"pchar", pchar},
		{"pop", pop}, {"pstr", pstr},
		{"swap", swap}, {"rotl", rotl},
		{"add", add}, {"div", div_n},
		{"nop", nop}, {"sub", sub},
		{"rotr", rotr}, {"queue", queue},
		{"stack", stack},
		{NULL, NULL}};

	int i = 0;
	char *magic = NULL;

	magic = strtok(args.line, " \n");
	if (!magic || *magic == '#')
		return;
	while (code[i].opcode && magic)
	{
		if (strcmp(magic, code[i].opcode) == 0)
		{
			code[i].f(&(args.stack), args.count);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%ld: unknown instruction %s\n", args.count, magic);
	cleaner();
	exit(EXIT_FAILURE);
}
