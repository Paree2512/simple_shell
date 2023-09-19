#include "shell.h"

/**
 * main - program entry point
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 * @env: array of environment variables
 *
 * Return: Always 0
 */

int main(int argc, char **argv, char **env)
{
	char *input;
	char **args;

	(void)argc;
	(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			sh_print("ALX_SimpleShell$> ");
			fflush(stdout);
		}

		input = read_string();
		args = splits_input(input);

		if (args[0] == NULL)
		{
			free(input);
			free(args);
			continue;
		}

		handle_builtin(args, env);

		free(input);
		free(args);
	}

	return (0);
}
