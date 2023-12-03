#include "my_shell.h"

/** This is the function that searches the list for a given variable name and returns the corresponding value */
char *replace_variable(char *name)
{
    /** Initialize a pointer to traverse the list from the head node */
    struct variable_node *curr = variable_head;

    /** Loop until the end of the list or a match is found */
    while (curr != NULL && strcmp(curr->name, name) != 0)
    {
        /** Move the pointer to the next node */
        curr = curr->next;
    }

    /** Check if a match is found */
    if (curr != NULL)
    {
        /** If so, return the value of the current node, which is the variable value */
        return curr->value;
    }
    else
    {
        /** If not, return the original name, which means there is no variable for it */
        return name;
    }
}