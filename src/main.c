/*******************************************************************************************************************
 * * FILE NAME : main.c
 *
 * * DESCRIPTION : This is the main menu file which through which different login mode can be accessed.
 *
 * * Revision History:
 * 	DATE				NAME 				REASON
 *-----------------------------------------------------------------------------------------------------------------
 *  23/10/2022			Ajay Kumar		Creation of file
 * 
*******************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <header.h>

int main()
{
    char ch;
    do
    {
        system("clear");
        printf("----CUSTOMER SERVICE MANAGEMENT SYSTEM----");
        printf("\n\nSelect Login Mode");
        printf("\n1. CRM Login");
        printf("\n2. Customer Login");
        printf("\n3. Exit Application");

        printf("\nEnter yout choice- ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            CRM_login();
            break;
        case 2:
            customer_login();
            break;
        case 3:
            return EXIT_SUCCESS;
        default:
            printf("\nInvalid Choice...\n");
        }
        getchar();
        printf("\nContinue to Login Mode....(Y/N) ");
        ch = getchar();
    } while (ch == 'Y' || ch == 'y');

    return EXIT_SUCCESS;
}