#include <stdio.h>
#include"head.h"

void strncat_custom(char *s,char *t,int n);

void fun2()
{
     int n=7;
    char s[] = "hello";
    char t[] = "world ok";

    strncat_custom(s, t,n);

    printf("Concatenated String: %s\n", s);


}
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

