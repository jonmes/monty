#include "monty.h"

/**
 *sub-substract the top of the element
 *@stack:pointer
 *@lineNum:line number
 */

void sub(stack_t **stack, unsigned int lineNum)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", lineNum);
		cleaner();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	delet_at_idx(stack, 0);
}

/**
 *div_n-divide the top of the element
 *@stack:pointer
 *@lineNum:line number
 */

void div_n(stack_t **stack, unsigned int lineNum)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", lineNum);
		cleaner();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", lineNum);
		cleaner();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	delet_at_idx(stack, 0);
}

/**
 *mul-divide the top of the element
 *@stack:pointer
 *@lineNum:line number
 */
void mul(stack_t **stack, unsigned int lineNum)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", lineNum);
		cleaner();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	delet_at_idx(stack, 0);
}

/**
 *mod-divide the top of the element
 *@stack:pointer
 *@lineNum:line number
 */

void mod(stack_t **stack, unsigned int lineNum)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", lineNum);
		cleaner();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", lineNum);
		cleaner();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	delet_at_idx(stack, 0);
}

/**
 *pchar-print the char the top of the element
 *@stack:pointer
 *@lineNum:line number
 */

void pchar(stack_t **stack, unsigned int lineNum)
{
	if (!(*stack) || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", lineNum);
		cleaner();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", lineNum);
		cleaner();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

