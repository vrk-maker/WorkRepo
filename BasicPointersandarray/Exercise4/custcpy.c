#include <stdio.h>
#include"head.h"
void strncpy_custom(char *s, char *t,int n);


/**
 * @brief Main function.
 */
void fun1() {
	int n=5;
	char s[] = "hello";
	char t[] = "worldnew";
	strncpy_custom(s, t,n);
	printf("%s", s);
	
}

/**
 * @brief Copies the first n characters of string t to string s.
 * @param[in] s Pointer to the destination array where the string will be copied.
 * @param[in] t Pointer to the source string from which characters will be copied.
 * @param[in] n Maximum number of characters to be copied from `t`.
 */
void strncpy_custom(char *s, char *t,int n) 
{
    while(n>0)
    {
        *s=*t;
        s++;
        t++;
        n--;
    }
    *s='\0';
}

