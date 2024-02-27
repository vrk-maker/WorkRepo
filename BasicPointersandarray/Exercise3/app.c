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
/**
 * @brief Concatenates two strings.
 * @param[in] s Pointer to the destination string.
 * @param[in] t Pointer to the source string to be appended to `s`.
*/
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

