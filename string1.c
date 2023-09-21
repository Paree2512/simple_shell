#include "shell.h"

/**
 * _strdup - creates duplicates of the input string
 * @src: pointer to the source string
 *
 * Return: pointer to the allocated duplicate string
 */

char *_strdup(const char *src)
{
	int len, i;
	char *dst;

	if (src == NULL)
		return (NULL);

	len = _strlen_const(src);

	if (len < 0)
		return (NULL);

	dst = (char *)malloc((len + 1) * sizeof(char));

	if (dst == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		dst[i] = src[i];
	}

	return (dst);
}

/**
 * _strcat – function concatenates two strings
 * @dest: char string to be concatenated to
 * @src: char string
 *
 * Return: concatenated string destination
 */

char *_strcat(char *dest, const char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - compare two strings
 * @str1: first string value
 * @str2: second string value
 *
 * Return: int value
 */

int _strcmp(char *str1, char *str2)
{
	int r;

	r = strcmp(str1, str2);

	if (r == 0)
		return (r);

	else if (r < 0)
		return (r);
	else
		return (r);
}
