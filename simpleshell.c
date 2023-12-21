#include "main.h"

int main(int ac, char **argv)
{
	char *line = NULL;
	char **input = NULL;
	int status=0;
	/*int i ;*/
	(void)ac;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n ", 1);
			}
			return (status);
		}
		
        input = tokenizer(line);  
        if (input == NULL)
            continue;

     /*for ( i = 0; input[i]; i++)
	   {
		printf("%s\n", input[i]);
		free(input[i]), input[i]= NULL;
	   }
	   free(input);*/

	   status = execute(input, argv);
	   
    }
}
