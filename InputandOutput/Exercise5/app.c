#include <stdio.h>

void printFile(FILE *file) 
{
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

int main() {
    char *fileNames[] = {"/home/vanshit/internship/git/vanshit_kamdar_idp/InputandOutput/Exercise5/file1.txt", "/home/vanshit/internship/git/vanshit_kamdar_idp/InputandOutput/Exercise5/file2.txt"};
    int numFiles = sizeof(fileNames) / sizeof(fileNames[0]);

    for (int i = 0; i < numFiles; i++) 
    {
        printf("\n-----");
        printf("\nTitle: %s",fileNames[i]);
        printf("\nPage: %d\n", i+1);
        FILE *file = fopen(fileNames[i], "r");
        printFile(file);
    }
    return 0;
}

