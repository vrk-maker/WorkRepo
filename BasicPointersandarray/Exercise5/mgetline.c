#include <stdio.h>
#include "head.h"
/**
 * @brief Calculates the length of a string.
 *
 * This function calculates the length of a null-terminated string.
 *
 * @param[in] t The string whose length is to be calculated.
 * @return The length of the string.
 */
int mgetline(char *t) {
    int count = 0;
    while (*t != '\0') {
        count++;
        t++;
    }
    return count;
}

/**
 * @brief Main function.
 */
void fun1() {
    char s[20];
    printf("Enter a string whose length is to be calculated: ");
    scanf("%19s", s); // Limit input length to avoid buffer overflow
    int len = mgetline(s);
    printf("\nThe length of the string is: %d\n", len);
}
