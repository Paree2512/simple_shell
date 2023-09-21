#include "shell.h"

/**
 * find_path - find the full path of a command
 * @cmd: command to search in full path
 *
 * Return: string containing the full path
 */

char *find_path(char *cmd)
{
	char *path, *full_path, *path_env = get_environ("PATH");
	size_t path_len, full_path_len, cmd_len;

	if (path_env == NULL)
	{
		return (NULL);
	}

	path = strtok(path_env, ":");
	while (path != NULL)
	{
		path_len = _strlen(path);
		cmd_len = _strlen(cmd);

		full_path_len = path_len + cmd_len + 2;

		full_path = malloc(full_path_len);
		if (full_path == NULL)
		{
			perror("malloc");
			return (NULL);
		}

		_strcpy(full_path, path);
		full_path[path_len] = '/';
		_strcpy(full_path + path_len + 1, cmd);

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}

		free(full_path);
		path = strtok(NULL, ":");
	}
	return (NULL);
}
