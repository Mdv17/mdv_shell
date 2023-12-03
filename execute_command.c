#include "my_shell.h"

/* This is the function that executes the input from the user */
/* Change the function definition to match the declaration, or vice versa */
int execute_input(char **input) /* Change the parameter type from char * to char ** */
{
    /* Use the input parameter as a pointer to a pointer, instead of a pointer to a string */
    char **args = tokenize(*input); /* Dereference the input parameter to get the string */
    int i = 0;
    while (args[i] != NULL) {
        if (execute_arg(args[i]) == -1) {
            return -1;
        }
        i++;
    }
    return 0;
}