#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<header.h>

void CRM_login()
{   
    system("clear");  
    printf("------CRM Login------");

    int attempt=1;

    while(1)
    {
        printf("\n\nEnter Password: ");
        char *pass=(char*)calloc(sizeof(char),SIZE);
        scanf("%s",pass);

        if(validatePass(pass))
        {
            char ch;
            while (1)
            { 
                printf("\n1. Manage Customer");
                printf("\n2. Manage Requests");
                printf("\n3. Requests Report");
                printf("\n4. Logout");
                printf("\n5. Exit");
                   
                printf("\nEnter Choice- ");
                int choice;
                scanf("%d",&choice);

                switch (choice)
                {
                    case 1: //manage_customer();
                        break;
                    case 2: //manage_request();
                        break;
                    case 3: //view_reports();
                        break;
                    case 4: return;
                    case 5: exit(0);
                    default: printf("\nInvalid choice\n");
                        continue;            
                }  
                printf("\nContinue...(Y/N");
                getchar();
                ch=getchar(); 
            }while (ch=='Y'||ch=='y');
        }

        else
        {
            printf("Incorrect Password....\nTry Again");
            attempt++;
            if(attempt>3)
            {
                printf("\n Max Attempts Reached !!!");
                return;
            }            
            continue;  
        }
    }    

}

