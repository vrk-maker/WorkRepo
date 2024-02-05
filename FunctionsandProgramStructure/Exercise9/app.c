#include <stdio.h>

#define BUF_SIZE 1
char arr[BUF_SIZE];
int i = 0;

int getch() {
    if (i > 0) {
        return arr[--i];
    } else {
        printf("Enter character: ");
        return getchar();
    }
}

void ungetch(char c) {
    if (i < BUF_SIZE) {
        arr[i++] = c;
    } 
    else 
    {
        printf("No space left for ungetch\n");
    }
}

int main() {
    char ch, d;
    ch = getch();
    ungetch(ch);
    putchar(ch);
    printf("\n");
    ungetch('x');
    return 0;
}

