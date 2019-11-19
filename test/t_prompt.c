#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;

	for (; av[i]; i++)
	{
		printf("argv[%2d]: %s\n", i, av[i]);
	}
	ac = 0;
	return(ac);
}
