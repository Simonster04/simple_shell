#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int psh_cd(char **args);
int psh_help(char **args);
int psh_exit(char **args);
int _putchar(char c);
char *psh_read_line(void);
void psh_loop(char **envp);
char **psh_tokenize(char *len);
int psh_execution(char **line, char **envp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int psh_init(char **line, char **envp);
void free_grid(int **grid);
int _strcmp(char *s1, char *s2);
int psh_env(char **args);
char **getpath(char **envp);
char *_strncat(char *dest, char *src, int n);
char **concat(char *len, char *path);
char **complete_command(char **envp);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
