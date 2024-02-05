#include <stdio.h>

#define BUF_SIZE 5
char buf[BUF_SIZE];
int bufp = 0;

void ungetch(char c) {
    if (c == '\0') {
        printf("EOF added\n");
        buf[bufp++] = c;
    } else if (bufp >= BUF_SIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getch(void) { 
    return (bufp > 0) ? buf[--bufp] : getchar(); 
}

int main() {
    printf("Enter a string: ");

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        ungetch(ch);
    }
    ungetch('\0');

    printf("String in the buffer: ");
    while ((ch = getch()) != EOF) {
        putchar(ch);
    }
    putchar('\n');

    return 0;
}

