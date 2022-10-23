#include <stdio.h>
#include <stdlib.h>
#include <header.h>
#include "validate.c"

int customer_login()
{
    while (1)
    {
        system("clear");
        printf("------welcome to Request Portal------");
        printf("\nEnter your customer ID: ");
        int custID;
        scanf("%d", &custID);

        if (isValidCustID(custID))
        {
            printf("\nPlease select the type of Request you have -");
            printf("\n1. Demo Request");
            printf("\n2. Service Request");
            printf("\n3. Complaint");

            printf("\nEnter your choice: ");
            getchar();
            int choice;
            scanf("%d", choice);
        }
        else
        {
            printf("\nCustomer NOT FOUND!!!");
            printf("\nWant to try again?...(Y/N)");
            char ch;
            getchar();
            ch = getchar();
            if (ch == 'Y' || ch == 'y')
                continue;
            else
                return;
        }
    }
    return EXIT_SUCCESS;
}