#include "shell.h"
/**
 * is_built_in - ...
 * @input: input
 * Return: 0
*/
int is_built_in(char *input)

{
	char *built[] = {"exit", "env", NULL};
	int i;

	for (i = 0; built[i]; i++)
	{
		if (strcmp(input, built[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * handle_built_in - ...
 * @input: input
 * @status: status
 * Return: 0
*/
void handle_built_in(char **input, int *status)
{
	int i;

	if (strcmp(input[0], "exit") == 0)
	{
		freearray(input);
		exit(*status);
	}
	else if (strcmp(input[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			printf("%s\n", environ[i]);
		}
		freearray(input);
		(*status) = 0;
	}
}
