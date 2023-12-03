#include "my_shell.h"

struct alias_node *alias_head = NULL; /* This defines and initializes alias_head as a global variable */

/** This is the function that prints the whole list */
void alias_print()
{

    /* Declare all the variables at the beginning of the function */
    struct alias_node *curr;

    /* Check if the list is empty */
    if (alias_head == NULL) {
        my_printf("No aliases found.\n");
        return;
    }
    /* Initialize a pointer to traverse the list */
    curr = alias_head;
    /* Loop until the end of the list */
    while (curr != NULL) {
        /* Print the name and value of the current node */
        my_printf("%s=%s\n", curr->name, curr->value);
        /* Move the pointer to the next node */
        curr = curr->next;
    }
}