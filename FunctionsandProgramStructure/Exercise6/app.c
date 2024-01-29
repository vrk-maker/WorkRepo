#include <stdio.h>
#include <string.h>

#define BUF_SIZE 100

char buffer[BUF_SIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buffer[--bufp] : getchar();
}

void ungetch(char c) {
    if (bufp >= BUF_SIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buffer[bufp++] = c;
    }
}

void ungets(char c[], int l) 
{
    for(int i=0;i<l;i++)
    {
        ungetch(c[i]);
    }
}

int main(void) {
    char text[20],c;
    printf("enter string:");
    printf("\n");
    gets(text);
    int len=strlen(text);
    
    ungets(text,len);
    
    printf("\nCharacters retrieved from the buffer:\n");

    while ((c = getch()) != EOF) {
        putchar(c);  // Print characters retrieved from the buffer
    }
    return 0;
}

