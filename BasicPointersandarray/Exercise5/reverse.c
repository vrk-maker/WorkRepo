#include <stdio.h>
#include <string.h>
#include"head.h"
void reverse(char *s);

void fun3() {
    char s[] = "hello world";
    reverse(s);
    printf("%s", s);
}

void reverse(char *str) 
{
    int len = strlen(str); 
    char *start = str;
    char *end = str + len - 1;
    while (start < end) { 
        char temp = *start; 
        *start = *end; 
        *end = temp; 
        start++; 
        end--; 
    }
}

