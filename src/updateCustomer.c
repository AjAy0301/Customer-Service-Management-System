#include<stdio.h>
#include<macros.h>
#include<struct.h>
#include<stdbool.h>

void updateCustomer(){
    customer c;
	printf("\nEnter the Customer ID to update: ");
	printf("\nCustomer Id: ");
	scanf("%d",&c.custID);

    int currCust;
    FILE* fp = fopen("Customer.txt", "w+");
    bool found = false;
    while(fscanf(fp, "%d %*d %*s %*s %*s %*s %*c", &currCust)==1){
        if(currCust==c.custID){
            found = true;
            break;
        }
    }
    char opt;
    printf("Do you want to update the ");
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
}
	

