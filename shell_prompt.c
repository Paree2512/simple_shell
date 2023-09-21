#include "shell.h"

/**
 * prompt - display shell prompt
 *
 * Return: Nothing
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		sh_print("$ ");
		fflush(stdout);
	}
}
