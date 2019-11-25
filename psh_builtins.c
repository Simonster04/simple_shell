#include "holberton.h"
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

/**
 * psh_cd - Returns to the main repository
 * @args: double pointer indicating the arrays of directions
 *
 * Return: 1 for succesfull operation
 */

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

/**
 * psh_help - find more about the functions built within the shell
 * @args: double pointer indicating the structure where commands are stored
 *
 * Return: 1 for succesfull operation
 */

int psh_help(char **args)
{
	(void) args;

	write(STDOUT_FILENO, "Tomás and Simón's Shell\n", 26);
	write(STDOUT_FILENO, "Those are our built-in commands:\n", 33);
	write(STDOUT_FILENO, "> cd\n> help\n> exit\n", 19);

	return (1);
}

/**
 * psh_exit - Exits the simple shell
 * @args: double pointer indicating the structure where commands are stored
 *
 * Return: 0 on success
 */
int psh_exit(char **args)
{
	(void) args;
	/* necesita un free??*/
	return (0);
}

int psh_env(char **args)
{
	int i, j;
	(void) args;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
		{
			_putchar(environ[i][j]);
		}
		_putchar('\n');
	}
	return (1);
}

