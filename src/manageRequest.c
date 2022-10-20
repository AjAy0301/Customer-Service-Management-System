#include<functions.h>

void manageRequest()
{
    char ch;
    do{    
        printf("\n1. Add Request");
        printf("\n2. Update Request");
        printf("\n3. Delete request");
        printf("\nChoice- ");

        int choice;
        scanf("%d",&choice);
        
        switch(choice){
            case 1: addRequest();
                break;
            case 2: updateRequest();
                break;
            case 3: deleteRequest(); 
                break;
            case 4: exit(0);
                break;
            default: printf("Invalid Choice:");           
        }

        printf("\nwant to continue Y/N");
        
        scanf("%c",ch);
    }while(ch=='Y'||ch=='y');

}