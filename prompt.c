#include "shell.h"

/**
 * my_putchar - display charestes to std output
 * @c: char to display
 *
 * Return: 1 on success.
 * On error,  and errno set -1 is returned.
 */
int my_putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * print_prompt - displays a prompt for  shell
 */
void print_prompt(void)
{
	char *input_prompt = " $ ";

	write(1, input_prompt, 2);
}

/**
 * my_puts - prints a string to standard output
 * @str: pointer to the string to print
 */
void my_puts(char *str)
{
	int x;

	for (x = 0; str[x] != '\0'; x++)
		my_putchar(str[x]);
	my_putchar('\n');
}
