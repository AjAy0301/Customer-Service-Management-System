/*****************************************************************************************************************************************
 ** FILENAME  :  customer_menu.c
 **
 ** DESCRIPTION : 
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

int customer_login()
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
            add_request();
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