#include "shell.h"

char **tokenizer(char *line)
{
	char *token = NULL;
	char **commands = NULL;
	char *line_copy = NULL;
	int argc = 0;
	int i = 0;

	if (!line)
		return (NULL);
	line_copy = strdup(line);
	token = strtok(line_copy, DELIM);
	if (token == NULL)
	{
		free(line_copy), line_copy = NULL;
		free(line), line = NULL;
		return (NULL);
	}
	while (token)
	{
		argc++;
		token = strtok(NULL, DELIM);
	}
	free(line_copy	), line_copy = NULL;
	commands = malloc(sizeof(char *) * (argc + 1));
	if (!commands)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, DELIM);
	while (token)
	{
		commands[i] = strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line), line = NULL;
	commands[i] = NULL;
	return (commands);
}

