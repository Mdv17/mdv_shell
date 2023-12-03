#include "my_shell.h"

/** This is the function that handles the pipes */
void execute_pipe(char **cmd1, char **cmd2)
{
    /** Declare all the variables at the beginning of the function */
    int fd[2];
    pid_t pid, pid2;

    /** Create a pipe with two file descriptors: one for reading and one for writing */
    pipe(fd);

    /** Create a child process for the first command */
    pid = fork();
    if (pid == 0) {
        /** Child process */

        /** Close the file descriptor for reading from the pipe, as it is not needed */
        close(fd[0]);

        /** Duplicate the file descriptor for writing to the pipe to the standard output, so that the output of the first command will be sent to the pipe */
        dup2(fd[1], STDOUT_FILENO);

        /** Close the file descriptor for writing to the pipe, as it is no longer needed after duplication */
        close(fd[1]);

        /** Execute the first command with its arguments using execvp, which will replace the current process image */
        /* Use a constant string as the first argument of execvp */
        execvp("cat", cmd1);
    }
    else {
        /** Parent process */

        /** Close the file descriptor for writing to the pipe, as it is not needed */
        close(fd[1]);

        /** Create another child process for the second command */
        pid2 = fork();
        if (pid2 == 0) {
            /** Child process */

            /** Close the file descriptor for writing to the pipe, as it is not needed */
            close(fd[1]);

            /** Duplicate the file descriptor for reading from the pipe to the standard input, so that the input of the second command will be received from the pipe */
            dup2(fd[0], STDIN_FILENO);

            /** Close the file descriptor for reading from the pipe, as it is no longer needed after duplication */
            close(fd[0]);

            /** Execute the second command with its arguments using execvp, which will replace the current process image */
            /* Use a constant string as the first argument of execvp */
            execvp("tail", cmd2);
        }
    }
}