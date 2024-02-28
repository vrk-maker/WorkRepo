#include <stdio.h>
#include "header.h"
#include <stdlib.h>
#include <ctype.h>

/**
 * @brief Main function of the program.
 * 
 * This function displays a menu for the user to choose between the admin panel, voter panel, or exiting the application.
 * It continuously prompts the user until they choose to exit.
 * 
 * @return 0 on successful execution.
 */
int main()
{
	int choice;
	while (choice != 3)
	{
		//system("clear");
		printf("\n-----Main Menu-----\n");
		printf("1.Admin Pannel\n");
		printf("2.Voter Pannel\n");
		printf("3.Exit\n");
		printf("Enter your choice: ");
		//scanf("%d", &choice);
		if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
			//system("sleep 2");
            continue;
        }
		printf("\n");
		switch (choice)
		{
		case 1:
			//system("clear");
			admin_pannel();
			break;
		case 2:
			//system("clear");
			voting_pannel();
			break;
		case 3:
			printf("Exiting the application!!!\n");
			//system("sleep 3");
			exit(0);
			break;
		default:
			printf("Value is not 1, 2, or 3\n");
			//("sleep 2");
			break;
		}
	}
	return 0;
}
