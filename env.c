#include "shell.h"

/**
 * print_env - print environment variables
 *
 * Return: Nothing
 */

void print_env(void)
{
	int i;
	char **env = environ;

	for (i = 0; env[i]; i++)
	{
		sh_print(env[i]);
		sh_print("\n");
	}
}
