#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include <stdbool.h>
#include <ctype.h>

/**
 * @struct student
 * @brief Structure to represent candidate information.
 */
struct student
{
    int srno, num, vote;
    char name[100];
};

/**
 * @brief Updates the details of a candidate in the candidate.csv file.
 * 
 * This function prompts the user to enter a serial number to be matched, and then 
 * it searches for the matching serial number in the candidate.csv file. If a match 
 * is found, it allows the user to update the name, number, or vote count of the candidate.
 */
void update()
{
    FILE *fp, *temp;
    fp = fopen("candidate.csv", "r");
    char line[200];
    int curno;
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    int flag = 0, x;
    printf("Enter the serial number to be matched:");
    // scanf("%d", &x);
    if (scanf("%d", &x) != 1)
    {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "%d", &curno);
        if (x == curno)
        {
            flag = 1;
            printf("Serial number is valid.\n");
            break;
        }
    }
    if (flag == 0)
    {
        printf("Serial number is invalid.\n");
        return;
    }
    fclose(fp);

    // printf("\n");
    fp = fopen("candidate.csv", "r");
    temp = fopen("temp.csv", "w");
    if (temp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    struct student *s;
    s=(struct student *)malloc(sizeof(struct student));
    // char line[256];

    fgets(line, sizeof(line), fp);
    fprintf(temp, "%s", line);
    int check1,check2,check3;

    while (fgets(line, sizeof(line), fp))
    {
        sscanf(line, "%d,%[^,],%d,%d", &s->srno, s->name, &s->num, &s->vote);

        if (s->srno == x)
        {
            // flag = 1;
            int choice = 0;
            // int check=0;
            while (choice != 4)
            {
                printf("----Updating the record----\n");
                printf("\n1)Update Name");
                printf("\n2)Update Number");
                printf("\n3)Update Votecount");
                printf("\n4)Exiting the updation");
                printf("\nEnter your choice:");
                if (scanf("%d", &choice) != 1)
                {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n')
                        ;
                    break;
                }
                printf("\n");
                switch (choice)
                {
                case 1:
                    check1 = 0;
                    printf("Enter updated name:");
                    scanf("%s", s->name);
                    for (int x = 0; s->name[x] != '\0'; x++)
                    {
                        if (!isalpha(s->name[x]))
                        {
                            check1 = 1;
                            printf("Invalid input. Candidate name must contain only alphabetic characters.\n");
                            break;
                        }
                    }
                    if (check1 == 0)
                    {
                        printf("\nName updation success\n");
                        
                    }
                    break;
                case 2:
                    check2 = 0;
                    printf("\nEnter updated number:");
                    if (scanf("%d", &(s->num)) != 1)
                    {
                        check2 = 1;
                        printf("Invalid input. Please enter a number.\n");
                        while (getchar() != '\n')
                            ;
                        break;
                    }
                    if (check2 == 0)
                    {
                        printf("\nNumber updation success\n");
                        
                    }
                    break;
                case 3:
                    check3 = 0;
                    printf("\nEnter updated VotesCount:");
                    // scanf("%d", &s.vote);
                    if (scanf("%d", &(s->vote)) != 1)
                    {
                        check3 = 1;
                        printf("Invalid input. Please enter a number.\n");
                        while (getchar() != '\n')
                            ;
                        break;
                    }
                    if (check3 == 0)
                    {
                        printf("\nVotecount updation success\n");
                        
                    }
                    break;
                case 4:
                    printf("\nExiting updating old values\n");
                    break;
                default:
                    printf("\nPlease enter choice between 1 and 4\n");
                    break;
                }
            }

            fprintf(temp, "%d,%s,%d,%d\n", s->srno, s->name, s->num, s->vote);
            // printf("\nRecord updated successfully\n");
        }
        else
        {
            fprintf(temp, "%d,%s,%d,%d\n",s->srno, s->name, s->num, s->vote);
        }
    }

    // if (flag == 0)
    // {
    //     printf("\nError: Record not found\n");
    // }

    fclose(fp);
    fclose(temp);

    remove("candidate.csv");
    rename("temp.csv", "candidate.csv");
}

/**
 * @brief function to check for the existence of the candidate.csv file before calling the update function.
 * 
 * This function first checks if the candidate.csv file exists. If it does, it calls the update function 
 * to update the candidate details. If the file does not exist, it prints an error message.
 */
void newupdate()
{
    FILE *fp;
    bool exist = false;
    fp = fopen("candidate.csv", "r");
    if (fp != NULL)
    {
        exist = true;
        fclose(fp);
        update();
    }
    if (!exist)
    {
        printf("\nfile candidate.csv not found\n");
        return;
    }
}
// int main()
// {
//     newupdate();
//     return 0;
// }
