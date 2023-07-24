#include "shell.h"

/**
 * atoi_ - converts str to  int
 * @s: str to be converted
 * Return: int from string
 */

long int atoi_(char *s)
{
	int x, digit, lenght, k;
	long int n;

	x = 0;
	n = 0;
	lenght = my_strlen(s);
	k = 0;
	digit = 0;

	if (s[x] == '+')
		x++;

	while (x < lenght && k == 0)
	{
		if (s[x] == '-')
			return (-1);

		if (s[x] >= '0' && s[x] <= '9')
		{
			digit = s[x] - '0';
			n = n * 10 + digit;
			k = 1;
			if (s[x + 1] < '0' || s[x + 1] > '9')
				break;
			k = 0;
		}
		x++;
	}

	if (k == 0)
		return (0);

	if (n > INT_MAX || n < 0)
		return (-1);

	return (n);
}

/**
 * convert_num_str - converts int and base to str
 * @num: given int
 * @base: base
 * Return: int to str
 */
char *convert_num_str(int num, int base)
{
	static char *exa_rep = "0123456789";
	static char buff[50];
	char *point = NULL;

	point = &buff[49];
	*point = '\0';
	do {
		*--point = exa_rep[num % base];
		num /= base;
	} while (num != 0);

	return (point);
}
