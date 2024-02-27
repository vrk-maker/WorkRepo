#include <stdio.h>

#define BUF_SIZE 1 /**< The size of the input buffer */
char arr[BUF_SIZE];
int i = 0;

/**
 * @brief Retrieves a character from input or the buffer.
 * @return The character retrieved.
 */
int getch() {
    if (i > 0) {
        return arr[--i];
    } else {
        printf("Enter character: ");
        return getchar();
    }
}


/**
 * @brief Pushes a character back onto the input buffer.
 * @param c The character to be pushed back.
 */
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

