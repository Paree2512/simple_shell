#include "shell.h"

/**
 * trimString – trim whitespace from a string
 * @str: string to trim
 *
 * Return: pointer to trimmed string
 */

char *trimString(char *str)
{
	char *start = str;
	char *end = str + strlen(str) - 1;

	while (*start && (*start == ' ' || *start == '\t' || *start == '\n'))
	{
		start++;
	}

	if (*start == '\0')
	{
		return (start);
	}

	while (end > start && (*end == ' ' || *end == '\t' || *end == '\n'))
	{
		end--;
	}

	*(end + 1) = '\0';

	return (start);
}

/**
 * _strlen - function calculates the length of a null-terminated str
 * @strng: pointer to input string
 *
 * Return: String Length
 */

size_t _strlen(const char *strng)
{
	size_t length = 0;

	while (strng[length] != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * _strlen_const - function calculates the length of a null-terminated str
 * @strng: pointer to input string
 *
 * Return: String Length
 */

size_t _strlen_const(const char *strng)
{
	size_t length = 0;

	while (strng[length] != '\0')
	{
		length++;
	}

	return (length);
}
