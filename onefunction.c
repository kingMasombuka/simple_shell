#include "shell.h"

/**
 * add_node_at_end - adds a new node to linked list
 * @head: a pointer to the  list
 * @str: the string to brthe new node
 * Return: a c address of new element
 */

env_t *add_node_at_end(env_t **head, char *str)
{
	env_t *curr = NULL;
	env_t *meean = *head;

	curr = malloc(sizeof(env_t));
	if (!curr)
		return (NULL);

	curr->str = my_strdup(str);
	curr->next = NULL;

	if (*head == NULL)
	{
		*head = curr;
		return (curr);
	}

	while (meean->next)
		meean = meean->next;

	meean->next = curr;

	return (curr);
}

/**
 * delete_index_node - removes  node in  linked list at a given index
 * @head: pointer to the first element in linked list
 * @index: position of the node to delete
 * Return: One
 */
int delete_index_node(env_t **head, unsigned int index)
{
	env_t *meean = *head;
	env_t *curr = NULL;
	unsigned int x = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(meean->str);
		free(meean);
		return (1);
	}

	while (x < index - 1)
	{
		if (!meean || !(meean->next))
			return (-1);
		meean = meean->next;
		x++;
	}

	curr = meean->next;
	meean->next = curr->next;
	free(curr->str);
	free(curr);

	return (1);
}
/**
 * node_at_index - adds ode in linked list at a certain index
 * @head:  pointer to the linked list
 * @str: string  the new node
 * @idx: insert the node
 * Return:0
 */

int node_at_index(env_t **head, char *str, int idx)
{
	int i;
	env_t *nw = NULL;
	env_t *meean = *head;

	nw = malloc(sizeof(env_t));
	if (!nw || !head)
		return (-1);

	nw->str = my_strdup(str);
	nw->next = NULL;

	if (idx == 0)
	{
		nw->next = *head;
		*head = nw;
		return (0);
	}

	for (i = 0; meean && i < idx; i++)
	{
		if (i == idx - 1)
		{
			nw->next = meean->next;
			meean->next = nw;
			return (0);
		}
		else
			meean = meean->next;
	}

	return (-1);
}

/**
 * index_list_fnd - finds the index of a given element in the list.
 * @head: linked list pointer
 * @name: charecytre  of the node to be find
 * Return: index of curr node
 */
int index_list_fnd(env_t *head, char *name)
{
	int idx = 0;
	int x = 0;

	while (head)
	{
		x = my_strncmp(head->str, name, my_strlen(name));
		if (x == 0)
			return (idx);
		idx++;
		head = head->next;
	}

	return (0);
}
