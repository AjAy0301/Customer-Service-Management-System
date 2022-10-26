#include <stdio.h>
#include <stdlib.h>
#include <header.h>

int customer_login()
{
    while (1)
    {
        system("clear");
        printf("------welcome to Customer Request Portal------");
        printf("\n\n\nEnter your customer ID: ");
        int custID;
        scanf("%d", &custID);

        if (isValidCustID(custID))
        {
            add_request();
        }
        else
        {
            printf("\n\nCustomer ID NOT FOUND!!!");
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