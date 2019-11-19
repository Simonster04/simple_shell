#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define PSH_BUFF_SIZE 64


int psh_init(char **line);

char* psh_read_line(void)
{
	size_t sz = 1024;
	char *line = NULL;

	line = malloc(sizeof(char) * sz);
	getline(&line, &sz, stdin);

	return (line);
}

char **psh_tokenize(char *args)
{
	char *len = NULL;
	int pos = 0, buff = PSH_BUFF_SIZE, buff2 = 0;
	char **line = malloc(sizeof(char*) * buff);

	if (line == NULL)
	{
		return (NULL);
	}

	len = strtok(args, " ");
	while (len)
	{
		line[pos] = len;
		pos++;
		len = strtok(NULL, " ");
	}
	if (pos >= buff)
	{
		buff2 = buff + PSH_BUFF_SIZE;
		line = _realloc(line, sizeof(char*) * buff, sizeof(char*) * buff2);
		if (line == NULL)
		{
		return (NULL);
		}
	}

	line[pos] = NULL;
	return (line);
}

int psh_execution(char** line)
{
	if (line[0] == NULL)
		return (1);

	return (psh_init(line));
}

int psh_init(char **line)
{
	pid_t pid;
	int status_w = 0;

	pid = fork();
	if (pid == 0)
	{
		if (execve(line[0], line, NULL) < 0)
		{
			perror("Error with execve");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error process failure");
	}
	else
	{
		do {
		waitpid(pid, &status_w, WUNTRACED);
		}
		while ((WIFEXITED(status_w) == 0) && (WIFSIGNALED(status_w) == 0));
	}
	return (1);
}

