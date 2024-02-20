#include <stdio.h>
#include "header.h"
#include <stdlib.h>
int main()
{
    int choice;
    while (choice != 3)
    {
   	 printf("\n-----Main Menu-----\n");
   	 printf("1.Admin Pannel\n");
   	 printf("2.Voter Pannel\n");
   	 printf("3.Exit\n");
   	 printf("Enter your choice: ");
   	 scanf("%d", &choice);
   	 printf("\n");
   	 switch (choice)
   	 {
   	 case 1:
   		 system("clear");
   		 admin_pannel();
   		 break;
   	 case 2:
   		 system("clear");
   		 voting_pannel();
   		 break;
   	 case 3:
   		 printf("Exiting the application!!!\n");
   		 system("sleep 3");
   		 exit(0);
   		 break;
   	 default:
   		 printf("Invalid choice\n");
   		 break;
   	 }
    }
    return 0;
}
