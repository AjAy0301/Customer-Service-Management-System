#include<stdio.h>
#include<stdlib.h>
#include<header.h>

void customer_login()
{   
    while(1){
        system("clear");
        printf("------REQUEST PORTAL-----");
        printf("\nEnter Customer ID: ");
        int custID;
        scanf("%d",&custID);

        if(validateCustID(custID)){

            
                
        }
        else{
            printf("\nCustomer NOT FOUND!!!");
            printf("Try Again?...(Y/N)");
            char ch;
            getchar();
            if(ch=='Y'||ch=='y')
                continue;
            else
                return;
        }
    }
}