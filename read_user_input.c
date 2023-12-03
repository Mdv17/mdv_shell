#include "my_shell.h"

/* This is the function that reads the user input from the standard input */
void read_user_input(char *input, size_t size)
{
    /* If the user input is NULL */
    if (fgets(input, size, stdin) == NULL)
    {
        /* If the end of file (feof) of the standard input is reached */
        if (feof(stdin))
        {
            /* Print a new line and exit with success status */
            my_printf("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            /* If there is an error reading the input, print an error message and exit with failure status */
            my_printf("Error reading input.\n");
            exit(EXIT_FAILURE);
        }
    }
    /* Remove the new line character in the input string */
    input[strcspn(input, "\n")] = '\0';
}