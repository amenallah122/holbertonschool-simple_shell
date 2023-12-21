#include "main.h"

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
