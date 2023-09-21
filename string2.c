#include "shell.h"

/**
 * _strcpy - this function copies the string pointed to by src
 * @dest: pointer to the buffer where the string is copied
 * @src: string to be copied
 *
 * Return: pointer to dest
 */

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strncpy - copies string
 * @dest: first string value
 * @src: second string value
 * @sz: size
 *
 * Return: dest
 */

char *_strncpy(char *dest, const char *src, int sz)
{
	int i;

	for (i = 0; i < sz && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for (; i < sz; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}

/**
 * _strncmp - compares two strings and returns their difference
 * @str1: first string
 * @str2: second string
 * @num: number of bytes to compare
 * Return: 0
 */

int _strncmp(const char *str1, const char *str2, size_t num)
{
	size_t i;

	for (i = 0; i < num; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		if (str1[i] == '\0')
			return (0);
	}
	return (0);
}
