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

		process_cmd(input);
		free(input);
		input = NULL;
		input_size = 0;
	}

	return (0);
}
