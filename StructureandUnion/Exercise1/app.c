#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];  // Buffer for ungetch
int bufp = 0;       // Next free position in buf

int getch(void) {   // Get a (possibly pushed back) character
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {  // Push character back on input
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getword(char *word, int lim);

int main() {
    char word[100];

    while (getword(word, 100) != EOF) {
        printf("Word: %s\n", word);
    }

    return 0;
}

int getword(char *word, int lim) {
    int c;
    char *w = word;

    // Skip leading whitespace
    while (isspace(c = getch()))
        ;

    // Handle preprocessor control lines
    if (c == '#') {
        while (--lim > 0 && (c = getch()) != EOF && c != '\n') {
            *w++=c;
        }
        if (c == '\n') {
            // Include the newline character in the word
            *w++ = c;
        }
        *w = '\0';
        return word[0];
    }

    // Handle comments
    if (c == '/') {
        if ((c = getch()) == '*') {
            // Inside a /* */ comment
            *w++ = '/';
            *w++ = '*';
            while (--lim > 0 && (c = getch()) != EOF) {
                *w++ = c;
                if (c == '*' && (c = getch()) == '/') {
                    *w++ = c;
                    break;
                }
            }
            *w = '\0';
            return word[0];
        } else {
            ungetch(c);
            c = '/';
        }
    }

    // Handle string constants
    if (c == '"') {
        *w++ = c; // Include the opening double quote in the word
        while (--lim > 0 && (c = getch()) != EOF && c != '"') {
            *w++ = c; // Include characters within the string constant
        }
        if (c == '"') {
            *w++ = c; // Include the closing double quote in the word
        }
        *w = '\0';
        return word[0];
    }
    
    if (c != EOF)
        *w++ = c;

    if (!isalpha(c) && c != '_') {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch()) && *w != '_') {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}

