#include "shell.h"

/**
 * handle_cmd - handles external shell commands
 * @args: array of arguments
 * @env: array of environment variables
 *
 * Return: None
 */

void handle_cmd(char **args, char **env)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(1);
	}

	if (child_pid == 0)
	{
		if (args[0][0] != '/' && find_path(args, env) != 0)
		{
			fprintf(stderr, "Command not found: %s\n", args[0]);
			exit(1);
		}
		if (execve(args[0], args, env) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else
	{
		int status;

		waitpid(child_pid, &status, 0);
	}
}
