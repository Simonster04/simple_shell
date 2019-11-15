#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main()
{
	size_t size = 0;
	ssize_t len = 0;
	char *line = NULL;

	while (len >= 0)
	{
		printf("$ ");
		len = (getline(&line, &size, stdin));
		printf("%s", line);


	/*When argv[1] == "exit"; perror and return -1*/


	}
	return (len);
}
