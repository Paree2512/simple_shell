#include "shell.h"

/**
 * print_env - prints environment variables to std output
 * @env: array of environment variables
 *
 * Return: None
 */

void print_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		sh_print(env[i]);
		sh_print("\n");
		i++;
	}
}
