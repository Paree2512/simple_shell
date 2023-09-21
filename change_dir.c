#include "shell.h"

/**
 * change_dir - function changes the current working directory
 * @path: path to the directory to change to
 *
 * Return: Nothing
 */

void change_dir(char *path)
{
	char *oldpwd = getenv("PWD");
	char *newpwd;

	if (path == NULL || path[0] == '\0')
	{
		path = getenv("HOME");
	}

	else if (strcmp(path, "-") == 0)
	{
		path = getenv("OLDPWD");
	}

	if (chdir(path) != 0)
	{
		perror("chdir");
		return;
	}

	newpwd = getcwd(NULL, 0);

	if (newpwd != NULL)
	{
		setenv("OLDPWD", oldpwd, 1);
		setenv("PWD", newpwd, 1);
		free(newpwd);
	}
	else
	{
		perror("getcwd");
	}
}
