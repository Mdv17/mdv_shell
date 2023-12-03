#include "my_shell.h"

/* This is the function that handles the variable command */
void variable(const char *input)
{
    /* Tokenize the input by spaces */
    char **args = tokenize((char *) input); /* Add (char *) before input to cast it to char * */

    /* Initialize a variable to count the number of arguments */
    int arg_count = 0;

    /* Loop until the end of the arguments */
    while (args[arg_count] != NULL)
    {
        /* Increment the argument count */
        arg_count++;
    }

    /* Check if the argument count is valid */
    if (arg_count < 2 || arg_count > 3)
    {
        /* If not, print an error message and return */
        my_printf("Invalid number of arguments for variable command.\n");
        return;
    }

    /* Check if the second argument is a valid name */
    if (!is_valid_name(args[1]))
    {
        /* If not, print an error message and return */
        my_printf("Invalid name for variable.\n");
        return;
    }

    /* Check if the third argument is given */
    if (args[2] != NULL)
    {
        /* If so, add or update the variable with the given name and value */
        variable_add(args[1], args[2]);
    }
    else
    {
        /* If not, delete the variable with the given name */
        variable_delete(args[1]);
    }

    /* Free the arguments array */
    free(args);
}
