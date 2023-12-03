#include <stddef.h>
#include "my_shell.h"

/** This is the function that handles the alias command */
void alias(const char *input)
{
    char **args;
    int arg_count = 0;
    char *equal_sign;
    char *name;
    char *value;

    /* Copy the input string to a non-const pointer */
    char *input_copy = strdup(input);
    if (!input_copy) {
        perror("MDV Shell$ ");
        exit(1);
    }

    /* Tokenize the input by spaces */
    args = tokenize(input_copy); /* Pass the non-const pointer to the tokenize function */

    /* Loop until the end of the arguments */
    while (args[arg_count] != NULL) {
        arg_count++;
    }
    /* If no arguments are given, print the whole list */
    if (arg_count == 1) {
        alias_print();
    }
    /* If one argument is given, print the value of the alias or add a new alias */
    else if (arg_count == 2) {
        /* Check if the argument contains an equal sign */
        equal_sign = strchr(args[1], '=');
        if (equal_sign != NULL) {
             /* Split the argument into name and value */
            name = strtok(args[1], "=");
            value = strtok(NULL, "=");
            /* Add a new alias to the list */
            alias_add(name, value);
        }
        else {
            /* Print the value of the alias */
            my_printf("%s\n", replace_alias(args[1]));
        }
    }
    /* If two arguments are given, check if the first one is -d */
    else if (arg_count == 3) {
        /* Check if the first argument is -d */
        if (strcmp(args[1], "-d") == 0) {
            /* Delete the alias with the given name */
            alias_delete(args[2]);
        }
        else {
            /* Invalid argument */
            my_printf("Invalid argument.\n");
        }
    }
    else {
        /* Too many arguments */
        my_printf("Too many arguments.\n");
    }

    /* Free the arguments array and the input copy */
    free(args);
    free(input_copy);
}