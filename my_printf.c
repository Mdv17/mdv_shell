#include <stdarg.h>
#include "my_shell.h"

/* The main function that implements my_printf */
void my_printf(const char *format, ...) {
    /* Declare the variables */
    va_list args;
    char *buffer;
    int index;
    int i;

    /* Initialize the argument list */
    va_start(args, format);

    /* Allocate a buffer to store the formatted output */
    buffer = malloc(1024);
    if (buffer == NULL) {
        perror("malloc");
        exit(1);
    }

    /* Initialize the buffer index */
    index = 0;

    /* Loop over the format string */
    for (i = 0; format[i] != '\0'; i++) {
        /* Check if the character is not a percent sign */
        if (format[i] != '%') {
            /* Copy the character to the buffer */
            buffer[index] = format[i];
            index++;
        } else {
            /* Check the next character and determine the format specifier */
            i++;
            switch (format[i]) {
                case 'd': /* Integer in decimal */
                {
                    /* Declare the string variable */
                    char str[32];

                    /* Get the next argument as an int */
                    int num = va_arg(args, int);

                    /* Convert the int to a string */
                    mdv_itoa(num, str, 10);

                    /* Copy the string to the buffer */
                    strcpy(buffer + index, str);
                    index += strlen(str);
                    break;
                }
                case 'x': /* Integer in hexadecimal */
                {
                    /* Declare the string variable */
                    char str[32];

                    /* Get the next argument as an int */
                    int num = va_arg(args, int);

                    /* Convert the int to a string */
                    mdv_itoa(num, str, 16);

                    /* Copy the string to the buffer */
                    strcpy(buffer + index, str);
                    index += strlen(str);
                    break;
                }
                case 'f': /* Floating-point number */
                {
                    /* Declare the string variable */
                    char str[32];

                    /* Get the next argument as a double */
                    double num = va_arg(args, double);

                    /* Convert the double to a string */
                    mdv_dtoa(num, str, 6);

                    /* Copy the string to the buffer */
                    strcpy(buffer + index, str);
                    index += strlen(str);
                    break;
                }
                case 's': /* String */
                {
                    /* Get the next argument as a char pointer */
                    char *str = va_arg(args, char *);

                    /* Copy the string to the buffer */
                    strcpy(buffer + index, str);
                    index += strlen(str);
                    break;
                }
                case 'c': /* Character */
                {
                    /* Get the next argument as a char */
                    char ch = (char)va_arg(args, int);

                    /* Copy the character to the buffer */
                    buffer[index] = ch;
                    index++;
                    break;
                }
                case '%': /* Literal percent sign */
                {
                    /* Copy the percent sign to the buffer */
                    buffer[index] = '%';
                    index++;
                    break;
                }
                default: /* Invalid format specifier */
                {
                    /* Print an error message and exit */
                    char *error = "Invalid format specifier: ";
                    write(STDERR_FILENO, error, strlen(error));
                    write(STDERR_FILENO, &format[i], 1);
                    write(STDERR_FILENO, "\n", 1);
                    exit(1);
                }
            }
        }
    }

    /* Terminate the buffer */
    buffer[index] = '\0';

    /* Print the buffer using the write function */
    write(STDOUT_FILENO, buffer, index);

    /* Free the buffer */
    free(buffer);

    /* Clean up the argument list */
    va_end(args);
}