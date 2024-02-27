#include <stdio.h>
#include"head.h"

void strncat_custom(char *s,char *t,int n);

/**
 * @brief Main function.
 */
void fun2()
{
     int n=7;
    char s[] = "hello";
    char t[] = "world ok";

    strncat_custom(s, t,n);

    printf("Concatenated String: %s\n", s);


}

/**
 * @brief Concatenates the first n characters of string t to string s.
 * @param[in] s Pointer to the destination array where the string will be copied.
 * @param[in] t Pointer to the source string from which characters will be copied.
 * @param[in] n Maximum number of characters to be copied from `t`.
 */
void strncat_custom(char *s, char *t,int n)
{
    while (*s !='\0')
    {
        s++;
    }
    while(n>0)
    {
        *s=*t;
        s++;
        t++;
        n--;
    }
    *s='\0';
}

