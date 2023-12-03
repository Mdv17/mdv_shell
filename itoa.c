#include "my_shell.h"

/* A helper function to convert an integer to a string */
int mdv_itoa(int num, char *str, int base) {
    int i = 0;
    int is_negative = 0;

    /* Handle 0 as a special case */
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return i;
    }

    /* Handle negative numbers for base 10 */
    if (num < 0 && base == 10) {
        is_negative = 1;
        num = -num;
    }

    /* Convert the number to the given base */
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    /* Add the negative sign for base 10 */
    if (is_negative) {
        str[i++] = '-';
    }

    /* Terminate the string */
    str[i] = '\0';

    /* Reverse the string */
    mdv_reverse(str, i);

    return i;
}