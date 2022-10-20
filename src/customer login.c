#include<stdio.h>>
#include<stdlib.h>

void customerLogin()
{    
    printf("---Customer Login---");
    printf("\nEnter Customer ID: ");
    int custID;
    scanf("%d",&custID);
    if(check_custID(custID)){
            //code
    }
    else
        printf("\nInvalid Customer ID");

}