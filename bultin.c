#include "shell.h"

/**
 * check_builtin_cmd - checks command if built in
 * @line: input line
 * @progg_nme:  program name
 * @i: the variable to print
 * @argv:  a command passed
 * @head:  its pointer to the environ list
 *
 * Return: Always 0 (Success)
 */

int check_builtin_cmd(char *line, char **argv, char *progg_nme,
					  int *i, env_t **head)
{
	int x, aarg;
	long int num;

	if (!my_strcmp(argv[0], "exit"))
	{
		num = handle_exit(argv);
		if (num == -1)
			print_exit_error(i, progg_nme, argv);
		else
		{
			free_ptr(argv);
			free(line);
			fr_lst(head);
			exit(num);
		}
		return (1);
	}
	if (!my_strcmp(argv[0], "env"))
	{
		x = handle_env(argv, head);
		if (x == -1)
			print_env_error(argv);
		return (1);
	}
	if (!my_strcmp(argv[0], "setenv") || !my_strcmp(argv[0], "unsetenv"))
	{
		handle_setenv(argv, head, i, progg_nme);
		return (1);
	}
	if (!my_strcmp(argv[0], "cd"))
	{
		aarg = handle_cd(argv, head);
		if (aarg == -1)
		{
			print_cd_error(i, progg_nme, argv);
			write(2, "\n", 1);
		}
		return (1);
	}
	return (0);
}

/**
 * handle_exit - handlese exit
 * @tokens: arr of str from cmd
 *
 * Return: -1 on failure, or the value of
 * the argument0 if there are no arguments,
 *
 */

long int handle_exit(char **tokens)
{
	int flg = 0, x;
	long int numb = 0;

	if (tokens[1] == NULL)
		return (numb);
	for (x = 0; tokens[1][x]; x++)
	{
		if ((tokens[1][x] >= '0' && tokens[1][x] <= '9') || tokens[1][0] == '+')
		{
			flg = 1;
			if (tokens[1][x + 1] < '0' || tokens[1][x + 1] > '9')
				break;
		}
		else
			break;
		flg = 0;
	}
	if (flg == 1)
	{
		numb = atoi_(tokens[1]);
		return (numb);
	}
	return (-1);
}

/**
 * handle_env - acts like built in cmd
 * @arv: array of args from  cmd line
 * @head: a pointer to linked list
 *
 * Return:  -1 on error, 0 on success
 */

int handle_env(char **arv, env_t **head)
{
	if (arv[1] == NULL)
	{
		prt_lst(*head);
		return (0);
	}
	return (-1);
}

/**
 * handle_cd - takes care of the bash cd
 * commands
 * @arv: arr of args from the cmd line
 * @head: a pointer to linked list
 * Return: 0
 *
 */

int handle_cd(char **arv, env_t **head)
{
	char *homedir = NULL, *ld_pt = NULL, **env = NULL;

	env = lst_2_arr(*head);
	if (!arv[1])
	{
		homedir = get_env("HOME=", env);
		chdir(homedir);
		handle_pwd(homedir, env, head);
		free_ptr(env);
		return (1);
	}
	if (my_strcmp(arv[1], "-") == 0)
	{
		ld_pt = get_env("OLDPWD=", env);
		my_puts(ld_pt);
		handle_pwd(ld_pt, env, head);
		chdir(ld_pt);
		free_ptr(env);
		return (1);
	}
	if (chdir(arv[1]) < 0)
	{
		free_ptr(env);
		return (-1);
	}
	else
	{
		handle_pwd(arv[1], env, head);
		free_ptr(env);
		return (1);
	}
	return (127);
}

/**
 *  handle_pwd - a helpe func
 *  @path: path of working dir to change to
 *  @head: a pointer to the linked list
 *  @env: arr containing the env
 */

void handle_pwd(char *path, char **env, env_t **head)
{
	int nds = 0, sett = 0;
	char **ld_pt = NULL, **curr = NULL;

	ld_pt = malloc(sizeof(char *) * 4);
	ld_pt[0] = my_strdup("old");
	ld_pt[1] = my_strdup("OLDPWD");
	ld_pt[2] = my_strdup(get_env("PWD=", env));
	ld_pt[3] = NULL;
	curr = malloc(sizeof(char *) * 4);
	curr[0] = my_strdup("current");
	curr[1] = my_strdup("PWD");
	curr[2] = my_strdup(path);
	curr[3] = NULL;
	nds = arr_2_lst(head, env);
	if (!nds)
		return;
	sett = my_setenv(head, ld_pt, 2);
	if (sett < 0)
	{
		free_ptr(ld_pt);
		free_ptr(curr);
		return;
	}
	free_ptr(ld_pt);
	sett = my_setenv(head, curr, 2);
	if (sett < 0)
	{
		free_ptr(curr);
		return;
	}
	free_ptr(curr);
}
