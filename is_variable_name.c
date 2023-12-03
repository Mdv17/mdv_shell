#include "my_shell.h"

/* This is a function that checks if a name is valid for a variable */
int is_valid_name(const char *name) /* Change the parameter type from char * to const char * */
{
    /* Declare a loop variable at the beginning of the function */
    int i;

    /* Check if the first character is a letter or an underscore */
    if (!isalpha(name[0]) && name[0] != '_') {
        return 0; /* Return 0 if not */
    }

    /* Loop over the rest of the characters and check if they are alphanumeric or underscores */
    for (i = 1; name[i] != '\0'; i++) {
        if (!isalnum(name[i]) && name[i] != '_') {
            return 0; /* Return 0 if not */
        }
    }

    /* Return 1 if all the characters are valid */
    return 1;
}