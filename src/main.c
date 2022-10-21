#include<functions.h>

int main()
{    
    printf("---CUSTOMER SERVICE MANAGEMENT SYSTEM---");
    printf("\n\nSelect Login Mode");
    printf("\n1. CRM Login");
    printf("\n2. Customer Login");
    printf("\n3. Exit Application");
    printf("\nChoice- ");

    int choice;
    scanf("%d",choice);
    
    switch (choice)
    {
    case 1: crmLogin();
        break;
    case 2: customerLogin();
        break;
    case 3: exit(0);   
    default: printf("\nInvalid Choice\n");        
    }

}