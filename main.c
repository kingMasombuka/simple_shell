#include "shell.h"

/**
* cmd_exec -  executes all thr given commands
* @input: array of args from stdin
* @s: program name
* @i: inx of err
* @head: list containing env
* Return: 0 on failure, return to main loop with 1 on success
*/

int cmd_exec(char **input, char *s, int *i, env_t **head)
{
	struct stat file_stats;
	int stas = 0;
	char *complete_comand = NULL, **env = NULL;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		print_error(i, s, input);
		free_ptr(input);
		exit(EXIT_SUCCESS);
	}
	if (child_pid == 0)
	{
		env = lst_2_arr(*head);
		if (get_env("PATH=", env)[0] != '/')
			execve(input[0], input, env);
		complete_comand = find_path(input, env);
		if (!complete_comand && !stat(input[0], &file_stats))
		{
			if (execve(input[0], input, env) == -1)
			{
				print_error(i, s, input);
				free_ptr(input), free_ptr(env);
				return (0);
			}
			free_ptr(input);
			free_ptr(env);
		}
		if (execve(complete_comand, input, env) == -1)
		{
			print_error(i, s, input);
			free(complete_comand), free_ptr(input), free_ptr(env);
			exit(EXIT_SUCCESS);
		}
	}
	else
		wait(&stas);
	free_ptr(input), free_ptr(env);
	return (1);
}

/**
 * main - cmd line arg
 * prints andwaits for  user to input  command,
 * and it creates a child process in which it exececutes the command
 * @ac: number of args
 * @av: array of args
 *
 * Return:For success,always 0
 */
int main(int ac, char *av[])
{
	size_t lenght = 0;
	char **input = NULL, *programe_nam = av[0], *line = NULL;
	int commandln_c = 0, gltln;
	env_t *head = NULL;

	if (ac != 1)
	{
		print_main_error(av);
		exit(127);
	}
	signal(SIGINT, handle_sigint);
	arr_2_lst(&head, environ);
	while (1)
	{
		if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
			print_prompt();
		gltln = getline(&line, &lenght, stdin);

		if (gltln < 0)
		{
			if (isatty(STDIN_FILENO) != 0 && isatty(STDOUT_FILENO) != 0)
				my_putchar('\n');
			break;
		}
		commandln_c++;
		if (my_strcmp(line, "\n") == 0)
			continue;
		input = prs_lne(line, gltln);
		if (!input)
			continue;
		if (check_builtin_cmd(line, input, programe_nam, &commandln_c, &head))
		{
			free_ptr(input);
			continue;
		}
		if (!cmd_exec(input, programe_nam, &commandln_c, &head))
			break;
	}
	fr_lst(&head), free(line);
	return (0);
}
