#include "monty.h"

/**
 *delet_at_idx-delete the node at the end of node
 *@head:First node of the list
 *@idx:index number
 *Return: 1 if the scu
 */

int delet_at_idx(stack_t **head, unsigned int idx)
{
	stack_t *temp = *head;
	unsigned int size = 0, i = 0;

	if (!head || !(*head))
		return (-1);
	if (idx == 0)
	{
		*head = (*head)->next;

		if (*head)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	while (temp)
	{
		size++;
		temp = temp->next;
	}
	if (size < idx + 1)
		return (-1);
	while (i < idx)
	{
		temp = temp->next;
		i++;
	}
	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);
	return (1);
}

/**
 *free_list-remove the list you can want
 *@head:pointer of the list
 */

void free_list(stack_t *head)
{
	stack_t *temp = head;

	while (head)
	{
		head = head->next;
		free(temp);
		temp = head;
	}
}


/**
 *list_size-print size of stack
 *@head:pointer of stack
 *Return:Num of stack
 */

size_t list_size(stack_t *head)
{
	size_t node;

	node = 0;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		node++;
	}

	return (node);
}


/**
 *add_node_first-add the new node at the first
 *@head:firat node pointer
 *@num:New node data
 *Return:node
 */


stack_t *add_node_first(stack_t **head, const int num)
{
	stack_t *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(stack_t));

	if (new == NULL)
		return (NULL);

	new->n = num;
	new->next = NULL;
	new->prev = NULL;

	new->next = *head;

	if (*head)
		(*head)->prev = new;
	*head = new;

	return (new);
}

/**
 *add_at_end-add new node at the end of list
 *@head:head of the node
 *@num: new data tha can be inserted to ne node
 *Return:node
 */

stack_t *add_at_end(stack_t **head, const int num)
{
	stack_t *new;
	stack_t *temp = *head;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = num;
	new->next = NULL;
	new->prev = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
	return (new);
}
