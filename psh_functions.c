#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define PSH_BUFF_SIZE 1024
extern char **environ;

int psh_init(char **line);

/**
 * psh_read_line - reads a line from the standar inputa console
 *
 * Return: pointer to the allocated string
 */

char *psh_read_line(void)
{

	int i;
	ssize_t lineptr = 0;
	size_t sz = 0;
	char *line = NULL;

	line = malloc(sizeof(char) * sz);
	if (line == NULL)
	{
		return (NULL);
	}

	lineptr = getline(&line, &sz, stdin);
	if (lineptr == EOF)
	{
		free(line);
		exit (0);
	}
	if (lineptr == -1)
	{
		free(line);
		exit(0);
	}
	for (i = 0; line[i]; i++)
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
		}
	}
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
	char *len;
	int pos = 0, buff = PSH_BUFF_SIZE;/* buff2 = PSH_BUFF_SIZE;*/
	char **line;

	line = malloc(sizeof(char *) * buff);
	if (line == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	len = strtok(args, " \t\n\r");
	while (len)
	{
		line[pos] = len;
		pos++;
		len = strtok(NULL, " \t\n\r");
	}
/*	if (pos >= buff)
	{
		buff2 += PSH_BUFF_SIZE;
		line = _realloc(line, sizeof(char *) * buff, sizeof(char *) * buff2);
		if (line == NULL)
		{
			free(line);
			return (NULL);
		}
	}
*/	line[pos] = NULL;
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
		"exit",
		"env"};

	int (*builtin_f[])(char **) = {
		&psh_cd,
		&psh_help,
		&psh_exit,
		&psh_env};

	if (line[0] == NULL)
	{
		return (1);
	}

	for (cont = 0; cont < 4; cont++)
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
	char **dir_com = NULL;
	char *command = NULL;
	int status_w = 0, i;

	dir_com = add_slash();
	command = access_check(dir_com, line, command);

	pid = fork();
	if (pid == 0)
	{
		for (i = 0; line[0][i]; i++)
		{
			if (line[0][i] == '/')
			{
				free_grid(dir_com);
				if (execve(line[0], line, NULL) == -1)
				{
					perror("Command");
					free_grid(line);
					exit(0);
				}
				free(line);
			}
		}
		if (execve(command, line, NULL) < 0)
		{
			free_grid(line);
			free_grid(dir_com);
			free(command);
			perror("Error with execve");
			exit(0);
		}
	}
	else if (pid < 0)
	{
		free(line);
		free_grid(dir_com);
		perror("Error process failure");
	}
	else
	{
		do {
		waitpid(pid, &status_w, WUNTRACED);
		} while ((WIFEXITED(status_w) == 0) && (WIFSIGNALED(status_w) == 0));

		free_grid(dir_com);
	}
	return (1);
}

