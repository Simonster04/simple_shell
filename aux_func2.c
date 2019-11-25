#include "holberton.h"
#include <stdio.h>

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

while (src[j] != '\0')
{
j += 1;
}

for (x = 0; x <= j; x++)
{
dest[x] = src[x];
}
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

while (dest[c] != '\0')
{
c += 1;
}

for (i = 0; src[i] != '\0'; i++)
{
dest[c + i] = src[i];
}

dest[c + i] = '\0';

return (dest);
}
