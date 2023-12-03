#include "my_shell.h"

/** This is the function that handles the redirections */
void execute_redirect(char **cmd, char *symbol, char *file)
{
    /** Create a child process using fork */
    pid_t pid = fork();
    if (pid == 0) {
        /** Child process */

        /** Open the file with the given name and mode */
        int fd;
        if (strcmp(symbol, ">") == 0) {
            /** If the redirection symbol is >, open the file for writing and create it if it does not exist */
            fd = open(file, O_WRONLY | O_CREAT, 0644);
        }
        else if (strcmp(symbol, "<") == 0) {
            /** If the redirection symbol is <, open the file for reading */
            fd = open(file, O_RDONLY);
        }
        else {
            /** If the redirection symbol is invalid, print an error message and return */
            my_printf("Invalid redirection symbol.\n");
            return;
        }

        /** Duplicate the file descriptor fd to the standard input or output depending on the symbol */
        if (strcmp(symbol, ">") == 0) {
            /** If the redirection symbol is >, duplicate the file descriptor fd to the standard output, so that the output of the command will be written to the file */
            dup2(fd, STDOUT_FILENO);
        }
        else if (strcmp(symbol, "<") == 0) {
            /** If the redirection symbol is <, duplicate the file descriptor fd to the standard input, so that the input of the command will be read from the file */
            dup2(fd, STDIN_FILENO);
        }

        /** Close the file descriptor fd, as it is no longer needed after duplication */
        close(fd);

        /** Execute the command with its arguments using execvp, which will replace the current process image */
        execvp(cmd[0], cmd);
    }
    else {
        /** Parent process */

        /** Wait for the child process to finish */
        wait(NULL);
    }
}