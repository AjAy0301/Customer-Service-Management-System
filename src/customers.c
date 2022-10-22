#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<macros.h>
#include<struct.h>
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


int find_customer(int custID)
{

    
    return FOUND;
}


void add_customer()
{
/*
	customer c;
	printf("\nEnter Customer Details : ");

   	printf("\nCustomer Id: ");
	scanf("%d",&c.custID); 

	printf("\nMobile Number : ");
	scanf("%ld",&c.phoneNum);
	getchar( );

	printf("\nFirst Name : ");
	fgets(c.firstName,SIZE,stdin);
	c.firstName[strlen(c.firstName)-1] = '\0';
	getchar( );

	printf("\nLast Lame : ");
	fgets(c.lastName,SIZE,stdin);
	c.lastName[strlen(c.lastName)-1] = '\0';
	getchar( );

	printf("\nPermanent Address :");
	fgets(c.address,SIZE,stdin);
	c.address[strlen(c.address)-1] = '\0';
	getchar( );

	printf("\nCustomer Type (New/Existing) : ");
	fgets(c.custType,SIZE,stdin);
	c.custType[strlen(c.custType)-1] = '\0';

	FILE *fp; 
	fp = fopen("Customer.txt","ab+");

	fwrite(&c, sizeof(customer), 1, fp);
	fprintf(fp, " |\n");
	fclose(fp);
*/

}

void delete_customer()
{
    
}
	
void update_customer()
{
    
}
	

