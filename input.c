#include "shell.h"

/**
 * read_string - reads text from the standard input
 *
 * Return: pointer to the allocated string
 */

char *read_string(void)
{
	char *buffer = NULL;
	size_t bufsize = 0, index = 0;
	int c;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));

	if (!buffer)
		exit(1);

	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			buffer[index] = '\0';
			break;
		}
		buffer[index] = c;

		if (++index >= bufsize)
		{
			bufsize += BUFFER_SIZE;
			buffer = (char *)realloc(buffer, bufsize * sizeof(char));

			if (!buffer)
				exit(1);
		}
	}
	return (buffer);
}

/**
 * splits_input - splits an input string into an array of arguments
 * @input: input string to split
 *
 * Return: array of pointers to the split arguments
 */

char **splits_input(char *input)
{
	char **args = malloc(64 * sizeof(char *));
	char *token;
	int idex = 0;

	if (!args)
	{
		perror("malloc");
		exit(1);
	}

	token = strtok(input, " \t\n");
	while (token != NULL)
	{
		args[idex] = strdup(token);

		if (!args[idex])
		{
			perror("strdup");
			exit(1);
		}
		idex++;
		token = strtok(NULL, " \t\n");
	}
	args[idex] = NULL;
	return (args);
}
