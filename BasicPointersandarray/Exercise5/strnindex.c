#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "head.h"

int mstrindex(char s[], char t[]);

int main() {
    char line[30];
    printf("enter string:");
    scanf("%s", line);
    printf("\n");
    char pattern[30];
    printf("enter pattern to be searched in the string:");
    scanf("%s", pattern);
    printf("\n");

    int found;

    found = mstrindex(line, pattern);
    if(found==0)
    {
        printf("no match found");
    }
    else
    {
        printf("Found: %d\n", found);
    }
    fun1();
    printf("\n");
    fun2();
    printf("\n");
    fun3();
    printf("\n");
    fun4();
    
    return 0;
}

/**
 * @brief Finds the index of the first occurrence of a substring within a string.
 * @param[in] s Pointer to the string in which to search for the substring.
 * @param[in] t Pointer to the substring to search for within `s`.
 * @return The index of the starting position of the first occurrence of `t` within `s`.
 */
int mstrindex(char *s, char *t) {
    char *b = s;
    char *p, *r;
    int result;

    for (; *s != '\0'; s++) {
        for (p = s, r = t; *r != '\0' && *p == *r; p++, r++);

        if (r > t && *r == '\0')
            result= s - b; //current - original
    }
    return result;
}

