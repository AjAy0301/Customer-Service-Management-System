/*****************************************************************************************************************************************
 ** FILENAME  :  customer_menu.c
 **
 ** DESCRIPTION : This File defines the customer menu function
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

int customer_menu()
{
    while (1)
    {
        system("clear");
        printf("\n*******************************************************\n");
        printf("*       Welcome to Customer Request Portal                *");
        printf("\n*******************************************************\n");

        printf("\n\n\nEnter your customer ID: ");
        int custID;
        scanf("%d", &custID);

        if (isValidCustID(custID))
        {
            printf("\n\n\nSelect your choice");
            printf("\n\n1. Add Request");
            printf("\n\n2. Update Request");
            printf("\n\n3. Delete request");
            printf("\n\n4. Back to Main Menu");
            printf("\n\n5. Exit Application");

        enter_choice:
            printf("\n\n\nChoice- ");
            char choice;
            scanf("%s", &choice);

            switch (choice)
            {
            case '1':
                add_request();
                break;
            case '2':
                update_request();
                break;
            case '3':
                delete_request();
                break;
            case '4':
                return EXIT_SUCCESS;
            case '5':
                exit(0);
            default:
                printf("Invalid Choice...");
                goto enter_choice;
            }
        }
        else
        {
            printf("\n\nCustomer ID NOT FOUND!!!\n");
            printf("\n\n do you want to try again?...(Y/N): ");
            char ch;
            getchar();
            ch = getchar();
            if (ch == 'Y' || ch == 'y')
                continue;
            else
                return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}