#include "shell.h"

/**
 * find_path - looks for programs in the directories listed in PATH
 * @args: array of arguments including the program to look for
 * @env: array of env variables, including PATH
 *
 * Return: 0 if program exists , 1 otherwise
 */

int find_path(char **args, char **env)
{
	int i = 0;
	char full_path[256];
	char **path_dirs = path_dir(env);

	if (path_dirs == NULL)
	{
		return (1);
	}

	while (path_dirs[i] != NULL)
	{
		strcpy(full_path, path_dirs[i]);
		strcat(full_path, "/");
		strcat(full_path, args[0]);

		if (access(full_path, X_OK) == 0)
		{
			args[0] = strdup(full_path);
			free(path_dirs);
			return (0);
		}
		i++;
	}

	free(path_dirs);
	return (1);
}

/**
 * path_dir - extracts and splits the PATH environment
 * variable into directories
 * @env: array of environment variables
 *
 * Return: array of pointers to the split directories
 */

char **path_dir(char **env)
{
	int i;
	char **dirs, *token, *path = NULL;
	int idex = 0;

	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path = env[i] + 5;
			break;
		}
	}

	if (!path)
	{
		fprintf(stderr, "PATH environment variable not found.\n");
		return (NULL);
	}

	dirs = malloc(64 * sizeof(char *));
	if (!dirs)
	{
		perror("malloc");
		exit(1);
	}

	token = strtok(path, ":");
	while (token)
	{
		dirs[idex] = strdup(token);
		if (!dirs[idex])
		{
			perror("strdup");
			exit(1);
		}
		idex++;
		token = strtok(NULL, ":");
	}
	dirs[idex] = NULL;
	return (dirs);
}
