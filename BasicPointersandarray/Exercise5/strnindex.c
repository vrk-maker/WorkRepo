#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "head.h"

int mstrindex(char s[], char t[]);

int main() {
    char line[] = "abcdefabc";
    char pattern[] = "abc";

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

