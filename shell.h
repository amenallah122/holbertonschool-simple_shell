#ifndef AHLA_NEES
#define AHLA_NEES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"
extern char **environ;

char *read_line(void);
char **tokenizer(char *line);
void freearray(char **array);
int execute(char **input, char **argv, int idx);
char *_getpath(char *input);
char *_getenv(char *variable);


#endif