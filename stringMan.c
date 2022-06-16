#include "monty.h"

/**
 *check_string-check the input string or not
 *@str:input value
 *Return:0 or 1
 */

int check_string(char *str)
{
	register int idx = 0;

	if (str == NULL)
		return (-1);
	if (*str == '-')
		str++;
	while (str[idx])
	{
		if (str[idx] >= '0' && str[idx] <= '9')
			idx++;
		else
			return (-1);
	}
	return (1);
}

/**
 *pstr-printin string form
 *@stack:pointer
 *@lineNum:line number
 */

void pstr(stack_t **stack, unsigned int lineNum)
{
	stack_t *temp = *stack;
	(void)lineNum;
	while (temp && (temp->n > 0 && temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

/**
 *rotl-rotates the stack to the top
 *@stack:pointer
 *@lineNum:line number
 */

void rotl(stack_t **stack, unsigned int lineNum)
{	
	if (*stack && (*stack)->next)
	{
		add_at_end(stack, (*stack)->n);
		delet_at_idx(stack, 0);
	}
	(void)lineNum;
}

/**
 *rotr-rotates the stack to the bottom
 *@stack:pointer
 *@lineNum:line number
 */

void rotr(stack_t **stack, unsigned int lineNum)
{
	int count = 0;
	stack_t *temp = *stack;
	if (*stack && (*stack)->next)
	{
		while (temp->next)
		{
			temp = temp->next;
			count++;
		}
		add_node_first(stack, temp->n);
		delet_at_idx(stack, count);
	}
	(void)lineNum;
}	
