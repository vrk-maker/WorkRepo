#include <stdio.h>
#include"head.h"
void strncpy_custom(char *s, char *t,int n);

void fun1() {
	int n=5;
	char s[] = "hello";
	char t[] = "worldnew";
	strncpy_custom(s, t,n);
	printf("%s", s);
	
}

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

