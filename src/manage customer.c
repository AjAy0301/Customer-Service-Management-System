#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<macros.h>

void manageCustomer( )
{
	while (1)
	{
		printf("----Customer Database----");
		printf("\n1.Add New Customer");
		printf("\n2.Update Customer Details");
		printf("\n3.Remove Customer");
		printf("\n4.Exit");
		printf("\nChoice- ");
		int choice;
		scanf("%d",&choice);

		switch (choice)
		{
			case 1: addCustomer();
				break;
			case 2:	updateCustomer();
				break;
			case 3: deleteCustomer();
				break;
			case 4: exit(0);
				break;
			default: printf("Invalid Choice...");
		}
	}
	
	
}