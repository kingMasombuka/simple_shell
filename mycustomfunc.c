#include "shell.h"

/**
 * my_strlen - length of a string returned
 * @s: string to process
 *
 * Return: the length of the string
 */
int my_strlen(char *s)
{
	int lenght = 0;

	if (!s)
		return (0);
	while (s[lenght])
		lenght++;
	return (lenght);
}

/**
 * *my_strcpy - cpy the str pointed to by src
 * and null byte (\0)
 * buffer in which we copy string
 * @src:  thestring to be copied
 * @dest: dest argument
 *
 * Return: the pointer to dest
 */
char *my_strcpy(char *dest, char *src)
{
	int length, x;

	length = 0;

	while (src[length] != '\0')
		length++;

	for (x = 0; x < length; x++)
		dest[x] = src[x];

	dest[x] = '\0';

	return (dest);
}
