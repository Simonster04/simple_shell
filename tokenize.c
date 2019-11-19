#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>






/**
 * main - PID
 *
 * Return: Always 0.
 */
int (/*int ac, char **av*/)
{
	size_t size = 0;
	ssize_t len = 0;
	char *line = NULL, *piece = NULL;

	while (len >= 0)
	{
		printf("$ ");
		len = (getline(&line, &size, stdin));
		piece = strtok(line, " ");
		while (piece)
		{
			printf("%s -", piece);
			piece = strtok(NULL, " ");
		}
	}
	return (0);
}


