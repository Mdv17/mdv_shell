#include "my_shell.h"

/* This is the function that checks if a string is empty or not */
bool is_empty(char *str) {
    /* Declare the loop variable before the for loop */
    int i;
    /* Loop over the string and check if it contains any non-whitespace characters */
    for (i = 0; str[i] != '\0'; i++) {
        /* If the character is not a whitespace, return false */
        if (!isspace(str[i])) {
            return false;
        }
    }
    /* If the loop ends, it means the string is empty or only contains whitespace, return true */
    return true;
}