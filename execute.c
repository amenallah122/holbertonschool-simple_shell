#include "shell.h"
int execute(char **input, char **argv)
{
	pid_t child;
	int status;
	char *command;

	command = _getpath(input[0]);
	if (!command)
	{
		fprintf(stderr, "%s:%s: not found\n", argv[0], input[0]);
		freearray(input);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(command, input, environ) == -1)
		{
			perror(argv[0]);
			freearray(input);
			free(command);
			exit(100);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearray(input);
		free(command);
	}
	return (WEXITSTATUS(status));
}
