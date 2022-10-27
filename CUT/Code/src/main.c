/*****************************************************************************************************************************************
 ** FILENAME  :  main.c
 **
 ** DESCRIPTION : This File defines the function which send external message for Refer.
 ** 
 ** Revision History :
 ** DATE                         NAME                                         REASON
 ** ---------------------------------------------------------------------------------------
 ** 21 October 2022               Ajay Kumar                                To make main.c file
 ** 25 October 2022               Hrishikesh                                To make changes in file header
 ****************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <header.h>

int main()
{
    char ch;
    do
    {
        system("clear");

        printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\t\t\t        =                  WELCOME                  =");
        printf("\n\t\t\t        =                     TO                    =");
        printf("\n\t\t\t        =               CUSTOMER SERVICE            =");
        printf("\n\t\t\t        =               MANAGEMENT SYSTEM           =");
        printf("\n\t\t\t        =                                           =");
        printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        printf("\n\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
      
        printf("\n\n\nSelect Login Mode");
        printf("\n\n\n1. CRM Login");
        printf("\n\n2. Customer Login");
        printf("\n\n3. Exit Application");

        printf("\n\n\nEnter yout choice- ");
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