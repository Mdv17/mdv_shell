#include "my_shell.h"


/* This is the main function of the shell program*/
int main(int argc, char **argv)
{
    /* Declare all the variables at the beginning of the function */
    char *input;
    FILE *fp;
    ssize_t nchars_read; /* Use ssize_t instead of int */
    char *lineptr;
    size_t n;
    char **tokens;

    if (argc > 1)
    {
        fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            my_printf("Error opening file: %s\n", strerror(errno));
            return -1;
        }
        while ((nchars_read = getline(&lineptr, &n, fp)) != -1)
        {
            /* Split the line into tokens */
            tokens = tokenize(lineptr);
            if (tokens == NULL)
            {
                my_printf("Tokenization failed: %s\n", strerror(errno));
                exit(1);
            }
            /* Execute the input using tokens instead of lineptr */
            execute_input(tokens);
            /* Free the memory allocated by tokenize */
            free(tokens);
        }

        /*Close the file*/
        fclose(fp);
    }
    else
    {
        while (1)
        {
            display_prompt();
            input = my_read_line(); /* This function is now declared in the header file */
            if (input == NULL)
            {
                my_printf("Memory allocation failed: %s\n", strerror(errno));
                exit(1);
            }
            if (is_empty(input))
            {
                continue;
            }
            tokens = tokenize(input);
            if (tokens == NULL)
            {
                my_printf("Tokenization failed: %s\n", strerror(errno));
                exit(1);
            }
            if (tokens[0] != NULL)
            {    /*If so, execute the input*/
                execute_input(tokens);
            }

            /*Free the memory allocated by tokenize and my_read_line*/
            free(tokens);
            free(input);
        }
    }
    return 0;
}