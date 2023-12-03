#include "my_shell.h"

/* This is the function that tokenizes the input into an array of strings */
char **tokenize(char *input)
{
    /* Declare all variables at the beginning of the function */
    int length = 0;
    int capacity = 16;
    int i; /* Declare a loop variable */
    char **tokens = malloc(capacity * sizeof(char*));
    char *delimiters = " \t\r\n"; /* Move the declaration of delimiters here */
    char *token;
    char **new_tokens;

    if (!tokens)
    {
        perror("MDV Shell$ ");
        exit(1);
    }

    /* Use input instead of line, since line is not defined */
    token = strtok(input, delimiters);
    while (token != NULL)
    {
        tokens[length] = token;
        length++;
        if (length >= capacity)
        {
            capacity = (int) (capacity * 1.5);
            new_tokens = malloc(capacity * sizeof(char*)); /* Move the declaration of new_tokens here */
            if (!new_tokens) {
                perror("MDV shell : Not enough memory");
                exit(1);
            }
            /* Use i instead of int i, since i is already declared */
            for (i = 0; i < length; i++) {
                new_tokens[i] = tokens[i];
            }

            /* Free the old array */
            free(tokens);

            /* Assign the new array to tokens */
            tokens = new_tokens;
        }

        /* Get the next token from the input */
        token = strtok(NULL, delimiters);
    }

    /* Add a NULL pointer at the end of the array */
    tokens[length] = NULL;
    /* Return the array of tokens */
    return tokens;
}