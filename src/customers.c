#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <header.h>

void manage_customer()
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
		return;
		break;
	case 5:
		exit(0);
	default:
		printf("Invalid Choice...");
		goto enter_choice;
	}
}

int generate_custID()
{

	return 111;
}

void add_customer()
{
	customer *c = (customer *)calloc(1, sizeof(customer));
	printf("\nEnter Customer Details : ");

	// c->custID = generate_custID;
	printf("\nCustomer Id: ");
	scanf("%d", &c->custID);

phone_num:
	printf("\nPhone Number: ");
	scanf("%s", c->phoneNum);
	if (!isNameValid(c->phoneNum))
	{
		printf("\nInvalid name format enter again");
		goto phone_num;
	}
	getchar();

first_name:
	printf("\nFirst Name : ");
	scanf("%s", c->firstName);
	if (!isNameValid(c->firstName))
	{
		printf("\nInvalid name format enter again");
		goto first_name;
	}
	getchar();

second_name:
	printf("\nLast Lame : ");
	scanf("%s", c->firstName);
	if (!isNameValid(c->firstName))
	{
		printf("\nInvalid name format enter again");
		goto second_name;
	}
	getchar();

	printf("\nPermanent Address :");
	fgets(c->address, SIZE, stdin);
	c->address[strlen(c->address) - 1] = '\0';
	getchar();

	int cust_type;
choose_type:
	printf("\nCustomer Type (1-New or 2-Existing): ");
	scanf("%d", cust_type);
	if (cust_type == 1)
		strcpy(c->custType, "new");
	else if (cust_type == 2)
		strcpy(c->custType, "existing");
	else
		printf("\nInvalid type");
	goto choose_type;

	FILE *fp;
	fp = fopen("../data/Customers.txt", "a");
	fprintf(fp, "%d|%s|%s|%s|%s|%s\n", c->custID, c->firstName, c->lastName, c->address, c->phoneNum, c->custType);
	fclose(fp);
}

void delete_customer()
{
	customer *c = (customer *)calloc(1, sizeof(customer));
	int custIDToDelete;
	printf("\nEnter Customer ID to delete the customer : ");
	scanf(" %d", &custIDToDelete);
	FILE *fp = fopen("../data/customers.txt", "r");
	FILE *tp = fopen("../data/temp.txt", "a");

	while (fscanf(fp, "%d|%s|%s|%s|%s|%s\n", &c->custID, c->firstName, c->lastName, c->address, c->phoneNum, c->custType))
	{
		if (!(c->custID == custIDToDelete))
		{
			fprintf(tp, "%d|%s|%s|%s|%s|%s\n", c->custID, c->firstName, c->lastName, c->address, c->phoneNum, c->custType);
		}
	}
	rewind(fp);
	rewind(tp);
	while (fscanf(tp, "%d|%s|%s|%s|%s|%s\n", &c->custID, c->firstName, c->lastName, c->address, c->phoneNum, c->custType))
	{
		fprintf(fp, "%d|%s|%s|%s|%s|%s\n", c->custID, c->firstName, c->lastName, c->address, c->phoneNum, c->custType);
	}
	fclose(fp);
	fclose(tp);
	remove("../data/temp.txt");
}

void update_customer()
{
	customer *c = (customer *)calloc(1, sizeof(customer));
	int custIDToUpdate;
	printf("\nEnter Customer ID to update the customer : ");
	scanf(" %d", &custIDToUpdate);
	FILE *fp = fopen("../data/customers.txt", "r");
	FILE *tp = fopen("../data/temp.txt", "a");

	while (fscanf(fp, "%d|%s|%s|%s|%s|%s\n", &c->custID, c->firstName, c->lastName, c->address, c->phoneNum, c->custType))
	{
		if ((c->custID == custIDToUpdate))
		{
			char ch;
			do
			{
				printf("\nselect what you want to update-");
				printf("\n1.First Name");
				printf("\n2.Last Name");
				printf("\n3.Address");
				printf("\n4.Mobile Number");
				int opt;
				scanf("%c", &opt);
				switch (opt)
				{
				case 1:
					printf("\nEnter the new first name:");
					char *fname = (char *)calloc(SIZE, sizeof(char));
					getchar();
					scanf("%s", fname);
					strcpy(c->firstName, fname);
					break;
				case 2:
					printf("\nEnter the new last name:");
					char *lname = (char *)calloc(SIZE, sizeof(char));
					getchar();
					scanf("%s", lname);
					strcpy(c->lastName, lname);
					break;
				case 3:
					printf("\nEnter the new address:");
					char *address = (char *)calloc(SIZE, sizeof(char));
					getchar();
					scanf("%s", address);
					strcpy(c->address, address);
					break;
				case 4:
					printf("\nEnter the new address:");
					char *phone = (char *)calloc(SIZE, sizeof(char));
					getchar();
					scanf("%s", phone);
					strcpy(c->phoneNum, phone);
					break;

				default:
					printf("\nInvalid Choice...");
				}
				getchar();
				printf("\nDo you want to update more things? press y");
				ch = getchar();
			} while (ch == 'y' || ch == 'Y');
			fprintf(tp, "%d|%s|%s|%s|%s|%s\n", c->custID, c->firstName, c->lastName, c->address, c->phoneNum, c->custType);
		}
		else
		{
			fprintf(tp, "%d|%s|%s|%s|%s|%s\n", c->custID, c->firstName, c->lastName, c->address, c->phoneNum, c->custType);
		}
	}
	rewind(fp);
	rewind(tp);
	while (fscanf(tp, "%d|%s|%s|%s|%s|%s\n", &c->custID, c->firstName, c->lastName, c->address, c->phoneNum, c->custType))
	{
		fprintf(fp, "%d|%s|%s|%s|%s|%s\n", c->custID, c->firstName, c->lastName, c->address, c->phoneNum, c->custType);
	}
	fclose(fp);
	fclose(tp);
	remove("../data/temp.txt");
}
