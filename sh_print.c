#include "shell.h"

/**
 * sh_print - prints strings to the standard output
 * @my_string: string to be printed
 */

void sh_print(const char *my_string)
{
	write(STDOUT_FILENO, my_string, strlen(my_string));
}
