#include <stdio.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 20

int main() {
    char text[] = "This is a longer string with more \t than 20 characters.\n";
    char *ptr = text;
    int charCount = 0;

    while (*ptr != '\0') {
        if (iscntrl(*ptr)) {
            int octalValue = *ptr;
            printf("\\%03o", octalValue);
            charCount += 4;
        } else {
            putchar(*ptr);
            charCount++;
        }
        if (charCount >= MAX_LINE_LENGTH) {
            putchar('\n');
            charCount = 0;  
        }
        ptr++;
    }
    return 0;
}

