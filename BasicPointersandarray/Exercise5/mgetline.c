#include <stdlib.h>
#include <stdio.h>
#include"head.h"

#define MAXLEN 100

int mgetline(char *s, int lim);

void fun1() {
    char s[MAXLEN];
    
    int length = mgetline(s, MAXLEN);

    printf("Length of the string: %d\n", length);

}

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

