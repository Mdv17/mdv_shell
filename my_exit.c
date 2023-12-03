#include "my_shell.h"

/** This is the function that implements the exit command */
void my_exit(char **args)
{
    /** Exit the program with a success status using the exit function */
    exit(0);
    (void)args; /* Add this line to avoid the unused parameter warning */
}        