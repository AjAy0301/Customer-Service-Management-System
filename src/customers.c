#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <header.h>

int manage_customer()
{
	char ch;
	do
	{
		system("clear");
		printf("\t\t\t\t-----Customer Database-----\t\t\t\t\n\n\n");
		printf("\n\n1. Add New Customer");
		printf("\n\n2. Update Customer Details");
		printf("\n\n3. Remove Customer");
		printf("\n\n4. Go Back");
		printf("\n\n5. Exit Application");

		printf("\n\n\nChoice- ");
		int choice;
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			add_customer();
			break;
		case 2:
			update_customer();
			break;
		case 3:
			delete_customer();
			break;
		case 4:
			return EXIT_SUCCESS;
			break;
		case 5:
			exit(0);
		default:
			printf("Invalid Choice...");
		}
		printf("\nDo you want to continue to Manage Customer...(Y/N): ");
		getchar();
		ch = getchar();
	} while (ch == 'Y' || ch == 'y');
	return EXIT_SUCCESS;
}



/***********************Funtion to auto generate Customer ID*************************/

int generate_custID()
{
	int customerID;
	FILE *f = fopen("../data/custIDgenerate.txt", "r");
	FILE *t = fopen("../data/temp.txt", "a");

	fscanf(f, "%d", &customerID);
	//printf("\n%d", customerID);
	customerID = customerID + 1;
	
	fprintf(t, "%d", customerID);
	fclose(f);
	fclose(t);
	remove("../data/custIDgenerate.txt");
	rename("../data/temp.txt","../data/custIDgenerate.txt");
	
	return customerID;
}



/***********************Funtion for adding a customer to the database*************************/

int add_customer()
{
	system("clear");
	printf("\nEnter Customer Details : ");

	customer *c = (customer *)calloc(1, sizeof(customer));
	
	c->custID = generate_custID();

	

	// first name input
first_name:
	printf("\n\nFirst Name : ");
	scanf("%s", c->firstName);
	if (!isNameValid(c->firstName))
	{
		printf("\nInvalid name format enter again");
		goto first_name;
	}

	// last name input
last_name:
	printf("\nLast Lame : ");
	scanf("%s", c->lastName);
	if (!isNameValid(c->lastName))
	{
		printf("\nInvalid name format enter again");
		goto last_name;
	}

	// phone number input
phone_num:
	printf("\n\nPhone Number: ");
	getchar();
	scanf("%s", c->phoneNum);
	if (!isPhoneValid(c->phoneNum))
	{
		printf("\nInvalid phone number enter again");
		goto phone_num;
	}

	// address input
	getchar();
	printf("\n\nPermanent Address :");
	fgets(c->address, BIGSIZE, stdin);
	c->address[strlen(c->address) - 1] = '\0';

	// customer type
	int cust_type;
choose_type:
	printf("\n\nCustomer Type (1-New or 2-Existing): ");
	scanf("%d", &cust_type);
	if (cust_type == 1)
		strcpy(c->custType, "new");
	else if (cust_type == 2)
		strcpy(c->custType, "existing");
	else
	{
		printf("\nInvalid type");
		goto choose_type;
	}

	// Storing the inputted data to customers.txt file
	FILE *fp;

	fp = fopen("../data/customers.txt", "a");

	fprintf(fp, "%d | %s | %s | %s | %s | %s\n", c->custID, c->firstName, c->lastName, c->address, c->phoneNum, c->custType);

	fclose(fp);

	free(c);

	return EXIT_SUCCESS;
}



/***********************Funtion for deleting a customer from the database*************************/

int delete_customer()
{
	system("clear");

	customer *c = (customer *)calloc(1, sizeof(customer));

	int custIDToDelete;

	printf("\n\nEnter Customer ID to delete the customer: ");
	scanf("%d", &custIDToDelete);

	FILE *fp = fopen("../data/customers.txt", "r"); 
	FILE *tp = fopen("../data/temp.txt", "a+");

	
	while (!feof(fp))	//checking if fp has reached end of file.
	{
		fscanf(fp, "%d | %s | %s | %s | %s | %[^\n]s", &c->custID, c->firstName, c->lastName, c->phoneNum, c->custType, c->address);
		//printf("%d | %s | %s | %s | %s | %s\n", c->custID, c->firstName, c->lastName, c->phoneNum, c->custType, c->address);
		if (c->custID != custIDToDelete)
		{
			fprintf(tp, "%d | %s | %s | %s | %s | %s\n", c->custID, c->firstName, c->lastName, c->phoneNum, c->custType, c->address);
		}	
	}
	fclose(fp);
	fclose(tp);
	remove("../data/customers.txt");
	rename("../data/temp.txt","../data/customers.txt");

	printf("\nCustomer with customer ID %d is deleted successfully",custIDToDelete);

	free(c);
	return EXIT_SUCCESS;
}



/***********************Funtion for updating the details of existing customer in the database*************************/

int update_customer()
{
	customer *c = (customer *)calloc(1, sizeof(customer));

	int custIDToUpdate;

	printf("\nEnter Customer ID to update the customer : ");
	scanf(" %d", &custIDToUpdate);
	FILE *fp = fopen("../data/customers.txt", "r");
	FILE *tp = fopen("../data/temp.txt", "a+");

	while (!feof(fp))
	{
		fscanf(fp, "%d | %s | %s | %s | %s | %[^\n]s", &(c->custID), c->firstName, c->lastName, c->phoneNum, c->custType, c->address);
		
		if ((c->custID == custIDToUpdate))
		{
			
				printf("\nselect what you want to update-");
				printf("\n1.First Name");
				printf("\n2.Last Name");
				printf("\n3.Address");
				printf("\n4.Mobile Number");
				printf("\n\nEnter choice- ");
				int opt;
				scanf("%d", &opt);
				getchar();
				switch (opt)
				{
				case 1:
					printf("\nEnter the new first name: ");
					char *fname = (char *)calloc(SIZE, sizeof(char));
					
					scanf("%s", fname);
					strcpy(c->firstName, fname);
					break;
				case 2:
					printf("\nEnter the new last name: ");
					char *lname = (char *)calloc(SIZE, sizeof(char));
					
					scanf("%s", lname);
					strcpy(c->lastName, lname);
					break;
				case 3:
					printf("\nEnter the new address: ");
					char *address = (char *)calloc(BIGSIZE, sizeof(char));
					
					scanf("%s", address);
					strcpy(c->address, address);
					break;
				case 4:
					printf("\nEnter the mobile number: ");
					char *phone = (char *)calloc(SIZE, sizeof(char));
					
					scanf("%s", phone);
					strcpy(c->phoneNum, phone);
					break;

				default:
					printf("\nInvalid Choice...");
				}
		}
		

		fprintf(tp, "%d | %s | %s | %s | %s | %s\n", c->custID, c->firstName, c->lastName, c->phoneNum, c->custType, c->address);

		
	}

	fclose(fp);
	fclose(tp);
	
	remove("../data/customers.txt");
	rename("../data/temp.txt","../data/customers.txt");

	free(c);

	return EXIT_SUCCESS;
}