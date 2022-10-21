#include<functions.h>

void manage_customer( )
{
	system("clear");  
	printf("----Customer Database----");
	printf("\n1. Add New Customer");
	printf("\n2. Update Customer Details");
	printf("\n3. Remove Customer");
	printf("\n4. Back to Main Menu");
	printf("\n5. Exit Application");

	enter_choice:
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
		case 5: exit(0);	
		default: printf("Invalid Choice...");
			goto enter_choice;
	}
	
}