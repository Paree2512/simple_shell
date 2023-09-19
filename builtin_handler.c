#include "shell.h"

/**
 * handle_builtin - handles built-in shell commands
 * @args: array of arguments
 * @env: array of environment variables
 *
 * Return: None
 */

void handle_builtin(char **args, char **env)
{
	if (args[0] == NULL)
	{
		return;
	}

	if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		change_dir(args);
	}
	else
	{
		handle_cmd(args, env);
	}
}

/**
 * change_dir - changes the current working directory
 * @args: array of arguments
 *
 * Return: None
 */

void change_dir(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "cd: missing argument\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
}
