#include <stdio.h>
#include <stdlib.h>
#include <header.h>

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
            add_request();
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
                return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}