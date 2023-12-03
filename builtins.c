#include "my_shell.h"
#include "builtins.h"

/* Define and initialize the builtins array */
struct builtin builtins[] =
{
    {"help", my_help},
    {"exit", my_exit},
    {"cd", my_cd},
}; /* This defines and initializes builtins as a global array */