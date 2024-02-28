#include <stdio.h>
#include "header.h"
#include <stdlib.h>

/**
 * @brief Prompts the user to enter a Voter ID and validates it.
 * 
 * This function prompts the user to enter a Voter ID and then calls the 
 * validateVoterID function to validate the entered ID.
 */
void entervoterid()
{
	char str1[20];
	printf("Enter the Voter ID: ");
	scanf("%s", str1);
	validateVoterID(str1);
}
/**
 * @brief Displays the voting panel.
 */
void voting_pannel()
{
	int choice;
	while (choice != 3)
	{
    	//system("clear");
    	printf("\n-----Main Menu for voting pannel-----\n");
    	printf("1.Enter VoterID and Vote for candidate\n");
    	printf("2.Election Results\n");
    	printf("3.Exit the Voting Pannel\n");
    	printf("Enter your choice: ");
    	if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
			//system("sleep 2");
            continue;
        }
    	switch (choice)
    	{
    	case 1:
        	//system("clear");
        	entervoterid();
        	//system("clear");
        	break;
    	case 2:
        	//system("clear");
        	result_cand();
        	//system("clear");
        	break;
    	case 3:
        	printf("Exiting the voting pannel!!!\n");
        	//system("sleep 3");
        	//system("clear");
        	//system("clear");
        	break;
    	default:
        	printf("Invalid choice please enter between 1 and 3\n");
			//system("sleep 2");
			//system("clear");
        	break;
    	}
	}
}
