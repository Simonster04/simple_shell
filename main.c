#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */

int main(int ac, char **av, char **envp)
{
	write(STDOUT_FILENO, "\n\n\n**************************************\n", 42);
	write(STDOUT_FILENO, "\nWelcome to the best shell in the world\n", 40);
	write(STDOUT_FILENO, "\n**************************************\n\n\n", 42);

	psh_loop(envp);
	(void) av;
	ac = 0;

	return (ac);
}

