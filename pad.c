#include "my_shell.h"

/* A helper function to pad a string with a given character */
void mdv_pad(char *str, int len, char ch, int left) {
    /* Declare the variables */
    char *buf;
    int i;

    /* Check if the length is valid */
    if (len <= 0) {
        return;
    }

    /* Create a temporary buffer */
    buf = malloc(len + 1);
    if (buf == NULL) {
        perror("malloc");
        exit(1);
    }

    /* Fill the buffer with the padding character */
    for (i = 0; i < len; i++) {
        buf[i] = ch;
    }

    /* Terminate the buffer */
    buf[len] = '\0';

    /* Copy the string to the buffer */
    if (left) {
        /* Left padding */
        strcpy(buf + len - strlen(str), str);
    } else {
        /* Right padding */
        strcpy(buf, str);
    }

    /* Copy the buffer back to the string */
    strcpy(str, buf);

    /* Free the buffer */
    free(buf);
}