#include "holberton.h"
#include <stdlib.h>

/**
 * free_grid - function that frees
 * @height: rows
 * @grid: bidimensional malloc
 *
 * Return: void
 */

int (*psh_builtins(char *s))(int, int)
{
	builtins_t builtins[] = {
			{"help", psh_help},
			{"cd", psh_cd},
			{"exit", psh_exit},
			{NULL, NULL}
	};
	int i = 0;

	while (i < 4)
	{
		if (builtins[i].builtin[0] == *s)
		{
			return (builtins[i].f);
		}
		i++;
	}
	return (NULL);
}


int psh_cd(char **args)
{


}

int psh_help(char **args)
{
	int i;

	write(STDOUT_FILENO, "Tomás and Simón's Shell\n", 24);
	write(STDOUT_FILENO, "Check the following commands:\n",30);

	for (i = 0; i < )
}


int psh_exit(char **args)
{


}
