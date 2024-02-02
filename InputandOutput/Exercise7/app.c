#include <ctype.h>
#include <stdio.h>

int test_upper(int i, int counter)
{
    char ch;
    char a[50] = "HelloWorlD";
    ch = a[0];

    while (ch != '\0') {
        ch = a[i];
        if (isupper(ch))
            counter++;

        i++;
    }

    return counter;
}
int main()
{
    int i = 0;
    int counter = 0;

    counter = test_upper(i, counter);
    printf("\nNumber of upper case present in the sentence is : %d\n", counter);
    return 0;
}

