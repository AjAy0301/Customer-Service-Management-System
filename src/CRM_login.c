#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <header.h>

int CRM_login()
{

    while (1)
    {
        system("clear");
        printf("************************************CRM Login************************************");

        int attempt = 1;

        printf("\n\nEnter Password: ");
        char *pass = (char *)calloc(sizeof(char), SIZE);
        scanf("%s", pass);

        if (isValidPass(pass))
        {
            printf("Login Successfull.....");
            char ch;
            do
            {
                system("clear");
                printf("\n\t\t\t\t\t------CRM Menu------\t\t\t\t\t\n\n");
                printf("\n\n1. Manage Customer");
                printf("\n\n2. Manage Requests");
                printf("\n\n3. View Requests Report");
                printf("\n\n4. Logout");
                printf("\n\n5. Exit");

                printf("\n\n\nEnter your choice- ");
                int choice;
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    manage_customer();
                    break;
                case 2:
                    manage_request();
                    break;
                case 3:
                    view_reports();
                    break;
                case 4:
                    return EXIT_SUCCESS;
                    ;
                case 5:
                    exit(0);
                default:
                    printf("\nInvalid choice\n");
                    continue;
                }
                printf("\ndo you want to continue to CRM menu...(Y/N): ");
                getchar();
                ch = getchar();
            } while (ch == 'Y' || ch == 'y');
        }

        else
        {
            printf("n\nIncorrect Password....\nTry Again");
            attempt++;
            if (attempt > 3)
            {
                printf("\n Max Attempts Reached !!!");
                return EXIT_SUCCESS;
            }
            continue;
        }
    }
    return EXIT_SUCCESS;
}
