#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM " " 
char **tokenizer(char *line)
{
	char *token = NULL;
	char *line_copy = NULL;
	char **command = NULL;
	int argc = 0, i = 0;

	if (line == NULL)
		return NULL;

	line_copy = strdup(line);
	token = strtok(line_copy, DELIM);

	if (token == NULL)
	{
		free(line_copy);
		line_copy = NULL;
		return NULL;
	}

	while (token)
	{
		argc++;
		token = strtok(NULL, DELIM);
	}
	free(line_copy);
	line_copy = NULL;

	command = malloc(sizeof(char *) * (argc + 1));

	if (command == NULL)
	{
		free(line);
		line = NULL;
		return NULL;
	}

	token = strtok(line, DELIM);
	while (token)
	{
		command[i] = strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}

	free(line);
	line = NULL;
	command[i] = NULL;

	return command;
}

int main(void)
{
	char *test = "Hello I am Chaima";
	char **commands;
	
	commands = tokenizer(test);
	return 1;
}
