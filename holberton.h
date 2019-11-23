#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;


typedef struct builtins
{

	char *builtin;
	int (*f)(char **args);

} builtins_t;

int psh_cd(char **args);
int psh_help(char **args);
int psh_exit(char **args);
int _putchar(char c);
char *psh_read_line(void);
void psh_loop(int ac, char **av, char **env);
char **psh_tokenize(char *len, char *delim);
int psh_execution(char **line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int psh_init(char **line);
void free_grid(int **grid);
int _strcmp(char *s1, char *s2);
int psh_env(char **args);
char *psh_getenv(const char *name, char **env);
list_t *add_node(list_t **head, const char *str);



#endif
