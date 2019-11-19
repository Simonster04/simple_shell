#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

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
	int pos = 0;
	char **line = malloc(sizeof(char*) * 64);

	if (line == NULL)
	{
		return (NULL);
	}
	args = strtok(len, " ");

	while (args)
	{
		line[pos] = args;
		pos++;
	}

	args = strtok(NULL, " ");
	line[pos] = NULL;

	return (line);
}

int psh_execution(**char line)
{
	int i = 0;

	if (line[0] == NULL || line[0] == EOF)
		return (1);

	return (psh_init(line));
}

int psh_init(char **line)
{
	pid_t pid;

