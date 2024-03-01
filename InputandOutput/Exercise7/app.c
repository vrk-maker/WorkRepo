// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    char str[20];
    printf("enter string:");
    gets(str);
    int i=0;
    int counter=0;
    while(str[i]!='\0')
    {
        if (isupper(str[i]))
            counter++;
        i++;
    }
    printf("Number of uppercase:%d",counter);

    return 0;
}