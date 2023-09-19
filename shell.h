#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

/* Function prototypes */

int main(int argc, char **argv, char **env);
void sh_print(const char *my_string);
void print_env(char **env);
char *read_string(void);
char **splits_input(char *input);
int find_path(char **args, char **env);
char **path_dir(char **env);
void handle_cmd(char **args, char **env);
void handle_builtin(char **args, char **env);
void change_dir(char **args);

#endif /* SHELL_H */
