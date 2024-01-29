#include <stdlib.h>
#include <stdio.h>
#include"head.h"

#define MAXLEN 100

void itoa(int n, char s[]);

void fun2() {
    int n = 123;
    char s[MAXLEN];

    itoa(n, s);

    printf("%s", s);

}

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

