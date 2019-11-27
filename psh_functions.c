#include "holberton.h"

/**
 * psh_read_line - reads a line from the standar inputa console
 *
 * Return: pointer to the allocated string
 */

char *psh_read_line(void)
{

	int i;
	ssize_t lineptr = 0;
	size_t sz = 0;
	char *line = NULL;

	lineptr = getline(&line, &sz, stdin);
	if (lineptr == EOF)
	{
		free(line);
		exit(0);

	}
	if (lineptr == -1)
	{
		free(line);
		exit(0);
	}
	for (i = 0; line[i]; i++)
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
		}
	}
	return (line);
}

/**
 * psh_tokenize - splits a string into different argumnets
 * @args: string with the arguments to be tokenize
 *
 * Return: double pointer of the arrays of strings
 */
char **psh_tokenize(char *args)
{
	int pos = 0, buff, buff2;
	char *len;
	char **line;

	buff = PSH_BUFF_SIZE;
	buff2 = PSH_BUFF_SIZE;
	line = malloc(buff * sizeof(char *));
	if (line == NULL)
	{
		perror("malloc");
		exit(1);
	}

	len = strtok(args, " \t\n\r");
	while (len)
	{
		line[pos] = len;
		pos++;
		len = strtok(NULL, " \t\n\r");
	}
	if (pos >= buff)
	{
		buff2 += PSH_BUFF_SIZE;
		line = _realloc(line, sizeof(char *) * buff, sizeof(char *) * buff2);
		if (line == NULL)
		{
			free(line);
			return (NULL);
		}
	}
	line[pos] = NULL;
	return (line);
}

/**
 * psh_execution - calls the builtin functions the simple shell has
 * @line: the commands it will execute
 *
 * Return: initializes the pid function process
 */

int psh_execution(char **line)
{
	int cont;
	char *builtin_cmd[] = {
		"cd",
		"help",
		"exit",
		"env"};

	int (*builtin_f[])(char **) = {
		&psh_cd,
		&psh_help,
		&psh_exit,
		&psh_env};

	if (line[0] == NULL)
	{
		return (1);
	}

	for (cont = 0; cont < 4; cont++)
	{
		if (_strcmp(line[0], builtin_cmd[cont]) == 0)
		{
			return ((*builtin_f[cont])(line));
		}
	}

	return (psh_init(line));
}

/**
 * psh_init - initialize a ppid and pid process
 * @line: the commands it will execute
 *
 * Return: 1 if the process worked correctly
 */

int psh_init(char **line)
{
	pid_t pid;
	char **dir_com = NULL;
	char *command = NULL;
	int status_w = 0;

	dir_com = add_slash();
	command = access_check(dir_com, line, command);
	pid = fork();
	if (pid == 0)
	{
		child(dir_com, line, command);
	}
	else if (pid < 0)
	{
		free_grid(dir_com);
		free_grid(line);
		perror("Error process failure");
	}
	else
	{
		do {
		waitpid(pid, &status_w, WUNTRACED);
		} while ((WIFEXITED(status_w) == 0) && (WIFSIGNALED(status_w) == 0));
		free_grid(dir_com);
	}
	return (1);
}

/**
 * child - initialize a ppid and pid process
 * @line: the commands it will execute
 * @dir_com: path with slash concatenated
 * @command: pointer command with path concatented
 * Return: void
 */

void child(char **dir_com, char **line, char *command)
{
	int i;

	for (i = 0; line[0][i]; i++)
	{
		if (line[0][i] == '/')
		{
			free_grid(dir_com);
			if (execve(line[0], line, environ) < 0)
			{
				perror("Command");
				free_grid(line);
				exit(0);
			}
			free(line);
		}
	}
	if (!command)
	{
		free_grid(dir_com);
		free_grid(line);
		perror("./hsh");
		exit(0);
	}
	if (execve(command, line, environ) < 0)
	{
		free_grid(line);
		free(command);
		free_grid(dir_com);
		perror("Error with execve");
		exit(0);
	}
	free(line);
	free_grid(dir_com);
}
