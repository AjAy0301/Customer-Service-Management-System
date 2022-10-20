#include<stdio.h>>
#include<stdlib.h>

int main()
{    
    printf("---CUSTOMER SERVICE MANAGEMENT SYSTEM---");
    printf("\n\nSelect Login Mode\n1. CRM Login \n2. Customer Login 3. Exit Application\nChoice- ");
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