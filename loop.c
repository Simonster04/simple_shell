#include "holberton.h"

/**
 * psh_loop - Runs the simple shell process and calls every function needed
  * Return: Doesn't return nothing
 */

void psh_loop(void)
{
	char **comms;
	char *len;
	int exec = 1;

	while (exec)
	{
		signal(SIGINT, handle_sigint);
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "($) ", 4);
		}

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

/**
 * handle_sigint - replaces ctrl+c
 * @sig: comodin.
 *
 * Return: void.
 */

void handle_sigint(int sig)
{
	(void)sig;
	_putchar('\n');
	write(STDOUT_FILENO, "($) ", 4);
}
