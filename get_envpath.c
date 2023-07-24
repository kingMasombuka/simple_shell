#include "shell.h"

/**
 * c - returns the value of a env variable
 * @str1: env key to check arr
 * @str2:  arr of str containing env copy
 *@n:varrable
 * Return: value of name in env
 */
int c(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
	}

	return (0);
}

/**
 * get_env - returns the value of a env variable
 * @name: env key to check arr
 * @env: arr of str containing env copy
 *
 * Return: value of name in env
 */

char *get_env(char *name, char **env)
{
	int x;

	for (x = 0; env[x]; x++)
		if (c(env[x], name, my_strlen(name)) == 0)
			return (env[x] + my_strlen(name));
	return (NULL);
}

/**
 * get_env_path - changes the PATH str in an arr of st.
 * @name: key to select in env varr
 * @env: it contains array of strings containing the environment copy
 *
 * Return: value at key, in the form of an array of strings
 */

char **get_env_path(char *name, char **env)
{
	char **val = NULL, **pth = NULL;
	int i;

	for (i = 0; env[i]; i++)
	{
		pth = token_strtok(env[i], '=');
		if (my_strcmp(name, pth[0]) == 0)
		{
			val = token_strtok(pth[1], ':');
			free_ptr(pth);
			return (val);
		}
		else
			free_ptr(pth);
	}
	free_ptr(pth);
	free_ptr(val);
	return (NULL);
}
/**
 * find_path -  function to connecting drectty in PATH with input cmd
 * tand check if executable
 * @s: input, in form array of strs
 * @env: array of strings containing the environment copy
 *
 * Return:  NULL on failure, concatenated string on success
 */

char *find_path(char **s, char **env)
{
	int i;
	char *drectty = NULL;
	char *progr_nm = NULL;
	char **v_of_pth = NULL;

	v_of_pth = get_env_path("PATH", env);
	if (!v_of_pth)
	{
		free_ptr(v_of_pth);
		return (NULL);
	}

	for (i = 0; v_of_pth[i]; i++)
	{
		drectty = mystr_concat(v_of_pth[i], "/");
		progr_nm = mystr_concat(drectty, s[0]);

		if (access(progr_nm, X_OK) == 0)
		{
			free_ptr(v_of_pth);
			free(drectty);
			return (progr_nm);
		}
		free(drectty);
		free(progr_nm);
	}
	free_ptr(v_of_pth);
	return (NULL);
}
