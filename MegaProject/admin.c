#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// #include <assert.h>
#include <ctype.h>
#include "header.h"
#include <stdbool.h>
// #define BUFFER_SIZE 100
// #define MAX_LINE_LENGTH 100
struct cname
{
    char name[20];
    int no;
    int serial;
    int votes;
};
struct cname *arr;
// arr=(struct cname*) malloc(sizeof(struct cname)*4);

int checkcand = 0;
int alreadyentered = 0;
int candlist;
int i = 0;
// user authentication
void getarr()
{
    arr = (struct cname *)malloc(sizeof(struct cname) * candlist);
    // return arr;
}

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

    if (flag == 1)
    {
        printf("Details already enterd\n"); // add
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
    if (scanf("%d", &x) != 1)
    {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    printf("Enter the name of the election: ");
    scanf("%s", ename);
    for (int j = 0; ename[j] != '\0'; j++)
    {
        if (!isalpha(ename[j]))
        {
            printf("Invalid input. Candidate name must contain only alphabetic characters.\n");
            return;
        }
    }
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Current Date: %d-%d-%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    fprintf(fp, "Election name: %s\nDate of the election: %d-%d-%d\nMaximum votes: %d\n", ename, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, x);
    flag = 1;

    fclose(fp);
}

// voter id verification

int numVoters = 0;
void validateVoterID(char *voterID)
{
    char voter[x][11]; // rows->maximum voter id =0 to x-1 and columns->length of voterid=0 to 10
    if (i == 0)
    {
        printf("\nNo candidate at current moment\n");
        return;
    }
    // if (i != candlist)
    // {
    //     printf("\nCandidate list not out yet\n");
    //     return;
    // }
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
            // printf("%2[A-Z]%6[0-9]%2[A-Z]\n");
            system("sleep 3");
            return;
        }
    }

    if (strlen(voterID) != 10)
    {
        printf("Invalid voter ID. Please check the format.\n");
        printf("%2[A-Z]%6[0-9]%2[A-Z]\n");
        system("sleep 3");
        return;
    }

    for (int i = 0; i < 2; i++)
    {
        if (!isalpha(voterID[i]) || !isupper(voterID[i]))
        {
            printf("Invalid voter ID. Please check the format.\n");
            printf("%2[A-Z]%6[0-9]%2[A-Z]\n");
            system("sleep 3");
            return;
        }
    }

    for (int i = 2; i < 8; i++)
    {
        if (!isdigit(voterID[i]))
        {
            printf("Invalid voter ID. Please check the format.\n");
            printf("%2[A-Z]%6[0-9]%2[A-Z]\n");
            system("sleep 3");
            return;
        }
    }

    for (int i = 8; i < 10; i++)
    {
        if (!isalpha(voterID[i]) || !isupper(voterID[i]))
        {
            printf("Invalid voter ID. Please check the format.\n");
            printf("%2[A-Z]%6[0-9]%2[A-Z]\n");
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

void add_cand()
{
    // struct cname *arr=getarr();
    if (i == candlist)
    {
        printf("Maximum number of candidates already reached\n");
        return;
    }
    int j;
    int candidateExists = 0; // Flag to check if candidate already exists

    printf("Enter candidate name: ");
    scanf("%s", (arr + i)->name);

    for (j = 0; (arr + i)->name[j] != '\0'; j++)
    {
        if (!isalpha((arr + i)->name[j]))
        {
            printf("Invalid input. Candidate name must contain only alphabetic characters.\n");
            return;
        }
    }

    // Check if candidate name already exists
    for (j = 0; j < i; j++)
    {
        if (strcmp((arr + i)->name, (arr + j)->name) == 0)
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
        // scanf("%d", &p[i].no);
        if (scanf("%d", &(arr + i)->no) != 1)
        {
            // printf("Invalid input. Candidate number must contain only digits.\n");
            // return;
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ;
            return;
        }
        else
        {
            printf("Candidate Name:%s\tCandidate Number:%d\tSuccessfully added\n", (arr + i)->name, (arr + i)->no);
            i++;
            checkcand++;
        }
    }
}

// delete candidate
void delete_cand()
{
    // struct cname *arr=getarr();
    if (i == 0)
    {
        printf("\nNo candidate at current moment\n");
        return;
    }

    int roll, flag = 0;
    printf("Enter candidate number to be deletd: ");
    if (scanf("%d", &roll) != 1)
    {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n')
            ;
        return;
    }

    for (int j = 0; j < i; j++)
    {
        if (roll == (arr + j)->no)
        {
            flag = 1;
            printf("The candidate named %s whose number is %d is deleted\n", (arr + j)->name, (arr + j)->no);
            for (int k = j; k < i - 1; k++)
            {
                *(arr + k) = *(arr + k + 1);
            }
            // Clear the last element
            arr[i - 1].no = 0;
            strcpy(arr[i - 1].name, "");
            // Decrease the count of candidates
            i--;
            // checkcand--;
            break;
        }
    }

    if (flag == 0)
    {
        printf("No candidate with that number\n");
        return;
    }
}

// edit details
void edit_cand()
{
    // struct cname *arr=getarr();
    if (i == 0)
    {
        printf("\nNo candidate at current moment\n");
        return;
    }
    int roll, flag = 0;
    printf("enter the candidate number that you want to update:");
    // scanf("%d", &roll);
    if (scanf("%d", &roll) != 1)
    {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    int check1, check2;
    for (int j = 0; j < i; j++)
    {
        if ((arr + j)->no == roll)
        {
            flag = 1;
            printf("Updating for roll=%d\tname=%s\n", (arr + j)->no, (arr + j)->name);
            int choice;
            while (choice != 3)
            {
                printf("Updating details....\n");
                printf("1.Name\n");
                printf("2.Candidate number\n");
                printf("3.Exit\n");
                printf("Enter your choice of updation:");
                if (scanf("%d", &choice) != 1)
                {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n')
                        ;
                    break;
                }
                // printf("\n");
                switch (choice)
                {
                case 1:
                    check1 = 0;
                    printf("Enter candidate Name:");
                    scanf("%s", (arr + j)->name);
                    for (int x = 0; (arr + j)->name[x] != '\0'; x++)
                    {
                        if (!isalpha((arr + j)->name[x]))
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
                    printf("Enter candidate Number:");
                    if (scanf("%d", &(arr + j)->no) != 1)
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
                    printf("Exiting edit option!\n");
                    break;
                default:
                    printf("Invalid choice! Please enter a number between 1 and 3.\n");
                    break;
                }
            }
        }
    }
    if (flag == 0)
    {
        printf("No candidate with that number\n");
        return;
    }
}

// vote count
void vote_cand()
{
    if (i == 0)
    {
        printf("\nNo candidate at current moment\n");
        return;
    }
    else
    {
        int flag = 0;
        if (checkcand == 0)
        {
            printf("\nNo candidate at current moment\n");
            return;
        }
        int no;
        static int count = 0;

        if (count == x)
        {
            printf("\nMaximum vote limit reached!\n");
            // system("sleep 3");
            return;
        }

        while (1)
        {
            printf("\nEnter the candidate number you want to vote for:");
            if (scanf("%d", &no) != 1)
            {
                printf("Invalid input. Please enter a number.\n");
                while (getchar() != '\n')
                    ;
                continue; // Ask for input again
            }

            for (int j = 0; j < i; j++)
            {
                if ((arr + j)->no == no)
                {
                    flag = 1;
                    printf("\nYou have voted for: %s\n", (arr + j)->name);
                    (arr + j)->votes = (arr + j)->votes + 1;
                    count++;
                    system("sleep 3");
                    break; // Exit the loop if candidate found
                }
            }

            if (flag == 0)
            {
                printf("\nNumber not found\n");
                continue; // Ask for input again
            }

            break; // Exit the loop if candidate found or maximum vote limit reached
        }
    }
    // struct cname *arr=getarr();
}

// Voting results
void result_cand()
{
    // struct cname *arr=getarr();
    if (i == 0)
    {
        printf("\nNo candidate at current moment\n");
        return;
    }
    else
    {
        int max_votes = 0;
        int winner_count = 0;
        int winner_indices[candlist];

        // Find the maximum number of votes
        for (int x = 0; x < i; x++)
        {
            if ((arr + x)->votes > max_votes)
            {
                max_votes = (arr + x)->votes;
            }
        }

        // Find the indices of candidates with the maximum number of votes
        for (int x = 0; x < i; x++)
        {
            if ((arr + x)->votes == max_votes)
            {
                winner_indices[winner_count++] = x;
            }
        }

        if (winner_count > 0)
        {
            printf("\nElection Winners:\n");
            printf("Candidate Name\t\tVotesCount\n");
            for (int j = 0; j < winner_count; j++)
            {
                printf("%s\t\t\t%d\n", (arr + winner_indices[j])->name, (arr + winner_indices[j])->votes);
            }
        }
        else
        {
            printf("\nNo votes have been cast yet.\n");
        }
        system("sleep 3");
    }
}

// show cand
void show_cand()
{

    int sno = 1;
    printf("SrNo.\tName\t\t\tNumber\n");
    for (int x = 0; x < i; x++)
    {
        printf("%d\t%s\t\t\t%d\n", sno, (arr + x)->name, (arr + x)->no);
        ++sno;
    }
    // struct cname *arr=getarr();
}

// Display candidate
void display_cand()
{
    // struct cname *arr=getarr();
    if (i == 0)
    {
        printf("\nNo candidate at current moment\n");
        return;
    }
    int sno = 1;
    printf("SrNo.\tName\t\t\tNumber\t\tVotesCount\n");
    for (int x = 0; x < i; x++)
    {
        printf("%d\t%s\t\t\t%d\t\t%d\n", sno, (arr + x)->name, (arr + x)->no, (arr + x)->votes);
        ++sno;
    }
}
void store_file()
{
    // struct cname *arr=getarr();
    if (i == 0)
    {
        printf("\nNo candidate at current moment\n");
        remove("candidate.csv");
        return;
    }

    int sno = 1;
    FILE *fp;
    fp = fopen("candidate.csv", "w");
    printf("Storing the data in the file.....\n");
    fprintf(fp, "SrNo.,Name,Number,VotesCount\n");

    for (int j = 0; j < i; j++)
    {
        fprintf(fp, "%d,%s,%d,%d\n", sno, (arr + j)->name, (arr + j)->no, (arr + j)->votes);
        ++sno;
    }

    printf("Data stored in the file.....\n");
    fclose(fp);
    // system("sleep 2");
    // system("clear");
}

// UPDATE OLD ELECTION----------------------------------------------------------------

bool checkforold()
{
    FILE *fp;
    bool exist = false;
    fp = fopen("candidate.csv", "r");
    if (fp != NULL)
    {
        exist = true;
        fclose(fp);
        // update();
    }
    return exist;
}

// bool checkelection()
// {
//     int sum = 0;
//     for (int y = 0; y < candlist; y++)
//     {
//         sum = sum + (arr + y)->votes;
//     }
//     if (sum == x)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

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
    // printf("SrNo.,Name,Number,VotesCount\n");
    // fgets(line, sizeof(line), fp);
    while ((fgets(line, sizeof(line), fp)) != NULL)
    {
        printf("%s\n", line);
    }

    fclose(fp);
    // system("sleep 7");
    // system("clear");
}

void newdisplay_file()
{
    FILE *fp;
    bool exist = false;
    fp = fopen("candidate.csv", "r");
    if (fp != NULL)
    {
        exist = true;
        fclose(fp);
        display_file();
    }
    if (!exist)
    {
        printf("\nfile candidate.csv not found\n");
        return;
    }
}

void deleteserial()
{
    FILE *fp, *tmp;
    fp = fopen("candidate.csv", "r");
    // tmp = fopen("temp.csv", "w");

    char line[200];
    int srno, curno, num, vote, flag = 0;
    char name[200];

    printf("enter serial number:");
    // scanf("%d", &srno);
    if (scanf("%d", &srno) != 1)
    {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    printf("\n");

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        sscanf(line, "%d", &curno);
        if (curno == srno)
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

    fp = fopen("candidate.csv", "r");
    tmp = fopen("temp.csv", "w");
    fgets(line, sizeof(line), fp);
    fprintf(tmp, "%s", line);
    // printf("\nDoint the file transfer\n");
    while (fgets(line, sizeof(line), fp))
    {
        sscanf(line, "%d,%[^,],%d,%d", &curno, name, &num, &vote);
        if (srno != curno)
        {
            fprintf(tmp, "%d,%s,%d,%d\n", curno, name, num, vote);
        }
    }
    // printf("\nFile completed\n");

    fclose(fp);
    fclose(tmp);
    remove("candidate.csv");
    rename("temp.csv", "candidate.csv");
    printf("\nSerial number: %d is deleted\n", srno);
    // system("sleep 7");
    // system("clear");
}

void newdeleteserial()
{
    FILE *fp;
    bool exist = false;
    fp = fopen("candidate.csv", "r");
    if (fp != NULL)
    {
        exist = true;
        fclose(fp);
        deleteserial();
    }
    if (!exist)
    {
        printf("\nfile candidate.csv not found\n");
        return;
    }
}

// int checkoldelection = 0;
void admin_pannel()
{
    user_auth();
    if (alreadyentered == 0)
    {
        printf("\nEnter the number of candidates:");
        // scanf("%d", &candlist);
        if (scanf("%d", &candlist) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ;
            return;
        }
        getarr();
        alreadyentered = 1;
    }
    printf("\n");
    // struct cname *arr;
    // arr=(struct cname*) malloc(sizeof(struct cname)*4);
    int choice;

    do
    {
        // system("clear");
        printf("\n1.Start New election\n");
        printf("2.Update old election\n");
        printf("3.Exit\n");
        printf("enter your choice:");
        // scanf("%d", &choice);
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ;
            // system("sleep 2");
            continue;
        } // Read the choice after displaying the menu
        printf("\n");
        switch (choice)
        {
        case 1:
        {
            // checkoldelection=1;
            int inner_choice;
            do
            {
                // system("clear");
                printf("\n---------Main Menu for new election----------\n");
                printf("1.Election Details\n");
                printf("2.Add Candidate\n");
                printf("3.Delete Candidate\n");
                printf("4.Display Candidates\n");
                printf("5.Edit details\n");
                printf("6.Store data in the file\n");
                printf("7.Exit\n");
                // printf("8. Exit\n");
                printf("Enter your choice: ");
                if (scanf("%d", &inner_choice) != 1)
                {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n')
                        ;
                    // system("sleep 2");
                    continue;
                }

                switch (inner_choice)
                {
                case 1:
                    // system("clear");
                    election_details();
                    break;
                case 2:
                    // system("clear");
                    add_cand();
                    break;
                case 3:
                    // system("clear");
                    delete_cand();
                    // system("clear");
                    break;
                case 4:
                    display_cand();
                    break;
                case 5:
                    // system("clear");
                    edit_cand();
                    break;
                case 6:
                    store_file();
                    break;
                case 7:
                    printf("Exiting the start the new election\n");
                    break;
                default:
                    printf("Invalid choice! Please enter a number between 1 and 7.\n");
                    // system("sleep 2");
                    // system("clear");
                    break;
                }
            } while (inner_choice != 7);
            break; // Exiting the inner do-while loop
        }
        case 2:
        {
            // if (checkoldelection == 0)
            // {
            //     printf("No election is present at the moment.\n");
            //     // system("sleep 5");
            //     break;
            // }
            // bool fine = checkforold();
            bool ok = checkforold();
            if (ok == true)
            {
                int inner_choice;
                do
                {
                    // system("clear");
                    printf("\n---------Main Menu for old election----------\n");
                    printf("1. Delete Candidate\n");
                    printf("2. Display Candidates\n");
                    printf("3. Edit details\n");
                    printf("4. Exit\n");
                    printf("Enter your choice: ");
                    // scanf("%d", &inner_choice);
                    if (scanf("%d", &inner_choice) != 1)
                    {
                        printf("Invalid input. Please enter a number.\n");
                        while (getchar() != '\n')
                            ;
                        // system("sleep 2");
                        continue;
                    }

                    switch (inner_choice)
                    {
                    case 1:
                        // system("clear");
                        newdeleteserial();
                        break;
                    case 2:
                        // system("clear");
                        newdisplay_file();
                        // system("sleep 3");
                        break;
                    case 3:
                        newupdate();
                        break;
                    case 4:
                        // system("clear");
                        printf("Exiting the update old election section\n"); // Fixed the message
                        // system("sleep 2");
                        break;
                    default:
                        printf("Invalid choice! Please enter a number between 1 and 4.\n");
                        // system("sleep 2");
                        // system("clear");
                        break;
                    }
                } while (inner_choice != 4);
                break;
            }
            else
            {
                printf("No election is present at the moment.\n");
                // system("sleep 5");
                break;
            }
            // Exiting the inner do-while loop
        }

        case 3:
            printf("Exiting the admin panel\n");
            // system("sleep 2");
            // system("clear");
            break;

        default:
            printf("Invalid choice! Please enter between 1 and 3.\n");
            // system("sleep 2");
            // system("clear");
            break;
        }
    } while (choice != 3);
}
