#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	size_t sz = 0;
	ssize_t len = 0;
	char *line = NULL;

	printf("$ ");
	len = getline(&line, &sz, stdin);
	printf("%s", line);

	return (0);
}
