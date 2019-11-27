#ifndef HOLBERTON_H
#define HOLBERTON_H
#define _GNU_SOURCE

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PSH_BUFF_SIZE 64

extern char **environ;

char *access_check(char **splitpath, char **line, char *command);
char **getthepath(void);
char **add_slash(void);
int _strncmp(char *s1, const char *s2, int n);
void handle_sigint(int sig);
int psh_cd(char **args);
int psh_help(char **args);
int psh_exit(char **args);
int _putchar(char c);
char *psh_read_line(void);
void psh_loop(char **envp);
char **psh_tokenize(char *len);
int psh_execution(char **line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int psh_init(char **line);
void free_grid(char **grid);
int _strcmp(char *s1, char *s2);
int psh_env(char **args);
char **getpath(void);
char **complete_command(void);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
void *_calloc(unsigned int nmemb, unsigned int size);

#endif
