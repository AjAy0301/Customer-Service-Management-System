/*******************************************************************************************************************
 * * FILE NAME : customers.c
 *
 * * DESCRIPTION : .
 *
 * * Revision History:
 * 	DATE				NAME 				REASON
 *-----------------------------------------------------------------------------------------------------------------
 *  23/10/2022			Ajay Kumar		Creation of file
 * 
*******************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <header.h>


int manage_request()
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
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        add_request();
        break;
    case 2:
        update_request();
        break;
    case 3:
        delete_request();
        break;
    case 4:
        CRM_login();
        break;
    case 5:
        exit(0);
    default:
        printf("Invalid Choice...");
        goto enter_choice;
    }
    return EXIT_SUCCESS;
}



/***********************Funtion to generate Request ID*************************/

int generate_requestID()
{
    int requestID;
	FILE *f= fopen("requestIDgenerate.txt","r+");
	fscanf(f,"%d",&requestID);
	requestID=requestID+1;
	fprintf(f,"%d",requestID);
	fclose(f);
	return requestID;
}



/***********************Funtion to add a request*************************/

int add_request()
{
    printf("\nEnter the details for creating new request :- ");

    request *r = (request *)calloc(1, sizeof(request));

enter_id:
    printf("\nEnter Customer ID:");
    scanf("%d", &r->customerID);
    if (!isValidCustID(r->customerID))
    {
        printf("\nInvalid Customer ID ");
        goto enter_id;
    }

enter_date:
    printf("\nRequest Date (DD-MM-YYYY): ");
    scanf("%d%d%d", &r->requestDate.d, &r->requestDate.m, &r->requestDate.y);
    if (!isValidDate(r->requestDate.d, r->requestDate.m, r->requestDate.y))
    {
        printf("Invalid Date...Enter again");
        goto enter_date;
    }

    char *req_type = (char *)calloc(sizeof(char), SIZE);

    printf("\nPlease select the type of Request you have -");
    printf("\n1. Demo Request");
    printf("\n2. Service Request");
    printf("\n3. Complaint");

enter_choice:
    printf("\nEnter your choice: ");
    getchar();
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        strcpy(r->description, "demo");
        demo(r->requestID);
        break;
    case 2:
        strcpy(r->description, "service");
        service(r->requestID);
        break;
    case 3:
        strcpy(r->description, "complaint");
        complaint(r->requestID);
        break;

    default:
        printf("\nInvalid Choice..");
        goto enter_choice;
    }

    strcpy(r->requestStatus, "open");

    FILE *fp = fopen("../data/requests.txt", "a");
    fprintf(fp, "%d|%d|%d-%d-%d|%s|%s\n", r->requestID, r->customerID, r->requestDate.d, r->requestDate.m, r->requestDate.y, r->description, r->requestStatus);
    fclose(fp);
    return EXIT_SUCCESS;
}



/***********************Funtion to delete a request*************************/

int delete_request()
{
    request *r = (request *)calloc(1, sizeof(request));

    int reqID;
    char ch;

    do
    {
        system("clear");
        printf("\nEnter the request Id for the request to be deleted: ");
        scanf("%d", &reqID);
        if (!isValidRequestID(reqID))
            printf("\nNo request in the database with this request ID");
        printf("\ndo you want to enter request ID again?....(y/n)");
        getchar();
        scanf("%c", ch);
    } while (ch == 'y' || ch == 'Y');

    FILE *fp = fopen("../data/requests.txt", "a+");
    FILE *tp = fopen("../data/temp.txt", "a+");

    while (fscanf(fp, "%d|%d|%d-%d-%d|%s|%s\n", &r->requestID, &r->customerID, &r->requestDate.d, &r->requestDate.m, &r->requestDate.y, r->description, r->requestStatus) != EOF)
    {
        if (!r->requestID == reqID)
            fprintf(tp, "%d|%d|%d-%d-%d|%s|%s\n", r->requestID, r->customerID, r->requestDate.d, r->requestDate.m, r->requestDate.y, r->description, r->requestStatus);
    }

    rewind(fp);
    rewind(tp);

    while (fscanf(tp, "%d|%d|%d-%d-%d|%s|%s\n", &r->requestID, &r->customerID, &r->requestDate.d, &r->requestDate.m, &r->requestDate.y, r->description, r->requestStatus) != EOF)
        fprintf(fp, "%d|%d|%d-%d-%d|%s|%s\n", r->requestID, r->customerID, r->requestDate.d, r->requestDate.m, r->requestDate.y, r->description, r->requestStatus);

    fclose(fp);
    fclose(tp);
    remove("../data/temp.txt");

    free(r);

    return EXIT_SUCCESS;
}



/***********************Funtion to update details of existing request*************************/

int update_request()
{
    char ch;
    do
    {
        system("clear");

        FILE *fp = fopen("../data/requests.txt", "a+");
        FILE *tp = fopen("../data/temp.txt", "a+");

        request *r = (request *)calloc(1, sizeof(request));

        int reqID;

        system("clear");
        printf("Enter the Request ID for the request to be update");
        scanf("%d", &reqID);
        if (isValidRequestID(reqID))
        {
            printf("\nSelect what you want update in the request: ");
            printf("\n1. Update request description");
            printf("\n2. Request Status");
            printf("\n3. Return Back");

        enter_choice:
            printf("\nEnter your choice");
            int opt;
            scanf("%d", &opt);
            switch (opt)
            {
            case 1:
                printf("\nwhat you want update in description: ");
                printf("\n1. Change Request Type");
                printf("\n2. Update the current request type description only");

            sel_opt:
                printf("Enter your choice: ");
                int c;
                scanf("%d", c);
                switch (c)
                {
                case 1:
                    printf("\nPlease select the type of Request you have -");
                    printf("\n1. Demo Request");
                    printf("\n2. Service Request");
                    printf("\n3. Complaint");

                entr_choice:
                    printf("\nEnter your choice: ");
                    getchar();
                    int choice;
                    scanf("%d", &choice);

                    char *desc = (char *)calloc(sizeof(char), SIZE);

                    switch (choice)
                    {
                    case 1:
                        strcpy(desc, "demo");
                        demo(reqID);
                        break;
                    case 2:
                        strcpy(desc, "service");
                        service(reqID);
                        break;
                    case 3:
                        strcpy(desc, "complaint");
                        complaint(reqID);
                        break;
                    default:
                        printf("\nInvalid Choice..");
                        goto enter_choice;
                    }
                    while (fscanf(fp, "%d|%d|%d-%d-%d|%s|%s\n", &r->requestID, &r->customerID, &r->requestDate.d, &r->requestDate.m, &r->requestDate.y, r->description, r->requestStatus) != EOF)
                    {
                        if (r->requestID == reqID)
                        {
                            del_req_desc(r->requestID, r->description);
                            strcpy(r->description, desc);
                        }

                        fprintf(tp, "%d|%d|%d-%d-%d|%s|%s\n", r->requestID, r->customerID, r->requestDate.d, r->requestDate.m, r->requestDate.y, r->description, r->requestStatus);
                    }
                    rewind(fp);
                    rewind(tp);

                    while (fscanf(tp, "%d|%d|%d-%d-%d|%s|%s\n", &r->requestID, &r->customerID, &r->requestDate.d, &r->requestDate.m, &r->requestDate.y, r->description, r->requestStatus) != EOF)
                        fprintf(fp, "%d|%d|%d-%d-%d|%s|%s\n", r->requestID, r->customerID, r->requestDate.d, r->requestDate.m, r->requestDate.y, r->description, r->requestStatus);

                case 2:
                    while (fscanf(fp, "%d|%d|%d-%d-%d|%s|%s\n", &r->requestID, &r->customerID, &r->requestDate.d, &r->requestDate.m, &r->requestDate.y, r->description, r->requestStatus) != EOF)
                    {
                        if (r->requestID == reqID)
                        {
                            if (strcmp(r->description, "demo"))
                                demo(reqID);
                            else if (strcmp(r->description, "complaint"))
                                complaint(reqID);
                            else
                                service(reqID);
                        }
                    }
                    break;
                default:
                    printf("Invalid Choice");
                    goto sel_opt;
                }
                break;
            case 2:
                while (fscanf(fp, "%d|%d|%d-%d-%d|%s|%s\n", &r->requestID, &r->customerID, &r->requestDate.d, &r->requestDate.m, &r->requestDate.y, r->description, r->requestStatus) != EOF)
                {
                    if (r->requestID == reqID)
                    {
                        if (strcpy(r->requestStatus, "open"))
                            strcpy(r->requestStatus, "close");
                        else
                            strcpy(r->requestStatus, "open");
                    }
                    fprintf(tp, "%d|%d|%d-%d-%d|%s|%s\n", r->requestID, r->customerID, r->requestDate.d, r->requestDate.m, r->requestDate.y, r->description, r->requestStatus);
                }
                rewind(fp);
                rewind(tp);

                while (fscanf(tp, "%d|%d|%d-%d-%d|%s|%s\n", &r->requestID, &r->customerID, &r->requestDate.d, &r->requestDate.m, &r->requestDate.y, r->description, r->requestStatus) != EOF)
                    fprintf(fp, "%d|%d|%d-%d-%d|%s|%s\n", r->requestID, r->customerID, r->requestDate.d, r->requestDate.m, r->requestDate.y, r->description, r->requestStatus);
                break;
            case 3:
                return EXIT_SUCCESS;
            default:
                printf("\nInvalid Choice...");
                goto enter_choice;
            }
        }
        else
            printf("No request with this Request ID in database...");

        printf("\nWant to update more requests...(y/n)");
        getchar();
        ch = getchar();

        fclose(fp);
        fclose(tp);
        remove("../data/temp.txt");

        free(r);

    } while (ch == 'y' || ch == 'Y');

    

    return EXIT_SUCCESS;
}