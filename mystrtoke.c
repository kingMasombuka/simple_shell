#include "shell.h"

/**
 * token_count - counts toknss
 * @str: string to tokenize
 * @delim: charecter delimeter between tokens
 *
 * Return: number of tokens
 */
int token_count(char *str, char delim)
{
	int number = 0, x;
	int flg = 0;

	for (x = 0; str[x]; x++)
	{
		if (str[x] == delim)
		{
			flg = 0;
		}
		else if (flg == 0)
		{
			flg = 1;
			number++;
		}
	}
	return (number);
}

/**
* token_strtok - conv string to array of tokens
* @str: str to toknize
* @delim: delim between the tokens
*
* Return: pointer to the arr of strings  or NULL on failure on success
*/
char **token_strtok(char *str, char delim)
{
	char *stringcopy = NULL, **tokninpt = NULL;
	int i = 0, x = 0, ln = 0, ttltokns = 0;

	if (str == 0 || *str == 0)
		return (NULL);
	ttltokns = token_count(str, delim);
	if (ttltokns == 0)
		return (NULL);
	tokninpt = malloc(sizeof(char *) * (ttltokns + 1));
	if (tokninpt == NULL)
		return (NULL);
	while (*str && i < ttltokns)
	{
		if (*str == delim)
			str++;
		else
		{
			stringcopy = str;
			while (*str != delim && *str)
			{
				ln++;
				str++;
			}
			tokninpt[i] = malloc(sizeof(char) * (ln + 1));
			if (!tokninpt[i])
				return (NULL);
			while (*stringcopy != delim && *stringcopy && *stringcopy != '\n')
			{
				tokninpt[i][x] = *stringcopy;
				stringcopy++;
				x++;
			}
			tokninpt[i][x] = '\0';
			i++;
			x = 0;
			ln = 0;
		}
	}
	tokninpt[i] = NULL;
	return (tokninpt);
}
