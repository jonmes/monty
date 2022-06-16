#include "monty.h"

/**
 *stack-add data top of stack
 *@stack:pointer
 *@lineNum: find lin
 */

void stack(stack_t **stack, unsigned int lineNum)
{
	(void)stack;
	(void)lineNum;
	args.order = 1;
}

/**
 *queue- add new data at end of stack
 *@stack:pointer
 *@lineNum:line num
 */

void queue(stack_t **stack, __attribute__((unused)) unsigned int lineNum)
{
	(void)stack;
	args.order = 0;
}

/**
 *print_list-print list of node
 *@head:pointer of node
 *Return:node
 */

size_t print_list(const stack_t *head)
{
	size_t node = 0;

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		node++;
	}
	return (node);
}

/**
 *pint-print the value
 *@stack:pointre
 *@lineNum:line number
 */

void pint(stack_t **stack, unsigned int lineNum)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineNum);
		cleaner();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 *pop-remove the top of element
 *@stack:pointer
 *@lineNum:number of line
 */

void pop(stack_t **stack, unsigned int lineNum)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", lineNum);
		cleaner();
		exit(EXIT_FAILURE);
	}
	else
		delet_at_idx(stack, 0);
}
