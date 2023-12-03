#include "my_shell.h"

struct variable_node *variable_head = NULL; /* This defines and initializes variable_head as a global variable */

/* This is the function that adds a new node to the variable list */
void variable_add(char *name, char *value)
{
    struct variable_node *new_node = malloc(sizeof(struct variable_node));
    /* Check if the allocation was successful */
    if (new_node == NULL) {
        /* If not, print an error message and exit */
        perror("MDV shell: Not enough memory");
        exit(1);
    }
    /* Copy the name and value to the new node */
    new_node->name = strdup(name);
    new_node->value = strdup(value);
    /* Check if the copying was successful */
    if (new_node->name == NULL || new_node->value == NULL) {
        /* If not, free the allocated memory and exit */
        free(new_node);
        perror("MDV Shell: Error!");
        exit(1);
    }
    /* Insert the new node at the beginning of the list */
    new_node->next = variable_head;
    variable_head = new_node;
}