#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define PSH_BUFF_SIZE 64

int psh_init(char **line);

/**
 * psh_read_line - reads a line from the standar inputa console
 *
 * Return: pointer to the allocated string
 */

char *psh_read_line(void)
{
	size_t sz = 1024;
	char *line = NULL;
	int i;
	ssize_t lineptr;

	line = malloc(sizeof(char) * sz);
	if (line == NULL)
	{
		free(line);
		perror("malloc");
		/*sera q se utiliza exit mejor*/
		return (NULL);
	}

	lineptr = getline(&line, &sz, stdin);
	if (lineptr == 0)
	{
/*
		while (line)
		{
			free(&line[pos]);
			pos++;
		}*/
		free(line);
		return (NULL);
	}
	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
		}
	}
/*
	free(line);
*/
	return (line);
}

/**
 * psh_tokenize - splits a string into different argumnets
 * @args: string with the arguments to be tokenize
 *
 * Return: double pointer of the arrays of strings
 */
char **psh_tokenize(char *args)
{
	char *len = NULL;
	int pos = 0, buff = PSH_BUFF_SIZE, buff2 = PSH_BUFF_SIZE;
	char **line = malloc(sizeof(char *) * buff);

	if (line == NULL)
	{
		free(line);
		return (NULL);
	}

	len = strtok(args, " ");
	do {
		line[pos] = len;
		pos++;
		len = strtok(NULL, " ");
	} while (len);
	if (pos >= buff)
	{
		buff2 += PSH_BUFF_SIZE;
		line = _realloc(line, sizeof(char *) * buff, sizeof(char *) * buff2);
		if (line == NULL)
		{
			free(line);
			return (NULL);
		}
	}

	line[pos] = NULL;
	return (line);
}

/**
 * psh_execution - calls the builtin functions the simple shell has
 * @line: the commands it will execute
 *
 * Return: initializes the pid function process
 */
int psh_execution(char **line)
{
	int cont;
char *builtin_cmd[] = {
		"cd",
		"help",
		"exit"};

int (*builtin_f[])(char **) = {
		&psh_cd,
		&psh_help,
		&psh_exit};

	if (line[0] == NULL)
	{
	/*posible free del doble puntero line*/
		return (1);
	}

	for (cont = 0; cont < 3; cont++)
	{
		if (_strcmp(line[0], builtin_cmd[cont]) == 0)
		{
			return ((*builtin_f[cont])(line));
		}
	}

	return (psh_init(line));
}

/**
 * psh_init - initialize a ppid and pid process
 * @line: the commands it will execute
 *
 * Return: 1 if the process worked correctly
 */
int psh_init(char **line)
{
	pid_t pid;
	int status_w = 0, i;

	pid = fork();
	if (pid == 0)
	{
		if (execve(line[0], line, NULL) < 0)
		{
			free(line);
			perror("Error with execve");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		for (i = 0; line; i++)
		{
			free(line[i]);
		}
		free(line);
		perror("Error process failure");
	}
	else
	{
		do {
		waitpid(pid, &status_w, WUNTRACED);
		} while ((WIFEXITED(status_w) == 0) && (WIFSIGNALED(status_w) == 0));
	}
	return (1);
}

