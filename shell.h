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

extern char **environ;
#define MAX_INPUT_LEN 1024

/* Function prototypes */

void sh_print(const char *my_string);
int main(void);
char *_strdup(const char *str);
char *_strcat(char *dest, const char *src);
int _strcmp(char *str1, char *str2);
size_t _strlen(const char * strng);
size_t _strlen_const(const char * strng);
char *trimString(char *str);
char *find_path(char *cmd);
char *_strcpy(char *dest, const char *src);
char *_strncpy(char *dest, const char *src, int sz);
int _strncmp(const char *str1, const char *str2, size_t num);
char *get_environ(const char *env_var);
int handle_cmd(char *cmd_args);
void child_process_cmd(char *cmd, char *args[]);
void prompt(void);
void print_env(void);


#endif /* SHELL_H */
