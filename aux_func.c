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
void free_grid(char **grid)
{
	char **temp = NULL;

	temp = grid;

	if (!grid)
	{
		return;
	}
	while (*grid)
	{
		free(*grid++);
	}
	free(temp);
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

	while ((s1[i] && s2[i]) && s1[i] == s2[i])
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

/**
 * _strcpy - copy the string pointed to by src to the buffer pointed to by dest
 * @src: char pointer
 * @dest: char pointer
 * Return: No return.
 */

char *_strcpy(char *dest, char *src)
{
	int j = 0;
	int x;

	while (src[j])
	{
		j++;
	}
	for (x = 0; x <= j; x++)
	{
		dest[x] = src[x];
	}
	dest[x + 1] = '\0';
	return (dest);
}

/**
 * _strcat - returns the length of a string
 * @src: source array
 * @dest: destination array
 * Return: 0.
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int c = 0;

	while (dest[c])
	{
		c++;
	}

	for (i = 0; src[i]; i++)
	{
		dest[c + i] = src[i];
	}

	dest[c + i] = '\0';
	return (dest);
}
