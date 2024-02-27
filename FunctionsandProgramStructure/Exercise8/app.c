#include <stdio.h>
#include <string.h>

/**
 * @brief Reverses the characters in a string recursively.
 * @param[in,out] str Pointer to the string to be reversed.
 * @param[in] start Index of the starting character.
 * @param[in] end Index of the ending character.
 */
void reverseStringRecursive(char* str, int start, int end) {
    if (start >= end) return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseStringRecursive(str, ++start, --end);
}

/**
 * @brief Reverses a string.
 * @param[in,out] str Pointer to the string to be reversed.
 */
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
