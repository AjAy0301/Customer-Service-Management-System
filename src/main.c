#include <stdio.h>
#include <stdlib.h>
#include <header.h>

int main()
{
    char ch;
    do
    {
        system("clear");
        printf("\t\t\t\t-----CUSTOMER SERVICE MANAGEMENT SYSTEM-----\t\t\t\t");
        printf("\n\nSelect Login Mode");
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