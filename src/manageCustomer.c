#include<functions.h>

void manage_customer( )
{
	char ch;
    do{  
		printf("----Customer Database----");
		printf("\n1. Add New Customer");
		printf("\n2. Update Customer Details");
		printf("\n3. Remove Customer");
		printf("\n4. Go Back");
		printf("\nChoice- ");
		int choice;
		scanf("%d",&choice);

		switch (choice)
		{
			case 1: add_customer();
				break;
			case 2:	update_customer();
				break;
			case 3: delete_customer();
				break;
			case 4: crm_login();
				break;
			default: printf("Invalid Choice...");
		}

		printf("\nwant to continue Y/N");
        scanf("%c",ch);
    }while(ch=='Y'||ch=='y');
	
	
}