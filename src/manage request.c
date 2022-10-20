#include<stdio.h>>

void manageRequest()
{
    do{    
        printf("\n1. Add Request\n2.Update Request\n3.Delete request\nChoice- ");
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1: addRquest();
                break;
            case 2: updateRequest();
                break;
            case 3: deleteRequest() 
                break;
            case 4: exit(0);
                break;
            default: printf("Invalid Choice:");           
        }

        printf("\nwant to continue Y/N")
        char ch;
        scanf("%c",ch)
    }while(ch=="Y"||ch=='y')
}