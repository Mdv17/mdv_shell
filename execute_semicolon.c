#include "my_shell.h"

#define MAX_PATHS 100 /* Define the MAX_PATHS constant as 100, or any other value you want */

/** This is the function that handles the semicolons */
void execute_semicolon(const char *input)
{
    /** Split the input into an array of commands separated by semicolon */
    char *buffer;
    char *token; /* Declare a char * variable to store the return value of strtok_r */
    int i; /* Declare the loop variable before the for loop */
    int num_commands = 0;
    token = strtok_r((char *)input, ";", &buffer); /* Cast the input to a char * and assign it to token */
    while (token != NULL) {
        num_commands++;
        token = strtok_r(NULL, ";", &buffer); /* Assign the next token to token */
    }

    /** Loop over the array of commands and execute each command using the execute_input function */
    for (i = 0; i < num_commands; i++) {
        token = strtok_r(NULL, ";", &buffer); /* Get the next token from the buffer */
        execute_input(&token); /* Use &token instead of token, and cast it to a char ** */
    }
}