#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* psh_read_line(void)
{
	size_t sz = 0;
	ssize_t len = 0;
	char *line = NULL;

	len = getline(&line, &sz, stdin);
	printf("$ %s", line);

	return (line);
}

char **
