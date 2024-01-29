#include <stdio.h>

void strncat_custom(char *s,char *t);

int main()
{
    char s[] = "hello";
    char t[] = "world ok";

    strncat_custom(s, t);

    printf("Concatenated String: %s\n", s);

    return 0;
}

// Function definition
void strncat_custom(char *s, char *t)
{
    while (*s !='\0')
    {
        s++;
    }
    while(*t!='\0')
    {
        *s=*t;
        s++;
        t++;
    }
    *s='\0';
}

