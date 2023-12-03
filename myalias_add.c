#include "my_shell.h"

/* This is the function that adds a new node to the list */
void alias_add(char *name, char *value) {
    /* Allocate memory for the new node */
    struct alias_node *new_node = malloc(sizeof(struct alias_node));
    /* Check if the allocation was successful */
    if (new_node == NULL) {
        /* If not, print an error message and exit */
        perror("MDV shell: You do not have enough memory");
        exit(1);
    }
    /* Copy the name and value to the new node */
    new_node->name = strdup(name);
    new_node->value = strdup(value);
    /* Check if the copying was successful */
    if (new_node->name == NULL || new_node->value == NULL) {
        /* If not, free the allocated memory and exit */
        free(new_node);
        perror("MDV");
        exit(1);
    }
    /* Insert the new node at the beginning of the list */
    new_node->next = alias_head; /* Use alias_head instead of variable_head */
    alias_head = new_node; /* Use alias_head instead of variable_head */
}                 