#include <stdlib.h>
#include <stdio.h>
#include"head.h"

#define MAXLEN 100 /**< Maximum length of string */

void itoa(int n, char s[]);

/**
 * @brief Main function.
 */
void fun2() {
    int n;
    printf("enter number you want to convert to string:");
    scanf("%d", &n);
    char s[MAXLEN];

    itoa(n, s);

    printf("%s", s);

}


/**
 * @brief Converts an integer to a string representation.
 * @param[in] n The integer to be converted to a string.
 * @param[out] s The character array where the resulting string will be stored.
 */
void itoa(int n, char s[]) {
    char *p = s;
    static int i;

    if (n / 10)
        itoa(n / 10, s);
    else {
        i = 0;
        if (n < 0)
            *(p + i++) = '-';
    }

    *(p + i++) = abs(n) % 10 + '0';

    *(p + i) = '\0';
}

