#include <stdlib.h>
#include <stdio.h>
#include"head.h"

#define MAXLEN 100

int mgetline(char *s, int lim);

/**
 * @brief Main function.
 */
void fun1() {
    char s[MAXLEN];
    
    int length = mgetline(s, MAXLEN);

    printf("Length of the string: %d\n", length);

}

/**
 * @brief A function to calculate the length of the string
 * @param[in] s Pointer to the string whose length is to be calculated.
 * @param[in] lim which defines the maximum length of the string.
 * @return the length of the string
 */
int mgetline(char *s, int lim)
{
    int c, i;
    char *b=s;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        *(s++) = c;
    *s = '\0';
    return s-b;
}

