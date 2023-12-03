#ifndef SHELL_H
#define SHELL_H

/* My header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>
#include <errno.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdbool.h>
#include "builtins.h"

/* Define the maximum number of commands and operators */
#define MAX_COMMANDS 10
#define MAX_OPERATORS 10

#define MAX_PATHS 100 /* Define the MAX_PATHS constant as 100, or any other value you want */

/* Declare the global variables using the extern keyword */
extern struct alias_node *alias_head; /* This tells the compiler that alias_head is a global variable defined in another file */
extern struct variable_node *variable_head; /* This tells the compiler that variable_head is a global variable defined in another file */
extern struct builtin builtins[]; /* This tells the compiler that builtins is a global array defined in another file */

/* This is the data structure for the alias nodes */
struct alias_node
{
    char *name; /* the alias name */
    char *value; /* the alias value */
    struct alias_node *next; /* the pointer to the next node */
};

/* this function handles the cd command */
void my_cd(char **args);

/* this function handles the help command */
void my_help(char **args);

/* this function handles the exit command */
void my_exit(char **args);

/* This is the data structure for the variable nodes */
struct variable_node {
    char *name; /* the variable name */
    char *value; /* the variable value */
    struct variable_node *next; /* the pointer to the next node */
};

/* My prototypes */

/* this function displays the prompt */
void display_prompt(void);

/* this function prints the input to the standard output */
void my_printf(const char *format, ...);

/* This is the declaration of execute_input function in my_shell.h */
int execute_input(char **input); /* Change the parameter type from char * to char ** */
/* this function reads the input from the user */
void read_user_input(char *input, size_t size);

/* this function handles the help command */
void my_help(char **args);

/* this function executes the redirection of input or output */
void execute_redirect(char **cmd, char *symbol, char *file);

/* this function executes the command from the path */
void execute_path(const char *input, char **args);

/* this function tokenizes the input into an array of strings */
char **tokenize(char *input);

/* this function reads the user input */
void read_user_input(char *input, size_t size);

/* this function executes the pipe between two commands */
void execute_pipe(char **cmd1, char **cmd2);

/* this function executes the commands separated by semicolon */
void execute_semicolon(const char *input);

/* this function executes the commands separated by logical operators */
void execute_logical(const char *input);

/* this function adds a new node to the alias list */
void alias_add(char *name, char *value);

/* this function deletes an existing node from the alias list */
void alias_delete(char *name);

/* this function prints the whole alias list */
void alias_print();

/* this function searches the alias list for a given alias name and returns the corresponding value */
char *replace_alias(char *name);

/* this function handles the alias command */
void alias(const char *input);

/* this function adds a new node to the variable list */
void variable_add(char *name, char *value);

/* this function deletes an existing node from the variable list */
void variable_delete(char *name);

/* this function prints the whole variable list */
void variable_print();

/* this function searches the variable list for a given variable name and returns the corresponding value */
char *replace_variable(char *name);

/* this function handles the variable command */
void variable(const char *input);

int is_valid_name(const char *name); /* Change the parameter type from char * to const char * */

/* Declare the execute_arg function in the header file, or define it in the source file */
int execute_arg(const char *arg); /* Change the return type from void to int */

/* A helper function to pad a string with a given character */
void mdv_pad(char *str, int len, char ch, int left);

/* A helper function to convert an integer to a string */
int mdv_itoa(int num, char *str, int base);

/* A helper function to convert a double to a string */
int mdv_dtoa(double num, char *str, int precision);

/* A helper function to reverse a string */
void mdv_reverse(char *str, int len);

/* This is the function that checks if a string is empty or not */
bool is_empty(char *str);

/* Read a single line of input from stdin. The return value is a string pointer
 which needs to be freed once we're finished with it. */
char *my_read_line();

#endif /*SHELL_H*/