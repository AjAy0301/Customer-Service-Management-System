#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 2
#define SIZE 30
struct Customer 
{
	int custid;
	long int ph_num ;
	char fname[SIZE],lname[SIZE],paddress[SIZE],custtype[SIZE];
}c[MAX];

void Manage_Customer( )
{
	FILE *fp; 
	fp = fopen("CustomerDetails.txt","wb+");
	if(fp == NULL)
	{
		printf("File does not created !!!");
		
	}
	for(int i=0 ; i < MAX ; i++)
	{	
		printf("\nEnter Customer Id : ");
		scanf("%d",&c[i].custid); 
		printf("\nEnter your phone number : ");
		scanf("%ld",&c[i].ph_num);
		getchar( );
		printf("\nEnter the first Name : ");
		fgets(c[i].fname,SIZE,stdin);
		c[i].fname[strlen(c[i].fname)-1] = '\0';
		getchar( );
		printf("\nEnter the last name : ");
		fgets(c[i].lname,SIZE,stdin);
		c[i].lname[strlen(c[i].lname)-1] = '\0';
		getchar( );
		printf("\nEnter your permanent address :");
		fgets(c[i].paddress,SIZE,stdin);
		c[i].paddress[strlen(c[i].paddress)-1] = '\0';
		getchar( );
		printf("\nEnter the customer type(new/existing) : ");
		fgets(c[i].custtype,SIZE,stdin);
		c[i].custtype[strlen(c[i].custtype)-1] = '\0';
	}
	fwrite(c,sizeof(c),MAX,fp);

	rewind(fp); 
		    
	fread(c,sizeof(c),MAX,fp);
	printf("\nDetails are as follows\n");
	for(int i=0 ; i<MAX ; i++)
		printf("%d %ld %s %s %s %s \n",c[i].custid, &c[i].ph_num, c[i].fname, c[i].lname, c[i].paddress, c[i].custtype);

}

int main( )
{
	Manage_Customer( );
	return 0;
}

