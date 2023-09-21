#include "shell.h"

/**
 * handle_cmd – Execute a command with arguments in a child process.
 * @cmd_args: The command with its arguments
 *
 * Description - This function executes a specified command
 * with its arguments in a child process using execve.
 * It handles errors during forking, command execution,
 * and file access, ensuring the command runs smoothly
 * in a child process while addressing potential issues
 *
 * Return: 0 on success, -1 on failure
 */

int handle_cmd(char *cmd_args)
{
	pid_t child_pid;
	int status, arg_count = 0;
	char *token, *args[MAX_INPUT_LEN / 2 + 2];

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (child_pid == 0)
	{

		token = strtok(cmd_args, " ");
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		child_process_cmd(args[0], args);
	}
	else
	{
		wait(&status);
	}
	return (0);
}

/**
 * child_process_cmd - execute a cmd in a child process with full /
 * @cmd: cmd to execute
 * @args: arguments for the cmd
 *
 * Description - This function runs a command in a child process via
 * execve, dealing with errors in command execution and file access
 *
 * Return: Nothing
 */

void child_process_cmd(char *cmd, char *args[])
{
	char *path = find_path(cmd);

	if (path != NULL)
	{
		if (execve(path, args, NULL) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	}
	else if (access(cmd, X_OK) == 0)
	{
		if (execve(cmd, args, NULL) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("./hsh");
		_exit(EXIT_FAILURE);
	}
}
