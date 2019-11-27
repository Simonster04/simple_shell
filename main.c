#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 * @ac: amount of arguments entered
 * @av: array with entered arguments
 * @envp: array with characteristics of bash
 *
 * Return: Always 0.
 */

int main(int ac, char **av, char **envp)
{
	write(STDOUT_FILENO, "\n\n\n**************************************\n", 42);
	write(STDOUT_FILENO, "**************************************\n", 39);
	write(STDOUT_FILENO, "\nWelcome to the best shell in the world\n", 40);
	write(STDOUT_FILENO, "**************************************\n", 39);
	write(STDOUT_FILENO, "\n**************************************\n\n\n", 42);

	psh_loop(envp);
	(void)ac;
	(void)av;
	return (0);
}

