#include "shell.h"

/**
 * handle_sigint - dont exit when Ctrl-C
 * @sig: this is nedded for sig to work
 * Return:0
 */

void handle_sigint(int sig)
{
	(void)sig;
	my_putchar('\n');
	print_prompt();
	fflush(stdout);
}
/**
* prs_lne - takes care of the newline char if found,then parses the input line
* @line: line read from stdin
* @get: the size of line returned from getline
*
* Return: parsed line
*/

char **prs_lne(char *line, int get)
{
	char **comm = NULL;

	if (line[get - 1] == '\n')
		line[get - 1] = '\0';
	comm = token_strtok(line, ' ');

	return (comm);
}

/**
 * free_ptr - free arr of str
 * @args: arr of str 2 free
 * Return:0
 */

void free_ptr(char **args)
{
	int x;

	if (!args)
		return;

	for (x = 0; args[x]; x++)
		free(args[x]);

	free(args);
}

