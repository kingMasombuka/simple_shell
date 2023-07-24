#include "shell.h"

/**
 * print_error - displays all custom err msg
* @i: indx of cmd
 * @s: program name
 * @argv: arr of args from the command line
 *
 */
void print_error(int *i, char *s, char **argv)
{
	char *bufone = NULL, *bufftow = NULL, *buffthree = NULL,
	     *buffor = NULL, *bufffive = NULL;
	char *num = NULL;

	num = convert_num_str(*i, 10);

	bufone = mystr_concat(s, ": ");
	bufftow = mystr_concat(bufone, num);
	free(bufone);
	buffthree = mystr_concat(bufftow, ": ");
	free(bufftow);
	buffor = mystr_concat(buffthree, argv[0]);
	free(buffthree);
	bufffive = mystr_concat(buffor, ": not found\n");
	free(buffor);
	write(2, bufffive, my_strlen(bufffive));
	free(bufffive);
}

/**
 * print_env_error - displays a custom err message for env builtin
 * @argv:  list  of arguments from the comline
 */
void print_env_error(char **argv)
{
	char *bufone = NULL, *bufftow = NULL, *buffthree = NULL;

	bufone = mystr_concat(argv[0], ": ");
	bufftow = mystr_concat(bufone, argv[1]);
	free(bufone);
	buffthree = mystr_concat(bufftow, ": No such file or directory\n");
	free(bufftow);
	write(2, buffthree, my_strlen(buffthree));
	free(buffthree);
	
}

/**
 * print_exit_error - displays a custom err msg for exit.
 * @i: idx of cmd in his.
 * @s: program name
 * @argv: arr of args from the cmd line
 */

void print_exit_error(int *i, char *s, char **argv)
{
	char *bufone = NULL, *bufftow = NULL, *buffthree = NULL;
	char *num = NULL;
	char *buffor = NULL, *bufffive = NULL, *buffsize = NULL, *buffseve = NULL;

	num = convert_num_str(*i, 10);

	bufone = mystr_concat(s, ": ");

	bufftow = mystr_concat(bufone, num);
	free(bufone);
	buffthree = mystr_concat(bufftow, ": ");
	free(bufftow);
	buffor = mystr_concat(buffthree, argv[0]);
	free(buffthree);
	bufffive = mystr_concat(buffor, ": Illegal number: ");
	free(buffor);
	buffsize = mystr_concat(bufffive, argv[1]);
	free(bufffive);
	buffseve = mystr_concat(buffsize, "\n");
	free(buffsize);
	write(2, buffseve, my_strlen(buffseve));
	free(buffseve);
}

/**
 * print_main_error - displays a custom err msg for main
 * @av: array of the args passed to the  main
 */

void print_main_error(char **av)
{
	char *bufone = NULL, *bufftow = NULL, *buffthree = NULL;

	bufone = mystr_concat(av[0], ": 0: Can't open ");
	bufftow = mystr_concat(bufone, av[1]);
	free(bufone);
	buffthree = mystr_concat(bufftow, "\n");
	free(bufftow);
	write(2, buffthree, my_strlen(buffthree));
	free(buffthree);
}

/**
 * print_cd_error - displays a custom err msg
 * @i: index of the cmd
 * @s: name of the program
 * @argv: array of arguments from the command line
 *
 */
void print_cd_error(int *i, char *s, char **argv)
{
	char *bufone = NULL, *bufftow = NULL, *buffthree = NULL, *buffor = NULL;
	char *bufffive = NULL, *buffsize = NULL;
	char *num = NULL;

	num = convert_num_str(*i, 10);

	bufone = mystr_concat(s, ": ");
	bufftow = mystr_concat(bufone, num);
	free(bufone);
	buffthree = mystr_concat(bufftow, ": ");
	free(bufftow);
	buffor = mystr_concat(buffthree, argv[0]);
	free(buffthree);
	bufffive = mystr_concat(buffor, ": can't cd to ");
	free(buffor);
	buffsize = mystr_concat(bufffive, argv[1]);
	free(bufffive);
	write(2, buffsize, my_strlen(buffsize));
	free(buffsize);
}
