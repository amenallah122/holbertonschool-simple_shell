#include "main.h"

int execute(char **input, char**argv)
{
    pid_t child;
    int status;

    child = fork();
    if (child == 0)
    {
        if (execve(input[0], input, environ) == -1)
        {
            perror(argv[0]);
            freearray(input);
            exit(0);
        }
    }
    else 
    {
        waitpid(child, &status,0);
        freearray(input);
    }
    return(WEXITSTATUS(status));
}