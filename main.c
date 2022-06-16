#include "monty.h"
args_t args;
/**
 *main-mainfunction of the code
 *@ac:number of argument
 *@av:array of srgs
 *Return:success on exit
 */

int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	args.argv = av;
	args.count = 0;
	args.line = NULL;
	args.stack = NULL;
	args.file = NULL;
	args.order = 1;
	monty();
	free_list(args.stack);
	return (EXIT_SUCCESS);
}
