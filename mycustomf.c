#include "shell.h"

/**
* my_strdup - copies string and allocates memory
* @str:  the string to copy
*
* Return:  NULL on failure ,new string on success
*/

char *my_strdup(char *str)
{
	char *srtdup = NULL;
	int x, s = 0;

	if (!str)
		return (NULL);

	while (str[s])
		s++;

	srtdup = malloc(sizeof(char) * s + 1);

	if (!srtdup)
		return (NULL);

	for (x = 0; x < s; x++)
		srtdup[x] = str[x];

	srtdup[x] = '\0';

	return (srtdup);
}

/**
 * mystr_concat - concat strings,
 * @s1: string onr to concat
 * @s2: string two to concat
 *
 * Return: pointer to the string created on success, or NULL on failure
 */
char *mystr_concat(char *s1, char *s2)
{
	char *str3 = NULL;
	unsigned int i = 0, v = 0, lnthree = 0, ln2 = 0;

	lnthree = my_strlen(s1);
	ln2 = my_strlen(s2);

	str3 = malloc(sizeof(char) * (lnthree + ln2 + 1));
	if (str3 == NULL)
		return (NULL);

	i = 0;
	v = 0;

	if (s1)
	{
		while (i < lnthree)
		{
			str3[i] = s1[i];
			i++;
		}
	}

	if (s2)
	{
		while (i < (lnthree + ln2))
		{
			str3[i] = s2[v];
			i++;
			v++;
		}
	}
	str3[i] = '\0';

	return (str3);
}

/**
 * my_strcmp - compare 2 str
 * @s1: str 2 compare
 * @s2: str  2 compare
 *
 * Return: 0 if s1 == s2equal less than 0 if s1 < than s2,
 * more
 */
int my_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
* my_strncmp - compare str up to n byt
* @s1: str to compare against
* @s2: str to compare from
* @n: nummber of byt 2 compare
*
* Return:  non-zero if they are the same 0 if the strings are different,
*/
int my_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int d = 0;

	while (*s1 == *s2 && d < n)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
		d++;
	}
	return (d != n);
}
