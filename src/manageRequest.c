#include<functions.h>

void manage_request()
{
    system("clear");  
    printf("\n1. Add Request");
    printf("\n2. Update Request");
    printf("\n3. Delete request");
    printf("\n4. Back to Main Menu");
	printf("\n5. Exit Application");

    enter_choice:
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
        case 5: exit(0);	
		default: printf("Invalid Choice...");
			goto enter_choice;
	}
}