#include "shell.h"

/**
 * arr_2_lst - changes the env variable to  linked list
 * @head: its pointer to the list to fill
 * @env: array of strs containing the env variables
 * Return: number of nodes
 */

int arr_2_lst(env_t **head, char **env)
{
	int b = 0;

	if (head)
		fr_lst(head);

	while (env[b])
	{
		add_node_at_end(head, env[b]);
		b++;
	}
	return (b);
}

/**
 * lst_2_arr - it changes the list in the  array of strings
 * @head: pointer to the linked list
 * Return: addressof array
 */
char **lst_2_arr(env_t *head)
{
	env_t *curr = head;
	char **a_rry = NULL, *sc = NULL;
	int i;
	size_t size = 0;


	size = list_length(head);

	if (!head || !size)
		return (NULL);

	a_rry = malloc(sizeof(char *) * (size + 1));
	if (!a_rry)
		return (NULL);

	for (i = 0; curr; curr = curr->next, i++)
	{
		sc = malloc(sizeof(char) * (my_strlen(curr->str) + 1));
		if (!sc)
		{
			free_ptr(a_rry);
			return (NULL);
		}
		sc = my_strcpy(sc, curr->str);
		a_rry[i] = sc;
	}
	a_rry[i] = NULL;

	return (a_rry);
}
/**
 * prt_lst - displsy all nodes
 * @h: its a pointer to list to display
 *
 * Return:  nummber of nodes diplayed
 */
size_t prt_lst(env_t *h)
{
	size_t siz = 0;

	while (h)
	{
		if (!h->str)
			my_puts("(nil)");
		else
			my_puts(h->str);
		h = h->next;
		siz++;
	}

	return (siz);
}
/**
 * fr_lst - frees  nodes of  list
 * @head: the list to be freed
 * Return:0
 */

void fr_lst(env_t **head)
{
	env_t *curr = NULL;

	if (head == NULL)
		return;

	while (*head)
	{
		curr = (*head)->next;
		free((*head)->str);
		free(*head);
		*head = curr;
	}

	*head = NULL;
}

/**
 * list_length -  num of elements in list
 * @h: pointer to the env_t list
 *
 * Return: number of elements in h
 */
size_t list_length(const env_t *h)
{
	size_t pos = 0;

	while (h)
	{
		pos++;
		h = h->next;
	}
	return (pos);
}
