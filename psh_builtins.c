#include "holberton.h"
#include <stdlib.h>

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

	write(STDOUT_FILENO, "Tomás and Simón's Shell\n", 24);
	write(STDOUT_FILENO, "Those are our built-in commands:\n", 33);
	write(STDOUT_FILENO, "> cd\n> help\n> exit\n", 19);

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

	write(STDOUT_FILENO, "USER=" getenv("USER"), 13);

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

	return (0);
}
