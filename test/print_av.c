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
	int i = 0;

	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	argc = 0;

	return (argc);
}

