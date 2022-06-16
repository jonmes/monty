#include "monty.h"

/**
 *push-add data at top of the stack
 *@stack:pointer of the node
 *@lineNum:the nember of line can be given
 */

void push(stack_t **stack, unsigned int lineNum)
{
	register int num;
	char *gir = strtok(NULL, "\n");

	if (check_string(gir) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer \n", lineNum);
		cleaner();
		exit(EXIT_FAILURE);
	}

	num = atoi(gir);
	if (args.order == 1)
	{
		add_node_first(stack, num);
	}
	else
		add_at_end(stack, num);
}
/**
 *pall-print the stack
 *@stack:pointer
 *@lineNum:line nume
 */

void pall(stack_t **stack, unsigned int lineNum)
{
	(void)lineNum;
	print_list(*stack);
}

/**
 *swap- swaps the top two elemwnt of the stack
 *@stack:pointer
 *@lineNum:line number
 */

void swap(stack_t **stack, unsigned int lineNum)
{
	register int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", lineNum);
		cleaner();
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
/**
 *add- add the top two elemwnt of the stack
 *@stack:pointer
 *@lineNum:line number
 */

void add(stack_t **stack, unsigned int lineNum)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", lineNum);
		cleaner();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	delet_at_idx(stack, 0);
}

/**
 *nop-no change
 *@stack:pointer
 *@lineNum:number
 */

void nop(stack_t **stack, unsigned int lineNum)
{
	(void)lineNum;
	(void)stack;
}
