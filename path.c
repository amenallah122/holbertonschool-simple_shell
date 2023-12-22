#include "shell.h"
/**
 * _getpath - function that gets the path
 * @input: command to get the path of
 * Return: 0
*/
char *_getpath(char *input)
{
	char *env, *path, *command;
	struct stat st;
	int i;

	for (i = 0; input[i]; i++)
	{
		if (input[i] == '/')
		{
			if (stat(input, &st) == 0)
				return (strdup(input));
			return (NULL);
		}
	}
	env = _getenv("PATH");
	if (env == (NULL))
		return (NULL);
	path = strtok(env, ":");
	while (path)
	{
		command = malloc(strlen(path) + strlen(input) + 2);
		if (command != (NULL))
		{
			snprintf(command, strlen(path) + strlen(input) + 2, "%s/%s", path, input);
			if (stat(command, &st) == 0)
			{
				free(env);
				return (command);
			}
			free(command);
			path = strtok((NULL), ":");
		}
		else
		{
			free(env);
			return (NULL);
		}
	}
	free(env);
	return (NULL);
}
