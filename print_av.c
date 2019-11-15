#include <stdio.h>
#include <string.h>

/**
 * main - Entry point
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	char *token;
	char *saveptr = *argv;

/*	token = strtok_r(saveptr, " ", &saveptr);
*/	while (*argv)
	{	token = strtok_r(saveptr, " ", &saveptr);

		printf("%s\n", token);
	}
token = strtok_r(NULL, " ", &saveptr);
	argc = 0;
	return (argc);
}

