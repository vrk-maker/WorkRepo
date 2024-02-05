#include <stdio.h>


void reverseStringRecursive(char* str, int start, int end) {
    if (start >= end) return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseStringRecursive(str, ++start, --end);
}

void reverseString(char* str) {
    reverseStringRecursive(str, 0, strlen(str) - 1);
}

int main() {
    char str[] = "Hello, world!";
    printf("Original string: %s\n", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}

