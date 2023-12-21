#include "shell.h"
char *_getpath(char *input)
{
	char *path_env, *full_cmd, *dir;
	int i;
	struct stat st;

	for (i = 0; input[i]; i++)
	{
		if (input[i] == '/')
		{
			if (stat(input, &st) == 0)
				return (strdup(input));
			return (NULL);
		}
	}

	path_env = _getenv("PATH");
	dir = strtok(path_env, ":");

	while (dir)
	{
		full_cmd = malloc(strlen(dir) + strlen(input) + 2);
		if (full_cmd)
		{
			strcpy(full_cmd, dir);
			strcat(full_cmd, "/");
			strcat(full_cmd, input);
			if (stat(full_cmd, &st) == 0)
			{
				free(path_env);
				return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
