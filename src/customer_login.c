#include<stdio.h>
#include<stdlib.h>
#include<validate.h>
#include<functions.h>

void customer_login()
{   
    system("clear");     
    printf("------REQUEST PORTAL-----");

    enter_custid:
    printf("\nEnter Customer ID: ");
    int custID;
    scanf("%d",&custID);

    if(find_customer(custID)){

        printf("\nhello");
            
    }
    else{
        printf("\nCustomer NOT FOUND!!!");
        printf("Try Again?...(Y/N)");
        char ch;
        getchar();
        if(ch=='Y'||ch=='y')
                goto enter_custid;
        else
              return;
    }
}