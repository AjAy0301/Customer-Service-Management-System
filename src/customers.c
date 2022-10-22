#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
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
	fp = fopen("../data/Customer.txt","a+");
	
	fprintf(fp, "%d\t%d\t%s\t%s\t%s\t%s\t|\n", c.custID, c.phoneNum, c.firstName, c.lastName, c.custType);
	fclose(fp);

}

void delete_customer()
{
	int custIDToDelete;
	printf("\nEnter Customer ID to delete the customer : ");
	scanf(" %d", &custIDToDelete);
	customer cust;
	FILE *tempFile = fopen("../data/TempCust.txt", "w+");
	FILE *fp = fopen("../data/Customer.txt", "w+");
	while(fscanf(fp, "%d\t%d\t%s\t%s\t%s\t%s", &cust.custID, &cust.phoneNum, cust.firstName, cust.lastName, cust.address, cust.custType)==4){
		if(!(cust.custID==custIDToDelete)){
			fprintf(tempFile, "%d\t%d\t%s\t%s\t%s\t%s|\n", cust.custID,cust.phoneNum, cust.firstName, cust.lastName, cust.address, cust.custType);
		}
	}
	rewind(fp);
	rewind(tempFile);
	while (fscanf(tempFile, "%d\t%d\t%s\t%s\t%s\t%s", &cust.custID, &cust.phoneNum, cust.firstName, cust.lastName, cust.address, cust.custType)==4){
		fprintf(fp, "%d\t%d\t%s\t%s\t%s\t%s|\n", cust.custID, cust.phoneNum, cust.firstName, cust.lastName, cust.address, cust.custType);
	}
	fclose(fp);
	fclose(tempFile);
	remove("../data/tempCust.txt");

}
	
void update_customer()
{
    int custIDToUpdate;
	printf("\nEnter Customer ID to delete the customer : ");
	scanf(" %d", &custIDToUpdate);
	printf("Which of the following data you want to change? :\n");
	printf("1.Phone Number\n2.Name\n3.Address4.\nCustomer Type");
	int opt;
	switch (opt)
	{
	case 1:
		int newNumber;
		printf("Please enter the new phone number:");
		scanf(" %d", &newNumber);
		break;
	case 2:
		char firstName[SIZE], lastName[SIZE];
		printf("Please enter your First Name and Last Name with space in between:");
		scanf(" %s %s", firstName, lastName);
		int changed = changeName(firstName, lastName);
		if(changed){
			printf("Name updated successfully!\n");
		}else{
			printf("Name could not be updated ):\n");
		}
		break;
	case 3:
		char address[BIGSIZE];
		printf("Please enter the new address:");
		scanf("%[^\n]s", address);
		int changed = changeAddress(address);
		if(changed){
			printf("Address updated successfully!\n");
		}else{
			printf("Address could not be updated ):\n");
		}
		break;
	case 4:
		char custType[SIZE];
		tryAgain:
		printf("Please enter the new custType:");
		scanf(" %[^\n]s", custType);
		int changed = changeCustType(custType);
		if(changed){
			printf("Customer Type updated successfully!\n");
		}else{
			printf("Customer Type could not be updated ):\n");
		}
		break;
	default:
		printf("You entered an invalid input. Would you like to try again? :\n");
		printf("Press \"Y/y\" if you want to try again, and \"N/n\" if you don't want to do that.");
		char choice;
		scanf(" %c", &choice);
		if(choice=='y' || choice=='Y')
			goto tryAgain;
		break;
	}

	// customer cust;
	// FILE *tempFile = fopen("TempCust.txt", "w+");
	// FILE *fp = fopen("Customer.txt", "w+");
	// while(fscanf(fp, "%d\t%d\t%s\t%s\t%s\t%s", &cust.custID, &cust.phoneNum, cust.firstName, cust.lastName, cust.address, cust.custType)==4){
	// 	if(!(cust.custID==custIDToUpdate)){
	// 		fprintf(tempFile, "%d\t%d\t%s\t%s\t%s\t%s|\n", cust.custID,cust.phoneNum, cust.firstName, cust.lastName, cust.address, cust.custType);
	// 	}
	// }
	// while (fscanf(tempFile, "%d\t%d\t%s\t%s\t%s\t%s", &cust.custID, &cust.phoneNum, cust.firstName, cust.lastName, cust.address, cust.custType)==4){
	// 	fprintf(fp, "%d\t%d\t%s\t%s\t%s\t%s|\n", cust.custID, cust.phoneNum, cust.firstName, cust.lastName, cust.address, cust.custType);
	// }
	// fclose(fp);
	// fclose(tempFile);
}
	

