#include "my_shell.h"

/* This is the function that prints the whole list of variables */
void variable_print() {
    /* Declare all the variables at the beginning of the function */
    struct variable_node *curr; /* Move the declaration of curr here */
    /* Check if the list is empty */
    if (variable_head == NULL) {
        /* If so, print a message and return */
        my_printf("No variables found.\n");
        return;
    }
    /* Initialize a pointer to traverse the list */
    curr = variable_head; /* Assign the value of variable_head to curr */
    /* Loop until the end of the list */
    while (curr != NULL) {
        /* Print the name and value of the current node */
        my_printf("%s=%s\n", curr->name, curr->value);
        /* Move the pointer to the next node */
        curr = curr->next;
    }
}