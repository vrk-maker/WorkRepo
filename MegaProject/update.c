#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

struct student
{
    int srno, num, vote;
    char name[100];
};

void update()
{
    FILE *fp, *temp;
    fp = fopen("candidate.csv", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    temp = fopen("temp.csv", "w");
    if (temp == NULL)
    {
        printf("Error creating temporary file\n");
        fclose(fp);
        return;
    }

    int flag = 0, x;
    printf("Enter the serial number to be matched:");
    scanf("%d", &x);
    printf("\n");

    struct student s;
    char line[256];

    fgets(line, sizeof(line), fp);
    fprintf(temp, "%s", line);

    while (fgets(line, sizeof(line), fp))
    {
        sscanf(line, "%d,%[^,],%d,%d", &s.srno, s.name, &s.num, &s.vote);

        if (s.srno == x)
        {
            flag = 1;
            int choice = 0;
            while (choice != 4)
            {
                printf("----Updating the record----\n");
                printf("\n1)Update Name");
                printf("\n2)Update Number");
                printf("\n3)Update Votecount");
                printf("\n4)Exiting the updation");
                printf("\nEnter your choice:");
                scanf("%d", &choice);
                printf("\n");
                switch (choice)
                {
                case 1:
                    printf("Enter updated name:");
                    scanf("%s", s.name);
                    break;
                case 2:
                    printf("\nEnter updated number:");
                    scanf("%d", &s.num);
                    break;
                case 3:
                    printf("\nEnter updated VotesCount:");
                    scanf("%d", &s.vote);
                    break;
                case 4:
                    printf("\nExiting your choices\n");
                    break;
                default:
                    printf("\nPlease enter valid choice\n");
                    break;
                }
            }

            fprintf(temp, "%d,%s,%d,%d\n", s.srno, s.name, s.num, s.vote);
            printf("\nRecord updated successfully\n");
        }
        else
        {
            fprintf(temp, "%d,%s,%d,%d\n", s.srno, s.name, s.num, s.vote);
        }
    }

    if (flag == 0)
    {
        printf("\nError: Record not found\n");
    }

    fclose(fp);
    fclose(temp);

    remove("candidate.csv");
    rename("temp.csv", "candidate.csv");
}
