#include "my_shell.h"

/** This is the function that implements the cd (change directory) command */
void my_cd(char **args)
{
    /** Check if the second argument is NULL, which means no directory name is given */
    if (args[1] == NULL)
    {
        /** If so, print an error message using the custom my_printf function */
        my_printf("MDV shell: cd: missing argument\n");
    }
    else
    {
        /** If not, try to change the current working directory to the given directory name using the chdir function */
        if (chdir(args[1]) != 0)
        {
            /** If the chdir function returns a non-zero value, it means that the directory change failed */
            /** Print an error message using the perror function, which will show the reason for the failure */
            perror("MDV shell: cd");
        }
    }
}