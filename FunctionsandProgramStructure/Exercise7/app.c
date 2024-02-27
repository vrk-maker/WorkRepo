#include <stdlib.h>
#include<stdio.h>

#define MAXLEN 100 /**< Maximum length of string */

void itoa(int n, char s[]);


int main(void) {
    int n;
    char s[MAXLEN];

    n = 123;

    itoa(n, s);

    printf("%s", s);
   
    return 0;
}

/**
 * @brief Converts an integer to a string representation.
 * @param[in] n The integer to be converted to a string.
 * @param[out] s The character array where the resulting string will be stored.
 */
void itoa(int n, char s[]) {
    static int i;

    if (n / 10)
        itoa(n / 10, s);
    else {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }

    s[i++] = abs(n) % 10 + '0';

    s[i] = '\0';
}

