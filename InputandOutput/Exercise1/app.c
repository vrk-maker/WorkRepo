#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char c;

    if (strcmp(argv[1], "lower") == 0)
    {
        printf("Enter text to convert: ");
        while ((c = getchar()) != EOF)
        {
            putchar(tolower(c));
        }
    }
    else
    {
        printf("Enter text to convert: ");
        while ((c = getchar()) != EOF)
        {
            putchar(toupper(c));
        }
    }
    return 0;
}

