#include "holberton.h"
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

/**
 * psh_loop - Runs the simple shell process and calls every function needed
 *
 * Return: Doesn't return nothing
 */

void psh_loop(char **envp)
{
	char **comms;
	char *len = NULL, *path = NULL;
	int exec = 1, i, j;
	char *username = "USER=";

	signal(SIGINT, handle_sigint);

	while (exec)
	{
		for (i = 0; envp[i]; i++)
		{
			for (j = 0; j < 5; j++)
              		{
				if (username[j] != envp[i][j])
					{break; }
				while(envp[i][j + 5])
				{
					_putchar(envp[i][j + 5]);
					j++;
				}
			}
		}
		write(STDOUT_FILENO, "$ ", 2);
		len = psh_read_line();
		comms = psh_tokenize(len);
		exec = psh_execution(comms);

		free(len);
		free(comms);
	}
}

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: elements
 * @size: size bytes
 *
 * Return: pointer to the allocated memory
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{

	char *p = NULL;
	unsigned int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	p = malloc(nmemb * size);
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (nmemb * size); i++)
	{
		p[i] = 0;
	}

	return (p);
}

void handle_sigint(int sig)
{
	char *username = "USER=";
	int i, j;

	(void)sig;
	_putchar('\n');
	for (i = 0; environ[i]; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (username[j] != environ[i][j])
			{break; }
			while(environ[i][j + 5])
			{
				_putchar(environ[i][j + 5]);
				j++;
			}
		}
	}
	write(STDOUT_FILENO, "$ ", 2);
}

