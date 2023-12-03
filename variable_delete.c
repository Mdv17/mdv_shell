#include "my_shell.h"

void variable_delete(char *name) {
    /** Declare all the variables at the beginning of the function */
    struct variable_node *temp;
    struct variable_node *prev;
    struct variable_node *curr;

    /** Check if the list is empty */
    if (variable_head == NULL) {
        my_printf("No variables found.\n");
        return;
    }
    /** Check if the head node matches the name */
    if (strcmp(variable_head->name, name) == 0) {
        /** Save the head node in a temporary variable */
        temp = variable_head;
        /** Move the head pointer to the next node */
        variable_head = variable_head->next;
        /** Free the memory of the temporary node */
        free(temp->name);
        free(temp->value);
        free(temp);
        return;
    }
    /** Initialize two pointers to traverse the list */
    prev = variable_head;
    curr = variable_head->next;
    /** Loop until the end of the list or a match is found */
    while (curr != NULL && strcmp(curr->name, name) != 0) {
        /** Move the pointers to the next nodes */
        prev = curr;
        curr = curr->next;
    }
    /** Check if a match is found */
    if (curr != NULL) {
        /** Save the current node in a temporary variable */
        temp = curr;
        /** Link the previous node to the next node */
        prev->next = curr->next;
        /** Free the memory of the temporary node */
        free(temp->name);
        free(temp->value);
        free(temp);
    }
    else {
        /** No match is found */
        my_printf("Variable not found.\n");
    }
}                                      