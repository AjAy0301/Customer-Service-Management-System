#include<functions.h>

void manage_request()
{
    char ch;
    do{    
        printf("\n1. Add Request");
        printf("\n2. Update Request");
        printf("\n3. Delete request");
        printf("\n4. Go Back");
        printf("\nChoice- ");

        int choice;
        scanf("%d",&choice);
        
        switch(choice){
            case 1: add_request();
                break;
            case 2: update_request();
                break;
            case 3: delete_request(); 
                break;
            case 4: crm_login();
                break;
            default: printf("Invalid Choice:");           
        }

        printf("\nwant to continue Y/N");
        
        scanf("%c",ch);
    }while(ch=='Y'||ch=='y');

}