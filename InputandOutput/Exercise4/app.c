#include <stdio.h>
#include <string.h>
void compareFiles(FILE *fp,FILE *ft)
{
    char line1[1000], line2[1000];
    int count = 0;

    while( (fgets(line1,sizeof(line1),fp) !=NULL) && (fgets(line2,sizeof(line2),ft)!=NULL) )
    {
        if(strcmp(line1,line2)!=0)
        {
            printf("this is of file1.txt:%s", line1);
            printf("this is of file2.txt:%s", line2);
            count++;
            break;
        }
    }
    if(count==0)
    {
        printf("files are identical");
    }
    else
    {
        printf("files are not identical");
    }
}


int main()
{
    FILE *fp;
    FILE *ft;

    fp = fopen("file1.txt", "r");
    ft = fopen("file2.txt", "r");

    compareFiles(fp, ft);

    fclose(fp);
    fclose(ft);
}

