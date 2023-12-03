#include "my_shell.h"

/** This is the function that executes the command and its arguments by searching the PATH environment variable */
/* This is the function that executes the command and its arguments by searching the PATH environment variable */
void execute_path(const char *input, char **args)
{
    /** Declare the loop variable before the for loop */
    int i;

    /** Split the PATH environment variable into an array of paths */
    char *buffer;
    char **paths = malloc(sizeof(char*) * MAX_PATHS); /* MAX_PATHS is a constant that defines the maximum number of paths */
    int num_paths = 0;
    paths[num_paths] = strtok_r(getenv("PATH"), ":", &buffer);
    while (paths[num_paths] != NULL) {
        num_paths++;
        paths[num_paths] = strtok_r(NULL, ":", &buffer);
    }

    /** Loop over the array of paths and append the input to each path */
    for (i = 0; i < num_paths; i++) {
        /* Check if the path already ends with a slash */
        if (paths[i][strlen(paths[i]) - 1] != '/') {
            /* If not, append a slash to the path */
            strcat(paths[i], "/");
        }
        /* Append the input to the path */
        strcat(paths[i], input);
    }

    /** Execute the command using the paths */
    execvp(paths[0], args); /* Pass the args parameter to the execvp function */
}