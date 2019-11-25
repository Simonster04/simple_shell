#include "holberton.h"

char **getpath(char **envp)
{
	char *path = "PATH=";
	char *aux = NULL, *len;
	char **path_split = NULL;
	int i, j;

	aux = malloc(1024 * sizeof(char));
        if (aux == NULL)
        {
                perror("allocation (aux)");
        }

	path_split = malloc(1024 * sizeof(char *));
	if (path_split == NULL)
	{
		perror("allocation (paths)");
	}

	for (i = 0; envp[i]; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (path[j] != envp[i][j])
			{
				break;
			}

			if (j == 5)
			{
				break;
			}
		}
	}
	_strcpy(aux, envp[i]);

	len = strtok(aux, ":");
	for (j = 0; len; j++)
	{
		path_split[j] = len;
		len = strtok(NULL, ":");
	}
	path_split[j] = NULL;

	free(aux);
	return (path_split);
}

char **complete_command(char **envp)
{
	int i;
	char *path;
	char **ptr, **slash_command = NULL;

	ptr = getpath(envp);
	path = malloc(sizeof(char) * 1024);
	if (path == NULL)
		{return (NULL); }
	slash_command = malloc(1024 * sizeof(char *));
	if (slash_command == NULL)
		{return (NULL); }

	i = 0;
	while (ptr[i] != NULL)
	{
		_strncpy(path, ptr[i], sizeof(ptr[i]));
		_strcat(path, "/");
		slash_command[i] = malloc(sizeof(char) * 1024);
		_strcpy(slash_command[i], path);
		i++;
	}

	free(ptr[0]);
	free(ptr);
	free(path);
	return (slash_command);
}
