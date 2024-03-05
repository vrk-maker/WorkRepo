#include <stdio.h>
#include <string.h>

int strend(char *s,char *t);

int main() {
    char s[20],t[20];
    printf("enter first string=");
    gets(s);
    printf("enter second string to check whether it exisits at the end=");
    gets(t);

    int x = strend(s, t);
    if (x == 1) {
        printf("string occurs at the end of the string.\n");
    } else {
        printf("string doesn't occur at the end\n");
    }

    return 0;
}

/**
 * @brief Check if the string t occurs at the end of the string s.
 *
 * This function checks if the string t occurs at the end of the string s.
 *
 * @param s The string to be searched.
 * @param t The string to be searched for.
 * @return 1 if string t occurs at the end of string s, otherwise 0.
 */
int strend(char *s, char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_t > len_s) {
        return 0;
    }

    s += (len_s - len_t);
    while (*s != '\0' && *t != '\0') {
        if (*s != *t) {
            return 0;
        }
        s++;
        t++;
    }
    if (*t == '\0') {
        return 1;
    } else {
        return 0;
    }
}
