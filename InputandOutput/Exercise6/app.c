#include <stdio.h>
#include <string.h>

void mstrindex(FILE *fp)
{
    char pattern[] = "ould";
    char line[1000];
    int count = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, pattern) != NULL) {
            printf("Pattern found at line:%s",line);
            fclose(fp);
            count++;
        }
    }
    if(count ==0)
    {
        printf("Pattern not found");
        fclose(fp);
    }
}

int main(int argc, char *argv[]) 
{
    FILE *fp = fopen(argv[1], "r");
    mstrindex(fp);
    return 0;
}

