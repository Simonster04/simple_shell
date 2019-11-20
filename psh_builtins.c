#include "holberton.h"
#include <stdlib.h>

int psh_cd(char **args)
{

	if (args[1] == NULL)
	{
		perror("\"cd\" needs an argument");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("chdir fails");
		}
	}
	return (1);
}

int psh_help(char **args)
{
	(void) args;

	write(STDOUT_FILENO, "Tomás and Simón's Shell\n", 24);
	write(STDOUT_FILENO, "Those are our built-in commands:\n", 33);
	write(STDOUT_FILENO, "> cd\n> help\n> exit\n", 19);

	return (1);
}


int psh_exit(char **args)
{
	(void) args;

	return (0);
}
