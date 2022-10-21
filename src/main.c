#include<stdio.h>
#include<stdlib.h>
#include<functions.h>

int main()
{   
    system("clear");  
    printf("----CUSTOMER SERVICE MANAGEMENT SYSTEM----");
    printf("\n\nSelect Login Mode");
    printf("\n1. CRM Login");
    printf("\n2. Customer Login");
    printf("\n3. Exit Application");

    enter_choice:
    printf("\nChoice- ");
    int choice;
    scanf("%d",&choice);
    
    switch (choice)
    {
        case 1: crm_login();
            break;
        case 2: customer_login();
            break;
        case 3: return EXIT_SUCCESS;   
        default: printf("\nInvalid Choice\n");
            goto enter_choice;        
    }
    return EXIT_SUCCESS;
}