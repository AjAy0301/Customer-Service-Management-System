#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<header.h>

void manage_request()
{
    system("clear");  
    printf("\n1. Add Request");
    printf("\n2. Update Request");
    printf("\n3. Delete request");
    printf("\n4. Back to Main Menu");
	printf("\n5. Exit Application");

    enter_choice:
	printf("\nChoice- ");
	int choice;
	scanf("%d",&choice);

    switch(choice){
        case 1: add_request();
            break;
        case 2: update_request();
            break;
        case 3: delete_request(); 
                break;
        case 4: crm_login();
            break;
        case 5: exit(0);	
		default: printf("Invalid Choice...");
			goto enter_choice;
	}
}


int generate_requestID(){
    
    return 101;
}



void add_request()
{
    printf("\nEnter the details for creating new request :- ");

    request r;

    r.requestID=generate_requestID;

    printf("\nEnter Customer ID:");
    while(scanf("%d",&r.customerID))
    {
        if(isValidCustID(r.customerID))
            break;
        else
            printf("\nInvalid Customer ID \nEnter Customer ID: "); 

    }    
    

    while (1)
    {    
        printf("\nRequest Date:");
        scanf("%d%d%d",&r.requestDate.d,&r.requestDate.m,&r.requestDate.y);
        if(isValidDate(r.requestDate.d,r.requestDate.m,r.requestDate.y))
            break;
        else
            printf("Invalid Date...Enter again");
           
    }

    char *req_type = (char*)calloc(sizeof(char),SIZE);

    while(1)
    {
        

        printf("\nPlease select the type of Request you have -");
        printf("\n1. Demo Request");
        printf("\n2. Service Request");
        printf("\n3. Complaint");

        enter_choice:
        printf("\nEnter your choice: ");
        getchar();
        int choice;
        scanf("%d",&choice);

        switch (choice)
        {
            case 1: strcpy(req_type,"demo");
                demo(r.requestID);
                break;
            case 2:strcpy(req_type,"service");
                service(r.requestID);
                break;
            case 3:strcpy(req_type,"complaint");
                complaint(r.requestID);
                break;        
                
            default: printf("\nInvalid Choice..");
                goto enter_choice;
        }

    }

    strcpy(r.description,req_type);
    strcpy(r.requestStatus,"OPEN");


    //add to database    
    
}

void delete_request()
{
 
}

void update_request()
{

}
    