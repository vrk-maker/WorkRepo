#include <stdio.h>
#include <string.h>

int main()
{
    char buf[100];
    FILE *fp;
    fp = fopen("/home/vanshit/internship/git/vanshit_kamdar_idp/StructureandUnion/Exercise6/new.c", "r");
    if (fp == NULL)
    {
        printf("File open error\n");
        return 1;
    }

    // Keywords and symbols to ignore
    char *keywords[] = {
        "#include<stdio.h>",
        "int",
        "main()",
        "{",
        "}",
        "float",
        "char",
        "double",
        "return",
        "0;"
        };
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
    char variables[100][100];
    int num_variables = 0;

    while (fscanf(fp, "%s", buf) != EOF)
    {
        // Check if buf is a variable name
        int is_keyword = 0;
        for (int i = 0; i < num_keywords; i++)
        {
            if (strcmp(buf, keywords[i]) == 0)
            {
                is_keyword = 1;
                break;
            }
        }
        // If buf is not a keyword, add it to the variables array
        if (!is_keyword)
        {
            // Remove the semicolon if present at the end
            int len = strlen(buf);
            if (len > 0 && buf[len - 1] == ';')
            {
                buf[len - 1] = '\0';
            }
            strcpy(variables[num_variables], buf);
            num_variables++;
        }
    }

    // Bubble sort
    char temp[100];
    for (int i = 0; i < num_variables - 1; i++)
    {
        for (int j = i + 1; j < num_variables; j++)
        {
            if (strncmp(variables[i], variables[j], 6) > 0)
            { // Compare only first 6 characters
                strcpy(temp, variables[i]);
                strcpy(variables[i], variables[j]);
                strcpy(variables[j], temp);
            }
        }
    }

    // Print the sorted variable names
    for (int i = 0; i < num_variables; i++)
    {
        printf("%s\n", variables[i]);
    }

    fclose(fp);
    return 0;
}
