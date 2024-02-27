#include <stdio.h>


int mstrindex(char s[], char t[]);

int main() {
    char line[] = "abcdefabc";
    char pattern[] = "abc";

    int found;

    found = mstrindex(line, pattern);
    printf("Found: %d\n", found);
}

/**
 * @brief Finds the index of the rightmost occurrence of a substring within a string.
 * @param[in] s Pointer to the string in which to search for the substring.
 * @param[in] t Pointer to the substring to search for within `s`.
 * @return The index of the starting position of the rightmost occurrence of `t` within `s`.
 */
int mstrindex(char s[], char t[]) {
    int i, j, k, result;

    result = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            result = i;
    }
    return result;
}

