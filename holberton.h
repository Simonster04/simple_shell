#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char* psh_read_line(void);
void psh_loop(void);
char **psh_tokenize(char *len);
int psh_execution(char **line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int psh_init(char **line);
void free_grid(int **grid);

#endif
