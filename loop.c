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

void psh_loop(int ac, char **av, char **env)
{
	char **comms, **token;
	char *len = NULL, *delim = " \n";
	int exec = 1;
	list_t *head = NULL;
	char *get_path = psh_getenv("PATH", env);

	token = psh_tokenize(get_path, ":");
	make_nodes(token, &head);




	while (exec)
	{
		write(STDOUT_FILENO, "$ ", 2);
		
		len = psh_read_line();
		comms = psh_tokenize(len, delim);
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
