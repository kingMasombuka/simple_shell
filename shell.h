#ifndef SHELL_H
#define SHELL_H

#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/**
 * struct list_s - A single node linked list
 * @str: a charecter type
 * @next: moves to the next node in the list
 *
 * Description: A single linked list proto
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} env_t;
void handle_sigint(int sig);
int c(const char *str1, const char *str2, size_t n);
char **token_strtok(char *str, char delim);
void print_prompt(void);
int my_putchar(char c);
void print_exit_error(int *i, char *s, char **argv);
void print_main_error(char **av);
void print_cd_error(int *i, char *s, char **argv);
void my_puts(char *str);
int cmd_exec(char **input, char *s, int *i, env_t **head);
char **get_env_path(char *name, char **env);
char *find_path(char **s, char **env);
char *get_env(char *name, char **env);
int token_count(char *str, char delim);
void print_error(int *i, char *s, char **argv);
void print_env_error(char **argv);
int check_builtin_cmd(char *line, char **argv, char *progg_nme,
		int *i, env_t **head);
long int handle_exit(char **tokens);
int handle_env(char **arv, env_t **head);
int handle_cd(char **arv, env_t **head);
void handle_pwd(char *path, char **env, env_t **head);
int my_strcmp(char *s1, char *s2);
char *mystr_concat(char *s1, char *s2);
char *my_strstr(char *haystack, char *needle);
int my_strncmp(char *s1, char *s2, unsigned int n);
char *my_strdup(char *str);
void free_ptr(char **args);
char **prs_lne(char *line, int get);
int my_strlen(char *s);
char *my_strcpy(char *dest, char *src);
int my_unsetenv(env_t **head, char **argv);
int my_setenv(env_t **head, char **argv, int args);
void handle_setenv(char **argv, env_t **head, int *i, char *prog_name);
void print_setenv_error(int *i, char *s, char **argv);
char *convert_num_str(int num, int base);
long int atoi_(char *s);
size_t list_length(const env_t *h);
size_t prt_lst(env_t *h);
void fr_lst(env_t **head);
int arr_2_lst(env_t **head, char **env);
char **lst_2_arr(env_t *head);
env_t *add_node_at_end(env_t **head, char *str);
int node_at_index(env_t **head, char *str, int index);
int delete_index_node(env_t **head, unsigned int index);
int index_list_fnd(env_t *head, char *name);

#endif
