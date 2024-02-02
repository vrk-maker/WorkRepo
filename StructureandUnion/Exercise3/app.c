#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

int main() 
{
    FILE *fp;
    char buff[100],ch;

    fp = fopen("/home/vanshit/internship/git/vanshit_kamdar_idp/StructureandUnion/Exercise3/file1.txt", "r");

    int line_number = 1;
    while (fscanf(fp, "%s", buff) == 1)
    {
        if (strcmp(buff, "the") != 0 && strcmp(buff, "and") != 0) 
        {
            printf("The word '%s' belongs to line %d\n", buff, line_number);
        }
        if((ch=fgetc(fp))=='\n') 
        {
            line_number++;
        }
    }

    fclose(fp);
    return 0;
}

