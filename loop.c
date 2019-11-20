#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void psh_loop(void)
{
	char **comms;
	char *len;
	int exec = 1;

	while(exec)
	{
		write(STDOUT_FILENO,"$ ", 2);
		len = psh_read_line();
		comms = psh_tokenize(len);
		exec = psh_execution(comms);

		free(len);
		free(comms);
	}


}

