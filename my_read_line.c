#include <stddef.h>
#include "my_shell.h"

/* Read a single line of input from stdin. The return value is a string pointer
 which needs to be freed once we're finished with it. */
char *my_read_line()
{
    /* Declare all the variables at the beginning of the function */
    char *line = NULL;
    size_t buflen = 0;
    size_t num_whitespace = 0;
    int strlen; /* Use int instead of ssize_t */

    /* Read a line from the standard input */
    strlen = getline(&line, &buflen, stdin);

    /* Cast the num_whitespace variable to an int type */
    if ((int)num_whitespace == strlen)
    {
        /* Free the memory allocated by getline and return NULL */
        free(line);
        return NULL;
    }

    /* Remove the trailing newline character if present */
    if (line[strlen - 1] == '\n')
    {
        line[strlen - 1] = '\0';
    }

    /* Return the line */
    return line;
}