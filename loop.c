#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void psh_loop(void)
{
	char **comms;
	char *len;
	int exec = 0;

	while(1)
	{
		write(1,"$ ", 2);
		len = psh_read_line();
		comms = psh_tokenize(len);
		exec = psh_execution(comms);

		free(len);
		free(comms);
	}


}

