#ifndef MONTY_H
#define MONTH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct arguments - Values to be accessed by various functions
 * @argv: Name of the executable
 * @counter: counts number of lines
 * @line: input line
 * @stack: doubly linked list
 * @file: file
 * @order: FIFO or LIFO
 */
typedef struct arguments
{
	char **argv;
	ssize_t count;
	char *line;
	stack_t *stack;
	FILE *file;
	int order;
} args_t;
/** main .c*/
void nop(stack_t **stack, unsigned int lineNnm);

/* support*/
void pall(stack_t **stack, unsigned int lineNum);
void push(stack_t **stack, unsigned int lineNum);
void pint(stack_t **stack, unsigned int lineNum); 
void pop(stack_t **stack, unsigned int lineNum);
void queue(stack_t **stack, __attribute__((unused)) unsigned int lineNum);

/*stack and queue*/

void stack(stack_t **stack, unsigned int lineNum);
size_t print_list(const stack_t *head);
int check_string(char *str);
void swap(stack_t **stack, unsigned int lineNum);
void add(stack_t **stack, unsigned int lineNum);

/* doublelinked list*/

int delet_at_idx(stack_t **head, unsigned int idx);
void free_list(stack_t *head);
size_t list_size(stack_t *head);
stack_t *add_node_first(stack_t **head, const int num);
stack_t *add_at_end(stack_t **head, const int num);

/* support*/
void cleaner(void);
void monty(void);
void caller(void);
void pstr(stack_t **stack, unsigned int lineNum);

/* math_operation*/
void sub(stack_t **stack, unsigned int lineNum);
void div_n(stack_t **stack, unsigned int lineNum);
void mul(stack_t **stack, unsigned int lineNum);
void mod(stack_t **stack, unsigned int lineNum);
void pchar(stack_t **stack, unsigned int lineNum);

/*string man*/
void rotl(stack_t **stack, unsigned int lineNum);
void rotr(stack_t **stack, unsigned int lineNum);

extern args_t args;
#endif
