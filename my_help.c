#include "my_shell.h"

/** This is the function that implements the help command */
void my_help(char **args)
{
    /** Define the help text as a constant string */
    char *helptxt =
        "MDV shell - the shell I created myself "
        "The following commands are built in:\n"
        "  cd       Change the working directory.\n"
        "  exit     Exit the shell.\n"
        "  help     Print this help text.\n"
        ;

    /** Print the help text using the custom my_printf function */
    my_printf("%s", helptxt);
    (void)args; /* Add this line to avoid the unused parameter warning */
}      