#include <stdio.h>
#include <string.h>
#include"head.h"
void reverse(char *s);

/**
 * @brief Main function.
 */
void fun3() {
    char s[10];
    printf("enter string to reverse:");
    scanf("%s", s);
    printf("\n");
    reverse(s);
    printf("%s", s);
}

/**
 * @brief Reverses the characters in a string.
 * @param[in] str Pointer to the null-terminated string to be reversed.
 */
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

