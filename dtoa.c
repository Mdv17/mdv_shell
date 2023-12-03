#include "my_shell.h"

/* A helper function to convert a double to a string */
int mdv_dtoa(double num, char *str, int precision) {
    /* Split the number into integer and fractional parts */
    int int_part = (int)num;
    double frac_part = num - (double)int_part;

    /* Convert the integer part to a string */
    int i = mdv_itoa(int_part, str, 10);

    /* Check if the precision is zero */
    if (precision == 0) {
        return i;
    }

    /* Add the decimal point */
    str[i] = '.';
    i++;

    /* Convert the fractional part to a string */
    while (precision > 0) {
        /* Declare the digit variable */
        int digit;

        /* Multiply the fractional part by 10 */
        frac_part = frac_part * 10;

        /* Get the next digit */
        digit = (int)frac_part;

        /* Append the digit to the string */
        str[i] = digit + '0';
        i++;

        /* Update the fractional part */
        frac_part = frac_part - (double)digit;

        /* Decrease the precision */
        precision--;
    }

    /* Terminate the string */
    str[i] = '\0';

    return i;
}