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

void psh_loop(char **envp)
{
	char **comms, **path_command;
	char *len = NULL, *path = NULL;
	int exec = 1, i, j, lenu;
	char *username = "USER=";

	while (exec)
	{
		if (isatty(STDIN_FILENO))
		{
			for (i = 0; envp[i]; i++)
			{
				for (j = 0; j < 5; j++)
                       		{
					if (username[j] != envp[i][j])
					{
						break;
					}
					while(envp[i][j + 5])
					{
						_putchar(envp[i][j + 5]);
						j++;
					}
				}
			}


			write(STDOUT_FILENO, "$ ", 2);
		}

		len = psh_read_line();
		comms = psh_tokenize(len);
		exec = psh_execution(comms, envp);

		free(len);
		free(comms);
	}
}
