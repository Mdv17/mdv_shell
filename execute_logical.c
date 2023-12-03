#include "my_shell.h"

/** This is the new function that handles the logical operators */
void execute_logical(const char *input)
{
    /* Declare all variables at the beginning of the function */
    char *buffer;
    char **commands;
    int num_commands = 0;
    char *buffer2;
    char **operators;
    int num_operators = 0;
    int i; /* Declare a loop variable */
    int status;
    char *temp; /* Declare the temporary pointer here */

    /* Copy the input string to a non-constant string */
    char *input_copy = strdup(input);
    if (!input_copy) {
        perror("MDV Shell$ ");
        exit(1);
    }

    /* Allocate memory for the array of commands */
    commands = malloc(sizeof(char *) * MAX_COMMANDS); /* MAX_COMMANDS is a constant that defines the maximum number of commands */
    if (!commands) {
        perror("MDV Shell$ ");
        exit(1);
    }

    /* Split the input into an array of commands */
    temp = strtok_r(input_copy, "&&||", &buffer); /* Use the temporary pointer to get the next token */
    while (temp != NULL && num_commands < MAX_COMMANDS) {
        commands[num_commands] = temp; /* Assign the token to the array element */
        num_commands++;
        temp = strtok_r(NULL, "&&||", &buffer); /* Get the next token */
    }
    commands[num_commands] = NULL; /* Add a NULL pointer at the end of the array */

    /* Allocate memory for the array of operators */
    operators = malloc(sizeof(char *) * MAX_OPERATORS); /* MAX_OPERATORS is a constant that defines the maximum number of operators */
    if (!operators) {
        perror("MDV Shell$ ");
        exit(1);
    }

    /* Split the input into an array of logical operators */
    temp = strtok_r(input_copy, " \t\r\n", &buffer2); /* Use the temporary pointer to get the next token */
    while (temp != NULL && num_operators < MAX_OPERATORS) {
        if (strcmp(temp, "&&") == 0 || strcmp(temp, "||") == 0) {
            operators[num_operators] = temp; /* Assign the token to the array element */
            num_operators++;
        }
        temp = strtok_r(NULL, " \t\r\n", &buffer2); /* Get the next token */
    }
    operators[num_operators] = NULL; /* Add a NULL pointer at the end of the array */

    /* Loop over the array of commands and execute each command */
    for (i = 0; i < num_commands; i++) {
        /* Execute the command and get the exit status */
        status = WEXITSTATUS(execute_input(&commands[i])); /* Pass the address of the command pointer as the parameter */
        /* Check if there is a next command and a logical operator */
        if (i < num_commands - 1 && i < num_operators) {
            /* Check the logical operator */
            if (strcmp(operators[i], "&&") == 0) {
                /* If the logical operator is &&, execute the next command only if the current command succeeds */
                if (status != 0) {
                    break;
                }
            }
            else if (strcmp(operators[i], "||") == 0) {
                /* If the logical operator is ||, execute the next command only if the current command fails */
                if (status == 0) {
                    break;
                }
            }
        }
    }
    free(input_copy);
    free(commands);
    free(operators);
}