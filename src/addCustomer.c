#include<macros.h>
#include<struct.h>
#include<functions.h>

<<<<<<< HEAD:src/add customer.c
void main(){
=======
void addCustomer(){

>>>>>>> b8f34eb4da5dce90343756c30525d1a66b81dfb1:src/addCustomer.c
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
}