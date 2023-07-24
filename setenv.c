#include "shell.h"

/**
 * my_setenv - function to set the env varble,
 * @head: a pointer to the env varialbe
 * @argv: variable name set
 * @args: no of args
 *
 * Return: -1 on failure and 0 on success,
 */
int my_setenv(env_t **head, char **argv, int args)
{
	char *bufone = NULL, *bufftwo = NULL;
	int idx = 0;

	if (!head || !*head)
		return (0);

	if (args != 3)
		return (-1);

	bufone = mystr_concat(argv[1], "=");
	bufftwo = mystr_concat(bufone, argv[2]);
	free(bufone);

	idx = index_list_fnd(*head, argv[1]);
	if (idx == 0)
	{
		add_node_at_end(head, bufftwo);
		free(bufftwo);
		return (0);
	}

	if (idx > 0)
	{
		delete_index_node(head, idx);
		node_at_index(head, bufftwo, idx);
		free(bufftwo);
		return (0);
	}

	free(bufftwo);
	return (0);
}

/**
 * my_unsetenv - this un set curen env varial,
 * takes care of  the unsetenv builtin
 * @head: pointer in linked list
 * @argv: contains parsed line or array of strngs
 * Return:  -1 on failure and0 on success
 */
int my_unsetenv(env_t **head, char **argv)
{
	int idx;

	if (!argv[1])
		return (-1);

	idx = index_list_fnd(*head, argv[1]);
	if (idx == 0 || !head || !*head)
		return (0);

	else
		delete_index_node(head, idx);

	return (0);
}

/**
 * handle_setenv - handle the build in
 * @argv: array of args
 * @head: pointer to linked list
 * @i: index of the arg or commands in history
 * @progg_nme: program name
 *
 */
void handle_setenv(char **argv, env_t **head, int *i, char *progg_nme)
{
	int v = 0, a = 0, arg = 0;
	char *rem_error = "unsetenv: Too few arguments.\n";

	while (argv[arg])
		arg++;

	if (!my_strcmp(argv[0], "setenv"))
	{
		a = my_setenv(head, argv, arg);
		if (a == -1)
			print_setenv_error(i, progg_nme, argv);
	} else if (!my_strcmp(argv[0], "unsetenv"))
	{
		v = my_unsetenv(head, argv);
		if (v == -1)
			write(2, rem_error, my_strlen(rem_error));
	}
}

/**
 * print_setenv_error - display custom error message
 * @i: index of cmd in history
 * @s:program name
 * @argv: array of args
 *
 */
void print_setenv_error(int *i, char *s, char **argv)
{
	char *bufone = NULL, *bufftwo = NULL, *bufffive = NULL,
	     *buffor = NULL, *bufftree = NULL;
	char *num = NULL;

	num = convert_num_str(*i, 10);

	bufone = mystr_concat(s, ": ");
	bufftwo = mystr_concat(bufone, num);
	free(bufone);
	bufffive = mystr_concat(bufftwo, ": ");
	free(bufftwo);
	buffor = mystr_concat(bufffive, argv[0]);
	free(bufffive);
	bufftree = mystr_concat(buffor, ": Bad variable name\n");
	free(buffor);
	write(2, bufftree, my_strlen(bufftree));
	free(bufftree);
}
