#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<header.h>

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
		case 4: return;
			break;
		case 5: exit(0);	
		default: printf("Invalid Choice...");
			goto enter_choice;
	}
	
}


int generate_custID(){
    
    return 111;
}


void add_customer()
{
	customer c;
	printf("\nEnter Customer Details : ");

	//c.custID = generate_custID;
   	printf("\nCustomer Id: ");
	scanf("%d",&c.custID); 

	phone_num:
	printf("\nPhone Number: ");
	scanf("%s",c.phoneNum);
	if(!isNameValid(c.phoneNum)){
		printf("\nInvalid name format enter again");
		goto phone_num;
	}
	getchar( );

	first_name:
	printf("\nFirst Name : ");
	scanf("%s",c.firstName);
	if(!isNameValid(c.firstName)){
		printf("\nInvalid name format enter again");
		goto first_name;
	}
	getchar( );

	second_name:
	printf("\nLast Lame : ");
	scanf("%s",c.firstName);
	if(!isNameValid(c.firstName)){
		printf("\nInvalid name format enter again");
		goto second_name;
	}
	getchar( );

	printf("\nPermanent Address :");
	fgets(c.address,SIZE,stdin);
	c.address[strlen(c.address)-1] = '\0';
	getchar( );

	int cust_type;
	choose_type:
	printf("\nCustomer Type (1-New or 2-Existing): ");
	scanf("%d",cust_type);
	if(cust_type==1)
		strcpy(c.custType,"new");
	else if(cust_type==2)
		strcpy(c.custType,"existing");
	else
		printf("\nInvalid type");
		goto choose_type; 	

	

	FILE *fp; 
	fp = fopen("../data/Customer.txt","a+");
	
	fprintf(fp, "%d\t%ld\t%s\t%s\t%s\t%s\t|\n", c.custID, c.phoneNum, c.firstName, c.lastName, c.custType);
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
		char newNumber[SIZE];
		printf("Please enter the new phone number:");
		scanf(" %s",newNumber);
		break;
	case 2:
		char firstName[SIZE], lastName[SIZE];
		printf("Please enter your First Name and Last Name with space in between:");
		scanf(" %s %s", firstName, lastName);
		int changed1 = changeName(firstName, lastName);
		if(changed1){
			printf("Name updated successfully!\n");
		}else{
			printf("Name could not be updated ):\n");
		}
		break;
	case 3:
		char address[BIGSIZE];
		printf("Please enter the new address:");
		scanf(" %[^\n]s", address);
		int changed2 = changeAddress(address);
		if(changed2){
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
		int changed3 = changeCustType(custType);
		if(changed3){
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
	

