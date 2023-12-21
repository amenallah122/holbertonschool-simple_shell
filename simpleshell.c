#include "shell.h"

int main(int ac, char **argv)
{
	char *line = NULL;
	char **input = NULL;
	int status = 0;
	int idx = 0;
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
		idx++;
		input = tokenizer(line);
		if (input == NULL)
			continue;

		if (is_built_in(input[0])==1)
			handle_built_in(input,&status);
		else
			status = execute(input, argv, idx);
	}
}
