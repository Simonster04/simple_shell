#include "holberton.h"

/**
 * _strncpy - copies a string
 * @src: source array
 * @dest: destination array
 * @n: amount of bytes
 * Return: 0.
 */

char *_strncpy(char *dest, char *src, int n)
{

int i;

for (i = 0; i < n && src[i] != '\0'; i++)
{
dest[i] = src[i];
}
	while (i < n)
	{
	dest[i] = '\0';
	i++;
	}


return (dest);

}
