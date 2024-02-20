#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include "header.h"
#define BUFFER_SIZE 100
#define MAX_LINE_LENGTH 100
struct cname
{
    char name[20];
    int no;
    int serial;
    int votes;
} p[20];

// user authentication
void user_auth()
{
    char username[20];
    char password[20];
    int authenticated = 0;

    do
    {
        printf("Enter username:");
        scanf("%s", username);
        printf("Enter password:");
        scanf("%s", password);

        if (strcmp(username, "user") == 0)
        {
            if (strcmp(password, "voting") == 0)
            {
                printf("You have successfully logged in\n");
                authenticated = 1;
            }
            else
            {
                printf("Please enter correct password\n");
            }
        }
        else
        {
            printf("Incorrect username\n");
        }
    } while (!authenticated);
}

// election details
int x;
void election_details()
{
    FILE *fp;
    static int flag = 0;

    if(flag==1)
    {
        printf("Details already enterd\n"); //add
        return;
    }

    fp = fopen("election.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    char ename[20];
    printf("Enter the number of votes: ");
    scanf("%d", &x);
    printf("Enter the name of the election: ");
    scanf("%s", ename);
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Current Date: %d-%d-%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    fprintf(fp, "Election name: %s\nDate of the election: %d-%d-%d\nMaximum votes: %d\n", ename, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, x);
    flag = 1;

    fclose(fp);
}

// voter id verification
char voter[20][11];
int numVoters = 0;
void validateVoterID(char *voterID)
{
    if (numVoters >= x)
    {
        printf("Maximum number of voters already reached. Voting is closed.\n");
        system("sleep 3");
        return;
    }

    for (int i = 0; i < numVoters; i++)
    {
        if (strcmp(voterID, voter[i]) == 0)
        {
            printf("You have already voted!!!\n");
            system("sleep 3");
            return;
        }
    }

    if (strlen(voterID) != 10)
    {
        printf("Invalid voter ID. Please check the format.\n");
        system("sleep 3");
        return; 
    }

    for (int i = 0; i < 2; i++)
    {
        if (!isalpha(voterID[i]) || !isupper(voterID[i]))
        {
            printf("Invalid voter ID. Please check the format.\n");
            system("sleep 3");
            return; 
        }
    }

    for (int i = 2; i < 8; i++)
    {
        if (!isdigit(voterID[i]))
        {
            printf("Invalid voter ID. Please check the format.\n");
            system("sleep 3");
            return;
        }
    }

    for (int i = 8; i < 10; i++)
    {
        if (!isalpha(voterID[i]) || !isupper(voterID[i]))
        {
            printf("Invalid voter ID. Please check the format.\n");
            system("sleep 3");
            return;
        }
    }

    strcpy(voter[numVoters], voterID);
    numVoters++;
    printf("Voter ID is valid. Now proceed to vote.\n");
    show_cand();
    vote_cand();
}

// add candidate
int i = 0;
void add_cand()
{

    int j;
    int candidateExists = 0; // Flag to check if candidate already exists

    printf("Enter candidate name: ");
    scanf("%s", p[i].name);

    // Check if candidate name already exists
    for (j = 0; j < i; j++)
    {
        if (strcmp(p[i].name, p[j].name) == 0)
        {
            printf("Candidate name already exists!\n");
            system("sleep 3");
            candidateExists = 1;
            break;
        }
    }

    if (!candidateExists)
    {
        printf("Enter candidate number: ");
        scanf("%d", &p[i].no);
        i++;
    }
}

// delete candidate
void delete_cand()
{
    int roll;
    printf("enter number:");
    scanf("%d", &roll);
    for (int j = 0; j < i; j++)
    {
        if (roll == p[j].no)
        {
            printf("The candidate named %s whose number is %d is deleted", p[j].name, p[j].no);
            for (int k = j; k < i - 1; k++)
            {
                p[k] = p[k + 1];
            }
            p[i - 1].no = 0;
            strcpy(p[i - 1].name, "");
            break;
        }
    }
    i--;
}

// edit details
void edit_cand()
{
    int roll;
    printf("enter number that you want to update:");
    scanf("%d", &roll);
    for (int j = 0; j < i; j++)
    {
        if (p[j].no == roll)
        {
            int choice;
            while (choice != 3)
            {
                printf("Updating details....\n");
                printf("1.Name\n");
                printf("2.Candidate number\n");
                printf("3.Exit\n");
                printf("Enter your choice of updation:");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("Enter candidate Name:");
                    scanf("%s", p[j].name);
                    break;
                case 2:
                    printf("Enter candidate Number");
                    scanf("%d", &p[j].no);
                    break;
                case 3:
                    printf("records updated successfully!!");
                    break;
                default:
                    printf("Invalid choice! Please enter a number between 1 and 3.\n");
                    break;
                }
            }
        }
    }
}

// vote count
void vote_cand()
{
    int no;
    static int count = 0;

    if (count == x)
    {
        printf("\nMaximum vote limit reached!\n");
        // system("sleep 3");
        return;
    }

    printf("\nEnter the candidate number you want to vote for:");
    scanf("%d", &no);

    for (int j = 0; j < i; j++)
    {
        if (p[j].no == no)
        {
            printf("\nYou have voted for: %s\n", p[j].name);
            p[j].votes++;
            count++;
            system("sleep 3");
        }
    }
}

// Voting results
void result_cand()
{
    int max_votes = 0;
    int winner_count = 0;
    int winner_indices[3];

    for (int x = 0; x < i; x++)
    {
        if (p[x].votes > max_votes)
        {
            max_votes = p[x].votes;
        }
    }
    for (int x = 0; x < i; x++)
    {
        if (p[x].votes == max_votes)
        {
            winner_indices[winner_count++] = x;
        }
    }
    if (winner_count > 0)
    {
        printf("\nElection Winners:\n");
        for (int j = 0; j < winner_count; j++)
        {
            printf("%s\n", p[winner_indices[j]].name);
        }
    }
    else
    {
        printf("\nNo votes have been cast yet.\n");
    }
    system("sleep 3");
}

//show cand
void show_cand()
{
    int sno = 1;
    printf("SrNo.\tName\t\t\tNumber\n");
    for (int x = 0; x < i; x++)
    {
        printf("%d\t%s\t\t\t%d\n", sno, p[x].name, p[x].no);
        ++sno;
    }
}

// Display candidate
void display_cand()
{
    int sno = 1;
    printf("SrNo.\tName\t\t\tNumber\t\tVotesCount\n");
    for (int x = 0; x < i; x++)
    {
        printf("%d\t%s\t\t\t%d\t\t%d\n", sno, p[x].name, p[x].no, p[x].votes);
        ++sno;
    }
    system("sleep 2");
    system("clear");
}
void store_file()
{
    int sno = 1;
    FILE *fp;
    fp = fopen("candidate.csv", "w");
    printf("Storing the data in the file.....\n");
    fprintf(fp, "SrNo.,Name,Number,VotesCount\n");

    for (int j = 0; j < i; j++)
    {
        fprintf(fp, "%d,%s,%d,%d\n", sno, p[j].name, p[j].no, p[j].votes);
        ++sno;
    }

    printf("Data stored in the file.....\n");
    fclose(fp);
    system("sleep 2");
    system("clear");
}


// UPDATE OLD ELECTION----------------------------------------------------------------
void display_file()
{
    FILE *fp;
    fp = fopen("candidate.csv", "r");
    char line[200];

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    //printf("SrNo.,Name,Number,VotesCount\n");
    //fgets(line, sizeof(line), fp);
    while ((fgets(line, sizeof(line), fp)) != NULL)
    {
        printf("%s\n", line);
    }

    fclose(fp);
    system("sleep 7");
    //system("clear");
}

void deleteserial()
{
    FILE *fp, *tmp;
    fp = fopen("candidate.csv", "r");
    tmp = fopen("temp.csv", "w");

    char line[200];
    int srno, curno, num, vote;
    char name[200];

    printf("enter serial number:");
    scanf("%d", &srno);
    printf("\n");

    fgets(line, sizeof(line), fp);
    fprintf(tmp, "%s", line);
    //printf("\nDoint the file transfer\n");
    while (fgets(line, sizeof(line), fp))
    {
        sscanf(line, "%d,%[^,],%d,%d", &curno, name, &num, &vote);
        if (srno != curno)
        {
            fprintf(tmp, "%d,%s,%d,%d\n", curno, name, num, vote);
        }
    }
    //printf("\nFile completed\n");

    fclose(fp);
    fclose(tmp);
    remove("candidate.csv");
    rename("temp.csv", "candidate.csv");
    printf("\nSerial number: %d is deleted\n", srno);
    system("sleep 7");
    system("clear");
}


void admin_pannel()
{
    user_auth();
    int choice;

    do
    {
        system("clear");
        printf("1.Start New election\n");
        printf("2.Update old election\n");
        printf("3. Exit\n");
        printf("enter your choice:");
        scanf("%d", &choice); // Read the choice after displaying the menu
        printf("\n");
        switch (choice)
        {
        case 1:
        {
            int inner_choice;
            do
            {
                system("clear");
                printf("\n---------Main Menu for new election----------\n");
                printf("1. Election Details\n");
                printf("2. Add Candidate\n");
                printf("3. Delete Candidate\n");
                printf("4. Display Candidates\n");
                printf("5. Edit details\n");
                printf("6. Store data in the file\n");
                printf("7. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &inner_choice);

                switch (inner_choice)
                {
                case 1:
                    system("clear");
                    election_details();
                    break;
                case 2:
                    system("clear");
                    add_cand();
                    break;
                case 3:
                    system("clear");
                    delete_cand();
                    system("clear");
                    break;
                case 4:
                    display_cand();
                    break;
                case 5:
                    system("clear");
                    edit_cand();
                    break;
                case 6:
                    store_file();
                    break;
                case 7:
                    printf("Exiting the start the new election\n");
                    system("sleep 2");
                    system("clear");
                    break;
                default:
                    printf("Invalid choice! Please enter a number between 1 and 7.\n");
                    system("sleep 2");
                    system("clear");
                    break;
                }
            } while (inner_choice != 7);
            break; // Exiting the inner do-while loop
        }
        case 2:
        {
            int inner_choice;
            do
            {
                system("clear");
                printf("\n---------Main Menu for old election----------\n");
                printf("1. Delete Candidate\n");
                printf("2. Display Candidates\n");
                printf("3. Edit details\n");
                printf("4. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &inner_choice);

                switch (inner_choice)
                {
                case 1:
                    //system("clear");
                    deleteserial();
                    break;
                case 2:
                    // system("clear");
                    display_file();
                    //system("sleep 3");
                    break;
                case 3:
                    update();
                    break;
                case 4:
                    system("clear");
                    printf("Exiting the update old election section\n"); // Fixed the message
                    system("sleep 2");
                    break;
                default:
                    printf("Invalid choice! Please enter a number between 1 and 4.\n");
                    system("sleep 2");
                    system("clear");
                    break;
                }
            } while (inner_choice != 4);
            break; // Exiting the inner do-while loop
        }

        case 3:
            printf("Exiting the admin panel\n");
            system("sleep 2");
            system("clear");
            break;

        default:
            printf("Invalid choice! Please enter either 1 or 3.\n");
            system("sleep 2");
            system("clear");
            break;
        }
    } while (choice != 3);
}
