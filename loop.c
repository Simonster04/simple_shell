#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * psh_loop - Runs the simple shell process and calls every function needed
 *
 * Return: Doesn't return nothing
 */

void psh_loop(void)
{
	char **comms;
	char *len = NULL;
	int exec = 1;

	while (exec)
	{
		write(STDOUT_FILENO, "$ ", 2);
		len = psh_read_line();
		comms = psh_tokenize(len);
		exec = psh_execution(comms);
/*
		while (comms[i])
		{
			free(comms[i]);
			i++;
		}
*/
		free(len);
		free(comms);
	}
}
