#include <stddef.h>
#include "my_shell.h"

/** This is the function that searches the list for a given alias name and returns the corresponding value */
char *replace_alias(char *name)
{
    /** Initialize a pointer to traverse the list from the head node */
    struct alias_node *curr = alias_head;

    /** Loop until the end of the list or a match is found */
    while (curr != NULL && strcmp(curr->name, name) != 0)
    {
        /** Move the pointer to the next node */
        curr = curr->next;
    }

    /** Check if a match is found */
    if (curr != NULL)
    {
        /** If so, return the value of the current node, which is the alias value */
        return curr->value;
    }
    else
    {
        /** If not, return the original name, which means there is no alias for it */
        return name;
    }
}