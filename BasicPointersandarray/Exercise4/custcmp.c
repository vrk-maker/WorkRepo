#include <stdio.h>
#include <string.h>
#include"head.h"

// Function prototype
int mystrncmp(char *s, char *t, int n);

int main() {
    char s[] = "hello";
    char t[] = "hello";
    int n = 3;
    int result = mystrncmp(s, t, n);

    if (result == 0) {
        printf("Strings are equal\n");
    } else {
        printf("Strings are not equal\n");
    }
	
	fun1();
	printf("\n");
	fun2();
    return 0;
}

// Function definition
int mystrncmp(char *s, char *t, int n) 
{
    while( (*s == *t) && (n>0) )
    {
        s++;
        t++;
        n--;
    }
    if( (*s)=='\0' && n==0 )
    {
        return 0;
    }
}
