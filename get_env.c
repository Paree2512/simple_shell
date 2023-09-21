#include "shell.h"

/**
 * get_environ - get the value of an environment variable
 * @env_var: environment variable
 *
 * Return: pointer to the value of the env variable
 */

char *get_environ(const char *env_var)
{
	int i, len;
	char **env;
	char *value;

	if (!env_var)
		return (NULL);

	env = environ;

	for (i = 0; env[i]; i++)
	{
		for (len = 0; env[i][len] != '=';)
		{
			len++;
		}
		if (_strncmp(env_var, env[i], len) == 0)
		{

			value = &env[i][len + 1];
			return (value);
		}
	}

	return (NULL);
}
