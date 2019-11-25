#include "holberton.h"

extern char **environ;

/**
 * getthepath - splits the path in different tokens
 *
 * Return: a list of directories
 */

char **getthepath()
{
	int i, j;
	char *path = NULL, *token, *name = "PATH=";
	char **splitpath = NULL;

	path = malloc(1024 * sizeof(char));
	if (path == NULL)
	{
		free(path);
		perror("malloc str");
	}
	splitpath = malloc(1024 * sizeof(char *));
	if (splitpath == NULL)
	{
		free(path);
		perror("Directories allocation");
	}
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, 5) == 0)
		{
			_strcpy(path, environ[i]);
			token = strtok(path, ":");
			for (j = 0; token; j++)
			{
				splitpath[j] = token;
				token = strtok(NULL, ":");
			}
			splitpath[j] = NULL;
			free(path);
			return (splitpath);
		}
	}
	perror("The path was not found");
	free(splitpath);
	return (0);
}

/**
 * add_slash - add an slash at the end of each directory
 *
 * Return: a list of directories with slash at the end
 */

char **add_slash(void)
{
	int i;
	char *path = NULL;
	char **splitpath;
	char **dir_com = NULL;

	splitpath = getthepath();
	dir_com = _calloc(1024, sizeof(char));
	if (dir_com == NULL)
	{return (NULL); }
	path = malloc(sizeof(char) * 500);
	if (path == NULL)
	{
		free(path);
		free(splitpath);
		return (NULL);
	}
	for (i = 0; splitpath[i]; i++)
	{
		_strcpy(path, splitpath[i]);
		_strcat(path, "/");
		dir_com[i] = malloc(sizeof(char) * 1024);
		_strcpy(dir_com[i], path);
	}
	free(path);
	free(splitpath);
	return (dir_com);
}

/**
 * access_check - determines whether a file can be accessed
 * @splitpath: path splited through doubledot
 * @line: tokens took from stdin
 * @command: space for the command
 *
 * Return: the command with the correct path
 */

char *access_check(char **splitpath, char **line, char *command)
{
	int i;

	for (i = 0; splitpath[i]; i++)
	{
		_strcat(splitpath[i], line[0]);
		if (access(splitpath[i], X_OK) > -1)
		{
			command = splitpath[i];
			return (command);
		}
	}
	free_grid(splitpath);
	return (NULL);
}

/**
 * _strncmp - compares n bytes of 2 strings
 * @s1: first string
 * @s2: second string
 * @n: number of chars to be compared
 *
 * Return: 0
 */

int _strncmp(char *s1, const char *s2, int n)
{
	int i = 0, dif = 0;

	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			dif = s1[i] - s2[i];
			break;
		}
	i++;
	}
	return (dif);
}
