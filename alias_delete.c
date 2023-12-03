#include "my_shell.h"

/** This is the function that deletes an existing node from the list */
void alias_delete(char *name) {
    /** Declare the pointers before any statements */
    struct alias_node *temp;
    struct alias_node *prev;
    struct alias_node *curr;
    /** Check if the list is empty */
    if (alias_head == NULL) {
        my_printf("No aliases found.\n");
        return;
    }
    /** Check if the head node matches the name */
    if (strcmp(alias_head->name, name) == 0) {
        /** Save the head node in a temporary variable */
        temp = alias_head;
        /** Move the head pointer to the next node */
        alias_head = alias_head->next;
        /** Free the memory of the temporary node */
        free(temp->name);
        free(temp->value);
        free(temp);
        return;
    }
    /** Initialize the pointers to traverse the list */
    prev = alias_head;
    curr = alias_head->next;
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
        my_printf("Alias not found.\n");
    }
}