#include "shell.h"
/**
 * freearray - frees arrays
 * @array: array to be freed
 * Return: 0
*/
void freearray(char **array)
{
	int i;

	if (array == NULL)
		return;
	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}

	free(array);
	array = NULL;
}
