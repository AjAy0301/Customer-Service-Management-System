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

    request *r=(request*)calloc(1,sizeof(request));

    enter_id:
    printf("\nEnter Customer ID:");
    scanf("%d",&r->customerID);
    if(!isValidCustID(r->customerID))
    {
        printf("\nInvalid Customer ID "); 
        goto enter_id;
    }    
    

    enter_date:
    printf("\nRequest Date (DD-MM-YYYY): ");
    scanf("%d%d%d",&r->requestDate.d,&r->requestDate.m,&r->requestDate.y);
    if(!isValidDate(r->requestDate.d,r->requestDate.m,r->requestDate.y))
    {    
        printf("Invalid Date...Enter again");
        goto enter_date;   
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
            case 1: strcpy(r->description,"demo");
                demo(r->requestID);
                break;
            case 2:strcpy(r->description,"service");
                service(r->requestID);
                break;
            case 3:strcpy(r->description,"complaint");
                complaint(r->requestID);
                break;        
                
            default: printf("\nInvalid Choice..");
                goto enter_choice;
        }

    }

    strcpy(r->requestStatus,"open");

    FILE *fp = fopen("../data/requests.txt","a");
    fprintf(fp,"%d|%d|%d-%d-%d|%s|%s\n",r->requestID,r->customerID,r->requestDate.d,r->requestDate.m,r->requestDate.y,r->description,r->requestStatus);
    fclose(fp);    
}

void delete_request()
{
    request *r=(request*)calloc(1,sizeof(request));

    int reqID;
    char ch;

    do
    {
        system("clear");
        printf("\nEnter the request Id for the request to be deleted: ");
        scanf("%d",&reqID);
        if(!isValidRequestID(reqID)) 
            printf("\nNo request in the database with this request ID");
        printf("\ndo you want to enter request ID again?....(y/n)");
        getchar();
        scanf("%c",ch);
    }while(ch=='y'||ch=='Y');

    FILE *fp = fopen("../data/requests.txt","r");
    FILE *tp = fopen("../data/temp.txt","a");

    while(fscanf(fp,"%d|%d|%d-%d-%d|%s|%s\n",&r->requestID,&r->customerID,&r->requestDate.d,&r->requestDate.m,&r->requestDate.y,r->description,r->requestStatus)!=EOF){
        if(!r->requestID==reqID)
            fprintf(tp,"%d|%d|%d-%d-%d|%s|%s\n",r->requestID,r->customerID,r->requestDate.d,r->requestDate.m,r->requestDate.y,r->description,r->requestStatus);
    }

    rewind(fp);
	rewind(tp);

    while(fscanf(tp,"%d|%d|%d-%d-%d|%s|%s\n",&r->requestID,&r->customerID,&r->requestDate.d,&r->requestDate.m,&r->requestDate.y,r->description,r->requestStatus)!=EOF)
        fprintf(fp,"%d|%d|%d-%d-%d|%s|%s\n",r->requestID,r->customerID,r->requestDate.d,r->requestDate.m,r->requestDate.y,r->description,r->requestStatus)!=EOF){

    fclose(fp);
	fclose(tp);
	remove("../data/temp.txt");
}

void update_request()
{
    system("clear");

    FILE *fp = fopen("../data/requests.txt","r");
    FILE *tp = fopen("../data/temp.txt","a");

    int reqID;
    char ch;
    do{
        system("clear");
        printf("Enter the Request ID for the request to be update");
        scanf("%d",&reqID);
        if(isValidRequestID(reqID))
        {
            printf("\nSelect what you want update in the request: ");
            printf("\n1. Update request description");
            printf("\n2. Request Status")
            printf("\n3. Return Back")

            enter_choice:
            printf("Enter your choice");
            int choice;
            scanf("%d",&choice);
            switch(choice);
            {
                case 1: while(fscanf(fp,"%d|%d|%d-%d-%d|%s|%s\n",&r->requestID,&r->customerID,&r->requestDate.d,&r->requestDate.m,&r->requestDate.y,r->description,r->requestStatus)!=EOF)
                        {                            
                            if(r->requestID==reqID)
                            {
                                if(strcmp(r->requestStatus,"open"))
                                    strcpy(r->requestStatus,"closed");
                                else
                                    strcpy(r->requestStatus,"open");

                            }
                            fprintf(tp,"%d|%d|%d-%d-%d|%s|%s\n",r->requestID,r->customerID,r->requestDate.d,r->requestDate.m,r->requestDate.y,r->description,r->requestStatus);
                        }
                        rewind(fp);
	                    rewind(tp);

                        while(fscanf(tp,"%d|%d|%d-%d-%d|%s|%s\n",&r->requestID,&r->customerID,&r->requestDate.d,&r->requestDate.m,&r->requestDate.y,r->description,r->requestStatus)!=EOF)
                            fprintf(fp,"%d|%d|%d-%d-%d|%s|%s\n",r->requestID,r->customerID,r->requestDate.d,r->requestDate.m,r->requestDate.y,r->description,r->requestStatus)!=EOF){

                        fclose(fp);
	                    fclose(tp);
	                    remove("../data/temp.txt");   
                    break;
                case 2: 
                    break;
                case 3: return;
                
                default: printf("\nInvalid Choice...");
                    goto enter_choice;  
            }
        }
        else
            printf("No request with this Request ID in database...");

        printf("\nWant to update more requests...(y/n)");
        getchar();
        ch=getchar();            
    }while(ch=='y'||ch=='Y');  

}
    