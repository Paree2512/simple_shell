#include "shell.h"

/**
 * main - shell entry point
 *
 * Return: Always 0.
 */

int main(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t read_size;
	int result;

	while (1)
	{
		prompt();
		read_size = getline(&input, &input_size, stdin);
		if (read_size == -1)
		{
			free(input);
			return (0);
		}
		if (input[read_size - 1] == '\n')
			input[read_size - 1] = '\0';

		if (_strncmp(input, "exit", 4) == 0)
		{
			free(input);
			input = NULL;
			input_size = 0;
			exit(EXIT_SUCCESS);
		}

		if (_strcmp(trimString(input), "env") == 0)
		{
			print_env();
			continue;
		}

		if (read_size > 1)
		{
			result = handle_cmd(trimString(input));
			if (result == -1)
				break;
		}
	}
	free(input);
	return (0);
}
