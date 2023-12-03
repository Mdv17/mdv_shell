#ifndef BUILTINS_H
#define BUILTINS_H

#include <stddef.h>
#include <stdbool.h>

/* A builtin instance associates a command name with a handler function */
struct builtin
{
    char *name; /* the name of the builtin command */
    void (*func)(char **args); /* the pointer to the handler function */
};

extern struct builtin builtins[]; /* This tells the compiler that builtins is a global array defined in another file */
#endif /* BUILTINS_H */