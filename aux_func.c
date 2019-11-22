#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using
 * @old_size: initial size
 * @new_size: needed size
 * @ptr: pointer
 *
 * Return: pointer to the allocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *my_realloc = NULL;
	unsigned int loop, final_size;

	if (new_size == old_size)
	{
		return (ptr);
	}
	else if (new_size > old_size)
	{
		final_size = old_size;
	}
	else
	{
		final_size = new_size;
	}
	if (new_size == 0 && ptr != '\0')
	{
		free(ptr);
		return (NULL);
	}
	my_realloc = malloc(new_size);
	if (ptr == NULL)
	{
		return (my_realloc);
	}
	if (my_realloc == NULL)
	{
		free(ptr);
		return (NULL);
	}
	for (loop = 0; loop < final_size; loop++)
	{
	my_realloc[loop] = ((char *)ptr)[loop];
	}
	free(ptr);
	return (my_realloc);
}

/**
 *free_grid - frees an array of pointers
 *@grid: array of pointers
 *
 *Return: Always
 */
void free_grid(int **grid)
{
int a;

	if (grid == NULL)
		{
		return;
		}
	for (a = 0; grid; a++)
	{
		free(grid[a]);
	}
	free(grid);
}

/**
 * _strcmp - compare two strings
 * @s1: array
 * @s2: array
 *
 * Return: 15 if first is bigger, 0 or -15.
 */

int _strcmp(char *s1, char *s2)
{

int i = 0;

while ((s1[i] != '\0' && s2[i] != '\0') && s1[i] == s2[i])
	{
	i++;
	}

	if (s1[i] == s2[i])
	{
	return (0);
	}

	else
	{
	return (s1[i] - s2[i]);
	}
}
