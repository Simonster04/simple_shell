#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


typedef struct builtins
{

	char *builtin;
	int (*f)(char **args);

} builtins_t;

int psh_cd(char **args);
int psh_help(char **args);
int psh_exit(char **args);


char* psh_read_line(void);
void psh_loop(void);
char **psh_tokenize(char *len);
int psh_execution(char **line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int psh_init(char **line);
void free_grid(int **grid);

#endif
