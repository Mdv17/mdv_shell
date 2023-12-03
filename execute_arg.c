#include "my_shell.h"

/* This is the function that executes a single argument entered by the user */
/* Change the function definition to match the usage, or vice versa */
int execute_arg(const char *arg) /* Change the return type from void to int */
{
    /* Check if the argument is a built-in command, such as exit, cd, or echo */
    if (strcmp(arg, "exit") == 0) {
        /* If the argument is exit, terminate the program */
        exit(0);
    }
    else if (strcmp(arg, "cd") == 0) {
        /* If the argument is cd, change the current working directory to the home directory */
        chdir(getenv("HOME"));
        return 0; /* Return 0 to indicate success */
    }
    else if (strcmp(arg, "echo") == 0) {
        /* If the argument is echo, print the rest of the arguments to the standard output */
        char *buffer;
        char *token = strtok_r(NULL, " ", &buffer); /* Get the next token after echo */
        while (token != NULL) {
            printf("%s ", token); /* Print the token with a space */
            token = strtok_r(NULL, " ", &buffer); /* Get the next token */
        }
        printf("\n"); /* Print a newline */
        return 0; /* Return 0 to indicate success */
    }
    else {
        /* If the argument is not a built-in command, try to execute it as an external command using the execute_path function */
        execute_path(arg, NULL); /* Pass the argument and NULL as the parameters */
        return 0; /* Return 0 to indicate success */
    }
}