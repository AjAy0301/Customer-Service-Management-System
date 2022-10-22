#include<stdio.h>
#include<stdlib.h>
#include<header.h>

int main()
{   
    char ch;
    do{
        system("clear");  
        printf("----CUSTOMER SERVICE MANAGEMENT SYSTEM----");
        printf("\n\nSelect Login Mode");
        printf("\n1. CRM Login");
        printf("\n2. Customer Login");
        printf("\n3. Exit Application");

        printf("\nChoice- ");
        int choice;
        scanf("%d",&choice);
            
        switch (choice)
        {
            case 1: CRM_login();
                break;
            case 2: customer_login();
                break;
            case 3: return EXIT_SUCCESS;   
            default: printf("\nInvalid Choice...\n");
        }
        getchar();
        printf("\nContinue to Login Mode....(Y/N) ");
        scanf("%c",&ch);
    } while(ch=='Y'||ch=='y');    
     
    return EXIT_SUCCESS;
}